 // sacrifice.c silencer@fy
#include <ansi.h> 
inherit SSERVER; 
int cast(object me, object target)
{ 
        object ding; 
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�����������\n");
        if(me->is_fighting()) 
                return notify_fail("ս���в���ʩ�˷�.\n");
        if((int)me->query_skill("necromancy",1) < 120 )
                return notify_fail("���������������ߣ�\n");
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ���������\n");
        if (!target->query("env/sacrifice"))
                return notify_fail("���˲�Ը�������Լ���\n"); 
        if (target->query("combat_exp")<1500000)
                return notify_fail("���˹���̫ǳ,ֻ�ܰװ�����.\n");
        if (target->query("death/sacrifice_time")+86400>time())
                return notify_fail("���������������������پ���һ�ա�\n");     
        if( !objectp(ding = present("ding", environment(me))) )
                        return notify_fail("ֻ�����б���֮��ʩ�˷���\n");
        if((int)me->query("mana") < 500 )
                return notify_fail("��ķ���������\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("����񲻹���\n"); 
        me->add("mana", -500);
        me->receive_damage("sen", 500);
        me->start_busy(5);
        target->start_busy(5);
        
        message_vision(HIW"\n$N��ϥ���������״�Ŀ��Ĭ�����������Ϊ�ˣ�������˭��������\n"NOR,target);
        message_vision(HIY"$N�����૵��������ģ�����һ�ӣ����о���һ�Ž������$n��\n" NOR,me,target);
        message_vision(HIY"�����$N����һ���������뱦��֮�ڡ�\n"NOR,target);
        message_vision(YEL"$N����ɫɲ�Ǽ��ή��ȥ��\n"NOR+HIR"$N����.\n"NOR,target);
        call_out("sacrifice_die",1,target);
        call_out("sacrifice_pill", 3 ,target);
   return 1;
} 
void sacrifice_die(object victim)
{
                int combat_exp, combat_pot; 
                victim->set("bellicosity", 0);  
                combat_exp = victim->query("combat_exp");
                combat_pot = victim->query("potential") - victim->query("learned_points");
                if(combat_pot < 0) {
                        combat_pot = 0;
                }
                
                if(combat_exp < 20000) {
                        victim->add("combat_exp", -(int)(combat_exp * 2 / 100)); 
                } else if(combat_exp < 200000) {
                        victim->add("combat_exp", -(int)(combat_exp * 2 / 100));
                        victim->add("potential", -(int)(combat_pot * 25 / 100));                
                
                } else if(combat_exp < 1000000) {
                        victim->add("combat_exp", -(int)(combat_exp * 3 / 100));
                        victim->add("potential", -(int)(combat_pot * 25 / 100));                
                
                } else {
                        victim->add("combat_exp", -(int)(combat_exp * 3 / 100));
                        victim->add("potential", -(int)(combat_pot * 50 / 100));                
                
                }
                victim->skill_death_penalty(combat_exp);
                victim->set("env/sacrifice",0);
                victim->set("death/sacrifice_time",time());
                victim->unconcious();
}  
void sacrifice_pill(object victim)
{
        object pill;
  
        seteuid(getuid());
        pill= new("/obj/item/sacrifice_pill");
        pill->move(victim);
        message_vision( HIY "\n\nһ��"+pill->name()+HIY"�Ӷ���Ծ��������$N���ġ�\n" NOR, victim);
       
}
                   
