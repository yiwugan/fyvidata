#include <ansi.h>
inherit NPC;
void use_poison(); 
void create()
{
    set_name("����", ({ "boa", "snake" }) );
    set("race", "Ұ��");
    set("age", 4);
    set("long", "һ��ˮͰ��ϸ�Ĵ����ߡ�\n");
    set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
    set("verbs", ({ "bite" }) );
//    set("attitude", "aggressive");
    set_skill("dodge", 50);
    set("combat_exp", 5000000 + random(2000000));
        set("bellicosity", 300 ); 
    setup(); 
}      
