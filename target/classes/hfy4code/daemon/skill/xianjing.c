 inherit SKILL;
void setup(){
        set("name", "�ɾ��ķ�");
        set("usage/force", 1);
        set("effective_level", 150);
        set("learn_bonus", 40);
        set("practice_bonus", 10);
        set("skill_class", "huangshan");
}  
int valid_learn(object me)
{
        object ob;
        if(!::valid_learn(me)) {
                return 0;
        }
        if (me->query("class")!="huangshan")
                return notify_fail("�㻹����ѧ�����书��\n");
         return 1;
} 
