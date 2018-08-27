 // unarmed.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "扑击格斗之技");
        set("effective_level",50);
        set("learn_bonus", 5);
        set("unarmed_parry_msg", ({
                "但是被$n挡开了。\n",
                "但是被$n格开了。\n",
/*              "$n左腿略挫，右掌虚晃，呼的一声，左拳猛击而出，劲雄势急，$N只得撤手换招。\n",
                "$n不退不避，运劲出拳，往$N面门猛击过去，卸去了$N的攻势。\n",
                "$n下盘不动，上盘不避，将腰向左一挪，斗然移开半尺，右手送出，将$N格开。\n",
                "$n衣袖轻抖，人向右转，左手衣袖突从身后向$N肩头拂去，以巧劲化去了$N的掌力。\n",
                "$n举手挡格，双臂相交，两人各退一步。\n",*/
        }) ); 
        set("parry_msg", ({
                "但是被$n挡开了。\n",
                "但是被$n格开了。\n",
/*              "$n左腿略挫，右掌虚晃，呼的一声，左拳猛击而出，劲雄势急，$N只得撤手换招。\n",
                "$n举手一挡，反腕钩出，竟已拿住了$N击来的$w。\n",
                "$n立定马步，扬声吐气，嘿的一声，一拳打在$N的$w正中。\n",
                "$n衣袖轻抖，人向右转，左手衣袖突从身后向$N肩头拂去，以巧劲化去了$N的招式。\n",
                "$n下盘不动，上盘不避，将腰向左一挪，斗然移开半尺，右手送出，将$N格开。\n",
                "$n手腕翻处，伸手硬抓$N的兵刃。\n",*/
        }) );
}   
void skill_improved(object me)
{
        int s; 
        s = me->query_skill("unarmed", 1);
        if( s%10==9 && (int)me->query("str") < s/5) {
                tell_object(me, HIW "由於你勤练武艺，你的力量提高了。\n" NOR);
//              me->add("str", 2);
                me->set("str",(s+1)/5);
        }
}  
