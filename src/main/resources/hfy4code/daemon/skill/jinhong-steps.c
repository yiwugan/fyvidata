 // jinhong-steps.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "��粽��");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("black_white_ness", -10);
        set("practice_bonus",   0);
        set("practice_limit",160);
        set("effective_level", 120);
        set("skill_class", "assassin");
        set("dodge_msg", ({
                "$nһ�С���Ǯ���ء��������ɵر��˿�ȥ��\n",
                "ֻ��$n��Ӱһ�Σ�һʽ���������ԡ����ѱ����߳�֮�⡣\n",
                "$nʹ�����ƻ����ء����������ɵ�������\n",
                "$n����һ�㣬һ�С��������¡��ڿն��𣬱��˿�ȥ��\n",
                "����$nʹһ�С������ٷ硹����������Ʈ�˿�ȥ��\n",
        }) );
} 
int practice_skill(object me)
{
        
        if((int)me->query("force") < 3 ) {
                return notify_fail("���������������������粽����\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -3);
        return 1;
} 
void skill_improved(object me)
{
    int s;
    s = me->query_skill("jinhong-steps", 1);
    if (s== 100 && me->query("class")=="assassin") {
       tell_object(me,HIW "��Խ�粽�����˽�����һ����Ծ��\n"NOR);
       } 
    if (s== 150 && me->query("class")=="assassin") {
       tell_object(me,HIW "��Խ�粽�����˽�����һ����Ծ��\n"NOR);
       tell_object(me,HIW "��ģ۲���է�֣ݿ���ʹ������æ�����ˣ�\n"NOR);
       } 
    if (s== 160 && me->query("class")=="assassin") {
       tell_object(me,HIW "���Ȼ���ã�������Լ����ټ�����������ȼ��Ļ���\n"NOR);
       tell_object(me,HIW "���ܹ��ѽ�粽����Ч�������һЩ��\n"NOR);
       } 
}      
