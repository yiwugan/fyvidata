#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("小鱼儿", ({ "master xiaoyuer", "master", "xiaoyuer" }) );
        set("nickname", HIR "武林至尊"NOR);
        set("gender", "男性");
        set("age", 24);
        set("attitude", "peaceful");
        set("class", "yihua");
        set("apprentice_available", 3);
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
                (: perform_action, "unarmed.shuihuoburong" :),
        }) );
        set("atman", 1000);
        set("max_atman", 1000);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 100);
        set("mana", 1000);
        set("max_mana", 1000);
        set("combat_exp", 10000000);
        set("score", 10000);
        set_skill("sword", 180);
        set_skill("blade", 200);
        set_skill("binghuostrike",250);
        set_skill("unarmed", 250);
        set_skill("force", 250);
        set_skill("dodge", 200);
        set_skill("literate", 250);
        set_skill("parry", 200);      
        set_skill("move",200);
        set_skill("shenji-blade", 200);
        set_skill("yanyu-sword", 200);
        set_skill("shenji-steps",200);
        set_skill("lingshenforce",200);
        map_skill("blade", "shenji-blade");
        map_skill("parry", "yanyu-sword");
        map_skill("sword", "yanyu-sword");
        map_skill("force", "lingshenforce");
        map_skill("dodge","shenji-steps");
        map_skill("unarmed", "binghuostrike");
        create_family("雁羽门", 4, "门主");
        setup();
//        carry_object("/tongji/obj/cloth")->wield();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本门主今天已经收够了弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
        if( ob->query("betrayer") > 3 )
                command("say 你对门派太不忠心了，我不会收你这种徒弟的。");
        else if(ob->query("m_success/孽龙")){
                ob->set("class","yihua");
                command("say 看在你不惧生死，勇屠孽火巨龙的份上，我就收你为徒吧！\n");
                command("rumor 又有人成功地成为“雁羽门”的弟子了！！！\n");
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
                command("say 本宫门主向来不愿意与人争斗，你速速离开吧。");

        return 0;
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","雁羽门弟子");
                return ;
          } else if ( exp <= 1870000 ) {
                 student->set("title","雁羽门");
                 return ;
          } else if ( exp <= 6244000 ) {
                 student->set("title",HIR"绝代双骄"NOR);
                 return ;
          } else
                student->set("title",BLINK HIY"绝代双骄"NOR);
                return ;

}


