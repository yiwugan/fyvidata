 // friend.c
// -silencer@fy4.com 
#include <ansi.h> 
inherit F_CLEAN_UP; 
void create()
{
        seteuid(getuid());
} 
int main(object me, string arg)
{
        string msg, name, *friends,*new_friends;
        object body,ob;
        int i;
        
        friends = me->query("friends_list");
        if (!friends) 
                friends=({});
        
        new_friends=friends;
        
        if( (int)me->query("sen") < 150 && !wizardp(me))
                        return notify_fail("至少需要１５０点心神。\n"); 
        
        if( !arg ) {
                if (!sizeof(friends)) {
                        write("你的通讯录是空的。\n");
                        return 1;
                }
                for (i=0;i<sizeof(friends);i++) {
                        name=friends[i];
                        ob = new(LOGIN_OB);
                        ob->set("id", name);
                        if (!ob->restore()) {
                                msg=sprintf(YEL"%-26s\t不存在，已自动从你的通讯录中除名。\n"NOR, name);
                                new_friends=new_friends-({name});
                                write(msg);
                                continue;
                        }       
                        if( objectp(body = find_player(name)) && geteuid(body)==name ) 
                                msg = sprintf(HIG"%-16s%-10s\t目前正在连线中。\n"NOR, ob->query("name"),name); 
                   else 
                                msg=sprintf(CYN"%-16s%-10s\t目前不在连线中。\n"NOR, ob->query("name"),name);
                        write(msg); 
                }
                me->set("friends_list",new_friends);
                if (!wizardp(me)) me->receive_damage("sen",150);
        }
        else    {
                ob = new(LOGIN_OB);
                ob->set("id", arg);
                if( !ob->restore() ) {
                        write ("没有这个玩家。\n");
                        return 1;
                }
                if ( !friends || member_array(arg,friends)==-1) { 
                        if (sizeof(friends)>=15) {
                                write(HIR"通讯录中最多只能有十五个名字，请删去一些不常用的。\n"NOR);
                                return 1;
                        }
                        me->set("friends_list",friends+({arg}));
                        write(WHT"你将玩家 "+ob->query("name")+"（"+arg+"） 加入通讯录。\n"NOR);
                }else   {
                        me->set("friends_list",friends-({arg}));
                        write(WHT"你将玩家 "+ob->query("name")+"（"+arg+"） 从通讯录中去除了。\n"NOR);
                }
        
        } 
        return 1;
} 
int help(object me)
{
  write(@HELP
指令格式 : friend [玩家英语代号]
此指令为开关式，第一次打入将把一个玩家名字加入你的通讯录，对同样
的玩家名字再次操作将把此名字从通讯录中删除。如果不跟任何参数则将
显示通讯录中所有玩家的在线状况。通讯录中最多可存储十五个名字。
see also : who, finger
HELP
    );
    return 1;
}
       
