 // doggiesteps.c
inherit SKILL; 
void setup() {
        set("name", "Ұ������");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 90);
        set("learn_bonus", 50);
        set("practice_bonus", 0);
        set("black_white_ness", 30);
        set("skill_class", "beggar");
        set("dodge_msg", ({
        "����$n����Ʈ��������һ�ݣ�һ�С�Ұ����ʳ������������ıܿ���һ����\n",
        "$n������ת��һʽ��Ұ��б�ݡ���ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�ʹ����Ұ���������$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ�һ�С�Ұ���ϴڡ������Դܿ����ߣ����˿�ȥ��\n",
        "$n����΢�Σ�ʹ����Ұ�����������о����յرܿ���$N��һ�С�\n",
        "$n��������һ�Σ�һ�С�Ұ����ҡ����һ��ת����������֮�⡣\n"
        }) );
}     
