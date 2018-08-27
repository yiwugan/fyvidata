 // Room: irongate.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "��ש��");
        set("long", @LONG
����һ������������������ʵ����ש�̾͡�����ͷ��һ���Ұ��Ĵ�����
��������ǰ����ǰ����ש�ƺ��б��˷������ĺۼ���
LONG); 
        set("objects", ([
                __DIR__"obj/yubow" : 1,
        ]));
        set("outdoor","yinghe");
        
        
        setup();
}
void init(){
        object bow;
        add_action("do_open", "open");
        bow = present("yu bow", this_object());
        if(objectp(bow)){
                bow->set("installed", 1);
        }        
}  
void close_path(int i){
        object room;
        switch(i) {
        case 1:
                if( query("exits/south") ) {
                message("vision","����һ������������ǰ�رա�\n",this_object() );
                delete("exits/south");
                room = find_object(__DIR__"irongate2");
                if(!objectp(room)) {
                        room = load_object(__DIR__"irongate2");
                }
                message("vision","����һ������������ǰ�رա�\n", room);
                        room->delete("exits/north");
            }
        break;
   case 2:
                if( query("exits/north") ) {
                message("vision","����һ������������ǰ�رա�\n",this_object() );
                delete("exits/north");
                room = find_object(__DIR__"thundercity");
                if(!objectp(room)) {
                        room = load_object(__DIR__"thundercity");
                }
                message("vision","����һ������������ǰ�رա�\n", room);
                        room->delete("exits/south");
            }   
    break;
    }
}
int do_open(string arg){
        object room, me, room1;
        
        me = this_player();
    if( arg=="south door" || arg =="�ںڵĴ�����") {
                if(query("exits/south")){
                        return notify_fail("���Ѿ������ˡ�\n");
                }
        message_vision("$N���������������һ�ƣ������Ż����򿪡�\n", me);
                room = find_object(__DIR__"irongate2");
                if(!objectp(room)){
                        room = load_object(__DIR__"irongate2");
                }
                message("vision", "�ű��˴�����һ�ߴ򿪡�\n", room);
                room->set("exits/north", __DIR__"irongate");
                set("exits/south", __DIR__"irongate2");
                call_out("close_path", 5, 1);
                return 1;
        } 
        if (arg=="north door" || arg =="�Ұ��Ĵ�����") {
                if(query("exits/north")){
                        return notify_fail("���Ѿ������ˡ�\n");
                }
        message_vision("$N���������������һ�ƣ������Ż����򿪡�\n", me);
                room = find_object(__DIR__"thundercity");
                if(!objectp(room)){
                   room = load_object(__DIR__"thundercity");
                }
                message("vision", "�ű��˴�����һ�ߴ򿪡�\n", room);
                room->set("exits/south", __DIR__"irongate");
                set("exits/north", __DIR__"thundercity");
                call_out("close_path", 5, 2);
                return 1;
        } 
        if(arg = "door"){
                return notify_fail("��Ҫ����һ���ţ���������衡����򣯣������衡�����\n");
        }
        else {
                write("��Ҫ��ʲô�أ�\n");
        }
        return 1;       
        message_vision("$N�����ƿ��˴����š�\n", me);
}
