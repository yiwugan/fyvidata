 // silencer@fy
#include <ansi.h>
inherit F_CLEAN_UP;
//inherit SSERVER; 
int main(object me, string arg)
{
        string what, who;
        object ob, victim;
        mapping myfam, vtfam;
        int sp, dp;
        
        object where = environment(me);
        if ( me->query("class")!="shenshui")
                  return notify_fail("只有神水弟子才能使用勾魂法！\n"); 
        if( environment(me)->query("no_fight"))
                return notify_fail("这里是很严肃的场合，你该知道不能有出格的举动。\n"); 
        if( me->query_temp("seducing") )
                return notify_fail("你正在施勾魂法了！\n");
        
        if( !arg || sscanf(arg, "%s for %s", who, what)!=2 ) return
                notify_fail("指令格式：seduce <某人> for <某物>\n"); 
        if ( (int)me->query_skill("nine-moon-spirit",1) < 100)
                return notify_fail("并不是每个女孩都会有效地勾引人的，你还是该勤修姹女神功才是。\n"); 
        if( me->is_fighting() )
                return notify_fail("打架的时候还可以乱抛媚眼？\n"); 
        if(me->query("sen") <= 200)
            return notify_fail("你精神不振，委委靡靡的一点不吸引人。\n");
        if(me->query_per() < 20)
            return notify_fail("你今天看起来一点也不吸引人，还是回去好好打扮一下再来试吧。\n");  
        victim = present(who, environment(me)); 
        if( !victim || victim == me) 
                return notify_fail("你想勾引的对象不在这里。\n");
        
        if( !living(victim) || !objectp(victim) || victim == me)
                return notify_fail("你要勾引谁？\n"); 
        if( victim->is_fighting() ) 
                return notify_fail(victim->name() + "正在打架，没空理你！\n");
        
        if( !ob = present(what, victim) ) {
                object *inv;
           inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail( victim->name() + "身上看起来没有什麽让你感兴趣的东西。\n");
                ob = inv[random(sizeof(inv))];
        } 
        if ( ob->query("equipped") || ob->query("no_drop") || ob->query("owner"))
                return notify_fail(victim->name()+"太看重这样东西了,天仙下凡也没用。\n");  
        me->add("sen",-200);
        
        sp = (int)me->query_skill("nine-moon-spirit",1) * (int)me->query_skill("nine-moon-spirit",1) 
         + (int)me->query_per()* (int)me->query_per() * me->query_per() /3;
         
        if(me->query("gender")==victim->query("gender"))
                sp=sp/3;
                
        if(victim->query("age")<12 || victim->query("age")>60)
                sp=sp/3; 
         
        if( sp < 1 ) sp = 1;
        
        dp = (int)victim->query_cps()*1000+20000; 
        tell_object(me, HIG"你轻笑了起来，用小猫一样好奇的目光瞟着"+victim->name()+HIG"带着的"+ ob->name());
        tell_object(me, NOR MAG"\n你带着艳羡的神色，轻轻咬了咬下嘴唇 —— \n你知道自己已经足够了，若有什么人还不懂你的意思，那人一定是白痴。\n\n"NOR); 
        tell_object(victim, HIG+ me->name() + HIG"银铃般的轻笑声传入你耳中，你向她看去。\n"NOR);
        tell_object(victim,MAG"她的眼睛会说话，她的媚笑会说话，就算是瞎子，也可以闻得到她身上散发出的\n那一缕缕甜香，也可以听得到她那销魂荡魄的浅笑。\n\n"NOR);
        tell_object(victim,MAG"她似乎对你的"+ob->name()+NOR MAG"很感兴趣。\n"NOR);
        
        message("vision", HIG"只听"+me->name()+HIG"轻笑了起来，用小猫一样好奇的目光瞟着"NOR+victim->name()+"。\n"NOR,environment(me), ({ me, victim }) );
        message("vision", MAG+me->name()+ MAG"的眼睛会说话，她的媚笑会说话，就算是瞎子，也可以闻得到她身上散发出的\n那一缕缕甜香，也可以听得到她那销魂荡魄的浅笑。\n"NOR,environment(me), ({ me, victim }) );
        message("vision", YEL + me->name()+ YEL"似乎很感兴趣"+ victim->name()+"身上带的什么东西。\n\n"NOR,environment(me), ({ me, victim }) );
        
        me->set_temp("seducing", 1);
        call_out( "compelete_seduce",random(3)+1, me, victim, ob, sp, dp); 
        return 1; 
}    
void compelete_seduce(object me, object victim, object ob, int sp, int dp)
{
        int amount;
        object ob1; 
        me->delete_temp("seducing");
   if(!objectp(victim)) { 
        
                tell_object(me, "白浪费感情了，你要勾引的人已经不见了。\n");
                return;
        }
        
        if( environment(victim) != environment(me) ) {
                tell_object(me, "白浪费感情了，你要勾引的人已经不见了。\n");
                return;
        }
// not a human being
        if(!victim->query("spi")) {
                tell_object(me,victim->name()+"根本就无动于衷！\n");
                return;
        }
        // exp limit to stop beggar dummies
        if (victim->query("combat_exp")>me->query("combat_exp")*8) {
                message_vision(NOR"\n$N一副酷酷的样子，根本不在乎$n费尽心机的诱惑。\n"NOR, victim, me);
                return;
        }
        if( living(victim) && (random(sp+dp) > dp) && ob->move(me)) 
        {
                message_vision(YEL"$N痴痴地望着$n，恍然间就明白了$n的意思，马上把" 
                                + ob->query("unit") + ob->name() + YEL"交到$n手里。\n
\n$N脸上现出洋洋自得的神气，好像在说：如此善解佳人的大情圣，舍我其谁？\n\n"NOR,victim,me);
                me->start_busy(3);
        } 
        else 
        {
                if( random(sp+dp) > dp*3/4 && random (4)>1) {
                message_vision(YEL"$N望着远处,似乎根本就没注意到$n。\n"NOR, victim,me);
                me->start_busy(3);
                        return;
                }
                else
                message_vision(YEL"$N狠狠地瞪了$n一眼，喝道：大胆妖女,竟敢在此无礼！\n"NOR, victim,me);
                if(!environment(victim)->query("no_fight"))     
                victim->fight_ob(me);
                me->start_busy(3);
        }
}    
