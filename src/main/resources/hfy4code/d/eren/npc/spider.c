#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("long", "һ�������С�ĺ����ˣ�����ȫ��һ����������Ľ����·�������ס��һ����Ҳ
������ڵ���ߣ�ֻʣ��һ˫�ڰ׷��������ӣ��ڵĵط����ᣬ�׵ĵط���ѩ��\n");
        set("age",25);
        set("combat_exp", 1000000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",30);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",150,125,1,"/obj/weapon/","fighter_w","lefthand");
        set_name("��֩��",({"spiderman"}));
        set("force_factor",40);
        setup();
        carry_object(__DIR__"obj/darkcloth")->wear();
}        
