// taijian.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("С̫��", ({ "xiao taijian","taijian" }) );
        set("gender", "����" );
        set("age", 14);
        set("long",
                "����һ���빬���õ�С̫�࣬��δͨ���¡�\n");
        set("title","�ʹ�");
        set("int",14);
        set("str",12);
        set("cor",14);
        set("int",20);
        set("per",30);
        set("combat_exp", 250);
        set("attitude", "friendly");
//        set("rank_info/respect", "������");
        set("chat_chance", 3);
        set("chat_msg", ({
                "����氲��������\n",
  //            (: random_move :),
        }) );
        set_skill("dodge",50);
        setup();
}