inherit ROOM;
void create()
{
  set("short","���¹�");
  set("long",@LONG
�������¹�����Ϣ�ĵط���ֻ��һ��������, ò���绨��Ů��վ����
������,�������书���,������ص��ƻ�����������ǰ��Ϊ������������
�������ǳ������ˣ��������������ò�Ҫ�ӽ�����
LONG
    );
  set("exits",([
      "west" : __DIR__"changlang1",
      "southwest" : __DIR__"woshi",
     ]));
  set("objects",([
        "/d/yihua/npc/yaoyue" : 1,
     ]));
        set("coor/x",-150);
        set("coor/y",115);
        set("coor/z",0);
 setup();
 replace_program(ROOM);
}
