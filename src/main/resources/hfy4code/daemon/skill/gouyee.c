 // gouyee.c
inherit SKILL;
void setup() {
        set("name", "�����ķ�");
        set("usage/force", 1);
        set("skill_class", "taoist");
        set("effective_level", 130);
        set("learn_bonus", 0);
        set("practice_bonus", 5);
        set("black_white_ness", -20);
} 
int valid_learn(object me)
{
    if((int)me->query_skill("taoism",1) < (int)me->query_skill("gouyee",1)){
        return notify_fail("�����ʦ�����������޷����������ķ������衣\n");
        }
    return 1;
}        
