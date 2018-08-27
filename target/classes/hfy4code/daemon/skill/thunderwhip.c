 // thunderwhip.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "������");
        set("usage/whip", 1);
        set("usage/parry", 1);
        set("effective_level", 180);
        set("learn_bonus", 20);
        set("practice_bonus", -200);
        set("black_white_ness", 20);
        set("skill_class", "yinshi");
        set("parry_msg", ({
        "$nһ��ת�գ����μ�ʽ�������ߣ������������ޡ�̫����������β��������һ�����棬��סȫ��\n",
                "$nһ�С���������������������ֱ��$N���е�$w\n",
                "$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
                "$n��̤�����λ�λ���ÿ���һ�С�\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$nһ��ת�գ����μ�ʽ�������ߣ������������ޡ�̫����������β��������һ�����棬��סȫ��\n",
        "$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
        "$n��̤�����λ�λ���ÿ���һ�С�\n",
        }) );
        
        action = ({
                ([
                        "action":               
                        "$N��߳һ����˫�ֲ��٣����ⶸ�ɣ���ʱ�˱޺�һ�����ֱ��$n��ȥ",
                        "dodge":                100,
                        "damage":               60,
                        "damage_type":  "����"
                ]),
                ([
                        "action":               
                        "$N���б�Ӱէ�ţ��������ص�⣬��̫�ſ��족��Ȼ��ɨ��",
                        "dodge":                500,
                        "damage":               40,
                        "damage_type":  "����"
                ]),
                ([
                   "action":               
                        "$N��ʽһ�䣬ɱ���Ĳ���չ������������ȥ�޻ص�ɱ�С�̫�ŷ���˵���ԡ�",
                        "dodge":                400,
                        "damage":               150,
                        "damage_type":  "����"
                ]),
                ([
                        "action":               
                        "$NԾ�����ɣ����ڰ�գ���ʽ���䣬��̫���������羪�κ��ˣ���ת�������",
                        "dodge":                400,
                        "damage":               60,
                        "damage_type":  "����"
                ]),
        });
}
int valid_learn(object me)
{
        object ob; 
        if( (int)me->query("max_force") < 50 ){
                return notify_fail("�������������û�а취��������, ����Щ���������ɡ�\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        if((int)me->query("force") < 10 ){
                return notify_fail("�������������û�а취��ϰ�����ơ�\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
        write("�㰴����ѧ����һ�������ơ�\n");
        return 1;
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob,weapon;
    int cele;
    
    if( random(damage_bonus) < 100 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "hammer" || ob->query("skill_type") == "spear"||ob->query("skill_type") == "fork"||ob->query("skill_type") == "staff")
    if(victim->query_skill_mapped("hammer") == "pangu-hammer"
     ||victim->query_skill_mapped("hammer") == "assasin-hammer"
     ||victim->query_skill_mapped("hammer") == "liuxing-hammer"
     ||victim->query_skill_mapped("fork") == "jingang-tieguai" 
     ||victim->query_skill_mapped("staff") == "jingang-tieguai"  
     ||victim->query_skill_mapped("spear") == "jingang-tieguai" 
     )
     
    if(me->query_skill("whip")+50 > victim->query_skill("hammer")) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n�������ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("whip")) * 4;
    }
    return 0;
}        
