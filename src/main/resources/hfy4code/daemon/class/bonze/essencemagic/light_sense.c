#include <ansi.h>
inherit SSERVER;
int bbqthem(object me, object obj);
int check_legit( object ob); 
int conjure(object me, object target)
{
        int lvl,i,j,k;
        
        object env, *inv, obj;
        object *myteam;
        string id_enemy;
        
if(me->query("class")!="bonze" && me->query("class")!="yinshi" )
                return notify_fail("ֻ�еõ���ɮ����������ʿ�ſ���ʹ�ù�ʶ��ͨ��\n");
        
        lvl = (int) me->query_skill("magic");
        lvl += (int) me->query("spi");
        if((int) me->query_skill("essencemagic",1) < 120)
                return notify_fail("��İ�ʶ��ͨ�������");
        if( me->query("atman") < 300 )
                return notify_fail("�������������\n");
        if( me->query("max_gin") <= 50 )
                return notify_fail("��ľ�������\n");
        me->add("atman", -300);
        me->receive_damage("gin", 50);
        message_vision(HIW "$N�ڿշ��𣬱���һ��������\n" NOR, me);
        
        env = environment(me);
        inv = all_inventory(env);
                
        if (lvl <= random(300))
        {
                for(i=0; i<sizeof(inv); i++) {
                        if (check_legit(inv[i])) continue;
                        inv[i]->kill_ob(me);
                        me->kill_ob(inv[i]);
                }
                me->start_busy(2);
                return notify_fail("�����������߶�ʧ���ˣ�\n");
        }
   
        message_vision(HIR "������$Nȫ�������ȵ�Ѫ���â������\n\n" NOR, me);
        
        for(i=0; i<sizeof(inv); i++) {
                if (check_legit(inv[i])) continue;
                inv[i]->kill_ob(me);
                me->kill_ob(inv[i]);
                if (me->is_busy()) 
                        return notify_fail("��Ĺ�ʶ������ˣ�����\n");
                bbqthem(me, inv[i]);
        }
        if(me->query_busy()<5) me->start_busy(5); 
        return 1; 
} 
int check_legit(object ob) {
        object me, *team, owner;
        me=this_player();
        
        if (ob->is_corpse() || !ob->is_character() || ob==me) return 1;
        if (owner=ob->query("possessed"))
        if (owner==me) return 1;
        
        team=me->query_team();
        if (team) {
                if (member_array(ob,team)!=-1) return 1;
                if (owner=ob->query("possessed"))
                if (member_array(owner,team)!=-1) return 1;
        }
        return 0;
}
         
int bbqthem(object me, object obj)
{
        int magic;
        string id_enemy;
        magic = (int) me->query_skill("magic");
        message_vision(HIR "\n���ȵĺ��������������$N��\n" NOR, obj);
        obj->receive_damage("sen", 0, me);
        
        if(obj->is_ghost() && obj->query("combat_exp")<random(me->query("combat_exp"))*10) {
                message_vision(WHT "$N�ҽ���һ������Ϊ�˻ҽ���\n" NOR, obj);
                obj->die();
        
                return 1;
        }
        if(obj->is_zombie() && obj->query("combat_exp")<random(me->query("combat_exp"))*10) {
                message_vision(RED "$N�ҽ���һ������Ϊ��һ̲Ѫˮ��\n" NOR, obj);
                obj->die();
                
                return 1;
        }
        
        magic = 4*random(magic) + magic;
        obj->receive_damage("sen",magic,me);
        obj->set_temp("damaged_during_attack", 1);
        obj->set_temp("last_damage_from",me);
        COMBAT_D->report_status(obj);
        
        return 1;
}    
