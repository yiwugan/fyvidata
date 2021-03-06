 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("王莹", ({ "wang ying", "wang"}) );
        set("gender", "女性" );
        set("age",22);
        set("long", "一个佩剑的黄山派弟子。\n");
        create_family("黄山派", 6, "弟子");
        set("combat_exp", random(10000)+1000);
        set("attitude", "friendly");
        set_skill("sword", 60+random(10));
        set_skill("siqi-sword",random(50)+30);
        set_skill("move",60);
        set_skill("force",20);
        map_skill("sword", "siqi-sword");
        set_skill("dodge",100);
        set_skill("liuquan-steps",40+random(40));
        map_skill("dodge","liuquan-steps");
        set("chat_chance", 5);
        set("chat_msg", ({
"王莹长剑一指道：大好河山呀！真是黄山绝胜处！\n",
        }) );
        set("chat_chance_combat", 30);
        set("force",500);
        set("chat_msg_combat", ({
                (: perform_action, "sword.siqi" :),
        }) );
        set("max_force",500);
        set("force_factor",2);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}       
