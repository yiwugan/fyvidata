 // five-steps.c
inherit SKILL;
void setup() {
        set("name", "������");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 200);
        set("learn_bonus", 10);
        set("skill_class", "wudang");   
        set("practice_bonus", -5);
        set("black_white_ness", -5);
        set("dodge_msg", ({
        "����$n����������ˮ������һ����һʽˮ�־��еġ��鵶��ˮ������������ıܿ���һ����\n",
        "$n������ת���Ų����У�һʽ���С�ľ�־�����ٿ�ش�ľ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�ʹ���������еġ����־�����$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ��ó������Ӱ���ӻ������Դܿ����ߣ����˿�ȥ��\n",
        "$n����΢�Σ�ʹ�����С����־��������ݵ���$N�����\n",
        }) );
}
int valid_learn(object me)
{
if((int)me->query_skill("changelaw", 1) < (int)(me->query_skill("five-steps", 1)/2)) {
                return notify_fail("����׾����˽⻹��������޷�ѧϰ��������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("five-steps",1) > 100)
                return notify_fail("��ϰ�Ѿ����ܼ�������������������ֻ��ͨ���ݱ䡸����ͼ��������ˡ�\n");
        if((int)me->query("force") < 10) {
                return notify_fail("���������������������������\n");
        }
        me->add("force", -10);
        return ::practice_skill(me);
}     
