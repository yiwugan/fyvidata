 // void_sense.c
#include <ansi.h> 
inherit SSERVER;
int soul_flame(object me, object obj, int lvl, int counter);
int cast(object me, object target)
{
        int lvl,i, number;
        object env, *inv;
/*        if(me->query("class")!="yinghe")
                return notify_fail("ֻ��ӫ����ʿ�ſ���ʹ����ڤħ�䣡\n");*/
        if((int) me->query_skill("devil-spells",1) < 120)
                return notify_fail("�����ڤħ�䲻�����");
                
        lvl = (int) me->query_skill("spells");
        if( me->query("mana") < 110 )
                return notify_fail("��ķ���������\n");
        if( me->query("sen") <= 60 )
                return notify_fail("����񲻹���\n"); 
        me->add("mana", -100);
        me->receive_damage("sen", 50);
        message_vision(NOR CYN"$N��ɫ�������������������������������ħ�־�����ǰ������������״�� \n" NOR, me); 
        message_vision(BLU"�������ĵ�����·��ܵ���ħ�ֵ��ٻ��ӵ������ڶ��� \n$N��Χ��ʱ����˿ֲ����˼������� ", me);
        
        if(target)
                soul_flame(me, target, lvl,1);
        else
        {
                env = environment(me);
                inv = all_inventory(env);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]==me ) continue;
                        if( inv[i]->is_corpse() ) continue;
                        if( !inv[i]->is_character()) continue;
                        if( !inv[i]->is_fighting(me)) continue;                 
                        number++;
                        soul_flame(me, inv[i], lvl/number, 0);
                        
                }
        }
         
        if (userp(me)) me->start_busy(3) ;
        else  me->start_busy(1);
        return 1; 
} 
int soul_flame(object me, object obj, int lvl, int counter)
{
        int ratio;
        if (! obj->is_fighting() ) return 0;
        if (counter) message_vision(NOR BLU "\n�䶯�������$N���������ζ�����\n"NOR, obj);
        message_vision(HIC "\nһ�����䶯�����������߰������$N��\n"NOR, obj);
        if(obj->is_zombie()==1) {
                message_vision(RED "$N����һ�󽹳�ζ������ʱ���ɺںڵ�ľ̿��\n" NOR, obj);
                obj->die();
                return 1;
        }
        ratio = 100 + 100* (int) me->query("combat_exp") / (10 + (int) obj->query("combat_exp"));
        
        obj->set_temp("last_damage_from", me);
        obj->receive_wound("gin",lvl,me);
        obj->receive_wound("kee",lvl,me);
        obj->receive_wound("sen",lvl,me);
        
        COMBAT_D->report_status(obj); 
        return 1;
} 
