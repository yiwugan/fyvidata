 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
    set_name("���Ϸ���", ({ "song fuzi","song" }) );
    set("gender", "����" );
    set("age", 99 );
    set("title", HIG "��������"NOR);
        set("long",
        "һ���׷��Բԣ���Ŀ�����ƺ���ʱ�����ܵ��µ����ߡ���ż��˫Ŀ\n���������̾�����һ�������˰㡣\n");
        set("attitude", "friendly");
    set("combat_exp", 500000);
        set("chat_chance", 1);
        set("chat_msg", ({
  "���Ϸ���������̧��ͷ����������һ�ۡ�\n",
                }) );
        set("per",30);
    set("vendor_goods", ([
               __DIR__"obj/xuezhi":3,
               __DIR__"obj/sanyecao":4,
               __DIR__"obj/qisehua":3,
        ]) );
    set_skill("fall-steps",100);
    set_skill("unarmed",200);
    set_skill("dodge",100);
    set_skill("parry",100);
    map_skill("dodge","fall-steps");
        setup();
    carry_object("/obj/armor/cloth")->wear();
}
void init()
{
        add_action("do_vendor_list", "list");
}  
void reset()
{
    set("vendor_goods", ([
               __DIR__"obj/xuezhi":3,
               __DIR__"obj/sanyecao":4,
               __DIR__"obj/qisehua":3,
        ]) );
}    
