 // xiaohun-sword.c
#include <ansi.h>
inherit SKILL;
int check_skill(object victim) ; 
void setup(){
        set("name", "��Ȼ���꽣��");
        set("usage/sword", 1);
        set("usage/parry", 1);
        set("practice_damage", 100);
        set("effective_level", 300);
        set("learn_bonus", -850);
        set("practice_bonus", -300);
        set("black_white_ness", 0);     
        set("skill_class", "new");
        set("parry_msg", ({
                "$n����$v��һƬ��������ƮƮ�ط���һʽ[��������]��$N���ˡ�\n",
        "������ɢ��$n��Ȼ���ף�[����������ݺ] ���Ķ�������㽣Ӱ����
Ʈ����$N��ʱ�в�֪����ĸо���\n",
        }) ); 
        set("unarmed_parry_msg", ({
                "$n����$v��һƬ��������ƮƮ�ط���һʽ[��������]��$N���ˡ�\n",
        "������ɢ��$n��Ȼ���ף�[����������ݺ] ���Ķ�������㽣Ӱ����
Ʈ����$N��ʱ�в�֪����ĸо���\n",
        }) );
        
        action = ({
        ([      "action":               
"$Nһչ$w��һ��[��ʱ��ɫ]�������ʣ�������ã�����$n������ ",
                //"dodge":                50,
                "damage":               530,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w��ڣ�����������������֣����������ξ��ĸо�����Ȼ�䣬
���㽣����������$n��������Ȼ���꽣����[�����軨]��",
                //"dodge":                120,
                "damage":               630,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ���Ƴ���һ��[ҹѩ����]��ֻ��������֯����$n",
                //"dodge":                155,
                "damage":               850,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ؽ�������ʹ��[��������]��ƬƬ��Ӱ����ȴ��Ȼ�������������$n",
                "dodge":                300,
                "damage":               320,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������į������$w����бָ��$w��Ȼɫת�Ա̣���Ȼ���꽣���ľ���
[�Ľ�һҹ̦��]�Ѿ��������������������̦�̵���$n������",
//                "dodge":                150,
                "damage":               1500,
                "damage_type":  "����"
        ]),
        });
}
void skill_improved(object me)
{
        int s; 
        s = me->query_skill("xiaohun-sword", 1);
        if( s==175 && me->query("class") == "swordsuper" ) {
                tell_object(me, HIB"�����������гɣ��������꽣���ϵ�����ͻ���ͽ�������\n" NOR);
                me->set_skill("xiaohun-sword", 199);
//                me->set("con",(s+1)/5);
        }
        if( s==225 && me->query("class") == "swordsuper" ) {
                tell_object(me, HIB"�����������гɣ��������꽣���ϵ����и���һ�㣡����\n" NOR);
                me->set_skill("xiaohun-sword", 249);
                me->set("SUPERER",1);
//                me->set("con",(s+1)/5);
        }

        if( s==275 && me->query("class") == "swordsuper" ) {
                tell_object(me, HIB"�����������гɣ��������꽣���ϵ����дﵽ�˵߷壡����\n" NOR);
                me->set_skill("xiaohun-sword", 299);
//                me->set("con",(s+1)/5);
        }

} 
int valid_learn(object me)
{
       if (!me->query("m_success/���괫��") && (me->query("class")!="swordsuper") )
                return notify_fail("��һ�������꽣�����д����ˣ�ѧ��������޷��ɡ�\n");
        
        if( (int)me->query("max_force") < 500 ){
            return notify_fail("�������������û�а취����Ȼ���꽣����\n");
        }       
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        return notify_fail("��Ȼ���꽣��ֻ����ѧ�ġ�\n");
} 
mapping query_action(object me, object weapon) 
{
        int act;
   act=random(sizeof(action));
        me->set_temp("xiaohun-act",act);
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
                this_player()->set_temp("xiaohun-parry",act);
                return msg[act];
        }
        
        return 0;
} 
mixed hit_ob(object me, object victim){ 
        int act, pro, dam;
        
        act=me->query_temp("xiaohun-act");      
        if(act==1)
        {
                dam = (int) me->query("max_force");
                dam = (random(dam)+dam)/2;
                pro = victim->query("con");
                if (pro>30)
                {
                        dam = dam*(1-(pro-30)/30);
                }
                victim->receive_damage("sen",dam/10);
                return (HIY "$nֻ����Ȼ���ˣ�������ģ��������\n" NOR);
        }
        if(act==4)
        {
                dam = (int) me->query("max_force");
                dam = (random(dam)+dam)/2;
                pro = victim->query("con");
                if (pro>30)
                {
                        dam = dam*(1-(pro-30)/30);
                }
                victim->receive_damage("sen",dam/10);
                return (HIY "$nֻ����Ȼ���ˣ�������ģ��������\n" NOR);
        }
} 
mixed parry_ob(object victim, object me)
{       int busy_time,alr_busy_time;
        int level;
        if (victim->query("race")=="Ұ��") return 0;
        if (victim->query_temp("xiaohun-parry")!=1)     return 0;
        //if (!check_skill(victim)) return 0;
        level = me->query_skill("xiaohun-sword",1);
        if (level < 50) return 0;
        alr_busy_time=victim->query_busy();
        
        busy_time=random(7);
        if(!busy_time) return 0;
        if(busy_time>alr_busy_time)     victim->start_busy(busy_time);
        return HIB"$N"HIB"��$n"HIB"�Ľ�������һʱ��������η�Ӧ��\n"NOR;
}         
int check_skill(object victim) {
        
        object weapon;
        
        if (weapon=victim->query_temp("weapon"))
        if (weapon->query("skill_type")=="blade" && victim->query_skill("blade",1)>100 
                && victim->query_skill("shenji-blade",1)>100
                && victim->query_skill_mapped("blade")=="shenji-blade")
                return 0; 
        return 1;
}        

