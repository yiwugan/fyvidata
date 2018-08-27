#include <ansi.h>
inherit SMART_NPC;
void create()
{  
        set("attitude", "friendly"); 
        set("combat_exp", 5000000);
        set("dungeon_npc","eren2");
        
        set("max_atman", 3000);
        set("atman", 3000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("max_force",4000);
        set("force",4000);
        set("force_factor",60);
        
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
        
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
        
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",250,200,1,"/d/eren2/npc/obj/","all","all");
        set_name("������", ({ "maskman"}) );
        set("long", "���˴�����ߣ���ɫ������һ��ز԰ס�\n");
        setup();
   carry_object(__DIR__"obj/w_cloth")->wear();
}   
void die()
{
        if(environment(find_living("xiao mimi")))
        {
                message_vision(HIR "\n\n�����俩����Ц���Ӹߴ�������$Nһ���飬������������\n\n"NOR,this_object());
                receive_curing("gin",5000);
                receive_curing("kee",10000);
                receive_curing("sen",5000);
                receive_heal("gin",5000);
                receive_heal("kee",10000);
                receive_heal("sen",5000);
                COMBAT_D->report_status(this_object(),1);
                return;
        }
        else    ::die();
        return;
}  
