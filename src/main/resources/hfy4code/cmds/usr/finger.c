 // finger.c
inherit F_CLEAN_UP; 
void create()
{
        seteuid(getuid());
} 
int main(object me, string arg)
{
        if( !arg ) {
                if( (int)me->query("sen") < 50 )
                        return notify_fail("��ľ����޷����С�\n");
                if( !wizardp(me) )
                {
                        me->receive_damage("sen", 50);
                me->start_more("", FINGER_D->finger_all(0), 0);
                }
                else
                me->start_more("", FINGER_D->finger_all(1), 0); 
        } else {
                if( (int)me->query("sen") < 15 )
                        return notify_fail("��ľ����޷����С�\n");
                if( !wizardp(me) )
                        me->receive_damage("sen", 15);
                write( FINGER_D->finger_user(arg,(wizardp(me) || arg == (string)me->query("id"))) );
        }
        return 1;
} 
int help(object me)
{
  write(@HELP
ָ���ʽ : finger [ʹ��������]
 
���ָ��, ���û��ָ��ʹ��������, ����ʾ�����������������
����������. ��֮, �����ʾ�й�ĳ����ҵ�����, Ȩ�޵�����.
 
see also : who
HELP
    );
    return 1;
}
       
