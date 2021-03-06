#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";
//inherit "/d/taiping/npc/timeshift"; 
inherit NPC;
int show_me();
void time_greet(object ob); 
void create()
{
        set_name("胡歪瓜",({"hu waigua","hu","waigua"}));
        set("title","地痞");
        set("long","胡歪瓜原名胡锦绣，是这里镇上的一个小地痞，他整天耷拉着脑袋东走西走，所
以人们背后就偷偷地叫他胡歪瓜。\n");
        set("gender","男性");
        
        set("combat_exp",5000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        set("max_atman",random(1000));
        set("atman",query("max_atman"));
        set("max_mana",random(500));
        set("mana",query("max_mana"));
        set("max_force",1000+random(500));
        set("force",query("max_force"));
        set("force_factor",100);
        
        set("resistance/kee",random(30));
        set("resistance/gin",random(30));
        set("resistance/sen",random(30));
                
        set("inquiry", ([
                "保护费" :      (: show_me :),
                "protection" :  (: show_me :),
        ]));
                
        set("day_room",AREA_BIANCHENG"smallroad2");
        set("dinner_room",AREA_BIANCHENG"mianguan");
        set("shift/dinner_leave","$N伸了个懒腰：“干活去了“，说罢向北离开。\n");
        set("shift/dinner_arrive","$N慢条斯理地走了过来。\n");
        set("shift/after_dinner","$N嘿嘿冷笑几声，向门外走去。\n");
        set("shift/back_dinner","$N打着饱嗝走了过来。\n");
                        
        set("death_msg",CYN"\n$N说：“英雄。。饶命啊。”\n"NOR);        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: name()+"叫道：“老子一拳把你打成个歪瓜！”\n",
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                "胡歪瓜得意洋洋地道：“做人，就要会动脑子，死干活不成。”\n",
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","tigerstrike",2);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();    
    
} 
int show_me() {
        command("say 怎么？你也想交钱？还是看不顺眼？");
        command("say 看不顺眼可以，先问过老子的拳头，要不要来比划比划？");
        this_player()->set_temp("wanma/can_fight",1);
        return 1;
} 
int accept_fight(object me){
        if (!me->query_temp("wanma/can_fight")) {
                command("say 老子哪有这闲工夫！");
                return 0;
        }
        
 //下面这个屏蔽是无奈的。
/*        if (!check_health(this_object(),99) || this_object()->is_fighting()) {
                command("say 想群殴啊？让老子先喘口气！");
                return 0;
        }   */
        command("say 好，你赢了我，这地头就是你的了！\n");
        return 1;
}  
void win_enemy(object loser){
    command("pk "+loser->get_id());
} 
void lose_enemy(object winner){
    command("say 你狠，咱们骑驴看唱本，走着瞧。\n");
    winner->set_temp("wanma/胜地痞",1);
} 
void init() {
        
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("shifting");
                call_out("shifting", 1, me);
        }
}  
void time_greet(object ob) {
        object *inv;
        int i;
        inv=all_inventory(environment(ob));
        if (sizeof(inv)<=1) return;
        
        for (i=0;i<sizeof(inv);i++){
                if (inv[i]->query("id")=="zhang laoshi") {
                        message_vision(YEL"$N对$n说：“今天的保护费准备好了么？”\n"NOR,ob,inv[i]);
                        message_vision(YEL"$n叹口气，塞给$N几张银票。\n"NOR,ob,inv[i]);
                }
        }
        
} 
