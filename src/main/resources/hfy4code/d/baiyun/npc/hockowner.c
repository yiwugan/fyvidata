#include <ansi.h>
inherit NPC;
inherit F_PAWNOWNER;
inherit F_VENDOR;
void create()
{
        set_name("���꾫", ({ "foxgirl" }) );
        set("gender", "Ů��" );
        set("class","huashan");
        set("age", 29);
        set("title", "���ǵ��� �ϰ���");
        set("long","
���꾫����ĸ���꣬��Ȼ���Ϻ���ķ��ˣ��Ϻ�������ţ�
�����ѵ�Ȼ����ĸ���������ӵ������һ������ò������
һ������Ӱ��û����֪���������������뷨����ͺ��꾫����
�ˣ������书��ߣ�����һȥ��������һ�㣬��һ
���ĺ��꾫�������˲������ĺ��꾫��\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("per",30);
        set("str",4);
        set("no_arrest",1);
        set_skill("unarmed",600);
        set("richness",100000);
        set_skill("dodge",200);
        set_skill("zhaixin-claw",50);
        map_skill("unarmed","zhaixin-claw");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.zhaixin" :),
        }) );
        
        setup();
        carry_object("/obj/armor/skirt", 
                        ([      "name"  :       HIY "��" + HIR "��"NOR + "����ȹ",
                                "long"  :       "һ�����˿��ɵĽ���ȹ\n",
                                "armor_prop/armor" :    3  ])   
                        )->wear();
} 
void init()
{  
        object ob;
        ::init();
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
        add_action("do_vendor_list","list");
} 
void greeting(object ob)
{
        if ( !ob || environment(ob) != environment() ) return;
        if ( ob->query("gender") == "����")
           {
             switch( random(3) ) 
                {
                  case 0:
                  message_vision("$N����������˵�������������ϣ�������λ"+RANK_D->query_respect(ob)+
"������䵱Щʲô������Ʒ��\n",this_object(),ob);       
                  break; 
                  case 1:
                  message_vision("$N��ǰ��ס$n���֣�Ц�����˵������λ"+RANK_D->query_respect(ob)+
"����������ϴ������ʱ���ߴ����ͣ�Ӣ�������ˣ���\n",this_object(),ob);
                  break;
                  
                }
           }
        else
           {
             switch( random(3) ) 
                {
                  case 0:
                  message_vision("$N��ǰ�ḧ$n�ķ�����˵������λ"+RANK_D->query_respect(ob)+
"����������£����������ˣ�\n",this_object(),ob);
                  break;
             
                  case 1:
                  message_vision("$N��ǰ��ס$n���֣�Ц�����˵������λ"+RANK_D->query_respect(ob)+
"������䵱Щʲô������Ʒ��\n",this_object(),ob);
                  break;
                }
           }            
}      
