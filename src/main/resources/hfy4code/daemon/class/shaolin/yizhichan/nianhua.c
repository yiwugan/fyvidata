 //mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int count,int extra);
int perform(object me, object target)
{
        string msg;
        int extra;
        
        if(me->query("class")!="shaolin")
                return notify_fail("�黨�����־���������ô���ܻ�ʹ�أ�\n");
        extra = me->query_skill("yizhichan",1);
        if(extra<150) return notify_fail("��һָ������Ϊ�������޷�ʹ�����黨���ľ��С�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���黨��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query_temp("nianhua_beauty")+1>time())
                return notify_fail("�����񲻾����в���ʹ�á��黨��\n");        
        if(target->query_skill_mapped("dodge") == "anxiang-steps" && random(6)>1) {
                tell_object(me,HIM"\n�㿴�Ŷ��ַ���Ʈ�����Ӱ��ֻ�е������Ķ�ʣ���һָ��������ȥ��\n"NOR);
                me->set_temp("nianhua_beauty",time());
                return 1;
                }       
        message_vision(HIG"\n$N����ʳ����ָ�����ס�����黨֮״������ͬʱ������������$n���˹�ȥ��\n\n"NOR,me,target);
        begin_perform(me,target,3,extra);
        me->set_temp("nianhua_beauty",time());
        return 1;
        
}      
string *perform_msg=({
        YEL"ǧ˿���Ƶ�ָ��������Ϣ��Ϯ��$n��\n\n"NOR,
        YEL"���·��������󳪣�ָ���������������͵͵�������\n\n"NOR,
        YEL"������ָ������������¶�Ļ��꣬Ȼ��¶�����ʱ������Ҳ���Ʈɢ�ˡ�����������\n\n"NOR
        }); 
int begin_perform(object me,object target,int count,int extra)
{
        string msg;
   int enf,ext,enp;
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return 0;
        if(count)
        {
                msg=perform_msg[--count];       
                enf=me->query_skill("force");
                ext=extra*extra*extra+me->query("combat_exp");
                enp=target->query("combat_exp");
                message_vision(msg,me,target);
                if(random(ext+enp)>enp)
                {
                        message_vision(HIR"$n��һ����͵�ָ��һ����ֻ����ͷ������һ����\n"NOR,me,target);
                        target->receive_damage("kee",enf*2+random(enf*extra)/50);
                        COMBAT_D->report_status(target);
                }
                else
                        message_vision(HIC"$n����ָ�����ƣ�����������������һ���� \n\n"NOR,me,target);
                if (me->query_busy()<3) me->start_busy(3);
                if(random(2)) begin_perform(me,target,count,extra);
                else
                        call_out("begin_perform",1,me,target,count,extra);
                return 1;
        }
         
        return 1;
}  
