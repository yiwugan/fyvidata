#include <ansi.h>
#include <net/daemons.h>

inherit F_DBASE;
void count_time(int min);
void auto_reboot_start();
void auto_reboot_done();
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "自动定时启动精灵");
		CHANNEL_D->do_channel( this_object(), "sys", "自动定时重启精灵已经启动。");
                call_out("auto_reboot_start", 86400*5+random(7200));
		log_file("AUTOREBOOT", sprintf("autoreboot启动成功！\n"));
		return;
}

void auto_reboot_start()
{
	remove_call_out("auto_reboot_start");
        message("system",HIR"【天神频道】"HIY"为了提高系统的运行速度，本游戏在20分钟内会自动重起！\n" NOR,users());
        call_out("count_time",60,20); 
}

void count_time(int min)
{
	min--;
	if( min ) {
                message("system",HIR"【天神频道】"HIY"请大家注意,现在还有" + chinese_number(min) +"分钟的时间重新启动！\n"NOR,users() );
		call_out("count_time", 60, min); 
	} else {
		message("system",HIR"【天神频道】"HIY"系统现在自动重启！！！\n"NOR,users() );
		call_out("auto_reboot_done", 3); 
	}
}

void auto_reboot_done()
{
	int i,j;
	object *ob, link_ob;
	string id;
	j=0;
	seteuid(getuid());
	set("channel_id", "存盘精灵"); 
	ob=users();
	i=sizeof(ob);
	for( i=0;i<sizeof(ob);i++) {
	id = (string) ob[i]->query("id");
	if (!id) continue;
	if(!environment(ob[i]) )        continue;
	if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
	if( (int)link_ob->save() && (int)ob[i]->save() ) j = 1;
	else CHANNEL_D->do_channel( this_object(), "sys", ob[i]->query("name")+"档案自动存盘失败。");
	}
	write_file("/log/static/LASTCRASH", HIY"系统自动重启于 "+ctime(time())+"\n"NOR, 1);
	CHANNEL_D->do_channel( this_object(), "sys", "档案自动存盘成功。");
	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
	shutdown(0);
	return;
}
