 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
int leave();
int tell_him();
int wieldblade();
void create()
{
    set_name("������", ({ "master yumen", "master"}) );
    set("nickname", HIW "���ѻ���"NOR);
    set("gender", "����" );
    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 45);
    set("per", 15);
    set("agi", 300);
    set("str", 50);
    set("int",30);
    set("ill_boss",5);
    set("attitude","friendly");
    set("max_force", 3000);
    set("force", 3000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
    
    set("long", "
һ���ߴ��ΰ�ĺ��ӣ�ȴ�ݹ�֧�룬�����ݵ�ֻʣ��Ƥ����ͷһ����
���ǵ��߲��ȣ���վ����վ���ȣ�������ȴ���ǳԸ���ͣ��\n");
    create_family("������", 7, "����");
    set("rank_nogen",1);
    set("ranks",({"�ŷ�","���","�Ų�","������","ִ����","��ʦ","��ͷ",
                      "������ͷ","����ͷ",HIW"��ʹ"NOR,
                      RED"����"NOR,HIY"�󵱼�"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: perform_action, "dodge.changmengwuchen" :),
                (: wieldblade  :),
        (: perform_action, "dagger.pingshuixiangfeng" :),
             }) );
    set("combat_exp", 5000000);
    set("chat_chance", 1);
    set("chat_msg", ({
                "����������������䣺��������Ұѽ������һ�����������ϲ���ǰ�ɳ������ˣ�����\n",
            }) ); 
    set("inquiry",  ([
                "leave": (: leave :),
                "wolf tooth" : (: tell_him :),
                "������" : (: tell_him:),
                ]) );

    set_skill("dagger", 150);
    set_skill("move", 160);
    set_skill("parry",120);
    set_skill("dodge", 120);
    set_skill("force", 180);
    set_skill("literate", 100);
    set_skill("unarmed",220);
  //  set_skill("blade",200);

  //  set_skill("xiruo-blade",180);
    set_skill("liumang-strike",220);
    set_skill("wuchen-steps",120);
    set_skill("yuping-dagger",200);
    set_skill("wuchenforce",200);

  //  map_skill("blade", "xiruo-blade");
    map_skill("dodge", "wuchen-steps");
    map_skill("move", "wuchen-steps");
    map_skill("force", "wuchenforce");
    map_skill("unarmed", "liumang-strike");
    map_skill("dagger","yuping-dagger");
    map_skill("parry","yuping-dagger");


   setup();
   carry_object(__DIR__"obj/dagger")->wield();
   carry_object("/d/fugui/npc/obj/m_cloth1")->wear(); 
} 
void attempt_apprentice(object me)
{
    if((int)me->query("deposit")>=5000000)
    {if (me->query("betrayer"))
    	    	{  command("shake");
    	           command("say Ǯ����ͨ�񣬵���һ�����ٰ�������");
    	           return;
                   }    
        command("haha");
        command("say �ú�������Ȼ��������ģ��Ҿ͸�������Т�����ӣ�\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("heihei");
        command("say ȥȥȥ�����Ҽҵ�����ȥС���ǣ����������ӣ�"); 
    }
} 
 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "quanli");
} 



void init()
{       
//	  object ob;
        ::init();
  /*              if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }*/
        add_action("do_killing", "kill");
} 


int leave() {
        if (this_player()->query("class")!="quanli") return 0;
        message_vision(CYN"$N����һ�����ò�м���������㡣\n"NOR, this_object());
        message_vision(CYN"$N˵��������ϧ�ٻ���������å��ȭ��Ҳ���������ˣ�\n"NOR,this_object());
        return 1;
} 
int wieldblade()
{
command("unwield dagger");
perform_action("unarmed.pofuchenzhou");
command("wield dagger");
return 1;
}

int tell_him()
{
    object me;
    me =this_player();
    tell_object(me,"�����ź������������֣�������˵�ϲ���ֻ��ʮһ���Ŵ������Ľ���������֪�����ڶ����ˡ���\n");
    return 1;
} 

int accept_object(object me, object obj)
{
        object book;
        if( (string) obj->query("name") == HIY"������"NOR)
        {
                obj = new(__DIR__"obj/xiruobook");
                message_vision(CYN"$N˵������л��л�������춿������ϲ���ǰ����һ���ˡ�ûʲ��ö������㣬�����ҿ�������������ɣ�\n"+"$N��"NOR + obj->name() + CYN"����$n���С�\n", 
                            this_object(),this_player() );

                        book = new(__DIR__"obj/xiruobook");
                        if(book) book->move(this_player());
                        
                        
                if(!me->query("m_success/������"))
                {
                        me->add("score",1000);
                        me->set("m_success/������",1);
                }
           return 1;       
        }
        else {return notify_fail("�����Ź�����Ц�������������ү�Ҷ����أ�\n");}
            
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