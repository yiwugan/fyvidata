 inherit SSERVER;
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        int force, lvl;
        object obj;
        lvl = me->query_skill("bibo-force",1);
        if (lvl<80)
                return notify_fail("��ı̲��ķ����̫�\n");
                
        if( target != me)
                return notify_fail("��ֻ��Ϊ�Լ�������\n");
                
        force =(int) me->query("force");
        if( force <=100) return notify_fail("����������㡣\n");
        
        message_vision(HIW"$N�˹�������ͷ��ð������ĺ�������\n"NOR, me);       
        me->add("force", -100  );
        
        if (random(lvl) < 50)   return notify_fail("��ʧ���ˡ�\n");
                else    {
                        me->clear_condition();
                        write("��ɹ��ˣ�\n");
                        return 1;
                        }
        }              
