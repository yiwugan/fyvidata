 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("����" , ({ "jian dan","jian" }) );
    set("nickname",HIG"����Ȫ"NOR);
    set("long", "һϮ����ӭ�����ɢ���������裬�����������һ��������ĺ�«�������\n�����е��������˵ľ��㡣\n");
        set("attitude", "friendly");
    set("age", 32);
        set("gender", "����" );
        create_family("���Ƴ�",1, "����");
    set("per",40);
    set("combat_exp", 3000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "�����������«���˼��ڣ��̿���ֽ���������ߣ����������������齣������\n
���ֱ����������´��ƣ���ɽ��ˮ�����գ�\n",
        "���������Ÿ裺�廨��ǧ���ã��������������ƣ����ͬ����ų\n",
        }) );
set_skill("dodge", 200);
    set_skill("feixian-steps", 200);
    set_skill("feixian-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("henglian", 200);
    map_skill("iron-cloth","henglian");
    map_skill("dodge","feixian-steps");
    map_skill("sword","feixian-sword");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) ); 
        setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}     
