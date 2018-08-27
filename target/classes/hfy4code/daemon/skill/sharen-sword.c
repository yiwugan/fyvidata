 // sharen-sword.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "ɱ�˽���");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("effective_level", 150);
        set("practice_bonus", 0);
        set("practice_limit",180);
        set("black_white_ness", 0);
        set("skill_class", "assassin");
        set("parry_msg", ({
                "$n���е�$v��һ��ָ������$N��$l����������\n",
                "$n����һ����$vЮ�������������$N��$l��\n",
                "$n����һ�������е�$v�������ϴ���$N��$l��\n",
                "$n���н��Ⱪ������ǧ����Ы��$N$lҧȥ��\n",
        }) ); 
        set("unarmed_parry_msg", ({
                "$n���е�$v��һ��ָ������$N����������\n",
                "$n����һ����$vЮ�������������$N��\n",
                "$n����һ�������е�$v�������ϴ���$N��\n",
                "$n����$v���Ⱪ������ǧ����Ы��$Nҧȥ��\n",
        }) );   
        action = ({
                ([      "name":                 "a",
                        "action":               "$N���е�$w��һ��ָ������$n��$l��������",
                        "dodge":                50,
                        "parry" :               100,
                        "force":                170,
                        "damage" :              150,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "b",
                        "action":               "$N����һת�����е�$w����������$n��$l���˹�ȥ",
                        "dodge":                50,
                        "damage":               170,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "c",
                        "action":               "$N����һ����$wЮ�������������$n��$l",
                        "dodge":                40,
                        "damage" :              50,
                        "force" :               120,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "d",
                        "action":               "$N����һ�������е�$w�������ϴ���$n��$l",
                        "dodge":                40,
                        "damage":               80,
                        "damage_type":  "����"
                ]),
           ([      "name":                 "e",
                        "action":               "$N����$w���Ⱪ������ǧ����Ы��$n$lҧȥ",
                        "dodge":                160,
                        "damage":               120,
                        "damage_type":  "����"
                ]),
                ([      "name":                 "f",
                        "action":               "$N���е�$w���޷����ݵ��ٶ�ֱ��$n��$l",
                        "dodge":                120,
                        "force" :               100,
                        "damage":               150,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
        if ( me->query("family/master_id")!="master shangguan" 
                && me->query("family/master_id")!="master jin"
                && me->query_skill("sharen-sword",1)>160)
                return notify_fail ("�����ɱ�˽���ֻ�ܸ���Ǯ���ʦ��ѧ��\n"); 
        if ( (int)me->query_skill("lefthand-sword",1)<75)
                return notify_fail ("ѧ��Ҫѭ�򽥽���ɱ�˽�����Ҫ75�����ֽ���Ϊ����\n");
        if( (int)me->query("max_force") < 200 )
                return notify_fail("�������������û�а취��ɱ�˽�����\n");
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 10 ){
                return notify_fail("�����������������û�а취��ϰɱ�˽�����\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
        write("�㰴����ѧ����һ��ɱ�˽�����\n");
   return 1;
} 
void skill_improved(object me)
{
        if( (int)me->query_skill("sharen-sword", 1)     % 10 == 0 ) {
                tell_object(me,
                        RED "\n��ͻȻ����һ�ɶ���������ͷ��ֻ������ɱ��....\n�����ȥɱ�����߹ٸ��̽������....\n\n" NOR);
                me->add("bellicosity", 1000);
                me->set("vendetta/authority", 1);
        } else
                me->add("bellicosity", 200);
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object ob;
        if( random(damage_bonus) < 200 ) return 0;
        if(ob=victim->query_temp("weapon"))
        if(ob->query("skill_type") == "staff")
        if(victim->query_skill_mapped("staff") == "cloudstaff"
                || victim->query_skill_mapped("spear") == "xuezhan-spear")
        if(me->query_skill("sword") > victim->query_skill("staff")
                ||me->query_skill("sword")+80 > victim->query_skill("staff") ) {
        switch(random(3)) {
                case 0:
                        message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                        break;
                case 1:
                        message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                        break;
                case 2:
                        message_vision(HIR "\n���书·����ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                        break;
                        }
        return random(me->query_skill("sword")) * 3;
        }
        return 0;
}   
