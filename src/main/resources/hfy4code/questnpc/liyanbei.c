#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER; 
void create()
{
        set_name("���౱", ({ "li yanbei", "li" }) );
        set("gender", "����" );
        set("nickname",HIC"����������"NOR); 
        set("age", 43);
        set("int", 21);
        set("per", 20);
        set("str", 40);
        set("dur", 50);
        set("cor", 35);
        set("long",
"���౱��߰˳ߡ��磬��ΰǿ׳���������棬Ũü�����ۡ�ӥ
�ǡ���������ϣ����Ǵ����ֽӽ��п�ı��飬������������
�մ�ԭʼɽ���дܳ����ı��ӡ�\n");
        set("force_factor", 30);
        set("max_gin", 1400);
        set("max_kee", 3200);
        set("max_sen", 1700);
                set("max_force",2000);
                set("force",2000); 
        set("combat_exp", 1500000);
        set("score", 15000);
        set_skill("unarmed", 150);
        set_skill("force", 120);
        set_skill("parry", 140);
        set_skill("literate", 50);
        set_skill("dodge", 140); 
                
     
//        set("chat_chance_combat", 40);
//        set("chat_msg_combat", ({
//                (: perform_action,"spear.qingheluo":),
//        }) );
        setup();
        carry_object(__DIR__"obj/zimagua")->wear();
   add_money("gold",8);
}
/*
object offensive_target(object me)
{
        int sz;
        object *enemy; 
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0; 
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4; 
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}  
*/    
