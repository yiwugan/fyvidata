 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
int leave();
int wieldsword();
void create()
{
    set_name("������", ({ "master hu", "master"}) );
    set("nickname", HIY "��������"NOR);
    set("gender", "Ů��" );
    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 5);
    set("age", 34);
    set("per", 35);
    set("str", 25);
    set("ill_boss",5);
    set("int",30);
    set("attitude","friendly");
    set("max_force", 800);
    set("force", 800);
    
    set("long", "
�����Ͽ�������Ʈ�ݡ�����������������Ž�ߣ��������ý��������ĵ����\n���������һ˫���֣��޳���Բ��ʮָ������������ɡ�\n");
    create_family("������", 12, "����");
    set("rank_nogen",1);
    set("ranks",({"�ŷ�","���","�Ų�","������","ִ����","��ʦ","��ͷ",
                      "������ͷ","����ͷ",HIW"��ʹ"NOR,
                      RED"����"NOR,HIY"�󵱼�"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("chat_chance_combat", 99);
    set("chat_msg_combat", ({
        (: perform_action, "sword.meikaiwudu" :),
                (: wieldsword  :),
             }) );
    set("combat_exp", 3500000);
    set("inquiry",  ([
                "leave": (: leave :),
                ]) );
        set("chat_chance", 1);
    set("chat_msg", ({
                "�������ڿ�͵Ц��������������ϲ��ǣ�������Ȼ�ǳ�����������������\n",
            }) ); 
    set_skill("perception", 180);
    set_skill("move", 220);
    set_skill("parry",100);
    set_skill("dodge", 220);
    set_skill("force", 100);
    set_skill("literate", 140);
    set_skill("unarmed",100);
    set_skill("sword",120);

    set_skill("zhao-sword",120);
    set_skill("tenderzhi",120);
    set_skill("stormdance",320);
    set_skill("qiankunstrike",100);
    set_skill("wuchenforce",100);

    map_skill("dodge", "stormdance");
    map_skill("move", "stormdance");
    map_skill("force", "wuchenforce");
    map_skill("unarmed", "qiankunstrike");
    map_skill("sword","zhao-sword");
    map_skill("parry","zhao-sword");


   setup();
   carry_object(__DIR__"obj/thin_sword")->wield();
   carry_object("d/fugui/npc/obj/m_cloth2")->wear(); 
} 
void attempt_apprentice(object me)
{
    if((int)me->query("deposit")>=1000000)
    {
    	if (me->query("betrayer"))
    	    	{  command("shake");
    	           command("say Ǯ����ͨ�񣬵���һ�����ٰ�������");
    	           return;
                   }    	
        command("xixi");
        command("say ����Ҳ��ֻ�������Ҿ��չ��չ���ɣ�\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("heihei");
        command("say ���ǵ���ң�����ѧ�˵����񣿣�"); 
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
        message_vision(CYN"$N˵��������ϧ�ٻ���������չ÷������Ҳ���������ˣ�\n"NOR,this_object());
        return 1;
} 
int wieldsword()
{
command("unwield sword");
perform_action("unarmed.qiankun");
command("wield sword");
return 1;
}