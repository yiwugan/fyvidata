 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�ض�ү", ({ "master guan", "master" }) );
        set("gender", "����" );
        set("title", "��ʥ" );
        set("nickname", HIC"ǧ���ߵ���"NOR );
        set("age", 44);
        set("cor", 40);
        set("cps", 30);
                
        set("attitude","friendly");
        set("max_force", 100);
        set("force", 100);
        set("force_factor",10);
        set("long",
"
����������������ܸ����壬ǧ����ɩ�������ն�����Ĺض�ү\n"
        );
        set("combat_exp", 2000000);
        set("no_busy",4); 
        set_skill("move", 170);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("force", 160);
        set_skill("blade",150);
        set_skill("shortsong-blade",120);
        set_skill("qidaoforce",120);
        set_skill("fall-steps",150);
        
        map_skill("parry","shortsong-blade");
        map_skill("blade","shortsong-blade");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        
        setup();
           carry_object(__DIR__"obj/g_blade")->wield();
        carry_object("/obj/armor/cloth")->wear();
}  
int is_ghost() { return 1; }    
