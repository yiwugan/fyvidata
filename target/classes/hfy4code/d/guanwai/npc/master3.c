 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
int leave();
int tell_him();
int wieldblade();
void create()
{
    set_name("关玉门", ({ "master yumen", "master"}) );
    set("nickname", HIW "生裂虎豹"NOR);
    set("gender", "男性" );
    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 45);
    set("per", 15);
    set("agi", 300);
    set("str", 50);
    set("int",30);
    set("ill_boss",5);
    set("attitude","friendly");
    set("max_force", 3000);
    set("force", 3000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
    
    set("long", "
一条高大魁伟的汉子，却瘦骨支离，好象瘦的只剩下皮包骨头一样。
他非但走不稳，连站好象都站不稳，但嘴里却总是吃个不停。\n");
    create_family("财神庙", 7, "当家");
    set("rank_nogen",1);
    set("ranks",({"脚夫","伙计","信差","趟子手","执旗手","镖师","镖头",
                      "副总镖头","总镖头",HIW"特使"NOR,
                      RED"令主"NOR,HIY"大当家"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: perform_action, "dodge.changmengwuchen" :),
                (: wieldblade  :),
        (: perform_action, "dagger.pingshuixiangfeng" :),
             }) );
    set("combat_exp", 5000000);
    set("chat_chance", 1);
    set("chat_msg", ({
                "关玉门瞄了瞄胡金袖：如果能让我把金狼牙找回来，这次在老卜面前可长面子了．．．\n",
            }) ); 
    set("inquiry",  ([
                "leave": (: leave :),
                "wolf tooth" : (: tell_him :),
                "金狼牙" : (: tell_him:),
                ]) );

    set_skill("dagger", 150);
    set_skill("move", 160);
    set_skill("parry",120);
    set_skill("dodge", 120);
    set_skill("force", 180);
    set_skill("literate", 100);
    set_skill("unarmed",220);
  //  set_skill("blade",200);

  //  set_skill("xiruo-blade",180);
    set_skill("liumang-strike",220);
    set_skill("wuchen-steps",120);
    set_skill("yuping-dagger",200);
    set_skill("wuchenforce",200);

  //  map_skill("blade", "xiruo-blade");
    map_skill("dodge", "wuchen-steps");
    map_skill("move", "wuchen-steps");
    map_skill("force", "wuchenforce");
    map_skill("unarmed", "liumang-strike");
    map_skill("dagger","yuping-dagger");
    map_skill("parry","yuping-dagger");


   setup();
   carry_object(__DIR__"obj/dagger")->wield();
   carry_object("/d/fugui/npc/obj/m_cloth1")->wear(); 
} 
void attempt_apprentice(object me)
{
    if((int)me->query("deposit")>=5000000)
    {if (me->query("betrayer"))
    	    	{  command("shake");
    	           command("say 钱虽能通神，但可一不可再啊。。。");
    	           return;
                   }    
        command("haha");
        command("say 好孩儿！既然你有这份心，我就给机会你孝敬老子！\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("heihei");
        command("say 去去去，过家家的玩意去小胡那，别来找老子！"); 
    }
} 
 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "quanli");
} 



void init()
{       
//	  object ob;
        ::init();
  /*              if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }*/
        add_action("do_killing", "kill");
} 


int leave() {
        if (this_player()->query("class")!="quanli") return 0;
        message_vision(CYN"$N哼了一声，用不屑的眼神看着你。\n"NOR, this_object());
        message_vision(CYN"$N说：不懂珍惜荣华富贵，这流氓神拳你也不配再用了！\n"NOR,this_object());
        return 1;
} 
int wieldblade()
{
command("unwield dagger");
perform_action("unarmed.pofuchenzhou");
command("wield dagger");
return 1;
}

int tell_him()
{
    object me;
    me =this_player();
    tell_object(me,"关玉门豪气地拍了拍手：哈，听说老卜有只萧十一郎遗传下来的金狼牙，不知道现在丢哪了……\n");
    return 1;
} 

int accept_object(object me, object obj)
{
        object book;
        if( (string) obj->query("name") == HIY"金狼牙"NOR)
        {
                obj = new(__DIR__"obj/xiruobook");
                message_vision(CYN"$N说道：多谢多谢，这次终於可以在老卜面前威风一次了。没什麽好东西给你，这书我看不懂，就送你吧！\n"+"$N将"NOR + obj->name() + CYN"塞入$n手中。\n", 
                            this_object(),this_player() );

                        book = new(__DIR__"obj/xiruobook");
                        if(book) book->move(this_player());
                        
                        
                if(!me->query("m_success/金狼牙"))
                {
                        me->add("score",1000);
                        me->set("m_success/金狼牙",1);
                }
           return 1;       
        }
        else {return notify_fail("关玉门哈哈大笑：这破玩意你大爷我多着呢！\n");}
            
        return 1;
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