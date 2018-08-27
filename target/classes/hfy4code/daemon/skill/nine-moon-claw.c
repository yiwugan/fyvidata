 // nine-moon-claw.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "�����׹�צ");
        set("usage/unarmed", 1);
        set("effective_level", 200);
        set("skill_class", "shenshui");
        set("learn_bonus", 0);
        set("practice_bonus", -50);
        set("black_white_ness", -80);
        set("parry_msg", ({
                "$n�����ָ��һ�С���ʯΪ��������$N��$w���εļ���ָ�У�\n",
                "$n����һ����˫��������ץ��$N���е�$w�ƺ�ͻȻ�����������������ö��ò��ȡ�\n",
                "$n��������һץ��һ�С����ӵ�������������һƬ��Ҷһ����$N$w��������Ʈ����\n",
                "$n˫צ����һ��һ����һ�С�������ǡ�������$N���е�$w����˫צ֮�ϣ�\n",
        }) ); 
        set("unarmed_parry_msg", ({
        "$n˫�۱�����һ�С���צ�ѻ꡹����$N˫�����д�ѨȫȻ����צ�£�\n",
                "$n���һת����$N���벻���ĽǶ���Ȼ�ػ���һ�С�����է�֡���$N���ˡ�\n",
                "$n��ָ΢����һ�С��޿ײ��롹��һ����ɭɭ��ָ��ֱ��$N�����š�\n",
                "$n˫�ֽ���һ�С���ؽ�������$NȦ��צ��֮�¡�\n",     
        }) );
        action = ({
        ([      "action":               
"$Nʹ��һ�С����İ�ץ��������ץ��$n��$l",
                "dodge":                330,
                "parry":                290,
                "force":                400,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nʹ��һ�С��������ץ�������ֻ�ָΪצ����������$n��$l",
                "dodge":                200,
                "parry":                320,
                "force":                370,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nʹ�������׹�צ�ġ�צ�����꡹������Ȱ�����$n��ǰ��һצ����$n��$l",
                "dodge":                200,
                "parry":                320,
                "force":                350,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N˫��һ��ʹ�����޵ۿ�צ������׼$n��$l����ץ��",
                "dodge":                250,
                "parry":                300,
                "force":                390,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N����ָ�ױ�ͻ�������Ƴ���һ�С����������󡹣�ץ��$n$l",
                "dodge":                250,
                "parry":                350,
                "force":                470,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$Nʹ�������������ǡ���˫��ͬʱ��$n��$l��צ����",
                "dodge":                280,
                "parry":                380,
                "force":                380,
                "damage_type":  "ץ��"
        ]),
        ([      "action":               
"$N����������һ�С�а������צ��˫�۲����ݳ�",
                "parry":                400,
                "dodge":                280,
                "force":                320,
                "damage_type":  "ץ��"
        ]),
        });
}
int valid_learn(object me)
{
        if( (string)me->query("gender") != "Ů��" ){
                return notify_fail("�����׹�צ��ֻ��Ů�Ӳ��������书��\n");
        }
   if (me->query_skill("nine-moon-claw",1) >= 50+ me->query_skill("nine-moon-force",1)){
                return notify_fail("��ľ����ľ���򲻹���\n");
        }
        if( (int)me->query("max_force") < 100 ){
                return notify_fail("�������̫�����޷��������׹�צ��\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
    return 1;
} 
int practice_skill(object me)
{
    if (me->query_skill("nine-moon-claw",1) > 190)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");
    if( (int)me->query("force") < 5 ){
        return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
    }
    if(!::practice_skill(me)){
        return 0;
    }
    me->add("force", -5);
    return 1;
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
    
    int damage;
    
    if( damage_bonus < 110 ) return 0;
    
    if( random(damage_bonus)/4> victim->query_str() ) {
    
        damage = (damage_bonus - 100) / 2;
        victim->add("kee",-damage);
        victim->add("eff_kee",-damage);        
        victim->receive_wound("kee",1,me );
        switch(random(3)) {
            case 0: return "��������������һ�����죬�����ǹ����������\n";
            case 1: return "$N����һ�£�$n��$l������������һ�����죡\n";
            case 2: return "ֻ����$n��$l��������һ�� ...\n";
        }
    }
}
    
void skill_improved(object me)
{
    if( (int)me->query_skill("nine-moon-claw", 1)  % 10 == 0 ) {
        tell_object(me, RED "\n��ͻȻ����һ������������ͷ��ֻ������ɱ��....\n\n"NOR);
        me->add("bellicosity", 500);
    } else {
            me->add("bellicosity", 100);
        }
} 
mixed parry_ob(object victim,object me)
{
        int mylvl,extra ;
        string msg;
        mylvl=me->query_skill("nine-moon-force",1);
        if (extra=me->query_temp("nine-moon-force_poison"))
        {
                victim->receive_wound("kee",extra/3,me);
                victim->receive_damage("kee",extra/3*2,me);
                if (!victim->query_temp("weapon"))      return MAG"$Nֻ�����ִ�����һ������������׶�Ķ�����\n"NOR;
                        else return MAG"$Nֻ��һ�㵭���������ӱ��������Ӷ������̹ǵĺ�������������ת�����顣\n"NOR;
                return msg;
        }
}     
