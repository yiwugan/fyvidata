 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("��ľ�", ({ "killer h" }) );
        set("title",HIC"����ɱ��"NOR);
        set("gender", "����" );
        set("fle",100);
        set("age", 42);
        set("long",
                "���˺ڲ����棬����ڵĿӵ���ֻ�б��������⡣\n");
        set("attitude", "friendly");
        set("combat_exp", 1400000);
        set("attitude", "friendly");
        set("class","taoist"); 
        set("max_mana",1000);
        set("mana",1000); 
        set("sen",2000);
        set("max_sen",2000);
        set("eff_sen",2000);
        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "invocation" :),
        }) ); 
        set_skill("move", 150);
        set_skill("force", 200);
        set_skill("spells", 100);
        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("gouyee", 120);
        set_skill("notracesnow",120);
        set_skill("taoism", 120);
        set_skill("necromancy", 100);            
        set_skill("snowshade-sword",120); 
        map_skill("force", "gouyee");
        map_skill("unarmed","tenderzhi");
        map_skill("dodge","notracesnow");
   map_skill("spells", "necromancy");
        map_skill("parry", "snowshade-sword");
        map_skill("sword", "snowshade-sword"); 
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
