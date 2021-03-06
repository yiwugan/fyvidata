#include <ansi.h>
inherit NPC;
void goto_batdao(object ob);
void create()
{
    set_name("高亚男", ({ "gao yanan", "gao" }));
    set("long", "她身材高挑，一身青衣窄袖，显得英气勃勃。她有一双令人心跳加快的眼睛。\n" );
        set("title", "华山派 第十七代弟子");
        set("gender", "女性");
        set("age", 18);
        set("per", 27);
        set("int", 24);
        set("con", 25);
        set("agi", 23);
        set("class","huashan");
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 30);
        set("combat_exp", 800000+random(500000));
        
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                "高亚男自言自语道：“师傅让我在这里注意她做什么。”\n", 
                "高亚男道：“这个华真真为什么总藏在玉女峰上面？”\n", 
        }) );
        set_skill("unarmed", 75);
        set_skill("move", 80);
        set_skill("dodge", 90);
        set_skill("parry", 80);
        set_skill("force", 80);
        set_skill("sword", 70);
        set_skill("qingfeng-sword", 50);
        set_skill("anxiang-steps", 90); 
        map_skill("move", "anxiang-steps");
        map_skill("parry", "qingfeng-sword");
        map_skill("sword", "qingfeng-sword");
        map_skill("dodge", "anxiang-steps"); 
        setup();
        carry_object(__DIR__"obj/gcloth",
           ([      "name"  :       "青衣",
                "long"  :       "淡青色的小褂。"                ])
        )->wear();
        carry_object("/obj/weapon/sword")->wield(); 
}     
