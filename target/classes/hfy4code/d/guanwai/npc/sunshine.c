 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
    set_name("������", ({ "sunshine" }) );
    set("gender", "Ů��" );
    set("age", 17);
    set("title", HIY "��ɫ��"NOR);
        set("long",
        "һ�������Ů���ӣ����ϴ����·���������������Ⱥ�ˮ������\n��Ҳ��δ����������ʣ������������Ů���ӡ�\n");
        set("attitude", "friendly");
        set("class","legend");
        set("chat_chance", 1);
        set("chat_msg", ({
"������ͻȻ������Ц�ݣ���Ȼ����ʥĸǡĸ���������ֻ��Ѫ�������ᣬ\n����ȥǰ����Ѫ����������Ů�������������\n",
"����������һЦ�����Ǹ�С������ȥ�װͰ͵ģ��ı�����Ů�˻�Ҫ����\n",
                }) );
        set("per",30);
        set("combat_exp",3000000);
        set("vendor_goods", ([
               __DIR__"obj/gw_sword":20,
               __DIR__"obj/gw_spear":20,
               __DIR__"obj/gw_hammer":20,
               __DIR__"obj/gw_whip":20,
               __DIR__"obj/gw_axe":20,
               __DIR__"obj/gw_blade":20,
               __DIR__"obj/gw_staff":20,
               __DIR__"obj/gw_dagger":20,
               __DIR__"obj/gw_stone":10,
               __DIR__"obj/gw_iron":2,
        ]) );
    set_skill("fall-steps",100);
    set_skill("meihua-shou",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        map_skill("unarmed", "meihua-shou");
        map_skill("dodge","fall-steps");
        setup();
    carry_object("/d/jinan/npc/obj/changbao")->wear();
}
void init()
{
        add_action("do_vendor_list", "list");
        ::init();
}  
void reset()
{
        set("vendor_goods", ([
               __DIR__"obj/gw_sword":20,
               __DIR__"obj/gw_spear":20,
               __DIR__"obj/gw_hammer":20,
               __DIR__"obj/gw_whip":20,
               __DIR__"obj/gw_axe":20,
               __DIR__"obj/gw_blade":20,
               __DIR__"obj/gw_staff":20,
               __DIR__"obj/gw_dagger":20,
               __DIR__"obj/gw_stone":100,
               __DIR__"obj/gw_iron":2,
        ]) );
}
