 // cloud-dance.c
inherit SKILL; 
void setup() {
        set("name", "�÷�Ʈ����");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 175);
        set("learn_bonus", -500);
        set("practice_bonus", -200);
        set("black_white_ness", 0);
        set("skill_class", "huashan");
        set("dodge_msg", ({
                "$n����Ʈ����������е�һ�����ơ�\n",
                "$n��������һ�ۣ���������Ʊܿ���$N�Ĺ��ơ�\n",
                "$n��������Ʈ�����ë����Ӱ������̬���������еرܿ���$N����ʽ��\n",
                "��ͬ�����ĳ��������µ�÷����$n������Ʈ����\n",
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ) {
                return notify_fail("�������������û�а취ѧ�÷�Ʈ���衣\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        return notify_fail("�÷�Ʈ����ֻ����ѧ�ġ�\n");
}    
