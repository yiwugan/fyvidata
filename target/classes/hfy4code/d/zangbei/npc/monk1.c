#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{
        set_name("����µ�����",({"chonggu lama","lama"}));
        set("long", "����ֱ���´�ɨ��Ժ�����\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 1500000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",30+random(20));
        set("class", "lama");
        
        
        set_skill("iron-cloth", 100);
        set_skill("staff", 100);
        set_skill("lamastaff", 100);
        set_skill("unarmed", 100);
        set_skill("lamaism", 100);
        set_skill("bloodystrike", 100);
        set_skill("force", 100);
        set_skill("bolomiduo", 100);
        set_skill("spells",100);
        set_skill("parry",100);

        set_skill("kwan-yin-spells",100);
        set_skill("perception", 100);
        
        map_skill("spells","kwan-yin-spells");
        map_skill("parry","lamastaff");
        map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("staff", "lamastaff");

        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "�����������������飬���²������ӵ�����ȥι�㡣\n",  
        }) );
        set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
            (: perform_action, "unarmed.fefawubian" :),
            }) ); 
/*        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );*/
          
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        //set("force_factor",40);
        setup();
        carry_object(__DIR__"obj/lamacloth")->wear();
        
}
