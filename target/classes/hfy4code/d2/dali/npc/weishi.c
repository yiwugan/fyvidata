#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIY "金甲卫士" NOR, ({"weishi" }) );
        set("long",

"他全身披挂，一动不动地站在那里，有说不出的威风。\n");
        set("attitude", "heroism");
        set("pursuer", 1);
        set("vendetta_mark", "dali");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 1000000+random(1500000));
        set_skill("sword", 120+random(60));
        set_skill("dodge", 130);
        set_skill("parry", 140);
        set_skill("move", 120);
        set_skill("force", 150);
        set_skill("duan-sword", 100);
        set_skill("duan-force", 200);
        set_skill("iron-cloth", 200);
        map_skill("force","duan-force"); 
        map_skill("sword","duan-sword"); 
        map_skill("parry","duan-sword"); 

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/armor")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 500000 ) {
                        say("金甲卫士笑呵呵的道：就这么的吧...\n");
                        who->set("vendetta/dali", 0);
                        who->remove_all_killer();
                        return 1;
                } else {
                    say("金甲卫士说道：你打发叫花子呢！！！\n");
                        return 0;
                }
        return 0;
}
