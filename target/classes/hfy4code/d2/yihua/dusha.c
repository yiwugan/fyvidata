inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
        set_name(HIR"杜杀" NOR, ({ "dusha" }) );
        set("no_arrest",1);

        set("gender", "男性");
        set("age", 46);
        set("long",
                "    这人身子又瘦又长，一身雪白的长袍，双手缩在袖中，面色苍白，白得几乎如冰一般变
得透明了。\n");
        set("attitude", "aggressive");
        set("skill_public",1);
        set("str", 40);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "杜杀冷冷地盯了你一眼．．．．\n",
        }) );

        set("force", 40000);
        set("max_force", 8000);
        set("force_factor", 100);

        set("combat_exp", 3200000);
        set("score", -50000);
        
        set_skill("move", 120);
       set_skill("dodge",120);
        set_skill("unarmed", 200);
        set_skill("force", 150);
        set_skill("iron-cloth", 120);
        set_skill("jin-gang", 130);
        set_skill("tigerstrike", 130);
        map_skill("iron-cloth", "jin-gang");
        map_skill("unarmed", "tigerstrike");

        create_family("eren", 1, "大师傅");
        set("title", HIR "血手" NOR);
        setup();
        carry_object(__DIR__"obj/tiegou")->wield();

}

