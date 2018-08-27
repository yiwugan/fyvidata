#include <ansi.h>
inherit QUESTNPC;
//inherit F_MASTER;
//inherit SSERVER;
void do_fight();
void create()
{
        set_name("����", ({ "gong jiu", "gong" }) );
        set("gender", "����" );
        set("npc_difficulty",10);
        set("organization/����","а");
        set("age", 27);
        set("int", 70);
        set("per", 38);
        set("str", 150);
        set("dur", 35);
        set("cor", 110);
        set("agi",100);
        set("title","̫ƽ���� ���ߴ�����");
        set("long",
"�����ǹ��ţ��Ǹ��ɶ��ߵ�Һ��������ģ������еı�ѩ����ɽ�ϵ���ʯ��ʨ�ӵ����ͣ�����
�ĺ��������յ����ͣ��˵Ĵ������ټ���һ������ʮ�˲�ز��µĹ�깹�ɵĹ��š�\n"
                );
        set("force_factor", 100);
        set("max_gin", 80000);
        set("max_kee", 100000);
        set("max_sen", 80000);
        set("max_force",4000);
        set("force",4000); 
        set("combat_exp", 130000000);
        set("score", -3000);
        set_skill("unarmed", 600);
        set_skill("sword", 600);
        set_skill("force", 400);
        set_skill("parry", 500);
        set_skill("literate", 300);
        set_skill("dodge", 500);
        
        set("chat_chance",10);
        set("chat_msg",({
                        "���ŵ�����Ŀ�������������ϣ���Ȼ�����Ҿ��ǹ��ţ���һ�޶��Ĺ��š���\n",
                })      );
//         set("chat_chance_combat",100);
//              set("chat_msg_combat",({
//                      (:do_fight:),
//              })      );
        
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/diewusword")->wield();
        add_money("tenthousand-cash",1);
} 
object offensive_target(object me)
{
        int sz;
        object *enemy; 
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0; 
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4; 
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
} 
void crazy(int i,int exp);
void init()
{       
        add_action("do_show","show");
} 
void begin_crazy(); 
void remove_crazied()
{
        set("crazied",0);
} 
int do_show(string arg)
{       
        object whip,me;
        int i,dayTime; 
        mixed *local; 
        me=this_player();
        
        i=me->query("show_gongjiu");        
        local = NATURE_D->get_current_time(); 
        dayTime = local[5]; 
        
        if(!arg) 
        {
                write("��������˿�ʲô������\n");
                return 1;
        }
        if( !whip=present(arg,this_player()))
   {       
                write("������û����������ѽ��\n");
                return 1;
        }
/*        if (whip->query("skill_type")!="whip"||query("crazied")||(string)(NATURE_D->outdoor_room_description()) != "    " +
"ҹĻ�ʹ������췱�ǣ�����һƬ���ҡ�
") */    if ( whip->query("skill_type")!="whip"||query("crazied")||me->query("combat_exp")<25000000 || (dayTime > 240 && dayTime < 1250) )
        {
                message_vision("$N�ó����е�"+whip->name()+"��$n������$nʲô��Ӧ��û�С�����\n",this_player(),this_object());
                return 1;
        }
        if (random(10) >= i){	
        	message_vision("$N�ó�����"+whip->name()+"��$n��ǰ���˻�\n",this_player(),this_object());
        	begin_crazy();
        	set("crazied",1);
        	call_out("remove_crazied",900);
        	return 1;
        }
        else{
        	message_vision("$N����Ŀ���$n��������İ�Ϸ��û���湻ô����\n",this_object(),me);
        	this_object()->kill_ob(me);
        	set("crazied",1);
        	return 1;
        }
        
} 
void begin_crazy()
{
        object weapon;
        object me,ob;
        int exp; 
        ob=this_object();
        me=this_player();
        
//      weapon=me->query_temp("weapon");
//      if(!this_object()->query_temp("crazy") )
//      if (weapon->query("skill_type")=="whip") 
        {
                message_vision("������ɫ��Ȼ��䣬�����𽥱�죬���ڵ���˺�з���������\n",this_object());
                exp=this_object()->query("combat_exp");
                this_object()->delete("no_busy");
                this_object()->start_busy(100);
                this_object()->set("combat_exp",1);
                if(me->query("show_gongjiu") <= 8) { me->add("show_gongjiu",1);me->save();}         //��show���ӵĴ�����1���ӵ�9����ô���ĳɹ���ֻ��1/10
                call_out("crazy",4+random(1),0,exp);
                return;
        }
}  
void crazy(int i,int exp)
{       
        object ob,me,weapon;
   
        ob=this_object();
        me=this_player();
        weapon=me->query_temp("weapon"); 
        if(ob)
        if (!weapon||weapon->query("skill_type")!="whip"||i>12)
        {
                message_vision("$N���ָֻ����侲�����������$n���������Ǻ������Եģ���ֻ����·һ������\n",ob,this_player());
                ob->stop_busy();
                ob->set("no_busy",10);
                ob->set("combat_exp",exp);
//              ob->set("kee",ob->query("max_kee"));
                ob->delete_temp("crazy");
                return;
        }
        else
        {       
                if(!random(2))
                        message_vision("���ŵ���Ϣ������һͷ��������ʮ�����ţ���Ѿ�����˺���Լ����·�������������е��������ң����ҡ���\n",ob);
                ob->receive_damage("kee",5000);
                call_out("crazy",1+random(1),i+1,exp);
        }
}   
int accept_fight(object me)
{
	command("grin");
        command("say ���ϲ�����ô�����˴���㲻֪�����кܶ����õ�����ô��");
        return 0;
}