#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
//      set("title",YEL"恶人窟守卫"NOR);
        set("long", "这是一伙专门打劫行商的马贼。\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 1500000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",30);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",150,125,1,"/obj/weapon/","fighter_w","all");
        set_name("马贼",({"bandit"}));
        set("force_factor",40);
        setup();
        carry_object(__DIR__"obj/oldcloth")->wear();
        
}  
void init() {
   
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
         add_action("do_kill", "kill");
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() ) return;
        if (ob->query("gender")=="女性") {
                message_vision(CYN"$N对着$n叫道：美人，留下跟着大爷吃香喝辣吧！\n"NOR,this_object(),ob);
                return;
                }
        else    {
                message_vision(CYN"$N叫道：劫财不伤命，识相的就把金子留下，大爷放你一点生路！\n"NOR,this_object());
                kill_ob(ob);
                }
} 
int do_kill(string arg){
        
        
        if ( (arg=="bandit" || arg=="bandit 2") && !this_object()->is_fighting()
                && this_player()->query_temp("eren/bandit_2") 
                && this_player()->query("combat_exp")>=2500000){
                message_vision(CYN"$N大叫一声：不好，点子扎手，扯呼！\n"NOR,this_object());
                message_vision("$N一溜烟地往废墟背后跑掉了。\n",this_object());
                this_player()->set_temp("eren/bandit_around",1);
                destruct(this_object());        
                return 1;
                }
        return 0;
}    
