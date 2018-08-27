#include <ansi.h>
inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name( "����ǹ", ({ "shen yinqiang", "shen" }) );
        set("long", "�ھ������ġ�������ǹ����һ�����룬һ�ֳ�һ������ɫ�ĳ�ǹ��\n");
        set("attitude", "friendly");
        set("title", HIY "������ǹ"NOR);
        set("age", 57);
        set("gender", "����" );
        set("cor", 40);
        set("cps", 25);
        set("per", 60);
        set("combat_exp", 2900000);
        set("class","fugui");
        set("reward_npc", 1);
        set("difficulty", 3);
        
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
        set("force",1000);
        set("max_force",1000);
        set("force_factor",30);
        
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/kee",30);
                }
        
        set_skill("move", 160);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("unarmed", 150);
        set_skill("skyforce",150);
        set_skill("iron-cloth", 120);
        set_skill("spear", 200);
        set_skill("xuezhan-spear",130);
        set_skill("hawk-steps",150);
        set_skill("lingxi-zhi",150);
        set_skill("henglian",100);
        
        map_skill("iron-cloth","henglian");
        map_skill("force", "skyforce");
        map_skill("parry","xuezhan-spear");
        map_skill("spear","xuezhan-spear");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps"); 
        map_skill("unarmed","lingxi-zhi");     
        
        setup();
        carry_object("obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/silver_spear")->wield();
        add_money("gold", random(5));
} 
smart_fight()
{
        int i,j;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        for(j=0;j<sizeof(enemy);j++)
        {
                if (enemy[j]->is_zombie() && random(2))
                {
                        this_object()->perform_action("spear.zombie-wp1");
                        return;
                }               
        }
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<this_object()->query("combat_exp")*3/2) {
                           this_object()->smart_busy();
                        }
                        if (enemy[i]->is_busy()) {
                                        this_object()->smart_attack();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.yingjichangkong");
}
smart_attack() {
        this_object()->perform_action("spear.bafangfengyu");    
        } 
