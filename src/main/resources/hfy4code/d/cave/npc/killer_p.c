 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("ص����", ({ "killer p" }) );
        set("title",HIC"����ɱ��"NOR);
        set("gender", "����" );
        set("age", 42);
        set("long",
                "���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
        set("attitude", "friendly");
        set("combat_exp", 1600000);
        set("attitude", "friendly");
        set("class","wudang");
        set("force",1000);
        set("max_force",1000);
        set("force_factor",30);
        
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("blade",150);
        set_skill("taiji-sword",150);
        set_skill("five-steps",150);
        set_skill("move",150);
        set_skill("sword",150);
        set_skill("taiji",150);
        
        map_skill("dodge","five-steps");
        map_skill("move","five-steps");
        map_skill("sword","taiji-sword");
        map_skill("parry","taiji-sword");
        map_skill("unarmed","taiji");
        
/*      set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action("sword.chanzijue") :),    
        }) ); */ 
        setup();
        
   carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
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
