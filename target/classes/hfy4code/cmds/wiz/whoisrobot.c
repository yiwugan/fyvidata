#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        object room;
        object *ob_list;
        string msg="";
        string subip;
        int i;
        if(! room = find_object(AREA_WIZ"courthouse"))
                room = load_object(AREA_WIZ"courthouse");
        if (!arg) 
        {
        ob_list = users();
        for(i=0;i<sizeof(ob_list);i++)
        if(environment(ob_list[i]) && !wizardp(ob_list[i]))
        {
                tell_object(ob_list[i],HIR "\n\n�㱻������Ա����Ϊ�����ˣ�
����㲻�ܴӷ�Ժ��ʱ�뿪�Ļ����ͻᰴ��������������\n\n" NOR);
                ob_list[i]->move(room);
        }               
                return 1;
        }
        if(!ob=find_player(arg))
        {
        return notify_fail("�Ҳ������"+arg+"��\n");
        }
        else
        {
                tell_object(ob,HIR "\n\n�㱻������Ա����Ϊ�����ˣ�
����㲻�ܴӷ�Ժ��ʱ�뿪�Ļ����ͻᰴ��������������\n\n" NOR);
                ob->move(room);
        }
        return 1;
}
int help(object me)
{
   write(@HELP
ָ���ʽ: whoisrobot <id/arg/none>
���������У�������������Ƿ��ǻ����ˡ� 
HELP
   );
   return 1;
}  