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
                        write("����ʹ���� *, +, ? ��β�ĵ�ַ��\n");
                else
                        NETBAR_D->add(site);
                }
        else if (sscanf(arg, "- %s", site) == 1)
                NETBAR_D->delete(site);
        else write("ָ���ʽ��netbar [+|- site]\n"); 
        return 1;
        
} 
int help()
{
        write(@HELP
ָ���ʽ��netbar [+|- site] 
�����������������������б�ġ�
���Ի��һ��ip 3 �����ϵ�id ����
HELP
        );
        return 1;
}
