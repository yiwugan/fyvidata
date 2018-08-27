 // perform.c
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
    object weapon;
    string martial, skill;
    object *enemy, *e_enemy;
    int result;
    
    mapping research_skills;
    int skill_level,skill_learned;
    
        
    seteuid(getuid()); 
    if( environment(me)->query("no_fight"))
                return notify_fail("这里无法使用外功。\n");
    if( me->is_busy() )
        return notify_fail("（你上一个动作还没有完成，不能施用外功。） \n");
        
//    if (me->query_temp("till_death/lockup")==1)
//      return notify_fail(" （你血脉不畅，真气受滞，一时竟然运不起外功。）\n");   
    if( !arg ) return notify_fail("你要用外功做什麽？\n"); 
    if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
        if( weapon = me->query_temp("weapon") )
            martial = weapon->query("skill_type");
        else if( weapon = me->query_temp("secondary_weapon") )
            martial = weapon->query("skill_type");
        else
            martial = "unarmed";
    } else{
        if( martial == "axe" || 
            martial == "blade" ||
            martial == "dagger" ||
            martial == "fork" ||
            martial == "hammer" ||
            martial == "parry" ||
            martial == "unarmed" ||
            martial == "staff" ||
            martial == "sword" ||
            martial == "throwing" ||
            martial == "spear" ||
            martial == "whip" ) 
            return notify_fail("这种外功不需指定武功种类！\n");
        if( martial == "move")
                return notify_fail("此类武功应该使用闪躲术的外功。\n");    
    }
    if( stringp(skill = me->query_skill_mapped(martial)) ) {
        if( SKILL_D(skill)->perform_action(me, arg) ) {
            if( random(120) < (int)me->query_skill(skill) && userp(me))
            {
//              added here to avoid robot performing in certain place
                if (environment(me)->query("no_death_penalty")) return 1;
                enemy=me->query_enemy();
                e_enemy=filter_array(enemy,(: $1->query("combat_exp")>$2->query("combat_exp")*9/10 :),me);
                if (!sizeof(e_enemy)) return 1; 
//              added following check to fix research bug -- silencer@fy4
                research_skills= me->query_learned();
                skill_level=me->query_skill(skill,1);
                if(research_skills[skill]) {
                        skill_learned=research_skills[skill];
                }
                if ((skill_level+1)*(skill_level+1)+1>skill_learned)
                {
                          me->improve_skill(skill, 1, 1);
                }            
                return 1;            
            }
            return 1;
        }
        return 0;
    }
    return notify_fail("你请先用 enable 指令选择你要使用的外功。\n");
}       
int help (object me)
{
    write(@HELP
指令格式：perfrom [<武功种类>.]<招式名称> [<施用对象>] 
如果你所学的外功(拳脚、剑法、刀法....)有一些特殊的攻击方式或招式，可以
用这个指令来使用，你必须先用 enable 指令指定你使用的武功，不指定武功种
类时，空手的外功是指你的拳脚功夫，使用武器时则是兵刃的武功。 
若是你的外功中有种类不同，但是招式名称相同的，或者不属於拳脚跟武器技能
的武功(如轻功)，可以用 <武功>.<招式>  的方式指定，如： 
perform dodge.xueyeqianzong 
perform move.lianhuanbu 
换句话说，只要是 enable 中的武功有特殊招式的，都可以用这个指令使用。
HELP
        );
    return 1;
}
        
