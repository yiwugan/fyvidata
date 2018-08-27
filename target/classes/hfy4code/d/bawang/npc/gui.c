 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("�鶫��", ({ "gui", "gui dong jing"}) );
        set("nickname", RED "���Ǹ���"NOR);
        set("gender", "����" );
        set("age", 44);
        set("per", 25);
        set("int",50);
        set("str",40);
        set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 90);
        
        set("reward_npc", 1);
        set("difficulty", 5);
        set("long",
                "һ�ŷ���������������ȴ�ܷḻ�������ִ����ܣ�ȴ���ǹεúܸɾ���\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
"�鶫������ص�������ϲ���Ϸ��Ѿ��ش����ﳤ�࣬�˶���Ҳ������
�Ľ����������ڣ����С椣�Ҳ�䵽�ҵ�����....������˲��书��
Ҫ��Ը����Ϸ�Я�֣��Ǻ�....�ư����֣�ָ�տɴ�������\n",
        }) );
        set("combat_exp", 3500000);
        
        set_skill("move", 180);
        set_skill("dodge", 180);
        set_skill("iron-cloth", 150);
        set_skill("xisui", 100);
        set_skill("unarmed",160);
        set_skill("puti-steps",100);
        set_skill("tanzhi-shentong",130);
        set_skill("dragonstrike",160);
        set_skill("throwing",180);
        set_skill("parry",160);
        set_skill("perception",200);
   
        map_skill("iron-cloth","xisui");
        map_skill("dodge", "puti-steps");
        map_skill("unarmed", "dragonstrike");
        map_skill("throwing","tanzhi-shentong");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/dart")->wield();
} 
void init()
{
        object me;
        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
        if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
        add_action("do_killing","kill");
} 
void greeting(object me)
{
        if( !me || environment(me) != environment() ) return;
        if((string)me->name() != "��ɽ��")
        {
                message_vision("$Nһ��$n�����ȵ�����ʲô�ˣ������Ҵ���կ����������������\n",this_object(),me);
                this_object()->kill_ob(me);
                me->kill_ob(this_object());
        }
        else
        {
                message_vision("$NЦ��������ɽ���������ռ����ɷ񣿴�������λС��������\nһ��������Ʒ��������ա���\n",this_object(),me);      
                message_vision("$Nתͷ����������Ц��������С椣����ż�......������\n",this_object(),me);                
        }
} 
int do_killing(string arg)
{
        object me,victim;
        string name;
   me = this_player();
        if( !arg) return 0;
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = (string)victim->name();
                if( (string)name == "�鶫��"&&(string)me->name() == "��ɽ��"&&!me->query("m_success/ɱ�鶫��") )
                {
                        message_vision("$N��ʧɫ�������㲻����ɽ������$n��ͻȻ����ʹ$N¶���˶ദ������\n",this_object(),me);
                }
                else
                {
                        this_object()->kill_ob(me);
                        me->kill_ob(this_object());
                }
        }
} 
