#include <ansi.h>
// shout.c 
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
        if( !wizardp(me) )
                return notify_fail("Ŀǰ�ݲ�������� shout��\n");
        if (!arg) return notify_fail("����Ҫ���ʲ��?\n");
        shout(HIR ""+me->name() + "������Х��" + BLINK + arg + "\n" NOR);
        write(HIW"��������Х��" + arg + "\n"NOR);
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : shout <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�.
 
see also : tune
HELP
    );
    return 1;
}
       
