#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("title","��������");
        set("long", "һ�����ҵĵ��ˣ���������ͨ��ǣ�˫üб�����ޡ�\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 4500000);
        set("wimpy",50); 
                
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",30);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "������̾�������������Ե��������书֮ǿǿ�����£�ƶ���������ţ�
������һ������������������",
                
        }) );
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,170,1,"/d/eren2/npc/obj/","fighter_w","softsword");
        set_name("������",({"zang yizi"}));
        set("force_factor",80);
        setup();
        carry_object("/obj/armor/cloth")->wear();
   
}     
