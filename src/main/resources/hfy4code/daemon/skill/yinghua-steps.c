 // yinhua-steps.c 樱花步法
inherit SKILL;
void setup(){
        set("name", "樱花步法");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 250);
        set("learn_bonus", -50);        
        set("skill_class", "bat");      
        set("dodge_msg", ({
        "$n身行一转，猛的跳向一旁,躲过了$N的攻势。\n",
        "$n身体如一只苍鹰，呼的一声从$N的眼前飞过。\n",
        "$n全身化为一道白影，忽的一个空翻，从左边飘到右边。\n",
        "$n忽的拔地而起，在半空中一转，已落到几丈远的地方。\n",
        "$n宛若一条矫矢苍龙，倏的拔地而起，令$N不敢仰视。\n",
        }) );
}     
