 // TIE@FY3
// mapo.c
inherit SKILL;
void setup() {
        set("name", "麻婆寒练术");
        set("usage/spells", 1);
        set("skill_class", "new");
} 
int practice_skill(object me)
{
        return notify_fail("麻婆寒练术只能用学的\n");
}    
