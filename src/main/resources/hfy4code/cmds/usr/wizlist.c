//kelly
inherit F_CLEAN_UP; 
#include <ansi.h>
int main(object me, string arg)
{
        string output;
//      write(__VERSION__+"\n");
        output = HIG"\n����������"HIB"����Ϸ����Ա��ǿ����,��������"HIG"�����������\n"NOR;
        write(output);
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : version
���ָ�����ʾ��ϷĿǰ���õ�MudOS�Լ�MudLIB�汾.
HELP
    );
    return 1;
}
// wizlist.c
/*
#include <ansi.h>
int main(object me, string arg)
{
        string str;]
	str="";	
        str += HIR"��"HIC"����������������"HIR" ��"HIY" ������� "HIR"�� "HIC"��������������������"HIR"��\n"NOR;
        str += HIG"\n����������"HIB"����Ϸ����Ա��ǿ����,��������"HIG"�����������\n"NOR;
        str += "\n"HIR"��"HIC"����������������������������������������������������"HIR"��\n"NOR;
        me->start_more(str);
        return 1;
}
int help(object me)
{
        write("\nָ���ʽ : wizlist\n"
        "��; : �г�Ŀǰ���е���ʦ������\n"
        );
        return 1;
}
 // wizlist.c
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
        string *list; 
        write(MUD_NAME + "Ŀǰ�Ĺ����У�\n");
        list = sort_array(SECURITY_D->query_wizlist(), 1);
        for(int i=0; i<sizeof(list); i++)
 if (list[i]!="hyue")
                printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');
        write("\n");
        return 1;
} 
int help(object me)
{
write(@HELP
ָ���ʽ : wizlist 
��; : �г�Ŀǰ���еĹ�����������
HELP
     );
     return 1;
}    
*/
