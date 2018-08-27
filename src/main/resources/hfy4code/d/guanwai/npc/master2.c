 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
int wieldstaff();
int leave();
void create()
{
    set_name("������", ({ "master yan", "master"}) );
    set("nickname", GRN "����"NOR);
    set("gender", "Ů��" );
    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 60);
    set("ill_boss",5);
    set("per", 25);
    set("str", 88);
    set("int",30);
    set("attitude","friendly");
    set("max_force", 8000);
    set("force", 8000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
    set("no_busy", 8);
    
    set("long", "
С�����걾������������ʵ�ģ���ϧ�����Ƕ���ǰ���¡�
�����������Ѿ������ֳ��˼����ܡ�ֻ������һ������Ȼ���˸һ��ɡ�\n");
    create_family("������", 6, "����");
    set("rank_nogen",1);
    set("ranks",({"�ŷ�","���","�Ų�","������","ִ����","��ʦ","��ͷ",
                      "������ͷ","����ͷ",HIW"��ʹ"NOR,
                      RED"����"NOR,HIY"�󵱼�"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: perform_action, "staff.yinshechudong" :),
        (: wieldstaff  :),    
             }) );
    set("combat_exp", 10000000);
    set("inquiry",  ([
                "leave": (: leave :),
                ]) );

    set_skill("spells", 160);
    set_skill("mapo", 180);
    set_skill("herb", 200);
    set_skill("move", 120);
    set_skill("parry",200);
    set_skill("dodge", 120);
    set_skill("force", 160);
    set_skill("literate", 150);
    set_skill("unarmed",160);
    set_skill("staff",200);

    set_skill("feiyuancurse",150);
    set_skill("xioushan-water",220);
    set_skill("yinshe-stick",160);
    set_skill("stormdance",200);
    set_skill("wuchenforce",140);

    map_skill("spells", "mapo");
    map_skill("herb", "feiyuancurse");
    map_skill("dodge", "stormdance");
    map_skill("move", "stormdance");
    map_skill("force", "wuchenforce");
    map_skill("unarmed", "xioushan-water");
    map_skill("staff","yinshe-stick");
    map_skill("parry","feiyuancurse");


   setup();
   carry_object(__DIR__"obj/junkstaff")->wield();
   carry_object("/d/fugui/npc/obj/w_skirt1")->wear(); 
   add_money("gold", 4);
} 
void attempt_apprentice(object me)
{
    if((int)me->query("deposit")>=50000000)
    {if (me->query("betrayer"))
    	    	{  command("shake");
    	           command("say Ǯ����ͨ�񣬵���һ�����ٰ�������");
    	           return;
                   }    
        command("giggle");
        command("say �ð������������ŵ�ʹ�����Ų��õ��أ�������ʦ����\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("heihei");
        command("say ��ͷ׬��������������̫�Űɡ�"); 
    }
} 
 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "quanli");
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
        if(id_class == "quanli"&& userp(victim)&& player != victim)
        {
            message_vision(HIW
"$N��Цһ����ı�ƺ��������Ҵ�ط��˰ɣ�\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 

int leave() {
        if (this_player()->query("class")!="quanli") return 0;
        message_vision(CYN"$N����һ�����ò�м���������㡣\n"NOR, this_object());
        message_vision(CYN"$N˵��������ϧ�ٻ������������ȷ���Ҳ���������ˣ�\n"NOR,this_object());
        return 1;
} 
int wieldstaff()
{
command("unwield staff");
perform_action("unarmed.shuimanjinshan");
command("wield staff");
return 1;
}
