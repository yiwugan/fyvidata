 // feeblebolt.c
#include <ansi.h> 
inherit SSERVER; 
int cast(object me, object target)
{
        string msg;
        int damage, ap, dp,lvl;
        int extradam; 
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�����������\n"); 
        if((int)me->query_skill("spells") < 50 )
                return notify_fail("��ķ��������ߣ�\n");
        
        if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ַ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        lvl=me->query_skill("necromancy",1); 
        if((int)me->query("mana") < 25)
                return notify_fail("��ķ���������\n");
        if((int)me->query("sen") < 20 )
                return notify_fail("��ľ���û�а취��Ч���У�\n");
        if((int)me->query("mana") < 25+lvl/2)
                return notify_fail("��ķ���������\n");
        if((int)me->query("sen") < 20+lvl/2)
                return notify_fail("��ľ���û�а취��Ч���У�\n");
        
        if (lvl<100) {
                me->add("mana", -25);
                me->receive_damage("sen", 20);
        } else {
                me->add("mana", -25-(lvl-100)/2);
                me->receive_damage("sen", 20+(lvl-100)/2);
        }
        
        if( random(me->query("max_mana")) < 20 ) {
                write("��ʧ���ˡ�\n");
                return 1;
   }
        
        msg = HIW "$N�����૵��������ģ�����һ�ӣ����о���һ�Ű׹�����$n��\n\n" NOR; 
        ap = me->query_skill("spells");
        extradam = ap/2;
        ap = ( ap * ap / 10 ) * (int)me->query("sen") ;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_mana") / 8 + random(extradam);
                if (me->query("max_sen")<2000)  damage+= random(me->query("max_sen")/8);
                        else damage+= random(2000/8);
                damage = damage + random(damage);       
                if (lvl> 130 && me->query("combat_exp")<target->query("combat_exp"))
                        damage = damage*(me->query("combat_exp")/100)/(target->query("combat_exp")/100);
                if( damage > 0 ) {
                        msg +=  HIR "������͡���һ�����׹��$p����͸��������ϳ�һ�������ĺ���������£�\n"NOR;
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                } else
                        msg += "������͡���һ�����׹��$p����͸�������������Ϣ��������£�\n";
        } else
                msg += "���Ǳ�$n�㿪�ˡ�\n"; 
        message_vision(msg, me, target);
        if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
        } 
        me->start_busy(2);
        return 1;
} 
