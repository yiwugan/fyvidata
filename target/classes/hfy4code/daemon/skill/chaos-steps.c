 // chaos-steps.c
inherit SKILL; 
void setup() {
        set("name",                                     "�������ǲ�");
        set("black_white_ness",         10);
        set("usage/dodge",                      1);
        set("effective_level",                  170);
        set("usage/move",                       1);
        set("skill_class",                      "shenshui");
        set("dodge_msg",                        ({
                        "$nһ�С��������ࡹ�������ɵر��˿�ȥ��\n",
                        "ֻ��$n��Ӱһ�Σ�һʽ������Ҳ������ѱ����߳�֮�⡣\n",
                        "$nʹ������ת��Ȩ�����������ɵ�������\n",
                        "$n����һ�㣬һ�С���Ӱ���ࡹ�ڿն��𣬱��˿�ȥ��\n",
                        "����$nʹһ�С��綯��⡹����������Ʈ�˿�ȥ��\n",
                        "$n��Ӱ΢�����Ѿ���һ�С�������������������\n",
                        "����$nһ�С��������١�ʹ���������Ƶ�$N���ᣡ\n"
                        })
        );
} 
int valid_learn(object me) {
        if(!::valid_learn(me)) {
                return 0;
        }
        
        if( (int)me->query("max_force") < 50 ) {
                return notify_fail("�������������û�а취���������ǲ���\n");
        }
        return 1;
}  
int practice_skill(object me) {
        if((int)me->query("force") < 3) {
                return notify_fail("������������������������������ǲ�����\n");
        }
        
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -3);
        return 1;
} 
