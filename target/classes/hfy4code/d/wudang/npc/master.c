 // taolord.c
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave(); 
void create()
{
    set_name("石雁", ({ "master shi", "master", "shi" }) );
    set("nickname", "五行真人");
    set("gender", "男性");
    set("age", 62);
    set("long",
        "石雁乃当代武当掌门，他的太极心法和三才剑法已炼到了极高的境界。\n"
        "他尤其精通太极五行，五行身法已是当世无双，所以人称［五行真人］。\n");
    set("combat_exp", 90000000);
    set("score", random (20000)); 
    set("class", "wudang");
    set("reward_npc", 1);
    set("difficulty", 40); 
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30);
    set("fly_target",1);        
    set("force", 3000);
    set("max_force", 3000);
    set("force_factor", 100);
    set("atman", 1400);
    set("max_atman", 1400);
    set("mana", 2000);
    set("max_mana", 2000); 
    set("resistance/gin",70);
    set("resistance/kee",70);
    set("resistance/sen",99);
        
    set("inquiry", ([
        "太极心法": "太极心法乃道家入门的基本心法，能够调和体内的阴阳二气。\n",
        "武当派":   "我武当派自张真人开山立派至今，世世代代皆以行侠仗义为己任。\n",
        "七星法" :  "七星法名为七星却只有两诀：捍星诀（hanxing）和击星诀（jixing）。\n",
        "qixing" :  "七星法名为七星却只有两诀：捍星诀（hanxing）和击星诀（jixing）。\n",
    "leave" : (: leave :),
         ]) ); 
    set("apprentice_available", 10);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
            (: cast_spell, "jixing" :),
            (: perform_action, "sword.nianzijue" :),
             }) ); 
    create_family("武当派", 57, "掌门人");
    set("rank_nogen",1);
    set("ranks",({"道士","小真人","真人","小天师","天师",YEL"大天师"NOR,YEL"副掌门"NOR,
                      HIY"掌门"NOR})); 
    set_skill("literate", 140);
    set_skill("force", 150);
    set_skill("move", 150);
    set_skill("unarmed", 130);
    set_skill("sword", 200);
    set_skill("parry", 220);
    set_skill("dodge", 160);
    set_skill("changelaw", 180);
    set_skill("three-sword", 160);
    set_skill("taijiforce", 200);
    set_skill("taiji", 150);
    set_skill("foreknowledge",120);
    set_skill("five-steps", 180);
    set_skill("spells",100);
    set_skill("qixing",180);
    set_skill("incarnation",180);
    set_skill("perception", 200);
    map_skill("spells","qixing");
    map_skill("parry", "three-sword");
    map_skill("sword", "three-sword");
    map_skill("move", "five-steps");
    map_skill("dodge", "five-steps");
    map_skill("literate", "changelaw");
    map_skill("force", "taijiforce");
    map_skill("unarmed", "taiji"); 
    setup(); 
    carry_object(__DIR__"obj/msword")->wield();
    carry_object(__DIR__"obj/mcloth")->wear();
    carry_object(__DIR__"obj/mhat")->wear();
} 
void attempt_apprentice(object ob)
{
    if(ob->query("marry")){
                message_vision("$N哼了一声：武当门下，没有拖儿带女的。”\n", 
                                this_object(), ob);
                return;
    }
    if (ob->query("once_menpai/wudang")&& ob->query("class")!="wudang") {
                command("say 你不是叛出去了么,还有脸回来见我？");
                return;
                } 
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
    if( (string)ob->query("marks/武当弃徒") )
        command("say " + ob->query("name") + "！你还有脸回来见我？");
    else {
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/wudang",1);
    }
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        (ob->set("class", "wudang")&& ob->set("wudang/zhen", 1));

    add("apprentice_availavble", -1);
} 
int accept_object(object who, object ob)
{
    object              book; 
    if((string)ob->name() != "顾云飞的秘函") return 0;
    command("say 多谢这位" + RANK_D->query_respect(who));
    command("say 这本书你留作记念吧。");
    book = new(__DIR__"obj/wubook");
    book->move(this_object());
    command("give book to " + who->get_id());
    return 1;
}  
void die()
{
    object ob;
    if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
    if(ob) 
        ob->set_temp("killed_master_shi",1);
    ::die();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_killing", "kill");
} 
void greeting(object ob)
{
        object *inv,letter, *sy_inv, things;
        int i,j;
        int got_sword = 0;
        if( !ob || environment(ob) != environment() ) return;
        
/*        if (ob->query("once_menpai/shaolin") && !ob->query("marks/muren_time")
                && !ob->query("marks/bugout") && ob->query("class")=="wudang"
                && ob->query("betrayer")==0)
        {
                ob->set("marks/bugout",1);
                letter = new(__DIR__"obj/letter1");
           if(letter) letter->move(ob);
                message_vision(HIW"啪地一声，$N从怀中掏出一封信扔在$n手里。\n"NOR,this_object(),ob);
                message_vision(HIW"$N说：自己去看吧。\n"NOR,this_object());
                ob->add("betrayer",1);
        } */
        if(ob->short() == "武当老掌门(wudang master)") {
//Okey, we got a old wudang master here, fake or real?
        inv =all_inventory(ob);
        for(i=0; i<sizeof(inv); i++) 
         if(inv[i]->query("fake_7sword") && inv[i]->query("equipped")=="wielded"
                && inv[i]->query_temp("marks/owner_name") == ob->query("id")) 
                got_sword = 1;
        if(got_sword) {
        for(i=0; i<sizeof(inv); i++)
        if(inv[i]->query("name")=="面具") destruct(inv[i]);
        command("say 天哪！这，这，这是，是，老，老帮主么？\n");
        message_vision("$N突然一口鲜血喷了出来，惊吓得六神出窍，脸色土黑。。。一头栽倒在地下。\n",
        this_object());
        ob->set_temp("killed_master_shi",1);
        
        sy_inv = all_inventory(this_object());
        for(j=0;j<sizeof(sy_inv);j++){
                things = sy_inv[j];
                destruct(things);
        }
        this_object()->die();
        tell_object(ob,"现在可以去通知老刀把子了，别忘了带上井里的那把真剑。\n");
        
        } else {
        command("say 大胆！竟敢化妆成老帮主来吓唬老夫！\n");
        kill_ob(ob);
        } 
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
        if(id_class == "wudang"&& userp(victim)&&player!=victim)
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
        if (this_player()->query("class")!="wudang") return 0;
        message_vision(CYN"$N怒道：不成器的家伙给我滚开！\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：想走可以，这太极五行的武当秘技你就别想再用了。\n"NOR,this_object(),this_player());
        message_vision(CYN"$N说：以后也别再来见我！\n"NOR,this_object(),this_player());
        return 1;
}
