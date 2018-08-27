 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("��ս", ({ "master bu", "master" }) );
        set("nickname", HIW"ս����"NOR);
        set("gender", "����" );
        set("apprentice_available", 5);
        set("reward_npc", 1);
        set("difficulty", 5);
        set("age", 46);
        set("int", 40);
        set("spi", 25);
        set("cor", 20);
        set("per", 40);
        set("attitude","heroism");
        set("max_force", 200);
        set("force", 200);
        set("force_factor", 30); 
        set("long",
                "�����Ź������Ȼ�������ƣ�ȴ������˵�������������š�\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
                "��սһ�ֽ������ź���ǹ�����ǰ�ú���������ң�˭ɱ������ɱ�ǳ�\n���⣬�Ϸ���������ڡ�\n",
        }) );
        create_family("��ɽ", 3, "��ͷ��");
         set("rank_nogen",1); 
        set("ranks",({ "С���","�����","СͷĿ","��ͷĿ","��ͷ��",RED"���"NOR,RED"��˧"NOR,HIR"��ɽ��"NOR }));
        set("combat_exp", 2200000);
        
        set_skill("move", 140);
        set_skill("xueyeqianzong", 120);
        set_skill("wolf-strike", 180);
        set_skill("animal-training", 180);
        set_skill("assasin-hammer", 150);
        set_skill("cursism", 100);
        set_skill("parry", 120);
        set_skill("wolf-curse",180);
        set_skill("dodge", 140);
        set_skill("force", 200);
        set_skill("unarmed", 160);
        set_skill("summonwolf", 180);
        set_skill("literate", 100);
        set_skill("hammer",150);
        set_skill("wolf-force",150);
        set_skill("perception", 100);    
            map_skill("dodge","xueyeqianzong");
            map_skill("unarmed","wolf-strike");
            map_skill("parry","assasin-hammer");
            map_skill("hammer","assasin-hammer");
            map_skill("force","wolf-force");
        setup();
        carry_object(__DIR__"obj/silkcloth")->wear();
        carry_object(__DIR__"obj/hanyan")->wield();
       carry_object(__DIR__"obj/mysterypicture"); 
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
                        command("say ������һ��һ������\n");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else {
                command("say �Ϸ��Ѿ��չ��˵��ӣ����������ˡ�\n");
        }
} 
void do_recruit(object me)
{
        if( (string)me->query("class") != "wolfmount" )
        {
                command("say ��ֻ�ձ��ŵ��ӣ��㻹����ı�߾Ͱɣ�\n");
        }
        else if(!me->query_temp("marks/wolf_win_tiezhan"))
        {
                switch ( random(2) )
                {
                        case 0:
                                command("say �ø����Ҳ�Т�ļһ��Ȼû�к���ս���к�����������\n����գ�\n");
                                break;
                        case 1:
                                command("say ѧ��Ҫѭ�򽥽����㻹�Ǵ�û��������ɡ�\n");
                                break;
                }
        }
        else if (!me->query_temp("marks/wolf_killed_wuyi"))
        {
                command("shake");
                command("say ��ɱ����������ƥ���Ϸ������ͽ��\n");
        }
        else
        {
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
void init()
{       
        ::init();
        add_action("do_killing", "kill");
        if( !query_heart_beat(this_object()) ) {
                set_heart_beat(1); 
        }
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
        if(id_class == "wolfmount"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ�����ɽ�ӵ�,ͬ����֦,�����������꣡\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}
