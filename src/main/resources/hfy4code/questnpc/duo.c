inherit QUESTNPC;
//inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("����", ({ "master lv", "master"}) );
        set("nickname", HIR "Ȩ������"NOR);
        set("gender", "����" );
        set("age", 31);
        set("per", 30);
        set("npc_difficulty",8);
        set("organization/����","а");
        set("agi",25);
        set("int",30);
        set("cor",40);
        set("combat_exp",80000000);
        set("max_kee",200000);
        set("max_gin",100000);
        set("max_sen",100000);
        set("max_force", 8000);
        set("force", 8000);
        set("force_factor", 120);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        set("long",
"
û���˵����ϻᷢ���������ģ����������ϴ��Ÿ���ͭ��ߡ�
���˵����Ͼʹ�����ͭ��ߣ����ǹ��¿������Եø����������졣
�����ϴ��ŵģ�ȴ�Ǽ��������廨���ۣ�������б���������䵶��
�ұ�ɫ�ĵ����ϣ�׺������������ 
\n"
        );
        create_family("�������", 2, "����"); 
        set("score", 20000);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.lianhuanbabu" :),
                (: perform_action, "blade.tiandirenmo" :),
                (: exert_function, "mihun" :)
        }) );
        set_skill("move", 400);
        set_skill("blade",400);
        set_skill("parry",400);
        set_skill("dodge", 400);
        set_skill("force", 200);
        set_skill("literate", 90);
        set_skill("unarmed",220);
        set_skill("demon-steps",300);
        set_skill("demon-blade",300);
        //set_skill("wenhou-claw",150);
        set_skill("demon-force",220);
        set_skill("iron-cloth",200);
        set_skill("jin-gang",180);
        map_skill("dodge", "demon-steps");
        map_skill("parry", "demon-blade");
        map_skill("move",  "demon-steps");
        map_skill("force", "demon-force");
        map_skill("blade", "demon-blade");
        map_skill("iron-cloth","jin-gang"); 
        setup();
        carry_object(__DIR__"obj/xiuhuacloth")->wear();
        carry_object(__DIR__"obj/duomianju")->wear();
        carry_object(__DIR__"obj/duoblade")->wield();
} 
int accept_fight(object me)
{
	command("heng");
        command("say ��֪����ļһ���аɣ�");
        return 1;
}