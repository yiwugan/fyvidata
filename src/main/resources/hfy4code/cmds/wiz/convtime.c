 inherit F_CLEAN_UP;
int main(object me, string arg)
{
        int time;
        if(!arg || sscanf(arg,"%d",time)!=1)
                return notify_fail("USAGE:ctime time.\n");
        write(sprintf("您输入的为：%d，对应时间为：%s\n",time,ctime(time)));
        return 1;
} 
int help(object me)
{
     write(@HELP
指令格式: time 
这个指令让你(玩家)知道一个time到底应该是什么时间。 
HELP
    );
    return 1;
}     
