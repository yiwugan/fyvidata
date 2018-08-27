 //TIE@FY3
// puti-steps.c 
inherit SKILL;
void setup(){
        set("name", "������ղ���");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("learn_bonus", -20);
        set("practice_bonus", -5);      
        set("black_white_ness", 10);
        set("skill_class", "shaolin");
        set("dodge_msg", ({
                "$nһ�С����᱾�������������ɵر��˿�ȥ��\n",
                "ֻ��$n��Ӱһ�Σ�һʽ���龵���̨�����ѱ����߳�֮�⡣\n",
                "$nʹ����������һ����������ɵ�������\n",
                "$n����һ�㣬һ�С��δ��ǳ������ڿն��𣬱��˿�ȥ��\n",
                "����$nʹһ�С�����Ϫˮ������������Ʈ�˿�ȥ��\n",
                "$n��Ӱ΢�����Ѿ���һ�С����ϱ��������������\n",
                "����$nһ�С���ʱ�����С�ʹ���������Ƶ�$N���ᣡ\n",
        "����$n����Ʈ��������һ�ݣ�һ�С�˵�����ա����ܿ���һ����\n",
        "$n��������һ�Σ�һ�С�շת���ɲ¡���һ��ת����������֮�⡣\n", 
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ){
                return notify_fail("�������������û�а취��������ղ�����\n");
        }
        return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("force") < 3 ){
                return notify_fail("�����������������������������ղ�����\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -3);
        return 1;
}       
