 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>
int leave();
int damo();
int swit();
int be_guard();
int take_challenge(object me);
void create()
{
    set_name("心湖", ({ "master hu", "master"}) );
    set("vendetta_mark","shaolin");
    set("gender", "男性" );
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"道：经书一丢再丢，谁还肯去守经楼？\n"
            }) );
    set("age", 84);
    set("per", 35);
    set("agi",30);
    set("int",30);
    set("attitude","friendly");
    set("max_force", 1500);
    set("force", 1500);
    set("long",
        "少林寺现任掌门人，由于少林常丢经书，现在喜怒无常，经常将守经书"
        "的弟子逐出少林。\n");
    create_family("少林寺", 17, "掌门");
    set("student_title","长老");    
    set("combat_exp", 5000000);
    set("no_arrest", 1);
    set("inquiry", ([
        "易筋经" : (: damo :),
        "yijinjing" : (: damo :),
        "达摩" : (: damo :),
        "damo" : (: damo :),
           "绝技" : (: damo :), 
        "守经楼": (: be_guard :),
         "leave" : (: leave :),
        "师叔" : (: swit :),
    ]));
    set_skill("move", 160);
    set_skill("dodge", 160);
    set_skill("force", 160);
    set_skill("literate", 150);
    set_skill("unarmed",160);
    set_skill("puti-steps",150);
    set_skill("dabei-strike",150);
    set_skill("zen",150);
    set_skill("chanting",160);
    set_skill("xiaochengforce",150);
    set_skill("yiyangzhi",140);
    set_skill("fanwen",160);
    set_skill("perception",120);
    map_skill("dodge", "puti-steps");
    map_skill("force", "xiaochengforce");
    map_skill("unarmed", "yiyangzhi"); 
    setup();
    carry_object(__DIR__"obj/monk_cloth")->wear(); 
} 
int be_guard(){
        object me;
        me = this_player();
        message_vision("$N道：“你想协助本寺查出藏经楼失窃的疑案？....嗯....你不怕贼人下毒手吗？”（answer）\n",this_object()); 
        add_action("do_answer", "answer");
        return 1;
} 
int damo(){
        object me;
        int explvl, budlvl;
        me = this_player();
        explvl = me->query("combat_exp");
        budlvl = me->query_skill("zen",1); 
        if(this_object()->is_fighting()){
                return notify_fail("心湖似乎正在忙！\n");
        }
   if(me->query("marks/面壁领悟")){
                message_vision("$N盘弄着手中的佛珠,低声咏道：“ 众生无我，并缘业所转，苦乐齐受，皆从缘生。”\n",
                                this_object()); 
                return 1;
        }
        message_vision("$N微微一耸眉说道：”易筋经乃少林至宝，一向只传有缘之人。。。”\n", this_object()); 
        if(me->query("betrayer") && me->query("class")=="shaolin" && budlvl<150) {
                message_vision("$N凝神看了看你说道，“徒儿，你前生杀孽太重，易筋经怕是与你无缘了。”\n",this_object());
                return 1;
                }       
        if(me->query("class") != "shaolin") {
                message_vision("$N笑道：“你既非我少林，还是不要多问了。”\n", this_object());
                return 1;
        } else if(explvl > 2400000 && budlvl > 150){
                message_vision(YEL"\n$N看了看$n，惊异的”啊“了一声。"NOR, this_object(), me);
                message_vision(YEL"长叹一声”原来如此，善哉，善哉。”\n"NOR, this_object());
                message_vision(YEL"$N看着$n说道：”要学易筋经，为师我先要考考你武学上的修为，可否？”\n"NOR, 
                                this_object(), me);
                message_vision(YEL"（ａｃｃｅｐｔ　ｙｅｓ／ｎｏ）\n"NOR, this_object());  
                add_action("do_accept", "accept");
                me->set_temp("marks/问心湖", 1);
                call_out("no_answer", 60, me);  
        } else {
                message_vision("$N看了看$n：”徒儿，你修行未够，不可强求。。。“\n", this_object(), me); 
        }       
        return 1;
}  
int do_accept(string arg) {
        object me;
        
        me = this_player();
        if(!arg || (arg != "yes" && arg != "no")){
                return 0;
        }
        if(me->is_fighting()){
                return notify_fail("你正在忙！\n");
        }
        if(!me->query_temp("marks/问心湖")){
                return 0;
        }
   if(this_object()->is_fighting() || this_object()->is_busy()){
                command("say 我现在正忙，等会吧。。。");
                return 1;
        }
        if(arg == "no"){
                remove_call_out("no_answer");
                message_vision("$N点了点头，闭上了眼，喃喃道：“得失从缘，心无增减，喜风不动，冥顺于道。。”\n",
                        this_object());
        } else if(arg == "yes"){
                remove_call_out("no_answer");
                message_vision("$N道：出招吧。（ｆｉｇｈｔ）\n", this_object());
                me->set("marks/challenge_xinhu", 1);
        }
        me->delete_temp("marks/问心湖"); 
        return 1;
} 
int accept_fight(object me){
        if(this_object()->is_fighting()){
                command("say 我现在正忙，等会吧。。。");
        } else if(!me->query("marks/challenge_xinhu")) {
                message_vision("$N闭上了眼，喃喃道：“得失从缘，心无增减，喜风不动，冥顺于道。。”\n", this_object());
                return 0;
        } else if (me->query("marks/面壁领悟") == 1) {
                message_vision(YEL"$N沉声吟到：”欲得净土，当净其心，随其心净，即佛土净，汝能明否？“\n"NOR,
                                this_object());
        } else if (me->query("marks/面壁领悟") == 2) {  
                message_vision(YEL"$N点点头说：”善哉，善哉。。。。。。“\n"NOR, this_object()); 
                message_vision(YEL"$N疾声喝到：”未来事未至，莫愿莫求，未来心自绝，即名无未来事。，汝能解否！“\n"NOR, 
                                this_object());
        } else if (me->query("marks/面壁领悟") == 3) {  
                message_vision(YEL"$N双手合十，微笑到：”恭喜，恭喜，你终于应证了大道！“\n"NOR, this_object());
                message_vision(YEL"$N双手合十，恭身谢道：”多谢师傅指点迷津。“\n"NOR, me); 
                message_vision("\n$N问道：”只如佛之与法，为是佛在先？为是法在先？若法在先，法是何佛所说？若是佛在先，\n",
                                this_object());
                message_vision("承何教而成道？”\n", this_object()); 
                message_vision("$N郎声回答：“佛亦在法先，亦在法后。”\n", me); 
                message_vision("\n$N又问到：“因何佛法先后？”\n", me); 
                message_vision("$N欣然曰：”一切诸佛，皆因寂灭法而得成佛，即是法先佛后。然始广说十二部经，引化众生。\n",
                                me);
                message_vision("众生承佛法教，修行得成佛，即是佛先法后也。”\n", me); 
           message_vision("$N和$n相对会心的一笑。\n", me, this_object());
                message_vision(HIY"\n$N说：“你要寻找的东西我已经指引给你了，你还不快去？”\n"NOR, this_object());
                me->delete("marks/面壁领悟");
                me->delete("marks/challenge_xinhu");
                me->set("marks/少林_面壁成功", 1);
                return 0;
        }
        message_vision("\n$N道：“接招。。。。”\n", this_object());
        return 1;
} 
void win_enemy(object obj){
        message_vision("$N摇了摇头，自言自语道：“可惜，可惜。”\n", this_object());    
} 
void lose_enemy(object me) {
        object room;
        
        if(!me->query("marks/面壁领悟")) {
                message_vision(HIR"\n$N勃然大怒：”蘖徒，和师傅过招也下这么重的手”，$N伸出左手无名指
在$n胸前一晃。\n"NOR, this_object(), me);
                tell_object(me, HIR"\n你觉得檀中一热，就失去了知觉。\n"NOR);
                me->set("marks/少林面壁", 1);           
                me->unconcious();
        } else if(me->query("marks/面壁领悟") == 1){
                message_vision(HIR"\n心湖大喝一声：“给我回去！”右手掌心向外平推，左手食指凌空虚点。\n"NOR, this_object());
                tell_object(me, HIR"你觉得胸口气血翻涌，眼前一黑，晕了过去。\n"NOR);
                me->set("marks/少林面壁", 1);
                me->unconcious();
        } else if(me->query("marks/面壁领悟") == 2) {
                message_vision(HIR"\n只见$N身形掠起，双手拇指同时按向$n太阳穴。$n大惊失色，躲闪不及。\n"NOR, 
                                this_object(), me);
                tell_object(me, HIR"只觉额头两侧一阵灼热，眼前一黑，晕了过去。\n"NOR); 
                me->set("marks/少林面壁", 1);
                me->unconcious();
        } 
        message("vision", "两个小沙弥走来把" + me->name()+ "抬了出去。\n", environment(me), me);
        room = find_object("/d/songshan/damocave");
        if(!objectp(room)){
                room = load_object("/d/songshan/damocave");
        }
        me->move(room);
   message("vision", "两个小沙弥把" + me->name() + "抬进来放到了地上。\n", room);
        me->delete_temp("marks/问心湖");
} 
void yijing(object me){
        
} 
void no_answer(object me) { 
        message_vision("$N点了点头，闭上了眼，喃喃道：“得失从缘，心无增减，喜风不动，冥顺于道。。”\n",
                        this_object()); 
        if(me->query_temp("marks/问心湖")){
                me->delete_temp("marks/问心湖");
        }
        delete("asking");       
} 
void attempt_apprentice(object me)
{
    if(me->query("once_menpai/shaolin") && me->query("once_menpai/wudang")
        && me->query("marks/bugout") && me->query("class")=="wudang"
                && me->query("combat_exp")>3000000
                && !me->query("marry")) {
        message_vision(HIY"$N说道：善哉善哉，苦海无涯，回头是岸，徒儿，你明白了？\n"NOR,this_object());
        message_vision(HIY"$N一掌击在$n的顶门上。\n"NOR,this_object(),me);
        me->delete_skill("changelaw");
        me->delete_skill("three-sword");
        me->delete_skill("five-steps");
        me->delete_skill("taiji");
        me->delete_skill("taijiforce");
        me->delete_skill("taiji-sword");
        me->delete_skill("qixing");
        if (me->query_skill("incarnation",1)>150) me->set_skill("incarnation",150);
        command("recruit " + me->query("id") );
        me->delete("marks/bugout");
        me->delete("once_menpai/wudang");
        me->add("betrayer", -2);  
        if (me->query("betrayer")<0) me->set("betrayer",0);
        return;
    }
    if(me->query_temp("won_master_yi")||me->query_temp("won_master_17"))
    {
        command("smile");
        command("recruit " + me->query("id") );
        me->delete_temp("won_master_yi");
        me->delete_temp("won_master_17");
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
        ob->set("class", "shaolin");
} 
int do_answer(string arg)
{
    object ob;
    if(arg == "不怕" )
    {
        command("say 好，你去吧！\n");
        command("say 这里是我的手谕，你用（wave）它才可以上藏经楼。\n");
        ob = new(__DIR__"obj/shouyu");
        if(ob) ob->move(this_player());
        return 1;
    }
    return 0;
} 
void die(){
        message_vision("$N退后几步微一凝气，脸色又恢复了红润。\n", this_object());
        "/cmds/imm/full"->main(this_object(),"");
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
        if(id_class == "shaolin"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：阿弥陀佛,佛门清静之地,岂可妄起杀心?施主请恕老衲得罪了！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="shaolin") return 0;
        message_vision(CYN"$N合掌道：阿弥陀佛，既是无缘，何必再留,以后也不要再回来了。\n"NOR, this_object(),this_player());
        return 1;
}  
int swit () {
        object me;
        me=this_player();
        if((me->query("family/family_name") == query("family/family_name") &&
                me->query("family/master_id") == query("id")) ){
                message_vision(CYN"$N道：你可以找达摩院的几位师叔学艺，只是他们授徒甚严，你要多加努力才成。\n",this_object());
                this_player()->set_temp("won_master_17",1);
                return 1;
        }
        return 0;
}
