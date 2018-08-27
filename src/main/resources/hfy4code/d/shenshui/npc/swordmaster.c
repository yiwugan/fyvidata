 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("������", ({ "bai sankong" }) );
    set("nickname", HIY"��ƽ����"NOR);
    set("gender", "����" );
    set("class","shenshui");
    set("reward_npc", 1);
    set("difficulty", 5);
    set("age", 54);
    set("cor", 30);
    set("cps", 30);
    set("int", 30);
    set("per", 20);
    set("str",40);
    set("skill_public",1);
    set("attitude","peaceful");
    
    set("no_busy",10);
    
    set("atman",1000);
    set("max_atman",1000);
    set("max_force", 500);
    set("force", 500);
    set("force_factor", 100);
    set("fly_target",1);
    set("long", "��ƽɽׯׯ��\n");
    create_family("��ƽɽׯ", 1, "ׯ��");
    set("rank_nogen",1);
    set("ranks",({"��ͯ","����","��ʿ","����","����","����"}));
    set("rank_levels",({64000,256000,1536000,3456000,26244000}));
    
    set("resistance/kee",50);
    set("resistance/gin",50);
    set("resistance/sen",50);
        
    set("combat_exp", 3800000);
    set("score", 200000); 
    set_skill("move", 180);
    set_skill("parry", 150);
    set_skill("dodge", 150);
    set_skill("force", 200);
    set_skill("literate", 180);
    set_skill("sword",200);
    set_skill("unarmed",150);
    set_skill("bai-quan", 200);

    set_skill("qingpingsword",180);
    set_skill("qingpingforce",120);
    set_skill("chaos-steps",180);
    set_skill("perception",100); 

    map_skill("force", "qingpingforce");
    map_skill("parry","qingpingsword");
    map_skill("sword","qingpingsword");
    map_skill("dodge","chaos-steps");
    map_skill("move","chaos-steps"); 
    map_skill("unarmed","bai-quan"); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengzijue" :),
        }) ); 
    setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/sword")->wield();
    carry_object(__DIR__"obj/shuzhi")->wield();  
    set("chat_chance", 2);
    set("chat_msg", ({
        "������ҡͷ̾��������ƽɽׯ������ϣ��˶�˥����������\n",       
        "�����մ�������һ�ۣ���������ˮ���ӣ��ҵ�����ָ���㼸�С���\n"
            }) ); 
} 
void attempt_apprentice(object me)
{
    command("sigh");
    command("say ���������Ļ����䣬����ʲôͽ�ܡ���\n");
    command("say ��������ˮ���ӣ��ҵ�����ָ���㼸�У�Ҳ��������һ������\n");
        
} 
int recognize_apprentice(object ob)
{
        if(ob->query("class")=="shenshui" ) {
                if (ob->query("combat_exp")<1500000) {
                command("say ���㻹����������ʦ���Ĺ����������Ұɣ����ھ����ڶࡣ��\n");
                return 0;
                }
                return 1;
        }       
        return 0;
}   
void init()
{
    object me; 
    ::init();
    if( interactive(me = this_player()) && !is_fighting())
    if (me->query("combat_exp")>3200000 && me->query("class")=="shenshui" 
        && !me->query("marks/ʤ������") && !me->query_temp("marks/ask_bai")) {
        remove_call_out("greeting");
        add_action("do_accept", "accept");
        me->set_temp("bai_in_ask",1);
        call_out("greeting", 1, me);
    }
        add_action("do_killing", "kill");
} 
int greeting(object me)
{
    message_vision(HIY"\n$N����ؿ���$nһ��˵�����������ѧ��ҵ���гɣ���Ը�������һ����Ը����accept yes/no��\n" NOR, this_object(), me);
    return 1;
}  
int do_accept(string arg)
{
        string name;
        if (!this_player()->query_temp("bai_in_ask"))
                return notify_fail("ʲô��\n");
        if( arg != "yes" &&  arg != "no") 
                return notify_fail("��Ҫ����ʲô��\n");
        if( arg == "yes") {
                this_player()->set_temp("marks/bai_ask",1);
                message_vision(CYN "$N˵����ʮ��ǰ��ɣ��������ս���֣���������ɱ������ɡ�˫����ʿ�衢
���ɽ�����硢�����ڽ��ǣ�Ϊʦ�಻�Ƕ��֣��������º�������֡�������\n"NOR,this_object());
                message_vision(CYN"�������º����ţ��������־�����������������ԭ����������\n"NOR,this_object());
                message_vision(CYN"$N˵�����Ѿ�����ˮ�书���裬������ƽ�书֮�ĵã����ٸ���������һս��\n"NOR,this_object());
                message_vision(CYN"��ԭ������˥���ڴ�һ�ۣ���ʤ���ɰܣ�\n"NOR,this_object());
        }
        else 
                command("sigh");
        this_player()->delete_temp("bai_in_ask");
        return 1;
} 
int accept_object(object who, object ob)
{
        if(!who->query("marks/ʤ������")) return 0; 
        if( ob->query("id")!="katana" ) return 0;
                message_vision(CYN"$N��Ц�����ã��ã�̫���ˡ�\n"NOR,this_object());
                message_vision(CYN"$N˵:�Ϸ��⼸������˽���ƽ����ˮ�ڹ��ڻ�֮�����ʹ��ڸ���ɡ�\n"NOR,this_object());
                tell_object(who,HIW"������þ����ķ����˺͵�תǬ���ˣ�����\n"NOR);
                who->delete_temp("marks/bai_ask");
                who->set("marks/��������",1);
                message_vision(CYN"$N�ֵ�����ʵ��ˮ������ز�¶֮�����࣬�����ߣ������ջ�ġ�\n"NOR,this_object());
        return 1;
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
        if(id_class == "shenshui"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ����Ϸ������ˮ���Ŀ��ˣ����ݲ�������������Ұ��\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}
