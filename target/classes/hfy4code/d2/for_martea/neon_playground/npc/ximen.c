 inherit NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu(); 
void create()
{
        set_name("���ŷ�", ({ "ximen feng" }) );
        set("gender", "����");
        set("age", 65);
        set("long",
"��λ�ų������µ�һ���������������������㣬������
���ž��ȣ�Ҳ������������\n" );
        set("inquiry", ([
            "�����" : (: kill_him :),
             "��ź�" : (: fanghe :),
              "������" : (: peiyu :),
   ]));
      
        set("chat_chance", 1);
        set("chat_msg", ({
                "���ŷ�Ц�����������޼��ŵ���������������С����������ģ���\n",
                "���ŷ�����ò�ѽ�ò裡\n",
        }) );
          
        set("attitude", "friendly");
        set("title",HIY"éɽ"NOR);
        set("nickname",HIY"�����޹�"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",10);
        set("class","lama");
        
        set("combat_exp", 2500000);        
        set("int", 40);
        set("cps", 20);
        set("spi", 30);
        set("fle",100);
        
        set("force", 2000);
        set("max_force",2000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action("unarmed.fefawubian") :),
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic",150);
                
          
        set_skill("bloodystrike", 200);
        set_skill("iron-cloth",1000);
        
        map_skill("unarmed","bloodystrike");
        map_skill("iron-cloth","xisui");
        
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(5));
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
