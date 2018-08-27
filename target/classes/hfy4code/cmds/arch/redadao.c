// BY Yiner
#define DADAO_D                "/adm/daemons/dadaod"
#include <ansi.h>

int main(object me)
	{
	  if( !wizardp(me) )
        return notify_fail("玩家不能使用此命令来刷新大盗使命！:(\n");
      message("system",HIC "巫师刷新大盗使命．．．\n"NOR,users()); 
DADAO_D->fengbu_dadao();
         return 1;
	}
        	
 int help(object me)
{
  write(@HELP

redadao 命令是用来刷新大盗使命的指令

HELP
    );
return 1;
}

