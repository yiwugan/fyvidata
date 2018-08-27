//coding by xiaolang for glqx 2006-01-03
//��Ȩ����
//www.glqx.net
#include <ansi.h> 
inherit F_DBASE;
inherit F_CLEAN_UP; 

int main(object me)
{
	     string where,map_buffer,room_name,dir1,dir2,dir3;
	     string replace,final_map;
	     
	     object room;
	     
	     room = environment(me);
	     
	     if( !objectp(room) )
	           return notify_fail("�����ڵķ����д���������ʦ��ϵ��\n");
	     if( room->query("no_maphere") )
	           return notify_fail("���ﲻ����쿴��ͼ��\n");
	     where = file_name(room);      
	     sscanf(where,"/%s/%s/%s",dir1,dir2,dir3);
	     
	     map_buffer = read_file("/doc/map/"+dir2+"_map.txt");
	     
	     if( !stringp(map_buffer) )
	           return notify_fail("�㵱ǰ�����������޵�ͼ��\n");
	     room_name = room->query("short");
	     if( !stringp(room_name) )
	           return notify_fail("�����ڵķ���������������ϵwiz������\n");
	     
	     replace = BLINK+HBRED+WHT+room_name+NOR;
	     
	     final_map = replace_string(map_buffer,room_name,replace);
	     write(final_map+"\t\n");
	     printf(HIR"ͼ�к�ɫ��˸�ĵط�Ϊ����������λ�á�\n"NOR);
	     return 1;
}