#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW "������ʿ" NOR, ({ "jinyi weishi", "weishi"}) );
        set("title","�ʹ�");
        set("gender", "����" );
        set("age", 25);
        set("long", "��һ����ʽ��£����屦��������˵���������硣\n");
        set("combat_exp", 700000);
        set("attitude", "friendly");
        set_skill("sword", 90+random(100));
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("duan-sword", 80);
        set_skill("duan-force", 80);
        set_skill("iron-cloth", 200);
        map_skill("force","duan-force"); 
        map_skill("sword","duan-sword"); 
        map_skill("parry","duan-sword"); 
        set("chat_chance", 2);
        set("chat_msg", ({
                "������ʿ����ȵ����ʹ��ﲻҪ���ܣ���\n",
                "������ʿ����ȵ���վס������ʲô�ģ���\n",
        }) );
        
        setup();
        add_money("silver", 150);                                               carry_object(__DIR__"obj/jinyi")->wear();
        carry_object("obj/weapon/sword")->wield();
}