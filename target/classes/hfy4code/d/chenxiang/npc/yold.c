 // (C)1998-2000 Tie Yu
inherit NPC;
void create()
{
    set_name("杨老太", ({ "yang","yang laotai" }) );
    set("gender", "女性" );
    set("title","无依无靠");
    set("long","杨老太无依无靠，天天靠讨饭为生，真的很可怜！\n");
    set("age", 75);
    set("combat_exp", 5);
    set("attitude", "friendly");
    set("chat_chance", 5);
    set("chat_msg", ({
        "杨老太抹了抹眼泪：我饿呀，谁可怜可怜我吧！\n",
            }) );
    setup();
    carry_object("/obj/armor/cloth")->wear();
} 
int accept_object(object me, object obj)
{
    object ob;
    me->add_temp("marks/杨老太",obj->value());
    if(me->query_temp("marks/杨老太") > 49000 && !query("given"))
    {
        command("say 看来你是个好心人，我有一卷越秀山的艾绒，专门可以灸各种瘀肿，送给你吧！\n");
        ob= new(__DIR__"obj/arong");
//      set("given",1);
        ob->move(me);
        me->delete_temp("marks/杨老太");
    }
    else command("say 这点哪里够呢？\n");
    return 1;   
} 
/*
void reset()
{
delete("given");
}*/     
