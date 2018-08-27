 // nodust-steps.c
inherit SKILL;
void setup(){
        set("name", "�޳�����");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 200);
        set("learn_bonus", 20);
        set("practice_bonus", -60);
        set("black_white_ness", 20);
        set("skill_class", "ghost");           
        set("dodge_msg", ({
        "$nһ�С�������翡��������ɵر��˿�ȥ��\n",
        "ֻ��$n��Ӱһ�Σ�һʽ������ֱ�ϡ����ѱ����߳�֮�⡣\n",
        "$nʹ������շɶɡ����������ɵ�������\n",
        }) );
} 
int valid_learn(object me)
{
    if( (int)me->query("max_force") < 150 ){
        return notify_fail("�������������û�а취���޳�������\n");
        }
    return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 3 ){
        return notify_fail("������������������������޳�������\n");
    }
    if(!::practice_skill(me)) {
        return 0;
    }
    me->add("force", -3);
    return 1;
}      
