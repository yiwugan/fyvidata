 // huashan-steps.c
inherit SKILL;
void setup(){
        set("name", "华山身法");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 110);
        set("learn_bonus", -20);
        set("practice_bonus", -10);
        set("black_white_ness", 40);    
        set("dodge_msg", ({
                "$n肩头微缩，身向后掠，一式「苍松迎客」避在五尺开外。\n",
                "只见$n一招「凌空飞渡」闪过，这一下出招快极，抑且如梦如幻。\n",
                "$n突然绕着$N急转，丈许方园尽是人影，正是一招极为高明的「苍龙盘岭」。\n",
                "$n一式「燕子回时」，猛的踏上一步，身向左转，敌招都落在空处。\n",
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练华山身法。\n"); 
        return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("force") < 3 ) {
                return notify_fail("你的气或内力不够，不能练华山身法。\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -3);
        return 1;
}    
