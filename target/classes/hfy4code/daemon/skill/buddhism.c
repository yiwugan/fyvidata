 // buddhism.c
inherit SKILL; 
void setup() {
        set("name",                             "��˷�");
        set("type",                             "knowledge");
        set("learn_bonus",                      -30);
        set("practice_bonus",           -10);
        set("black_white_ness",         40);
        set("effective_level",          180);
        set("usage/literate",           1);
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("���ɱ��̫�أ��޷�������˷𷨡�\n");
        return 1;
}         
