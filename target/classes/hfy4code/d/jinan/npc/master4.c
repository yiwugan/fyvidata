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
    set_name("�Ϲ���", ({ "master nangong", "master"}) );
    set("nickname", HIR "����"NOR);
    set("gender", "����" );
    set("class","beggar");
    set("reward_npc", 1);
    set("difficulty", 5);
    set("age", 34);
    set("per", 35);
    set("int",30);
    set("attitude","friendly");
    set("max_force", 800);
    set("force", 800);
    
    set("long", "�������µ�һ���İ�����ǰ�ϰ����δȵİ�ͽ��\n");
    create_family("ؤ��", 7, "��ͷ����");
    set("rank_nogen",1);
    set("ranks",({"�������","һ������","��������","��������","�Ĵ�����",
                      "�������","��������","�ߴ�����","�˴�����",WHT"�Ŵ�����"NOR,
                      WHT"����"NOR,HIW"��ͷ���"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.xianglongwuhui" :),
             }) );
    set("combat_exp", 2000000);
    
    set_skill("perception", 100);
    set_skill("move", 120);
    set_skill("parry",120);
    set_skill("dodge", 120);
    set_skill("force", 180);
    set_skill("literate", 140);
    set_skill("unarmed",150);
    set_skill("doggiesteps",120);
    set_skill("dragonstrike",120);
    set_skill("huntunforce",150);
    set_skill("staff",150);
    set_skill("dagou-stick",120);
    set_skill("begging",220);
    set_skill("foreknowledge",120);
    map_skill("dodge", "doggiesteps");
    map_skill("force", "huntunforce");
    map_skill("unarmed", "dragonstrike");
    map_skill("staff","dagou-stick");
    map_skill("parry","dagou-stick");
    set("inquiry", ([
        "ıɱ" : (: kill_him :),
        "�δ�" : (: kill_him :),
        "leave" : (: leave :),
        ]));
    setup();
    carry_object(__DIR__"obj/9bagcloth")->wear(); 
} 
void attempt_apprentice(object me)
{
    if((int)me->query("deposit")<=0)
    {
        command("say ������һƶ��ϴ�ķ��ϣ��Ҿ�����Ϊͽ�ɣ�\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("sigh");
        command("say ��������������з磬����Ǯ���Ƶģ�ΪʲôҪ������ؤ�"); 
    }
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "beggar");
} 
int kill_him()
{
    object me;
    me = this_player();
    command("say �������Ѿ�֪����̫���ˣ��� \n");
    this_object()->kill_ob(me);
    me->kill_ob(this_object());
    return 1;
} 
int accept_object(object who, object ob)
{
        if(ob->query("name")!="���ʳ���") return 0;
        if(who->query("���_quest2")=="�ɹ�")
        {
        message_vision(HIC"�Ϲ����Ц�Ŷ�$N�������⵶���Ҵ�磡��\n"NOR,who);
                return 0;
        }
        if(who->query("���_quest1")!="�ɹ�")
        {
                message_vision(HIR"�Ϲ�����ɫһ�䣬˵������С�ӣ�ֻ�ù���֪����̫���ˡ�������\n"NOR,who);
                kill_ob(who);
                return 0;
        }
    message_vision(HIW "�Ϲ���һ��Ĩ�����ᣬ���������úúã����Ҹ����Ɑ���ͺʹ��һ��ȥ������
�˼ҽӻ�����\n"NOR,who);
        message_vision(WHT"�Ϲ��齫���ʳ�������$N��\n"NOR,who);
    tell_object(who,"�Ϲ�������˵�����ͷ�����֪ͨ����޻������������ֳ���Ϊɮ��\n");
        tell_room( environment(), "�Ϲ�����"+who->name()
                + "����С����˵��Щ����\n", ({ who, this_object() }) );
        who->set("���_quest2","�ɹ�");
        this_object()->set("chat_msg", ({
"�Ϲ����������Ÿ��Ʊ���������˼״��\n"
        }) );
        this_object()->set("chat_chance",2);
//      return 2;
}  
void init()
{       
        ::init();
        add_action("do_killing", "kill");
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "beggar"&& userp(victim)&& player != victim)
        {
            message_vision(HIW
"$N��Цһ�����л����䲻�ɲģ�ȴҲ�ֲ����������̰ܽɣ�\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="beggar") return 0;
        message_vision(CYN"$N̾�˿����������㵽����̰ͼ����ѽ����\n"NOR, this_object());
        message_vision(CYN"$N˵���򹷰����ͻ���ľ�����ʦү�������ģ������˾�ѧ�����ˡ�\n"NOR,this_object());
        return 1;
} 
