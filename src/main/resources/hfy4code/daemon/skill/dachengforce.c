 // dachengforce.c
inherit SKILL; 
void setup() {
        set("name", "����ľ�");
        set("usage/force", 1);
        set("effective_level", 130);
        set("skill_class", "shaolin");
        set("learn_bonus", -70);
        set("practice_bonus", -90);
        set("black_white_ness", 90);
} 
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }
        if((int)me->query("bellicosity") > (int)me->query_skill("doomforce",1) * 10 ) {
        return notify_fail("���ɱ��̫�ߣ��޷����������Ĵ���ľ���\n");
    }
        return 1;
}      
