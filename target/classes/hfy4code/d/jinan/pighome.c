 // pighome.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","�����Ժ");
  set("long",@LONG
���Ǽ��ϳǵĹ����Ժ�����������������ߺ�ȡ�������������
�Ǽ��ϳǵĴ�֣����Ͼ��ǹ�����
LONG
  );
  set("exits",([
         "westup":__DIR__"street3",
         "up":__DIR__"proom",
               ]));
//    set("throw_exit","westup");
    set("no_magic",1);
    set("NONPC",1);
        set("coor/x",50);
        set("coor/y",1930);
        set("coor/z",0);
        setup();
    replace_program(ROOM); 
}        
