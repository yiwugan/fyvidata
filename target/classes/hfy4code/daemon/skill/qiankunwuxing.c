 // TIE@FY3
inherit SKILL;
void setup() {
        set("name", "Ǭ������");
        set("usage/magic", 1);
        set("skill_class", "lishi");
        set("learn_bonus", -10);
        set("practice_bonus", -5);
        set("black_white_ness", 10);
}
/*int valid_learn(object me)
{
        if( (int)me->query_skill("putiforce",1) < 10
        ||      (int)me->query_skill("putiforce",1) <= (int)me->query_skill("qiankunwuxing",1) )
                return notify_fail("����е��ķ�����������޷�ѧϰǬ�����Ρ�\n");
        return 1;
}*/ 
int practice_skill(object me)
{
        return notify_fail("Ǭ������ֻ����ѧ��\n");
}  
