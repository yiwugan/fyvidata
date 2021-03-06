 //silencer@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void get_up(object me,object target);
int perform(object me, object target)
{
        string msg;
        int extra, myexp, enemyexp, lvl;
        object weapon,hisweapon; 
        if(me->query("class")!="beggar" && userp(me))
                return notify_fail("［戳字诀］只传授给丐帮弟子！\n");
        
        lvl = (int) me->query_skill("dagou-stick",1);
        if(lvl < 20)
                return notify_fail("你的打狗棒法还不够熟练！\n");       
        
        if (me->query_skill_mapped("force") != "huntunforce")
                return notify_fail("戳字诀需要混沌心法的配合。\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［戳字诀］只能对战斗中的对手使用。\n"); 
        weapon = me->query_temp("weapon");
        
        msg = HIY"\n$N"+HIY"一招“"+NOR CYN"戳"+HIY"”字诀，迎面一棒刺去，棒身晃动，似是刺向上盘，却又似向$n"+HIY"下三路缠打。\n"NOR;
        
        me->add_temp("apply/attack", lvl);
        me->add_temp("apply/damage", lvl/5);
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -lvl);
        me->add_temp("apply/damage", -lvl/5);
        me->start_busy(1+random(2));
        return 1;
}    
