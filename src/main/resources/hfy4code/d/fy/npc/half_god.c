 // half_god.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//  
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int give_reward(object who,mapping quest);
int time_period(int timep, object me);
int wait_period(int timep, object me);
string sysmsg;
void create() {
        set_name(HIY"�������"NOR, ({ "tianji", "Tian ji", "Tian" }) );
        set("gender", "����");
        set("age", 99);
        set("long", "�������������ף��׷�ͯ�ա��ڱ�������������һ��
�����Ϲ٣�С��֮�ϣ�����������а�����¶��ɰ�����������������ͽ�����ޣ�������\n");
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 26000);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({ "������������̳��˼��ڣ�������\n" }));
        set("force", 40000);
        set("max_gin", 8000);
        set("max_sen", 8000);
        set("max_force", 80000);
        set("force_factor", 1000);
    set("combat_exp", 100000000);
        set("score", 200000);
        set_skill("unarmed", 120);
        set_skill("force", 100);
        set_skill("iron-cloth", 100);
        set_skill("yiqiforce", 30);
        set_skill("dagger",200);
        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);
   map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce"); 
        create_family("��ң��", 1, "��ʦ");
        set("title", "����Ұ��");
        setup(); 
        carry_object(__DIR__"obj/jade-cloth")->wear();
        carry_object(__DIR__"obj/hanyan")->wield();
} 
int accept_fight(object me) {
                command("say �����ɹ󣡲�Ҫ��Ѱ��·��");
                return 0;
} 
void init() {
                
                 object ob;
        ::init();
        add_action("give_quest", "quest");
//        add_action("do_killing", "kill");
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
} 
int accept_object(object who, object ob) {
        return QUESTS_D->accept_quest_object(who, ob, this_object());
} 
int give_quest(string arg) {
        int gold = this_player()->query("deposit")/10000; 
        if (arg == "cancel" && this_player()->query("quest")) {
                if (gold <5 ) return notify_fail("������������������ӡ�\n");
                this_player()->add("deposit", -50000);
                tell_object(this_player(), HIY"����ȡ���ˡ�\n�����������ϻ���"+chinese_number(gold)+"���ƽ�\n"NOR);
                this_player()->delete("quest");
                return 1;
        }
                
        return QUESTS_D->give_quest(this_player(), 
                        ([      "name" : this_object()->name(),
                                "employer" : "�������" ])
                        );      
} 
void attempt_apprentice(object me) {
        switch(random(4)) {
                case 0:
                        message_vision("$N��$nЦ�ʵ���ʲô���Ľ���\n", this_object(),me);
                        break;
                case 1:
                   message_vision("$N��$nЦ�ʵ���ʲô�ǣ��в������Ҳ�������һ�������ȶ�����\n", this_object(),me); 
                        break;
                case 2:
                        message_vision("$N��$nЦ�ʵ��������Σ����Σ���ʲô��\n", this_object(),me);             
                        break;
                case 3:
                        message_vision("$N��$nЦ�ʵ�����ѧ����߾�����ʲô��\n", this_object(),me);
                        break;
        }
} 
void recruit_apprentice(object ob) {
        if(::recruit_apprentice(ob)) {
                ob->set("class", "xianren");
        }
}
int attack()
{
        object opponent;
        opponent = select_opponent();
        if (userp(opponent)) {
                if (random(10)) {
                        set_temp("last_opponent", opponent);
                        command("say �����ɹ󣬲�Ҫ��Ѱ��·��");
                        this_object()->remove_all_killer();
                        return 1;
                } else {
                        command("say ��֪����Ķ�����ȥ���ɡ�");
                        COMBAT_D->do_attack(this_object(), opponent, query_temp("weapon"));
                        return 1;
                }
        } else if(objectp(opponent)) {
                COMBAT_D->fight(this_object(), opponent);
                return 1;
        } else
                return 0;
        
} 
void unconcious()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ; 
} 
void die()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ; 
}   

void punish_betray(object ob)
{
        if( ( ob->query("once_xman")==1) && ( (ob->query("class"))!= "shaolin"))
          {      
                tell_object(ob, YEL"\n������˳�̾:��������֮ͽ������\n"NOR);                  
                message("vision", YEL"������˶�"+ ob->name() +"̾������"+ ob->name() + "�� ��ʦ���Ҵ��������Ż������㲻���ˣ�\n"NOR, environment(ob), ob);
                tell_object(ob, HIW"�������һȭ�������������ϣ�\n"NOR);              
                message("vision", HIW"�������һȭ����"+ ob->name() +"��������ϣ�\n"NOR, environment(ob), ob);
                tell_object(ob, HIR"��ֻ�����ε�ת,ҡҡ�λεص�����ȥ----�ڲ�����ѽ!\n"NOR);
                ob->set("title",HIC"������ͽ"NOR);
                ob->die();
          }
}  