 //TIE@FY3
#include <ansi.h>
inherit QUESTNPC;
//inherit F_MASTER;
void create()
{
        set_name("˧һ��", ({ "shuai yifan","shuai" }) );
        set("gender", "����" );
    	set("title","ժ����ʿ");
    	set("nickname",HIG"һ������ɽ ̸Цն����"NOR);
    	set("class","huangshan");
    	set("npc_difficulty",12);
    	set("organization/����","а");
        set("age", 55);
        set("int", 30);
        set("per", 30);
        set("fle",40);
        set("cps",35);
        set("dur",40);
        set("resistance/kee",80);
        set("resistance/gin",80);
        set("resistance/sen",80);
        set("long",
"������¸߹ڵİ׷����߱��ǵ���һ������ɽ����ն�����ǵ�������\n"
                );
        set("force_factor", 110);
        set("max_gin", 280000);
        set("max_kee", 340000);
        set("max_sen", 280000);
        set("eff_gin", 300000);
         set("gin", 300000);
        set("kee", 300000);
        set("sen", 300000);
        set("max_force", 5000);
        set("force", 5000); 
        set("combat_exp", 100000000);
        set("score", 80000);
        set_skill("unarmed", 400);
        set_skill("sword", 600);
        set_skill("force", 300);
        set_skill("move", 500);
        set_skill("literate", 140);
        set_skill("dodge", 500);
        set_skill("siqi-sword", 500);
        set_skill("liuquan-steps", 600);
        set_skill("parry",440);
   	map_skill("parry","siqi-sword");
    	map_skill("sword", "siqi-sword");
    	map_skill("dodge", "liuquan-steps");
        set("chat_chance",1);
        set("chat_msg",({
"˧һ������̾Ϣ��һ��������ϧ�����Ƕ�����ȥ��ֻʣ������ٲ�֮��
�����˼����ˣ�������һ���ܰ�������Խ����ˣ��಻�ɵ��ˡ���\n",
        })      );
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.siqi" :),
                 (:perform_action,"dodge.liushuichanchan":),
        }) ); 
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/qiushui")->wield();
}   
