 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("叶秀珠", ({ "ye xiuzhu","ye" }) );
        set("gender", "女性" );
        set("title", "峨嵋派 侠女" );
        set("nickname", HIG"三英四秀之"NOR );
        set("long",
"一个年轻而美丽的少女，窄窄的衣服衬得苗条的身子更加婀娜动人。\n"
                );
        set("attitude", "peaceful");
        set("age", 22);
        set("cps", 40);
        set("int", 50);
        set("per", 20);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 100000);
        
        set("force", 500);
        set("max_force", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 10);
        set("inquiry",  ([
               "叶孤城" : "白云城主的岛不大，架子倒不小，我们峨嵋四秀 来了，竟也没个接待的。\n",
               "master ye" : "白云城主的岛不大，架子倒不小，我们峨嵋四秀 来了，竟也没个接待的。\n",
                 "西门吹雪"  :"看孙师妹这些日子恍恍忽忽，定是和这个冷血杀手。。\n",
                 "master ximen"  :"看孙师妹这些日子恍恍忽忽，定是和这个冷血杀手。。\n",
        ])                      );
       set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "叶秀珠恨恨道：师傅真是，几十年了峨嵋山还不如小小白云岛气派。。\n",
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
        carry_object("/d/fugui/npc/obj/w_skirt2")->wear();
}      
