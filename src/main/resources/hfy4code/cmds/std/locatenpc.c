 // task.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <ansi.h>
int main(object me, string str)
{
        string output;
        me->add("sen",-5);
        output =  HIY"����������������������������������"NOR + HIR"�����Ƣ�ʹ����"NOR + HIY"����������������������������������\n"NOR;
        output += HIY"����������������������������������"NOR + HIR"����������������"NOR + HIY"����������������������������������\n"NOR;
        output += TASK_D->dyn_quest_list();
        output += HIY"����������������������������������"NOR + HIR"����������������"NOR + HIY"����������������������������������\n"NOR;
        output += HIY"����������������������������������"NOR + HIR"����������������"NOR + HIY"����������������������������������\n"NOR; 
        me->start_more("", output, 0);
        return 1;
} 
int help(object me)
{
        write(@HELP
ָ���ʽ: tasks 
���ָ����������֪Ŀǰ������ʹ��. 
HELP
        );
        return 1;
}    
