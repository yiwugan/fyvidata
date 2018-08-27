 //mimicat@fy4
// - rewriten by neon 06-09-2002
// - new daojianruomeng 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int single_perform(object target, object me, object blade, object sword);
int team_perform(object target, object me, object you);
int perform(object me, object target)
{
        int mylevel;
        string msg,yourname,myname,targetname;
        int skl_me, skl_you, extra_me, extra_you,j,k, solo = 0;
        object you, ob,*myteam, *mystuff, sword, blade; 
        if (!target) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［刀剑若梦］只能对战斗中的对手使用。\n"); 
        if(me->query("gender")!="男性")
                return notify_fail("短歌刀法的［刀剑若梦］必须由男子发动。\n");
            
        mylevel=me->query_skill("shortsong-blade",1);
        
        myteam = me->query_team();
        k = 0;
        if( !pointerp(myteam)) solo = 1 ;
        else {
                for (j = 0; j< sizeof(myteam); j++) {
                        if (environment(myteam[j]) == environment(me)) {
                                if( myteam[j] != me ) you = myteam[j];
                                k++;
                        }
                }
                if (k == 1) solo = 1;
                else if (k == 2) solo = 0;
                else 
                        return notify_fail("［刀剑若梦］需要两人心心相印，现在有第三者在旁边，威力就发挥不出来。\n"); 
        }
        
        
        /*Single player perform*/
        if (solo) 
                return notify_fail("短歌刀法的［刀剑若梦］需要两人才能发动。\n");
        /*Team perform*/
        else { 
                return team_perform(target, me, you);
        }
        
} 
int team_perform(object target, object me, object you)
{
        object blade, sword;
        int skl_me, skl_you, extra_me, extra_you,j,k, bonus;
        string msg,yourname,myname,targetname; 
        if(me->query("gender")!="男性"|| you->query("gender")!="女性")  
                return notify_fail("必须一男一女才能够使用这个绝技。\n"); 
        if(me->query_skill("shortsong-blade",1)<30)
                return notify_fail("你的短歌刀法级别不够。\n");
        if(!you->query_skill("diesword",1) || you->query_skill_mapped("sword") != "diesword") 
                return notify_fail("同伴没有配合的武功。\n");
        if(you->query_skill("diesword",1)<30)
                return notify_fail("同伴武功级别不够。\n");
        if(!objectp(sword=you->query_temp("weapon"))) 
                return notify_fail("同伴没有兵器。\n");
        if(sword->query("skill_type") != "sword")
                return notify_fail("同伴兵器种类不对。\n");
        if(you == target )
                return notify_fail(MAG"你怎么狠得下这个心？\n"NOR);
        if(you->query("class")!="legend" && me->query("class")!="legend")
                return notify_fail("至少有一个人必须是铁雪弟子才能用［刀剑若梦］。\n");
        if (you->is_busy())
                return notify_fail("同伴正忙着，没法和你一起施展［刀剑若梦］。\n"); 
                    
        // Now determine the bonus for same menpai and couple
        bonus = 0;
        if (you->query("class") == "legend" && me->query("class") == "legend" )  bonus++;
        if (you->query("marry") == me->query("id") && you->query("id") == me->query("marry"))  {
                bonus++;
                message_vision(HIG"\n$N与$n凝目对望一眼，忽然间柔情蜜意充满心头，清光闪动，刀剑如梦幻般挥出。。。\n\n"NOR,me,you);              
   }
        
        
        skl_me=(int)me->query_skill("shortsong-blade",1);
        extra_me=(int)me->query_skill("shortsong-blade",1);        
        skl_you=(int)you->query_skill("diesword",1);
        extra_you= (int)you->query_skill("diesword",1);
        
        skl_me=(skl_me+skl_you)/4 *(2+ bonus)/4;
        extra_me=(extra_me+extra_you)/2 * (1+bonus)/2;
        
//        message_vision((string)(bonus)+" "+(string)(skl_me)+" "+(string)(extra_me)+".\n",me);
        
        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        you->add_temp("apply/attack",skl_me);
        you->add_temp("apply/damage",extra_me);
 
        you->kill_ob(target);
        target->kill_ob(you);
        
        myname=me->name();
        yourname=you->name();
        targetname=target->name();
        blade=me->query_temp("weapon"); 
                msg=HIY"\n$N和$n刀剑合壁，使出了一式“刀剑若梦”，丝丝入扣，滴水不漏的向"+targetname+HIY"斩去。 \n\n";
                msg+=HIC"迢迢牵牛星，皎皎河汉女。\n"NOR;
                msg+=HIY"$N手中的"+sword->name()+HIY"百转千回，变幻不定，"+targetname+HIY"眼前一花，$n手中的"
                +blade->name()+HIY"早已杀到面前。 "NOR;
                message_vision(msg,you,me);
                COMBAT_D->do_attack(me,target, TYPE_REGULAR," "); 
                msg=CYN"\n纤纤擢素手，札札弄机杼。\n";
                msg+="$N移行换步上前，反手就是一剑！ \n"NOR;
                COMBAT_D->do_attack(you,target,TYPE_REGULAR,msg); 
                msg=HIW"\n\n终日不成章，涕泣零如雨。\n";
                msg+="$n手中的"+blade->name()+HIW"不住虚晃，$N乘机攻出一片剑影，将"+targetname+HIW"全身笼罩其中。" NOR;
                message_vision(msg,you,me);
                COMBAT_D->do_attack(you,target,TYPE_REGULAR," "); 
                msg=MAG"\n\n河汉清且浅，相去复几许。\n";
                msg+="$n左手轻搂$N的蛮腰，右手"+blade->name()+MAG"斜斜挥出，直取"+targetname+MAG"的要害。 "NOR;
           message_vision(msg,you,me);
                COMBAT_D->do_attack(me,target, TYPE_REGULAR," "); 
                msg=HIG"\n\n盈盈一水间，脉脉不得语。\n";
                msg+="$n和$N心意相通，一刀一剑，有如缠绵中的情侣，竟合而为一，直向"+targetname+HIG"飞去。"NOR;
                message_vision(msg,you,me);
                me->add_temp("apply/attack",extra_me/4*bonus);
                you->add_temp("apply/attack",extra_me/4*bonus);
                me->add_temp("apply/damage",extra_me);
                you->add_temp("apply/damage",extra_me);
                COMBAT_D->do_attack(me,target, TYPE_REGULAR," ");
                COMBAT_D->do_attack(you,target,TYPE_REGULAR," ");
                me->add_temp("apply/attack",-extra_me/4*bonus);
                you->add_temp("apply/attack",-extra_me/4*bonus);
                me->add_temp("apply/damage",-extra_me);
                you->add_temp("apply/damage",-extra_me); 
        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
        you->add_temp("apply/attack",-skl_me);
        you->add_temp("apply/damage",-extra_me);
        if (me->query_busy()<3) me->start_busy(3);
        if (you->query_busy()<3) you->start_busy(3);
        return 1;
}       
