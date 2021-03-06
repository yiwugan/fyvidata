 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("马秀真", ({ "ma xiuzhen","ma" }) );
        set("gender", "女性" );
        set("title", "峨嵋派 侠女" );
        set("nickname", HIC"三英四秀之"NOR );
        set("long",
"身材很高，细细长长的一双凤眼，在笑的时候仿佛也带着种逼人的杀气。\n"
                );
        set("attitude", "peaceful");
        set("age", 27);
        set("cps", 40);
        set("int", 50);
        set("per", 15);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 100000);
        
        set("force", 500);
        set("max_force", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 10);
        set("inquiry",  ([
                "叶孤城" : "哼，什么一剑西来，天外飞仙，我看也不过如此，如果遇到我师傅他老人家，\n定叫他拱手让出天下第一剑的名头。\n",
                "master ye" : "哼，什么一剑西来，天外飞仙，我看也不过如此，如果遇到我师傅他老人家，\n定叫他拱手让出天下第一剑的名头。\n",
                  "西门吹雪" :" 这个冷血魔头，杀了我师兄苏少英，这血海深仇一定要报！\n",
                  "master ximen" : "这个冷血魔头，杀了我师兄苏少英，这血海深仇一定要报！\n",
        ])                      );
       set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "马秀真挑了挑丹凤眼，不屑道：白云岛也不过如此。\n",
                }) ); 
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("sky-sword", 10);
        set_skill("liuquan-steps", 10);
        map_skill("dodge", "liuquan-steps");                
        map_skill("move", "liuquan-steps");                
        map_skill("sword", "sky-sword");
        map_skill("parry", "sky-sword");
        setup(); 
        carry_object("/obj/weapon/sword")->wield();
        add_money("gold",2);
        carry_object("/d/fugui/npc/obj/w_skirt1")->wear();
}   
