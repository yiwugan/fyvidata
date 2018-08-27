 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    set_name("���", ({ "master tian", "master"}) );
    set("nickname", HIW "ǰ�η���"NOR);
    set("vendetta_mark","shaolin");
    set("gender", "����" );
    set("age", 94);
    set("per", 25);
    set("int",30);
    set("cps",60);
    set("attitude","friendly");
    set("max_force", 1500);
    set("force", 1500);
    set("force_factor",40);
    set("no_busy",10);
    set("resistance/kee",50);
    set("resistance/gin",50);
    set("resistance/sen",50);
    
    set("long", "���ֵĵ�ʮ������ɣ��������Ѹߣ������ڴˡ�\n");
    create_family("������", 15, "��ʦ");
    
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"�����������������ã�һ��ƷζƷζ���ɡ�����\n",
            name()+"̾����������ѽ������\n"
        }) );
    set("reward_npc", 1);
    set("difficulty", 10);    
    set("combat_exp", 5000000);
    
    set_skill("move", 200);
    set_skill("dodge", 200);
    set_skill("force", 200);
    set_skill("literate", 120);
    set_skill("unarmed",200);
    set_skill("puti-steps",200);
    set_skill("yiyangzhi",180);
    set_skill("xiaochengforce",90);
    set_skill("staff",200);
    set_skill("parry",200);
    
    map_skill("dodge", "puti-steps");
    map_skill("force", "dachengforce");
    map_skill("unarmed", "yiyangzhi");
    
    setup();
    carry_object(__DIR__"obj/monk_cloth")->wear();
} 
void attempt_apprentice(object me)
{
    command("shake");
    command("say ���������Ѹߣ��㻹��ȥ�ҷ��ɰɣ�\n");
}    
