 // ban.c
void create()
{
        seteuid(getuid());
} 
int main(object me, string arg)
{
        string site; 
        if (!arg)
                BAN_D->print();
        else if (sscanf(arg, "+ %s", site) == 1) {
                if (site[sizeof(site)-1] == '*' ||
                    site[sizeof(site)-1] == '?' ||
                    site[sizeof(site)-1] == '+')
                        write("���ܽ��� *, +, ? ��β�ĵ�ַ��\n");
                else
                        BAN_D->add(site);
                }
        else if (sscanf(arg, "- %s", site) == 1)
                BAN_D->delete(site);
        else if (sscanf(arg, "a %s", site) == 1)
                BAN_D->allow(site);
        else write("ָ���ʽ��ban [+|- site]\n"); 
        return 1; 
} 
int help(object me)
{
        write(@HELP
ָ���ʽ��ban [+|-|a site]
���Բ���?��*��ͨ���
+�ǽ�ֹ���˷���
-��ɾ��ban���ĵ�ַ
a�Ǽ����������ĵ�ַ
��������� ban + 211.100��Ȼ��ban a 211.100.99.11
������ban��������211.100���Σ���������211.100.99.11���ip���� 
����������������ֹ�������⵷�ҡ�
HELP
        );
        return 1;
}   
