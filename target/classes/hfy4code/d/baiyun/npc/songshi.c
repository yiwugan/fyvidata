 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("��ʵ" , ({ "song shi","song" }) );
    set("nickname",HIY"���ʵ"NOR);
    set("long", "էһ��ȥ���⺺�ӳ��³��㣬üĿ�ֺ�������ϸ�����������˾�������ʵ�Ǹ�\n����֮�ˡ�\n");
        set("attitude", "friendly");
    set("age", 32);
        set("gender", "����" );
        create_family("���Ƴ�",1, "����");
    set("per",40);
    set("combat_exp", 6000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "��ʵ���ź��ӳ������Σ���Ȼ˫üһ��������һ�ţ��������˿�����\n",
        "��ʵ��ü΢�壬��̾һ������һ�ֽ����н٣����й�����г������ε��ƽ⣿\n",
        }) );
    set_skill("dodge", 200);
    set_skill("fall-steps", 200);
    set_skill("sky-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("henglian", 200);
    map_skill("iron-cloth","henglian");
    map_skill("sword","sky-sword");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianrenheyi" :),
        }) ); 
        setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}      
