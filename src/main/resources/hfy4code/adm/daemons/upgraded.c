// Daemon:/adm/daemons/updated.c
/*ģ�⻪���Զ��������ϵͳ V 0.2
   �˰汾��������ϵͳ���ڸ���kittt����Ļ����϶�ԭ�����ϴ�
   �Ľ����ɵģ����ȣ���ָ���д��ԭ���ĵȼ�ѧ��������룬
   �����˴������ظ��жϣ�ͬʱ��������ʦ�ĸ�д�������ƶ���
   ��ѧ��Ҫ��ͬʱ��һ�Ľ��ǰ�ԭ����call_out���м�����
   ��check_all()�����ĳ�����localtime�����еķ������Ͼ���
   ���ȽϽ�ʡϵͳ��Դ������localtime��efun��ִ������Ҳ�졣
   ����汾�Ĺ����ļ�����upgraded.c��scmore.c��hp.c��
   һ��С���⣬Ҳ����һ�¡�*/

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
        1400000000, // ���40����ϣ��Ŀǰ�й����˿ھ����������hehe
});

void ready_to_start()
{
        mixed *local;
        local = localtime(time());
        if (!((local[1])%25)) // ÿ25���Ӽ��һ����ҵĵȼ�
        check_all();
}
void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "�������");
        CHANNEL_D->do_channel( this_object(), "fywiz", "�������ϵͳ�Ѿ�������\n");
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
        tell_object(ob,HIG"\n��ϲ�㣡����\n    "HIY"������ľ���ֵ�ﵽ"+chinese_number(exp[i])+"�㣬���ڽ���ĵȼ�����Ϊ "+chinese_number(i+1)+" �ȼ�������
\n                                            "HIW"���������¹����顿\n"NOR);
        return;
                }
        }
}

void check_all()
{
        object *ob = users();
        int i;
        message("system", GRN"\n��������⡿�Զ������ҵȼ���ϡ�\n", users());
        for(i=0; i<sizeof(ob); i++){
        upgrade(ob[i]);
        }
        if (i>=sizeof(ob)) {
        message("system","" NOR, users()); 
        ready_to_start();
        }
}