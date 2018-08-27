 // shenji-steps.c
inherit SKILL;
void setup(){
        set("name", "�������");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 180);
        set("learn_bonus", -90);
        set("practice_bonus", -50);
        set("black_white_ness", 40);
        set("skill_class", "emei");
        set("dodge_msg", ({
                "$nһ�С�����ѿǡ����������飬����Ʈ����$N����ʽ��ա�\n",
                "ֻ��$n������������$N����ʽ���ϣ�һʽ���ٳղ�񲡹�����ɵض���һ�ԡ�\n",
                "$nʹ�������ܹ��ݡ���бб�شܿ���\n",
                "$n����һ�㣬һ�С����ɳ²֡��ڿն��𣬱��˿�ȥ��\n",
                "����$nʹһ�С����ݴ��͡�������Ʈ��������$N�Ĺ���ʧȥ��׼ͷ��\n",
                "$n����һ�С������ۻ𡹣�����Ʈ�ˣ�����������\n",
                "����$nһ�С�����ҽ���ʹ�������λζ����ó�������Ӱ���Լ�����Ʈ�����ɿ��⣡\n",
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취���������\n"); 
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 10 ){
                return notify_fail("��������������������������������\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
        return 1;
}       
