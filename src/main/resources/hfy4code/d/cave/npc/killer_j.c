 inherit NPC;
#include <ansi.h> 
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
        set_name("������", ({ "killer j" }) );
        set("title",HIC"����ɱ��"NOR);
        set("gender", "����" );
        set("age", 42);
        set("long",
                "���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
        set("attitude", "friendly");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("class","assassin");
        set("force",500);
        set("max_force",500);
        set("force_factor",30);
        
        set_skill("unarmed",150);
        set_skill("flame-strike",150);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("sharen-sword",150);
        set_skill("three-sword",150);
        set_skill("jinhong-steps",140);
        set_skill("lefthand-sword",150);
        
        map_skill("unarmed","flame-strike");
        map_skill("dodge","jinhong-steps");
        map_skill("move","jinhong-steps");
        map_skill("parry","three-sword");
        map_skill("sword","sharen-sword");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
           (: smart_fight() :),    
        }) );       
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
} 
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->query_temp("till_death/lockup"))
                        {
                                this_object()->smart_busy();
                        } else  if (enemy[i]->is_busy()) 
                                        this_object()->smart_attack();
                          else {
                                command("enable sword lefthand-sword");
                                this_object()->perform_action("sword.duxin"); 
                                command("enable sword sharen-sword");
                        }
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.canglongzhaxian");
}
smart_attack() {
        this_object()->perform_action("sword.sharenruma");      
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
