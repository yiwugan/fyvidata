#include <ansi.h>
inherit F_CLEAN_UP;  
int exert(object me,object target,int amount)
{
        int extra; 
        if(me->query("class")!="shenshui"&& userp(me))
                return notify_fail("ֻ����ˮ�����Ӳ���ʹ���������������ľ�����\n");
        
        if(me->query_temp("nine-moon-force_poison"))
                return notify_fail("���Ѿ���ʩչ�������������ˡ�\n");
        
        if (me->query_skill("nine-moon-force",1)<150)
                return notify_fail("��ľ����ľ�̫�\n");
        
        if (me->query_skill("nine-moon-claw",1)<120)
                return notify_fail("��ľ����׹�ץ����������\n");
                
        if (me->query_skill("nine-moon-spirit",1)<150)
                return notify_fail("����Ů�񹦲���������\n");
        
        if (me->query("force") < 300)
                return notify_fail("�������������\n");
        
        extra = me->query_skill("force");
        extra= extra+random(extra);
        extra= extra*2;
             
        me->add("force", -300);
        message_vision(MAG"$N�Ŀ��Ϣ����������ľ���һ�㵭����������$N��Χһ�����š�\n"NOR,me);
        
        
        me->add_temp("nine-moon-force_poison",extra);
        call_out("remove_effect",extra,me,extra);
        return 1;
} 
int remove_effect(object me,int extra)
{
        if(!me) return 0;
        me->add_temp("nine-moon-force_poison",-extra);
        tell_object(me,"��ġ�������������Ч��ʧ�ˡ���\n");
   return 1;
}  
