 // void_sense.c
#include <ansi.h> 
inherit SSERVER;
int bbqthem(object me, object obj);
int cast(object me, object target)
{
        int lvl,i;
        object env, *inv;
        if(me->query("class")!="lama")
                return notify_fail("ֻ�д����µĵ��Ӳſ���ʹ�����ԣ�\n");
        if((int) me->query_skill("kwan-yin-spells",1) < 120)
                return notify_fail("��Ĺ����������䲻�����");
        if (!me->is_fighting())
                return notify_fail("���ء�ֻ����ս����ʹ�á�\n"); 
        lvl = (int) me->query_skill("spells");
        if( me->query("mana") < 200 )
                return notify_fail("��ķ���������\n");
        if( me->query("max_sen") <= 200 )
                return notify_fail("����񲻹���\n"); 
        if (target==me)
                        return notify_fail("��Ҫ���ˣ�\n");
        if (userp(me)) me->add("mana", -200);
        if (userp(me)) me->receive_damage("sen", 200);
        
        message_vision(WHT"$N����һ�����ء������ֻ��ģ�����ƽ̯�����Ǽ��������գ������һ�� 
ֻ�������İ׹�͸�����⡣ \n" NOR, me);
        message_vision(HIW "������$N��һ�ɵ����İ�������Χ����\n" NOR, me);
        if(target) {
                bbqthem(me, target);
        }
        else
        {
                env = environment(me);
                inv = all_inventory(env);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]==me ) continue;
                        if( inv[i]->is_corpse() ) continue;
                        if( !inv[i]->is_character()) continue;
                        if( !inv[i]->is_fighting(me)) continue;                 
                        bbqthem(me, inv[i]);
           }
        }
        if(me->query_busy()<5) me->start_busy(5); 
        return 1; 
} 
int bbqthem(object me, object obj)
{
        int magic,objsen;
        
        magic = (int) me->query_skill("spells");        
        
        message_vision(MAG "\n������"NOR+"$N"+MAG"��ͷ������������ע��$n�����ڣ�\n" NOR, obj,me);
        obj->receive_damage("sen", 1, me);
        
        if(obj->is_ghost()==1 && obj->query("combat_exp")<random(me->query("combat_exp"))*10) {
                message_vision(WHT "$N�漴���������Ӱ���٣�\n" NOR, obj);
                me->add("kee",obj->query("sen")/10);
                obj->die();
                return 1;
        }
        if(obj->is_zombie()==1 && obj->query("combat_exp")<random(me->query("combat_exp"))*10) {
                message_vision(WHT "$N����ȫ��������������һ����ľͷ�Ƶص��£���Ϊ��һ̲Ѫˮ��\n" NOR, obj);
                me->add("kee",obj->query("kee")/10);
                obj->die();
                return 1;
        }
        
        magic = random(magic*2) + magic;
        obj->receive_damage("sen",magic,me);
        
        me->receive_curing("kee", magic);
        if (me->query("kee")<me->query("eff_kee"))   me->add("kee",magic);
                else me->set("kee",me->query("eff_kee"));
        
        COMBAT_D->report_status(obj);
        COMBAT_D->win_lose_check(me,obj,1);
        return 1;
}        
