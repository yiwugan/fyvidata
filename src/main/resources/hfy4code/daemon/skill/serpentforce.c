 // serpentforce.c
inherit SKILL;
void setup(){
        set("name", "伏蛟功");
        set("usage/force", 1);
        set("skill_class", "beggar");
}
int practice_skill(object me)
{
    if( !environment(me)->query("resource/water") ){
        return notify_fail("伏蛟功只能在有水的地方练。\n");
    }
    if( (int)me->query("force") < 10 ){
        return notify_fail("你的内力不够");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -10);
    return 1;
}  
