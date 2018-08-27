 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void  smart_fight( object who); 
void create()
{
    set_name("����ħ", ({ "master yumo", "master"}) );
    set("nickname", HIW "��"NOR);
    set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 4);
    set("age", 64);
    set("per", 35);
    set("int",30);
    set("class","beggar");
    set("attitude","friendly");
    
    set("max_force", 1000);
    set("force", 1000);
    set("force_factor",30);
    
    set("pursuer", 1);
    set("resistance/kee",10);
    set("resistance/gin",10);
    set("resistance/sen",10);
    
    set("long", "�������µ�һ���İ�����ʦ�壬������������ȱ�ǰ�ϰ����δ����ؤ�\n");
    create_family("ؤ��", 6, "ʦ��");
    set("rank_nogen",1);
    set("ranks",({"�������","һ������","��������","��������","�Ĵ�����",
                      "�������","��������","�ߴ�����","�˴�����","�Ŵ�����",
                      "����","������"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("combat_exp", 2000000);
    set_skill("move", 120);
    set_skill("parry",120);
    set_skill("dodge", 120);
    set_skill("force", 120);
    set_skill("literate", 120);
    set_skill("unarmed",150);
    set_skill("doggiesteps",130);
    set_skill("dragonstrike",130);
    set_skill("huntunforce",120);
    set_skill("staff",150);
    set_skill("dagou-stick",160);
    set_skill("begging",120);
    set_skill("stealing",150);
    set_skill("betting",100);
    set_skill("perception",150); 
    map_skill("dodge", "doggiesteps");
    map_skill("force", "huntunforce");
    map_skill("unarmed", "dragonstrike");
    map_skill("staff","dagou-stick");
    map_skill("parry","dagou-stick");
    map_skill("move", "doggiesteps"); 
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: smart_fight(this_object()) :),  
        }) );   
    setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object(__DIR__"obj/staff")->wield();
} 
void attempt_apprentice(object me)
{
    if((int)me->query("score")<= -1)
    {
        command("say ����������ζ��Ͷ�ķ��ϣ��Ҿ�����Ϊͽ�ɣ�\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("grin");
        command("say ���Һ�����һ·����\n"); 
    }
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "beggar");
} 
void smart_fight(object who)
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1) {
                who->perform_action("staff.tianxiawugou");
                return;
        }       
        while(i--) {
                if(enemy[i] && living(enemy[i])&& random(100)>50 ) {
                        who->perform_action("staff.banzijue");
        }
        }
        return;
}  
int heal_up()
{
        if(environment() && !is_fighting() && !is_busy()
                && query("startroom") 
                && file_name(environment()) != query("startroom")) {
//              command("say ok");
                return_home(query("startroom"));
                return 1;
        }
        return ::heal_up() + 1;
}     
