#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me,object target,int amount)
{
        object *ob;
        int i, extra; 
        if(me->query("class")!="legend"&& userp(me))
                return notify_fail("ֻ����ѩɽׯ�ĵ��Ӳ��ܹ�ʹ�þ�������Ρ�\n"); 
        if(me->query_temp("qidaoforce_juqi"))
                return notify_fail("���Ѿ���ʩչ���Ƶ��书�ˡ�\n");
        
        if( (int)me->query("force") < 600 )
                return notify_fail("�������������\n");
        extra = me->query_skill("force");
      
        me->add("force", -600);
        
        
        if(me->query("family/master_id")=="master xuerui") {
                message_vision(HIG"$N˫�����棬����������չ������Ө����ɫ��â����໺����ɢ����������\n"NOR,me);
                me->add_temp("qidaoforce_diemeng",extra/10+random(extra/5));
        } else 
                message_vision(HIW"$N�˾����������ۣ�ȫ������������һ���������޵İ���������\n"NOR,me);
        
        extra= extra+random(extra);
//      320+ random(320);
        me->add_temp("qidaoforce_juqi",extra);
        call_out("remove_effect",extra/5,me,extra);
        return 1;
} 
int remove_effect(object me,int extra)
{
        if(!me) return 0;
        me->delete_temp("qidaoforce_juqi");
        me->delete_temp("qidaoforce_diemeng");
        if(me->query("family/master_id")=="master xuerui") 
                tell_object(me,"��"+HIG"����"NOR+"��Ч���Ѿ���ʧ�ˡ�\n");
                else 
                        tell_object(me,"��"+HIW"����"NOR+"��Ч���Ѿ���ʧ�ˡ�\n");
        return 1;
}
