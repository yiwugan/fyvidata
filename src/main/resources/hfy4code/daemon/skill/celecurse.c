 // celecurse.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL; 
void setup() {
        set("name",                             "ͨ�콵");
        set("learn_bonus",                      -10);
        set("practice_bonus",           10);
        set("practice_damage",          40);
        set("black_white_ness",         0);
        set("usage/cursism",            1);
        set("effective_level",          150);
        set("skill_class",                      "yinshi");
}  
int practice_skill(object me)
{
        if (me->query_skill("celecurse",1) > 80)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");
        if((int)me->query("force") < 5 ) {
                return notify_fail("�������������������ͨ�콵��\n");
        }
        me->add("force", -5);
        return ::practice_skill(me);
        
        
} 
