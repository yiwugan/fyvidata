 inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
����һ�俴������Ϣ��С�ݣ����ݲ�����ʰ�û������롣�����°���һ��ľ
�����������ӷְ������࣬�������һ���������������ż򵥵ı��졣͸�����ڿ�
������ؿ����ɴ��ſڽ������ˡ�    
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
