 // jin-gang.c
inherit SKILL;
void setup() {
        set("name", "ʮ��̫������");
        set("usage/iron-cloth", 1);
        set("effective_level", 170);
        set("bounce_ratio", 20);
        set("learn_bonus", -500);
        set("practice_bonus", -10);
        set("black_white_ness", 30);
        set("skill_class", "fugui");
        set("absorb_msg", ({
        "$n�������ܣ���Ӳ����$N��һ�С�\n",
        "$n������ͨ���ھ�����ȫ�����£��Կ�$N����һ�С�\n",
        "$n��ȻһЦ������һ���ѽ�$N�ĳ����𿪡�\n",
        }) );
}  
int valid_learn(object me){
        
        if( (int)me->query_skill("skyforce",1)< (int)me->query_skill("henglian",1)*4/5 ) {
        return notify_fail("��ı̿��ķ���Ϊ�������޷�����������ʮ��̫��������\n");
        }
        if( (string)me->query("gender") != "����" ) {
        return notify_fail("ʮ��̫��������ֻ�����Ӳ��������书��\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
} 
int practice_skill(object me)
{
        return notify_fail("ʮ��̫������ֻ��ͨ��ѧϰ����ߡ�\n");
                
}   
