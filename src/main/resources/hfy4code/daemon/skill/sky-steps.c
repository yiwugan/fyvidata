 // ����������첽��
inherit SKILL;
void setup(){
        set("name", "�̿ղ���");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("practice_damage", 100);    
        set("effective_level", 400);
        set("learn_bonus", -700);
        set("black_white_ness", 10);
        set("skill_class", "emei");
        set("dodge_msg", ({
        "$n�������飬һ�С����������С����������ϵİ���һ�㣬��$N�Ĺ���ң���ɼ���\n",
        "$n����΢����һʽ�����Ӿò�������ٿ��Ų��������$N�Ҳ�����$n����Ӱ��\n",
        "$n����΢ణ�ȴ�ڿ̲��ݻ�֮��������𣬻�����$N�Ĺ��ƣ�����һ�С�����ɦ���ס���\n",
        "ȴ��$n������ɫ��ʹ��������ƽ��־����������������������һת��ȴǡ����$N�Ĺ�����ա�\n"
        }) );
} 
int practice_skill(object me)
{
	if( me->query("family/master_id") != "master yichen" && me->query("class") != "emei")
        return notify_fail("�̿ղ���ֻ��ѧ�ġ�\n");
}
