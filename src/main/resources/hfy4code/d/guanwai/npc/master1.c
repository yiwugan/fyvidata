 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
int leave();
int wieldsword();
void create()
{
    set_name("李红袍", ({ "master hongpao", "master"}) );
    set("nickname", RED "夺命"NOR);
    set("gender", "男性" );
    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 88);
    set("per", 10);
    set("str", 100);
    set("ill_boss",5);
    set("int",30);
    set("attitude","friendly");
    set("max_force", 8000);
    set("force", 8000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
    set("no_busy", 9);
    
    set("long", "
他的身材本来应该很高，可是现在已经像虾米一样萎缩佝偻，满头白发也已经快掉光了，
蜡黄的脸上全是皱纹，身上居然穿这件比红花还红的大红袍子，而且是纯丝的，剪裁和
手工都考究的要命。\n");
    create_family("财神庙", 4, "当家");
    set("rank_nogen",1);
    set("ranks",({"脚夫","伙计","信差","趟子手","执旗手","镖师","镖头",
                      "副总镖头","总镖头",HIY"特使"NOR,
                      RED"令主"NOR,HIW"大当家"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("chat_chance_combat", 999);
    set("chat_msg_combat", ({
        (: perform_action, "dodge.changmengwuchen" :),
        (: wieldsword  :),
        (: perform_action, "unarmed.sanmeizhenhuo" :),
             }) );
    set("combat_exp", 15000000);
    set("inquiry",  ([
                "leave": (: leave :),
                ]) );

    set_skill("move", 120);
    set_skill("parry",150);
    set_skill("dodge", 120);
    set_skill("force", 280);
    set_skill("literate", 180);
    set_skill("unarmed",220);
    set_skill("sword",220);

    set_skill("jindian-fire",200);
    set_skill("hanshan-sword",160);
    set_skill("wuchen-steps",200);
    set_skill("wuchenforce",220);

    map_skill("dodge", "wuchen-steps");
    map_skill("move", "wuchen-steps");
    map_skill("force", "wuchenforce");
    map_skill("unarmed", "jindian-fire");
    map_skill("sword","hanshan-sword");
    map_skill("parry","jindian-fire");


   setup();
//   carry_object(__DIR__"obj/thin_sword")->wield();
     carry_object(__DIR__"obj/redcloth3")->wear(); 
     carry_object("/d/guanwai/obj/junksword.c");
     add_money("gold", 5);


} 
void attempt_apprentice(object me)
{
    if((int)me->query("deposit")>=100000000)
    {if (me->query("betrayer"))
    	    	{  command("shake");
    	           command("say 钱虽能通神，但可一不可再啊。。。");
    	           return;
                   }    
        command("grin");
        command("say 不错不错不错，我这个老不死以后吃的喝的用的就全拜托你了！\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("heihei");
        command("say 你那点钱还不够供奉我，你还是去找弟妹他们吧。"); 
    }
} 
 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "quanli");
    add("apprentice_availavble", -1);
}  



void init()
{       
        ::init();
        add_action("do_killing", "kill");
} 

int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "quanli"&& userp(victim)&& player != victim)
        {
            message_vision(HIW
"$N冷笑一声：谋财害命？！找错地方了吧！\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 

int leave() {
        if (this_player()->query("class")!="quanli") return 0;
        message_vision(CYN"$N哼了一声，用不屑的眼神看着你。\n"NOR, this_object());
        message_vision(CYN"$N说：不懂珍惜荣华富贵，这寒山剑法你也不配再用了！\n"NOR,this_object());
        return 1;
} 
int wieldsword()
{
command("wield sword");
perform_action("sword.yueyinghanshan");
command("unwield sword");
return 1;
}
