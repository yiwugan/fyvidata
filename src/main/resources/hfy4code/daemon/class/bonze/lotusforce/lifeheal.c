 // lifeheal.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int exert(object me, object target, int amount)
{
        int level,i, n,add;
        object *enemy, *mem;
        
        if(me->query("class")!="bonze")
                return notify_fail("ֻ���˹����µĵ��Ӳ����ô��ķ���\n");
        level=me->query_skill("lotusforce",1)/50+1;
        if (level<2) 
                return notify_fail("��������ķ�̫���ˡ�\n");
        if( !target )                                                                           
                target=me;
        
        mem = me->query_team();
        if (!mem && target!=me)
                 return notify_fail("��ֻ�ܸ�ͬһ�����е������ˡ�\n");
        
        if (target!=me) {
        for(i=0;i<sizeof(mem);i++) {
                if (target!=mem[i]) n=n+1;
                }
        if (n>=sizeof(mem)) 
                return notify_fail("��ֻ�ܸ�ͬһ�����е������ˡ�\n");
        }
                
        
        if( (int)me->query("force") < 250 )
                return notify_fail("�������������\n");
        me->add("force", -250);
        me->set("force_factor", 0);     
        if (target!=me)
        message_vision(HIY "$N�����ڹ�������������$n���ģ������ؽ���������$n����....\n\n"NOR,me,target);
        else
        message_vision(HIY "$N�����ڹ��������ؽ�������������ת....\n\n"NOR,me);
        call_out("heal_him", 4, me, target, level);
        me->start_busy(1);
   if( target->is_fighting()) {
                enemy = target->query_enemy();
                for (i=0;i<sizeof(enemy);i++) {
                        me->kill_ob(enemy[i]);  
                        enemy[i]->kill_ob(me);
                }       
        }       
        return 1;
}  
int heal_him(object me, object target, int level)
{
        int amount;
//      amount=target->query("max_kee")/20*level;
        amount=1000;
        if (!present(target,environment(me))) {
                tell_object(me,"��Ҫ���ε����Ѿ����������ˡ�\n");
                return notify_fail("");
                }
        if (target!=me)
        message_vision(HIY"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me,target);
        else 
        message_vision(HIY"���˲��ã�$N�³�һ����Ѫ����ɫ������������ˡ�\n"NOR,me);
        target->receive_curing("kee", amount);
        if (target->query("kee")+ amount<target->query("max_kee"))
                target->add("kee",amount);
                else target->set("kee",target->query("max_kee"));       
}   
