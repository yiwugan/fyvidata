#include <ansi.h>
inherit NPC;
void use_poison();
void sonic_attack();
void create()
{
    set_name(HIY"��������"NOR, ({ "sand guardian" }) );
//      set_title("ӫ���ػ���ʿ");
    set("age", 400);
    set("long", "��ɫ�������ͷ�ϵĽǣ����˴�˵�е����롣\n");
    set("attitude", "heroism");
    set_skill("dodge", 250+random(100));
    set_skill("move", 450+random(200));
    set("combat_exp", 1000000+random(2000000));
        set("bellicosity", 300);
        set("invisibility",1);
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
//            (: sonic_attack :),
    }) ); 
    setup();
} 
/*void sonic_attack() {
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
                                enemy[number_enemy]->revieve_damage(kee, 1000+random(1000), this_object());
                                enemy[number_enemy]->revieve_wound(sen, 700+random(1000), this_object());
                                COMBAT_D->report_status(enemy[number_enemy],1);
                   }
                }
        }
        start_busy(3);
}*/ 
