#include <ansi.h>
inherit NPC;
void goto_batdao(object ob);
void create()
{
    set_name("С���", ({ "xiao linger", "linger" }));
    set("long", "����Ľ�С����ڵĳ������һ�Դ��٣��������Ĵ����г������档\n" );
        set("title", "��ɽ�� ��ʮ�ߴ�����");
        set("gender", "Ů��");
        set("age", 13);
        set("per", 27);
        set("str", 30);
        set("int", 24);
        set("con", 25);
        set("agi", 20);
//      set("max_kee", 600);
//      set("max_gin", 600);
        set("force", 1000);
        set("max_force", 800);
        set("force_factor", 50);
        set("combat_exp", 80000+random(50000));
        set("attitude", "friendly");
        set("chat_chance", 5);
        set("chat_msg", ({
                "С���С��˵������ʦ������������һ�Ѿ�ץ��������Ү���� \n",
                "С����������������������ʦ������ڽ�ʦ�������������ѽ����\n", 
                "С�����������ʦ��ϲ�������ϵ��ٵġ���\n", 
        }) ); 
        set_skill("unarmed", 43);
        set_skill("move", 50);
        set_skill("dodge", 45);
        set_skill("parry", 35);
        set_skill("force", 49);
        set_skill("sword", 30);
        set_skill("qingfeng-sword", 20);
//      set_skill("zixia-force", 90);
        set_skill("huashan-steps", 30);
        map_skill("force", "zixia-force");
        map_skill("move", "huashan-steps");
        map_skill("parry", "qingfeng-sword");
   map_skill("sword", "qingfeng-sword");
        map_skill("dodge", "huashan-steps"); 
        setup();
    carry_object(__DIR__"obj/gcloth",
        ([      "name"  :       "����",
                "long"  :       "����ɫ��С�ӡ�"                ])
        )->wear();
    carry_object("/obj/weapon/sword_short")->wield(); 
}
