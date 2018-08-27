 // huanhua-steps.c
inherit SKILL; 
void setup() {
        set("name", "佻�����");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 200);    
        set("black_white_ness", 10);
        set("skill_class", "shenzhou");
        set("dodge_msg", ({
                "$nһ�С���ˮ�صޡ��������ɵر��˿�ȥ��\n",
                "ֻ��$n��Ӱһ̤佻�������һʽ��������̡����ѱ����߳�֮�⡣\n",
                "$nʹ������ת��С����������ɵ�������\n",
                "$n����һ�㣬һ�С���Ӱ�������ڿն��𣬱��˿�ȥ��\n",
                "����$nʹһ�С��綯�񶯡�����������Ʈ�˿�ȥ��\n",
                "$n��Ӱ΢�����Ѿ���һ�С�������������������\n",
                "����$nһ�С���ҡ�ɵء�ʹ���������Ƶ�$N���ᣡ\n"
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 20 ){
                return notify_fail("�������������û�а취��佻�������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 3 ){
                return notify_fail("�������������������佻�������\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -3);
        return 1;
}        
