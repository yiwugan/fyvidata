inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����ͨ�������޹��ĳ��ȣ����Ӻ������϶������������Ĺ�
���������һ�䷿�䣬�����洫�������ӵ��������ƺ��кܶ��ˡ�
LONG
     );

  set("exits",([
      "north" : __DIR__"yihua_ge",
      "south" : __DIR__"changlang1",
     ]));

        set("coor/x",-160);
        set("coor/y",125);
        set("coor/z",0);
 setup();
 replace_program(ROOM);
}
