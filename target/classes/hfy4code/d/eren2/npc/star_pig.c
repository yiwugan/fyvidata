#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("age",30+random(20));
        set("attitude", "aggressive");
        set("combat_exp", 5500000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 3000);
        set("atman", 3000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("max_force",4000);
        set("force",4000);
        set("force_factor",80);
        
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
        
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",250,200,0,"/d/eren2/npc/obj/","fighter_u","yue-strike");
        set_name("黑面神君",({"heimian"}));
           set("title",HIG"十二星象"NOR);
        set("long", "“十二星象“中的“猪“，此人身长不足五尺，瘦小枯干，却穿着一
身火红的衣裳，那模样正有说不出的诡秘，说不出的猥琐。。\n");
        
        setup();
        carry_object(__DIR__"obj/j_cloth")->wear();
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
        
        if( !ob || environment(ob) != environment() ) return;
        message_vision(CYN"$N舔了舔嘴说：哼哼，肥羊。\n"NOR,this_object());
}  
