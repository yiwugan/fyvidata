 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_challenge();
int leave();
void create()
{
    set_name("������", ({ "master xiao", "xiao","master" }) );
    set("gender", "����" );
    set("nickname",HIY "���¿�" NOR);
    set("reward_npc", 1);
    set("difficulty", 15);
    set("age", 45);
    set("int", 30);
    set("per", 30);
    set("attitude","friendly");
    set("class","yinshi");
    set("apprentice_available", 50);
    create_family("������", 1, "����");
    set("rank_nogen",1);
    set("ranks",({ "����","���","С�ܼ�","�ܼ�","��ܼ�",
                        CYN"����"NOR,CYN"��ʿ"NOR,HIC"����"NOR }));; 
    set("long",
        "�����������û���κ���֪��������\n"
        );
    set("force_factor", 40);
    set("max_force", 2200);
    set("force", 2200);
    set("combat_exp", 9999999);
    set("score", 90000);
    set_skill("unarmed", 200);
    set_skill("whip", 200);
    set_skill("force", 190);
    set_skill("parry", 150);
    set_skill("literate", 140);
    set_skill("dodge", 150);
    set_skill("move",150);
    set_skill("cursism",200);
    set_skill("celecurse",200);
    set_skill("flying-dragon", 180);
    set_skill("thunderwhip", 180);
    set_skill("iceheart", 150);
    set_skill("zuixian-steps", 140);
    set_skill("perception", 100);
    map_skill("cursism","celecurse");
    map_skill("unarmed", "flying-dragon");
    map_skill("whip", "thunderwhip");
    map_skill("force", "iceheart");
    map_skill("parry", "thunderwhip");
    map_skill("dodge", "zuixian-steps");
        set("inquiry",([
        "challenge" : (: ask_challenge :),
        "��ս": (: ask_challenge :),
                "tiaozhan": (: ask_challenge :),
                "���촸" : (: ask_challenge :),
                "master lan" : (: ask_challenge :),
                "leave" : (: leave :),
    ]) );
    set("agi",25);
    set("int",30);
    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
        (: perform_action, "whip.tianleiyiji" :),
        (: perform_action, "whip.yunlongjiuxian" :),
            }) );
    setup();
    carry_object(__DIR__"obj/shenxue")->wear();
    carry_object(__DIR__"obj/baojia")->wear();
    carry_object(__DIR__"obj/zhiai")->wear();
    carry_object(__DIR__"obj/sidai")->wield();
}
void reset()
{
    delete_temp("learned");
    set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say ������һ��һ������");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say �����������Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
    }
}
void do_recruit(object ob)
{
    if((int) ob->query_temp("wait_time") < 360)
    {
        command("think");
        command("say ���Ĳ��ϣ�����\n");
        ob->set_temp("xiao_failed",1);
        return;
    }
    else { 
        command("smile");
        command("say ���պ���д�ɣ�");
        command("smile");
        command("recruit " + ob->query("id") );
    }
}
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "yinshi");
    add("apprentice_availavble", -1);
} 
int ask_challenge()
{
        object me;
        me = this_player();
        if ((string) me->query("class") == "yinshi" && me->query("marks/challenge_xiao_forlan"))
        {       
                say(HIW"\n��������Ц��һ���������϶����������𣿡�\n"NOR);
                if (me->query("combat_exp")>1500000 && me->query("score")>10000)
                {
                        me->delete("marks/challenge_xiao_forlan");
                        message_vision(HIW"$N�����Ķ�$n˵��������ѧҵ�гɣ���ô����Ϊʦ��һ��ɡ����������������촸���̹ž�ʽ(challenge master lan).��\n"NOR,this_object(),me);
                   me->set("marks/challenge_lan",1);
                }else
                {
                        message_vision("$N��Ц���������϶��Ĵ�������һ����ֻ��ϧ����δ�������ܴ�Ϊʦ��ѵ����������\n ",this_object());
                }
                return 1;
        }
        return 0;
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
        if(id_class == "yinshi"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ�����ĳ��ͽ�ܣ��ݲ��ø������̣ܽ�\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
   if (this_player()->query("class")!="yinshi") return 0;
        message_vision(CYN"$N�������Ҳ���ǿ�����¡���\n"NOR, this_object());
        message_vision(CYN"$N˵��ֻ����ͨ�콵̫Ϊ�ն񣬲��������������\n"NOR,this_object());
        return 1;
}
