 // imprison.c
 
#include "/doc/help.h"
#define SYNTAX  "ָ���ʽ��imprison <���id> because <ԭ��>\n"
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob;
        object room;
        string name,reason;
        if (!wizardp(me)) return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
        if (!arg) return notify_fail(SYNTAX);
        if (sscanf(arg, "%s because %s", name, reason)!=2 )
                return notify_fail(SYNTAX);
        ob = find_player(name);
        if (!ob) return notify_fail("�Ҳ��������ҡ�\n");
        message_vision("$N��һ�ӣ�һ��΢�罫$n������Ƽ���������\n",me,ob);
        seteuid( geteuid(this_player(1)) );
        if(!(room =find_object(AREA_WIZ"jail")))
        room = load_object(AREA_WIZ"jail");
        ob->move(room);
        ob -> save();
        log_file("static/imprison", sprintf("[%s] %s imprison %s(%s) because %s.\n",
                ctime(time())[0..15], me->query("id"), ob->query("name"), ob->query("id"), reason));    
        return 1;
}
 
int help(object me)
{
   write(@HELP
ָ���ʽ: mprison <���id> because <ԭ��>
��ĳ����ҽ����ڷ��Ƶļ�����ڼ�����ʲôҲ�����ˣ�
һֱ������������� 
HELP
   );
   return 1;
}
