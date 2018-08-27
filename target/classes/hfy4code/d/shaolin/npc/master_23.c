 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int got_me();
int leave();
void create()
{
    set_name("����", ({ "master kong", "master"}) );
    set("nickname", HIG "��Ϊ" NOR);
    set("vendetta_mark","shaolin");
    set("gender", "����" );
    set("reward_npc", 1);
        set("difficulty", 1);
    set("age", 64);
    set("agi",30);
    set("per", 35);
    set("int",30);
    set("cps",80);
    set("attitude","friendly");
    set("max_force", 500);
    set("force", 500);
    set("long","���ֵڶ�ʮ������ʦ������ר�Ŵ��������׼ҵ����书��\n"
        );
    set("inquiry", ([
        "����ǰ" : (: got_me :),
        "chujiaqian" :  (: got_me :),
        "leave" : (: leave :),
                       
        ]) );
    create_family("������", 23, "����");
    set("student_title","�׼ҵ���");
        
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.qianshouqianbian" :)
            }) );
    set("combat_exp", 100000);
    set_skill("move", 80);
    set_skill("dodge", 80);
    set_skill("force", 80);
    set_skill("literate", 100);
    set_skill("unarmed",80);
    set_skill("puti-steps",80);
    set_skill("dabei-strike",80);
    set_skill("blade", 80);
    set_skill("lianxin-blade",80);
    set_skill("zen",80);
    set_skill("chanting",80);
    set_skill("xiaochengforce",80);
    map_skill("blade","lianxin-blade");
    map_skill("dodge", "puti-steps");
    map_skill("force", "dachengforce");
    map_skill("unarmed", "dabei-strike");
    setup();
    carry_object(__DIR__"obj/monk22_cloth")->wear();
}  
void attempt_apprentice(object me)
{
    if(me->query("gender") != "����")
    {
        command("say ���գ����գ���λŮʩ����ذɣ�����ֻ���е��ӡ�����\n");
        return;
        }
        if(me->query("marry")){
                message_vision("$Ņͷ���˿�$n����λʩ������δ����������ذɡ�\n", 
                                this_object(), me);
                return;
        }
        else  {
    if(((int)me->query_skill("dabei-strike",1)>=15 && 
        (int)me->query_skill("xiaochengforce",1)>=10 &&
        (int)me->query_skill("puti-steps",1)>=15) /*|| me->query_temp("marks/go_head_to_app_mas_kong")*/)
    {
        if (me->query("once_menpai/shaolin")) {
                command("shake");
                command("say ʩ�������뿪���֣��ο��ٻ����أ�\n");
                return;
   }
        me->set("once_menpai/shaolin",1);
        command("smile");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("smile");
        command("say ��ʦҪ�г��⣬����ȥѧѧ���İɣ�\n");
        return;
                } 
    }
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
} 
int accept_fight(object me)
{
        if(me->query("class") == "shaolin")
        {
        command("say �ã���Ӯ���ң���Ϳ���ȥ�������и������ʦ���ˣ�\n");
        return 1;
        }
        else
        {
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say �����ӷ�ͽ����ҪŬ��ѽ��\n");
}
void lose_enemy(object winner)
{
command("say �����ӷ������ȥ�ұ��ʦ��ȥ�����ˡ�\n");
winner->set_temp("won_master_kong",1);
} 
int got_me()
{
command("sigh");
command("say ����ǰ���²���Ҳ�գ�\n");
return 1;
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
        if(id_class == "shaolin"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ��������ӷ�,�����徲֮��,�������ɱ��?ʩ����ˡ���ĵ����ˣ�\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="shaolin") return 0;
        message_vision(CYN"$N���Ƶ��������ӷ𣬼�����Ե���α�����,�Ժ�Ҳ��Ҫ�ٻ����ˡ�\n"NOR, this_object(),this_player());
   return 1;
}        
