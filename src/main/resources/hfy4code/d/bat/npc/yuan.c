#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("ԭ����", ({ "master yuan suiyun", "yuan suiyun","master"}));
    set("long",
        "
��Ц����������У���һ˫�۾��ȴ������˵�����Ŀ��顢��į������
֮��, �Ǹ�����������˹�ĵ����꣬�����仪������ȴ������
\n"
        );
    set("title","����ɽׯ������");
    set("nickname", HIR "������"NOR);
    set("gender", "����");
    create_family("����", 1, "����");
    set("student_title","����");
    
    set("class","bat");
    set("reward_npc", 1);
    set("difficulty", 25);
    set("fly_target",1);
    set("age", 26);
    set("int", 40);
    set("con", 20);
    set("per", 40);
    
    set("atman",1000);
    set("max_atman",1000);
    set("force", 2000);
    set("max_force", 2000);
    set("force_factor", 100);
    set("combat_exp", 80000000);
    set("attitude", "friendly");
    
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
            (: perform_action, "dodge.huanyinqianchong" :),
            (: perform_action, "blade.shiwanshenmo" :),
            }) ); 
    set("chat_chance", 1);
    set("chat_msg", ({
        "ԭ�����ߵ��ٱߣ�һ����������ˮ������Ӵ���ָ�������
���伺�кܾ�û�й�����ö��������ˡ�\n ",
            "\n",
        }) );
        
    set_skill("unarmed", 160);
    set_skill("move", 180);
    set_skill("dodge", 160);
    set_skill("parry", 160);
    set_skill("literate",150);
    set_skill("force", 180);
    set_skill("blade", 280);
    set_skill("meng-steps", 180);
    set_skill("bat-blade", 180);
    set_skill("wuzheng-force", 220);
    set_skill("perception",280);    
    
    map_skill("force", "wuzheng-force");
    map_skill("move",  "meng-steps");
    map_skill("dodge", "meng-steps");
    map_skill("parry", "bat-blade");
    map_skill("blade", "bat-blade"); 
    set("ranks",({"����","Са","��а","������","��ȸ��","�׻���",
                      "������","������"}));
    set("rank_nogen",1); 
    setup();
    carry_object("/obj/armor/armor",
                ([      "name"  :       HIY"��˿���"NOR,
                        "long"  :       "����һ���ƽ�ǽ����·��µ���ף������ķų�
���˵Ľ�ɫ��â��һ�������������䡣\n",
                                "value" :       0,
                                "armor_prop/armor"      : 200 ])
                )->wear();
    carry_object(__DIR__"obj/hanhai")->wield();  
} 
void attempt_apprentice(object ob)
{
    if (ob->query("combat_exp") < 3000000) {
        command("say  ��ô����书����ôѧ�û��ҵĵ�����");
        return;
        }        
    if( (int) ob->query_temp("marks/murderhu") == 1 )
     {
        command("say �ܺã��ܺã���������Ҫ������������졢�����޼ɵ��˲ţ�");
        command("recruit " + ob->query("id"));
     }
     else     command("say ����û�����赶ɱ����仰 �������������µĵ�������");
}  
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bat");
        ob->add("betrayer",-1);
        if(ob->query("betrayer") < 0) ob->set("betrayer",0);
//      ob->add("score",-5000);
}
