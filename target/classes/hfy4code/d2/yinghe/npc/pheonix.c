#include <ansi.h>
inherit NPC; 
void create()
{
    set_name(HIR"���"NOR, ({ "red pheonix", "pheonix" }) );
    set("race", "Ұ��");
    set("gender", "female");
    set("imbs", ({"ͷ��", "����", "β��", "צ��", "���" }));
    set("verbs", ({"bite", "claw", "poke" }));
    set("age", 400);
    set("long", "һ�������ƻ�ķ�ˣ���ɫ���������и��Ը�����\n");
    set("attitude", "heroism");
    set_skill("dodge", 250+random(100));
    set_skill("move", 450+random(200));
    set("combat_exp", 1000000+random(2000000));
        set("bellicosity", 300);
        set("invisibility",1);
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
//            (: sonic_attack :),
    }) ); 
    setup();
} 
void init(){
        object obj, obj2, me; 
        me = this_player();
        if(!interactive(me)){
                return;
        }
        if(NATURE_D->is_day_time()){
                call_out("leaving", 1, me);
        } 
} 
void leaving(object me){
        message_vision(HIG"\n$N����һ�����õĽ�������ȥ��\n\n"NOR, this_object(), me);
        destruct(this_object());
        return ;
} 
int waken(object me){ 
        message_vision("$N"HIR"�ƺ�����ŭ$n������С���޴�ĳ��һ�죬���ɽ����������\n!!ž!!�ؽ�$n���Ӭһ�����ڵ��ϡ�\n"NOR, this_object(), me);
   if(me->query("attribute_mark") != "fire"){
                me->unconcious();
        } else {
                me->set("gin", 100);
                me->set("kee", 100);
                me->set("sen", 100);
        }
        me->delete_temp("yinghe_marks/wake_pheonix"); 
        return 1;
}    
