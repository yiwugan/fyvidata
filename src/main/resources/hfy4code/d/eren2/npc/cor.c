#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("����", ({ "gator" }) );
        set("race", "Ұ��");
        set("age", 400);
        set("long", "һ���ɳ������㣬��֪���ⰵ�����������˶�á�\n");
        set("limbs", ({ "ͷ��", "����", "β��", "�۾�" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set("combat_exp",1000000);
        set("gin",5000);
        set("kee",5000);
        set("sen",5000);
        set("cps",100);
        set("cor",50);
        set("str",80);
        add_temp("apply/dodge",300);
        add_temp("apply/attack",300);
        setup();
        carry_object(__DIR__"obj/gatorarmor1");
}    
