 // Room: nongjia.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "茅舍"); 
        set("long", @LONG
县城捕头杨铮在这租了间小屋，房东姓于，对待杨铮就象亲生儿
子一样，独生女儿莲姑并不漂亮，但却健康温柔。杨铮一天没有回来，
她就会急得躲到洗衣服的小溪边去偷偷流泪。但如今一切都变了，杨
铮亡命天涯，莲姑坠井而亡，老两口只能相依为命，而这一切，仅仅
因为杨铮追查着一件因“世袭一等侯”狄青麟而起的劫镖大案。
LONG); 
        set("type","indoors");
        set("exits",([
        "east":__DIR__"yard",
        ]) ); 
        set("objects", ([
                __DIR__"obj/coffin": 1,
        ]) );
        set("indoors", "libie");
        set("coor/x",43);
        set("coor/y",210);
        set("coor/z",0); 
        setup();
        replace_program(ROOM);
}    
