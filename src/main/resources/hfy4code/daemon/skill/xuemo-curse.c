 // xuemo-curse.c
inherit SKILL; 
void setup() {
        set("name", "Ѫħ����");
        set("effective_level", 150);
        set("learn_bonus", -10);
        set("practice_bonus", -5);
        set("black_white_ness", 60);
        set("usage/cursism", 1);
        set("skill_class", "xuemo");
} 
int valid_learn(object me)
{
        if( (int)me->query_skill("xuemo-blade",1) < 200
        ||      (int)me->query_skill("xuemo-blade",1) <= (int)me->query_skill("xuemo-curse",1) )
                return notify_fail("���Ѫħ��������������޷�ѧϰѪħ���\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("Ѫħ����ֻ����ѧ��\n");
}  
