 inherit QUESTNPC;
//inherit F_MASTER;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("路小佳", ({ "lu xiaojia", "lu" }) );
        set("gender", "男性" );
    	set("age", 25);
    	set("title", "独行客" );
    	set("nickname", HIR"快意江湖"NOR );
        set("int", 35);
        set("per", 30);
        set("npc_difficulty",10); 
        set("organization/性质","邪");
        set("quest_npc",1);
        set("class","assassin");
        set("resistance/kee",60);
        set("resistance/gin",60);
        set("resistance/sen",60);
        set("long",
                "他是个年轻人，一个奇怪的年轻人，有着双奇怪的眼睛，就连笑的时候，这双眼睛都
是冷冰的，就像是死人的眼睛，没有情感，也没有表情。
\n"
                );
        set("max_gin", 300000);
        set("max_kee", 300000);
        set("max_sen", 300000);
        set("eff_gin", 300000);
        set("eff_kee", 300000);
        set("eff_sen", 300000);
        set("gin", 300000);
        set("kee", 300000);
        set("sen", 300000);
        set("max_force", 4000);
        set("force", 4000);
        set("force_factor", 100);
        set("cor",80);
        set("str",50);
        set("combat_exp", 80000000);
        set("score", 3000);
        set("agi",25);
        set("int",30);
        set("chat_chance",10);
                set("chat_msg",({
"路小佳拈起一颗花生，剥开，抛起，然后看着这颗花生落到自己嘴里，闭上眼睛，
长长的叹了口气，开始慢慢咀嚼。\n",
"路小佳忽然笑笑 ，说道：“杀人是件干净痛快的事情。”他顿了一顿，又说道：
“所以在杀人之前，我一定要洗个澡。”\n",
        })      );
        set_skill("sword", 500);
        set_skill("force", 200);
        set_skill("parry", 300);
        set_skill("literate", 140);
        set_skill("dodge", 280);
        set_skill("sharen-sword", 300);
        set_skill("move", 300);
        set_skill("jinhong-steps", 200);
        set_skill("jingxing",250);
        map_skill("force","jingxing");
        map_skill("dodge","jinhong-steps");
        map_skill("move","jinhong-steps");
        map_skill("sword", "sharen-sword");
        map_skill("parry","suiyuan-sword");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );
        setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/lusword")->wield();
}   
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_skill("iron-cloth")>175) {
                                if (this_object()->query_temp("weapon")){
                                command( "say 好俊的硬功，看我的！");
                                command("unwield all");
                                }
                        } else  command("wield all");
                        
                        if (!enemy[i]->query_temp("till_death/lockup"))
                        {
                                this_object()->smart_busy();
                        } else this_object()->smart_attack();
                        
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.canglongzhaxian");
}
smart_attack() {
        this_object()->perform_action("sword.sharenruma");      
        }    
