 // shadowsteps.c
inherit SKILL;
void setup(){
        set("name", "���ٻ�Ӱ����");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 120);
        set("black_white_ness", -600);  
        set("practice_bonus", -20);
        set("skill_class", "swordsman");
        set("dodge_msg", ({
                "$nһ�С���Ӱ���Ρ�����һ��,���Ƶ�һ���������Բ������Ƶ��ĵط���\n",
                "ֻ��$n������ǰ,��Ȼ�硸����֮�������˷���,����������\n",
                "$nʹ������Ӱ���١�����Ȼ�������ټ���\n",
                "$n����һ�㣬һ�С��������롹��Ӱ��Ȼ��Ϊ����,��ͣ��ת,�����޷����\n",
                
        }) );
}
int practice_skill(object me)
{
        return notify_fail("���ٻ�Ӱ����ֻ��ѧ�ġ�\n");
}       
