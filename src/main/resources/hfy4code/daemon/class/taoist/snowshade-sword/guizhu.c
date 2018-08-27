#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string  msg;
        object  weapon;
        int skill;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۹����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        skill=me->query_skill("snowshade-sword",1);
        if(skill<50)
                return notify_fail("���ѩӰ������Ϊ̫���ˣ��޷�ʹ�ã۹���ݣ�");
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�ã۹���ݡ�\n");
        
        if( (int) me->query("mana") <skill*3) return notify_fail("��ķ������㡣\n");
        
        msg = HIR "$N�ȵ����������ˣ��ӱ���һ�У�\n" NOR;
        if (weapon = me->query_temp("weapon"))
                msg = msg + HIW "$N���е�"NOR+weapon->name()+HIW"���ַɳ�����ƾ�ջ���һ��ҫ�۵Ĺ⻪��\n\n" NOR;
        message_vision(msg, me);
        target->receive_damage("sen", 0, me);
        if(target->is_zombie()==1) {
                me->add("mana", - 100);
                message_vision(HIW "��͸���������������â��$N����ɢ�������\n" NOR, target);
                target->die();
                return 1;
        } 
        else
                me->add("mana", - skill*3);
                message_vision(HIW "��͸�������$Nȫ��һ�𣬷·��е�겻���ᡣ\n" NOR, target);
		        target->receive_damage("sen", skill*5+random(skill*5), me);
        if(me->query_busy()<2) me->start_busy(2);
        return 1;
        
}        
