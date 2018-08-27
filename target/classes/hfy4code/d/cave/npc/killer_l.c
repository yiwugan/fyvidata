 inherit NPC;
#include <ansi.h> 
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
        set_name("�һ���", ({ "killer l" }) );
        set("title",HIC"����ɱ��"NOR);
        set("gender", "����" );
        set("age", 42);
        set("long",
                "���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
        set("attitude", "friendly");
        set("combat_exp", 1300000);
        set("attitude", "friendly");
        set("class","shaolin");
        set("force",500);
        set("max_force",500);
        set("force_factor",30);
        
        set_skill("hammer", 150);
        set_skill("liuxing-hammer",150);
        set_skill("dodge",150);
        set_skill("move",180);
        set_skill("force",200);
        set_skill("puti-steps",150);
        set_skill("dabei-strike",150);
        
        map_skill("unarmed","dabei-strike");
        map_skill("dodge","puti-steps");
        map_skill("hammer", "liuxing-hammer");
        map_skill("parry","liuxing-hammer");
        
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
        setup();
        
   carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/shaolin/npc/obj/hammer")->wield();
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
                                && enemy[i]->query("combat_exp")<10*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                        if (enemy[i]->is_busy()) {
                                this_object()->smart_attack();
                        }
                }
        }
} 
smart_busy() {
        this_object()->perform_action("unarmed.qianshouqianbian");
}
smart_attack() {
        this_object()->perform_action("hammer.fanbei"); 
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
