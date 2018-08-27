#include <ansi.h>
#include <combat.h>
inherit SSERVER;
static object *enemy = ({});
int perform(object me, object target1,object target2)
{
        string msg;                                
        int extra;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("ill-quan",1);
        if ( extra < 50) return notify_fail("��Ĳ�άĦȭ���������죡\n");
        
        
        enemy=me->query_enemy();
        if (sizeof(enemy)<2) return notify_fail("�����ͬʱ���������ϵĵ���ս������ʹ��Ǭ��Ų�ƣ�\n");
        if( !target1 && target2) return notify_fail("�����ͬʱָ����������\n");
        if( !target2 && target1) return notify_fail("�����ͬʱָ����������\n");
        if(!target1 && !target2)
        {
           target1=enemy[0];
           target2=enemy[1];
         }
        if( !target1 || !target2
        ||      !target1->is_character() || !target2->is_character()
        ||      !me->is_fighting(target1) || !me->is_fighting(target2))
                return notify_fail("��Ǭ��Ų�ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query("force")<=100) return notify_fail("����������㣬�޷��������˹��ƣ�\n");
        me->add("force",-100);
        message_vision("$Nʹ����άĦȭ�Ĳ���֮�ء�Ǭ��Ų�ơ�\n",me);
                
        if (random(me->query("combat_exp")*(extra/30+1))>target1->query("combat_exp/30") && (target1->query("ill_boss") < 2))
        {
        	
          message_vision(HIY "$N���ִ���$n�Ĺ��ƣ�ʹ֮����"+target2->name()+"��\n" NOR,me,target1);
          COMBAT_D->do_attack(target1,target2, TYPE_PERFORM, 0);  
          target1->receive_damage("kee",1000,me);
          target1->start_busy(1);
        }
        else
        {
          message_vision("��$n����$N����ͼ�����Ʒ���������\n",me,target1);
          COMBAT_D->do_attack(target1,me,TYPE_PERFORM, 0);
        }
        
              
        if (random(me->query("combat_exp")*(extra/30+1))>target2->query("combat_exp/30")&&(target1->query("ill_boss") < 2))
        {
        	
          message_vision(HIY "$N���ִ���$n�Ĺ��ƣ�ʹ֮����"+target1->name()+"��\n" NOR,me,target2);
          COMBAT_D->do_attack(target2,target1, TYPE_PERFORM, 0);  
          target2->receive_damage("kee",1000,me);
          target2->start_busy(1);
        }
        else
        {
          message_vision("��$n����$N����ͼ�����Ʒ���������\n",me,target2);
          COMBAT_D->do_attack(target2,me,TYPE_PERFORM, 0);
        }
        return 1;
}      
