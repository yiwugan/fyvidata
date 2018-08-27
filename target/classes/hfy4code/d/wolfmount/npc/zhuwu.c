 inherit NPC;
inherit F_MASTER;
#include <ansi.h> 
void create()
{
        set_name("����̫ү", ({ "master zhuwu", "master", "zhuwu" }) );
        set("gender", "����" );
        set("age", 75);
        set("agi", 35);
        set("int", 40);
        set("spi", 25);
        set("cor", 20);
        set("con", 20);
        set("per", 40);
        set("str", 100);
        set("no_busy",99);
        set("class","wolfmount");
        set("attitude","heroism");
        set("apprentice_available", 5);
        set("long",
                "��ȫ���ѱ��佩Ӳ�����ϵļ���Ҳ����ή����Ť����һ�ű�����ׯ\n�ϵ������ѱ��˵������а��ɲ���\n"
                );
        create_family("��ɽ", 3, "ɽ��");
        set("rank_nogen",1); 
        set("ranks",({ "С���","�����","СͷĿ","��ͷĿ","��ͷ��",RED"���"NOR,HIR"��˧"NOR,HIY"����"NOR }));
        set("force_factor",400);
        set_temp("apply/damage",300);
        set("max_force", 10000);
        set("force", 10000);
        set("max_sen", 29740);
        set("attitude", "peaceful");
        
        set_skill("hammer", 200);
        set_skill("assasin-hammer", 280);
        set_skill("animal-training", 250);
        set_skill("cursism", 200);
        set_skill("force", 180);
        set_skill("move", 150);
        set_skill("wolf-force",190);
        set_skill("wolf-curse",120);
        set_skill("parry", 200);
        set_skill("dodge", 120);
        set_skill("xueyeqianzong", 120);
   set_skill("literate", 120);
        set_skill("unarmed", 200);
        set_skill("wolf-claw", 160);
        set_skill("dagger",200);
        set_skill("summonwolf", 250);
        set_skill("xinyue-dagger",150);
        set_skill("perception", 200);
        map_skill("dodge","xueyeqianzong");
        map_skill("dagger","xinyue-dagger");
        map_skill("unarmed","wolf-claw");
        map_skill("parry","assasin-hammer");
        map_skill("hammer","assasin-hammer");
        map_skill("force","wolf-force");
        map_skill("cursism","wolf-curse");
        set("combat_exp", 20000000);
                set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.ningxie" :),
                
        }) );

        setup();
        carry_object(__DIR__"obj/graycloth")->wear();
        carry_object(__DIR__"obj/juque");
        carry_object(__DIR__"obj/rockhammer");
} 
int is_ghost()
{ 
        return 1; 
} 
void init(){    
        
        ::init();
        add_action("do_kill","kill");
        if(this_player()->query("title") == "��ɽ "+HIR"��ȴ���"NOR){
                call_out("chiyou", 1, this_player());
        }
} 
void chiyou(object me){
        object ob;
        if(!interactive(me) || environment(me) != environment(this_object())){
                return;
        }
        message_vision(HIR"$N��Хһ�������ⲻ��аħ�Ĵ��ˣ���������\n"NOR, this_object());
        this_object()->kill_ob(me);
        if(ob=present("wanyan tie", environment(this_object()))){
           ob->kill_ob(me);
        } else if(ob=present("wanyan gang", environment(this_object()))){
                ob->kill_ob(me);
        }
        return;
} 
int do_kill(string arg)
{
        object me,ob;
        object player, victim;
        string id,id_class;
        me = this_player();
        if(arg == "master zhuwu" || arg == "master" )
        {
                if ( ob=present("wanyan tie",environment(this_object())) )
                {
                        message_vision("$N��$n���һ�������㲻���������������֣������������㣡\n",ob,me);
                        ob->kill_ob(me);
                        return 1;
                }
                else if ( ob=present("wanyan gang",environment(this_object())) )
                {
                        message_vision("$N��$n���һ�������㲻���������������֣������������㣡\n",ob,me);
                        ob->kill_ob(me);
                        return 1;
                }
                else 
                {
                        return 0;
                }
        }
        player = this_player();
        if(!arg || arg == "") return 0;
        victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
        if(living(victim))
        {
                id_class=victim->query("class");
                id=victim->query("id");
                   if(id_class == "wolfmount"&& userp(victim)&&player!=victim)
                {
                        message_vision(HIW"$N��$n�ȵ�����ɽ�ӵ�,ͬ����֦,�����������꣡\n"NOR, this_object(),player);
                        this_object()->kill_ob(player);
                        player->kill_ob(this_object());
                        if (!player->is_busy()) player->start_busy(2);
                        return 0;
                } 
        }
        return 0;
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
                command("say ��ɽ���ӣ��󾫲���࣬���������ˡ�");
        }
} 
void do_recruit(object me){
        if(me->query("title") == "��ɽ "+HIR"��ȴ���"NOR){
                return;
        }
        if( (string)me->query("class") != "wolfmount" )
        {
            command("say ��ֻ����ɽ�ӵܣ��㻹����ı�߾Ͱɣ�\n");
        }
        else if(!me->query("m_success/��ɽ���"))
        {
                switch ( random(2) )
           {
                        case 0:
                                command("say ��ɽ����������֮�֣���������㣿\n");
                                me->set_temp("marks/������̫ү",1);
                                break;
                        case 1:
                                me->set_temp("marks/������̫ү",1);
                                command("say ��ԩ�겻�𣬾��ǵ�������Ϊ�ұ��˳��ٴ���һ���书��\n");
                                break;
                }
        } else  {
                if (me->query("combat_exp")<1200000) {
                        command("say �ã��ã������ӣ����������������ҡ�\n");
                        return;
                }
                command("say ����ұ��˴���Ҿ�����Ϊͽ�ɣ�\n");
                command("recruit " + me->query("id") );
        }
}
                
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wolfmount");
        add("apprentice_availavble", -1);
}      
