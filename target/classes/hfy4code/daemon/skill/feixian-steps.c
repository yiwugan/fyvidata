 // feixian-steps.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "���ɲ���");
        set("usage/dodge", 1);
        set("usage/move", 1);   
        set("effective_level", 220);
        set("black_white_ness", 10);
        set("skill_class", "baiyun");
        set("dodge_msg", ({
                "$nһ�С��������ࡹ�������ɵر��˿�ȥ��\n",
                "ֻ��$n��Ӱһ�Σ�һʽ������Ҳ������ѱ����߳�֮�⡣\n",
                "$nʹ������ת��Ȩ�����������ɵ�������\n",
                "$n����һ�㣬һ�С���Ӱ���ࡹ�ڿն��𣬱��˿�ȥ��\n",
                "����$nʹһ�С��綯��⡹����������Ʈ�˿�ȥ��\n",
                "$n��Ӱ΢�����Ѿ���һ�С�������������������\n",
                "����$nһ�С��������١�ʹ���������Ƶ�$N���ᣡ\n"
        }) ); 
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ) {
                return notify_fail("�������������û�а취�����ɲ�����\n");
        }
        return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("force") < 3 ) {
                return notify_fail("����������������������������ɲ�����\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -3);
        return 1;
}  
mixed dodge_ob(object victim, object me)
{       int busy_time;
   int skill;
        int my_exp, your_exp;
        
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        
        skill=me->query_skill("chess",1);
        
        if (random(skill) + skill/3 > 88 && me->is_busy()) {
                message_vision(HIY"$N������գ�����б�ɣ����յģ۳���ƪ��������Ŀ��������Ȼ����������\n"NOR, me);       
                me->stop_busy();
        }
        
        return 0;
}        
