 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        object armor;
        set_name(RED"�������"NOR, ({ "red lama"}) );
        set("gender", "����" );
        set("age", 40+random(10));
        set("int", 30);
        set("long",
                "��̸�ɮ���ܸ���֮����������������ʧ��֮�¡�\n"
                );
        set("class","lama");
        set("combat_exp", 2500000);
        set("score", 900);
        set("fle",50);
        set("force",1000);
        set("max_force",1000);
        set("force_factor",50);
        set("atman",2500);
        set("max_atman",2500);
        set("mana",4000);
        set("max_mana",4000);
        set("resistance/kee",30);
        set("class","lama");        
        set("chat_chance", 1);
        set("chat_msg", ({
                "���������Ȼ˵��������һ�ղ��鲼�����������Ǿ�һ�ղ��ܰ�˯��\n",
                (: random_move :),
                }) );
        
        set_skill("iron-cloth", 200);
        set_skill("staff",150);
        set_skill("cloudstaff", 160);
        set_skill("unarmed",150);
        set_skill("bloodystrike", 150);
        set_skill("force", 80);
   set_skill("bolomiduo", 75);
        set_skill("spells",150);
        set_skill("parry",140);
        set_skill("kwan-yin-spells",100);
        
        if (random(2)) set_skill("jin-gang",100);
        
        map_skill("iron-cloth","jin-gang");
        map_skill("spells","kwan-yin-spells");
        map_skill("parry","cloudstaff");
        map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("staff", "cloudstaff");
        
        add_temp("apply/iron-cloth", 100);
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) ); 
        setup();
        armor=new(__DIR__"obj/redclothh");
        armor->set_name(RED"�����ߺ���"NOR,({"cloth"}) );
        armor->move(this_object());
        armor->wear();
        carry_object(__DIR__"obj/7staff")->wield();
}  
smart_fight()
{
        int i,j;
        object *enemy, who;
        who = this_object();
        if (who->is_busy()) return;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie() && random(2))
                {
                        this_object()->cast_spell("ni");
                   return;
                }               
        }
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_skill("iron-cloth")>300 
                                || enemy[i]->query("combat_exp")>who->query("combat_exp")) {
                                who->cast_spell("an");
                                return;
                        }
                        if (enemy[i]->is_busy()) this_object()->smart_attack();         
                        }
        }
return;
} 
smart_attack() {
        this_object()->perform_action("staff.longxianyuye");    
        return;
        }
