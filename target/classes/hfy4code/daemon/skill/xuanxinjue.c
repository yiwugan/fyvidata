 //sfy@fy4
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                     "���İ����");
        set("bounce_ratio",             25); 
        set("learn_bonus",              -800);
        set("black_white_ness",         20);
        set("effective_level",          195);
        set("usage/force",              1);
        set("usage/iron-cloth",         1);
		set("usage/spells",				1);
        set("skill_class",                      "mei");
        set("absorb_msg",                       ({
                        "$n�����񹦣�ȫ���â���ǣ���$N�Ĺ����������Ρ�\n",
                        "$n��������䣬��âӦ���������$N���˻�ȥ��\n",
                        "$N����ʽ�������壬ȴ��$n���������˻�ȥ��\n",
                        })
        );
}
int valid_learn(object me) {
        if(me->query("class") != "mei" || me->query("gender")!="Ů��") {
                return notify_fail("���İ����ֻ���ɹ��ֵ�Ů�����������\n");
        }       
        
        if(!::valid_learn(me)) {
                return 0;
        }
        if((int)me->query("max_force") < 350) {
                return notify_fail("�������������\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        return notify_fail("���İ����ֻ��ͨ��ѧϰ����ߡ�\n");
                
}     
void skill_improved(object me)
{
    int s;
    s = me->query_skill("xuanxinjue", 1);
       if (s== 150 && me->query("class")=="mei") {
   
       me->set("once_menpai/mei",1);
       } 
}  