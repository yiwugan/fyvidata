 // shudao.c
#include <ansi.h>
inherit SKILL; 
void setup() {
        set("name", "蜀道提纵术");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 175);
        set("learn_bonus", -15);
        set("practice_bonus", -5);
        set("black_white_ness", -20);
        set("skill_class", "tang");
        set("dodge_msg", ({
                "$n身形前冲有如悲鸟入空山，滑翔而过。\n",
                "只见$n腰往后微折，一式「难于上青天」从一个不可思议的角度跃起。\n",
                "$n右足一点，身形腾空而起，恰似猿猴攀石，利索闪过。\n",
                "$n凌空一个转身，人平地而起，身法仿如飞湍瀑流，干净、漂亮、利落。\n",
                "$n人在半空之中，双脚互踏着力，一止下沉身法，再提气跃起。\n",
                "$n一式「枯松倒挂倚绝壁」，倒纵后飞。\n",
                "$n闻风而动，踏入空门，以一式「避猛虎避长蛇」躲开这一击。\n",
                "$n左脚一伸，右脚一屈，犹如黄龙腾空，骇然正是「六龙回日」之精妙所在。\n",
                "$n身影晃动，步法急转，使出一式「雄飞雌从绕林间」左闪右避。\n",
                "$n向前一扑，身形几近贴地，却从杀气最盛之处穿越而出。\n",
                
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 ) {
                return notify_fail("你的内力不够，没有办法学蜀道提纵术。\n");
        }
        return 1;
} 
