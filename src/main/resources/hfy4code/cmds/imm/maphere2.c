//write by ever for glqx beta 1.0
//update by xiaolang for glqx beta 1.0
//Copyright��(C)��2005-2006������Ⱥ������All��rights��reserved. 
#include <ansi.h> 
inherit F_DBASE;
inherit F_CLEAN_UP; 

int main(object me, string arg)
{
	string map,map_cor;
	string where,shortname,replace;
	string short_nocor;
	string loc1,loc2,loc3;
	//����add by xiaolang
	replace = ""; 
	short_nocor = "";
//-------------------------------
	if (arg != "here")
		notify_fail("��ֻ����maphere");
	where = file_name(environment(me));
	//ȡ��·��������/d/eren/hotel,��ôloc1 = "d",loc2 = "eren",loc3 = "hotel"
	sscanf(where, "/%s/%s/%s",loc1,loc2,loc3);
	map = read_file("/doc/map/"+loc2+"_map.txt");
	if (!map)
		notify_fail("�㵱ǰ�����������޵�ͼ��\n");
	shortname = environment(me)->query("short");
	if ( !stringp(shortname) )
		notify_fail("�����ڵ�������������ϵwiz��\n");
	sscanf(shortname,"[%sm%s[%sm",loc1,short_nocor,loc3);
/*	if(short_nocor=="λ��")
	{
		notify_fail("�޷�ȷ�������ڵ�λ�á�\n");
		return 1;
	}
	else 
		tell_object(me,short_nocor);*/
	replace = BLINK""+HBRED""+WHT""+short_nocor+NOR"";
	//sprintf("WHT%sNOR",short);
/*	if(replace=="λ��")
		notify_fail("�޷�ȷ�������ڵ�λ�á�\n");
	else 
		tell_object(me,replace);*/
	if(short_nocor)
		map_cor = replace_string(map,short_nocor,replace);
	else
		write("�޷�ȷ�����λ�á�\n");
	//����add by xiaolang
	if(short_nocor=="")
	{
		write(HIR"������������λ��û�ڵ�ͼ�С�\n"NOR);
	}
	else
	{
		me->start_more("",map_cor,0);
		write(HIW"ͼ����˸�ĵط�Ϊ������λ�á�\n"NOR);	
	}
	return 1;
}
