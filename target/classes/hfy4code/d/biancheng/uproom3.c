 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "�Է�");
        set("long", @LONG
�������������ӵ�����ҲƵ����������˵����ң���ֻ�Ǽ�򵥵���ľ����
�ɣ�����һ�ſ��Σ��������û�������ļҾߡ���ҵ�ף���ҵ�ѣ����Ⱥ��ΪҪ��
�ʹ��£��Ͳ���̰ͼ��ǰ�İ��ݣ��͵�ʱʱ�̱̿��ֱ�һ��ľ���������
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"uproom2",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",-1100);
        set("coor/y",320);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}  
