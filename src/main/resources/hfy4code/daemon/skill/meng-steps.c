 //meng-steps.c  ���β���
inherit SKILL;
void setup() {
        set("name", "���β���");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 180);
        set("learn_bonus", -400);
        set("practice_bonus", -60);
        set("black_white_ness", -40);
        set("skill_class", "bat");      
        set("dodge_msg", ({
                "$n��һ����磬�滺��������$N���������ơ�\n",
                "$n˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",
                "$n���ζ��ر��Ʈ����������$N�޷����塣\n",
                "$n������ͥ�Ų����ڵ�ָ����Ȼ�˳����⡣\n",
                "����$n��һת����һ�ƣ���Ӱ����ʧ������\n",
        
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ){
                return notify_fail("�������������û�а취�����β�����\n");
        }
        if (me->query_skill("wuzheng-force",1)<me->query_skill("meng-steps",1))
                return notify_fail("��������ķ���򲻹���\n");
        return 1;
} 
int practice_skill(object me)
{
        return notify_fail("���β���ֻ��ѧ�ġ�\n");
} 
