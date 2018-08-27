#include <ansi.h>
inherit SMART_NPC; 
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("title",WHT"���˿�Ѳ��"NOR);
        set("long", "����һλ���˿ߵ��ӣ���һ��������ͬ�����Ǹ���Ѳ�Ӹ�����\n");
        set("age",30+random(20));
        set("attitude", "aggressive");
        set("combat_exp", 5500000);
        set("dungeon_npc","eren2");
        set("no_fly",1);
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",60);
        set("pursuer", 1);
        set("wimpy",40);
        
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                "Ѳ������������ܿ��˿�˵����ʲô����û�У�\n",
        }) );
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
           (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,200,1,"/d/eren2/npc/obj/","all","all");
        setup();
        
        carry_object(__DIR__"obj/g_armor")->wear();
}     
