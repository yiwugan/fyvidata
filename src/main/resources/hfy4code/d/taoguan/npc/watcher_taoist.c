 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("���羰�ĵ���", ({ "wandering taoist" }) );
        set("gender", "Ů��");
        set("age", 32);
        set("long",
"һ���пɶ��ĵ��ã���һ���ɫ�ĵ��ۣ��������յ��ں��Ͽ��羰��\n"
);
        set("combat_exp", 21000);
        set("score", 200);
        set("class", "taoist");
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5); 
        set("inquiry", ([
                "�����": 
"�ڹ����ƾ��ˣ�����ɢɢ�ģ�������Ǹ��õط�����\n",
        ]) );
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "invocation" :),
        }) ); 
        create_family("���幬", 7, "����"); 
        set_skill("move", 20);
        set_skill("force", 20);
        set_skill("spells", 30);
        set_skill("unarmed", 40);
        set_skill("notracesnow",30);
        set_skill("sword", 40);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("gouyee", 50);
        set_skill("necromancy", 30);    
        set_skill("snowshade-sword",30);
   
        map_skill("sword","snowshade-sword");
        map_skill("parry","snowshade-sword");
        map_skill("dodge","notracesnow");
        map_skill("spells", "necromancy"); 
        set_temp("apply/dodge", 25);
        set_temp("apply/armor", 25); 
        setup(); 
        add_money("coin", 10);
        carry_object(__DIR__"obj/sword1")->wield();
        carry_object(__DIR__"obj/tcloth")->wear(); 
}  
void init()
{       
        ::init();
        add_action("do_killing", "kill");
} 
int do_killing(string arg)
{
    object player, victim;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        if(userp(victim)&& victim!=player)
        {
            message_vision(HIW"$N����$n�ȵ����ѵó���ɢɢ�ģ���Ȼ������С�ӻ�������!\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
