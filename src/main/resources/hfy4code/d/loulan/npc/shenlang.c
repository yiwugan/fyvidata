#include <ansi.h>
inherit NPC;
int give_mission();
void create()
{
        set_name("����", ({ "shen lang","shen" }) );
        set("gender", "����" );
        set("title", "����" );
        set("nickname", HIC"�̽������ؾ���"NOR );
        set("long",
                "һ����ü��Ŀ��Ӣ�����꣬���΢΢���ϣ���ЦʱҲ��������Ц�⣬����\n��Ȼ��ɢ�������ֶ�ʲô�¶������ں���ζ����ȴ˵����������ϲ���� \n"
                );
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("class", "emei");
        set("difficulty", 20);
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                (:perform_action,"sword.tianrenheyi":),
                (:perform_action,"dodge.luoyeqiufeng":),
        }));
        set("age", 23);
        set("str", 100);
        set("cps", 100);
        set("int", 100);
        set("per", 100);
        set("cor", 40);
        set("agi", 80);
        set("combat_exp", 8000000);
        set("force", 8000);
        set("max_force", 8000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
        set("force_factor", 200);
        set_temp("apply/armor",300);
        set_temp("apply/attack", 200);
        set("chat_chance", 2);
        set("inquiry",([
           "������" : (: give_mission :),
                ]) );
        set("chat_msg", ({
                "����̾�˿�������������ߣ�������� \n",
                }));
        set_skill("unarmed", 200);
        set_skill("sword", 300);
  set_skill("sky-sword", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("move", 300);
        set_skill("fall-steps", 200);
        set_skill("luoriquan", 200);
        map_skill("dodge", "fall-steps");
        map_skill("unarmed", "luoriquan");
    map_skill("sword", "sky-sword");
  map_skill("parry", "sky-sword");
                
        setup(); 
        carry_object(__DIR__"obj/sword1")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
int give_mission()
{
        object me,jade;
        object ob;
        me=this_player();
        
        if (ob=present("bai feifei", environment(this_object())))
        {
                message_vision("$NŤ��������$n��̾�˿�����ĬȻ���\n",this_object(),ob);
        }
        else if( userp(me) && me->query_temp("marks/chai_notify_bai"))
        {
                if(!me->query_temp("marks/chai_get_jade"))
                {
                        command("consider");
                        message_vision("$NͻȻת��ͷ��Ŀ����濴��$n��ͻȻ΢΢һЦ���㲻�Ƿ�����......",this_object(),me);
                        message_vision("$N�ͳ�һ����赣�Ц����Ӣ�ۣ��������赽������ߣ�����Ȼ֪����һ������\n",this_object());
                        jade = new(__DIR__"obj/jade");
                   jade->move(me);
                        me->set_temp("marks/chai_get_jade",1);
                }
                else
                {
                        message_vision("$NЦ������λӢ�ۣ������������ߣ���һ�пɺã�\n",this_object());
                }
        }
        else
        {
                message_vision("$N����¶��һ˿�����΢Ц�����ߣ����Ǹ��ֵܹ�Ů����......\n",this_object());
        }
        return 1;
} 
int accept_object(object me, object obj)
{       
        object npc;
        object book;
        object *inv;
        int i;
        int j;
        j = 0;
        npc = this_object();
        if( userp(me))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("owner")=="������" && (int)inv[i]->query("equipped"))
                        {
                                j = 1;
                        }
                }
        }
        if (me->query_temp("marks/knight_kill_wang") && obj->query("name") == "��ľ�����" && j == 1)
        {
                message_vision(HIY"$N��ɫ���ؿ��������еİ׷ɷɣ�����̾�˿�����������\n"NOR,npc);
                message_vision(HIY"$N�ͳ�һ����ᣬ��Ȼ���������Ҹ����������������������Ѫ������Բ���һ�£�\n"NOR,npc);
                book = new(__DIR__"obj/book2");
                if (book) book->move(me);
           if (!me->query("m_success/¥����Ե"))
                {
                        me->add("score",300);
                        me->set("m_success/¥����Ե");
                }
                call_out("leave",2,me);
                return 1;
        }
        else
                return notify_fail("����ҡͷ΢Ц��ĬȻ���\n");       
} 
void leave(object me)
{
        object ob;
        if (living(this_object()) && environment(me) == environment())
        {
                message_vision(HIY"$N��Ȼ������𣬱���׷ɷɣ���Ц��������������װ�ˣ������ȥ�������\n�����������������ң������ط꣡\n"NOR,this_object(),me);
                message_vision(HIY"��Х���У�$N������ȥ��\n"NOR,this_object());
                destruct(this_object());
        }
        remove_call_out("leave");
} 
