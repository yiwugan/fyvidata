 inherit ROOM;
void create()
{
    set("short", "一线天"); 
        set("long", @LONG
行路至此，山路愈发变得陡峭无比，两边悬崖峭壁高高笔立，中间只留出一条
窄窄的山路，已是两人不能并肩而行，抬头望去，只有一线的天空，间或有几只山
鹰盘旋飞过。。。
LONG); 
        set("exits",([
        "southwest":__DIR__"safepub",
        "eastup":__DIR__"littlesky3",
        ]) );
       set("outdoors", "wolfmount");
        set("coor/x",-650);
        set("coor/y",-710);
        set("coor/z",60);
        setup();
        replace_program(ROOM);
}    
