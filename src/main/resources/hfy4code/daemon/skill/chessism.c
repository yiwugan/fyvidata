 // modified by sinny shi
// qidaoforce.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "�ĵ�");
        set("usage/force", 1);  
        set("skill_class", "baiyun");
        set("effective_level", 250);
        set("learn_bonus", -30);
        set("practice_bonus", -30);
        set("black_white_ness", 30);
        set("parry_msg",  ({
        "$n�������������ĵ�Ҫּ��ɲ�Ǽ��$N�Ĺ�������ָ�ơ�\n",
        }) );
}    
