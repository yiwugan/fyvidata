 // heart_sense.c
// silencer@fy4 -------- this is the revive skill ------------ 
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
        int skill,exp_recovered,pot_recovered;
        int extra,i,my_score,his_exp,my_loss;
        object *inv;
        
//      if(me->query("class")!="bonze")
//              return notify_fail("ֻ���˹����µĵ��Ӳſ���ʹ�ð�ʶ��ͨ��\n");
        if((int) me->query_skill("essencemagic",1) < 150)
                return notify_fail("��İ�ʶ��ͨ�������");
        if ((int)me->query("score")<20000)
                return notify_fail("������۲�����(20000)��\n");
        if( !target || !target->is_character() ||target->is_corpse())
                return notify_fail("��Ҫ��˭ʹ����ʶ��ͨ��\n");
        if( !target->is_ghost())
                return notify_fail("��ʶ��ͨ�������ڻ������ϡ�\n");
        my_score=me->query("score");
        his_exp=target->query("combat_exp");
        if (his_exp<500000) my_loss=0;
                else my_loss=(int)his_exp/10000;         
           if( my_loss >= 1000) my_loss = 1000;
        if (target==me && me->query("combat_exp")>5000000) my_loss=1000;
        if( !userp(target))
                return notify_fail("����ֻͨ������������ϡ�\n");       
        if( (int)target->query("death/time")+ 10800  < time())
                return notify_fail("̫���ˣ����������Ѿ���ʧ���Ȳ����ˡ�������ʱ��������Сʱ�ڣ�\n");
        if( (int)me->query("atman") < 500 ) 
                return notify_fail("�������������\n");
        if( me->query("sen") <= 10 )
                return notify_fail("����񲻹���\n");
        if (!target->query("env/revive"))
                return notify_fail("���˲�Ը�ⱻ��ʩ��ʶ��ͨ������Ҫ�Է�Set revive 1��\n"); 
                
        me->add("atman", -500);
        me->receive_damage("sen", 5);
                
        exp_recovered=target->query("death/exp_lost");
   pot_recovered=target->query("death/pot_lost");
        
        
        inv = all_inventory(this_player());
        for(i=0;i<sizeof(inv);i++) {
                if (inv[i]->query("id")=="sacrifice pill")
                {
                destruct(inv[i]);
                message_vision(HIY"$N��������,"NOR+HIR"����"NOR+HIY"�����Ľ����ڻ�.\n"NOR,me);
                extra=140;
                break;
                }
        }
        skill = me->query_skill("essencemagic",1);
        if (skill>200) skill=200;  // cap the skill, prevent overflow
        
        exp_recovered=(int)(exp_recovered*(skill+extra)/400);
        pot_recovered=(int)(pot_recovered*(skill+extra)/400);
                        
        if(me->query("class")!="bonze") {
                exp_recovered = (int)(exp_recovered/2);
                pot_recovered = (int)(pot_recovered/2);
        }
        
        me->add("score",-my_loss);
        
        message_vision( HIY "$Nһ�ַ���$n���������, һ������$n�ĺ���, �����۾���������...\n" NOR, me, target);
        target->add("combat_exp", exp_recovered);
        target->add("potential", pot_recovered);
        target->set("death/time",0);
        target->set("death/exp_lost",0);
        target->set("death/pot_lost",0);
        target->reincarnate();
        message_vision( HIW "$N������ҵز����ţ���Ȼ��һ����âע��$N�Ķ��š�\n",target);
        message_vision( HIW "��âԽ��Խǿ�ҡ�������\n",target);
        message_vision( HIR "$N�����ˣ���\n"NOR,target);
        me->start_busy(3);
        return 1;
}   
/*int conjure(object me, object target)
{ 
        if(me->query("class")!="bonze")
                return notify_fail("ֻ���˹����µĵ��Ӳſ���ʹ�ð�ʶ��ͨ��\n"); 
        if( !target || !target->is_character() )
                return notify_fail("��Ҫ��˭ʹ����ʶ��ͨ��\n");
        if( target->is_corpse() )
                return notify_fail("�������ˣ�ֻ�л��˲��ܾ��ѡ�\n");
        if((int) me->query_skill("essencemagic",1) < 80)
                return notify_fail("��İ�ʶ��ͨ�������");
        if( (int)me->query("atman") < 50 ) return notify_fail("�������������\n");
        if( me->query("sen") <= 30 )
                return notify_fail("����񲻹���\n");
        me->add("atman", -50);
        me->receive_damage("sen", 30);
        message_vision( HIY "$Nһ�ַ���$n���������, һ������$n�ĺ���, �����۾���������...\n" NOR, me, target);
        if( random(me->query("max_atman")) > 100 )
                target->revive();
        else
                me->unconcious();
        if( me->is_fighting() )
                me->start_busy(3);
        return 1;
}*/    
