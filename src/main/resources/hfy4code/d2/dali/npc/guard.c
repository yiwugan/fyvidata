#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����" , ({ "guard"}) );
      set("title","�ʹ�");
        set("gender", "����" );
        set("age", 25);
        set("long", "���Ǹ��ʹ����������\n");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set_skill("sword", 90+random(100));
        set_skill("dodge", 100);
        set_skill("duan-sword", 100);
        set_skill("iron-cloth", 200);
        map_skill("sword","duan-sword"); 
        
        setup();
        add_money("silver", 150);                                                                       carry_object(__DIR__"obj/tengjia")->wear();
        carry_object("/obj/weapon/sword")->wield();
}