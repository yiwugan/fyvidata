#include <ansi.h>
inherit NPC;
void goto_batdao(object ob);
void create()
{
    set_name("小铃儿", ({ "xiao linger", "linger" }));
    set("long", "她身材娇小，漆黑的长发娩成一对垂髻，闪亮著的大眼中充满好奇。\n" );
        set("title", "华山派 第十七代弟子");
        set("gender", "女性");
        set("age", 13);
        set("per", 27);
        set("str", 30);
        set("int", 24);
        set("con", 25);
        set("agi", 20);
//      set("max_kee", 600);
//      set("max_gin", 600);
        set("force", 1000);
        set("max_force", 800);
        set("force_factor", 50);
        set("combat_exp", 80000+random(50000));
        set("attitude", "friendly");
        set("chat_chance", 5);
        set("chat_msg", ({
                "小铃儿小声说：“我师傅晚上练功夫，一把就抓进树干了耶。” \n",
                "小铃儿自言自语道：“华真真师姐好像在教师傅功夫，真是奇怪呀。”\n", 
                "小铃儿道：“华师姐喜欢在晚上弹琴的。”\n", 
        }) ); 
        set_skill("unarmed", 43);
        set_skill("move", 50);
        set_skill("dodge", 45);
        set_skill("parry", 35);
        set_skill("force", 49);
        set_skill("sword", 30);
        set_skill("qingfeng-sword", 20);
//      set_skill("zixia-force", 90);
        set_skill("huashan-steps", 30);
        map_skill("force", "zixia-force");
        map_skill("move", "huashan-steps");
        map_skill("parry", "qingfeng-sword");
   map_skill("sword", "qingfeng-sword");
        map_skill("dodge", "huashan-steps"); 
        setup();
    carry_object(__DIR__"obj/gcloth",
        ([      "name"  :       "青衣",
                "long"  :       "淡青色的小褂。"                ])
        )->wear();
    carry_object("/obj/weapon/sword_short")->wield(); 
}
