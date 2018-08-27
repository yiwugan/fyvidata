 inherit SKILL;
void setup() {
        set("name", "������ʮ��ʽ");
        set("usage/dodge", 1.2);
        set("usage/move",1);
        set("effective_level", 150);
        set("learn_bonus", -30);
        set("practice_bonus", -30);
        set("black_white_ness", 0);
        set("skill_class", "knight");
        set("dodge_msg", ({
                "$n����ƮƮ�������ƣ���кˮ��һʽ���Դ����Ʒ����䡻��Ȼ��ɡ� \n",
                "$n������磬һ�С�����΢�ʶ�筴��������ѱ����߳�֮�⡣\n",
                "$n����ͻȻ�Ķ��������ǡ�������ͨ���Է�������о�����ա�\n",
                "ֻ��$n��������ǧ�������ߣ�һʽ���ջ�ҡ���ƽ��ۡ����ܿ���һ����\n",
                "$n˫�������棬������������֮��ʹ��һʽ�������ҷ������塻��\n",
                "$n����ͻ�������Σ�бб�س������һʽ�����˶��������ߡ�����������\n",
                "����$nһ�С�������ס����ʶ��ʹ���������Ƶ�$N���ᣡ\n",
                "����$n����Ʈ����һ�С�����������δ�ء����鶯�޷��ܿ���һ����\n",
        }));
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ) {
                return notify_fail("�������������û�а취��������ʮ��ʽ��\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 3 ) {
                return notify_fail("�������������������������ʮ��ʽ��\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -3);
        return 1;
}      
