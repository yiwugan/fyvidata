 // jin-gang.c
inherit SKILL;
void setup() {
        set("name", "��ղ�����");
        set("usage/iron-cloth", 1);
        set("effective_level", 200);
        set("bounce_ratio", 35);
        set("learn_bonus", -10);
        set("practice_bonus", -5);
        set("black_white_ness", 20);
        set("skill_class", "lama");
        set("absorb_msg", ({
        "$n˫��һ�𣬽�ղ������������Ƶ����ȶ�����\n",
        "$nʩչ����ղ������еġ������־���һ�ɵ�������$N�����ڡ�\n",
        "$nʹ��һ�С��ຣ���ġ�������Ϊʵ������Ӳ���ա�\n",
        "$nʩչ����ղ��������Կ�$N��һ��֮����\n",
        }) );
}  
int valid_learn(object me)
{
        if( (int)me->query_skill("lamaism",1) <= (int)me->query_skill("jin-gang",1)) {
                return notify_fail("������ڷ���Ϊ�������޷����������Ľ�ղ�������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("jin-gang",1) > 49)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");
        return ::practice_skill(me);
        
        
}    
