 // Room: irongate2.c --- neon
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "����԰");
        set("long", @LONG
���ƺ���һ����԰����԰����ľ���Ʊ����ǿ���һ�㣬�ںڵ������ϣ�֦Ҷ��
����䡣������һ���ںڵĴ����ţ�������һ����ڵĴ����š���ǰ�������ƺ���
���˷������ĺۼ���
LONG); 
        set("outdoor","yinghe");
        set("objects", ([
                __DIR__"npc/guard1" : 1,
                __DIR__"obj/yubow" : 1,
        ]));
        set("item_desc", ([
                "door" : "�ϱ��������������š�(north door/south door)\n",
                "south door" : "һ����ڵĴ����ţ� ���Դ򿪡�������\n",
                "��ڵĴ�����" : "һ����ڵĴ����ţ� ���Դ򿪡�������\n",
                "�ںڵĴ�����" : "һ���ںڵĴ����ţ� ���Դ򿪡�������\n",
                "north door" : "һ���ںڵĴ����ţ� ���Դ򿪡�������\n",
        ]));
        //}} 
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
                room = find_object(__DIR__"irongate3");
                if(!objectp(room)) {
                        room = load_object(__DIR__"irongate3");
                }
                message("vision","����һ������������ǰ�رա�\n", room);
                        room->delete("exits/north");
            }
        break;
        case 2:
                if( query("exits/north") ) {
                message("vision","����һ������������ǰ�رա�\n",this_object() );
                delete("exits/north");
                room = find_object(__DIR__"irongate");
                if(!objectp(room)) {
                        room = load_object(__DIR__"irongate");
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
    if( arg=="south door" || arg =="��ڵĴ�����") {
                if(query("exits/south")){
                        return notify_fail("���Ѿ������ˡ�\n");
                }
        message_vision("$N���������������һ�ƣ������Ż����򿪡�\n", me);
                room = find_object(__DIR__"irongate3");
                if(!objectp(room)){
                        room = load_object(__DIR__"irongate3");
                }
                message("vision", "�ű��˴�����һ�ߴ򿪡�\n", room);
                room->set("exits/north", __DIR__"irongate2");
                set("exits/south", __DIR__"irongate3");
                call_out("close_path", 5, 1);
           return 1;
        } 
        if (arg=="north door" || arg =="�ںڵĴ�����") {
                if(query("exits/north")){
                        return notify_fail("���Ѿ������ˡ�\n");
                }
        message_vision("$N���������������һ�ƣ������Ż����򿪡�\n", me);
                room = find_object(__DIR__"irongate");
                if(!objectp(room)){
                        room = load_object(__DIR__"irongate");
                }
                message("vision", "�ű��˴�����һ�ߴ򿪡�\n", room);
                room->set("exits/south", __DIR__"irongate2");
                set("exits/north", __DIR__"irongate");
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
int valid_leave(object ob, string dir){
        object guard;
        if(ob->query("attribute/mark") == "fire" && dir == "north"){
                guard = present("yinghe guard", this_object());
                if(objectp(guard)){
                        message_vision(HIY"$N��$n���һ����û������һ�أ���������ǰ��һ����\n"NOR, guard, ob);
                        return notify_fail("");
                }
                return 1;
        }
        return 1;
} 
