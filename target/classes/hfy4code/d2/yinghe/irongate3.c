 // Room: irongate3.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "��������");
        set("long", @LONG
һ��յغ��棬һ����ڵĴ�������������ǰ����ǰ�������ƺ��б��˷�����
�ĺۼ���
LONG); 
        set("outdoor","yinghe");
        set("objects", ([
                __DIR__"obj/yunbow" : 1,
        ]));
        
        set("item_desc", ([
                "door" : "��ڵĴ����Ų�֪�ú�����ɣ��ƺ����Դ򿪣�������\n",
                "������" : "��ڵĴ����Ų�֪�ú�����ɣ��ƺ����Դ򿪣�������\n",
        ]));
        set("exits",([
        "south":__DIR__"bowroom",
        ]) ); 
        setup(); 
} 
void init(){
        object bow; 
        add_action("do_open", "open");  
        bow = present("ground bow", this_object());
        if(objectp(bow)){
                bow->set("installed", 1);
                bow->set("owner", "yinghe");
        }
} 
void close_path(){
        object room;
        if( query("exits/north") ) {
        message("vision","����һ������������ǰ�رա�\n",this_object() );
        delete("exits/north");
        room = find_object(__DIR__"irongate2");
        if(!objectp(room)) {
                room = load_object(__DIR__"irongate2");
           }
        message("vision","����һ������������ǰ�رա�\n", room);
                room->delete("exits/south");
        
    }
}
int do_open(string arg){
        object room, me;
        
        me = this_player();
    if( arg=="door" || arg =="������") {
                if(query("exits/north")){
                        return notify_fail("���Ѿ������ˡ�\n");
                }
        message_vision("$N���������������һ�ƣ������Ż����򿪡�\n", me);
                room = find_object(__DIR__"irongate2");
                if(!objectp(room)){
                        room = load_object(__DIR__"irongate2");
                }
                message("vision", "�ű��˴�����һ�ߴ򿪡�\n", room);
                room->set("exits/south", __DIR__"irongate3");
                set("exits/north", __DIR__"irongate2");
                call_out("close_path", 5);
        }
        else {
                write("��Ҫ��ʲô�أ�\n");
        }
        return 1;       
        message_vision("$N�����ƿ��˴����š�\n", me);
}       
