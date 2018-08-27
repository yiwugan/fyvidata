//write by ever for glqx beta 1.0
//update by xiaolang for glqx beta 1.0
//Copyright　(C)　2005-2006　古龙群侠传　All　rights　reserved. 
#include <ansi.h> 
inherit F_DBASE;
inherit F_CLEAN_UP; 

int main(object me, string arg)
{
	string map,map_cor;
	string where,shortname,replace;
	string short_nocor;
	string loc1,loc2,loc3;
	//以下add by xiaolang
	replace = ""; 
	short_nocor = "";
//-------------------------------
	if (arg != "here")
		notify_fail("你只能用maphere");
	where = file_name(environment(me));
	//取得路径，类似/d/eren/hotel,那么loc1 = "d",loc2 = "eren",loc3 = "hotel"
	sscanf(where, "/%s/%s/%s",loc1,loc2,loc3);
	map = read_file("/doc/map/"+loc2+"_map.txt");
	if (!map)
		notify_fail("你当前所在区域暂无地图。\n");
	shortname = environment(me)->query("short");
	if ( !stringp(shortname) )
		notify_fail("你所在地名称有误，请联系wiz。\n");
	sscanf(shortname,"[%sm%s[%sm",loc1,short_nocor,loc3);
/*	if(short_nocor=="位置")
	{
		notify_fail("无法确定你所在的位置。\n");
		return 1;
	}
	else 
		tell_object(me,short_nocor);*/
	replace = BLINK""+HBRED""+WHT""+short_nocor+NOR"";
	//sprintf("WHT%sNOR",short);
/*	if(replace=="位置")
		notify_fail("无法确定你所在的位置。\n");
	else 
		tell_object(me,replace);*/
	if(short_nocor)
		map_cor = replace_string(map,short_nocor,replace);
	else
		write("无法确定你的位置。\n");
	//以下add by xiaolang
	if(short_nocor=="")
	{
		write(HIR"你现在所处的位置没在地图中。\n"NOR);
	}
	else
	{
		me->start_more("",map_cor,0);
		write(HIW"图中闪烁的地方为你所处位置。\n"NOR);	
	}
	return 1;
}
