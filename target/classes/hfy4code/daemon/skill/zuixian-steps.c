 // zuixian-steps.c
inherit SKILL; 
void setup() {
        set("name",                                     "�������²�");
        set("usage/dodge",                      1);
        set("usage/move",                       1);
        set("effective_level",          150);
        set("skill_class",                      "yinshi");
        set("dodge_msg",                        ({
                        "����$n����Ʈ��������һ�ݣ�һ�С��������¡�������׾ٵıܿ���һ����\n",
                        "$n������ת��һʽ�����˾��ơ������Դܿ����ߣ����˿�ȥ��\n",
                        "$n�������ϰ���һ�С��ѾƷ��ɡ���һ��ת����������֮�⡣\n"
                        })
        );
}   
int practice_skill(object me)
{
        if( (int)me->query("force") < 5 ){
            return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -5);
        return 1;
}      
