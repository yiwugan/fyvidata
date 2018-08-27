#include <ansi.h>
inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
    set_name("ëս", ({"mao zhan","mao"}) );
    set("gender", "����" );
    set("nickname", BLU"��ͷ��"NOR);
    set("title", "������ �ֶ滤��");
    set("long", "�������ܳ���������������ϳ����������㶹��ĸ���۾��ﲼ��Ѫ˿��\n");
        set("attitude", "friendly");
        set("age", 35);
        set("cor", 25);
        set("cps", 25);
        set("per", 6);
        set("combat_exp", 3000000);
        set("class","bandit");
        
        set_temp("apply/armor", 100);
        set("force",1000);
        set("max_force", 1000);
        set("force_factor", 50);
        set("reward_npc", 1);
        set("difficulty", 3);
        
        set_skill("unarmed",200);
        set_skill("dragonstrike",200);
        set_skill("blade", 200);
        set_skill("moon-blade", 100);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("demon-steps",150);
        
        map_skill("blade", "moon-blade");
        map_skill("parry","moon-blade");
        map_skill("dodge","demon-steps");
        map_skill("move","demon-steps");
        map_skill("unarmed","dragonstrike");
        
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "ëս������ͻȻЦ������������Ц����ͣ������¾�Ȼ��\n����ɵ��ϲ����һ��٪��ϹŮ�ˡ���\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/duanblade")->wield();
        carry_object("/obj/armor/cloth")->wear();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
                else add_money("gold", random(3));
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
        if( !interactive(ob) || environment(ob) != environment() )
                return;
        if (!ob->query("vendetta/authority")){
            message_vision("$N�ٺٵ�����������˽��������ĵ�ͷ���������ɣ�\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
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
                        if (enemy[i]->query_skill("iron-cloth")>200 
                                && this_object()->query_temp("weapon")) {
                                command("say ��Ӳ��!���ҵĽ���ʮ����������!");
                                command("unwield all");
                        } else if (enemy[i]->query_skill("iron-cloth")<200)
                                command ("wield blade");
                }
        }
} 
smart_busy() {
        this_object()->perform_action("blade.kuaidao");
}     
