#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("��ʦ", ({"da fashi","fashi"}) );
        set("gender", "����" );
        set("class", "taoist");
        set("nickname", HIR"ʳ������"NOR);
        set("long", "һ��̬�Ⱥ���������ˣ����Ŷ�Բ���Ķ�ǩ��һ��Ѫ������ĳ���\n���أ�ѩ�׵ĺ���ʹ���������������𾴡�\n");
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 10); 
        set("fly_target",1);
        set("cor", 35);
        set("cps", 3);
        set("age", 54);
        set("atman", 1000);
        set("max_atman", 1000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("mana_factor", 100);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "invocation" :),
            (: cast_spell, "drainerbolt" :),
        }) );
        set("combat_exp", random(800000)+2500000);
        
        set_skill("spells", 200);
        set_skill("necromancy", 150);
        set_skill("blade", 160);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("move", 160);
        set_skill("unarmed",100);
        set_skill("flame-strike",100);
        set_skill("notracesnow", 150);
        
        map_skill("spells", "necromancy");
        map_skill("dodge","notracesnow");
        map_skill("unarmed", "flame-strike");
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "��ʦ�ٺ�Ц����С������ⲻ���óԣ������̲��úܡ�\n",
        }) );
        set_temp("apply/armor", 50);
        setup();
        carry_object(__DIR__"obj/cassock")->wear();
        carry_object(__DIR__"obj/hat")->wear();
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
        if( !query_heart_beat(this_object()) ) {
                set_heart_beat(1); 
        }
} 
void greeting(object ob)
{   
        if (ob->query("gender") == "Ů��")
        {
                message_vision("$N���ſ�ˮ������$n����ϸƤ����ģ��ظ�һ���ܺóԡ���\n", this_object(),ob );
                this_object()->kill_ob(ob);
        }
        return;
} 
