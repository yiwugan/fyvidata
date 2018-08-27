 inherit NPC;
void use_poison(); 
void create()
{
        set_name("����", ({ "snake" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һ��ȫ����̵Ķ��ߡ�\n");
        set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        
        set("max_kee",2400);
        set("max_gin",1800);
        set("max_sen",1800);
        
        set("death_msg",          "����ʹ���Ť���˼��£�ȫ�������ɢ�˿�����\n\n"  );
        set("leave_msg",          "ವ�һ�����˳�ȥ"                     );
        set("arrive_msg",         "���ѵ����˹���"                              );
        set("fleeout_message",    "ವ�һ������$d���˳�ȥ"                      );
        set("fleein_message",     "���������˹����������ǵ��ڵ���ſ�š�\n"          );
        
        
        set("combat_exp", 1200000);
        set("bellicosity", 300 );
        set_skill("dodge", 200);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup(); 
} 
void use_poison()
{
        object *enemy, ob;
        string msg; 
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
        tell_object(ob,"��������Ͼ�ʹ������һ��������������ӡ�ۡ�\n");
                ob->receive_wound("kee",40);
                ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(3)+3);
}      
