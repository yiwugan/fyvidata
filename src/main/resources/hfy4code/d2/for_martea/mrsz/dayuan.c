 inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
վ��Ժ�У��������죬ǽ���������֣�������ϼ��ֻ���ô��ⰺȻ��Ժ����һ
���ϻ����������дУ��ڸ��˴���Ժ�ӣ���ש�̳ɵĵ���Ʈ���ż�Ƭ��Ҷ��Ժ��
��������һ����������䳡��������һ���᷿����������ɽׯ�������ˡ�
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */
        "east" : __DIR__"xiangfang",
        "south" : __DIR__"mrsz",
        "west" : __DIR__"wuchang",
        "north" : __DIR__"zhengtang",            
        ]) ); 
        set("outdoors","mrsz");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
}       
