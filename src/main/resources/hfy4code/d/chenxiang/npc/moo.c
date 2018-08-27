 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        object scoin;
        set_name("磨菜刀的", ({ "moman" }) );
        set("gender", "男性" );
        set("age", 47);
        set("long", "这个人是专门帮人磨剪子和锵菜刀的。\n");
        set("combat_exp", 10);
        set("str", 27);
        set("force", 30);
        set("max_force", 30);
        set("force_factor", 1);
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
                "磨菜刀的高声吆喝道：磨剪子喽～锵菜刀～～～\n",
                (: random_move :)
        }) );
        carry_object("/obj/armor/cloth")->wear();
        scoin= new(__DIR__"obj/coin");
        scoin->move(this_object());
} 
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + "！");
        return 1;
} 
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
        return 0;
}      
