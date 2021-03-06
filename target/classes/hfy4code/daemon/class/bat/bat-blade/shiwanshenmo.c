 // shiwanshenmo.c   十万神魔
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra, n, force;
        int tmp,chance;
        object weapon;
        
        if ( (string) me->query_skill_mapped("dodge") != "meng-steps")
                return notify_fail("［十万神魔］需要［幻梦步法］的配合！\n");
        
        extra = me->query_skill("bat-blade",1);
        if (extra < 100) return notify_fail("你的［蝙蝠刀法］还不够纯熟！\n");
        
        tmp = me->query_skill("meng-steps",1);
        if (tmp < 100)  return notify_fail("你的［幻梦步法］还不够纯熟！\n");
        
        if (me->query("class")=="bat") n=0;
                else n=100;
        
        if(userp(me) && me->query_temp("timer/shiwanshenmo")+n > time())
                return notify_fail("［十万神魔］需要聚气片刻。。\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［十万神魔］只能对战斗中的对手使用。\n");
        
        chance=extra+tmp;
        
        force= me->query_skill("force",1)/3;
        if (me->query_skill_mapped("force")=="wuzheng-force" && me->query("class")=="bat")
                force= me->query_skill("wuzheng-force",1);
        
        me->add_temp("apply/attack",tmp+force);
        me->add_temp("apply/damage",extra*3+force);
        
   weapon = me->query_temp("weapon");
        msg = MAG  "\n\n$N凝聚起天地间十万妖魔的无边力量，一式－十－万－神－魔 －如急电般劈向$n！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if (chance>random(300)) {
                msg = HIB  "\n$N"+HIB"手中$w"+HIB"幻出奇异的光华刺向$n！" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (chance>random(350)) {
                msg = HIR  "\n$N"+HIR"手中$w"HIR"发出摄人心魄的呼啸向$n"+HIR"劈去！" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (chance>random(400)) {
                msg = HIW  "\n$N"+HIW"手中$w"+HIW"竟然发出妙不可言的奇香扑向$n！" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (chance>random(450)) {
                msg = HIC  "\n十万诸魔齐在云端隐现，$N"+HIC"手中$w"+HIC"鬼神莫测已然到了$n"+HIC"的眼前！" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                if(!userp(me) && me->query("m_success/血鹦鹉")&& random(10)>3)
                        target->apply_condition("qicaibat",random(10)+10);
        }
        me->add_temp("apply/attack",-tmp-force);
        me->add_temp("apply/damage",-extra*3-force);
        me->set_temp("timer/shiwanshenmo",time());
        if (me->query_busy()<3) 
                me->start_busy(3);
       
        return 1;
}      