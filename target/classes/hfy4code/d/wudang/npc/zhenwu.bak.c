 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
    set_name(HIY "����۾�" NOR, ({ "master zhenwu", "master", "zhenwu" }) ); 
    set("gender", "����");
    set("age", 999);
    set("long", "����Ϊ����ǵۣ������䵱��Ϊ����������ʦ����ħ�����˵��̳��Ĵ���\n");
    set("attitude", "peaceful");
   set("reward_npc", 1);
        set("difficulty", 30);
    set("str", 6000);
    set("cor", 30);
    set("int", 24);
    set("cps", 30);
    set("force", 2000);
    set("max_force", 2000);
    set("force_factor", 1000);
    set("combat_exp", 20000000);
    set("score", 20000);
    set("class", "wudang");
    set_skill("unarmed", 160);
    set_skill("force", 200);
    set_skill("sword", 200);
    set_skill("taijiforce", 180);
    set_skill("literate",150);
    set_skill("incarnation",320);
    set_skill("dodge",160);
    set_skill("taiji",160);
    set_skill("taiji-sword",150);
    set_skill("parry",190);
    set_skill("changelaw", 200);
    set_skill("qixing",100);
    set_skill("five-steps",160);
    set_skill("spells",100);
    set_temp("apply/damage",30000);
    map_skill("spells","qixing");
    map_skill("dodge","five-steps");
    map_skill("move","five-steps");     
    map_skill("force", "taijiforce");
    map_skill("unarmed", "taiji");
    set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
             (: perform_action, "unarmed.nianzijue" :),
        }) );
    set("no_shown",1);
    set("rank_nogen",1);
    create_family("�䵱��", 1, "������ʦ"); 
    set("ranks",({"����",YEL"����"NOR,YEL"����"NOR,HIY"�۾�"NOR}));
    set("rank_levels",({320000,5187000,26244000}));
    setup();
}
int accept_fight(object me)
{
    return 0;
}
void attempt_apprentice(object me)
{
        if(me->query("class")=="wudang"&&me->query_skill("changelaw",1)>160&&me->query("marks/�䵱_ִ��")&&me->query("combat_exp")>=1000000)
                {
                me->set("once_menpai/wudang",1);
                command("recruit " + me->query("id") );
                }
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "wudang");
}
void init()
{
    add_action("do_look","look");
      add_action("do_killing", "kill");
} 
int do_look(string arg)
{
    if (arg == "master zhenwu" || arg == "zhenwu" || arg =="master")
    {
        write(HIY "����Ϊ����ǵۣ������䵱��Ϊ����������ʦ����ħ�����˵��̳��Ĵ��񡣡�\n" NOR);
        return 1;
    }
    return 0;
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
        if(id_class == "wudang"&& userp(victim)&&player!=victim)
        {
message_vision(HIW"$N����$n�ȵ���" + RANK_D->query_rude(player) 
                                                + "����ɱ" + RANK_D->query_self_rude(this_object()) 
                                                + "��ͽ�ܣ�ȥ���ɡ�\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}      
