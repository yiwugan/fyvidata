 inherit ROOM;
void create()
{
        set("short", "�ϱ����");
        set("long", @LONG
���Ƿ��Ƴǵ�һ����Ҫ��������ϴ���ɽ��ˮ��ֱ���ɻ������½ӷ��ƾ�����
��ͨ���Ϻ��ڡ��������������ò�����һ���������Ϸ��ͱ�����չ��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"road5",
  "south" : __DIR__"road1",
  "east" : AREA_QIANFO"road1",
 "westup" : AREA_DAOGUAN"sroad",
]));
        set("outdoors", "laowu");
        set("coor/x",0);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
