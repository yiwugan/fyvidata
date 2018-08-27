#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void create() 
{
    set_name("��÷��ʦ", ({ "master kumei", "kumei","master"}));
    set("long", 
        "
����һ���׷��ԲԵ��ϸ���һ�Ÿɿ����������������˰̣�����ȱ�˰����
�۾�Ҳ����һֻ��ʣ�µ�һֻ�۾��뿪��ϣ�����֮�䣬���Ⱪ�䣬����˭Ҳ
���ұ��ӡ������Ӻ���С����ȴ����˵�����������ϣ�����˭��ֻҪ������ 
һ�ۣ���˵������������ѹ��Щ��
\n"
        );
    set("nickname", HIW "���ɹ�" NOR);
    set("gender", "Ů��");
    create_family("��ɽ��", 16, "����");
    set("student_title","����");
    set("age", 59);  
    set("str", 25);
    set("int", 30);
    set("con", 25);
    set("kee", 50000);
    set("max_kee", 50000);
    set("gin", 2000);
    set("max_gin", 2000);
    set("force", 9000);
    set("max_force", 9000);
    set("force_factor", 30);
    set("combat_exp", 1500000);
    set("attitude", "friendly");
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "sword.pochan" :),
            (: perform_action, "sword.poqi" :),
            }) ); 
    set_skill("unarmed", 70);
    set_skill("move", 100);
    set_skill("dodge", 100);
    set_skill("parry", 90);
    set_skill("literate",100);
    set_skill("force", 90);
    set_skill("sword", 150);
    set_skill("meng-steps", 150);
    set_skill("dugu-sword", 140);
    set_skill("wuzheng-force", 220);
    map_skill("force", "wuzheng-force");
    map_skill("move", "meng-steps");
    map_skill("parry", "dugu-sword");
    map_skill("sword", "dugu-sword");
    map_skill("dodge", "meng-steps"); 
    set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"}));
    
    setup();
    carry_object("/obj/armor/cloth", 
                ([      "name"  :       HIB "������" NOR,
                        "long"  :       0 ])
                )->wear();
    carry_object("/obj/weapon/sword")->wield(); 
} 
void init()
{
    object ob;
    ob=this_player();
   if ((int)ob->query("marks/killed_yuan")==1 )
       {
           ob->delete("marks/killed_yuan");
           kill_ob(ob);
       }
}
void attempt_apprentice(object ob)
{
        if (ob->query_skill("sword",1) < 100) {
         command("say  ��Խ�����֪���٣���Ȼ�������ң�");
                return;
    }
    if ((int)ob->query_skill("move",1) < 100 ) {
        command("say ���µ����ƺ�����ѧ�䰡��");
                return;
    }
    if( (int) ob->query("marks/ɱ������") == 1 )
     { 
    command("smile");
    command("recruit " + ob->query("id"));
    ob->delete("marks/ɱ������");
     }
     else   
     command("say �����ڴ����ϳ�ҵ����ֻ࣬��һ�˻ỵ�ҵĴ���...");
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
}    
