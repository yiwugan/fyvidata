 // celestial.c
inherit SKILL; 
void setup() {
        set("name",                             "��а��");
        set("black_white_ness",         -50);
        set("usage/force",                      1);
        set("effective_level",  500);
        set("skill_class",                      "new");
}  
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if((int)me->query("bellicosity") < (int)me->query_skill("celestial") * 50) {
                return notify_fail("���ɱ���������޷�������������а�񹦡�\n");
        }
        return 1;
}    
