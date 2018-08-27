 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void smart_fight();
int leave();
void create()
{
    set_name("�˹���ʦ", ({ "master xing", "master", "xing" }) ); 
    set("gender", "����");
    set("nickname", HIY "���ޱ�"NOR);
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 74);
    set("attitude", "peaceful");
    set("class", "bonze");
    set("apprentice_available", 3); 
    set("resistance/kee",30);
    set("resistance/sen",30);   
    set("resistance/gin",30);
    
    set("int", 30);
    set("spi", 30);
    set("con", 30);
    set("cps", 30);
    set("cor", 50);
    set("agi",25); 
    set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
    set("fly_target",1);
    set("atman", 1000);
    set("max_atman", 1000);
    set("force", 1200);
    set("max_force", 1200);
    set("force_factor", 90);
    set("mana", 2000);
    set("max_mana", 2000);
     
    set("combat_exp", 8000000); 
    set_temp("apply/armor", 280);
    set_temp("apply/damage", 200);
    set("score", 9000); 
    set_skill("staff", 200);
    set_skill("unarmed", 200);
    set_skill("force", 200);
    set_skill("dodge", 160);
    set_skill("literate", 150);
    set_skill("chanting", 220);
    set_skill("parry", 160);
    set_skill("magic", 280);
    set_skill("cloudstaff", 180);
    set_skill("lotusforce", 150);
    set_skill("buddhism", 280);
    set_skill("essencemagic", 280);
    set_skill("notracesnow",120);
    set_skill("dabei-strike",120);
    set_skill("move",180);
    set_skill("perception", 120);
    
    map_skill("staff", "cloudstaff");
    map_skill("parry", "cloudstaff");
    map_skill("force", "lotusforce");
    map_skill("magic", "essencemagic");
    map_skill("dodge","notracesnow");
    map_skill("unarmed","dabei-strike");
    map_skill("move","notracesnow");
    
    set("inquiry", ([
        "leave" : (: leave :),
                ]));
    create_family("�˹�����", 3, "ס��");
    set("rank_nogen",1);
    set("ranks",({"ɮ��","��ʦ","�޺�","���","��ɮ",YEL"��ɮ"NOR,YEL"ʥɮ"NOR,HIY"����"NOR})); 
    setup();
    carry_object(__DIR__"obj/buddha_staff")->wield();
    carry_object("/obj/armor/cloth")->wear(); 
} 
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say ������һ��һ������");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say ���ɽ����Ѿ��չ��˵��ӣ���������ͽ�ˡ�");
    }
} 
void do_recruit(object ob)
{
    if (ob->query("once_menpai/bonze") && ob->query("class")!="bonze") {
                command("shake");
                command("say ʩ�������޳���û�����֮�ġ�\n");
                return;
        }
    if(ob->query("marry")){
                message_vision("$Ņͷ���˿�$n����λʩ������δ����������ذɡ�\n", 
                                this_object(), ob);
                return;
        }
    if( (string)ob->query("gender") != "����" )
        command("say �����ӷ�Ůʩ����Ҫ�����ɿ���Ц��");
    else if(ob->query_temp("marks/ye")){
        ob->set("class","bonze");
        command("say ���ڰ��Ƴ����ķ��ϣ��Ҿ�����Ϊͽ�ɣ�");
        command("say �����ӷ����գ����գ�");
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/bonze",1);
    }
    else if(ob->query_temp("marks/lady")){
        ob->set("class","bonze");
        command("say �����㲻��������������Ϊ�ķ��ϣ��Ҿ�����Ϊͽ�ɣ�");
        command("say �����ӷ����գ����գ�");
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/bonze",1);
        }
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) ) {
        add("apprentice_availavble", -1);
        return 1;
    }
} 
int accept_fight(object me)
{
    if( (string)me->query("class")=="bonze" )
        command("say �����ӷ𣡳����˽��ǿ�񶷣����Ĳ���Υ����档");
    else
        command("say ʩ����Ȼ�����գ�����������ǣ�Ҳ���ؽ����ˡ�"); 
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
        if(id_class == "bonze"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ��������ӷ�,����������������ȴҲ���������꣬ʩ�����ˣ�\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="bonze") return 0;
        message_vision(CYN"$N���Ƶ��������ӷ𣬼�����Ե���α��������Ժ�Ҳ��Ҫ�ٻ����ˡ�\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵�����ŵ���ͨ�����ķ��ǵ��Ӳ���ʹ�á�\n"NOR,this_object(),this_player());
        return 1;
} 
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie2");
                return;
        }
        who->perform_action("staff.longxianyuye"); 
        return;
}        
