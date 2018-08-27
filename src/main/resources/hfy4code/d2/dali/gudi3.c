inherit ROOM;

void create()
{
        set("short", "琅寰福地");
        set("long",@LONG 
这是一间极大的石洞，比外面的石室大了数倍，洞中一排排的列满木制书架，
可是架上却空洞洞的连一本书册也无。        
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