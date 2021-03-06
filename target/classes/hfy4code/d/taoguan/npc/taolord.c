 // taolord.c
inherit NPC;
inherit F_MASTER;
int leave();
int marriage();
#include <ansi.h> 
void create()
{
    set_name("丁乘风", ({ "master ding", "master", "ding chengfeng" }) );
    set("nickname", HIG"碧海乘风" NOR);
    set("gender", "男性");
    set("age", 47);
    set("long","丁乘风原本出身武林世家，但从小好学，擅长钻研心法，\n"
        "于是隐居于此精修成仙降魔之道。\n");
    
    set("combat_exp", 10000000);
    set("score", 20000); 
    set("class", "taoist"); 
    set("str", 60);
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30);
    set("reward_npc", 1);
        set("difficulty", 20); 
    set("force", 2000);
    set("max_force", 1000);
    set("force_factor", 30);
//  set("fly_target",1);
    set("atman", 1400);
    set("max_atman", 1400); 
    set("mana", 4000);
    set("max_mana", 2000);
    set("mana_factor", 5); 
    set("inquiry", ([
        "谷衣心法": 
        "谷衣心法是我三清宫为对抗邪魔外道所创的内功心法。\n",
        "三清宫": 
        "我三清宫自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n",
         "leave" : (: leave :),
         "marriage" : (: marriage :),
        ]) ); 
    set("apprentice_available", 3);
    create_family("三清宫", 5, "主持");
    set("rank_nogen",1);
    set("ranks",({"道士","小真人","真人","小天师","天师",YEL"大天师"NOR,YEL"副主持"NOR,
                      HIY"主持"NOR})); 
    set_skill("literate", 140);
    set_skill("force", 200);
    set_skill("move", 150);
    set_skill("scratching", 220);
    set_skill("spells",200);
    set_skill("unarmed", 150);
    set_skill("sword", 180);
    set_skill("parry", 160);
    set_skill("dodge", 150);
    set_skill("gouyee", 180);
    set_skill("notracesnow", 220);
    set_skill("snowshade-sword", 200);
    set_skill("alchemy",240);
    set_skill("magic",200);     
    set_skill("taoism", 240);
    set_skill("scratmancy", 220);
    set_skill("necromancy",120);
    set_skill("perception", 100);
    set_skill("qiankunstrike", 150);
    map_skill("unarmed", "qiankunstrike");
    map_skill("scratching", "scratmancy");
    map_skill("parry", "snowshade-sword");
    map_skill("sword", "snowshade-sword");
    map_skill("move", "notracesnow");
    map_skill("dodge", "notracesnow");
    map_skill("spells", "necromancy");
    map_skill("magic", "alchemy");      
    set_temp("apply/dodge", 20);
    set_temp("apply/armor", 20);
    setup(); 
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.baixueaiai" :),
        }) );   
    carry_object(__DIR__"obj/sword")->wield();
    carry_object(__DIR__"obj/robe")->wear();
    carry_object(__DIR__"obj/hat")->wear();
    carry_object(__DIR__"obj/shoe")->wear();
} 
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say 慢著，一个一个来。");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say 贫道今天已经收了三个弟子，不想再收徒了。");
    }
} 
void do_recruit(object ob)
{
   
    if( (string)ob->query("gender") != "男性" )
        {
        command("say 贫道是出家人，不便收女徒，得罪了。");
                return;
        }
    else if(ob->query("marry")){
                message_vision("$N道：剑断情丝，方能修到真身。”\n", this_object(), ob);
                return;
         }
    else if (ob->query("once_menpai/sanqing") && ob->query("divorced")) {
                message_vision("$N摇了摇头道：“你既叛出三清，不遵师嘱与人成婚，却又始乱终弃。“\n",this_object());
                message_vision("$N说：“我如何还会再收你？“\n",this_object());
                return;
                }
        
        command("say 嗯... 想入我三清宫？也好....");
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/sanqing",1);
        ob->set("once_sanqing",1);
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "taoist");
    add("apprentice_availavble", -1);
} 
void init()
{       
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
        add_action("do_killing", "kill");
} 
void greeting(object me)
{
        object ob,*inv, ding;
        
        ob=this_object();
        if( !me || environment(me) != environment() ) return;
        
                
        if (me->query("class")=="taoist" 
                && me->query("gender")=="男性" && 
                me->query("combat_exp")>1000000)        {
                
                inv = all_inventory(me);
                
                if  ( sizeof(inv) >= 15) 
                        return;
        
                if (present("ding",me)) return;
                
                message_vision(CYN"$N对$n说：“你跟随为师多年，今日传你一宝鼎，望你能光大师门。”\n"NOR,ob,me);
                ding= new("/obj/specials/ding/ding_baby");
                if (me->query("combat_exp")>5000000) {
                        ding->set("name",RED"红木宝鼎"NOR);
                        ding->set_max_encumbrance(200);
                } else if (me->query("combat_exp")>3000000) {
                   ding->set("name",YEL"黄木宝鼎"NOR);
                        ding->set_max_encumbrance(100);
                } else {
                        ding->set("name",HIC"青木宝鼎"NOR);
                        ding->set_max_encumbrance(50);
                }
                ding->move(me);
                message_vision("$N从怀里取出一口"+ding->name()+"递给$n。\n",ob,me);     
                return;
        }
                
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
        if(id_class == "taoist" && userp(victim)&&player!=victim)
        {
            message_vision(HIW"$N对著$n喝道：" + RANK_D->query_rude(player) 
                                                + "竟敢杀" + RANK_D->query_self_rude(this_object()) 
                                                + "的徒弟，去死吧。\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="taoist") return 0;
   message_vision(CYN"$N道。三清奇术，概不外传，你若走了可不要后悔。\n"NOR, this_object(),this_player());
        return 1;
}  
int marriage () {
        if (this_player()->query("once_menpai/sanqing")){
                message_vision(CYN"$N道，凡我门人，当养生修道，莫要儿女情长。\n"NOR,this_object());
                message_vision(CYN"$N又道：若你执意为此要下山我也不能勉强，只是俗念一生，回头就难，切记！\n"NOR, this_object());
                this_player()->delete("once_sanqing");
                return 1;
        }
        return 0;
}  
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/丁乘风_ma", 1);
        }
        
        ::die(); 

}
