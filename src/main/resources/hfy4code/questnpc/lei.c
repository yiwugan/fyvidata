#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
do_fight();
void create()
{
        set_name("小雷", ({ "lei" }) );
        set("gender", "男性" );
    	set("nickname",RED"我要活下去"NOR);
    	set("title","风雷山庄");
        set("age", 23);
        set("int", 29);
        set("npc_difficulty",6);
        set("organization/性质","正");
        set("class","legend");
        set("per", 30);
        set("str", 32);
        set("dur", 30);
        set("cor", 50);
//  create_family("铁雪山庄", 2, "弟子");
        set("long",
"他脸上流着血，流着汗，全身的骨骼都似已将因痛苦而崩散。\n"
                );
        set("force_factor", 100);
        set("max_gin", 30000);
        set("max_kee", 110000);
        set("max_sen", 30000);
        set("max_force",20000);
        set("force",20000); 
        set("combat_exp", 30000000);
        set("score", 1200);
        set_skill("unarmed", 200);
        set_skill("blade", 300);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("literate", 80);
        set_skill("dodge", 200); 
    	set_skill("shortsong-blade", 180);
        set_skill("qidaoforce", 60);
    	set_skill("fall-steps",250);
    	set_skill("meihua-shou",180);
        
        map_skill("unarmed", "meihua-shou");
        map_skill("blade","shortsong-blade");
        map_skill("force", "qidaoforce");
        map_skill("parry", "shortsong-blade");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        set("chat_chance",10);
        set("chat_msg", ({
                "小雷咬紧牙关道“因为我还活着，一个人只要还活着，就得活下去。”\n"
                })      );  
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        	(: do_fight :),
                (:exert_function,"juqi":),
        }) );
        setup();
    	carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();
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
}  */
int accept_fight(object me)
{
        command("say 请出招！！");
        return 1;
}
do_fight()
{       
        command("perform dodge.luoyeqiufeng");
        command("perform duangechangmeng");
} 
        
              
