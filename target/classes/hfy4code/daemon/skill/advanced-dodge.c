#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name", "�߼���Ծ����֮��");
        set("effective_level", 200);
        set("learn_bonus", -500);
        set("black_white_ness", 0);
} 
int practice_skill(object me)
{
    return notify_fail("�߼���Ծ����֮��ֻ����ѧ�� \n");
} 
