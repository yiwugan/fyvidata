inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
        set_name(HIW "�׿���" NOR, ({ "baikaixin" }) );

        set("gender", "����");
        set("age", 48);
        set("long",
                "��������������ƤЦ��������һ�����׼׼�ĵ�Ʀ�����࣬���������κ�һ����
�Ĳ�¥�Ĺݻ�������������Լ������������κ��˶�����������˶���һ�۵�.\n");
        set("attitude", "heroism");
        set("skill_public",1);
        set("no_arrest",1);
        set("str", 40);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�׿����������ڵĻ���������������ֱЦ.\n",
        }) );

        set("force", 40000);
        set("max_force", 8000);
        set("force_factor", 100);

        set("combat_exp", 3000000);
        set("score", -20000);
        
        set_skill("move", 100);
       set_skill("dodge", 90);
        set_skill("staff", 200);
        set_skill("force", 100);
        set_skill("iron-cloth", 100);
        set_skill("jin-gang", 130);
        set_skill("xingyi-stick", 130);
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "xingyi-stick");

        create_family("eren", 1, "��ʦ��");
        set("title", HIY "���˲�����" NOR);
        setup();
        carry_object(__DIR__"obj/shaohuo")->wield();

}

