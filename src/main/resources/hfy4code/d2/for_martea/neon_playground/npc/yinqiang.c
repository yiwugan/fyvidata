 inherit NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
        set_name("����ǹ", ({ "shen yinqiang" }) );
        set("gender", "����");
        set("age", 18);
        set("long",
"��λ�������������������㣬�����д��ž��ȣ�Ҳ����������\n"
);
        set("inquiry", ([
            "�����" : (: kill_him :),
             "��ź�" : (: fanghe :),
              "������" : (: peiyu :),
   ]));
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ǹЦ�����������޼��ŵ���������������С����������ģ���\n",
                "����ǹ�����õط�ѽ�õط���\n",
        }) );
          
        set("attitude", "friendly");
        set("title","����");
        set("nickname", HIW"������ǹ"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",5);
        set("class","fugui");
        
        set("combat_exp", 4500000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",50);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("skyforce", 150);
        set_skill("hawk-steps",150);
        set_skill("eagle-claw",150);
        set_skill("xuezhan-spear",140);
        
        map_skill("unarmed","eagle-claw");
        map_skill("force", "skyforce");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps");
        map_skill("parry","xuezhan-spear");
        map_skill("spear","xuezhan-spear");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(2));
        carry_object("/obj/weapon/spear")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
 
int kill_him()
{
        object me;
        me = this_player();
        command("say ������֪�����治�٣��� \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
} 
int fanghe()
{
    command( "say �ź������������޼��ŵ������ˡ�");     
    return 1;
}  
int peiyu()
{
    command ("say ��С���������ֲ��ɲĵĶ��ӡ�");
    return 1;
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
                        if (enemy[i]->is_busy()) {
                                this_object()->smart_attack();
                        }
                }
   }
} 
smart_busy() {
        this_object()->perform_action("dodge.yingjichangkong");
}
smart_attack() {
        this_object()->perform_action("spear.bafangfengyu");    
        }
