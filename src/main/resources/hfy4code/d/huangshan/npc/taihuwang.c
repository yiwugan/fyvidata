 inherit NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();
void smart_fight(); 
void create()
{
        set_name("������", ({ "wang zhenxiang" }) );
        set("gender", "����");
        set("age", 55);
        set("long",
"̫����ʮ�Ķ���ܶ��������������ү�ӡ�\n"
);
        set("inquiry", ([
            "�����" : (: kill_him :),
             "��ź�" : (: fanghe :),
              "������" : (: peiyu :),
   ]));
                        
        set("chat_chance", 1);
        set("chat_msg", ({
                "������Ц�����������޼��ŵ���������������С����������ģ���\n",
                "����������õط�ѽ�õط���\n",
        }) );
          
        set("attitude", "friendly");
        set("title","̫����");
        set("nickname", HIG"ˮ�ϴ��"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",5);
        set("class","yinshi");
        set("fly_target",1);
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
        set("combat_exp", 4000000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",50);
        set("str",36);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 100);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        set("chat_chance_combat", 100);
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
        set_skill("whip",200);        
        set_skill("qidaoforce", 150);
        set_skill("five-steps",180);
        set_skill("thunderwhip",180);
        set_skill("pofeng-strike",180);
                
        map_skill("unarmed","pofeng-strike");
        map_skill("force", "qidaoforce");
        map_skill("dodge","five-steps");
        map_skill("move","five-steps");
        map_skill("whip","thunderwhip");
        map_skill("parry","thunderwhip");
        
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(3));
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/w_whip")->wield();
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
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1 && enemy[1]->is_zombie()) {
                who->perform_action("whip.zombie-wp1");
                return;
        }
        who->perform_action("whip.tianleiyiji"); 
        return;
}  
