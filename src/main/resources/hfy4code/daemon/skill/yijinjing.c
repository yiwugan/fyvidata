 //mimicat@fy4
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name",                     "�׽");
        set("bounce_ratio",             35); 
        set("learn_bonus",              -900);
        set("black_white_ness",         20);
        set("effective_level",          200);
        set("usage/force",              1);
        set("usage/iron-cloth",         1);
        set("usage/unarmed",            1);
        set("skill_class",                      "shaolin");
        
                
        
        set("absorb_msg",                       ({
                        "�ۿ�$N��ʽѸ����$n������ǰӭ��һ����һȦ��ǽӦ�������$N������\n",
                        "$n˫�ֺ�ʮ���Ŀ������һ���ھ�͸�������$N���˻�ȥ��\n",
                        })
        );
        set("unarmed_parry_msg",        ({
                        "�ۿ�$N��ʽѸ����$n������ǰӭ��һ����һȦ��ǽӦ�������$N������\n",
                        "$n˫�ֺ�ʮ���Ŀ������һ���ھ�͸�������$N���˻�ȥ��\n",
                        })
        ); 
        action = ({
                        ([      "action":
                        "$N����һ����ƽ�͵������紺�����̣�����$n$l",
                                "parry":                500,
                                "force":                300,
                                "damage_type":  "����"
                        ]),
                        ([      "action":
                        "$Nչ��һ�ӣ�������һ����������һ�����θ�ǽѹ��$n",
                                "parry":                200,
                                "force":                140,
                                "damage_type":  "����"
                        ]),
                        ([      "action":
                   "$Nһ���������䣬����Ѱ����ȴ��֪Ϊ�ε��޿ɵ������޿ɱ�",
                                "parry":                500,
                                "dodge":                1000,
                                "force":                360,
                                "damage_type":  "����"
                        ]),
        });
} 
int valid_learn(object me) {
        if((string)me->query("class") != "shaolin" ) {
                return notify_fail("�׽��ֻ�����ָ�ɮ���������书��\n");
        }       
        if( (int)me->query_skill("zen",1) < (int)me->query_skill("yijinjing",1))
                return notify_fail("���������Ϊ�������޷������������׽��\n");
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
	     if (me->query("once_xman")==1) return 0;
        else {return notify_fail("�׽ֻ��ͨ��ѧϰ����ߡ�\n");}
                
}     

int effective_level()
{
        object me=this_player();
        
        if (me->query("once_xman")==1) return 330;
        
        if (me->query_temp("SUPERER")) return 500;
        
        else {return 200;}
        
        
                
} 