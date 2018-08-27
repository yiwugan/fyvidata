 inherit NPC;
#include <ansi.h>
int kill_him(); 
void    smart_fight(); 
void create()
{
        set_name("л����", ({ "xie changqing" }) );
        set("gender", "����");
        set("age", 25);
        set("long",
"һ�������Ӣ�������꣬�������ڲ����ţ�Ӣ���������ϣ�Ҳ����
һ������֮ɫ����\n"
);
      
        set("chat_chance", 1);
        set("chat_msg", ({
"л�����૵������һ����ᣬ�Ҳ��ܾ�����������Ϣ����ȥ��������ʱ
�����������ˣ���ʹ����������֮�£�����˭�ᴫ����ȥ����������
���˶���Ϊ�Լ�����ɡ���\n",
        }) ); 
        set("inquiry", ([
            "÷ɽ��" : (: kill_him :),
            "mei shanmin" : (: kill_him :),
             ]));
        set("fly_target",1); 
        set("attitude", "friendly");
        set("title",HIG"���"NOR);
        set("nickname", HIG"��Ӣ��"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",2);
        set("class","legend");
        
        set("combat_exp", 3500000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",60);
        set("per",40);
        set("str",40);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 90);
        set("atman", 1000);
        set("max_atman", 1000);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),              
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("qidaoforce", 150);
        set_skill("fall-steps",150);
        set_skill("meihua-shou",150);
        set_skill("diesword",150);
        
        map_skill("unarmed","meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("parry","diesword");
        map_skill("sword","diesword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(5));
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
 
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy() && random(3)
                                && enemy[i]->query("combat_exp")<10*this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                        if (!this_object()->is_busy()) {
                                this_object()->smart_attack();
                        } 
                }
        }
} 
smart_busy() {
        command("unwield sword");
        this_object()->perform_action("unarmed.meihai");
        command("wield sword");
        return;
}
smart_attack() {
        this_object()->perform_action("sword.caidiekuangwu");
        return;
} 
int kill_him()
{
        object me;
        me = this_player();
        if (this_object()->is_fighting()) return 1;
        message_vision(CYN"л�������˰���˵:������ƽ���֮��....\n"NOR,this_object());
        message_vision(CYN"л����ͻȻ�������г���������Ƭ�̣���Ȼ�ӽ���������һ��������δЪ��
�������֣����ǡ�������һ����ֻ����˫����Ѫ���죬��ֻ��ķָ������ϣ���
����ʳ��ָ���ų�������һ��������Ӣ��������һȦ����ֱ�ɶ��������ˡ���һ
�����������ϣ���������С��ؽ�������ҡ��ε�������ͷҲ���ص�ȥ�ˡ�\n"NOR,this_object());
        me->set("marks/л����",1);
        destruct(this_object());
        return 1;
} 
