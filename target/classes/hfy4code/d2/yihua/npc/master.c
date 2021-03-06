#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("花无缺", ({ "master wuque", "master", "wuque" }) );
        set("nickname", HIR "武林至尊"NOR);
        set("gender", "女性");
        set("age", 24);
        set("attitude", "peaceful");
        set("class", "yihua");
        set("apprentice_available", 3);
//        set("student_title","宫主");
        set("str", 50);
        set("int", 30);
        set("spi", 30);
        set("con", 30);
        set("spi", 30);
        set("con", 30);
        set("cps", 30);
        set("cor", 20);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tiannvsanhua" :),
        }) );
        set("atman", 1000);
        set("max_atman", 1000);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 100);
        set("mana", 1000);
        set("max_mana", 1000);
        set("combat_exp", 100000000);
        set("score", 10000);
        set_skill("sword", 200);
       set_skill("jueqing-zhang", 200);
        set_skill("unarmed", 250);
        set_skill("force", 250);
        set_skill("dodge", 200);
        set_skill("literate", 250);
        set_skill("parry", 200);      
        set_skill("move",200);
        set("max_kee", 105000);
        set("max_sen", 105000);
        set("max_gin", 105000);
        set_skill("lanhua-sword", 200);
        set_skill("yihua-jiemu",200);
        set_skill("mingyu-shengong",200);
        map_skill("sword", "lanhua-sword");
        map_skill("parry", "lanhua-sword");
        map_skill("force", "mingyu-shengong");
        map_skill("dodge","yihua-jiemu");
        map_skill("unarmed", "jueqing-zhang");
        create_family("移花宫", 2, "宫主");
        setup();
        carry_object(__DIR__"obj/cq")->wield();
        carry_object(__DIR__"obj/xianfu")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本宫主今天已经收够了弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "女性" )
                command("say 我向来不与男人交往,你速速离开吧。");
              else if( ob->query_kar() < 40)
                command("say 你我缘分未到，你速速离去吧。");
        else if(ob->query("m_success/孽龙")){
                ob->set("class","yihua");
                command("say 看在你不惧生死，勇屠孽火巨龙的份上，我就收你为徒吧！\n");
                command("fy 又有人成功地成为“移花宫”的弟子了！！！");
                command("recruit " + ob->query("id") );
          }
         else
         command("say 你如果能杀了孽火巨龙,证明你是个勇士,我就收下你了！\n");
        
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                add("apprentice_availavble", -1);
                return 1;
        }
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="yihua" )
                command("say 师傅我怎么能和你一般见识呢？");
        else
                command("say 本宫主向来不愿意与人争斗，你速速离开吧。");

        return 0;
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","移花宫移花使者");
                return ;
          } else if ( exp <= 187000 ) {
                 student->set("title","移花宫护法");
                 return ;
          } else if ( exp <= 6244000 ) {
                 student->set("title",HIW"花仙子"NOR);
                 return ;
          } else
                student->set("title",BLINK HIR"花神"NOR);
                return ;

}


