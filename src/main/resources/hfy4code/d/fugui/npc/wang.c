 inherit NPC;
inherit F_MASTER;
#include <ansi.h> 
void smart_fight();
void smart_busy();
void smart_attack(); 
int leave();
void create()
{
        set_name("����", ({ "master wang", "master", "wang" }) );
        set("nickname", HIR"һ�ɳ��� ӥ����"NOR);
        set("gender", "����" );
        set("apprentice_available", 10);
        set("class","fugui");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("age", 36);
        set("int", 40);
        set("spi", 25);
        set("cor", 20);
        set("per", 40);
        set("attitude","heroism");
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor",40); 
        set("long",
"�����ñ������ѿ���ֻ�����Ե���Ƽ��ݣ���˵������������������\n�ӣ������Ѷ��˺ü��졣ֱͦͦ���ڴ���,����û��˯�ţ��۾�����\n���úܴ�\n"
        );
        set("chat_chance", 2);
        set("chat_msg", ({
                "�������������·����ţ�����ܵ�����ȥ�ˣ�\n",
        }) );
        set("inquiry",  ([
                "����·" : "��...��ͷ��ţ.....\n",
                "������" : "��....\n",
                "leave": (: leave :),
                ])                      ); 
        create_family("����ɽׯ", 7, "ׯ��");
        set("combat_exp", 4000000);
        set("rank_nogen",1);
   
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
                set_skill("perception",200);
        set_skill("move", 220);
        set_skill("henglian", 200);
        set_skill("parry", 180);
        set_skill("dodge", 250);
        set_skill("force", 200);
        set_skill("unarmed", 160);
        set_skill("skyforce",160);
        set_skill("literate", 150);
        set_skill("iron-cloth", 180);
        set_skill("spear", 200);
        set_skill("xuezhan-spear",180);
        set_skill("hawk-steps",220);
        set_skill("eagle-claw",280);
        
        map_skill("force", "skyforce");
        map_skill("parry","xuezhan-spear");
        map_skill("iron-cloth","henglian");
        map_skill("spear","xuezhan-spear");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps"); 
        map_skill("unarmed","eagle-claw");      
        
        set_temp("apply/iron-cloth",110);
        
        set("ranks",({ "����","���","С�ܼ�","�ܼ�","��ܼ�",
                        CYN"�ܹ�"NOR,CYN"���ܹ�"NOR,HIC"��ׯ��"NOR }));
        setup();
        carry_object(__DIR__"obj/oldcloth")->wear();
        carry_object(__DIR__"obj/spear");
} 
void reset()
{
                set("apprentice_available", 5);
} 
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else 
        {
                command("say ���������ɽׯ��úܣ��Ѿ��չ��˵��ӣ����������ˡ�");
        }
} 
void do_recruit(object me)
{
        if( (string)me->query("gender") != "����" )
          {
                command("say ��ֻ���е��ӣ��㻹����ı�߾Ͱɣ�");
                return 0;
          }
        if(!me->query_temp("marks/���ƿ") && !me->query_temp("marks/������"))
          {
                switch ( random(2) )
                  {
                        case 0:
                                command("sigh\n");
                                command("say ����Ҵ��ѵ�ͷ���⵹Ҳ���ˣ���ȴ�������������ֵܣ�\n�����涾���������ڻ���֮�У��������ϣ�����������С�ֵ��㰡��\n");
                                break;
                        case 1:
                                command("say ��·�����ˣ����ǵ�֪���˴�·����Ϣ��̸���°�.\n");
                                break;
                  }
          }
        else 
          {
                if (me->query("combat_exp")<300000) {
                    command ("say �㼼�ղ�����ǿ���������İԵ������к����棬�������ñ��������Ҹ���ɽׯ�ɡ�\n");
                        return 0;
                }
                   command("say �������ȴ��ͷ���£��Ҿ�����Ϊͽ�ɣ�\n");
                me->set("class","fugui");
                command("recruit " + me->query("id") );
          }
}
                
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "fugui");
                ob->add("betrayer",-1);
                ob->add("score",-5000);
        if(ob->query("betrayer") < 0) ob->set("betrayer",0);
        add("apprentice_availavble", -1);
} 
void killed_enemy(object who)
{
        command("say �α���Ѱ��·�أ�\n");
} 
int accept_fight(object me)
{
        command("say ���ܣ����ŵ��������Ҵ�ɨһ��Ժ�Ӱɣ�");
        command("sleep");
        return 0;
} 
void init()
{
        ::init();
        add_action("do_killing", "kill");
} 
int do_killing(string arg)
{       
        object player, victim, weapon;
        string name;
        if(!arg) return 0;
        player = this_player();
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = victim->name();
                if( name == "����")
                {
                        if (weapon = present("silver spear", this_object())) {
                                message_vision("$N����üͷ��\n", this_object());
                           message_vision("$N��֪����������һֻ����ǹ��\n", this_object());
                                weapon->wield();
                                call_out("do_unwie", 3);
                                }
                        return 0;
                }
                return 0;
        }
        return 0;               
} 
int do_unwie()
{
        if( !this_object()->is_fighting())
        {
                command("unwield spear");
                message_vision("$N�����ۡ������Ƿ�������ɵ��ڴ��ϡ�������\n", this_object());
                return 1;
        }
        else
                call_out("do_unwie", 3);
} 
int accept_object(object me, object ob)
{
        if(ob->query("name") == HIY"������"NOR)
        {
                command("touch " + me->query("id"));
                command("say ����֪����·����Ϣ�ˣ�\n");
                command("say ��λ" + RANK_D->query_respect(me)+ "���������л��ֻҪ��Ը�⣬�Ժ�������Ҹ���ɽׯ������.\n");
                me->set_temp("marks/������",1);
                return 1;
        }
        else
                tell_object(me,"����˵�����ⲻ������Ҫ�ġ�\n");
                return 0;      
} 
int leave() {
        if (this_player()->query("class")!="fugui") return 0;
        message_vision(CYN"$NЦЦ�������̫�����ס���ˡ���\n"NOR, this_object());
        message_vision(CYN"$N˵���˸���־���Ҳ���ǿ��ֻ���ҵĺ����ľ�����û��������ˡ�\n"NOR,this_object());
        return 1;
} 
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                        {
                                this_object()->smart_attack();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.yingjichangkong");
}
smart_attack() {
        this_object()->perform_action("spear.bafangfengyu");    
        }      
