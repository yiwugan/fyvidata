 // begging.c
inherit SKILL; 
void setup() {
        set("name",                             "�Ů��");
        set("learn_bonus",                      35);
        set("effective_level",          180);
        set("type", "knowledge");
        set("skill_class",              "shenshui");
}  
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        if((string)me->query("class") != "shenshui" ) 
                return notify_fail("�Ů������ˮ�����Ӷ��е��书��\n");
        return 1;
}
