 // explorer.c
#include <ansi.h>
inherit NPC;
void smart_fight(object who); 
void create()
{
        object weapon,armor;
        
        set_name("��ɽ������", ({"mountain climber"}) );
        set("gender", "����" );
        set("age", 36);
        set("agi",30);
        set("cps",40);
        set("cor",40);
        
        set("class","beggar");
         set("long",
                "���ԹŻ�ɽһ��·����������ʮ�������ʵǵģ���Ȼ�Ǿ���
ǿ׳�����ģ���໹���书��\n"
                );
        set("combat_exp", 2200000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ɽ��Ц�������⻪ɽ֮�գ�Ҳ�����������ѣ���\n",
                "��ɽ��ָ���ͱ��ϵ�ӥ��˵�������ϻ��ۣ��Ϳ���������ȥ��Сӥ׽��������\n",
        }) );
        
            
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 20);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
                  
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 140);
        set_skill("parry", 140);
        set_skill("dodge", 140);
                        
        set_skill("qidaoforce", 150);
        set_skill("doggiesteps",150);
        set_skill("dragonstrike",150);
        set_skill("dagou-stick",150);
        
        map_skill("unarmed","dragonstrike");
        map_skill("force", "qidaoforce");
        map_skill("dodge","doggiesteps");
        map_skill("move","doggiesteps");
        map_skill("parry","dagou-stick");
        map_skill("staff","dagou-stick");
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: smart_fight(this_object()) :),
        }) );   
        
            setup();
            carry_object(__DIR__"obj/shoe")->wear();
            armor=new("/obj/armor/cloth");
            armor->set_name(WHT"��ɽ��"NOR,({"cloth"}) );
            armor->move(this_object());
            armor->wear(); 
            weapon=new("/obj/weapon/staff");
            weapon->set_name(WHT"��ɽ��"NOR,({"staff"}) );
            
            weapon->move(this_object());
            weapon->wield(); 
            if (!random(5)) carry_object("/d/huashan/obj/flower3");
            carry_object(__DIR__"obj/leathersleeves.c")->wear();
}  
void smart_fight(object who)
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
   if (i>1) {
                who->perform_action("staff.tianxiawugou");
                return;
        }
        if (!random(3)) who->perform_action("staff.banzijue");  
        return;
}     
