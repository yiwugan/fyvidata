inherit ROOM;

void create()
{
        set("short", "��徸���");
        set("long",@LONG 
����һ�伫���ʯ�����������ʯ�Ҵ�������������һ���ŵ�����ľ����ܣ�
���Ǽ���ȴ�ն�������һ�����Ҳ�ޡ�        
LONG
        );
        set("exits", ([
                "north" : __DIR__"gudi1",
           ]));
   set("objects", ([
      __DIR__"obj/bookcase": 1,
   ]) );
   set("no_clean_up",1);
        set("no_magic",1);
        set("coor/x",-700);
        set("coor/y",-900);
        set("coor/z",90);
        setup();
        replace_program(ROOM);
}
void reset()
{
 object item1, bookcase;
 ::reset();

 bookcase = present("bookcase", this_object());
 item1 = new("/questnew/obj/mianfen.c");
 item1->move(bookcase);
}