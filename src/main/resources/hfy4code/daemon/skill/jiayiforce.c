 // jiayiforce.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "嫁衣神功");
        set("usage/force", 1);
        set("skill_class", "tieflag");
        set("effective_level", 250);
        set("learn_bonus", -30);
        set("practice_bonus", -10);
        set("black_white_ness", 60);
} 

void skill_improved(object me)
{
    int s; 
    s = me->query_skill("jiayiforce", 1);
    if( random(500) <2 || (me->query_skill("force",1) < me->query_skill("jiayiforce",1))){
        message_vision(HIR"$N体内真气振荡，一股气流走入叉道，啊！！....\n\n" NOR,me);
        me->set_skill("jiayiforce",s*2/3);
//        me->unconcious();
    } 
}

int valid_learn(object me)
{
        if(!::valid_learn(me))
                return 0;
        if (!me->query("mark/learn_jiayi"))
                return notify_fail("嫁衣神功为大旗门不传之秘，即使是大旗门子弟也不允许修炼此神功！\n");
        return 1;
} 