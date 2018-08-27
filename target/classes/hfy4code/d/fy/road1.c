 inherit ROOM;
void create()
{
        set("short", "城西小路");
        set("long", @LONG
一条小路弯弯曲曲向北延伸。路的旁边是风云城的护城河，河的另外一边就
是高大的风云城城墙了。从这里可以看到城墙上值勤的士兵在站岗。河堤上长满
了绿草。微风拂来，一股的泥土的气息。自从金钱帮在风云城里兴起以后，这里
的行人渐渐的多了起来，每天清晨都有金狮镖局的车队从此路过。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "south" :"/d/quicksand/huangyie0",
        "south" : __DIR__"fywest",
  "northeast" : __DIR__"road2",
]));
         set("objects", ([
        __DIR__"/d/fycycle/obj/grass" : 1,
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",-160);
        set("coor/y",50);
        set("coor/z",0);  
        setup();
} 
void reset()
{
object con, item, *inv;
::reset();
if( con = present("grass",this_object()))
if( inv = all_inventory(con))
if( !sizeof(inv))
        {
        item = new(__DIR__"obj/quant");
        item->move(con);
        }       
}    
