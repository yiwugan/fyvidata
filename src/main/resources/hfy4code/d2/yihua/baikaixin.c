inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
        set_name(HIW "白开心" NOR, ({ "baikaixin" }) );

        set("gender", "男性");
        set("age", 48);
        set("long",
                "这人猥猥琐琐，嘻皮笑脸，正是一副标标准准的地痞无赖相，你无论在任何一个城
的茶楼赌馆花街柳巷里，都可以见到，但无论任何人都不会对这种人多瞧一眼的.\n");
        set("attitude", "heroism");
        set("skill_public",1);
        set("no_arrest",1);
        set("str", 40);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "白开心呲着满口的黄牙冲你嘻嘻嘻的直笑.\n",
        }) );

        set("force", 40000);
        set("max_force", 8000);
        set("force_factor", 100);

        set("combat_exp", 3000000);
        set("score", -20000);
        
        set_skill("move", 100);
       set_skill("dodge", 90);
        set_skill("staff", 200);
        set_skill("force", 100);
        set_skill("iron-cloth", 100);
        set_skill("jin-gang", 130);
        set_skill("xingyi-stick", 130);
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "xingyi-stick");

        create_family("eren", 1, "四师傅");
        set("title", HIY "损人不利己" NOR);
        setup();
        carry_object(__DIR__"obj/shaohuo")->wield();

}

