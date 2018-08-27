// kickdead.c
// Write by 林雪(linxue) 1999/9/28
// 为了解决玩家档案出错断线在游戏中加的命令
 
#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob;
        string wiz_status;

        if (!arg) return notify_fail("指令格式: kickdead <living>\n");
        ob= LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("找不到这个玩家。\n");
        if( me!=this_player(1)
        || wiz_level(me) < wiz_level("(wizard)") )
                return notify_fail("你没有权力使用这个指令。\n");
        
        wiz_status = SECURITY_D->get_status(ob);
        if( wiz_status == "(admin)" )
                return notify_fail(HIR"你想造反啊? 给我老实点。 \n"NOR);
        write( "OK!!!"NOR);
        ob -> save();
        seteuid(ROOT_UID);
        destruct(ob);
        return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: kickdead <玩家>
将某个玩家踢出风云

also see ban
HELP
   );
   return 1;
}
