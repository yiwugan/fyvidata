// taijian.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("С��Ů", ({ "xiao gongnv","gongnv" }) );
        set("gender", "Ů��" );
        set("age", 14);
        set("long",
                "����һ���빬���õ�С��Ů����δͨ���¡�\n");
        set("title","�ʹ�");
        set("int",14);
        set("str",12);
        set("cor",14);
        set("int",20);
        set("per",30);
        set("combat_exp", 250);
        set("attitude", "friendly");
        set_skill("dodge",50);
        setup();
}