inherit ROOM;
#include <room.h>
void create() 
{ 
    set("short", "���ݴ���"); 
    set("long", @long
����֮�ƣ�����ս��������ᡣ��֮���󣬾���ȡ
�����վ���Ҳ����־���ͣ����ݣ����¶���֮������
��������ȡ֮��
long 
    ); 
    set("exits", ([ 
    	"north" : __DIR__"lou1e", 
    	"west" : __DIR__"lou1c",
    	//"west" : __DIR__"midao",
    	//"out" : __DIR__"alou4",
        ])); 
                set("objects", ([
                //__DIR__"npc/huoxiu": 1,
                
        ]));
        
        set("no_magic",1);
        
        set("indoors","shanxi"); 
set("coor/x",-400);
        set("coor/y",-200);
        set("coor/z",101);
        setup(); 
                //create_door("out", "ʯ��", "enter", DOOR_CLOSED); 

} 