 // mysterrier.c
inherit SKILL;
void setup() {
        set("name", "�����߾�");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("practice_damage", 20);     
        set("skill_class", "scholar");
        set("effective_level", 200);
        set("learn_bonus", 50);
        set("practice_bonus", 20);
        set("black_white_ness", 20);
        set("dodge_msg", ({
        "$n��Ӱһת�����׵رܿ�����һ�С�\n",
        "$n��Ʈ������һ�㣬��һ�٣���������һ�ԡ�\n",
        "����$n��Ӱһ�࣬�ڼ䲻�ݷ�֮�ʴ��ݵرܿ�����һ�С�\n",
        "$n���ζ�Ȼ�θߣ�ʹ$N�Ĺ��ƾ�����ա�\n",
        "$n����һ�㣬��Ӱ���󻬿����ߣ����˿�ȥ��\n",
        }) );
} 
int valid_learn(object me)
{
    if( me->query_skill_mapped("force") != "mystforce" ) {
        return notify_fail("�����߾�������ϲ����ķ�ʹ�á�\n");
        }
    return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("sen") < 20 ){
                return notify_fail("��������񲻹��������������߾���\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->receive_damage("sen", 20);
        return 1;
}     
