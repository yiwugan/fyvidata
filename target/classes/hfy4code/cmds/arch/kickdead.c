// kickdead.c
// Write by ��ѩ(linxue) 1999/9/28
// Ϊ�˽����ҵ��������������Ϸ�мӵ�����
 
#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob;
        string wiz_status;

        if (!arg) return notify_fail("ָ���ʽ: kickdead <living>\n");
        ob= LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("�Ҳ��������ҡ�\n");
        if( me!=this_player(1)
        || wiz_level(me) < wiz_level("(wizard)") )
                return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
        
        wiz_status = SECURITY_D->get_status(ob);
        if( wiz_status == "(admin)" )
                return notify_fail(HIR"�����췴��? ������ʵ�㡣 \n"NOR);
        write( "OK!!!"NOR);
        ob -> save();
        seteuid(ROOT_UID);
        destruct(ob);
        return 1;
}
 
int help(object me)
{
   write(@HELP
ָ���ʽ: kickdead <���>
��ĳ������߳�����

also see ban
HELP
   );
   return 1;
}
