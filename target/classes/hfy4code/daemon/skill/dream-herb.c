 inherit SKILL;
void setup() {
        set("name", "�����廨��");
        set("usage/herb", 1);
        set("practice_damage", 40);
        set("learn_bonus", 0);
        set("practice_bonus", -50);
        set("skill_class", "knight");
        set("black_white_ness", -50);
} 
int valid_learn(object me)
{
        if((int)me->query_skill("force", 1) < 100) {
                return notify_fail("����ڹ��ķ�����㣬�޷��������廨����\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("dream-herb",1) > 120)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");
        if ((int)me->query("force") < 20) {
                return notify_fail("������������������廨����\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -15);
        return 1;
}     
