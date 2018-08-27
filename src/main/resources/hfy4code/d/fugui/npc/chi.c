#include <ansi.h>
inherit NPC;
void create()
{
        set_name("赤练蛇", ({ "chilian she", "she" }) );
        set("long",
         "他就是无孔不入赤炼蛇，惹上他，你只有一条路好走--被他毒死。\n");
        set("nickname", RED "无孔不入"NOR);
        
        set("combat_exp", 1300000);
        set("no_arrest",1);
        set_temp("apply/damage",80);
        
        set_skill("unarmed", 200);
        set_skill("force",100);
        set_skill("parry",150);
        set_skill("dodge", 150);
        set_skill("move",100);
        set_skill("blade",100);
        set_skill("qiusheng-blade",150);
        set_skill("cloudforce",100);
        set_skill("literate",100);
        set_skill("meng-steps",100);
        set_skill("yunwu-strike",150);
        
        map_skill("unarmed","yunwu-strike");
        map_skill("blade","qiusheng-blade");
        map_skill("dodge","meng-steps");
        map_skill("move","meng-steps");
        map_skill("force","cloudforce");
        map_skill("parry","qiusheng-blade");
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();
} 
void init()
{
                ::init();
                add_action("do_get","get");
} 
int do_get(string arg)
{
        string what,where;
        if(!arg) return notify_fail("你想拿什么？\n");
        if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
        if((where == "fentou" || where == "坟头" ))
        {
                command("say 想拿解药，先过了我这一关再说。");
                return 1;
        }
}
