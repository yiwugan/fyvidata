inherit SKILL; 
void setup() {
        set("name",     "��Ѫ�ķ�");
        set("learn_bonus",     -10);
        set("practice_bonus",  -10);
        set("black_white_ness", 15);
        set("effective_level", 150);
        set("usage/force",       1);
        set("skill_class",  "tieflag");     
}  

int valid_learn(object me)
{
        if(!::valid_learn(me))
                return 0;
        if (!me->query("mark/learn_tiexue"))
                return notify_fail("��Ѫ�ķ�Ϊ�����Ÿ��������֮�ؾ���δ����ָ�����޷���ᣡ\n");
        return 1;
} 