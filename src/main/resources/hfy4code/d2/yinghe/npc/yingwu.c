#include <ansi.h>
inherit NPC;
void use_poison(); 
void create()
{
    set_name(HIR"Ѫ����"NOR, ({ "xue yingwu", "yingwu" }) );
    set("race", "Ұ��");
    set("age", 4);
    set("long", "Ѫ������ġ�\n");
    set("limbs", ({ "ͷ��", "����", "β��", "צ��" }) );
    set("verbs", ({ "bite" }) );
    set_skill("dodge", 500);
    set("combat_exp", 5000000 + random(2000000));
        set("bellicosity", 300 );
    set("chat_chance_combat", 1);
    set("chat_msg_combat", ({
    }) );
    setup(); 
}   
