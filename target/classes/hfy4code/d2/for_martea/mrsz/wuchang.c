 inherit ROOM;
void create()
{
        set("short", "���䳡");
        set("long", @LONG
�����м����˼���÷��׮������������ʯ�ʣ�������ż���û��������ɳ����
������Щ�������������˵�����Ǹ����䳡��������˵��һ��յء�
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */
        "east" : __DIR__"dayuan",
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
}     
