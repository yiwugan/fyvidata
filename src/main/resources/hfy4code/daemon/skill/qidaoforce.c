 // modified by mimicat@fy4
// qidaoforce.c
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "���");
        set("usage/force", 1);  
        set("skill_class", "legend");
        set("effective_level", 150);
        set("learn_bonus", -50);
        set("practice_bonus", -50);
        set("black_white_ness", 30);
        set("parry_msg",  ({
        "$n������������ס��$N�Ĺ��ơ�\n",
        }) );
        set("unarmed_parry_msg", ({
        "$n������������ס��$N�Ĺ��ơ�\n",
        }) );
        action = ({
        ([      "action":
"$Nʹ��һ�С�����ͷ�������־۳�һ�����������϶��£�����$n��$l",
                "force":                150,
                "damage":               200,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С���б�������־۳�һ��������бб����$n��$l",
                "force":                150,
                "damage":               250,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�˫���ࡹ��˫�־۳�һ������������ͬʱ����$n��$l",
                "force":                300,
                "damage":               300,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�����������ȫ���ڿն�������ȫ�����������$n��$l",
                "force":                400,
                "damage":          400,
                "damage_type":  "����"
        ]),
        });
}
int valid_enable(string usage) 
{ 
        object me;
        
        
        me=this_player();
        if(me->query_skill("qidaoforce",1)>70){
                return usage=="unarmed"||usage=="force"; 
        }
        else
                return usage=="force";
}  
mixed hit_ob(object me,object victim)
{
        int extra, dream;
        string message="";
        extra = me->query_temp("qidaoforce_juqi");
        dream = me->query_skill("six-sense",1)/2 + 400 * victim->query("resistance/kee")/100;   
//      write("dream is "+(string)(dream)+"\n");
//      write("extra is " +(string)(extra)+"\n");
        if( extra > 0) {
                victim->receive_damage("kee",extra/2,me);
                victim->add("kee",-extra/2);
        }
        if( me->query_temp("qidaoforce_diemeng") && me->query_skill("six-sense",1)>=180) {
                victim->receive_damage("kee",dream/2, me);
                victim->add("kee",-dream/2);
        }
        if (extra || me->query_temp("qidaoforce_diemeng"))
        if (me->query("family/master_id")=="master xuerui")
                        message_vision(WHT"\n$N������ɫ��â��������ƬƬ����$n��$n"+WHT"ֻ��������һ����ʹ��\n"NOR,me, victim);
                else 
                        message_vision(HIC"\n$N��������Ϊһ�ߣ�����$n"+HIC"�����ڡ�\n"NOR, me, victim);
        return;
}     
