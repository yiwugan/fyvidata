 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("������", ({ "sun xiuqin","sun" }) );
        set("gender", "Ů��" );
        set("title", "������ ��Ů" );
        set("nickname", HIR"��Ӣ����֮"NOR );
        set("long",
"���˴�Լ��һ���彣��������ȥ����Ӣ��������������ü��\n"
                );
        set("attitude", "peaceful");
        set("age", 27);
        set("cps", 40);
        set("int", 50);
        set("per", 30);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 100000);
        
        set("force", 500);
        set("max_force", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 10);
        set("inquiry",  ([
                "Ҷ�³�" : "Ҷ�����ķ��ɽ�������ж�������֮����ʦ��Ҳ�����������\n",
                "master ye" : "Ҷ�����ķ��ɽ�������ж�������֮����ʦ��Ҳ�����������\n",
                  "���Ŵ�ѩ" :"�������Ź����ܷ�Ӯ����Ҷ���������Ͻ�֮ս�����˹һ�����\n",
                  "master ximen" :"�������Ź����ܷ�Ӯ����Ҷ���������Ͻ�֮ս�����˹һ�����\n",
        ])                      );
       set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������üͷ΢�壬�������������紵ɢ�ĳ�������\n",
                }) ); 
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("sky-sword", 10);
        set_skill("liuquan-steps", 10);
        map_skill("dodge", "liuquan-steps");                
        map_skill("move", "liuquan-steps");                
        map_skill("sword", "sky-sword");
        map_skill("parry", "sky-sword");
                
        setup(); 
        carry_object("/obj/weapon/sword")->wield();
        add_money("gold",1);
        carry_object("/d/fugui/npc/obj/w_skirt3")->wear();
}    
