 // This is a new unfinished skill, do not attempt to set it or it will cause you problem
//      by silencer@fy@, 9/10/02 
inherit SKILL; 
void setup() {
        set("name", "����֮��");
        set("effective_level", 200);
        set("learn_bonus", -10);
        set("practice_bonus", -5);
        set("black_white_ness", 0);
        set("skill_class", "none");
}  
int valid_learn(object me)
{
        if( me->query_skill("combat_exp") <= 5000000 )
                return notify_fail("����书��Ϊ����������޷�ѧϰ����֮����\n");
        return 1;
}      
