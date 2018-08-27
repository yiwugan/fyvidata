#include <ansi.h>
inherit NPC;
string a_msg();
void use_poison();
void sonic_attack();
void create()
{
        set_name(HIB"��Ѫ����"NOR, ({ "soul bat","bat" }) );
        set("race", "Ұ��");
        set("age", 400);
        set("yes_carry", 1);
        set("long", "һֻ���ܳ������𡣱���ɫ��������΢��ӳ��������������
�����İ�͸����˫���ƺ�Ҳ͸�ŵ�����â��\n"); 
        set("limbs", ({ "ͷ��", "����", "β��", "���" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "heroism");
        set_skill("dodge", 250+random(100));
        set_skill("move", 450+random(200));
        set("combat_exp", 1000000+random(2000000));
        set("arrive_msg", "����ú�����˿˿�ķ�Ʈ����������ʲô���������㡣");
        set("leave_msg", "һ������������ƺ���ʲô����Ʈ��Զ����");
        set("bellicosity", 300);
        set("invisibility",1);
        set("self_go_msg", 1);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: sonic_attack :),
        }) );
        set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
                                (: sonic_attack :),
        }) ); 
        setup();
}  
void sonic_attack() {
        object *enemy, ob;
        string msg;
        int number_enemy, bat_exp;
        enemy = query_enemy();
   bat_exp = 1000000 + random((int) query("combat_exp"));
        number_enemy = sizeof(enemy); 
                        
        while(number_enemy--) {
                if( enemy[number_enemy] && living(enemy[number_enemy]) ) {
                        kill_ob(enemy[number_enemy]);
                        if( userp(enemy[number_enemy]) ) enemy[number_enemy]->fight_ob(this_object());
                        else enemy[number_enemy]->kill_ob(this_object()); 
                        if( bat_exp > (int)enemy[number_enemy]->query("combat_exp") ) {
                                tell_object(enemy[number_enemy],RED"����Ľ���������������������������û���׶���ѹǰ����ʹ��\n"NOR);
                                enemy[number_enemy]->receive_damage("kee", 1000+random(1000), this_object());
                                enemy[number_enemy]->receive_wound("sen", 700+random(1000), this_object());
                                COMBAT_D->report_status(enemy[number_enemy],1);
                        }
                }
        }
        start_busy(3);
}  
void suck_blood(object ob)
{
        object *enemy;
        string msg; 
        enemy = query_enemy();
        //if remove_call_out("suck_blood");
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        tell_object(ob,"�����һ���ʹ������һ������һ������ӡ�ۡ�\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("bat_poison",
                (int)this_player()->query_condition("bat_poison")
                + random(3)+3);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) 
                {
                        if (!query_leader() && userp(ob))
                        {
                                set_leader(ob);
                           kill_ob(ob);
                                call_out( "suck_blood", 1, ob);
                        } 
        }
} 
int random_move()
{
        //reset leader
        ::random_move();
        set_leader(0);
} 
void die(){
        message_vision("$N�˵�һ������һ�ɺ��̣�ת�ۼ�������ۣ���һֻ$N���۳��͡�\n", this_object());
        "/cmds/imm/full"->main(this_object(),"");
} 
void bat_die(object me){
        message_vision("�ƺ���һ�����ε�������������$N��ת˲��$N��ȥ���١�\n", this_object());
        me->set_temp("marks/yinghe_prepared", 1);
        destruct(this_object());
        return;
}   
