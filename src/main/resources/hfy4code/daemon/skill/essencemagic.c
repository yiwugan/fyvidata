 // essencemagic.c
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name", "��ʶ��ͨ");
        set("effective_level", 150);
        set("learn_bonus", -10);
        set("practice_bonus", -5);
        set("black_white_ness", 60);
        set("usage/magic", 1);
        set("skill_class", "bonze");
} 
int valid_learn(object me)
{
        if( (int)me->query_skill("buddhism",1) < 10
        ||      (int)me->query_skill("buddhism",1) < (int)me->query_skill("essencemagic",1) )
                return notify_fail("��ķ���Ϊ����������޷�ѧϰ��ʶ��ͨ��\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("��ʶ��ֻͨ����ѧ��\n");
}  

void skill_improved(object me)
{
    int s;
    s = me->query_skill("essencemagic", 1);
    if (s== 280) {
       tell_object(me,HIW " ͻȻ��԰�ʶ��ͨ���˸��������˽⡣\n"NOR);
       tell_object(me,HIW"��ϲ�㣡���Ժ�����ƶ��Լ��Ķ����ˣ�\n"NOR);
       me->set("open_sesame",1);
      } 
} 