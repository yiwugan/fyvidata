#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��������", ({ "oldman" }) );
        set("long","һ���������ǵ����˼ң��������Ͽ����˽⵽��Ľ�����\n");
        
        set("age", 76);
        set("cor", 50);
        set("cps", 25);
        set("agi",40);
        set("int",40);
        set("per",20);
        set("con",25);
        set("fle",25);
        set("tol",30);
        
        set("chat_chance",1);
        
        set("chat_msg", ({
            "�������������۳���̾��������ɽׯ�Ĺ�������̫���ˣ�����������\n����˭Ҫ���أ�\n",
         "���������ĳ۵�����˵��һ����������������������磬��үү�����˲���ɽ��\n��һƬ���־�˵������үү�����������ж����µ����󡣡�\n",
                })); 
        
        set("combat_exp", 500000);
        set("max_atman", 1000);
        set("atman", 1000);
        
        set("max_force",500);
        set("force",500); 
        set_skill("unarmed", 100);
        set_skill("force",200);
        set_skill("huntunforce",100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("move",100);
        set_skill("taiji",85);
        
        map_skill("unarmed","taiji");
        map_skill("force","huntunforce");
   
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.nianzijue" :),
        }) );
        
        
        set("inquiry",  ([
                "����" : "���긻��ɽׯ������ׯ����Ǳʯδ����ʱ������ɽׯ
�����Ǹ��󷱻����������£������Դ��ⲻ�����ġ����������̳м�
ҵ�󣬰�������һ��Ϳ�أ�һ����Ϳ���ݷõ������ˣ�����⼪����
Ҳ����˥������ࡣŪ�ô�ҵ����Ӷ��ٲ����ѡ�\n",
                "story" : "���긻��ɽׯ������ׯ����Ǳʯδ����ʱ������ɽׯ
�����Ǹ��󷱻����������£������Դ��ⲻ�����ġ����������̳м�
ҵ�󣬰�������һ��Ϳ�أ�һ����Ϳ���ݷõ������ˣ�����⼪����
Ҳ����˥������ࡣŪ�ô�ҵ����Ӷ��ٲ����ѡ�\n",
        ])                      );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}  
