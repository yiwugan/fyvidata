#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int damage,level,perp;
        object ob, room; 
        if(me->query("class")!="wolfmount")
                return notify_fail("ֻ����ɽ���Ӳ���ʹ�����潵����\n");
        level=(int)me->query_skill("wolf-curse",1);
        if(level < 100 )
                return notify_fail("��Ľ�ͷ�������ߣ�\n");
        
        if(!target) return notify_fail("������˭�������ͷ��\n");
        room=environment(target);
        if(room!=environment(me)) 
                return notify_fail("������˭�������ͷ��\n");
        
        if ( environment(me)->query("no_fly") || environment(target)->query("no_fly"))
                return notify_fail("�˵ز���ʹ���潵��\n"); 
        if (userp(target))
                return notify_fail("�潵��������������ϡ�\n");
        if(! target->is_character())
                return notify_fail("׷��������������ǲ��Ǿ��ú����ģ�\n"); 
        
        if (domain_file(file_name(environment(target)))=="eren2")
                return notify_fail("���˾���̫�ߣ��޷����潵��\n");
        if (target->is_corpse())
                return notify_fail("��ֻ��������������ͷ��\n");
                
        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ������\n");
        
        me->receive_damage("kee",100);
        me->start_busy(2);
        if(random(me->query("combat_exp"))>target->query("combat_exp")/4)
                {
                me->set_temp("chase_target",target);
                target->set_temp("chaser",me);
                perp=target->query_skill("perception",1);
           if (random(perp)>level/2) target->start_call_out( (: call_other, __FILE__, "warning", target:), 3);
                tell_object(me,HIW"���Ѿ��ɹ��Ķ�"+target->name()+"�����潵��\n"NOR);
                return 1;
                }
        else return notify_fail(HIW"�����ڲ���������ʧ���ˡ�\n"NOR);
}
                
                
                
void warning(object target)
{
        tell_object(target,HIR"      ���������ڰ��ж�ס����.\n"NOR);
}      
