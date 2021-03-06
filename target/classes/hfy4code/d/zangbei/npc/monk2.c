#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int loan(); 
void create()
{ 
        set("long", "塔公寺的老喇嘛，衣着比起附近寺庙里的喇嘛差多了，愁眉苦脸地望着塔林出神。\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 2000000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",30);
        set("class", "lama");
        
        set_skill("iron-cloth", 100);
        set_skill("staff", 100);
        set_skill("lamastaff", 100);
        set_skill("unarmed", 160);
        set_skill("lamaism", 100);
        set_skill("bloodystrike", 160);
        set_skill("force", 100);
        set_skill("bolomiduo", 100);
        set_skill("spells",100);
        set_skill("parry",100);

        set_skill("kwan-yin-spells",100);
        set_skill("perception", 100);
        
        map_skill("spells","kwan-yin-spells");
        map_skill("parry","lamastaff");
        map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("staff", "lamastaff");
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("inquiry", ([
                "香火":         (: loan() :),
                "香火钱":       (: loan() :),
                "朝圣":         (: loan() :),
                
 
        ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"说：施主，布施点香火钱吧。\n",  
        }) );
        set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
            (: perform_action, "fefawubian" :),
            }) ); 
/*        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) ); */
         
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
       set_name("塔公寺的喇嘛",({"tagong lama","lama"}));
        set("force_factor",40+random(50));
        setup();
        carry_object(__DIR__"obj/lamacloth")->wear();
        
}  
int loan(){
        object ob=this_object();
        
        message_vision(CYN"老喇嘛叹了口气说“这塔公寺年久失修，现在来朝圣的人是越来越少了。”\n"NOR,ob);
        message_vision(CYN"老喇嘛用希冀的眼光看着$N：“施主可愿捐些香火？”\n\n"NOR,this_player());
        return 1;
}   
int accept_object(object who, object ob){
        
        if (ob->query("value")<100000) {
                message_vision(CYN"老喇嘛脸上露出一丝失望，“嗯，多谢施主。”\n"NOR,this_object());
        } else if (ob->query("value")<500000) {
                message_vision(CYN"老喇嘛双掌合十，低头垂目：“嗯，多谢施主。”\n"NOR,this_object());
        } else {
                message_vision(CYN"老喇嘛的眼里忽然放出光来，话音也有些颤抖：“佛祖一定会保佑施主的。
老衲这就去让人重修佛塔，再塑金身。”\n"NOR,this_object());
                tell_object(who,WHT"听了老喇嘛的话你才注意到，原来这里的塔林久经风雨，已经十分破旧了。\n"NOR);
                who->set("zangbei/塔公寺施舍",1);
        }
        return 1;
}  
