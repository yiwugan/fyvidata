 // wuchen-steps.c
 
inherit SKILL; 
void setup(){ 
        set("name", "�����޳���"); 
        set("usage/dodge", 1); 
        set("usage/move", 1); 
        set("effective_level", 150); 
        set("learn_bonus", -20); 
        set("practice_bonus", -10); 
        set("black_white_ness", 40); 
        set("skill_class", "quanli"); 
        set("dodge_msg", ({ 
                "$n�������ĵ���������һ�����պñܹ�$N���������ơ�\n", 
                "����$nǡ����������һ���������$N��һ�С�\n", 
                "ֻ��$nһ�С����鳾�����������ϱ�ֱ���������࣬�����$N��һ�С�\n", 
                "$nһ������������������ݳ�����֮Զ���ܿ���$N���������ơ�\n", 
                "$nʹ��������졹����һ��ƮȻ�ݳ��������ŵء�\n" 
        "����$n����Ʈ��������һ�ݣ����ѱܿ���\n", 
        "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n", 
        "����$n����һ�ã�$N��һ�����˸��ա�\n", 
        "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n", 
        "$n����΢�Σ��о����յرܿ���$N��һ�С�\n" 
        }) ); 
} 
int valid_learn(object me) 
{ 
        if( (int)me->query("max_force") < 100 ) 
                return notify_fail("�������������û�а취�������޳�����\n"); 
        return 1; 
}  
