 // TIE@FY3
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int main(object me, string arg)
{
        int skill;
        object target;
        string msg;
        seteuid(getuid());
        if(me->query("class") != "shenshui") return
        notify_fail("假死是神水宫的绝技！\n");
        skill=me->query_skill("nine-moon-spirit",1);
        skill=skill/5*6;
        
        if((int)me->query("timer/polu") + 8 > time())
                return notify_fail(HIM"你刚刚使用过[破颅]，立即假死不会有效。\n"NOR);
        
        if((int)me->query("timer/jiasi") + 900-skill*3/2 > time())
         {
                return notify_fail(HIM"这么快就旧技重演会给看穿的\n"NOR);
        }
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你不在战斗中，不需要假装死。\n");
       
//      if(random(10))
//      {       
        message_vision("$N惨叫一声，一头栽倒在地下。\n$N死了。\n",me);
        me->set("disable_type",HIG "<假死中>" NOR);
        me->remove_all_killer();
        me->remove_all_enemy();
//      me->delete("env/wimpy");
        me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me :), 
random(50 - (int) me->query_con()));
        me->set_temp("disable_inputs",1);
        me->set_temp("block_msg/all",1);
   me->set_temp("is_unconcious",1);
        me->set_temp("in_jiasi",1);
        
//      }
/*      else
        {
        msg = "可惜$n装死并不成功，$N乘机发起迅然攻击！";
        COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);  
        me->start_busy(random(3) + 2);
        } */
        return 1;
} 
void remove_dazuo(object me)
{
        me->delete_temp("in_jiasi");
        me->delete_temp("is_unconcious",1);
        me->delete_temp("disable_inputs");
        me->delete("disable_type");
        me->delete_temp("block_msg/all");
        message_vision("$N在地上悄悄地翻了个身，小心翼翼地睁开了眼。\n",me);
        //me->move(environment(me),1);
        me->set("timer/jiasi",time());
} 
int help(object me)
{
        write(@HELP
指令格式 : jiasi
让你在战斗中装死，创造逃生的机会。
非神水宫的人不可以装死。 
HELP
        );
        return 1;
}
     
