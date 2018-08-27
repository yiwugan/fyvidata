 // Room: woodcabin.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "����ľ��"); 
        set("long", @LONG
����һ�䲻���۵�Сľ�ݡ�ľ�ϵ���ɫ�����ģ�Ȼ��ȴ��һ����翵�������
���ܴ���������������һ��С�ţ��ƺ�����ë�񶯵��������Ǳߴ�����
LONG);  
        //{{ --- by MapMaker
        set("exits",([
        "west":__DIR__"center",
        ]) );
        //}}
        set("item_desc", ([
                "door" : "һ��Сľ�ţ��ƺ������ƿ����������裩\n",
                "Сľ��" : "һ��Сľ�ţ��ƺ������ƿ����������裩\n",
                "��" : "һ��Сľ�ţ��ƺ������ƿ����������裩\n",
        ]));    
        set("objects", ([
                "/obj/food_item/shuihu" : 2,
                "/obj/food_item/dumpling" : 2,
        ]));
        set("indoors", "yinghe");
        setup(); 
}
void init(){
        add_action("do_push", "push");
} 
void close_path(){
        object room;
        
        room = find_object(__DIR__"garden");
        if(!objectp(room)){
                room = load_object(__DIR__"garden");
        }
        if( room->query("exits/west")){
                message("vision","֨ѽ������һ��ľ���������ˡ�\n",room );
        room->delete("exits/west");
    }
   if( query("exits/east") ) {
    message("vision","֨ѽ������һ��ľ���������ˡ�\n",this_object() );
    delete("exits/east");
    }
} 
int do_push(string arg){
        object me, room;
    me = this_player();
    if(query("exits/east")){
        return notify_fail("���ǿ��ŵġ�\n");
    }
    if( arg=="door" || arg =="��" || arg == "Сľ��") {
        message_vision("$N��Сľ���������һ�ƣ�֨��������һ���ſ��ˡ�\n", me);
                room = find_object(__DIR__"garden");
                if(!objectp(room)){
                        room = load_object(__DIR__"garden");
                }
                set("exits/east", __DIR__"garden");
                message("vision", "С�ű��˴򿪡�\n", room);
                room->set("exits/west", __DIR__"woodcabin");
                call_out("close_path", 5);
        } else {
                write("��Ҫ��ʲô�أ�\n");
        }
        return 1;       
} 
int valid_leave(object obj, string dir){
        if(dir == "west") {
                if(obj->query("attribute_mark") != "wood") {
                        return notify_fail("������ë�񶯵��������㲻�ɵ�ֹ����ǰ��\n");
                }
                return 1;
        }
        return 1;
}       
