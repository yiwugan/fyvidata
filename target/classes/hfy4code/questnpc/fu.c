#include <ansi.h>
inherit QUESTNPC;
#include <ansi.h>
void crazy();
void create()
{
        set_name("����ѩ", ({ "fu hongxue","fu" }) );
        set("gender", "����");
        set("age",26);
        set("nickname", HIC"���ġ����¡���"NOR);
        set("title", "�߳�����");
        set("combat_exp", 50000000);
        set("long",
                "�����ϵ�����Ӣ����ͻ������ȴ����Զɽ�ϵı�ѩ�ܳɵġ�\n",
        );
        set("cor",40);
//        set("quest_npc",1);
	set("organization/����","а");
	set("npc_difficulty",6);
//	set("no_busy",6);
	set("attitude", "peaceful");
        set("str",100);
        set("cps",31);
        set("max_force",4000);
        set("force",4000);
        set("force_factor",80);
        set("max_kee",100000);
        set("max_gin",80000);
        set("max_sen",80000);
        set_skill("force",200);
        set_skill("demon-force",200);
        set_skill("parry", 200);
        set_skill("blade",200);
        set_skill("dodge",300);
        set_skill("demon-steps",200);
        set_skill("demon-blade",200);
        map_skill("dodge","demon-steps");
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        map_skill("force","demon-force");
        set("chat_chance", 90);
        set("arrive_msg","���˹��������������һ�����ҽŲ�����������ȥ");
        set("leave_msg","��ȥ�����������һ�����ҽŲ�����������ȥ");
        set("chat_msg", ({
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: crazy :),
         "����ѩ����¶���˼���ʹ��ı��飬������������𣬱��𣡣���\n",
        }) );    
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action,"dodge.lianhuanbabu"  :),
          	(:perform_action,"blade.tiandirenmo" :),
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/blackblade")->wield();
}

void init()
{
	object ob;
        ::init();
        if( userp(ob = this_player()))
        if( (string)ob->name() == "��Ũ" )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void remove_effect(int exp);
//������ɱ����������busy
void crazy()
{       int exp;
        if (!random(50))
        {
                message_vision("����ѩ������ȻŤ�����Σ������³���ĭ���������¶���ʼ���Ρ�������¶�����ޱ�ʹ��ı��飬
���ƺ���˵ʲô��ȴһ����Ҳ˵������������������",this_object());
                exp=this_object()->query("combat_exp");
                this_object()->delete("no_busy");
        	this_object()->start_busy(30);
                this_object()->set("combat_exp",25000000);
                call_out("remove_effect",30,exp);
                return;
        }
        return;
} 
void remove_effect(int exp)
{
        message_vision("����ѩ��������ڷ������ˡ�\n",this_object());
        this_object()->stop_busy();
        this_object()->set("no_busy",6);
        this_object()->set("combat_exp",exp);
}    
int accept_fight(object me)
{
	command("heng");
        command("say �ҵĵ������������ġ�");
        return 0;
}

void greeting(object me)
{
	int exp;
        if(!me ||environment(me)!=environment())
                return ;
	        message_vision("����ѩ����ֵı��鿴�Ŵ�Ũ����������ȻŤ�����Σ�����¶�����ޱ�ʹ��ı��飬����
������ʲôʹ������飬���ƺ���˵ʲô��ȴ��˵����һ�仰��\nֻ���������³���ĭ���������¶���ʼ���Ρ�����������\n",this_object());
                exp=this_object()->query("combat_exp");
                this_object()->delete("no_busy");
        	this_object()->start_busy(15);
                this_object()->set("combat_exp",25000000);
                call_out("remove_effect",30,exp);
                return;
        return ;
}  