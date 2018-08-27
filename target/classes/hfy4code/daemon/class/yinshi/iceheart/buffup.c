 // silencer@fy
inherit SSERVER;
#include <ansi.h> 
int exert(object me, object target, int amount)
{
        int force, lvl, duration;
        int my_exp,your_exp;
        object obj; 
        lvl = me->query_skill("iceheart",1);
        if( lvl < 50)   return notify_fail("��ı��ľ�������졣\n"); 
        if (me->query("class")!="yinshi") lvl = lvl/2;
        amount = 300+ 15* (lvl-50); 
        force =(int) me->query("force") - (int) me->query("max_force");
        if( force <=lvl*3) return notify_fail("����������㡣\n");
        
        if (!target) target=me;
        
        if(!objectp(obj = present(target, environment(me))))
                        return notify_fail("����û������ˡ�\n");
        if (!obj->is_character() || obj->is_corpse() )
                        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
        if (target->query_temp("buffup/buffed_kee")==1)
                        return notify_fail("�����Ѿ����˹����ˡ�\n");   
        
        my_exp=me->query("combat_exp");
        your_exp=target->query("combat_exp");
        if (my_exp>your_exp*3 || my_exp<your_exp/3)
                return notify_fail("����֮�书�����̫Զ��,�����޷�����.\n");
        
        message_vision(HIW"$N�������˿�����������ľ������ߵġ����ľ�����\n"NOR, me);   
        
        if (target== me) me->add("force", -lvl*2 );
                else
        {       message_vision(HIW"$N���Ƶ���$n���ģ�����ԴԴ�����ش����Ĵ��˹�ȥ������\n"NOR, me,target);
                me->add("force", -lvl*3);
                amount= amount*2/3;
        }
        target->set_temp("buffup/buffed_kee",1);
        call_out("apply_effect",2, target, amount);
        me->start_busy(3);
   return 1;
}
 
        
void apply_effect(object target, int amount) {
        int kee;
        tell_object(target, HIR "�������һ�����������ͻȻע����������壡\n" NOR );
        kee = (int)target->query("max_kee");
        target->set("max_kee",kee+amount);
        target->set("eff_kee",target->query("eff_kee")+amount);
        target->set_temp("buffup/buffed_kee",1);
        call_out("remove_effect",180+amount/10, target,amount);
}  
void remove_effect(object target, int amount)
{
        tell_object(target, HIG "���������ֻ��������һ������������࣡\n" NOR );
        target->set("max_kee",(int)target->query("max_kee")-amount);
        if (target->query("eff_kee")>target->query("max_kee"))
                        target->set("eff_kee",target->query("max_kee"));
        if (target->query("kee")>target->query("max_kee"))
                        target->set("kee",target->query("max_kee"));
        target->delete_temp("buffup/buffed_kee");
} 
