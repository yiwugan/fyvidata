inherit SKILL; 
void setup() {
        set("name",     "铁血心法");
        set("learn_bonus",     -10);
        set("practice_bonus",  -10);
        set("black_white_ness", 15);
        set("effective_level", 150);
        set("usage/force",       1);
        set("skill_class",  "tieflag");     
}  

int valid_learn(object me)
{
        if(!::valid_learn(me))
                return 0;
        if (!me->query("mark/learn_tiexue"))
                return notify_fail("铁血心法为大旗门副掌门云铮之秘决，未经其指点则无法领会！\n");
        return 1;
} 