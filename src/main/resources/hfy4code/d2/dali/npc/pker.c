#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
inherit F_MASTER;
void create()
{
        set_name("白里冰", ({ "pker" }) );
set("long","风云中最大的帮派，权力帮的天王。\n");
set("nickname", HIR"药王"NOR);
        create_family("权力帮",2,"天王");
        set("gender", "男性");
set("age", 50);
        set("str", 20);
        set("cor", 20);
        set("cps", 20);
        set("agi",20);
        set("int",20);
        set("attitude","friendly");
        set("max_force", 10000);
        set("force", 10000);
        set("chat_chance_combat", 90);
       set("chat_msg_combat", ({(: perform_action, "dodge.changmengwuchen" :),      }) );
                 set("inquiry", ([
"帮主": "想见帮主，先打赢我再说。 \n",        ]) );
        set("combat_exp", 1000000);
        set_temp("apply/damage",500);
        set_skill("unarmed", 150);
        set_skill("force",80);
        set_skill("parry",70);
        set_skill("dodge",120);
        set_skill("move",100);
        set_skill("literate",70);
        set_skill("wuchenforce",70);
        set_skill("wuchen-steps",70);
        set_skill("herb",150);
        set_skill("feiyuancurse",150);
        map_skill("force","wuchenforce");
        map_skill("herb","feiyuancurse");
        map_skill("dodge","wuchen-steps");
            set("chat_chance", 2);
        set("force_factor", 30);
          set("chat_msg", ({
                "白里冰说道：上天入地，十九人魔。\n",
                "白里冰说道：帮主神出鬼没，我也不知道他的行踪。\n",
        }) );

    setup();

             carry_object("/obj/glass");
}

void attempt_apprentice(object me)
{
        command("recruit " + me->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "quanli");
}
void init()
{
        add_action("give_quest", "quest");
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 4000 ) {
                student->set("title","权力帮帮众");
                return ;
        } else if ( exp <= 10000 ) {
                student->set("title","权力帮小地魔");
                return ;
        } else if ( exp <= 18000 ) {
                student->set("title","权力帮地魔");
                return ;
        } else if ( exp <= 30000) {
                student->set("title","权力帮小天魔");
                return ;
        } else if ( exp <= 60000 ) {
                student->set("title","权力帮天魔");
                return ;
        } else if ( exp <= 120000 ) {
                student->set("title","权力帮小天王");
                return ;
        } else if ( exp <= 300000 ) {
                student->set("title","权力帮天王");
                return ;
        } else if ( exp <= 800000 ) {
                student->set("title","权力帮老小管家");
                return ;
        } else if ( exp <= 2000000 ) {
                student->set("title","权力帮大管家");
                return ;
        } else if ( exp <= 6000000 ) {
                student->set("title","权力帮副总管");
                return ;
        } else if ( exp <= 12000000 ) {
                student->set("title","权力帮总管");
                return ;
        } else
                student->set("title","权力帮副帮主");
                return ;
}
int accept_fight(object me)
{
        if(me->query("family/family_name") == query("family/family_name"))

        {
        command("say 好，你赢了我，你就可以去找帮主了！\n");
        return 1;
        }
        else
        {
        command("say 没空！\n");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say 你武功不行啊！\n");
}
void lose_enemy(object winner)
{
command("say 果然厉害！你可以去找帮主了。\n");
winner->set_temp("won_pker",1);
}
