// BY Yiner
#define DADAO_D                "/adm/daemons/dadaod"
#include <ansi.h>

int main(object me)
	{
	  if( !wizardp(me) )
        return notify_fail("��Ҳ���ʹ�ô�������ˢ�´��ʹ����:(\n");
      message("system",HIC "��ʦˢ�´��ʹ��������\n"NOR,users()); 
DADAO_D->fengbu_dadao();
         return 1;
	}
        	
 int help(object me)
{
  write(@HELP

redadao ����������ˢ�´��ʹ����ָ��

HELP
    );
return 1;
}

