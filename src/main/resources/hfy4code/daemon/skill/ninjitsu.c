 // ninjitsu.c
inherit SKILL; 
void setup(){
        set("name", "����");
        set("usage/magic", 1);
        set("skill_class", "ninja");
        set("effective_level", 180);
        set("learn_bonus", 0);
        set("practice_bonus", -5);
        set("black_white_ness", 0);
}
int practice_skill(object me)
{
        return notify_fail("����ֻ����ѧ�ġ�\n");
} 
int valid_learn(object me)
{
        object ob;
        
        if(!::valid_learn(me)) {
                return 0;
        }
        if (!me->query("tianfeng/done_quest"))
                return notify_fail("���ʮ����δ��Ӧת���������书��\n");
        if ((int)me->query("tianfeng/ninjitsu")!=1){
                return notify_fail("���ʮ����δ��Ӧ���������书��\n");
        }
        return 1;
}
