 // xiaochengforce.c
inherit SKILL; 
void setup(){
        set("name", "С���ľ�");
        set("usage/force", 1);
        set("effective_level", 140);
        set("learn_bonus", -50);
        set("practice_bonus", -60);
        set("black_white_ness", 50);
        set("skill_class", "shaolin");
} 
int valid_learn(object me){
        if((int)me->query("bellicosity") > (int)me->query_skill("xiaochengforce",1)* 50 ) {
        return notify_fail("���ɱ��̫�ߣ��޷�����������С���ľ���\n");
        }
        return 1;
}  
