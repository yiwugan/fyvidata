//kelly
inherit F_CLEAN_UP; 
#include <ansi.h>
int main(object me, string arg)
{
        string output;
//      write(__VERSION__+"\n");
        output = HIG"\n☆☆☆☆☆☆☆☆☆"HIB"本游戏管理员因强奸罪,都入狱了"HIG"☆☆☆☆☆☆☆☆☆☆\n"NOR;
        write(output);
        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : version
这个指令会显示游戏目前所用的MudOS以及MudLIB版本.
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
        str += HIR"≡"HIC"────────"HIR" ☆"HIY" 风云泥巴 "HIR"☆ "HIC"──────────"HIR"≡\n"NOR;
        str += HIG"\n☆☆☆☆☆☆☆☆☆"HIB"本游戏管理员因强奸罪,都入狱了"HIG"☆☆☆☆☆☆☆☆☆☆\n"NOR;
        str += "\n"HIR"≡"HIC"──────────────────────────"HIR"≡\n"NOR;
        me->start_more(str);
        return 1;
}
int help(object me)
{
        write("\n指令格式 : wizlist\n"
        "用途 : 列出目前所有的巫师名单。\n"
        );
        return 1;
}
 // wizlist.c
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
        string *list; 
        write(MUD_NAME + "目前的管理有：\n");
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
指令格式 : wizlist 
用途 : 列出目前所有的管事人名单。
HELP
     );
     return 1;
}    
*/
