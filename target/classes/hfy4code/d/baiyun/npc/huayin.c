 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����" , ({ "hua yin","hua" }) );
        set("nickname",HIR"������"NOR);
        set("long", "����Ů��ɫ��ȹ������ƮƮ���������ɣ��������������˫�������ػ�����\n�������衣\n");
        set("attitude", "friendly");
        set("per",60);
        set("age", 29);
        set("gender", "Ů��" );
        create_family("���Ƴ�",1, "��Ů");
        set("combat_exp", 2000000);
        set("chat_chance", 2);
        set("chat_msg", ({
        "������Ű�����˫�㣬������б���ڻ����У����ɵĴ��۾�͵͵�ش������㡣\n",
        "����ճ�����������ձ��ǽ���ʦ�ֵ��������û���ʲô�͸�����ʦ���أ�\n",
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
