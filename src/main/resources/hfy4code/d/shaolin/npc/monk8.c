 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        string *name = ({"��","��","��","��","��","��","Ӱ","��","��","��","��","��"});
        set_name("��"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(20)+ 32);
        set("cor",random(20)+20);
        set("class","shaolin");
        create_family("������", 19, "����");
        set("long", "���������µĺ���\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", 800000);
        set("attitude", "friendly");
        set("cps",80);
        set("force",550);
        set("max_force",550);
        set("force_factor",20);
        
        set_skill("blade", 160);
        set_skill("dodge", 160);
        set_skill("puti-steps",150);
        set_skill("dabei-strike",160);
        set_skill("lianxin-blade",150);
        set_skill("move",180);
        set_skill("force",200);
        map_skill("unarmed","dabei-strike");
        map_skill("dodge","puti-steps");        
        map_skill("blade", "lianxin-blade");
         
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.yipianlianxin-npc" :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/monk21_cloth")->wear();
   carry_object(__DIR__"obj/jiblade")->wield();
}   
