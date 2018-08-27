 // beggar.c
inherit NPC; 
void create()
{
        set_name("老乞丐", ({ "old beggar","beggar" }) );
        set("gender", "男性" );
        set("age", 63);
        set("long", "一个满脸风霜之色，骨瘦如柴的老乞丐。\n");
        set("combat_exp", 100000);
        set("str", 30);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "老乞丐说道：好心的大爷哪～ 赏我穷叫花子的几文钱吧～\n",
                "老乞丐懒洋洋地打了个哈欠：要不是我本事太差，肯定也去入山流，
杀尽那些赃官恶霸。\n",
                (: random_move :)
        }) );
        setup();
        carry_object("obj/armor/cloth")->wear();
} 
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + 
"，您好心一定会有好报的！");
        return 1;
} 
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"饶命！小的这就离开！\n");
        return 0;
}
 
