#include <ansi.h>
inherit NPC;
void use_poison(); 
void create()
{
    set_name("�۾���", ({ "cobra", "snake" }) );
    set("race", "Ұ��");
    set("age", 4);
    set("long", "һ���綾���۾��ߡ�\n");
    set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set_skill("dodge", 50);
    set("combat_exp", 5000000 + random(2000000));
        set("bellicosity", 300 );
    set("chat_chance_combat", 1);
    set("chat_msg_combat", ({
            (: use_poison :),
    }) );
    setup(); 
} 
void use_poison(){
    object *enemy, ob;
    string msg; 
    enemy = query_enemy();
    if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
    tell_object(ob,
"��������Ͼ�ʹ������һ��������������ӡ�ۡ�\n");
            ob->apply_condition("snake_poison", 
            (int)this_player()->query_condition("snake_poison")
            + random(3)+3);
}  
