#include <ansi.h>
inherit SMART_NPC; 
void special_smart_fight(); 
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("long", "�⺢������üĿ���㣬��ȴ��Ƽ��ݣ����Ƿ�����ȫ��ģ����������
����ʮ�����ꡣ�����Ų��ӣ����ű���һ˫�۾���ȴ�ֲ�ʱ͵͵����
��ǰ����ȥ��\n"); 
        set("age",16);
//      set("attitude", "aggressive");
        
        set("combat_exp", 5500000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 1500);
        set("atman", 1500);
        set("max_mana", 1500);
        set("mana", 1500);
        set("max_force",3000);
        set("force",3000);
        set("force_factor",60);
        
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: special_smart_fight() :),    
        }) );
        set_temp("apply/move",200); 
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",250,220,1,"/d/eren2/npc/obj/","fighter_u","wolf-claw");
        set_name("������",({"jiang yulang"}));
   setup();
        
        carry_object(__DIR__"obj/g_armor")->wear();
} 
void special_smart_fight(){
        
        object ob, room;
        
        ob=this_object();
        if (ob->query("kee")<ob->query("max_kee")/3
                || ob->query("sen")<ob->query("max_sen")/3
                || ob->query("gin")<ob->query("max_gin")/3) {
                message_vision("$N˵����Ӣ�ۡ�������������������\n",ob);
                message_vision("$N������Ķ����ˡ�\n",ob);
                ob->remove_all_killer();
                room=find_object(AREA_EREN2"innerroom");
                if(!objectp(room)) 
                        room = load_object(AREA_EREN2"innerroom"); 
                ob->move(room);
        }
        auto_smart_fight();
}       
            
