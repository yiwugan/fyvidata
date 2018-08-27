 // fumo-stick.c
inherit SKILL;
void setup() {
        set("name", "少林伏魔棍法");
        set("usage/staff", 1);
        set("usage/parry", 1);
        set("learn_bonus", -110);
        set("effective_level", 210);
        set("practice_bonus", -100);
        set("black_white_ness", 20);
        set("skill_class", "shaolin");
        set("parry_msg", ({
        "$n使出一招「声东击西」，手中的$v往旁边轻挑，引开$N的$w。\n",
        "$n棍法缜密，一招「何去何从」，手中$v舞的密不透风，无懈可击。\n",
        "$n一招「满目苍生」，手中的$v向前一戳，轻松就封住了$N的$w。\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n使出一招「声东击西」，手中的$v往旁边轻挑，引开$N的力道。\n",
        "$n棍法缜密，一招「何去何从」，手中$v舞的密不透风，无懈可击。\n",
        "$n一招「满目苍生」，手中的$v向前一戳，轻松就封住了$N的攻势。\n",
        }) );
        action = ({
        ([      "action":               
"$N使一招「回头是岸」，手中$w反扫，棍尖抖动不停，扫向$n的$l。",
                "damage":               200,
                "dodge":                200,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N一招「降龙伏虎」，原本双手执$w高举，突然凌空向$N的$l。",
                "damage":               210,
                "dodge":                220,
                "parry":                260,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N舞动手中$w，使出一招「苦海无边」，无数棍影连绵不断地击向$n$l。",
                "damage":               220,
                "dodge":                240,
                "parry":                240,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N使出一招「苦海慈航」，$w大开大合，虚虚实实，扫向$n的$l！",
                "damage":               240,
                "dodge":                210,
                "parry":                280,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        });
} 
int valid_learn(object me)
{
	      if(me->query("class") != "shaolin")
	              return notify_fail("只有少林高僧才能领悟少林伏魔棍法。\n");
	      if(me->query_skill("zen",1)<50 &&me->query_skill("zen",1) < me->query_skill("fumo-stick",1) )
	              return notify_fail("你的禅法不够高深，无法继续学习少林伏魔棍法。\n");	      
        if( (int)me->query("str") < 20 ) 
        {
                return notify_fail("你的手臂力量还不够，学习少林伏魔棍法需要25点力量。\n");
        }
        return 1;
} 
int practice_skill(object me)
{   
        return notify_fail("少林伏魔棍法只能用学的。\n");
}   
int check_perform(object me,int lvl)
{
	if(me->query("shaolin/class")=="chan")
	{
		if(lvl>=50)
			tell_object(me,"『降妖』：perform xiangyao\n");
		if(lvl>=125)
			tell_object(me,"『伏魔降妖』：perform fumoxiangyao\n");
		if(lvl<50) tell_object(me,"暂无\n");
	}else if(me->query("shaolin/class")=="wu")
	{
		if(lvl>=100)
			tell_object(me,"『降妖』：perform xiangyao\n");
		if(lvl>=150)
			tell_object(me,"『伏魔降妖』：perform fumoxiangyao\n");
		if(lvl<100) tell_object(me,"暂无\n");
	}
	else tell_object(me,"暂无\n");
	return 1;
}
		
	
	
