 // Room: woodroad3.c --- neon
inherit ROOM; 
void create()
{
        set("short", "�ľ����"); 
        set("long", @LONG
����һ���������ľ���ȣ��������ɳ��֮�ϡ����ȵ�ľ��͸���������ȵ��
ľ��ɫ���������µ�������������Ŀ��Ͼ�ӡ�
LONG);
        
        set("indoors", "yinghe");
        set("exits",([
        "south":__DIR__"woodroad4",
        "northwest":__DIR__"woodroad2",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/yingwu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}      
