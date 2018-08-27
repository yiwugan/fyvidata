// writen by FY@SH-morrison
#include <ansi.h>

int main(object me)
	{
	  if( !wizardp(me) )
		return notify_fail("玩家不能使用此命令来从新分布使命！:(\n");
      message("system",HIC "重新分布所有已完成的使命．．．"NOR,users()); 
      TASK_D->init_dynamic_quest();
      message("system",HIB "．．．所有已完成的使命重新分布完毕\n"NOR,users()); 
         return 1;
	}
        	
 int help(object me)
{
  write(@HELP

refresh 命令是用来重新布所有（完成和没完成）的使命（ｔａｓｋｓ）

HELP
    );
return 1;
}

