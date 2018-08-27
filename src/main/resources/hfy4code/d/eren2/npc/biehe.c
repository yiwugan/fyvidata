#include <ansi.h>
inherit SMART_NPC; 
void special_smart_fight(); 
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("long", "����ü��Ŀ�㣬�����������Ц�����������˸��������Ѽ���\n");
        set("title",HIG"���ϴ���"NOR);
        set("age",46);
        set("attitude", "friendly");
        
        set("combat_exp", 10000000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 5000);
        set("atman", 5000);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_force",10000);
        set("force",10000);
        set("force_factor",80);
        
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
        auto_npc_setup("guardian",250,200,1,"/d/eren2/npc/obj/","fighter_w","doomsword");
        set_name("�����",({"jiang biehe"}));
        setup();
   
        carry_object(__DIR__"obj/g_armor")->wear();
        carry_object(__DIR__"obj/key");
}  
        
void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
}  
void greeting(object ob) {
        
        object son;
        if( !ob || environment(ob) != environment() ) return;
        if (son=present("jiang yulang",environment(ob))) {
                message_vision("$Nһ����˵��С������������֪�����´��ⲻ���ˡ�\n",this_object());
                message("vision","������˵������λ����Ī�֣�С�Ӹղ��ǿ���Ц�ġ���\n",environment(ob));
        }
}  
