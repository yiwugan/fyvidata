 // netherbolt.c
#include <ansi.h> 
inherit SSERVER; 
int cast(object me, object target)
{
        string msg;
        int damage, ap, dp,lvl;
        int dam,extradam; 
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�����������\n"); 
        if((int)me->query_skill("necromancy",1) < 20 )
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
        
        if (userp(me)) {
                if (lvl<100) {
                        me->add("mana", -25);
                        me->receive_damage("sen", 20);
                } else {
                        me->add("mana", -25-(lvl-100)/5);
                        me->receive_damage("sen", 20+(lvl-100)/5);
                }
        }
        
        if (me->query("mana")<0) me->set("mana",0);
        
   if( random(me->query("max_mana")) < 20 ) {
                write("��ʧ���ˡ�\n");
                return 1;
        } 
        msg = HIC "$N�����૵��������ģ�����һ�ӣ����о���һ���������$n��\n\n" NOR; 
        ap = me->query_skill("spells");
        dam = ap;
        ap = (  ap * ap /10  ) * (int)me->query("sen") ;
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                
                if (me->query_skill("necromancy",1)<185) {
                        extradam=dam/2;
                        damage = (int)me->query("max_mana") / 8 + random(extradam);
                        if (me->query("max_sen")<3000)  damage+= random(me->query("max_sen")/8);
                                else damage+= random(3000/8);
                        damage = damage + random(damage);       
//              average 693, lowest 175,  highest 1850*/
                } else 
                        damage=dam*2+random(dam*2);
//              average 1200, lowest 800, highest 1600                                  
//              message_vision("damage is "+(string)(damage),me); 
                if( me->query_skill("necromancy",1)>=185 ) {            
                        msg +=  HIR "������͡���һ��������$p"+HIR"����͸��������ϳ�һ���������߲ʹ�������������\n"
                                        "��ת�����ִ�$N"+HIR"����ע��$P"+HIR"�����ڣ�\n" NOR;
                        me->receive_heal("kee",target->receive_damage("kee", damage, me)/3);
                        target->receive_wound("kee", damage/3, me);
                } else {
                        msg += "������͡���һ��������$p����͸�������������Ϣ��������£�\n";
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/3, me);
                }
        } else
                msg += "���Ǳ�$n�㿪�ˡ�\n"; 
        message_vision(msg, me, target);
        if (damage>0) {
                target->set_temp("damaged_during_attack", 2);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,damage);
        }
        me->start_busy(2);
        return 1;
}     
