inherit ROOM;

void create()
{
        set("short", "����֮��");
        set("long", @LONG
����һƬï�ܵ����֣���ǰ���Ǵ��̵����ӣ�����������ġ�
������һ����סդ��Χ���Ժ�ӣ�դ���ſ��ţ�������һ�����ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zhuwu",
  "east" : __DIR__"shanjiao",
]));
        set("outdoor","dali");
        set("coor/x",0);
        set("coor/y",-450);
        set("coor/z",10);
        setup();
}