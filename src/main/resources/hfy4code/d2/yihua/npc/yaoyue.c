#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({ "yao yue", "yao", "yue" }));
        set("long",
            "�����ǡ��ƻ������Ŀ�ɽ��ʦ.\n"+
            "���ñ�������ɴ������,����͸���ǿ���ɴ����Ȼ��ϡ�ɼ�\n"+
            "����ɫɷ��,�Բ����˼����˿�����,�㲻�ɵö࿴��һ��.\n");
        set("title", "�ƻ�������");
        set("gender", "Ů��");
        set("age", 36);
        set("nickname", HIR "ɱ�����¸��ĺ�" NOR);
      set("shen_type",-500);
        set("attitude", "peaceful");

    set("str", 50);
        set("int", 50);
        set("con", 40);
        set("dex", 50);

        set("kee", 5000000);
        set("max_kee", 5000000);
        set("sen", 5000000);
        set("max_sen", 5000000);
        set("gin", 5000000);
    set("max_gin", 5000000);
      set("force", 9000000);
    set("max_force", 9000000);
        set("force_factor", 800);

      set("combat_exp", 60000000);
        set("score", 2000000);
        set_skill("force", 200);
        set_skill("unarmed", 150);
        set_skill("dodge", 200);
        set_skill("parry", 220);
        set_skill("sword",250);
        set_skill("literate",200);

        set_skill("jueqing-zhang",220);
        set_skill("mingyu-shengong",220);
        set_skill("lanhua-sword",220);
        set_skill("yihua-jiemu",220);

        map_skill("force", "mingyu-shengong");
        map_skill("unarmed", "jueqing-zhang");
                map_skill("dodge", "lanhua-steps");
        map_skill("parry", "yihua-jiemu");
   map_skill("sword","lanhua-sword");

        create_family("�ƻ���",1, "���¹���");
set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tiannvsanhua" :),
                        }) );
        setup();
        carry_object("/obj/weapon/sword")->wield();
  //  carry_object("/d/yihua/obj/jinlvyi")->wear();
       
}

void attempt_apprentice(object ob)
{
   
   if ((string)ob->query("gender")!="Ů��")
           {
                command("chat* heihei");
                command("chat ����һ����޵ľ�������,��ȥ����!");
                kill_ob(this_player());
                command("perform yifeng");
                return;
           }
   if ((int)ob->query_skill("dodge", 1) < 100) 
           {
                command("say " + RANK_D->query_respect(ob) + "���������!");
                return;
           }
   if ((int)ob->query_skill("mingyu-shengong", 1) < 150) 
           {
                command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö����������񹦣�");
                return;
           }
   if ((int)ob->query_skill("yifeng-jian", 1) < 150) 
           {
                command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������Ʒ罣����");
                return;
           }
   if ((int)ob->query("betrayer") > 0) 
           {
                command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������Ʒ罣����");
                return;
           }
   if (ob->query_per() < 25) 
           {
                command("say ƾ����ģ���������Ϊʦ.");
                return;
           }
   if (ob->query_con() < 40) 
           {
                command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
                return;
           }
   command("recruit " + ob->query("id"));
   if((string)ob->query("class") != "yihua")
     ob->set("class", "yihua");
   return;
}

void init()
{
        object ob;

        ::init();

        ob = this_player();
        add_action("give_tongji", "quest");

        if (interactive(ob) && (!ob->query("gender") || ob->query("gender")!="Ů��"))
        {
                        command("heihei");
                        command("say ��ƽ�����������ˣ��㾹Ȼ���������ðɣ��Ҿͳ�ȫ���㣡\n");
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
                        command("perform yifeng");
        }
        else if(ob->query("gender")=="Ů��")
        {
        command("smile");
        command("say �����㲻�����˲�Ȼ������úܲҡ�");
        }
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if(ob) 
        ob->set("killyaoyue",1);
        ::die();
}
