 // silencer@fy
inherit SSERVER;
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        int force, lvl, duration;
        int my_exp,your_exp;
        object obj;
        int kee_record; 
//      if(me->query("class")!="yinshi")
//              return notify_fail("ֻ�е����ȵĵ��Ӳ���ʩ���ľ���\n");
        lvl = me->query_skill("iceheart",1);
        if( lvl < 50) 
                return notify_fail("��ı��ľ�������졣\n");
        
        duration = 2+(lvl-50)/10;
        if(me->query("class")!="yinshi")
                duration= duration / 2; 
        force =(int) me->query("force") - (int) me->query("max_force");
        if( force <=lvl*3) return notify_fail("����������㡣\n");
        
        if (target == me)
        {       
        if   (me->query_temp("till_death/buffed_kee")==1)
                        return notify_fail("���Ѿ����˹����ˡ�\n");
        
        kee_record=me->query("max_kee");
        me->set_temp("buffed_kee_record",kee_record);   
        message_vision(HIW"$N�������˿�����������ľ������ߵġ����ľ�����\n"NOR, me);   
        me->add("force", -lvl*2 );
        me->apply_condition("buffed",duration);
        }       
        else
        {
                if(!objectp(obj = present(target, environment(me))))
                        return notify_fail("����û������ˡ�\n");
                if( !obj->is_character() || obj->is_corpse() )
                        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
                if   (target->query_temp("till_death/buffed_kee")==1)
                        return notify_fail("�Է��Ѿ����˹����ˡ�\n");   
           my_exp=me->query("combat_exp");
                your_exp=target->query("combat_exp");
                if (my_exp>your_exp*3 || my_exp<your_exp/3)
                        return notify_fail("����֮�书�����̫Զ��,�����޷�����.\n");
                message_vision(HIW"$N���Ƶ���$n���ģ�����ԴԴ�����ش����Ĵ��˹�ȥ������\n"NOR, me,target);
                me->add("force", -lvl*3  );
                target->apply_condition("buffed",duration);
                }
        me->start_busy(3);
        return 1;
}
       
