//libieforce
//by xiaolang
#include <ansi.h>
inherit SKILL;
void setup() {
        set("name", "����ķ�");
        set("usage/force", 1);  
        set("skill_class", "new");
        set("effective_level", 120);
        set("learn_bonus", -50);
        set("practice_bonus", -50);
        set("black_white_ness", 30);
}
mixed hit_ob(object me,object victim)
{
        int extra, dream,i;
        extra = me->query_temp("libieforce_libie");
        dream = me->query_skill("libieforce",1) + 4 * victim->query("resistance/kee"); 
        i = me->query_temp("libieforce_busy");
      
        if( extra > 0) {
                victim->receive_damage("sen",extra/2,me);
                victim->receive_damage("gin",extra/2,me);
                victim->receive_damage("kee",dream*2,me);
                victim->add("kee",-dream*2);
                if(random(i)&& !victim->is_busy() ) victim->start_busy(random(2)+1);
        }
        if (extra || me->query_temp("libieforce_libie"))
           message_vision(MAG"\n$NͻȻĿ����ͣ�����������ȥ�����£�������Ȼ���ˣ�\n"NOR,victim);
        return;
}     
