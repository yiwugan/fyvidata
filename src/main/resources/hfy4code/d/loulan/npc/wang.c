#include <ansi.h>
inherit NPC; 
void create()
{
        object armor;
        set_name("������", ({ "wang lianhua","wang" }) );
        set("gender", "����" );
        set("title", "ǧ�湫��" );
        set("nickname", HIM"���ž���������"NOR );
        set("long",
                "һ�����û����������ꡣ����ݰף���ü��Ŀ����ɫ����͸�죬������������\n"
                );
        set("attitude", "peaceful");
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                      (:perform_action,"blade.shiwanshenmo":),
                      (:perform_action,"dodge.huanyingqianchong":),
        }));
        set("age", 25);
        set("cps", 40);
        set("int", 50);
        set("per", 40);
        set("cor", 40);
        set("agi", 30); 
        set("combat_exp", 2500000);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);  
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������Ц�����������ۣ�ҲҪ�����˼���ⳡ��Ϸ�� \n",
                "��������Ц�������ˡ������ˡ������˿��������Ͱ׷ɷɡ�����  \n",
                }) ); 
        set_skill("unarmed", 140);
        set_skill("blade", 200);
        set_skill("bat-blade", 150);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("move", 200);
        set_skill("meng-steps", 140);
        set_skill("nine-moon-claw", 140);
        
        map_skill("move","meng-steps");
        map_skill("dodge", "meng-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                
        setup();
        carry_object(__DIR__"obj/sword2")->wield();
        armor=new("/obj/armor/cloth");
        armor->set_name("��Ƥ����",({"coat"}) );
        armor->move(this_object());
        armor->wear();
}
