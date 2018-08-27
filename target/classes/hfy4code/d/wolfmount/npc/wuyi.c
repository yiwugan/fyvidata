#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("������", ({ "chang wuyi","wuyi" }) );
        set("gender", "����");
        set("title", "��Ƥ��");
        set("age", 35);
        set("long","һ��ר�Ű���Ƥ��Ƥ���������۾���ͬ����һ������ġ�\n");
        set("combat_exp", 1000000);
        set("attitude", "heroism"); 
        set("con", 50);
        set("int", 20);
        set("agi", 20);
        set("cor", 40); 
        set("force", 900);
        set("max_force",900);
        set("force_factor",20); 
        set_temp("apply/attack",  40);
        set_temp("apply/dodge", 40);
        set_temp("apply/parry", 40); 
        set_skill("move", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("bai-quan",100);
        set_skill("literate", 100);
        set_skill("sword",100);
        set_skill("qingpingsword",120);
        set_skill("qingpingforce",100);
        set_skill("chaos-steps",100);
        set_skill("perception", 100);
            
        map_skill("force", "qingpingforce");
        map_skill("parry","qingpingsword");
        map_skill("sword","qingpingsword");
        map_skill("dodge","chaos-steps");
        map_skill("move","chaos-steps"); 
        map_skill("unarmed","bai-quan"); 
   
        setup();
        carry_object(__DIR__"obj/softsword")->wield();
        carry_object(__DIR__"obj/tigercloth")->wear(); 
} 
void die()
{
        object ob;
        object *enemy;
        ob = query_temp("last_damage_from");
        if(!ob)
        { 
                enemy = this_object()->query_enemy();
                if (sizeof(enemy)!=0)
                {
                        ob=enemy[0];
                }
        }
        if(userp(ob))   ob->set_temp("marks/wolf_killed_wuyi",1);
        ::die();
}                                      
