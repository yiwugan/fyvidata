 inherit ROOM;
void create()
{
        set("short", "小屋");
        set("long", @LONG
这是一间看门人休息的小屋，房屋不大，收拾得还算整齐。窗口下摆着一张木
桌，两把椅子分摆在两侧，对面的是一个土塌，上面铺着简单的被褥。透过窗口可
以清楚地看到由大门口进出的人。    
LONG
        ); 
    set("exits", ([ /* sizeof() == 4 */
                "east" : __DIR__"menkou",
        ]) );
        set("objects", ([
                __DIR__"obj/table" : 1,
        ]));
        set("indoors","murong");
        setup(); 
} 
void reset(){
    object          *inv;
    object          con, item;
    int             i; 
    ::reset();
    con = present("table", this_object());
    inv = all_inventory(con);
    if(sizeof(inv) != 4) {
        for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
        item = new(__DIR__"obj/feather");
        item->move(con);
        item = new(__DIR__"obj/feather");
        item->move(con);
        item = new(__DIR__"obj/feather");
        item->move(con);
        item = new(__DIR__"obj/feather");
        item->move(con);
    }
}     
