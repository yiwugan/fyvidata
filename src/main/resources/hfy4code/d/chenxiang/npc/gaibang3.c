 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
//inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("����", ({ "dai", "dai ying"}) );
        set("title", "ؤ���������");
        set("gender", "����" );
        set("age", 34);
        set("attitude","friendly");
/*        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 15); */  
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xianglongwuhui" :)
        }) );
        set("combat_exp", 250000);
        set_skill("move", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
        set_skill("unarmed",100);
        set_skill("doggiesteps",80);
        set_skill("dragonstrike",80);
        set_skill("huntunforce",80);
        set_skill("begging",120);
        set_skill("inquiry",120);
        map_skill("dodge", "doggiesteps");
        map_skill("force", "huntunforce");
        map_skill("unarmed", "dragonstrike");
        setup();
        carry_object(__DIR__"obj/5bagcloth")->wear(); 
}  
