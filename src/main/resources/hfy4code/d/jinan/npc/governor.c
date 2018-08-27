 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int yuefei();
int leave();
void create()
{
    set_name("������", ({ "master yin", "master","yin" }) );
    set("long",
        "���ϳ�����ߵĹ٣����������ϵ�Ȩ��\n");
    set("nickname", RED"��ͼ���ѧʿ"NOR);
    set("class","official");
    set("attitude", "heroism");
    set("reward_npc", 1);
        set("difficulty", 35);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������������ϵ���͸��ҵ��з����������ˡ�����\n",
                "������ҡҡͷ�������������ˣ�û�������ѧ��������\n",
        }) );
    // Make this before create_family will prevent generation in title
    set("rank_nogen",1);
    create_family("��͢����",6,"̫��̫�� �ؼ��ϸ�");
    set("student_title","��Ա");
    set("ranks",({ "׼����","����","����","��ͳ��","ͳ��","��Ӫ��ͳ��",
                       "��Ӫͳ��","��Ӫ��ͳ��","���������ᶼָ��ʹ","�����������ᶼָ��ʹ",
                       "�����׾��������ݺ�","�����׾�������ݺ�",RED"��ǰ���ݺ�"NOR,
                       CYN"�����׾�������ָ��ʹ"NOR,YEL"�����׾������ָ��ʹ"NOR,BLU"��ǰ��ָ��ʹ"NOR,
                       CYN"�����׾�������ָ��ʹ"NOR,YEL"�����׾������ָ��ʹ"NOR,RED"��ǰ��ָ��ʹ"NOR }));
    set("rank_levels",({ 32000,64000,128000,256000,384000,
                             512000,800000,1024000,1556000,
                             2048000,3652000,5000000,
                             6258000,8848000,10800000,
                             14580000,20048000,26244000 })); 
        set("inquiry", ([
                "zonghengtianxia" : (: yuefei :),
                "�ݺ�����" : (: yuefei :),
           "yuefei" : (: yuefei :),
                "����" : (: yuefei :),
                "leave" : (: leave :),
        ]));
    set("vendetta_mark", "authority");
    set("str", 50+random(10));
    set("cor", 40);
    set("cps", 25);
    set("agi",25);
    set("int",30);
/*    set("max_kee",7000);
    set("max_gin",5000);
    set("max_sen",5000); */
    set("max_force",2000);
    set("force",2000);
    set("eff_force",2000);
        set("age",55);
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yuhuan" :),
            }) );
    set("combat_exp", 90000000);
    set_temp("apply/damage",500);
    set_skill("unarmed", 220);
    set_skill("force",180);
    set_skill("parry", 160);
    set_skill("dodge", 150);
    set_skill("changquan",220);
    set_skill("yue-spear",150);
    set_skill("manjianghong",150);
    set_skill("move", 180);
    set_skill("literate",140);
    set_skill("leadership",280);
    set_skill("strategy",280);
    set_skill("puti-steps",150);
    set_skill("spear",180);
    set_skill("perception", 200); 
    map_skill("unarmed","changquan");
    map_skill("dodge","puti-steps");
    map_skill("parry","yue-spear");
    map_skill("force","manjianghong");
    map_skill("spear","yue-spear"); 
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yuhuan" :),
        }) ); 
    setup();
    if(random(4)==2) set("env/no_teach",1);
    carry_object(__DIR__"obj/guanfu")->wear();
} 
int yuefei(){
        object me;
        me = this_player();
        if(me->query("marks/����������ƽǹ��")){
                message_vision("$N��$n˵��������Ȼ���Ѿ�ȥ���������ϣ�����ȥ��⿴���ҵ��ָ塣��\n", this_object(), me);
                return 1;
        }
        message_vision(CYN"\n$N����$n��̾��һ�������������µ���ĳ����������ݺ����£���Ҳ����ȫ������\n"NOR,
                        this_object(), this_player());
        message_vision(CYN"�м�İ��ء� ��˵������������������ƽ��֮�����㲻��ȥ��������\n"NOR, this_object());
        this_player()->set("marks/���������ݺ�����", 1);
        return 1;
}
void attempt_apprentice(object me)
{
    if( !me->query("class")||me->query("class")=="official")
    {
        if((int)me->query("combat_exp") > 400000 || me->query("m_success/ͷ­��")) {
        command("smile");
        command("say �ܺã���͢��������֮ʱ��Ŭ���ɣ�\n");
        command("recruit " + me->query("id") );
        } else command("say ��ʲô�����ᣬҲû��ʲô���飬��ô����͢Ч����\n");
    }
    else command("say ��͢����Ҫ�����ֲ������ģ���������֮�ˣ�\n");
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "official");
    ob->set("vendetta_mark", "authority"); 
}  
int accept_object(object who, object ob)
{
        if( ob->query("shangfang") ){
                this_object()->delete("env/no_teach");
        if(who->query_temp("marks/sword_gotit")) {
        //give reward
                command("nod");
                command("say ������ǰ�����һ����æ���Ǹ������и����ε��ˡ�\n");
                command("say ���ٰ��Ҳ����˭ɱ�˵��������䵱�ɵ������ţ�\n");
                if(!who->query("m_success/�з�����")) {
                        who->set("m_success/�з�����",1);
                        who->add("score",100);
                        tell_object(who,"�����ģ���õ�100�����ۣ�\n");
                }
        } else {
        //punish
                command("ah");
                command("say �󵨣�����͵�Ϸ�ı���\n");
                kill_ob(who);
                }
        return 1;
        }
        if (ob->query("name")=="ͷ­��" && ob->query("id")=="skull"
                && who->query("m_success/�з�����"))    {
                command("ack");
                command("consider");
                command("say �����䵱�������β��١�\n");
                command("say ʯ��Ǹ����Ҫ�⿪�����������ĵ������֡��ر����Ǹ��չ��ģ���ʱ�����Ų���ʱ�����������ŵġ�\n");
                if(!who->query("m_success/ͷ­��")) {
                        who->set("m_success/ͷ­��",1);
                        who->add("score",100);
                        who->add("potential",900);
                        who->add("combat_exp",5000);
                        tell_object(who,"�����ģ���õ�100�����ۣ�900��Ǳ�ܣ�5000�㾭�飡\n");
                }
                return 1;
        }
        return 0;
}  
void init()
{
        object ob;
        ::init();
        add_action("do_killing", "kill");
        if(interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, this_player());
        }
} 
void greeting(object ob) {
        if(!ob || environment(ob) != environment()) return;
        if (this_object()->query("env/no_teach")==1 && ob->query("family/master_id")=="master yin")
        message_vision("$N�����˵���������з��������Ϸ�����û��˼���㡣��\n",this_object());
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
        if(id_class == "official"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N�ȵ����󵨲��񣬾�Ȼ�����Ϸ���ǰ��Ұ���۳�͢����ô��\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        }
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="official") return 0;
        message_vision(CYN"$N��ɫ��������Ч��͢���Ҿ�����֮�£���ô�ܰ�;�����ء���\n"NOR, this_object());
        message_vision(CYN"$N˵����ִ��Ҫ����Ҳ����ǿ��ֻ�ǴӴ˾���һ��ƽ�񣬳�֮͢����Ҳ��Ȩ���ʡ�\n"NOR,this_object());
        message_vision(CYN"$N˵����ԧ��ȭҲ������ʹ����˼����˼��\n"NOR,this_object());
        return 1;
}   
