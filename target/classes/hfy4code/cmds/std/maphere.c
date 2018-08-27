//coding by xiaolang for glqx 2006-01-03
//版权所有
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
	           return notify_fail("你所在的房间有错误，请与巫师联系。\n");
	     if( room->query("no_maphere") )
	           return notify_fail("这里不允许察看地图。\n");
	     where = file_name(room);      
	     sscanf(where,"/%s/%s/%s",dir1,dir2,dir3);
	     
	     map_buffer = read_file("/doc/map/"+dir2+"_map.txt");
	     
	     if( !stringp(map_buffer) )
	           return notify_fail("你当前所在区域暂无地图。\n");
	     room_name = room->query("short");
	     if( !stringp(room_name) )
	           return notify_fail("你所在的房间名字有误，请联系wiz修正。\n");
	     
	     replace = BLINK+HBRED+WHT+room_name+NOR;
	     
	     final_map = replace_string(map_buffer,room_name,replace);
	     write(final_map+"\t\n");
	     printf(HIR"图中红色闪烁的地方为你现在所在位置。\n"NOR);
	     return 1;
}