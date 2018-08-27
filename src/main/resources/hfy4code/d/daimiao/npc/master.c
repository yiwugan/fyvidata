 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
int leave();
void create()
{
    set_name("�����", ({ "master yu", "master"}) );
    set("nickname", HIR "��ʤ��ħ"NOR);
    set("gender", "����" );
    set("age", 64);
    set("per", 3);
    set("agi",25);
    set("class","bandit");
    set("int",30);
    set("attitude","friendly");
    set("max_force", 1500);
    set("force", 1500);
    set("force_factor", 30);
    set("long",
        "���������������еĽ���������׵�����˭Ҳ�������Ҳû�˸��ʡ�
�����ʹ���֪��������������˶��������׵���ʧ�ˡ�\n");
    create_family("�������", 1, "����");
    set("rank_nogen",1);
    set("ranks",({"��ͽ","����","̽��",RED"ɱ��"NOR,HIB"ʹ��"NOR,
                      HIG"��������"NOR,HIW"��üӥ��"NOR,HIY"��ëʨ��"NOR,MAG"��������"NOR,
                      HIC"����"NOR,YEL"����"NOR,"������"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({

            (: perform_action, "dodge.lianhuanbabu" :),
            (: perform_action, "blade.kuaidao" :)
            }) );
    set("combat_exp", 8000000);
    set("score", 200000); 
    set_skill("move", 100);
    set_skill("parry",180);
    set_skill("dodge", 100);
    set_skill("force", 200);
    set_skill("literate", 120);
    set_skill("unarmed",100);
    set_skill("perception",160);
    set_skill("demon-steps",160);
    set_skill("demon-strike",160);
    set_skill("demon-force",200);
    set_skill("moon-blade",160);
    set_skill("blade",220);
    set_skill("demon-blade",200);

    map_skill("dodge", "demon-steps");
    map_skill("force", "demon-force");
    map_skill("unarmed", "demon-strike");
    map_skill("blade","moon-blade");
    map_skill("parry","demon-blade");
    set("inquiry", ([
        "������" : (: kill_him :),
        "������" : (: kill_him :),
        ]));
       set("inquiry",  ([
                "leave": (: leave :),
                ]) );
  
    setup();
    carry_object(__DIR__"obj/wufu")->wear();
    carry_object(__DIR__"obj/lou")->wield(); 
} 
     
int leave() {
        if (this_player()->query("class")!="bandit") return 0;
        message_vision(CYN"$N�·���ȫû������������⣬����������ͷ��\n"NOR, this_object());
        message_vision(CYN"$N����������˵��һ�����ţ�Բ�²��١���һ�����ţ�Բ�²��٣�\n"NOR,this_object());
        return 1;
} 
void attempt_apprentice(object me)
{
	    if (me->query("once_menpai/bandit")&& me->query("class")!="bandit") {
                command("puke");
                command("say �޳���ͽ������");
                return;
                } 
      if (me->query("betrayer")) {
                command("heng");
                command("say ��·����������");
                return;
                } 

    if(me->query_temp("for_bandit")&& me->query("combat_exp")<1000000)
    {
        command("say �ã��ã��Ϸ������ҵ�������֮�ġ�\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("sigh");
        command("say ������̲�����⣬������ɲ�Ʊ��������߸��������̣�
�����Ϸ򱦵��ĺ��ǵ���Ҳ���ˡ�\n");
        command("say ����������������£��Ϸ������Ϊͽ��\n");
    }
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "bandit");
}
int kill_him()
{
    object me;
    me = this_player();
    command("say �������Ѿ�֪���ҵ������ˣ��� \n");
    this_object()->kill_ob(me);
    me->kill_ob(this_object());
    return 1;
}
int accept_object(object me, object obj)
{
    if(obj->query("for_bandit"))
    {
        command("? "+me->query("id"));
        command("say �㣮����ɱ�˱��̵��ˣ�͵�˱��̵Ķ�������������Ū�Ϸ�\n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
    }
    if(obj->query("for_bandit2"))
    {
        me->set_temp("for_bandit",1);
        command("smile");
        command("say �ã��ܺã����������Ϸ���ˣ����Ϸ�Ϊʦ��\n");
        return 1;       
    }
    return 0;
}