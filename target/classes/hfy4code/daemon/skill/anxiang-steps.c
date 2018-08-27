 // fall-steps.c
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name", "���㸡Ӱ");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 175);
        set("learn_bonus", -15);
        set("practice_bonus", -5);
        set("black_white_ness", -20);
        set("skill_class", "huashan");
        set("dodge_msg", ({
                "$n���������������Ʈ���÷���꣬����Ʈ�˿�ȥ��\n",
                "ֻ��$n������΢�ۣ�һʽ��ѩѹ÷֦���������ɱ��˿�ȥ��\n",
                "$n����һ�㣬�����ڿն���ǡ���ּ��仨������������\n",
                "$n���һ���������˺��˰˳ߣ����ɾ���Ư�������䡣\n",
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ) {
                return notify_fail("�������������û�а취ѧ���㸡Ӱ��\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 5 ) {
                return notify_fail("����������������������㸡Ӱ��\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        if ((int)me->query_skill("anxiang-steps",1) > 180) {
                return notify_fail("��������Ժ�ֻ�ܿ�ѧ�ˡ�\n");
        }
        me->add("force", -5);
        return 1;
}       
void skill_improved(object me) {
        int s;
        s = me->query_skill("anxiang-steps", 1);
        if(s==200)
        {
       		tell_object(me, HIM "��ͻȻ�����˻�ɽ��ѧ�����У�\n" NOR);
       		me->set("open_sesame_1",1);
       	}
}  