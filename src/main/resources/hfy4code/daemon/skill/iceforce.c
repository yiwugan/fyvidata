 // iceforce.c2
inherit SKILL;
void setup() {
        set("name", "�⺮��");
        set("usage/force", 1);
        set("skill_class", "dancer");
        set("effective_level", 80);
        set("learn_bonus", 30);
        set("practice_bonus", 10);
        set("black_white_ness", -10);   
}  
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
        
        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(me->query_skill("iceforce")) > (damage_bonus + foo) ) {
                        victim->receive_wound("kee", (damage_bonus + foo));
                        victim->apply_condition("iceshock", factor/3);
                        return "$N����ʽЮ��һ�������ޱȵľ���ʹ��$n�������˸����䡣\n";
                }
        }
        return foo;
}
   
