 inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h> 
int update_condition(object me, int duration)
{
        int dam_kee,dam_gin,dam_sen;
        string msg;
        dam_kee = (int) me->query("max_kee")/10;
        dam_gin = (int) me->query("max_gin")/10;
        dam_sen = (int) me->query("max_sen")/10;
        me->receive_wound("kee", dam_kee);
    me->receive_wound("gin", dam_gin);
    me->receive_wound("sen", dam_sen);
        me->apply_condition("hehe", duration - 1);
    if( duration < 1 )
        {
                tell_object(me, HIR "�������ܲ���" HIY "�����Ϻ�ɢ" HIR "�Ĵ������ã�ȫ���Ѷ�����\n" NOR );
                message("vision", me->name() + "ȫ�������ѡ�\n", environment(me), me); 
                me->die();
        }
        else {
                tell_object( me, HIR "���е�" HIY "�����Ϻ�ɢ" HIR  "�����ˣ������ȫ�����Ȳ��ѣ�\n" NOR );
                msg = me->query("gender") == "����" ? 
                        "ͷ����췢�ȣ�����һ˫�۾����������������۹���Ҫ����ǹ⡣\n" 
                        : "����΢΢�����Ϸ���һ���һ��㵭���ĺ�ɫ�������ѽ��������Ĳ��������ƺ�Ҫ�γ�ˮ����\n" ;
                message("vision", "ֻ��" + me->name() + msg, environment(me), me);
        } 
        if( duration < 1 ) 
                return 0;
        return 1;
}  
int condition_type()
{
// in condition.h
/* 
#define NO_CURE                 10
#define NON_POISON              9
#define BLOOD_POISON            8
#define NERVE_POISON            7
#define BRAIN_POISON            6
#define OBSCENE_POISON             5
#define GENERIC                 0 
*/ 
        return OBSCENE_POISON;
}
