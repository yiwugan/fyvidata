inherit ROOM;

void create()
{
  set("short","õ����");
  set("long",@LONG
����ͨ����λ�����޹��ĳ��ȣ����Ӻ������϶������������Ĺ�
���������һ�䷿�������ǹ��������ң����������¹��������ҡ�
LONG
     );

  set("exits",([
      "north" : __DIR__"changlang",
      "west" : __DIR__"lianxing",
      "east" : __DIR__"yaoyue",
     ]));

        set("coor/x",-160);
        set("coor/y",115);
        set("coor/z",0);
 setup();
 replace_program(ROOM);
}
