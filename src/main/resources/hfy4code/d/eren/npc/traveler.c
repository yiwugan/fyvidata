#include <ansi.h>
inherit NPC;  
void create()
{
        set("long", "����һ�����̵����ˣ����Ǹ��ض��У��糾���͡�\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 1000000);
        set("dungeon_npc","eren");
                
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",30);
        
        set_skill("unarmed", 200);
        set_skill("iron-cloth", 150);
        set_skill("shuaijiao", 170);
        map_skill("unarmed", "shuaijiao");

        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����˵�������ɱ�������˲źá�\n"
                "����˵�����ǽ�Ӷ��У���ǿ���͸���ƴ����\n"
        }) );
        set("chat_chance_combat", 50);
/*        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );*/
         
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("guardian",100,120,1,"/obj/weapon/","fighter_w","cloudstaff");
        set_name("��Į����",({"traveler","desert traveler"}));
        set("force_factor",40);
        setup();
        add_money("silver", 50);
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/towel");
}  
