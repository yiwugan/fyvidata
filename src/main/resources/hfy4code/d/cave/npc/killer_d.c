 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("����¹", ({ "killer d" }) );
        set("title",HIC"����ɱ��"NOR);
        set("gender", "����" );
        set("age", 42);
        set("long",
                "���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
        set("attitude", "friendly");
        set("combat_exp", 1400000);
        set("attitude", "friendly");
        set("class","wolfmount");
        set("force",1000);
        set("max_force",1000);
        set("force_factor",30);
        
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("xueyeqianzong",150);
        set_skill("move",200);
        set_skill("wolf-strike",150);
                
        map_skill("dodge","xueyeqianzong");
        map_skill("move","xueyeqianzong");
        map_skill("unarmed","wolf-strike");
        
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action("unarmed.duanhou") :),    
        }) ); 
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
