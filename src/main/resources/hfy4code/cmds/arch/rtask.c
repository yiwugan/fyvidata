#include <ansi.h>
 int main(object me)
    {
    message("system",HIR "重新分布所有使命。。。"NOR,users()); 
  TASK_D->init_dynamic_quest(1);
   message("system",HIG "。。。使命重新分布完毕\n"NOR,users()); 
    }
  int help(object me)
 {
  write(@HELP
 rtask and r2task命令是用来重新布所有（完成和没完成）的使命（ｔａｓｋｓ）
HELP
    );
return 1;
 }
