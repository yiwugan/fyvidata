 //spring-water.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "��ˮ����");
        set("usage/iron-cloth", 1);
    set("effective_level", 120);
        set("bounce_ratio", 20);
        set("learn_bonus", -300);
        set("practice_bonus", -5);
        set("black_white_ness", 20);
    set("skill_class", "huashan");
        set("absorb_msg", ({
        "$n��ü΢����ʩչ�������������¡�����������Ʈ�裬��Ȼ�ƺ��е��΢�⸡����\n",
        "$nʩչ��ˮ�����ġ��κ�¥̨���������������ܣ����ƺ�������$N�����ڡ�\n",
        "$n΢΢����һʽ���仨�˶���������$N�Ĺ����£��´�ƮƮ����紵���衣\n",
        "$nʩչ����΢����˫�ɡ���˫���չ������$N��һ����\n",
        }) );
} 
int valid_learn(object me){
    if( (string)me->query("gender") != "Ů��" ) {
        return notify_fail("��ˮ������ֻ��Ů�Ӳ��������书��\n");
        }
        if(!::valid_learn(me)){
                return 0;
        }
        return 1;
}  
int practice_skill(object me)
{
        return notify_fail("��ˮ����ֻ��ͨ��ѧϰ����ߡ�\n");
                
}  
