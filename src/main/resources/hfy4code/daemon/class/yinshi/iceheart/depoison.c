 // recover.c
// inherit "/daemon/condition/generic_condition";
inherit SSERVER;
#include <ansi.h>
#include <condition.h> 
int exert(object me, object target, int amount)
{
        int force, lvl;
        object obj;
        lvl = me->query_skill("iceheart",1);
        if( target != me && lvl < 100) return 
                notify_fail("��Ĺ���������Ϊ���˱ƶ���\n");
                
        force =(int) me->query("force");
        if( force <=100) 
                return notify_fail("����������㡣\n");
        
        if (target == me)
        {
        message_vision(HIW"$N�˹�������ͷ��ð������ĺ�������\n"NOR, me);       
        me->add("force", -100  );
        if (random(lvl) < 20)   return notify_fail("��ʧ���ˡ�\n");
                else    {
                        me->clear_condition();
                        if (me->query_condition("tianyi"))
                                me->clear_condition_type(BLOOD_POISON);
                        write("��ɹ��ˣ�\n");
                        return 1;
                        }
        }       
        else
        {
                if(!objectp(obj = present(target, environment(me))))
                        return notify_fail("����û������ˡ�\n"); 
                if( !obj->is_character() || obj->is_corpse() )
                        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
                
                message_vision(HIW"$Nһ�ư���$n�����˹�������ͷ��ð������ĺ���������\n"NOR, me,target);
                me->add("force", -150  );
                if (random(lvl)< 60)    return notify_fail("��ʧ���ˡ�\n");
           else    {
                target->clear_condition();
                message_vision(HIC"$N�������£��۵�һ���³�һ�ں�Ѫ�����ϵ���������ɢȥ������\n"NOR, target);
                write("��ɹ��ˣ�\n");
                return 1;
                }
        } 
} 
