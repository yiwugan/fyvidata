#include <ansi.h>
inherit SSERVER;
int check_legit(object ob);  
int thunderspell(object me, object obj)
{
        int     spi, kar, kee, damage, spells; 
        message_vision(YEL "\nһ��������$N��ͷ�ϴ�����\n" NOR, obj);
        obj->receive_damage("sen", 0, me);
        spells = me->query_skill("spells");
        
        if(obj->is_ghost()) {
                message_vision(RED "$N�ҽ���һ������Ϊ�˻ҽ���\n" NOR, obj);
                obj->die();
                return 1;
        }
        
        if(obj->is_zombie()) {
                message_vision(RED "$N�ҽ���һ������Ϊ��һ̲Ѫˮ��\n" NOR, obj);
                obj->die();
                return 1;
        }
        
        if(obj->query("race")=="Ұ��") {
                kar = obj->query("kar");
                spi = obj->query("spi");
                damage = (31 - spi)*(spells/4)*(random(31-kar)+1)+100;
                if(damage <= 20) damage = 0;
                if(damage > 35) damage = 35;
                if(damage != 0) {
                        message_vision(RED "��������$N��ͷ�ϣ�\n" NOR, obj);
                        obj->receive_damage("kee", damage, me);
                        obj->set_temp("damaged_during_attack", 1);
                        COMBAT_D->report_status(obj);
                        if( !obj->is_fighting(me) ) {
                                obj->kill_ob(me);
                                me->kill_ob(obj);
                        }
                } else 
                        message_vision(RED "����$N����ˣ�\n" NOR, obj);
                return 1;
   }
        
        kar = obj->query("kar");
        spi = obj->query("spi");
        damage = (31 - spi)*(spells/10)*(random(30-kar)+1);
        if(damage < 0) damage = 0;
        if(damage > 20) damage = 20;
        if(damage != 0 && random(kar) < 20) {
                message_vision(RED "��������$N��ͷ�ϣ�\n" NOR, obj);
                obj->receive_damage("kee", damage, me);
                obj->set_temp("damaged_during_attack", 1);
                COMBAT_D->report_status(obj);
                if(!obj->is_fighting(me) ) {
                        if( living(obj) ) {
                                if( userp(obj) ) 
                                        obj->fight_ob(me);
                                else
                                        obj->kill_ob(me);
                        }
                        me->kill_ob(obj);
                }
        } else 
                message_vision(RED "����$N����ˣ�\n" NOR, obj);
        return 1;
        
} 
int cast(object me)
{
        string  msg;
        object  env;
        object  *inv, *myteam;
        int     i,k,j; 
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�����������\n"); 
        if((int)me->query_skill("necromancy",1) < 100 )
                return notify_fail("��ķ��������ߣ�\n"); 
        if((int)me->query("mana") < 200 )
                return notify_fail("��ķ���������\n"); 
        if((int)me->query("kee") < 100 )
                return notify_fail("�������������\n"); 
   if((int)me->query("sen") < 100 )
                return notify_fail("��ľ���û�а취��Ч���У�\n"); 
        me->add("mana", -200);
        me->receive_damage("sen", 90); 
        msg = YEL "$N�Ų������˫���ճɷ�ħӡ�������૵��������ģ�\n" NOR;
        msg = msg + RED "�͵�˫��һ�ӣ����ϴ����������磡\n\n" NOR;
        message_vision(msg, me);
        
        env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if (check_legit(inv[i])) continue;
                thunderspell(me, inv[i]);
        }
        me->start_busy(3);
        return 1;
} 
int check_legit(object ob) {
        object me, *team, owner;
        me=this_player();
        
        if (ob->is_corpse() || !ob->is_character() || ob==me) return 1;
//      if (owner=ob->query("possessed"))
//      if (owner==me) return 1;
        
        team=me->query_team();
//        if (sizeof(team)==0) team=({me});  
        if (team) {
                if (member_array(ob,team)!=-1) return 1;
                if (owner=ob->query("possessed"))
                if (member_array(owner,team)!=-1) return 1;
        }
        return 0;
}       
