 // TIE@FY3
inherit SKILL;
void setup(){
        set("name", "金刚铁拐");
        set("usage/fork", 1);
        set("usage/axe", 1);
        set("usage/staff", 1);
        set("usage/spear", 1);
        set("usage/hammer", 1);
        set("usage/parry", 1);
        set("practice_damage", 30);
        set("effective_level", 150);
        set("practice_limit",150);
        set("learn_bonus", -1000);
        set("practice_bonus", -5);
        set("skill_class", "new");
        
        set("parry_msg", ({
        "结果$n一招「一气呵成」，挥动手中$v格开了$N的$w。\n",
        "结果$n手中$v一分，一招「力拔山河」，斜劈$N的$w。\n",
        "结果$n手中$v抡动如飞，一招「千里追风」，荡开$N的$w。\n",
        "结果$n手中$v飞速旋转，一招「百鸟朝凤」，反扫$N的$w。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n手中的$v舞动如飞，一招「铜墙铁壁」，封住了$N的攻势。\n",
        "$n身影晃动，一招「秋风落叶」，反砍$N的下盘。\n",
        "$n身形一矮，一招「霸王举鼎」，躲过$N的攻势。\n",
        "$n手中的$v自上而下，一招「回头是岸」，反劈$N的要害。\n",
        }) );   
        action = ({
        ([      "action":               
"$N手中$w抡开，挟着呼呼风声，一招「金碧辉煌」，直取$n的各处要害！",
                "dodge":                -550,
                "parry":                -1500,
                "post_action":  "bash_weapon",
                "damage_type":  "砸伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w风声呼啸，一招「金榜题名」，横空向$n$l扫去！",
                "dodge":                -360,
                "parry":                -1010,
                "post_action":  "bash_weapon",
                "damage_type":  "砸伤"
        ]),
        ([      "action":               
"$N手中$w接连劈出，，一招「金篦刮目」，旋风般舞向$n$l！",
                "dodge":                -350,
                "parry":                -550,
                "post_action":  "bash_weapon",
                "damage_type":  "砸伤"
        ]),
        ([      "action":               
"$N使出一招「金蝉脱壳」，手中$w舞动，身随起势，化作一溜烟尘，滚滚奔向$n的$l！",
                "dodge":                -1040,
                "parry":                -540,
                "post_action":  "bash_weapon",
                "damage_type":  "砸伤"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 15 ){
            return notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");
        }
        if( me->query_skill("sword")>1 || me->query_skill("blade") >1|| me->query_skill("dagger") > 1 ){
            return notify_fail("金刚铁拐似乎与传统刀剑短刃等兵器用法不同，你一时之间不知从何学起。\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("jingang-tieguai",1)>100)
                return notify_fail("高级的金刚铁拐只能学的。\n");
        
        if( (int)me->query("force") < 10 ){
            return notify_fail("你的内力不够了，休息一下再练吧。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -10);
        return 1;
}      
int effective_level()
{
        object me=this_player();
        int skill,n;
         skill=me->query_skill("jingang-tieguai",1);
        if (skill > 199) return 300;
        if (skill < 200) return 150;
        
                
}  
