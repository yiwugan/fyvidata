 // Room: irongate4.c --- by neon
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "�Ĳ���"); 
        set("long", @LONG
����һ��Ĳݼ�����ɽ�£��ݴ��в�ʱ�������졣���¶���һ��ɽׯ��Լ�ɼ���
�������и��ںڵ�ɽ���������ȷ������Ʈ�����ƺ��������߳��������䶯��
LONG); 
        set("outdoor","yinghe");
        set("exits",([
                "east":__DIR__"thundercity",
                "northeast":__DIR__"snakehall",
        ]) );
        //}} 
        setup();
} 
// ��˵���� if player ne, or northeast, will a message
//��˵���� tells them, too many snakes down there, better not go 
int valid_leave(object obj, string dir){
        if(dir == "northeast"){
                if(obj->query_skill("animal-training")>200){
                        return 1;
                }               
                return notify_fail(HIY"��˻˻~~������������Ⱥ���䶯�ľ��������������⡣\n"NOR);
        }
        return 1;
}       
