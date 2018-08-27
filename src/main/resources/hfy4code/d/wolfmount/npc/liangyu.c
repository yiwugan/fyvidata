#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({"wen liangyu", "liangyu","wen" }));
        set("nickname", HIC"ǫǫ����"NOR HIG"��������"NOR );
        set("gender", "����");
        set("age", 42);
        set("long",
                "���¸߹ڣ��������ţ�������ҡ��һ�����ȣ�����ȥ������ס�\n");
        set("attitude","friendly");
        create_family("��ɽ", 3, "��ͷ��");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("apprentice_available", 5);
        set("rank_nogen",1); 
        set("ranks",({ "С���","�����","СͷĿ","��ͷĿ","��ͷ��",RED"���"NOR,RED"��˧"NOR,HIR"��ɽ��"NOR }));       
        set("str", 50);
        set("int", 40);
        set("con", 26);
        set("agi", 50);
        set("per", 40);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "̫��ʹ�����������������ǳ���������Ҿ������㡣�����㵽���ֺ��������� \n",
        }));
    set("max_force", 2000);
    set("force", 2000);
    set_temp("apply/damage", 100);
    set("force_factor", 100);
    set("combat_exp", 10000000);
        set("score", -50000);
        set_skill("force", 150);
        set_skill("bibo-force", 150);
   set_skill("unarmed", 180);
        set_skill("dodge", 180);
        set_skill("luoriquan", 220);
        set_skill("move", 180);
        set_skill("fengyu-piaoxiang", 320);
        set_skill("parry", 150);
        set_skill("literate",150);
        set_skill("stealing",320);
        map_skill("force"  , "bibo-force");
        map_skill("unarmed", "luoriquan");
        map_skill("dodge"  , "fengyu-piaoxiang");
        map_skill("move"  , "fengyu-piaoxiang");
        setup();
        carry_object(__DIR__"obj/mask")->wear();
        carry_object(__DIR__"obj/silkcloth")->wear();
} 
void die()
{
        object me;
        object grass; 
        if(objectp(me = query_temp("last_damage_from")))
        {
                command("say �����Ҵ��⣬�ݻ���ɽ����֮���ӣ�\n");
                if(me->query_temp("marks/������̫ү")){
                        me->delete_temp("marks/������̫ү");
                        me->set("m_success/��ɽ���",1);
                }
                me->set("marks/ɱ̫��ʹ��",1);
                grass = new(__DIR__"obj/grass");
                grass->move(this_object());
                ::die();
        }
} 
void init()
{
        object me;
        ::init();      
        if( interactive(me = this_player()) && !is_fighting()) 
        {
                call_out("greeting", 1, me);
   }
        add_action("do_kill", "kill");
} 
int greeting(object me)
{
        object npc;
        object xiaoma;
        npc = this_object();
        if ( me->query_temp("marks/wolf_xiaoma_good") )
        {
                message_vision(HIY "$N��Ц�����ٺ٣��ֲ���С����ô��������ԭ�������˸����֣�����ʲô��\n"NOR, npc);
        }
        else
        {
                message_vision(HIY "$N����������������Ұɣ���������֣�\n"NOR, npc);
        }
        return 1; 
} 
int do_kill(string arg)
{
        object me,ob;
        me = this_player();
        ob = this_object();
        if (arg != "sun legate")
                return 0;
        else 
        {
                me->kill(ob);
                ob->kill(me);
                environment(me)->kill_notify(ob,0);
        }
        return 1;
}
void do_recruit(object me){
        if(me->query("title") == "��ɽ "+HIR"��ȴ���"NOR){
                command("say ���Ҿ�����Ϊͽ�ɡ�\n");
                command("recruit" + me->query("id"));
        } else {
                command("hmm");
        } 
} 
int recruit_apprentice(object ob){
        if( ::recruit_apprentice(ob) )
            ob->set("class", "wolfmount");
    add("apprentice_availavble", -1);    
} 
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
            if( find_call_out("do_recruit") != -1 )
            command("say ������һ��һ������");
            else
            call_out("do_recruit", 2, ob);
        } else {
            command("say ���ղ������ˡ�");
        }
} 
void reset(){
        set("apprentice_available", 5);
}
