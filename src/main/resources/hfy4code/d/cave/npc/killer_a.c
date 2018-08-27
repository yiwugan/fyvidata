 inherit NPC;
#include <ansi.h> 
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
        set_name("�����", ({ "killer a" }) );
        set("title",HIC"����ɱ��"NOR);
        set("gender", "����" );
        set("age", 42);
        set("long",
                "���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
        set("attitude", "friendly");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("class","bat");
        set("force",500);
        set("max_force",500);
        set("force_factor",10);
        
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("blade",150);
        set_skill("bat-blade",110);
        set_skill("meng-steps",110);
        set_skill("move",200);
        set_skill("blade",150);
        set_skill("luoriquan",150);
        
        map_skill("dodge","meng-steps");
        map_skill("move","meng-steps");
        map_skill("blade","bat-blade");
        map_skill("parry","bat-blade");
        map_skill("unarmed","luoriquan");
        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();
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
        this_object()->perform_action("dodge.huanyinqianchong");
}
smart_attack() {
        this_object()->perform_action("blade.shiwanshenmo");    
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
