 // doomforce.c
inherit SKILL; 
void setup() {
        set("name", "��Ѫ��");
        set("usage/force", 1);
        set("effective_level", 260);
        set("learn_bonus", -300);
        set("black_white_ness", -50);
        set("skill_class", "fighter");
        
}       
int valid_learn(object me)
{
        if(!::valid_learn(me)) {
                return 0;
        }
        if((int)me->query("bellicosity") < (int)me->query_skill("doomforce")*5){ 
                return notify_fail("���ɱ���������޷����������Ĵ�Ѫ�񹦡�\n");
        }
        return 1;
}    
