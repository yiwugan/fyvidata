 // netbar.c
void create()
{
        seteuid(getuid());
} 
int main(object me, string arg)
{
        string site; 
        if (!arg)
                NETBAR_D->print();
        else if (sscanf(arg, "+ %s", site) == 1) {
                if (site[sizeof(site)-1] == '*' ||
                    site[sizeof(site)-1] == '?' ||
                    site[sizeof(site)-1] == '+')
                        write("不能使用以 *, +, ? 结尾的地址。\n");
                else
                        NETBAR_D->add(site);
                }
        else if (sscanf(arg, "- %s", site) == 1)
                NETBAR_D->delete(site);
        else write("指令格式：netbar [+|- site]\n"); 
        return 1;
        
} 
int help()
{
        write(@HELP
指令格式：netbar [+|- site] 
这条命令是用来加入网吧列表的。
可以获得一个ip 3 个以上的id 连线
HELP
        );
        return 1;
}
