 // nine-moon-steps.c
inherit SKILL;
void setup(){
        set("name", "������");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("skill_class", "shenshui");
        set("effective_level", 150);
        set("learn_bonus", 10); 
        set("practice_bonus", -15);
        set("dodge_msg", ({
                "$nһ�С����������������ɵر��˿�ȥ��\n",
                "ֻ��$n��Ӱһ�Σ�һʽ��������桹���ѱ����߳�֮�⡣\n",
                "$nʹ�����������桹���������ɵ�������\n",
                "$n����һ�㣬һ�С��������졹�ڿն��𣬱��˿�ȥ��\n",
                "����$nʹһ�С�������������������Ʈ�˿�ȥ��\n",
                "$n��Ӱ΢�����Ѿ���һ�С��������֡�����������\n",
                "����$nһ�С�����ɭɭ��ʹ���������Ƶ�$N���ᣡ\n"
        }) );
} 
int valid_learn(object me)
{
//        if( (string)me->query("gender") != "Ů��" )
//                return notify_fail("��������ֻ��Ů�Ӳ��������书��\n");
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취����������\n");
        if (me->query_skill("nine-moon-steps",1)>= 2*me->query_skill("nine-moon-force",1)){
                        return notify_fail("��ľ����ľ���򲻹���\n");
        }        
        return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("force") < 3 ){
                return notify_fail("�������������������������������\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -3);
   return 1;
}     
