#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,mystr,yourstr,lvl;
        object weapon; 
        if (me->query("class")!="tieflag")
                return notify_fail ("�Ǵ�����Ӳ���ʹ�ã۷�����ӿ��\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷�����ӿ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = target->query_temp("weapon");
        if(!objectp(weapon)) return notify_fail("��Ķ���û���ñ�����\n");
        myexp = (int) me->query("combat_exp") / 1000;
        mystr = (int) me->query_str();
        yourexp = (int) target->query("combat_exp") / 1000;
        yourstr = (int) target->query_str();
        lvl = (int) me->query_skill("sword") / 150;
        if(lvl<1) lvl=1;
        msg = YEL "$N�Է�����֮��һ�ӣ�$n�ı�����֪��ô�������˵��£� \n" NOR;
     if(objectp(weapon) )
{
         if (me->query_skill_mapped("force") == "jiayiforce")
               if (( myexp * lvl * mystr) > (yourexp * yourstr) ) 
                {
                weapon->unequip();              
                weapon->move(environment(target));
                message_vision(msg, me, target);
                target->start_busy(1);
                }
                else message_vision(RED"$N�����Է�����֮��һ�ӣ���ͼ����$n������������\n\n���$n������$N����ͼ���ܿ���������һ��\n"NOR, me, target);
          else 
                if (( (myexp + random(myexp)/3) * mystr ) > (yourexp * yourstr) )
                {
                weapon->unequip();              
                weapon->move(environment(target));
                message_vision(msg, me, target);
                target->start_busy(1);
                }
                else message_vision(RED"$N�����Է�����֮��һ�ӣ���ͼ����$n������������\n\n���$n������$N����ͼ���ܿ���������һ����\n"NOR, me, target);
}
        else COMBAT_D->do_attack(target,me, TYPE_PERFORM);
        me->start_busy(2);
        return 1;
}      
