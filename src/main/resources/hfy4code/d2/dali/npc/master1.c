inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("枯荣大师", ({ "master kurong", "master","kurong" }) );
        set("nickname", YEL "半枯半荣"NOR);
        set("gender", "男性" );
        set("age", 99);
        set("int", 30);
        set("apprentice_available", 20);
        create_family("天龙寺", 5, "主持");
        set("long",
                "枯容大师是天龙寺的得道高僧，没人知道他的来历。\n"
                );
        set("inquiry", ([
                "六脉神剑": "嗯...六脉神剑是大理世代相传镇邦绝技，
                可惜...这并非是一人所能施展的...\n",
                "段誉": "他是个很明事理的年轻人，对佛法也颇有研究。",
        ]) );
        set("combat_exp", 5000000);
        set("score", 90000);
        set_skill("unarmed", 150);
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("parry", 100);
        set_skill("literate", 200);
        set_skill("yiyangzhi", 200);
        //set_skill("cloudstaff", 100);
        set_skill("bolomiduo", 100);
        set_skill("buddhism", 200);
        //set_skill("jin-gang", 150);


        map_skill("unarmed", "yiyangzhi");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
     //   map_skill("iron-cloth", "jin-gang");
       // map_skill("staff", "cloudstaff");
        //map_skill("parry", "cloudstaff");
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 50);
    //    set("chat_msg_combat", ({
    //            (: perform_action, "staff.longxianyuye" :),
    //    }) );
        setup();
        carry_object(__DIR__"obj/jiasha")->wear();
 //       carry_object(__DIR__"obj/9staff")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本主持今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
                command("smile");
                command("say 很好，很好，很好。");
                command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dali");
        add("apprentice_availavble", -1);
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","天龙寺弟子");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","天龙寺罗汉");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","天龙寺高僧");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","天龙寺圣僧");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","天龙寺法王");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","天龙寺活佛");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","天龙寺副主持");
                return ;
        } else
                student->set("title","天龙寺主持");
                return ;

}