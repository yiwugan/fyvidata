 // devil-spells.c
inherit SKILL;
void setup(){
        set("name", "��ڤħ��");
        set("usage/spells", 1);
        set("skill_class", "yinghe");
        set("effective_level", 150);
        set("learn_bonus", 30);
        set("practice_bonus", 10);
        set("black_white_ness", -50);                   
}        
int practice_skill(object me)
{
        return notify_fail("��ڤħ��ֻ����ѧ��\n");
}       
