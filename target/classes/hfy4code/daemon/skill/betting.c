 // betting.c
inherit SKILL; 
void setup() {
        set("name",                             "�Ĳ�֮��");
        set("learn_bonus",                      -200);
        set("practice_bonus",           -110);
        set("effective_level",          300);
        set("type",                             "knowledge");
        set("usage/stealing",           1);
        set("usage/perception",         1);
        set("practice_damage",          5);     
} 
int valid_learn(object me) {
        if( (int)me->query_skill("betting") >=  10  && me->query("class")!="beggar") {
                return notify_fail("�Ĳ�֮����������̶�ֻ�ܴ�ʵ������ߡ�\n");
        } 
        return 1;
}     
