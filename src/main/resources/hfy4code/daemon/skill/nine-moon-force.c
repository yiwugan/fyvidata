 // nine-moon-force.c
inherit SKILL;
#include <ansi.h> 
void setup(){
        set("name", "�����ľ�");
        set("usage/force", 1);
        set("skill_class", "shenshui");
        set("learn_bonus", 10);
        set("practice_bonus", 5);
        set("black_white_ness", -10);
}
 
mixed hit_ob(object me,object victim, int damage_bonus)
{
        int extra;
        object weapon;
        string msg;
                
        if(!extra=me->query_temp("nine-moon-force_poison")) return ;
        
        if (weapon=me->query_temp("weapon")){
                if (weapon->query("skill_type")=="sword" && 
                        (me->query_skill_mapped("sword") == "nine-moon-sword"
                        || me->query_skill_mapped("sword") == "qingpingsword"))
                        {       
                        victim->add("kee",-extra/2);
                        victim->add("eff_kee",-extra/2);
                        victim->receive_wound("kee",1,me);
                        return MAG"$nֻ��˿˿����͸�ǣ��ƺ���һ�����ư��������$N�����ϴ�����\n"NOR;
                        }
        } else if (me->query_skill_mapped("unarmed") == "nine-moon-claw")
                {
                        victim->add("kee",-extra);
                        victim->add("eff_kee",-extra/2);
                        victim->receive_wound("kee",1,me);
                        msg=MAG"һ�����ư������һ����$nֻ�����������������׶���$Nָ�⴫����\n"NOR;
                        return msg;
                }
}   
/*int valid_learn(object me) 
{ 
    if( (string)me->query("gender") != "Ů��" ){
        return notify_fail("�����ľ���ֻ��Ů�Ӳ��������ڹ���\n");
    }
    return 1; 
} 
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    mixed foo;
    
    foo = ::hit_ob(me, victim, damage_bonus, factor);
    if( intp(foo) && (damage_bonus + foo > 0) )
    {
if(random(3*(me->query_skill("nine-moon-force", 1)/2)) > 
            (damage_bonus + foo) )
        {
            victim->receive_wound("kee", (damage_bonus + foo));
            victim->apply_condition("ninemoonpoison", factor/2);
            return "$N����ʽЮ��һ�������ޱȵľ���ʹ��$n�������˸����䡣\n";
        }
    }
    return foo;
} 
*/      
