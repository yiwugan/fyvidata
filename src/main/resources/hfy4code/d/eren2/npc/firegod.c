#include <ansi.h>
inherit __DIR__"smart_npc"; 
void create()
{
        int basic=400;
        int special=200;
                
        set_name("��������",({"xiuluo"}));
        set("title",YEL"ħ�� �˳���֮"NOR);
        set("long", "���˺���������һ�Ż��У�ȫ��������⣬�������ˡ�\n");
        set("age",100+random(20));
//      set("attitude", "aggressive");
        set("combat_exp", 10000000);
        set("dungeon_npc","eren2");
        set("no_fly",1);
        set("boss",1);
                
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("max_atman", 2000);
        set("atman", 2000);
        set("max_mana", 2000);
        set("mana", 2000);
        set("max_force",3000);
        set("force",3000);
        set("force_factor",130);
        set("str",45);
        
        set_skill("unarmed",basic);
        set_skill("dodge",basic);
        set_skill("parry",basic);
        set_skill("perception",basic);
        set_skill("move",basic);
   set_skill("force",basic);
        
        set_skill("lingxi-zhi",special);
        set_skill("fire-strike",special);
        set_skill("meng-steps",special);
        
        map_skill("unarmed","fire-strike");
        map_skill("dodge","meng-steps");
        map_skill("move","meng-steps");
        
        set("npc_type","fighter_u");
        set("class","bat");
        set("skill_type_u","fire-strike");
        set("perform_attack_2","unarmed.lieyan");
        set("perform_busy","dodge.huanyinqianchong");
        set("defense_type",4);  
        set("zombie-killer",1);
        set("officer-killer",1);
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
        
        setup();
        carry_object(__DIR__"obj/g_armor")->wear();
}     
