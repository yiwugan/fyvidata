//Ѫħ����Դ���ڡ�Ѫ���ġ���13λѪū��ʹ�õĵ���
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "Ѫħ����");
        set("usage/blade", 1);
        set("usage/parry", 1);
        set("usage/dodge", 1); 
        set("effective_level", 300);
        set("learn_bonus", -500);
        set("black_white_ness", -200);
        set("skill_class", "xuemo");
        
        set("dodge_msg", ({
        "$n����һԾ����������ɣ���ʱ$N�Ĺ��ƾͻ�Ϊ���Σ�\n",
                "$Nֻ������ǰ��$n��Ӱ�������ģ�������ʣ�Ȼ����ȫ��ʧ......��$Nһ����գ���\n",
                "$NͻȻ���У����˷�������ȴ���ֻ��е�$n��Ȼ��һ������\n",
                "$n��������������վ�������$Nȴ��$n��һƬ������û��������\n",
        }) ); 
        set("parry_msg", ({
        "$n���ص�����ͻȻ�ǳ����죬$N��ȻҲ��������㱣�����$w������������$n��$vת����\n",
//��Ѫ���ġ�����дħ������ʱ������һ�����¡�
        "$n���е�$v����������£���������ĵ��⾹Ȼ��$N���е�$w�𿪣�$N�ֱ۷��飬$w������֣�\n",
        "$n��ס$v����һ�������ԲȦ��������ħ�ⶸ����$N�е�ȫ���£�����$w���ɵ�����������\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$nЦ�ݹ��죬$Nֻ��ħ����棬����һ����Ӳ�������ջ��Լ�����ʽ��\n",
        "$NͻȻ���У���������$nʱȴ������ֻ������һ����Ӱ��\n",
        }) );
        action = ({
        ([ "action": "$N����$wһ����$n��ǰ����һ�ֳ���ħ�������......��",
                "damage": 200,
                "dodge": 400,
                "parry": 400,
                "damage_type": "����"
        ]),
        ([ "action": "$N������翣�����$w����һ�ӣ�ʮ����ħ��ʱӿ����$n��ǰ��",
                "dodge": 300,
                "parry": 500,
                "damage": 200,
                "damage_type": "����"
        ]),
        ([ "action": "$N��Цһ����$w��������������ħ����Ȼ��$n�������У�",
                "damage": 200,
                "dodge": 600,
                "parry": 400,
                "damage_type": "����"
        ]),
        ([ "action": "$N����$wͻȻ���Ѫ��,$w��ʱħ�����ޣ�$n�������⣬��Ȼ�޷����㣡",
          "damage": 250,
                "dodge": 1400,
                "parry": 1200,
                "damage_type": "����"
        ]),
        ([ "action": "$n�۾�һ����Ѫ���$w����������$n�ĺ�ǰ��",
                "damage": 150,
                "dodge": 100,
                "parry": 400,
                "damage_type": "����"
        ]), 
        });
} 
int practice_skill(object me)
{
       return notify_fail("��Ѫħ�����������ޱȣ��㲻���ܿ���ϰ��������о��壡\n");
} 

