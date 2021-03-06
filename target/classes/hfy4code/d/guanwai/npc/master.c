 inherit NPC;
inherit F_MASTER;
#include <ansi.h> 
void smart_fight();
void smart_busy();
void smart_attack();
int leave(); 
void create()
{
        set_name("葛伦", ({ "master gelun", "master","gelun" }) );
        set("gender", "男性" );
        set("class","lama");
        set("age", 99);
        set("int", 30);
        set("agi",25);
        set("int",30);
        set("fle",50);
        set("apprentice_available", 20);
        create_family("大昭寺", 20, "主持");
    set("rank_nogen",1);
    set("ranks",({"弟子","罗汉","高僧","大师","圣僧",YEL"法王"NOR,YEL"活佛"NOR,HIY"主持"NOR}));
        set("long",
                "葛伦高僧已在大昭寺主持多年。男女弟子遍布关外。\n"
                );
        set("inquiry", ([
                "舍利子": "嗯....舍利子.....在舍利塔里。\n",
                "普松": "普松在大昭寺的木屋里。",
                "leave": (: leave:),
        ]) );
        set("combat_exp", 3000000+random(1500000));
        set("score", random(90000));
        set("reward_npc", 1);
        set("difficulty", 30);
        set("mana",4000);
        set("max_mana",4000); 
        set("max_force",1500);
        set("force",1500);
        set("force_factor",30); 
        set_skill("unarmed", 200);
        set_skill("dodge", 100);
		set_skill("move", 100);
        set_skill("staff", 200);
        set_skill("force", 180);
        set_skill("parry", 150);
        set_skill("literate", 140);
        set_skill("fanwen",100);
        set_skill("iron-cloth", 230);
        set_skill("bloodystrike", 150);
        set_skill("lamastaff", 200);
        set_skill("bolomiduo", 160);
        set_skill("lamaism", 200);
        set_skill("jin-gang", 200);
        set_skill("spells",200);
        set_skill("kwan-yin-spells",200);
        set_skill("perception", 100);
        
        map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "fanwen");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "lamastaff");
        map_skill("parry", "lamastaff");
        map_skill("spells","kwan-yin-spells");
        
        set_temp("apply/iron-cloth",200); 
/*      set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "unarmed.fefawubian" :),
                (: cast_spell, "an" :),
        }) ); */
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
}  
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
} 
void attempt_apprentice(object ob)
{
      if(ob->query("marry")){
                message_vision("$N叹了口气道，“施主天赋异禀，只可惜被红尘误了。”\n", 
                                this_object(), ob);
                return;
        }
        
        
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本主持今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
                if (ob->query("once_gelun")>0 && ob->query("class")!="lama") {
                        command("say 你还有脸回来见我？");
                        return;
                } 
                command("smile");
                command("say 很好，很好，很好。");
                command("say 希望你不要像赤松那样让我失望。");
                command("recruit " + ob->query("id") );
                ob->set("once_gelun",1);
                ob->set("once_menpai/lama",1);
} 
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
        add("apprentice_availavble", -1);
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
        if(id_class == "lama"&& userp(victim)&& player!= victim)
        {
            message_vision("$N对著$n喝道：" + RANK_D->query_rude(player) 
                                                + "竟敢杀" + RANK_D->query_self_rude(this_object()) 
                                                + "的徒弟，去死吧。\n", this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}   
void die()
{
    object killer;
    if(objectp(killer = query_temp("last_damage_from")))
        killer->set("marks/杀了葛伦", 1);
    ::die();
}  
void init()
{
        object ob;
        ::init();
        add_action("do_killing", "kill");
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
}  
void punish_betray(object ob)
{
        if( ( ob->query("once_gelun")==1) && ( (ob->query("class"))!= "lama"))
          {      
                tell_object(ob, YEL"\n葛伦大怒:原来你跟赤松一样,是个背叛师门的小人！”\n"NOR);                  
                message("vision", YEL"葛伦对"+ ob->name() +"怒道：“"+ ob->name() + "！ 忘恩负义的家伙,吃我一杖！\n"NOR, environment(ob), ob);
                tell_object(ob, HIW"葛伦一杖击在你的背上！\n"NOR);              
                message("vision", HIW"葛伦一杖击在"+ ob->name() +"的背上！\n"NOR, environment(ob), ob);
                if (ob->query_skill("jin-gang",1)>150)  ob->set_skill("lamaism",150);
                if (ob->query_skill("spells",1)>100)  ob->set_skill("lamaism",100);
                if ( ob->query("max_mana")<300 )
                   ob->set("max_mana",0);
                else
                   ob->set("max_mana",-300);
                tell_object(ob, HIR"你只觉天晕地转,摇摇晃晃地倒了下去----悔不当初呀!\n"NOR);
                ob->set("once_gelun",2);
                ob->unconcious();
          }
}  
int leave() {
        if (this_player()->query("class")!="lama") return 0;
        message_vision(CYN"$N哼了一声，“又是一个心术不正的,老夫最恨的就是你这种人。“\n"NOR, this_object());
        message_vision(CYN"$N说：若是背弃了佛祖，再也颂不得观音明咒。\n"NOR,this_object());
        message_vision(CYN"$N说：心存了妄念，这刀枪不入的金刚不坏也就只有个虚名，老夫的密宗杖法你也无法领悟了。\n"NOR,this_object());
        
        return 1;
}  
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        if (who->is_busy()) return;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2) {
                who->cast_spell("ni");
                return;
   }
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_skill("iron-cloth")>300 
                                || enemy[i]->query("combat_exp")>who->query("combat_exp")) {
                                who->cast_spell("an");
                                switch( random(3) ) {
                                        case 0: command("grin");
                                                break;
                                        case 1: command("smile");
                                                break;
                                        case 2: command("smug");
                                                break;
                                        }
                                return;
                        }               
                        this_object()->smart_attack();
                        }
        }
return;
} 
smart_busy() {
        this_object()->perform_action("unarmed.fefawubian");
        return;
} 
smart_attack() {
        this_object()->perform_action("staff.fofazhizun");    
        return;
        }       
