inherit ROOM;
void create()
{
  set("short","���ǹ�");
  set("long",@LONG
�������¹�����Ϣ�ĵط���ֻ��һ��������,ò���绨��Ů��վ����
������,�������书���,������ص��ƻ�����������ǰ��Ϊ���Ľ������
�����������������������ǳ������ˣ��������������ò�Ҫ�ӽ�����
LONG
    );
  set("exits",([
      "east" : __DIR__"changlang1",
      "southeast" : __DIR__"woshi",
     ]));
  set("objects",([
        "/d/yihua/npc/lianxing" : 1,
     ]));
        set("coor/x",-170);
        set("coor/y",115);
        set("coor/z",0);
 setup();
 replace_program(ROOM);
}
