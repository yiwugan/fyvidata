 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("琴心" , ({ "qin xin","qin" }) );
    set("nickname",HIC"枕琴囊"NOR);
    set("long", "一个白衣女子席地而坐，膝上放着一张焦尾琴，正自弹奏。身周树木上停满了\n和琴声或一问一答，或齐声和唱。\n");
        set("attitude", "friendly");
    set("age", 22);
    set("per",40);
        set("gender", "女性" );
        create_family("白云城",1, "才女");
    set("combat_exp", 2500000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "琴心轻拂膝上瑶琴，琴音和鸟语互相应答，间间关关，宛转啼鸣。\n",
        "琴心柳眉微蹙，琴声忽高忽低，忽轻忽响，“铮”的一声，一根「徵弦」忽然断了。\n",
        }) );
    set_skill("dodge", 200);
    set_skill("anxiang-steps", 200);
    set_skill("qingfeng-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("spring-water", 100);
    map_skill("iron-cloth","spring-water");
    map_skill("sword","qingfeng-sword");
    map_skill("dodge","anxiang-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.yexuechiji" :),
        }) ); 
        setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}      
