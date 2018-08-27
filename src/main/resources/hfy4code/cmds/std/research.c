#include <skill.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
    int gin_cost;       
    int my_skill;
    int pot;
    int amount;
    string skill;
    if(environment(me)->query("no_fight"))
        return notify_fail("�㲻�����������о���\n");
    if( me->is_fighting() )
        return notify_fail("��ս���и��о�����û�и������\n");
    if(!arg || sscanf(arg, "%s with %d", skill, pot)!=2 )
         return notify_fail("ָ���ʽ: research <����> with <Ǳ�ܵ���>\n");
    if( !(int)my_skill=me->query_skill(skill,1) )
        return notify_fail("��Դ����һ����֪����θ��о����ǲ������ӽ�ˮ�ˣ�\n");
    
//    if( !SKILL_D(arg)->valid_learn(me) ) return 0;
//      if( !SKILL_D(arg)->valid_research(me) ) return 0;
    
    if (pot <24)
                 return notify_fail("��Ҳ߯�����ˣ����Ǳ�ܲ����������о���\n");
    
    if (pot > (int)me->query("potential") - (int) me->query("learned_points"))
                 return notify_fail("���Ǳ�ܵ㲻����\n");
    gin_cost = 10000 * 3 / ((int)me->query_int()*(int)me->query_kar());
    if((int)me->query("gin") < gin_cost)
    {
        me->set("gin",0);
        return notify_fail("������̫���ˣ����ʲ��Ҳû���о�������\n");
    }
    amount = (my_skill - 75) * SKILL_D(skill)->black_white_ness()/100;
    amount += SKILL_D(skill)->learn_bonus() +
        ((int)me->query_int() *  (int)me->query_int())/2 +
        to_int(pow(to_float((int)me->query("combat_exp")),0.3));
    amount = pot/10*(amount/100 + random(amount/100));
    me->add("learned_points",pot);
    me->receive_damage("gin", gin_cost );
    me->research_skill(skill,amount);
    write("���"+SKILL_D(skill)->name()+"����һ�����׵��о���\n");
    return 1;
}
int help(object me)
{
    write( @HELP
ָ���ʽ: research <����> with <Ǳ�ܵ���> 
��һָ�����������е�Ǳ�ܶ�ĳ�����������о���
HELP
   );
    return 1;
}  
