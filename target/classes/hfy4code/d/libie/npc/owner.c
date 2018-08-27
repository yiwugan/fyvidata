#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("客栈老板", ({ "lao ban","owner" }) );
        set("long",
                "一个肥肥胖胖的中年人。"); 
        set("attitude", "friendly"); 
        set("str", 20);
        set("cor", 10);
        set("agi", 10); 
        set("combat_exp", random(5000)); 
/*      set_skill("unarmed",150);
        set_skill("parry",150);
        set_skill("dodge",150);
*/      
        set("chat_chance", 1);
        set("chat_msg", ({
"老板擦着柜台叹道：你说杨捕头那么好的人，怎么会是劫镖大盗呢？\n"
        }) );
        set_temp("布衣",10);
        
        
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
} 
void init()
{
        ::init();
    add_action("do_give","give");
} 
int do_give(string arg)
{       string objectname, acceptor;
        object ob,who,cloth;
        int val;
        
        if( sscanf(arg, "%s to %s", objectname, acceptor)<2 ) 
                return 0;
        if(acceptor!="客栈老板"&&acceptor!="lao ban"&&acceptor!="owner")
                return 0; 
   who=this_player();
        ob=present(objectname,who);
        if(!objectp(ob)) return 0;
        val=ob->value();
        if (!val) return 0;
        if ((val<10000) ||!query_temp("布衣"))
        {
        message_vision(YEL "客栈老板摆摆手笑道：这怎么敢当？\n"NOR,who);
                return 1;
        }
        add_temp("布衣",-1);
        message_vision("$N拿出"+ob->query("name")+"给客栈老板。\n",who);
        destruct(ob);
    message_vision(HIY "客栈老板笑逐言开，连声说道：好说好说。\n",who);
    tell_object(who,HIY "客栈老板对你附耳说道：这位"+RANK_D->query_respect(who)+"想见狄小侯爷？没问题，穿上这个就可以了。\n");
        tell_object(who,HIY"客栈老板递给你一件店小二的装束。\n"NOR);
        cloth=new(__DIR__"obj/waitercloth");
        cloth->move(who);
        who->set_temp("libie/见狄青麟",1);
        return 1;
}
        
/*
int accept_object(object who, object ob)
{       
        int val;
        val=ob->value();
        if (val>10000)
        {
                say(HIG"老板笑逐言开，连连点头道：“好说好说，有什么要拜托的？”\n"NOR);
                add_action("do_answer","answer");
        }
*/   
