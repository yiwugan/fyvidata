#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER; 
void create()
{
        set_name("李燕北", ({ "li yanbei", "li" }) );
        set("gender", "男性" );
        set("nickname",HIC"仁义满京华"NOR); 
        set("age", 43);
        set("int", 21);
        set("per", 20);
        set("str", 40);
        set("dur", 50);
        set("cor", 35);
        set("long",
"李燕北身高八尺—寸，魁伟强壮，精力充沛，浓眉、锐眼、鹰
鼻、严肃的脸上，总是带著种接近残酷的表情，看来就像是条
刚从原始山林中窜出来的豹子。\n");
        set("force_factor", 30);
        set("max_gin", 1400);
        set("max_kee", 3200);
        set("max_sen", 1700);
                set("max_force",2000);
                set("force",2000); 
        set("combat_exp", 1500000);
        set("score", 15000);
        set_skill("unarmed", 150);
        set_skill("force", 120);
        set_skill("parry", 140);
        set_skill("literate", 50);
        set_skill("dodge", 140); 
                
     
//        set("chat_chance_combat", 40);
//        set("chat_msg_combat", ({
//                (: perform_action,"spear.qingheluo":),
//        }) );
        setup();
        carry_object(__DIR__"obj/zimagua")->wear();
   add_money("gold",8);
}
/*
object offensive_target(object me)
{
        int sz;
        object *enemy; 
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0; 
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4; 
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}  
*/    
