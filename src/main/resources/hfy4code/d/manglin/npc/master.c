 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("��ڤͨ��", ({ "master peiming", "master", "peiming" }) );
    set("nickname", HIG"�嶾ͯ��"NOR);
    set("gender", "����" );
    set("age", 44);
    set("str", 30);
    set("cor", 30);
    set("cps", 30);
    set("int", 30);
    set("per", 30);
    set("attitude","aggresive");
    set("max_force", 15000);
    set("force", 15000);
    set("force_factor", 3);
    set("long", "��ڤͨ��ѧ������Ȼ�����֮��Ϊʦ��һ����ɱ�������Σ�"
        "������ͨ�콵����\n");
    set("rank_nogen",1);
    create_family("ͨ����", 1, "����");
    set("ranks",({"����","������","����","��̳��","̳��",
                      "������","����","����","�󻤷�",
                      "����","����","������"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("combat_exp", 10000000);
    set("score", 200000);
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :)
            }) ); 
    set_skill("move", 70);
    set_skill("parry", 80);
    set_skill("dodge", 80);
    set_skill("force", 80);
    set_skill("literate", 60);
    set_skill("cursism",200);
    set_skill("celecurse",70);
    map_skill("force", "celecurse");
    map_skill("cursism","celecurse");  
    setup();
    carry_object(__DIR__"obj/ducloth")->wear();
} 
void attempt_apprentice(object me)
{
    if( !me->query("class")){
        command("smile");
        command("recruit " + me->query("id") );
    }
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "diabloist");
}   
