#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����ͷ" , ({ "guard leader","leader"}) );
        set("gender", "����" );
        set("age", 25);
        set("long", "���Ǹ��ʹ��������ͷ��\n");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set_skill("sword", 90+random(100));
        set_skill("dodge", 100);
        set_skill("duan-sword", 100);
        set_skill("iron-cloth", 200);
        map_skill("sword","duan-sword"); 
        set("chat_chance", 2);
        set("chat_msg", ({
                "����ͷ������˵�����úøɣ���\n",
                "����ͷЦ�Ŷ�����˵�����������ʹ����ã����úøɰɣ���\n",
        }) );
        
        setup();
        add_money("silver", 150);                                                                       carry_object(__DIR__"obj/tengjia")->wear();
        carry_object("/obj/weapon/sword")->wield();
}