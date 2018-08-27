 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    set_name("�޻�", ({ "master wu", "master"}) );
    set("nickname", HIM "��ɮ"NOR);
    set("vendetta_mark","shaolin");
    set("gender", "����" );
    set("age", 29);
    set("per", 55);
    set("int",30);
    set("attitude","friendly");
    set("max_force", 1500);
    set("force", 1500);
    set("cps",60);
    set("long", " ���°��࣬һ����Ⱦ���������ϵ�΢ЦҲ�г���֮��\n");
    create_family("������", 16, "��ʦ");
    set("reward_npc", 1);
    set("difficulty", 10);   
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.qiankun" :)
            }) );
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"����һ��һ���Ϊ��ʦ��衣����\n",
            name()+"�������������ˣ������Ҿ�˵����Ψһ���ƻ�����ƻ��ľ����㡣\n"
            }) );
    set("combat_exp", 5000000);
    set("reward_npc", 1);
    set("difficulty", 10);   
    set_skill("move", 200);
    set_skill("dodge", 200);
    set_skill("force", 200);
    set_skill("literate", 200);
    set_skill("unarmed",200);
    set_skill("puti-steps",200);
    set_skill("yiyangzhi",200);
    set_skill("buddhism",250);
    set_skill("chanting",200);
    set_skill("xiaochengforce",200);
    set_skill("staff",200);
    set_skill("parry",200);
    map_skill("parry","fumostaff");
    map_skill("dodge", "puti-steps");
    map_skill("force", "dachengforce");
    map_skill("unarmed", "yiyangzhi");
    set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
          (: perform_action, "unarmed.qiankun" :)
            }) );
    setup();
    carry_object(__DIR__"obj/monk_cloth")->wear();
} 
void attempt_apprentice(object me)
{
    command("shake");
    command("say �ҳ����������⣬�㻹��ȥ�ҷ��ɰɡ�\n");
}
void init()
{
    if(this_player()->query_temp("��һ��ˮ"))
        call_out("confess",13+random(3),this_player());
        ::init();
} 
int confess(object me)
{
    me->delete_temp("��һ��ˮ");
    command("say ������ʲô��֪���ˡ�����\n");
    command("say ����������û�ҡ�����\n");
    message_vision("$N˵�գ��ԶϾ����������ĵ��ڵ��ϡ�����\n",this_object());
    if(!me->query("m_success/��ƽ���ַ粨"))
    {
        me->set("m_success/��ƽ���ַ粨",1);
        me->add("score",500);
    }
    this_object()->die();
}  
int accept_object(object who, object ob)
{
        string msg;
        
        if(ob->query("name")!="���ʳ���") return 0;
        if (who->query("���_quest2")=="�ɹ�")
        {
                msg=HIG"�޻��ٺ���Ц���������Ϲ���Ǽһﶼ������˭�����Һ���ĸ�׵İ�ҵ��
����������Ҳ��������\n"NOR;
                who->set("���_quest3","�ɹ�");
        }
        else
                msg=HIM"�޻�ü���������Цһ����������������Ϲ�һͬ�ϻ�Ȫ�ɡ���\n"NOR;
        message_vision(msg,who);
        kill_ob(who);
        return 0;
}       
