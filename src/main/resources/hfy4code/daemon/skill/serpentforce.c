 // serpentforce.c
inherit SKILL;
void setup(){
        set("name", "���Թ�");
        set("usage/force", 1);
        set("skill_class", "beggar");
}
int practice_skill(object me)
{
    if( !environment(me)->query("resource/water") ){
        return notify_fail("���Թ�ֻ������ˮ�ĵط�����\n");
    }
    if( (int)me->query("force") < 10 ){
        return notify_fail("�����������");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
    me->add("force", -10);
    return 1;
}  
