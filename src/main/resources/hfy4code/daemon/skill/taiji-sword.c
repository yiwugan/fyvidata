#include <ansi.h>
inherit SKILL;
void setup() {
        set("name",                     "̫������");
        set("learn_bonus",              0);
        set("practice_bonus",   -200);
        set("black_white_ness", 40);
        set("effective_level",  250);
        set("usage/sword",              1);
        set("usage/parry",              1);
        set("unarmed_parry_msg",({
                "$nһ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ$N��$l\n",
                "$nһ�С�ȴ���齣�������Ծ����أ�$v�س飬���ֹ���$N��$l\n",
                "$nʹ����ʨ��ҡͷ����$v�������󻮳�һ�����֣���$NȦ������\n",
                "$nһ�С�ӭ�絧������$v���������һ�ӣ�$Nȴ����һ�ɾ���ӭ��Ϯ����\n",
                "$n���Ȱ�����ף�һ�С�����Ʊա����㽫$N�Ĺ��ƻ�����\n",        
        }) );           
        set("parry_msg",        ({
                "$nһ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ$N��$w\n",
                "$nһ�С�ȴ���齣�������Ծ����أ�$v�س飬���ֹ���$N��$w\n",
                "$nʹ����ʨ��ҡͷ����$v�������󻮳�һ�����֣���$N��$wȦ������\n",
                "$nһ�С�ӭ�絧������$v���������һ�ӣ�$Nȴ����һ�ɾ���ӭ��Ϯ����\n",
                "$n���Ȱ�����ף�һ�С�����Ʊա����㽫$N�Ĺ��ƻ�����\n",                       
        }) );
        
        set("skill_class",              "wudang");
action = ({
([      "action" : "$N�鲽������һ�С����ѵ�ˮ��������$w���������һ��������$n��$l",
        "force" : 60,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 45,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����һ�������ֽ���������$wʹ��һʽ��ָ���롹ֱ��$n��$l",
        "force" : 70,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 50,
        "lvl" : 4,
        "damage_type" : "����"
]),
([      "action" : "$N��������һ�죬���ֽ���������$wʹ��һʽ������ǡ�����$n��$l",
        "force" : 80,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 50,
        "lvl" : 9,
        "damage_type" : "����"
]),
([      "action" : "$N˫ϥ�³�������$wʹ��һʽ��̽��ʽ�������¶��ϼ���$n��$l",
        "force" : 90,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 50,
        "lvl" : 14,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С������Ӳ�����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��
ȥ",
        "force" : 100,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 60,
        "lvl" : 19,
        "damage_type" : "����"
]),
([      "action" : "$N���������һš��һ�С�������β��������$w������$n��$l��ȥ",
        "force" : 110,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 70,
        "lvl" : 24,
        "damage_type" : "����"
]),  
([      "action" : "$N������ϥ������$wбָ��һ�С�����Ͷ�֡�����$n��$l",
        "force" : 130,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 70,
        "lvl" : 34,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�������ˮ����$w���¶��ϻ���һ���󻡣�ƽƽ�ػ���$n��$l",
        "force" : 140,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 71,
        "lvl" : 39,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�����������¡���$w��������ԲȦ������ֱ�������಻�ϻ���$n
��$l",
        "force" : 150,
        "dodge" : 10,
        "parry" : 20,
        "damage" : 73,
        "lvl" : 44,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����Ҷ����$w����ػ�������Բ����Ѹ�ٵ���$n��$l��ȥ",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 75,
        "lvl" : 49,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����ͷ����$w����һ������ҸߵĴ󻡣�бб��ն��$n��$l",
        "force" : 170,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 77,
        "lvl" : 54,
        "damage_type" : "����"
]), 
([      "action" : "$N���̤ʵ���ҽ���㣬һ�С�����ָ·��������$w����һ�Ž�����
����$n��$l",
        "force" : 190,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 81,
        "lvl" : 64,
        "damage_type" : "����"
]),
([      "action" : "$N����Ծ��һ�С�Ұ����������$w�ڰ���л�ΪһȦ��â������$n
��$l",
        "force" : 200,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 83,
        "lvl" : 69,
        "damage_type" : "����"
]),
([      "action" : "$N����ǰ���󹭣�һ�С�����ʽ��������$wֱ��$n��$l",
        "force" : 210,
        "dodge" : 20,
        "parry" : 20,
        "damage" : 85,
        "lvl" : 74,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�С���ǡ�����������һ�죬���ֽ���������$wƽƽ����$n��
$l��ȥ",
        "force" : 220,
        "dodge" : 40,
        "parry" : 20,
        "damage" : 87,
        "lvl" : 79,
        "damage_type" : "����"
]),
([      "action" : "$N������ϣ�һ�С���Գ�׹���������$wбб����$n��$l��ȥ",
        "force" : 230,
        "dodge" : 30,
        "parry" : 20,
        "damage" : 89,
        "lvl" : 84,
        "damage_type" : "����"
]),  
([      "action" : "$Nһ�С�˳ˮ���ۡ���$w���϶��»���һ���󻡣�ƽƽ����$n��$l��
ȥ��",
        "force" : 250,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 93,
        "lvl" : 94,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����Ǹ��¡���$w����$n��$l",
        "force" : 260,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 95,
        "lvl" : 99,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�̶���������һ�С��������¡���$w���¶��ϵ���$n��$l��ȥ",
        "force" : 270,
        "dodge" : 25,
        "parry" : 25,
        "damage" : 97,
        "lvl" : 104,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����ʽ����$w���¶������컮��һ���󻡣�ƽƽ����$n��$l
��ȥ",
        "force" : 280,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 99,
        "lvl" : 109,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��Ʒ��붴����$w���϶��»���һ���󻡣�ƽƽ����$n��$l��
ȥ",
        "force" : 290,
        "dodge" : 40,
        "parry" : 25,
        "damage" : 102,
        "lvl" : 114,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����չ�᡹������Ծ������$w����$n��$l",
        "force" : 300,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 106,
        "lvl" : 119,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����ֽ�����$w����һƬ���̣�ƽƽ����$n��$l��ȥ",
        "force" : 310,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 120,
        "lvl" : 124,
        "damage_type" : "����"
]),
([      "action" : "$N��������棬������ǰһ�ˣ�һ�С������пա���$w��$n��$l��
ȥ",
        "force" : 320,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 125,
        "lvl" : 129,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С���ɨ÷����������Ծ�ڰ�գ�����$wɨ��$n��$l",
        "force" : 330,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 130,
        "lvl" : 90,
        "damage_type" : "����"
]),  
([  "action" : "$N����š���������鱧��һ�С�����հ�ա���$w�й�ֱ��������$n��$l",
        "force" : 380,
        "dodge" : 35,
        "parry" : 30,
        "damage" : 160,
        "lvl" : 149,
        "damage_type" : "����"
]),
}); 
}
int valid_learn(object me)
{
        object ob; 
        if( (int)me->query("max_force") < 300 )
                return notify_fail("�������������û�а취��̫��������\n"); 
        if( (string)me->query_skill_mapped("force")!= "taijiforce")
                return notify_fail("̫�������������̫���ڹ��ķ���������\n"); 
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n"); 
        return 1;
}  
int practice_skill(object me)
{       object ob; 
        if (me->query_skill("taiji-sword",1)>100)
                return notify_fail("̫��������Ϊ��£������ϵ���ʦ����̲��С�\n");
        
        if( (string)me->query_skill_mapped("force")!= "taijiforce")
                return notify_fail("̫�������������̫���ڹ��ķ���������\n");
        
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");
        
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 20 )
                return notify_fail("�����������������û�а취��ϰ̫��������\n");
        me->receive_damage("kee", 30);
        me->add("force", -20);
        write("�㰴����ѧ����һ��̫��������\n");
        return 1;
} 
/*
string *parry_msg = ({
        "$nһ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ$N��$w\n",
        "$nһ�С�ȴ���齣�������Ծ����أ�$v�س飬���ֹ���$N��$w\n",
                "$nʹ����ʨ��ҡͷ����$v�������󻮳�һ�����֣���$N��$wȦ������\n",
                "$nһ�С�ӭ�絧������$v���������һ�ӣ�$Nȴ����һ�ɾ���ӭ��Ϯ����\n",
                "$N���Ȱ�����ף�һ�С�����Ʊա����㽫$N�Ĺ��ƻ�����\n",
}); 
string *unarmed_parry_msg = ({
        "$nһ�С�����ɨ����һ�С�����ɨ��������ƽָ��һ���ǳɺ�ɨ$N��$l\n",
        "$nһ�С�ȴ���齣�������Ծ����أ�$v�س飬���ֹ���$N��$l\n",
                "$nʹ����ʨ��ҡͷ����$v�������󻮳�һ�����֣���$NȦ������\n",
                "$nһ�С�ӭ�絧������$v���������һ�ӣ�$Nȴ����һ�ɾ���ӭ��Ϯ����\n",
                "$N���Ȱ�����ף�һ�С�����Ʊա����㽫$N�Ĺ��ƻ�����\n",        
}); 
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
} 
int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return -200;
}
int black_white_ness()
{
        return 40;
} 
string perform_action_file(string action)
{
        return CLASS_D("wudang") + "/taiji-sword/" + action;
}
*/
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int myexp,urexp;
           myexp=me->query("combat_exp");
                urexp=victim->query("combat_exp")*victim->query("cps")/20;
                if (!victim->is_busy())
                if (random(myexp+urexp)>urexp && me->query_skill("taiji-sword",1)>100)
                {
                        victim->start_busy(2);
                        return HIW "$n��$N�Ľ����������ٶȲ��ɵ÷���������\n"NOR;
                }   
}   
