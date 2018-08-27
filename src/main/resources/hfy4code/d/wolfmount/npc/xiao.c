 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("萧十一郎", ({ "xiao11","xiao" }) );
        set("gender", "男性" );
        set("age", 25);
        set("per", 27);
        set("reward_npc", 1);
        set("difficulty", 10);

        set("attitude", "peaceful");
        set("max_atman", 300000);
        set("atman", 300000);
        set("class", "wolfmount");
        
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300000);
        set("force_factor",20);
        set("mana", 300000);
        set("long",     "他全身又干净又整洁，就像一个刚刚剥了壳的鸡蛋。\n");
        set("combat_exp", 9999999);
    set("title", "大盗");



        set_skill("blade", 120);
        set_skill("unarmed",50);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);
        set_skill("parry", 140);
        
        set_skill("animal-training", 174);
        set_skill("summonwolf", 174);
        
        set_skill("ittouryu", 280);
        set_skill("wolf-claw", 360);
        set_skill("xueyeqianzong", 440);
        
        
        map_skill("unarmed", "wolf-claw");
        map_skill("blade", "ittouryu");
        map_skill("parry", "ittouryu");
        map_skill("dodge", "xueyeqianzong");
        
        
        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                     (: ccommand, "xiao" :),

        }) );  

        
        
        
        
        setup();
        carry_object(__DIR__"obj/gelu")->wield();
        carry_object("/obj/armor/cloth")->wear();
}
void init()
{
        object me;
        ::init();
        add_action("do_answer","answer");
        me = this_player();
        if(interactive(me) 
        ) call_out("ask_him", 1,me );  
} 
int ask_him(object me)
{
        if(environment(me) == environment())
   tell_object(me,name()+"问道：到底谁是天宗的新主人？（answer）\n");
        return 1;
}
int do_answer(string arg)
{
object me;
me =this_player();
if(!arg )
return notify_fail(name()+"道：看来你也帮不了我！\n");
if( arg == "lian" || arg == "lian cheng bi" || arg == "连城壁")
{
if(me->query_temp("in_doubt") && me->query_temp("listened"))
{
        if(!me->query("m_success/识破天宗"))
        {
                me->set("m_success/识破天宗",1);
                me->add("score",300);
        }
command("unwield gelu");
command("give gelu to " + me->query("id"));
tell_object(me,name()+"道：你真是一语道破梦中人！好！\n");
return 1;
}
else
return notify_fail(name()+"道：真的吗？没有证据呀！\n"); 
}
else
return notify_fail(name()+"道：我觉得不像！\n");
}    
