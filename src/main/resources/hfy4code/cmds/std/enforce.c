 // enforce.c
// the maxium 150 enforce is added for game balance. Silencer @1-1-2002 
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
        int pts; 
        if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("ָ���ʽ��enforce 
<ʹ�����������˵�>|none"); 
        if( !me->query_skill_mapped("force") )
                return notify_fail("������� enable һ���ڹ���\n"); 
        if( arg=="none" )
                me->delete("force_factor");
        else {
                if( pts < 0 || pts > (int)me->query_skill("force")/3)
                        return notify_fail("����ڹ��޷�������ô���������\n");
           if (pts >200)
                        return notify_fail("Enforce �������ֵ��200��\n");
                me->set("force_factor", pts);
        } 
        write("Ok.\n");
        return 1;
} 
int help (object me)
{
        write(@HELP
ָ���ʽ: enforce <ʹ�����������˵�>|none
 
���ָ������ָ��ÿ�λ��е���ʱ��Ҫ�������������˵С� 
enforce none ���ʾ�㲻ʹ��������  
SEE ALSO : enable, enchant
HELP
        );
        return 1;
}
      
