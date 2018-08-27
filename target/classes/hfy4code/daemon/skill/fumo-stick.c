 // fumo-stick.c
inherit SKILL;
void setup() {
        set("name", "���ַ�ħ����");
        set("usage/staff", 1);
        set("usage/parry", 1);
        set("learn_bonus", -110);
        set("effective_level", 210);
        set("practice_bonus", -100);
        set("black_white_ness", 20);
        set("skill_class", "shaolin");
        set("parry_msg", ({
        "$nʹ��һ�С����������������е�$v���Ա�����������$N��$w��\n",
        "$n�������ܣ�һ�С���ȥ�δӡ�������$v����ܲ�͸�磬��и�ɻ���\n",
        "$nһ�С���Ŀ�����������е�$v��ǰһ�������ɾͷ�ס��$N��$w��\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$nʹ��һ�С����������������е�$v���Ա�����������$N��������\n",
        "$n�������ܣ�һ�С���ȥ�δӡ�������$v����ܲ�͸�磬��и�ɻ���\n",
        "$nһ�С���Ŀ�����������е�$v��ǰһ�������ɾͷ�ס��$N�Ĺ��ơ�\n",
        }) );
        action = ({
        ([      "action":               
"$Nʹһ�С���ͷ�ǰ���������$w��ɨ�����ⶶ����ͣ��ɨ��$n��$l��",
                "damage":               200,
                "dodge":                200,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�������������ԭ��˫��ִ$w�߾٣�ͻȻ�����$N��$l��",
                "damage":               210,
                "dodge":                220,
                "parry":                260,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�趯����$w��ʹ��һ�С��ຣ�ޱߡ���������Ӱ���಻�ϵػ���$n$l��",
                "damage":               220,
                "dodge":                240,
                "parry":                240,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��ຣ�Ⱥ�����$w�󿪴�ϣ�����ʵʵ��ɨ��$n��$l��",
                "damage":               240,
                "dodge":                210,
                "parry":                280,
                "post_action":  "bash_weapon",
                "damage_type":  "����"
        ]),
        });
} 
int valid_learn(object me)
{
	      if(me->query("class") != "shaolin")
	              return notify_fail("ֻ�����ָ�ɮ�����������ַ�ħ������\n");
	      if(me->query_skill("zen",1)<50 &&me->query_skill("zen",1) < me->query_skill("fumo-stick",1) )
	              return notify_fail("���������������޷�����ѧϰ���ַ�ħ������\n");	      
        if( (int)me->query("str") < 20 ) 
        {
                return notify_fail("����ֱ�������������ѧϰ���ַ�ħ������Ҫ25��������\n");
        }
        return 1;
} 
int practice_skill(object me)
{   
        return notify_fail("���ַ�ħ����ֻ����ѧ�ġ�\n");
}   
int check_perform(object me,int lvl)
{
	if(me->query("shaolin/class")=="chan")
	{
		if(lvl>=50)
			tell_object(me,"����������perform xiangyao\n");
		if(lvl>=125)
			tell_object(me,"����ħ��������perform fumoxiangyao\n");
		if(lvl<50) tell_object(me,"����\n");
	}else if(me->query("shaolin/class")=="wu")
	{
		if(lvl>=100)
			tell_object(me,"����������perform xiangyao\n");
		if(lvl>=150)
			tell_object(me,"����ħ��������perform fumoxiangyao\n");
		if(lvl<100) tell_object(me,"����\n");
	}
	else tell_object(me,"����\n");
	return 1;
}
		
	
	
