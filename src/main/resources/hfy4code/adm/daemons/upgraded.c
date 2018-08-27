// Daemon:/adm/daemons/updated.c
/*模拟华附自动检测升级系统 V 0.2
   此版本人物升级系统是在根据kittt建议的基础上对原版作较大
   改进而成的，首先，用指针改写了原来的等级学分需求代码，
   避免了大量的重复判断，同时，易于巫师的改写和重新制定升
   级学分要求。同时另一改进是把原来的call_out呼叫检测玩家
   的check_all()函数改成了用localtime来呼叫的方法，毕竟这
   样比较节省系统资源，而且localtime是efun，执行起来也快。
   这个版本改过的文件包括upgraded.c、scmore.c，hp.c有
   一点小问题，也改了一下。*/

#include <ansi.h>
inherit F_DBASE;
void check_all();
void ready_to_start();
void upgrade(object ob);
int *exp=({105000,
        150000,
        200000,
        270000,
        350000,
        450000,
        600000,
        1000000,
        1500000,
        2300000,
        3000000,
        4000000,
        5200000,
        6500000,
        8000000,
        10000000,
        12500000,
        16000000,
        23000000,
        35000000,
        45000000,
        58000000,
        75000000,
        100000000,
        125000000,
        175000000,
        200000000,
        250000000,
        300000000,
        375000000,
        475000000,
        600000000,
        800000000,
        1250000000,
        1400000000, // 最高40级，希望目前中国的人口就是这个数，hehe
});

void ready_to_start()
{
        mixed *local;
        local = localtime(time());
        if (!((local[1])%25)) // 每25分钟检测一次玩家的等级
        check_all();
}
void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "升级检测");
        CHANNEL_D->do_channel( this_object(), "fywiz", "升级检测系统已经启动。\n");
        ready_to_start();
}
void upgrade(object ob)
{
        if(userp(ob))
        {
        int myexp=ob->query("combat_exp");
        int i=ob->query("level"); 
        if (myexp>=exp[i]){
        ob->add("level",1);
        tell_object(ob,HIG"\n恭喜你！！！\n    "HIY"由于你的经验值达到"+chinese_number(exp[i])+"点，现在将你的等级提升为 "+chinese_number(i+1)+" 等级！！！
\n                                            "HIW"【风云天下工作组】\n"NOR);
        return;
                }
        }
}

void check_all()
{
        object *ob = users();
        int i;
        message("system", GRN"\n【升级检测】自动检测玩家等级完毕。\n", users());
        for(i=0; i<sizeof(ob); i++){
        upgrade(ob[i]);
        }
        if (i>=sizeof(ob)) {
        message("system","" NOR, users()); 
        ready_to_start();
        }
}
