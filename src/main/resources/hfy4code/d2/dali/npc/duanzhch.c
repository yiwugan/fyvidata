// mouse@wenxin
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("段正淳", ({ "master duan", "master"}) );
        set("nickname", HIG"风流王爷"NOR);
//        set("pursuer", 1);
//        set("vendetta_mark","dali");
        set("title","大理镇南王");
        set("gender", "男性" );
        set("age", 46);
        set("agi",20);
        set("str", 25);
        set("per", 40);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 50);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_atman", 5000);
        set("atman", 5000);
        set("long",
"
这是个英俊潇洒的中年汉子，是大理国皇帝的弟弟，位居镇南王。\n"
        );
        create_family("大理", 11, "弟子");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qijian" :),
        }) );
        set("combat_exp", 3500000);
        set_skill("dodge", 150);
        set_skill("move",160);
        set_skill("force", 180);
        set_skill("strategy", 200);
        set_skill("leadership", 200);
        set_skill("sword", 150);
        set_skill("literate", 180);
        set_skill("unarmed",180);
        set_skill("parry", 150);
        set_skill("duan-force", 180);
        set_skill("duan-yiyangzhi", 180);
        set_skill("duan-steps", 180);
        set_skill("duan-sword", 180);
        map_skill("force", "duan-force");
        map_skill("move", "duan-steps");
        map_skill("dodge", "duan-steps");
        map_skill("unarmed", "duan-yiyangzhi");
        map_skill("parry","duan-sword");
        setup();
     carry_object(__DIR__"obj/guanfu1")->wear();
//     carry_object("/d/dali/obj/longsword")->wield();

}

void attempt_apprentice(object me)
{
 if( !me->query("class"))
  {
   me->set("gongxian",0);
   command("smile");
   command("say 大理中兴，天下太平，你要为大理多做贡献啊！\n");
   command("recruit " + me->query("id") );
  }
  else command("say 大理不要你这种欺师灭祖、背信弃义之徒！\n");
//        command("smile");
//        command("recruit " + me->query("id") );
                return;
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
        command("say 你赢了我，你就可以去皇宫见皇上了！\n");
        return 1;
        }
        else
        {
        command("say 小王武功低微，壮士不要开这种玩笑。\n");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say 哎！徒儿你还差得远呢，还要努力呀！\n");
}
void lose_enemy(object winner)
{
command("say 很好！你可以去皇宫见皇上了。\n");
winner->set_temp("won_duanzhch",1);
}