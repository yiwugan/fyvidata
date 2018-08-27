 inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("�ض�����", ({ "guandong haoke", "haoke" }) );
        set("gender", "����" );
        set("age", 32+ random(10));
        set("long", "����һλ�Ӱ�ɽ��ˮ���Ĵ󺺣����´���һȺ�������ˡ�\n");
        set("combat_exp", 3200000);
        set("attitude", "aggrensive");
        set("class","knight");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ض��󺺺�ˬ�������Ц��\n",
        }) );
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );
        
        set("force",1200);
        set("max_force",1200);
        set("force_factor", 30);
              
        set_skill("unarmed", 180);
        set_skill("force", 180);
        set_skill("longlife-force", 140);
        set_skill("axe", 150);
        set_skill("xuanyuan-axe", 150);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("move", 180);
        set_skill("windy-steps", 160);
        set_skill("hanshan-strike", 200);
        
        map_skill("dodge", "windy-steps");
        map_skill("unarmed", "hanshan-strike");
        map_skill("force", "longlife-force");
        map_skill("axe", "xuanyuan-axe");
        map_skill("parry", "xuanyuan-axe");
        
        setup();
        add_money("gold", 2);
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/xuechang");
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
                        if (enemy[i]->is_busy()) {
                                this_object()->smart_attack();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.fengliu");
}
smart_attack() {
        this_object()->perform_action("unarmed.zhangjian");     
        }    
