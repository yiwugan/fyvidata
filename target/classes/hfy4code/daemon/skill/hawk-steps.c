 // hawk-steps.c
inherit SKILL;
void setup() {
        set("name", "��������");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 160);
        set("black_white_ness", 10);
        set("practice_damage",  40);
        set("practice_bonus", -80);
        set("skill_class", "fugui");
        set("dodge_msg", ({
                "$n����˫�ۣ�ʹ������ã��ľ��������������ɵر��˿�ȥ��\n",
                "ֻ��$n��Ӱһ�Σ�һʽ�����亮ɽ����뻡����ѱ����߳�֮�⡣\n",
                "$n��������ľ���,˲�����λ�λ��ʹ�����������ճ���Ȫ�����������ɵ�������\n",
                "$n����һ�㣬Ư����������ǡ�ơ�����򣴨��ʹ�ơ����ڿն��𣬱��˿�ȥ��\n",
                "����$nʹһ�С�����ɽ�������ơ����⾳�Ѵ������綯��Ĺ���,����Ʈ�˿�ȥ��\n",
                "$n��Ӱ΢�����Ѿ���һ�С���ϭ������Ϧ�š�����������\n",
                "$n������в��ȣ�����ʫ�⡸�Է�������ѩɫ��������˶�ȥ��\n",
                "$n˫������һ�ᣬ���α任���ĳֱ��������ġ�����ʱ����Ҷ�ɣ�ѩ���Ƕ���������Ӱ���١�\n",
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취ѧ����������\n"); 
        return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("force") < 20 ) {
                return notify_fail("�����������������������������\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}     
