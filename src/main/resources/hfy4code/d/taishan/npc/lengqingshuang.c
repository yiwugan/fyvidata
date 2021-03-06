 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("冷青霜", ({ "leng qingshuang" }) );
        set("title",HIG "寒枫堡" NOR);
        set("gender", "女性");
        set("age", 28);
        set("long",
"一个手撑湘妃竹伞的白衣女子。\n"
);
        set("inquiry", ([
               
        ]) );
       
        set("chat_chance", 1);
        set("chat_msg", ({
                "冷青霜看着长长叹息：“二妹，难道你也爱上了大旗门下的弟子，
难道你没有看到姐姐我的榜样？”\n",
        }) );
       
        set("attitude", "friendly");
        set("score", 200);
        set("class", "huashan");
        set("reward_npc", 1);
        set("difficulty", 1);
        set("resistance/kee",20);
        
        set("combat_exp", 2000000);        
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("per",50);
        set("str",26); 
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 80);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 300);
        set("max_mana", 300);
        
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
          
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
        set_skill("sword",150);
                
        set_skill("qingfeng-sword",150);            
        set_skill("hanmei-force", 150);
        set_skill("anxiang-steps",140);
        set_skill("zhaixin-claw",120);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("sword","qingfeng-sword");
        map_skill("parry","qingfeng-sword");
        map_skill("dodge","anxiang-steps");
        map_skill("move","anxiang-steps");
        
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(5));
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
 
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.yexuechuji");
}
