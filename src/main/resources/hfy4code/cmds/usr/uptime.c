 // uptime.c
inherit F_CLEAN_UP;
#include <ansi.h>
// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
        int t, d, h, m, s;
        string time;
        string mudver;
        t = uptime();
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t; 
        if(d) time = chinese_number(d) + "��";
        else time = ""; 
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        mudver = read_file("/doc/help/version.txt");
        if(!stringp(mudver)) {
                mudver = "CAN NOT READ FILE version.txt\n";     
        }
        mudver = replace_string(mudver, "\n","\n");
        write(GRN "���Ƣ��Ѿ�������"BLINK HIY + time + "��\n\n" NOR);
        return 1;
} 
int help(object me)
{
        write(@HELP
ָ���ʽ : uptime
 
���ָ�����������Ѿ����������˶��.
 
HELP
    );
    return 1;
}      