mixed hit_ob(object me, object victim, int damage_bonus)
{
           object ob,my_weapon;
           int badint;
           
           int act, pro, dam; //�������
           act=me->query_temp("xuemo-act");      
        if(act==1)
        {
                dam = (int) me->query("force");
                dam = (random(dam)+dam)/2;
                pro = victim->query("con");
                if (pro>20)
                {
                        dam = dam*(1-(pro-30)/20);
                }
                victim->receive_damage("sen",dam/5);
                return (WHT "$nֻ����ǰȺħ���裬�������⣬��־��ʼ��Щ�Ժ����壡��\n" NOR);
        }
        if(act==4)
        {
                dam = (int) me->query("force");
                dam = (random(dam)+dam)/2;
                pro = victim->query("con");
                if (pro>20)
                {
                        dam = dam*(1-(pro-30)/20);
                }
                victim->receive_damage("sen",dam/5);
                return (WHT "$nֻ����ǰȺħ���裬�������⣬��־��ʼ�Ժ����壡��\n" NOR);
        }
        //�������
        if( random(damage_bonus) < 200 ) return 0;
        if(ob=victim->query_temp("weapon"))
        if(ob->query("skill_type") == "blade")
        if(victim->query_skill_mapped("blade") == "bat-blade")
                if(me->query_skill("blade") > victim->query_skill("blade"))
                {
                    switch(random(2)) {
                    case 0:
                        message_vision(HIR "\n�򵶷���ˣ�$Nռ�����Ϸ磡"NOR,me,victim);
                        break;
                    case 1:
                        message_vision(HIR "\n$N��ħ�����׹���$n�Ŀ�϶֮�У�" NOR,me,victim);
                        break;
                    }
                return random(me->query_skill("blade")) * 4;
        }
        my_weapon=me->query_temp("weapon");
        if(damage_bonus < 300 ) return 0;
        if(victim->query_skill_mapped("iron-cloth") == "xisui"||"jin-gang")
{
                badint =victim->query_skill("iron-cloth")*2+random(victim->query_skill("iron-cloth"));
                if(badint) {
                        victim->receive_wound("kee",badint,me);
                        switch(random(2)) {
                                case 0: return HIR"$N����"+my_weapon->query("name")+HIR"͸����ħ��,��������$n�Ļ����񹦣�\n"NOR;
                                case 1: return HIR"$nֻ��ȫ��һ��,$N��"+my_weapon->query("name")+HIR"��͸����� ������\n"NOR;
                        }
                }
        }
    return 0;
} 

mapping query_action(object me, object weapon) 
{
        int act;
        act=random(sizeof(action));
        me->set_temp("xuemo-act",act);
        return action[act]; 
} 
string query_parry_msg(object weapon) {
        mapping msg;
        int act;
        
        if(objectp(weapon)) {
                msg = skill_attr["parry_msg"];
        }
        
        if(sizeof(msg) == 0) {
                msg = skill_attr["parry_msg"];
        }
       if(sizeof(msg) > 0) {
                act=random(sizeof(msg));
                this_player()->set_temp("xuemo-parry",act);
                return msg[act];
        }
        
        return 0;
} /*
mixed hit_ob(object me, object victim){ 
        int act, pro, dam;
        
        act=me->query_temp("xuemo-act");      
        if(act==1)
        {
                dam = (int) me->query("force");
                dam = (random(dam)+dam)/2;
                pro = victim->query("con");
                if (pro>20)
                {
                        dam = dam*(1-(pro-30)/20);
                }
                victim->receive_damage("sen",dam/5);
                return (WHT "$nֻ����ǰȺħ���裬�������⣬��־��ʼ��Щ�Ժ����壡��\n" NOR);
        }
        if(act==4)
        {
                dam = (int) me->query("force");
                dam = (random(dam)+dam)/2;
                pro = victim->query("con");
                if (pro>20)
                {
                        dam = dam*(1-(pro-30)/20);
                }
                victim->receive_damage("sen",dam/5);
                return (WHT "$nֻ����ǰȺħ���裬�������⣬��־��ʼ�Ժ����壡��\n" NOR);
        }
} */
mixed parry_ob(object victim, object me)
{       int busy_time,alr_busy_time;
        int level;
        if (victim->query("race")=="Ұ��") return 0;
        if (victim->query_temp("xuemo-parry")!=1)     return 0;
        level = me->query_skill("xuemo-sword",1);
        if (level < 50) return 0;
        alr_busy_time=victim->query_busy();
        
        busy_time=random(7);
        if(!busy_time) return 0;
        if(busy_time>alr_busy_time)     victim->start_busy(busy_time);
        return RED"$N"RED"��$n"RED"��ǰ��ħӰ����һʱ��֪����мܣ���\n"NOR;
} /*        
int check_skill(object victim) {
        
        object weapon;
        
        if (weapon=victim->query_temp("weapon"))
        if (weapon->query("skill_type")=="blade" && victim->query_skill("blade",1)>100 
                && victim->query_skill("shenji-blade",1)>100
                && victim->query_skill_mapped("blade")=="shenji-blade")
                return 0; 
        return 1;
}        
*/