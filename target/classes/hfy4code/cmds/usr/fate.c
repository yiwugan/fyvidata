#include <ansi.h> 
inherit F_CLEAN_UP;
 
int main(object me, string arg) 
{
    object ob;
    mapping my;
    seteuid(getuid(me));

    ob=me;
    my=ob->query_entire_dbase();
    if (mapp(my["����A"]) || mapp(my["����B"])) 
	   printf("�������״����\n");
    else return notify_fail("��û���κ�������\n");
    
    if (!mapp(my["����A"]))
	{
	printf("    ���ƺ���:0\n");
	printf("    ��ɽ����:0\n");
	printf("    ̩ɽ����:0\n");
	printf("    ��Դ����:0\n");
	}
    else
	{
	printf("    ���ƺ���:%d\n",my["����A"]["����_����"]);
	printf("    ��ɽ����:%d\n",my["����A"]["��ɽ_����"]);
	printf("    ̩ɽ����:%d\n",my["����A"]["̩ɽ_����"]);
	printf("    ��Դ����:%d\n",my["����A"]["��Դ_����"]);
	}
	
    if (!mapp(my["����B"]))
	{
	printf("    ��ɽ�ճ�:0\n");
	printf("    ��ɽ�ƺ�:0\n");
	printf("    ��ɽ���:0\n");
	printf("    ��ɽ�ٲ�:0\n");
	printf("    ��ɽ���:0\n");
	printf("    ̩ɽ�ճ�:0\n");
	printf("    ��������:0\n");
	printf("    �䵱��Ҷ:0\n");
	printf("    ��Դ����:0\n");
	printf("    ��Դ����:0\n");
	}
    else
	{
	printf("    ��ɽ�ճ�:%d\n",my["����B"]["��ɽ_�ճ�"]);
	printf("    ��ɽ�ƺ�:%d\n",my["����B"]["��ɽ_�ƺ�"]);
	printf("    ��ɽ���:%d\n",my["����B"]["��ɽ_���"]);
	printf("    ��ɽ�ٲ�:%d\n",my["����B"]["��ɽ_�ٲ�"]);
	printf("    ��ɽ���:%d\n",my["����B"]["��ɽ_���"]);
	printf("    ̩ɽ�ճ�:%d\n",my["����B"]["̩ɽ_�ճ�"]);
	printf("    ��������:%d\n",my["����B"]["����_����"]);
	printf("    �䵱��Ҷ:%d\n",my["����B"]["�䵱_��Ҷ"]);
	printf("    ��Դ����:%d\n",my["����B"]["��Դ_����"]);
	printf("    ��Դ����:%d\n",my["����B"]["��Դ_����"]);
	}

    return 1;
}


/*��ɽ_�ճ�B
��ɽ_�ƺ�B
��ɽ_���B
��ɽ_�ٲ�B
��ɽ_����A
����_����A
��ɽ_���B
̩ɽ_����A
̩ɽ_�ճ�B
����_����B
�䵱_��ҶB
��Դ_����B
��Դ_����A
��Դ_����B*/