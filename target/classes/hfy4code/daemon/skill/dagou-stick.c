 // silencer@fy4.com
//打狗棒法共有八诀，
//绊、Lvl 60  pfm
//劈、normal attack
//缠、Lvl 180 auto
//戳、Lvl 20  pfm
//挑、Lvl 100 pfm
//引、Lvl 80  pfm
//封、Lvl 140 auto
//转  Lvl 160 auto
//天下无狗 Lvl 120 
inherit SKILL;
#include <ansi.h> 
void setup() {
        set("name", "打狗棒法");
        set("usage/staff", 1);
        set("usage/parry", 1);
        set("learn_bonus", -200);
        set("practice_bonus", -5);
        set("practice_limit",150);
        set("skill_class", "beggar");   
        set("effective_level", 210);
        set("parry_msg", ({
        "$n使出个“缠”字诀，$n有如一根极坚韧的细藤，粘在$N的$w上。\n",
        "$n不避不闪，一招「双龙夺珠」，手中$v直取$N的双目。\n",
        "$n$v疾翻，搭在$w半腰，顺势向外牵引。\n",
        "$n$v缩回，使起“挑”字诀，搭住$w向上甩出。\n",
                })
        );
        set("unarmed_parry_msg", ({
        "$n伸出$v，一招“拨狗朝天”，封住了$N的攻势。\n",
        "$n不避不闪，一招「双龙夺珠」，手中$v直取$N的双目。\n",
        "$n挥出$v，蓦地点向$N的面门。\n",
        })      
        );      
        action = ({
([      "action": "$N使出一招「棒打双犬」，手中$w化作两道青光砸向$n的$l",
        "dodge": 10,
        "parry": 70,
        "damage": 90,
        "damage_type": "挫伤"
]),
([      "action": "$N手中$w左右晃动，倏然中宫直进，径点$n前胸“紫宫穴”",
        "dodge": 20,
        "parry": 100,
        "damage": 120,
        "damage_type": "挫伤"
]),
([      "action": "$N一招“劈字诀”，从背后以肩为支，$w扳击而下，威猛异常",
        "dodge": 20,
        "parry": 100,
        "damage": 320,
        "damage_type": "挫伤"
]),
([      "action": "$N一声怪啸，飘身而进，手中$w暴起，化作漫天棒影，向$n下盘扫去",
        "dodge": 20,
        "parry": 50,
        "damage": 120,
        "damage_type": "挫伤"
]),
([      "action": "$N使出打狗棒法中“沾”“挑”“抹”“拌”诸般法诀，灵蛇也似招招不离$n的要害",
        "dodge": 20,
        "parry": 270,
        "damage": 120,
        "damage_type": "挫伤"
]),
([      "action": "$N提起$w，一招「棒打狗头」，往$n头顶击去，出手狠辣，来势迅猛",
        "dodge": 20,
        "parry": 110,
        "damage": 120,
        "damage_type": "挫伤"
]),
([      "action": "$N使出「拨狗朝天」，$w由下往上向$n撩去",
        "dodge": 120,
        "parry": 70,
        "damage": 180,
        "damage_type": "挫伤"
]),
([      "action": "$N使出「关门打狗」，但见$w化成了一团碧影，猛点$n后心各大要穴",
        "dodge": 120,
        "parry": 300,
        "damage": 150,
        "damage_type": "挫伤"
]),
        });
} 
int valid_learn(object me)
{
    if(!::valid_learn(me)) {
        return 0;
    }
    if( (int)me->query("str") + (int)me->query("max_force") / 10 < 15 ) {
        return notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if( (int)me->query("kee") < 10 ) 
                return notify_fail("你的体力不够练这门棍法，还是先休息休息吧。\n");
        
        if(!::practice_skill(me)) return 0;
        me->add("force",-5);
        return 1;
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object ob,weapon;
        int myexp,urexp;
            
        myexp=me->query("combat_exp");
        urexp=victim->query("combat_exp")*victim->query("cps")/20;
        weapon=me->query_temp("weapon"); 
        if (!victim->is_busy())
        if (random(myexp+urexp)>urexp && me->query_skill("dagou-stick",1)>=180
                &&!me->query_temp("dagou/pfm") && me->query("class")=="beggar"
                && me->query_skill_mapped("force") == "huntunforce"){
                if (victim->query_busy()<2) victim->start_busy(2);
                message_vision(HIW "\n$N使出[缠字诀]，手中"+weapon->name()+HIW"有如一根极坚韧的细藤，缠住了$n。\n"NOR,me,victim);
         }   
           
         if(random(damage_bonus) < 250 ) return 0;
         if(ob=victim->query_temp("weapon"))
         if(ob->query("skill_type") == "whip")
         if(victim->query_skill_mapped("whip") == "thunderwhip")
                if(me->query_skill("staff") > victim->query_skill("whip")) {
                switch(random(3)) {
                    case 0:
                            message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                            break;
                    case 1:
                            message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                            break;
                    case 2:
                            message_vision(HIR "\n因棍鞭法相克，$n逐渐施展不开了！" NOR,me,victim);
                            break;
                            }
            return random(me->query_skill("staff")) * 3;
         }
         return 0;
}  
mixed parry_ob(object victim, object me)        {       
        
        int skill, my_exp, your_exp;
        string msg;
        
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        skill = me->query_skill("dagou-stick",1);
        
        if (!me->query_temp("dagou/feng") && me->query_skill("dagou-stick",1)>=140
                && me->query("class")=="beggar") {
                msg=CYN"\n$N"+CYN"使出打狗棒法中的「封字诀」，但见满天棒影，登时将自己身前数尺之地尽数封住。\n"NOR;
                message_vision(msg,me);
                me->set_temp("dagou/feng",1);
                me->add_temp("apply/parry",skill/5);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5:), 10);
                return;
        } 
        if (victim->query("race")=="野兽") return 0; 
   if (4*random(my_exp)>your_exp && me->query_skill("dagou-stick",1)>=160
                && me->query("class")=="beggar") {
                me->set_temp("counter_action",1);
                me->set_temp("counter_msg",HIY"$N使出打狗棒法「转字诀」，手中棒儿借机反击。\n"NOR);
                return 0;
        } 
}         
void remove_effect(object me, int amount)
{
        me->add_temp("apply/parry", -amount);
        me->delete_temp("dagou/feng");
        tell_object(me, "你的「封字诀」运转完毕。\n");
}    
