#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER; 
void auto_fight();
void create()
{
        set_name("��ͩ��", ({ "du tongxuan", "du" }) );
        set("gender", "����" );
        set("nickname",BLU"����ѧʿ"NOR); 
        set("organization/����","��");
        set("npc_difficulty",8);
        set("age", 47);
        set("int", 25);
        set("per", 20);
        set("str", 100);
        set("class","official");
        set("dur", 35);
        set("cor", 35);
        set("fle",20);
        set("long",
"���˺ܸߣ����ݣ�������������̬�ȼ�˹�ģ�����䲻��
������ȴ�Ѱ߰ף�һ���������������ϣ��·��������
���ݣ�ȴ�ִ����߷����ϣ����˾����Ҷ�����˿�����ӡ�\n");
        set("force_factor", 150);
        set("max_gin", 50000);
        set("max_kee", 250000);
        set("max_sen", 50000);
                set("max_force",8000);
                set("force",8000); 
        set("combat_exp", 75000000);
        set("score", 12000);
        set_skill("unarmed", 200);
        set_skill("force", 250);
        set_skill("parry", 300);
        set_skill("literate", 160);
        set_skill("dodge", 300);
        set_skill("fengyu-piaoxiang",400);
        set_skill("move",500);
        set_skill("iron-cloth",200);
        set_skill("henglian",200); 
        set_skill("manjianghong",200);
        set_skill("changquan", 350);
                
        map_skill("unarmed", "changquan");
        map_skill("force","manjianghong");
        map_skill("iron-cloth","henglian");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        map_skill("parry","changquan");
     
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
        	(: perform_action,"dodge.zonghengsihai":),
                (: perform_action,"unarmed.yuhuan":),
        }) );
        setup();
        carry_object(__DIR__"obj/bluecloth")->wear();
        carry_object(__DIR__"obj/baiyubi");
        carry_object(__DIR__"obj/yubanzhi")->wear();
//      add_money("gold",15);
//        carry_object(__DIR__"obj/feiyunspear")->wield();
}
int accept_fight(object me)
{
	command("smile");
        command("say ���¹���æ�����в��㡣");
        return 0;
}
void auto_fight() {
	object obj,me;
	obj = this_object();
	me = this_player();
	
        if(!me || !obj || !userp(me) || me->is_fighting(obj) || me->query_temp("is_unconcious")
                        ||!living(me) || environment(me)!=environment(obj)
                        || environment(me)->query("no_fight")
                        || obj->query_temp("is_unconcious")) {
                return;
        } 
	if(obj->query("organization/����") == "��"){            //���npcΪ��������
        	if( me->query("organization/����") == "��"){
        		if(me->query("justice")>= 1000 )
        			message_vision("$N��$n��ȭ�������ֵܣ���֯���˾Ϳ����ˣ�\n",obj,me);
        		else
        			message_vision("$N΢Ц�ض�$n�����ֵܽ��쾫�񲻴���\n",obj,me);
        		if(me->query("improbity") < 1000&&me->query("improbity") > 500){
        			message_vision("$N��$n�ȵ�����Ȼ�������ɣ�����Ϊ���������ҵý�ѵ��ѵ�㣡\n",obj,me);
        			obj->fight_ob(me);
        			me->fight_ob(obj);
        		}else if(me->query("improbity") >=1000){
        			message_vision("$N��$n���������������������������ͬ�������������Ż�����\n",obj,me);
        			obj->kill_ob(me);
        		}
        	}else{
        		if (me->query("organization/����") == "а")
        		{
        			if(me->query("improbity") <1000)
        				message_vision("$N��$n��������Ҳ���Ǹ����Ϊ�μ���а�̣�Ϊ����������ϧ��ϧ��\n",obj,me);
        			else{
        				message_vision("$N��$n�ȵ���а��������������ͬ��������������������ҪΪ���ֳ�����\n",obj,me);
        				obj->kill_ob(me);
        			}
        		}
        		else
        		{
        			if(me->query("improbity") <1000)
        				message_vision("$N����$n���ۣ�̾��������ϧ��ϧ�����˲�����Ϊ��ƫƫѧ����\n",obj,me);
        			else{
        				message_vision("$N��$n�ȵ������㻹û�м���а�̣����Ȱ�����ˣ�������պ��Ϊ���ֻ�������\n",obj,me);
        				obj->kill_ob(me);
        			}
        		}
        	}
        }
	if(obj->query("organization/����") == "а"){
		if( me->query("organization/����") == "а"){
        		if(me->query("improbity")>= 1000 )
        			message_vision("$N�ֺõö�$n˵�����Ժ����������Ρ�\n",obj,me);
        		else
        			message_vision("$N��Ц����������$n�����ֵܽ��������˶��١���������\n",obj,me);
        		if(me->query("justice") < 1000&&me->query("justice") > 500){
        			message_vision("$N��$n��Ц�������������㻹�Ǻ���һ�����ҵ���̼��У�\n",obj,me);
        			obj->fight_ob(me);
        			me->fight_ob(obj);
        		}else if(me->query("justice") >=1000){
        			message_vision("$N��$n��Ц�������������ˣ���\n",obj,me);
        			obj->kill_ob(me);
        		}
        	}else{
        		if (me->query("organization/����") == "��")
        		{
        			if(me->query("justice") <1000)
        				message_vision("$N��$n�����ٺ٣����Ǽ�������а�̰ɣ���ˮ�����ء�\n",obj,me);
        			else{
        				message_vision("$N��$n��Ц�����������㲻�ã�Ҫ��Ȼ�պ��ֵ��ǿ�û�к����ӹ���\n",obj,me);
        				obj->kill_ob(me);
        			}
        		}
        		else
        		{
        			if(me->query("improbity") <1000)
        				message_vision("$N����$n���ۣ���Ц���������ǿ�ò��ϣ�ΪʲôҪȥ�Һ��£��������ȥ��ҽ�������ʹ��\n",obj,me);
        			else{
        				message_vision("$N��$n��Ц������Ȼ�������ѣ��Ǿ��ǵ��ˣ���\n",obj,me);
        				obj->kill_ob(me);
        			}
        		}
        	}
        }            		
} 