#include <ansi.h>
inherit NPC;
void use_poison();
void sonic_attack();
void create()
{
    set_name(HIR"С���"NOR, ({ "baby pheonix", "pheonix" }) );
    set("race", "Ұ��");
    set("gender", "female");
    set("imbs", ({"ͷ��", "����", "β��", "צ��", "���" }));
    set("verbs", ({"bite", "claw", "poke" }));
    set("age", 1);
    set("long", "һ������ոճ���ϸ����ë��С��ˡ�\n");
    set("attitude", "heroism");
    set_skill("dodge", 25);
    set_skill("move", 45);
    set("combat_exp", 100+random(200));
        set("bellicosity", 300);
        set("invisibility",1); 
    setup();
} 
void init(){
        object me; 
        me = this_player();
        if(!interactive(me)){
                return;
        }
        if(!NATURE_D->is_day_time() && me->query("yinghe_marks/�������")){
                call_out("sleeping", 1, me);
                return;
        }       
        if(!NATURE_D->is_day_time() ){
                me->set_temp("yinghe_marks/wake_pheonix", 1);
                call_out("waken", 1, me);
        }
} 
void sleeping(object me){
        message_vision(HIG"��˱����ڰ�˯��\n"NOR, me);
        return ;
} 
void waken(object me){
        object hf;  
        hf = present("red pheonix", environment(this_object()));        
        message_vision(HIY"\$N����һ�������Ľ�����\n"NOR, this_object());
        if(!present(hf)){
                hf = new(__DIR__"npc/pheonix");
                hf->move(environment(this_object()));
                hf->waken(me);  
        } else {
                hf->waken(me);
        }
}      
