#include <ansi.h>;
inherit NPC; 
void create()
{
        set_name("С¹", ({ "little deer", "deer"}) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һͷǳǳ��ë���ϴ��Ű�ɫ�ߵ��С¹��\n");
        set("max_kee", 1200);
        set("max_sen", 1200);
        set("max_gin", 1200);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite" }) );
        set_skill("dodge", 100);
        set("combat_exp", 100);
        set("self_go_msg",1);
        set("arrive_msg","�ı����������˹���");
        set("leave_msg","�ı�������������");
        set("wimpy",99);
        setup();
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        random_move();
}      
