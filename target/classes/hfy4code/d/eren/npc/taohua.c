#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;
//inherit SMART_NPC; 
void create()
{ 
        set_name("�һ�����",({"taohua","niangzi","taohua niangzi"}));
        set("title",YEL"÷��������"NOR);
        set("long", "�����������ϵı��飬�������۾������ֳ��Թ��֮ɫ����������˭���ܿ��ó��ġ���\n");
        set("age",39);
        set("gender", "Ů��");
        set("combat_exp", 12000000);
         set("attitude", "aggressive");
             set("reward_npc", 1);
        set("difficulty", 35); 
        set("no_busy",9);
        set("class", "mei"); 
         set_skill("literate", 150);
    set_skill("force", 200);
    set_skill("spells", 280);
    set_skill("move", 200);

    set_skill("unarmed", 150);
    set_skill("tenderzhi",160);
    set_skill("sword", 200);
    set_skill("qiuzhi-sword", 220);
    set_skill("iron-cloth", 180);
    set_skill("parry", 160);
    set_skill("dodge", 200);
    set_skill("xuanxinjue", 200);
    set_skill("liuquan-steps", 160); 

    map_skill("iron-cloth", "xuanxinjue");
    map_skill("unarmed", "tenderzhi");
    map_skill("sword", "qiuzhi-sword");
    map_skill("parry", "qiuzhi-sword");
    map_skill("force", "xuanxinjue");
    map_skill("spells", "xuanxinjue");
    map_skill("dodge", "liuquan-steps");  
    map_skill("move", "liuquan-steps");  
    
    

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
     	        (: cast_spell, "xuanxinzhenfa" :),
     	        (: cast_spell, "xuanxinzhenfa" :),
     	        (: cast_spell, "xuanxinzhenfa" :),
                (: perform_action, "unarmed.qiankun" :),
        }) );
        setup();
    set_temp("apply/dodge", 200);
    set_temp("apply/armor", 300); 
    add_temp("apply/iron-cloth", 180);
    
        set_temp("xuanxinaomiao",1);

        
        set("max_atman", 2000);
        set("atman", 2000);
        set("max_mana", 2000);
        set("mana", 2000);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
   
         
        CHAR_D->setup_char(this_object());
       // auto_npc_setup("liaoyin",250,200,1,"/obj/weapon/","fighter_w","tanzhi-shentong");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}  
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        object another;
        message("vision",name() + "̾�˿������ֳ���һ�����ϸɿݵ����ᡣ\n", environment(),
                this_object() );
        another = new(__DIR__"liaoyin");
        another->move(environment(this_object()));
        destruct(this_object());
}     

void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/�һ�����_ma", 1);
        }
        
        ::die(); 
}