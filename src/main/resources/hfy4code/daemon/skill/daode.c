 // daode.c
inherit SKILL; 
void setup() {
        set("name", "���¾�");
        set("effective_level", 200);
        set("learn_bonus", -30);
        set("practice_bonus", -10);
        set("black_white_ness", 40);
        set("type", "knowledge");
        set("usage/literate", 1);
}        
/*
int valid_learn(object me) 
{
        if(!::valid_learn(me)){
                return 0;
        }
        if( (int)me->query("bellicosity") > 100 ) {
                return notify_fail("���ɱ��̫�أ��޷��������¾���\n");
        }
        return 1;
} 
*/     
