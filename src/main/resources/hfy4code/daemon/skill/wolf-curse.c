#include <ansi.h>
 inherit SKILL;
void setup() {
        set("name",                     "����Ѫ��");
        set("learn_bonus",              -500);
        set("practice_bonus",           10);
        set("black_white_ness",         0);
        set("usage/cursism",            1);
        set("skill_class",              "wolf");
}  
int practice_skill(object me)
{
        return notify_fail("����Ѫ��ֻ��ѧ�ġ�\n");
        
}  
int valid_learn(object me)
{
        if( (int)me->query_skill("wolf-force",1) < (int)me->query_skill("wolf-curse",1)-70)
                return notify_fail("��������ķ���Ϊ�������޷���������������Ѫ�䡣\n");
        return 1;
}

void skill_improved(object me)
{
    int s;
    s = me->query_skill("wolf-curse", 1);
    if (s== 200) {
       tell_object(me,HIW " �������Ѫ�����������˽⣡\n"NOR);
       tell_object(me,HIW"��ϲ�㣡���Ժ���ԡ����ǹ��衱�ˣ�\n"NOR);
      } 
}
