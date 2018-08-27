 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
        set("name", "ѩҰǱ��");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 190);
        set("learn_bonus", 10);
        set("practice_bonus", -10);
        set("skill_class", "wolf");
        set("dodge_msg", ({
                "$n�������Ʋ�������ƮƮ��������������һ�ԡ� \n",
                "$n��һ�ֽ���Ư���Ķ��������������㿪��$N�Ĺ����� \n",
                "$n����б�ݣ�ԶԶ������ͬʱ��ͷ����$N��ʽ�������� \n",
                "$n�����������Ի���$N�����ߣ���$N����ʽ��ա� \n"
        }) );
} 
int practice_skill(object me)
{
        if( (int)me->query("force") < 5 ){
            return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        return 1;
}     
