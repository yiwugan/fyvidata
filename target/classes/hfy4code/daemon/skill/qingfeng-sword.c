 // qingfeng-sword.c
// Last modification by neon
// Change: hit_ob action dependes on force_factor instead of force
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "���ʮ��ʽ");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("skill_class", "huashan");
        set("effective_level", 120);
        set("practice_limit",180);
        set("learn_bonus", 0);
        set("practice_bonus", -5);
        set("black_white_ness", 10);
        set("unarmed_parry_msg",({
                "$n����$v�������𣬽���Ʈ�������������������𣬡����ʮ��ʽ����
����ʽ���������ʹ������������֯��һ��������\n",
                "$n���$v�������������޼�бƮ������ʹ�������ʮ��ʽ���е�ʮһʽ
������ƫ��������$N���ƻ������Ρ�\n",
                "$n��紵������΢΢�������ֻӳ�$v��������ƬƬ��ϼƮ�����ԡ����
ʮ��ʽ���� ��ʮ��ʽ����ϼ��ɢ����$N�����\n",
                                        })      
        );
        action = ({
        ([      "action":               
"$N���ֺ�ü��$wб�������������������ޣ������ƿ���������·��ʵ���飬��ʽ 
����δ�䡣���ǡ����ʮ��ʽ���еĵ�һʽ����������� ",
                "dodge":                100,
                "damage":               533,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������ʮ��ʽ���еڰ�ʽ���綯ǧ�塱����������������������˷���ȴ 
�ֲ��嵽����һ�����졣"NOR,
                "dodge":                120,
                "damage":               540,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������ʮ��ʽ���еڶ�ʽ������ө�𡱣��ؽ�������Ʈ��Ľ����������ͬ
ҹ������ө���裬Ϯ��$n$l��",
                "dodge":                100,
                "damage":               550,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�����ᶶ�ὣ������ֻ������������Ʈҡ������ȴ�ǡ����ʮ��ʽ���е���ʽ
������ɽᰡ� ",
                "dodge":                270,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���ӣ��ƺ���̬���У�ͣ�в�����Ȼ�����Ʋ�����ı��֮���ѷ���$n$l��
���ǡ����ʮ��ʽ���е���ʽ���Ƶ����ᡱ��",
                "dodge":                150,
                "damage":               5100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ӻ���һ���뻡������$w���㣬ʹ�������ʮ��ʽ���е���ʽ����Ѩ���硱�� 
�����Ľ�����Ȼ������˷�����$n��",
                "dodge":                100,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w�������ǰ������б�Ӷ��£�����һת��$wƽƽ�Ƴ���˿˿����ƮȻ������ 
���ǡ����ʮ��ʽ���е���ʽ��˪����������",
                "dodge":                195,
                "damage":               570,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���ƺ�����ң�������ǰƮ�������˷ֲ��巽��Ȼ������ȴ���� 
�����紺���Ⱦ���֡����ǡ����ʮ��ʽ���еھ�ʽ�����Ǵ��硱��",
                "dodge":                110,
                "damage":               50,
                "damage_type":  "����"
        ]),                       
        ([      "action":               
"$Nʹ�������ʮ��ʽ���е�ʮʽ����÷��ѩ����ֻ���������裬�������䣬 
������÷�ڷ���Ʈ��$n$l��",
                "dodge":                195,
                "damage":               5120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w��ת��һ�����̶̵Ļ��⸡����ǰ�����ǡ����ʮ��ʽ���� 
��ʮ��ʽ�����͸�Ƽ����ֻ������Ʈ��������$n$l����",
                "dodge":                260,
                "damage":               5130,
                "damage_type":  "����"
        ]),     
                   
        });
}
int valid_learn(object me)
{
    if((int)me->query("max_force") < 300 ) {
            return notify_fail("�������������û�а취����罣����\n");
        }
        if(!::valid_learn(me)) {
                return 0;
        }
    return 1;
}  
mapping query_action(object me, object weapon)
{
        int attack_act;
        object *victims,victim;
        
        attack_act=random(sizeof(action));
        me->set_temp("qingfeng-act",attack_act); 
        return action[attack_act];
} 
int practice_skill(object me)
{ 
   if((int)me->query("force") < 10 ){
        return notify_fail("�����������������û�а취��ϰ��罣����\n");
    }
    if(!::practice_skill(me)) {
        return 0;
    }   
    me->add("force", -10);
    write("�㰴����ѧ����һ����罣����\n");
    return 1;
}  
mixed hit_ob(object me, object victim)
{       int act;
        int pro;
        int dam;
        int level_bonus;
        
        string damtype;
        object weapon;
        if (me->query_skill_mapped("force") != "hanmei-force")
                return ("");    
        level_bonus = me->query_skill("qingfeng-sword",1);
        act=me->query_temp("qingfeng-act");     
        switch(act) {
                case 2:
                        damtype="kee";
                        break;
                case 5:
                        damtype="gin";
                        break;
                case 8:
                        damtype="gin";
                        break;
                case 9:
                        damtype="sen";
                        break;
                case 1: if (me->query("class")!="huashan") break;
                        if (me->query("combat_exp")<2000000) break;
                        damtype="kee";
                        break;
                case 3: if (me->query("class")!="huashan") break;
                   if (me->query("combat_exp")<2500000) break;
                        damtype="kee";
                        break;
                case 4: if (me->query("class")!="huashan") break;
                        if (me->query("combat_exp")<3500000) break;
                        damtype="kee";
                        break;
                case 6: if (me->query("class")!="huashan") break;
                        if (me->query("combat_exp")<4500000) break;
                        damtype="sen";
                        break;
                }
        if(damtype)
        {
                // To add level bonus, changed 10* to 8*  
                // 03-30-2002
                //  -neon
                dam = 8 * (int) me->query("force_factor");
                dam += 3*level_bonus/2 ;
                pro = victim->query_con();
                if (pro>30)     
                        dam -= (dam*(pro-30))/30;
                victim->receive_damage(damtype,dam,me);
                return (HIY"$n"NOR+HIY"���û���һ�飬�ƺ��ѱ�$N���ھ����ˡ�\n" NOR);
        }               
} 
