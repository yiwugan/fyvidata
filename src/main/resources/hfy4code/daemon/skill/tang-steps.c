 // tang-steps.c ����ǧ�ﲽ
inherit SKILL;
void setup(){
        set("name", "����ǧ�ﲽ");
        set("usage/dodge",1);
        set("usage/move", 1);
        set("effective_level", 150);
        set("learn_bonus", -20);
        set("practice_bonus", -10);
        set("black_white_ness", 30);
        set("skill_class", "tangmen");
        set("dodge_msg", ({
                "$n�������ĵ���������һ�����պñܹ�$N���������ơ�\n",
                "����$nǡ����������һ���������$N��һ�С�\n",
                "ֻ��$nһ�С��׺׳��졹���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
                "$nһ�������ӷ���������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
                "$nʹ��������չ�᡹����һ��ƮȻ�ݳ��������ŵء�\n"
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
            return notify_fail("�������������û�а취������ǧ�ﲽ��\n"); 
        return 1;
		if(me->query_skill("tangforce",1)+100<me->query_skill("tang-steps",1)){
			return notify_fail("������е���⻹������\n");
	    }
		if((string)me->query_skill_mapped("force")!= "tangforce"){ 
            return notify_fail("����ǧ�ﲽ����������в�������\n");  
        } 
        if(!::valid_learn(me)){ 
            return 0; 
        } 

}       

