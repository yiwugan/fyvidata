//weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("����Ӣ", ({ "su shaoying","su" }) );
        set("gender", "����" );
        set("title", "������ ����" );
        set("nickname", HIM"��Ӣ����֮"NOR );
        set("long",
        "һ���Ǹ������ѵ��ˣ���û���ḯ����Ҳ���������鵱��Ȥ���Ǹ���ѧ�ľ��ˣ�\n�������������������ȴ�·���ᡣ\n"
                );
        set("attitude", "peaceful");
        set("age", 25);
        set("cps", 40);
        set("int", 50);
        set("per", 40);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 300000);
        
        set("force", 500);
        set("max_force", 500);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 20);
        set_temp("apply/armor",150);
        set_temp("apply/attack", 50);
        set_temp("apply/damage", 9999);

        set("chat_chance", 5);
        set("chat_msg", ({
                "����Ӣ̸Ц����������˵���������ķ������¡�����\n",
                "����Ӣ��ͷ���������Ǹ������ˣ�����������ף���Ȼû�����ܱȵ��ϡ������� \n",
                }) ); 
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("move", 50);
        set_skill("sky-sword", 50);
        set_skill("sky-steps", 50);                
        map_skill("parry", "sky-sword");
        map_skill("sword", "sky-sword");
        map_skill("move", "sky-steps");
        map_skill("dodge", "sky-steps");
        setup(); 
        carry_object("/obj/weapon/sword")->wield();
        add_money("gold",5);
        carry_object("/obj/armor/cloth")->wear();
} 