 // Room: woodroad2.c --- neon
#include <ansi.h>
inherit ROOM; 
string view(string room);
void create()
{
        set("short", "�ľ����"); 
        set("long", @LONG
����һ���������ľ���ȣ�������ڹ�����ɳ֮�ϡ����ȵ�ľ��͸����������
���ľ��ɫ������������������Χ��ݴ�����ʹ�˲���פ�������Χ�ķ羰��
LONG);
        
        set("indoors", "yinghe");
        set("exits",([
        "west":__DIR__"woodroad",
        "southeast":__DIR__"woodroad3",
        ]) );
        set("objects", ([
                __DIR__"npc/tan_tianlong" : 1,
        ]));
        setup();
} 
void init(){
        add_action("do_rest", "rest");
} 
int do_rest(){
        object me;
        string *rooms = ({"/d/guanwai/grassland0", "/d/guanwai/grassland1", "d/guanwai/grassland2",
"/d/guanwai/grassland3", "/d/guanwai/grassland4"});
        me = this_player();
        message_vision("$N������������������������\n", me);
        tell_object(me, view(rooms[random(sizeof(rooms))]));
        if(me->query("attribute_mark") == "fire"){
                me->set_temp("yinghe_marks/rest", 1);
        }
        return 1;
} 
string view(string room) {
        int i;
        object *inv,env;
   mapping exits;
        string roomdesc, str, *dirs;
        
        env = find_object(room); 
        if(!env) {
                return "һ��ʫ��������ͷ����Į����ֱ����������Բ��\n";
        }
        if (!env->query("outdoors"))
                str = "����ľ�ɫ����ϡ��Ϥ\n";
        else
                str = "ֻ����Բ� Ұãã������ɳ���У�����������������ʶ�ľ��󡣡���\n\n";
        
        // room descriptions.
        str += sprintf( "%s \n    %s",
                        env->query("long"),
                        //wizardp(target)? file_name(env)+sprintf(" - (%d,%d,%d)",env->query("coor/x"),
                        //              env->query("coor/y"),env->query("coor/z")): "",
                        //env->long(),
                        env->query("outdoors")? NATURE_D->outdoor_room_description() : "" ); 
        // exits. 
        
        // all things in the room.
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("no_shown") ) {
                        continue;
                }
                str += "  " + inv[i]->short() + "\n";
        }
        return str;
}  
int valid_leave(object obj, string dir){
        object ob;
        ob = present("tan tianlong", this_object());
        if(dir == "southeast" && objectp(ob)){
                if(obj->query("attribute_mark") == "fire" && obj->query_temp("yinghe_marks/rest")){
                        return 1;
                }
                message_vision("$N������λ" 
+ RANK_D->query_respect(obj) + "�����ܾ�ɫ���ˣ��β��ڴ���Ϣ��Ϣ�����������\n",ob);
           return notify_fail("");
        }
        return 1;
}     
