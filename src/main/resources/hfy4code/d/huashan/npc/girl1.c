#include <ansi.h>
inherit NPC;
void goto_batdao(object ob);
void create()
{
    set_name("�׾�", ({ "bai ju" }));
    set("long", "
һ��ʮ�������С��������۾���Ц����������������ľ��ѡ�\n" );
        set("title", "��ɽ�� ��ʮ�ߴ�����");
        set("gender", "Ů��");
        set("age", 13);
        set("per", 26);
        set("str", 18);
        set("int", 24);
        set("con", 25);
        set("kee", 600);
        set("max_kee", 600);
        set("gin", 600);
        set("max_gin", 600);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 20);
        set("combat_exp", 8000);
        set("attitude", "friendly");
        set("chat_chance", 1);
 set_skill("unarmed", 70);
        set_skill("move", 90);
        set_skill("dodge", 90);
        set_skill("parry", 80);
        set_skill("force", 80);
        set_skill("sword", 75);
        set_skill("qingfeng-sword", 50);
        set_skill("zixia-force", 90);
        set_skill("huashan-steps", 90);
        map_skill("force", "zixia-force");
        map_skill("move", "huashan-steps");
        map_skill("parry", "qingfeng-sword");
        map_skill("sword", "qingfeng-sword");
        map_skill("dodge", "huashan-steps"); 
        setup();
    carry_object(__DIR__"obj/gcloth")->wear();
    carry_object("/obj/weapon/sword_thin")->wield(); 
}     
