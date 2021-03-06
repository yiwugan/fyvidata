#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
inherit F_MASTER;
string ask_me();
string ask_app();
void create()
{
        set_name("燕南天", ({ "master yan", "master", "yan" }) );
        set("long",
                "他是小鱼儿的师傅，当代第一大侠，全身经脉震断，气若游丝。\n");
        set("nickname", HIY"血燕惊天"NOR);
        create_family("雁羽门",3,"门主");
         set("str", 45);
        set("cor", 45);
        set("cps", 45);
        set("agi",45);
        set("int",45);
       set("attitude","friendly");
        set("max_kee", 999999999);
        set("max_sen", 999999999);
        set("max_gin", 999999999);
        set("kee", 20000);
        set("sen", 20000);
        set("gin", 20000);
        set("max_force", 20000);
        set("max_atman", 5000);
set("max_mana", 6000);
set("force", 20000);
        set("force_factor", 700);
                 set("inquiry", ([
"雁羽门": "雁羽门是我师公天鹰老人所创。 \n",
                "邀月" : (: ask_me :),
                "报仇" : (: ask_me :),
                "拜师" : (: ask_app :),
        ]) );
set("combat_exp", 999999999);
        set_temp("apply/damage",500);
        set_skill("unarmed", 500);
        set_skill("force",500);
        set_skill("parry",500);
         set_skill("dodge",500);
 set_skill("move",500);
            set("chat_chance", 300);
set("chat_msg", ({
                "燕南天说道：若然月奴没有死就好了，那我还可以见她一面。\n",
                "燕南天说道：邀月还没有死，在那里了，我一定要杀她,为月奴报仇。\n",
        }) );

    setup();
        carry_object("/obj/cloth")->wear();
}
string ask_app()
{
        object ob;
        if ( (int)this_player()->query("combat_exp") < 3000000 )
                return RANK_D->query_respect(this_player()) + 
                "你的经验太浅了。";
        if (this_player()->query("yan_over")!=1)
                return RANK_D->query_respect(this_player()) + 
                "问题是你！";
        if ( (int)this_player()->query("killyaoyue") != 1 )
                return RANK_D->query_respect(this_player()) + 
                "对不起我有心事未了?";
                command("recruit " + this_player()->query("id") );

        return "好吧，能不能帮我报仇就看你和小鱼儿了。";

}string ask_me()
{
        object ob;
        if ( (int)this_player()->query("combat_exp") < 3000000 )
                return RANK_D->query_respect(this_player()) + 
                "你的经验太浅了。";
        if (this_player()->query("yan_over"))
                return RANK_D->query_respect(this_player()) + 
                "怎么了？有问题？";
        if ( (int)this_player()->query("killyaoyue") != 1 )
                return RANK_D->query_respect(this_player()) + 
                "对不起我有心事未了?";
        ob = new("/d/yihua/npc/obj/xueyan");
        ob->move(this_player());
        this_player()->set("yan_over",1);
            message_vision("$N拿到了飞燕剑。\n",this_player());

        return "好吧，能不能帮我报仇就看你和小鱼儿了。";

}
void attempt_apprentice(object me)
{
        switch(random(4)) {
                case 0:
message_vision("$N对$n道：你拜小鱼儿就可以了，我可是废人？\n", this_object(),me);
                        break;
                case 1:
message_vision("$N对$n道：邀月一天没有死，我都不会死，你回去吧，我不收徒？＂\n", this_object(),me);      
                        break;
                case 2:
message_vision("$N对$n道：是什么东西让你这么想拜我为师？\n", this_object(),me);             
                        break;
                case 3:
message_vision("$N对$n道：我没有什么值得你去学的，看看我现在就知道了？\n", this_object(),me);
                        break;
        }
                        return;

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yanyu");
}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 5000000 ) {
                student->set("title","雁羽门关门弟子");
                return ;
        } else
                student->set("title",HIM"雁羽门绝代天骄"NOR);
                return ;
}

