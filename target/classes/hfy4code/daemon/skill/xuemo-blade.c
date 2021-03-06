//血魔刀，源自于《血鹦鹉》中13位血奴所使用的刀法
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "血魔刀法");
        set("usage/blade", 1);
        set("usage/parry", 1);
        set("usage/dodge", 1); 
        set("effective_level", 300);
        set("learn_bonus", -500);
        set("black_white_ness", -200);
        set("skill_class", "xuemo");
        
        set("dodge_msg", ({
        "$n纵身一跃，向后疾退三丈，顿时$N的攻势就化为无形！\n",
                "$N只觉得眼前的$n身影慢慢变得模糊，蒙胧，然后竟完全消失......！$N一击落空！！\n",
                "$N突然变招，不退反进，但却发现击中的$n竟然是一个镜像！\n",
                "$n就这样蒙蒙胧胧站在那里，但$N却连$n的一片衣衫都没有碰到！\n",
        }) ); 
        set("parry_msg", ({
        "$n诡秘的眼神突然非常迷漓，$N竟然也变得神情恍惚，手中$w不由自主跟着$n的$v转动。\n",
//《血鹦鹉》中描写魔刀出刀时，就像一轮新月。
        "$n手中的$v犹如空中新月，新月射出的刀光竟然把$N手中的$w震开，$N手臂发麻，$w差点脱手！\n",
        "$n握住$v划了一个怪异的圆圈，空气中魔意陡增，$N感到全身发悸，手中$w不由得慢了下来！\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n笑容怪异，$N只觉魔意拂面，心中一惊，硬生生的收回自己的招式。\n",
        "$N突然进招，但当击中$n时却发现那只不过是一个虚影！\n",
        }) );
        action = ({
        ([ "action": "$N手中$w一闪，$n面前出现一轮充满魔意的新月......！",
                "damage": 200,
                "dodge": 400,
                "parry": 400,
                "damage_type": "砍伤"
        ]),
        ([ "action": "$N身形缥缈，手中$w随意一挥，十万神魔顿时涌现在$n眼前！",
                "dodge": 300,
                "parry": 500,
                "damage": 200,
                "damage_type": "砍伤"
        ]),
        ([ "action": "$N诡笑一声，$w刀光闪动，四面魔气竟然把$n笼罩其中！",
                "damage": 200,
                "dodge": 600,
                "parry": 400,
                "damage_type": "割伤"
        ]),
        ([ "action": "$N手中$w突然变的血红,$w顿时魔意无限！$n心生惧意，竟然无法闪躲！",
          "damage": 250,
                "dodge": 1400,
                "parry": 1200,
                "damage_type": "砍伤"
        ]),
        ([ "action": "$n眼睛一花，血红的$w诡异般出现在$n的喉前！",
                "damage": 150,
                "dodge": 100,
                "parry": 400,
                "damage_type": "割伤"
        ]), 
        });
} 
int practice_skill(object me)
{
       return notify_fail("「血魔刀法」精妙无比，你不可能靠练习来体会其中精义！\n");
} 

mixed hit_ob(object me, object victim, int damage_bonus)
{
           object ob,my_weapon;
           int badint;
           
           int act, pro, dam; //以下添加
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
                return (WHT "$n只见眼前群魔共舞，心生惧意，神志开始有些迷糊不清！！\n" NOR);
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
                return (WHT "$n只见眼前群魔共舞，心生惧意，神志开始迷糊不清！！\n" NOR);
        }
        //以上添加
        if( random(damage_bonus) < 200 ) return 0;
        if(ob=victim->query_temp("weapon"))
        if(ob->query("skill_type") == "blade")
        if(victim->query_skill_mapped("blade") == "bat-blade")
                if(me->query_skill("blade") > victim->query_skill("blade"))
                {
                    switch(random(2)) {
                    case 0:
                        message_vision(HIR "\n因刀法相克，$N占尽了上风！"NOR,me,victim);
                        break;
                    case 1:
                        message_vision(HIR "\n$N的魔刀轻易攻入$n的空隙之中！" NOR,me,victim);
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
                                case 0: return HIR"$N手中"+my_weapon->query("name")+HIR"透出的魔气,竟刺破了$n的护体神功！\n"NOR;
                                case 1: return HIR"$n只觉全身一凉,$N的"+my_weapon->query("name")+HIR"竟透体而入 ．．．\n"NOR;
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
                return (WHT "$n只见眼前群魔共舞，心生惧意，神志开始有些迷糊不清！！\n" NOR);
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
                return (WHT "$n只见眼前群魔共舞，心生惧意，神志开始迷糊不清！！\n" NOR);
        }
} */
mixed parry_ob(object victim, object me)
{       int busy_time,alr_busy_time;
        int level;
        if (victim->query("race")=="野兽") return 0;
        if (victim->query_temp("xuemo-parry")!=1)     return 0;
        level = me->query_skill("xuemo-sword",1);
        if (level < 50) return 0;
        alr_busy_time=victim->query_busy();
        
        busy_time=random(7);
        if(!busy_time) return 0;
        if(busy_time>alr_busy_time)     victim->start_busy(busy_time);
        return RED"$N"RED"被$n"RED"眼前的魔影所惑，一时不知如何招架！！\n"NOR;
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