// mouse@wenxin
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("段正明", ({ "duan", "duan zhengming"}) );
        set("nickname", HIY"有道名君"NOR);
//        set("pursuer", 1);
//        set("vendetta_mark","dali");
        set("title","大理皇帝");
        set("gender", "男性" );
        set("age", 50);
        set("agi",20);
        set("str", 25);
        set("per", 40);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 40);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_atman", 5000);
        set("atman", 5000);
        set("long",
"
大理国的当今皇帝，是位有道名君，大理国在他的治理下国泰民安。\n"
        );
        create_family("大理", 11, "弟子");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "qijian" :)
        }) );
        set("combat_exp", 5000000);
        set_skill("dodge", 180);
        set_skill("move",180);
        set_skill("force", 230);
        set_skill("sword", 180);
        set_skill("literate", 200);
        set_skill("unarmed", 200);
        set_skill("duan-force", 200);
        set_skill("duan-yiyangzhi", 200);
        set_skill("duan-steps", 200);
        set_skill("duan-sword", 200);
        map_skill("force", "duan-force");
        map_skill("move", "duan-steps");
        map_skill("dodge", "duan-steps");
        map_skill("unarmed", "duan-yiyangzhi");
        map_skill("parry","duan-sword");
        setup();
     carry_object(__DIR__"obj/guanfu2")->wear();
//     carry_object("/d/dali/obj/longsword")->wield();

}

void attempt_apprentice(object me)
{
        if(me->query_temp("won_duanzhch"))
        {
        command("smile");
        command("recruit " + me->query("id") );
                return;
        }
        else
        {
        command("shake");
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dali");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("gongxian");
        if( exp <= 320 ) {
                student->set("title","大理官员");
                return ;
        } else if ( exp <= 640 ) {
                student->set("title","大理大官员");
                return ;
        } else if ( exp <= 1280 ) {
                student->set("title","大理司徒");
                return ;
        } else if ( exp <= 2560 ) {
                student->set("title","大理司马");
                return ;
        } else if ( exp <= 5120 ) {
                student->set("title","大理司空");
                return ;
        } else if ( exp <= 10240 ) {
                student->set("title","大理将军");
                return ;
        } else if ( exp <= 15360 ) {
                student->set("title","大理大将军");
                return ;
        } else if ( exp <= 23040 ) {
                student->set("title","大理爵爷");
                return ;
        } else if ( exp <= 34560 ) {
                student->set("title","大理侯爷");
                return ;
/*        } else if ( exp <= 51870 ) {
                student->set("title","大理王爷");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","镇远将军");
                return ;*/
        } else
                student->set("title",HIG"大理王爷"NOR);
                return ;

}

int accept_fight(object me)
{
        if(me->query("family/family_name") == query("family/family_name") &&
           me->query("family/master_id") == query("id"))
        {
        command("say 好，你赢了我，你就可以去天龙寺学六脉神剑了！\n");
        return 1;
        }
        else
        {
        command("say 大胆！你这个凡夫俗子竟敢和朕较量，快快离开皇宫吧！！\n");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say 徒儿还要继续努力呀！\n");
}
void lose_enemy(object winner)
{
command("say 你可以去天龙寺学六脉神剑了。\n");
winner->set_temp("won_duanzhm",1);
}