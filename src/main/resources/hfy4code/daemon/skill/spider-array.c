 // spider-array.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "���뽣��");
        set("usage/array", 1);
        set("effective_level", 200);
        set("learn_bonus", 40);
        set("practice_bonus", 20);
        set("black_white_ness", 40);
} 
int form_array(object leader)
{
        object *member; 
        member = leader->query_team();
        if( sizeof(member) != 8 )
                return notify_fail("���뽣������ˣ���һ����һ�������С�\n");
        message_vision( HIG "$N������������վ���˸���λ������ˡ����뽣�󡹣�\n" NOR, leader);
        return 1;
}   
