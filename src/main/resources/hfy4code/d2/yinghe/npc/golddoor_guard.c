#include <ansi.h>
inherit NPC;
void use_poison();
void sonic_attack();
void create()
{
    set_name(HIY"�����ʿ"NOR, ({ "golddoor guardian", "guard" }) );
//      set_title("ӫ���ػ���ʿ");
    set("age", 400);
    set("long", "һ�������׵���ʿ����Ŀ�����ȫ����ס����ֵ������ı�����һ˫����\n");
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
