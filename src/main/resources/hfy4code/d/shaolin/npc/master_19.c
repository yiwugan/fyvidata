 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    set_name("��ƥ", ({ "master di", "master"}) );
    set("nickname", HIY "��Ե" NOR);
    set("vendetta_mark","shaolin");
    set("gender", "����" );
    set("reward_npc", 1);
        set("difficulty", 3);
    set("age", 64);
    set("agi",30);
    set("per", 35);
    set("int",30);
    set("cps",80);
//  set("str",20+random(20));
    set("attitude","friendly");
    set("max_force", 1000);
    set("force", 1000);
    set("long", "���ֵ�ʮ�Ŵ����ϣ�ר�Ŵ��������޺��书��\n");
    create_family("������", 19, "����");
    set("student_title","�޺�");
    set("combat_exp", 1100000);
    set_skill("move", 120);
    set_skill("dodge", 120);
    set_skill("force", 120);
    set_skill("literate", 140);
    set_skill("unarmed",120);
    set_skill("puti-steps",120);
    set_skill("dabei-strike",120);
    set_skill("zen",140);
    set_skill("chanting",120);
    set_skill("xiaochengforce",120);
    set_skill("staff",120);
    set_skill("parry",120);
    set_skill("fumostaff",120);
    set_skill("blade",120);
    set_skill("sword",120);
    set_skill("suiyuan-sword",120);
    set_skill("lianxin-blade",120);
//  set_skill("xingyi-stick",120);
    set_skill("liuxing-hammer",120);
    set_skill("hammer",120);
    map_skill("hammer","liuxing-hammer");
    map_skill("sword","suiyuan-sword");
    map_skill("staff","xingyi-stick");
    map_skill("parry","lianxin-blade");
    map_skill("dodge", "puti-steps");
    map_skill("force", "xiaochengforce");
    map_skill("unarmed", "dabei-strike");
    map_skill("blade","lianxin-blade");
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: perform_action, "staff.hequhecong" :),
        (: perform_action, "unarmed.qianshouqianbian" :)
            }) );
    
    setup();
    carry_object(__DIR__"obj/monk21_cloth")->wear(); 
} 
void attempt_apprentice(object me)
{
    if(me->query("gender") != "����")
    {
        command("say �����޺�ֻ�������е��ӡ�����\n");
        return;
    }
    if(me->query_temp("won_master_meng"))
    {
        me->set("once_menpai/shaolin",1);
        command("smile");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("shake");
    }
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
} 
int accept_fight(object me)
{
    if((me->query("family/family_name") == query("family/family_name") &&
        me->query("family/master_id") == query("id")) || me->query_temp("won_master_meng"))
    {
        if (me->query("combat_exp")<400000) {
                command("say ͽ����ѧ�䲻�ܺø���Զ����\n");    
                return 0;
                }
        
        
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
    winner->set_temp("won_master_di",1);
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
