#include <ansi.h>
inherit NPC;
void bird_attack();
void create()
{
        set_name(HIG"ҹݺ"NOR, ({ "nightingale", "ye ying" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("yes_carry", 1);
        set("long", "һֻ������������ҹݺ��\n");
        set("limbs", ({ "ͷ��", "����", "β��", "���" }) );
        set("class", "yinghe");
        set("verbs", ({ "bite" }) );
        set("attitude", "friendly");
        set_skill("dodge", 250+random(100));
        set_skill("move", 450+random(200));
        set("combat_exp", 3000000+random(2000000));
        set("bellicosity", 300);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: bird_attack :),
        }) );
        set("chat_chance", 1);
        
        setup();
} 
void bird_attack(){
}   
