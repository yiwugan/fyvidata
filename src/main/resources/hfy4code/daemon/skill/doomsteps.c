 //doomsteps.c
inherit SKILL; 
void setup() {
        set("name", "��Ѫ����");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("practice_bonus", -5);
        set("learn_bonus", -300);
        set("black_white_ness", -20);
        set("skill_class", "fighter");
        set("effective_level",150);
        set("dodge_msg", ({
                "����$n����Ʈ��������һ�ݣ�һ�С��黳���ȡ�����������ıܿ���һ����\n",
                "$n������ת��һʽ�����ѵ�ˮ����ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
                "����$n����һ�ã�ʹ����ϸ���ɷ��ơ���$N��һ�����˸��ա�\n",
                "ȴ��$n�㲻��أ�һ�С��׺׳��졹�����Դܿ����ߣ����˿�ȥ��\n",
                "$n����΢�Σ�ʹ�������ӷ������о����յرܿ���$N��һ�С�\n",
                "$n��������һ�Σ�һ�С�����չ�᡹��һ��ת����������֮�⡣\n"
        }) ); 
}  
int practice_skill(object me)
{
        return notify_fail("��Ѫ����ֻ��ѧ�ġ�\n");
} 
