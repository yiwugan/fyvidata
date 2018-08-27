 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("�����", ({ "killer g" }) );
        set("title",HIC"����ɱ��"NOR);
        set("gender", "����" );
        set("age", 42);
        set("long",
                "���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
        set("attitude", "friendly");
        set("combat_exp", 1400000);
        set("attitude", "friendly");
        set("class","assassin");
        set("force",1000);
        set("max_force",1000);
        set("force_factor",50);
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "spear.zonghengtianxia" :),
        }) ); 
        set_skill("flame-strike",150);
        set_skill("move", 100);
        set_skill("force", 100);
        set_skill("spells", 100);
        set_skill("unarmed", 100);
        set_skill("spear", 150);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("manjianghong", 100);
        set_skill("yue-spear",120);
        set_skill("puti-steps",160);
        set_skill("cursism", 100);
        set_skill("necromancy", 100);     
        map_skill("spells", "necromancy");
        map_skill("force", "manjianghong");
        map_skill("spear","yue-spear");
        map_skill("dodge","puti-steps");
        map_skill("parry","yue-spear");
        map_skill("move","puti-steps");
        map_skill("unarmed","flame-strike"); 
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/spear")->wield();
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
