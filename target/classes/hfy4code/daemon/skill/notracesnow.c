 // notracesnow.c
inherit SKILL;
void setup(){
        set("name", "̤ѩ�޺�");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 120);
        set("learn_bonus", 20);
        set("practice_bonus", 0);
        set("black_white_ness", -10);
        set("skill_class", "bonze");
        set("dodge_msg", ({
        "$nһ�С�Ϧ����ѩ���������ɵر��˿�ȥ��\n",
        "ֻ��$n��Ӱһ�Σ�һʽ�����Ƽ������ѱ����߳�֮�⡣\n",
        "$nʹ�����������졹���������ɵ�������\n",
        "$n����һ�㣬һ�С������ƶˡ��ڿն��𣬱��˿�ȥ��\n",
        "����$nʹһ�С�̤ѩ�޺ۡ�����������Ʈ�˿�ȥ��\n",
        "$n��Ӱ΢�����Ѿ���һ�С������������������\n"
        }) );
} 
int valid_learn(object me)
{
    if( (int)me->query("max_force") < 50 ) {
        return notify_fail("�������������û�а취��̤ѩ�޺ۡ�\n");
        }
    return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 3 ){
        return notify_fail("�����������������������̤ѩ�޺ۡ�\n");
    }
    if(!::practice_skill(me)){
        return 0;
    }
    me->add("force", -3);
    return 1;
}      
