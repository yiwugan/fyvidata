 // taoism.c
inherit SKILL;
void setup(){
        set("name", "��ʦ����");
        set("usage/literate", 1);
        set("type", "knowledge");
        set("effective_level", 200);
        set("learn_bonus", -50);
        set("practice_bonus", -25);
        set("black_white_ness", 30);
} 
int valid_learn(object me) 
{
        if( (int)me->query("bellicosity") > 100 )
                return notify_fail("���ɱ��̫�أ��޷�������ʦ������\n");
        return 1;
}  
