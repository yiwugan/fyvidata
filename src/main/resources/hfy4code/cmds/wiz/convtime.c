 inherit F_CLEAN_UP;
int main(object me, string arg)
{
        int time;
        if(!arg || sscanf(arg,"%d",time)!=1)
                return notify_fail("USAGE:ctime time.\n");
        write(sprintf("�������Ϊ��%d����Ӧʱ��Ϊ��%s\n",time,ctime(time)));
        return 1;
} 
int help(object me)
{
     write(@HELP
ָ���ʽ: time 
���ָ������(���)֪��һ��time����Ӧ����ʲôʱ�䡣 
HELP
    );
    return 1;
}     
