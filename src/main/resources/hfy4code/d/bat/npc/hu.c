 // hu.c
inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name("������", ({ "hu tiehua","hu" }) );
        set("title",HIB "�޾�����" NOR);
        set("gender", "����" );
        set("age", 35);
        set("str", 50+random(30));
        set("int", 20);
        set("cor", 40);
        set("no_heal",1); 
    set("long",
"
���⣬������������Ҳҵĺ����ӣ�Ҳ�������������������Ц�ݣ�
һ˫�ֺ������Ĵ��۾�, �����ǳ�������õ����Ѻ����������������ӡ�
\n"
    );
        set("max_gin", 5000);
        set("eff_gin", 5000);
        set("gin", 5000);
        set("max_kee", 10000);
        set("eff_kee", 8000);
        set("kee", 8000);
        set("max_sen", 6000);
        set("eff_sen", 6000);
        set("sen", 6000);
        
        set("combat_exp", 5000000);
        set("attitude", "friendly");
        
        set_skill("move",300);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("fengyu-piaoxiang",200);
        set_skill("luoriquan",220);
        set_skill("perception",200);
        
   map_skill("unarmed","luoriquan");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "������˵������������ƽ����Ȯ��ѽ ��\n",
                "������ĬȻ���Σ�˵������֪�ϳ������������� ��\n",
                }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: perform_action, "unarmed.luori" :),
        (: perform_action, "dodge.zonghengsihai" :),
        }) );
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
} 
void die()
{
        int i;
        object killer,owner;
        if(objectp(killer = query_temp("last_damage_from")))
        if(owner=killer->query("possessed")) {
                killer=owner;
        } 
        killer->set_temp("marks/murderhu", 1);
        ::die(); 
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill");
    
} 
int do_killing(string arg)
{
    object player, victim;
    string id;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id=victim->query("id");
        if(victim == this_object())
        {
            message_vision(HIW
"$NЦ����������ԭ���ƵĽ赶ɱ��֮���ˣ������������ң�����������̽��ʵ��\n"NOR, this_object());
            return 0;
        } 
    }
    return 0;
}  
