#include <ansi.h>
inherit NPC;   
void create() 
{ 
        set_name("陈准", ({ "chen zhun","zhun"}) ); 
        set("title",  "饿虎寨 赛诸葛" );
        set("nickname",HIC "活陈平"NOR);
        set("gender", "男性"); 
        set("age", 53);
        set("long", 
                "陈准是个很瘦小的人，长得就象是那种从来也没有做过蚀本买卖的生\n意人一样，脸上不笑时也象是带着诡笑似的\n"); 
        set("combat_exp", 430000);
        set("score", 1000);
        set("attitude","friendly");
        set("bellicosity", 200);
        
        set("max_force", 1000);
        set("force", 1500);
        set("force_factor", 10); 
        set("int",30);
        set_skill("force", 60);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("changquan",100);
        set_skill("puti-steps",100);
        set_skill("move",100);
        
        map_skill("move","puti-steps");
        map_skill("dodge","puti-steps");
        map_skill("unarmed","changquan"); 
        setup(); 
        carry_object(__DIR__"obj/leather")->wear();
        carry_object(__DIR__"obj/fur_coat")->wear();        
        add_money("gold", 1); 
}   
void init() 
{ 
        object me; 
        ::init(); 
   me = this_player();
        if(me && environment(me) == environment() && !me->is_fighting()) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }   
}   
void greeting(object me) 
{ 
        if((string)me->name() !="老山东" ) 
        {
                command("say 嘿嘿，天堂有路你不走，地域无门你来投！吃拳！\n");
                this_object()->kill_ob(me);
        }
        else if ((string)me->name() =="老山东")
        {
                message_vision("$N眯着眼睛盯着$n看了半晌......\n",this_object(),me);
                if((int)me->query("kar")+random(50) < 30 )
                {
                        message_vision("$N尖声道：“你瞒得了别人瞒不了我！哪里走！”\n",this_object(),me);
                        this_object()->kill_ob(me);
                }
        }
}     
