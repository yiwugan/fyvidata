#include <ansi.h>
inherit NPC;   
void create() 
{ 
        set_name("��һ��", ({ "wang yihu","yihu"}) );
        set("title", "����կ ������" );
        set("nickname", HIY"�������"NOR);
        set("gender", "����");
        set("age", 33);
        set("long",
                "һ�����ʹ󺺡�����˼�壬��������������������ѿ�ɽ�󸫣�һ\n���Ⱦͱȳ�׼�����˶��ء�\n" );
        set("combat_exp", 600000);
        set("score", 17000);
        set("cor",30);
        set("attitude","killer");
        set("bellicosity", 600); 
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 30); 
        set_skill("force", 60);
        set_skill("axe", 100);
        set_skill("parry", 80+random(50));
        set_skill("dodge", 70+random(50));
        set_skill("wuche-axe",120); 
        map_skill("axe", "wuche-axe");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "axe.sanbanfu" :)
        }) );  
        setup(); 
        carry_object(__DIR__"obj/huge_axe")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        carry_object(__DIR__"obj/fur_coat")->wear();        
        add_money("gold", 1);
}   
void init() 
{ 
        object me;
        ::init();
        me = this_player();
   if(me && environment(me) == environment() && !me->is_fighting()) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}   
void greeting(object me) 
{
        if((string)me->name() !="��ɽ��" ) 
        {
                command("say �����������㿴�����ӵĸ����ж�죡\n");
                this_object()->kill_ob(me);
        }
        else
        {
                command("say ��ɽ������θ����Ӵ��ռ���û�У�\n");
        }
}       
