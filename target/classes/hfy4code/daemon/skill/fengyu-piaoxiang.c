 // fengyu-piaoxiang.c  ����Ʈ�㲽
inherit SKILL;
#include <ansi.h> 
void setup() {
        set("name", "����Ʈ�㲽");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 120);
        set("practice_damage", 60);
        set("learn_bonus", -500);
        set("practice_bonus", -50);
        set("black_white_ness", 0);
        set("skill_class", "bat");
        set("dodge_msg", ({
            "$nһ����ĮĮ�����ء�������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�\n",
            "$nʹ��һ�С�ڤڤ��ȥ�١�����Ȼ�������࣬���$N���˸��ա�\n",
            "$n����һҡ���ó�������Ӱ��һ�С�ɽ�紵���֡������$N�Ĺ��ơ�\n",
            "$nһ�С�ǧ��ͬһɫ������Ծ��ٿ��������$N���\n",
            "$n��һҡ����һ�Σ�һ�С�����ȥ�岨��������������\n",
            "$n˫��һ�㣬бб����ʹ����������֡�������$N��ࡣ\n",
        }) ); 
} 
int practice_skill(object me)
{
        if (me->query_skill("fengyu-piaoxiang",1) > 180)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");       
        if ((int)me->query("force") < 20) {
                return notify_fail("�������������ϰ��\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}      

void skill_improved(object me)
{
        int s, n;
        s = me->query_skill("fengyu-piaoxiang", 1);
		if (s>320&&me->query_skill("move",1)>320&& s%10==1) {
			n = 1+(s-311)/10;
			if( n > 9 ) n = 9;
			if( me->query("no_busy") < n ) {
			me->set("no_busy",n);
            tell_object(me, HIY "�㳤���غ��˿���������������ɲ�Ǽ䣬����Ṧ������ﵽ�˸��ߵľ��磡����\n" NOR);
			}
		}
}