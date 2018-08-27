 inherit NPC;
#include <ansi.h> 
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
        set_name("Σ����", ({ "killer k" }) );
        set("title",HIC"����ɱ��"NOR);
        set("gender", "Ů��" );
        set("age", 42);
        set("long",
                "���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
        set("attitude", "friendly");
        set("combat_exp", 1400000);
        set("attitude", "friendly");
        set("class","huashan");
        set("force",200);
        set("max_force",200);
        set("force_factor",30);
        
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("throwing",150);            
        set_skill("hanmei-force", 100);
        set_skill("tanzhi-shentong",100);
        set_skill("anxiang-steps",120);
        set_skill("zhaixin-claw",120);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("throwing","tanzhi-shentong");
        map_skill("dodge","anxiang-steps");
        map_skill("move","anxiang-steps");
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/dart")->wield();
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
                                && enemy[i]->query("combat_exp")<3*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                }
        }
} 
smart_busy() {
        this_object()->perform_action("throwing.tanzhijinghun");
}
smart_attack() {
        this_object()->perform_action("throwing.mantianhuayu"); 
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
        message("vision",
                HIW + name() + "һ�����ںڰ�����ʧ�ˡ�\n" NOR, environment(),
                this_object() );
        destruct(this_object());
}  
void init()
{
    object ob;
    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) 
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
} 
void greeting(object ob)
{   
        string where, location;
        if( !interactive(ob) || environment(ob) != environment() )
                return;
        if (!ob->query("vendetta/authority") ){
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
}  
