 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("������", ({ "ma xiuzhen","ma" }) );
        set("gender", "Ů��" );
        set("title", "������ ��Ů" );
        set("nickname", HIC"��Ӣ����֮"NOR );
        set("long",
"��ĺܸߣ�ϸϸ������һ˫���ۣ���Ц��ʱ��·�Ҳ�����ֱ��˵�ɱ����\n"
                );
        set("attitude", "peaceful");
        set("age", 27);
        set("cps", 40);
        set("int", 50);
        set("per", 15);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 100000);
        
        set("force", 500);
        set("max_force", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 10);
        set("inquiry",  ([
                "Ҷ�³�" : "�ߣ�ʲôһ��������������ɣ��ҿ�Ҳ������ˣ����������ʦ�������˼ң�\n�����������ó����µ�һ������ͷ��\n",
                "master ye" : "�ߣ�ʲôһ��������������ɣ��ҿ�Ҳ������ˣ����������ʦ�������˼ң�\n�����������ó����µ�һ������ͷ��\n",
                  "���Ŵ�ѩ" :" �����Ѫħͷ��ɱ����ʦ������Ӣ����Ѫ�����һ��Ҫ����\n",
                  "master ximen" : "�����Ѫħͷ��ɱ����ʦ������Ӣ����Ѫ�����һ��Ҫ����\n",
        ])                      );
       set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�����������������ۣ���м�������Ƶ�Ҳ������ˡ�\n",
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
        add_money("gold",2);
        carry_object("/d/fugui/npc/obj/w_skirt1")->wear();
}   
