 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("����" , ({ "qin xin","qin" }) );
    set("nickname",HIC"������"NOR);
    set("long", "һ������Ů��ϯ�ض�����ϥ�Ϸ���һ�Ž�β�٣����Ե��ࡣ������ľ��ͣ����\n��������һ��һ�𣬻������ͳ���\n");
        set("attitude", "friendly");
    set("age", 22);
    set("per",40);
        set("gender", "Ů��" );
        create_family("���Ƴ�",1, "��Ů");
    set("combat_exp", 2500000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "�������ϥ�����٣����������ﻥ��Ӧ�𣬼��عأ���ת������\n",
        "������ü΢�����������ߺ��ͣ�������죬�����һ����һ�������ҡ���Ȼ���ˡ�\n",
        }) );
    set_skill("dodge", 200);
    set_skill("anxiang-steps", 200);
    set_skill("qingfeng-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("spring-water", 100);
    map_skill("iron-cloth","spring-water");
    map_skill("sword","qingfeng-sword");
    map_skill("dodge","anxiang-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.yexuechiji" :),
        }) ); 
        setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}      
