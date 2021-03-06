 // taolord.c
#include <ansi.h>
inherit QUESTNPC;
void create()
{
        set_name("云真人", ({ "master yun", "master", "yun" }) );
        set("nickname", HIW"太极神剑"NOR);
        set("gender", "男性");
        set("age", 69);
        set("long",
"云真人是当今武当掌门石雁的师叔，一手太极剑法名动天下。\n"
);                
        set("combat_exp", 80000000);
        set("score", 50000);
        set("npc_difficulty",10); 
//        set("quest_npc",1);
        set("class", "wudang"); 
        set("str", 80);
        set("int", 33);
        set("cor", 45);
        set("cps", 30);
        set("spi", 30);
	set("fle",      45); 
        set("force", 4000);
        set("max_force", 4000);
        set("force_factor", 100);
        set("max_kee",300000);
        set("max_gin",200000);
        set("max_sen",200000); 
        set("inquiry", ([
                "太极剑法": 
"太极剑法的秘诀，就在于一个“慢”字。\n",
        ]) ); 
//        set("apprentice_available", 1);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chanzijue" :),
                (:perform_action,"unarmed.nianzijue":),
        }) ); 
        create_family("武当派", 56, "真人"); 
        set_skill("literate", 140);
        set_skill("force", 200);
        set_skill("move", 240);
        set_skill("unarmed", 220);
//        set_skill("wudang-quan",220);
        set_skill("sword", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("changelaw", 500);
        set_skill("taiji-sword", 300);
        set_skill("taijiforce", 200);
        set_skill("taiji", 400);
        set_skill("five-steps", 250);
        map_skill("spells","qixing");
        map_skill("parry", "taiji-sword");
        map_skill("sword", "taiji-sword");
        map_skill("literate", "changelaw");
        map_skill("force", "taijiforce");
        map_skill("unarmed", "taiji"); 
        setup(); 
        carry_object("/obj/weapon/sword")->wield();
        carry_object(__DIR__"obj/taocloth")->wear();
        carry_object(__DIR__"obj/taohat")->wear();
} 

int accept_fight(object me)
{
        command("say 好，就让你见识见识什么叫真功夫。");
        return 1;
}