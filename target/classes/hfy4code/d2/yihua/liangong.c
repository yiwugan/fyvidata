inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
�������ƻ������������ĵط����м�������Ů������ר�����µ���
��,��������Ϊ�ƻ������书�ر�����,������Ϊ���ƻ������������
�������ú�Ͷ�롣
LONG
      );

  set("exits",([
      "east" : __DIR__"yihua_ge",
          ]));

        set("coor/x",-155);
        set("coor/y",-135);
        set("coor/z",0);
  setup();
 replace_program(ROOM);
}
