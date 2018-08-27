 // perform.c
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
    object weapon;
    string martial, skill;
    int result;
    
    mapping research_skills;
    int skill_level,skill_learned;
    
        
    seteuid(getuid()); 
    if( environment(me)->query("no_fight"))
                return notify_fail("�����޷�ʹ���⹦��\n");
    if( me->is_busy() )
        return notify_fail("������һ��������û����ɣ�����ʩ���⹦���� \n");
        
//    if (me->query_temp("till_death/lockup")==1)
//      return notify_fail(" ����Ѫ���������������ͣ�һʱ��Ȼ�˲����⹦����\n");   
    if( !arg ) return notify_fail("��Ҫ���⹦��ʲ�᣿\n"); 
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
            return notify_fail("�����⹦����ָ���书���࣡\n");
        if( martial == "move")
                return notify_fail("�����书Ӧ��ʹ�����������⹦��\n");    
    }
    if( stringp(skill = me->query_skill_mapped(martial)) ) {
        if( SKILL_D(skill)->perform_action(me, arg) ) {
            if( random(120) < (int)me->query_skill(skill) )
            { 
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
    return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��⹦��\n");
}       
int help (object me)
{
    write(@HELP
ָ���ʽ��perfrom [<�书����>.]<��ʽ����> [<ʩ�ö���>] 
�������ѧ���⹦(ȭ�š�����������....)��һЩ����Ĺ�����ʽ����ʽ������
�����ָ����ʹ�ã���������� enable ָ��ָ����ʹ�õ��书����ָ���书��
��ʱ�����ֵ��⹦��ָ���ȭ�Ź���ʹ������ʱ���Ǳ��е��书�� 
��������⹦�������಻ͬ��������ʽ������ͬ�ģ����߲����ȭ�Ÿ���������
���书(���Ṧ)�������� <�书>.<��ʽ>  �ķ�ʽָ�����磺 
perform dodge.xueyeqianzong 
perform move.lianhuanbu 
���仰˵��ֻҪ�� enable �е��书��������ʽ�ģ������������ָ��ʹ�á�
HELP
        );
    return 1;
}
        
