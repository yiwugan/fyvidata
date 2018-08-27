 // fall-steps.c
inherit SKILL; 
void setup() {
        set("name", "��粽��");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 150);
        set("learn_bonus", -20);
        set("practice_bonus", -100);
        set("black_white_ness", 40);
        set("skill_class", "legend");
        set("dodge_msg", ({
                "$nһ�С����������Ʒɡ��������ɵر��˿�ȥ��\n",
                "ֻ��$n��Ӱһ�Σ�һʽ����ľ���������Ϲ项���ѱ����߳�֮�⡣\n",
                "$nʹ��������������з������������ɵ�������\n",
                "$n����һ�㣬һ�С��������ⲻ�������ڿն��𣬱��˿�ȥ��\n",
                "����$nʹһ�С���¥����÷ںӡ�����������Ʈ�˿�ȥ��\n",
                "$n��Ӱ΢�����Ѿ���һ�С������������ز�������������\n",
                "����$nһ�С�������ⷢ���衹ʹ���������Ƶ�$N���ᣡ\n",
                "����$n����Ʈ��������һ�ݣ�һ�С����ּ��Ⱗ��ࡹ���ܿ���һ����\n",
                "$n��������һ�Σ�һ�С���׳��ʱ�����ϺΡ���һ��ת����������֮�⡣\n",
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ) {
                return notify_fail("�������������û�а취����粽��\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 3 ) {
                return notify_fail("���������������������粽����\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -3);
        return 1;
}       
