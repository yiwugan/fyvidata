 // huashan-steps.c
inherit SKILL;
void setup(){
        set("name", "��ɽ��");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 110);
        set("learn_bonus", -20);
        set("practice_bonus", -10);
        set("black_white_ness", 40);    
        set("dodge_msg", ({
                "$n��ͷ΢����������ӣ�һʽ������ӭ�͡�������߿��⡣\n",
                "ֻ��$nһ�С���շɶɡ���������һ�³��п켫������������á�\n",
                "$nͻȻ����$N��ת������԰������Ӱ������һ�м�Ϊ�����ġ��������롹��\n",
                "$nһʽ�����ӻ�ʱ�����͵�̤��һ����������ת�����ж����ڿմ���\n",
        }) );
} 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취����ɽ����\n"); 
        return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("force") < 3 ) {
                return notify_fail("�������������������������ɽ����\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -3);
        return 1;
}    
