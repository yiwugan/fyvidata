 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�����콾��");
        set("long", @LONG
����һ�����϶���ʥ�Ĵ���ʯ�ţ���Լ���ڰ���ǰ�����ϰ߰ߵ�㣬�绯��
������˵������ʴ���ٷ��ѽ����¶�ŮӢ�۵ĵط������Ǳ��ѽ���Ӣ�۶���Ϊ
����֮��
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"kezhan",
        ]));
        set("item_desc", ([
                "door" : "����ʯ�Ž����ţ����ϰ߰ߵ�㣬�绯��������֪���ź�ͨ��δ����������裩\n",
                "����ʯ��" : "����ʯ�Ž����ţ����ϰ߰ߵ�㣬�绯��������֪���ź�ͨ��δ����������裩\n",
                "��" : "����ʯ�Ž����ţ����ϰ߰ߵ�㣬�绯��������֪���ź�ͨ��δ����������裩\n",
        ]));
    set("outdoors", "fycity");
    set("coor/x",-50);
        set("coor/y",30000);
        set("coor/z",0);
        setup();
} 
void init(){
        add_action("do_push", "push");
} 
int do_push(string arg){
        object me, room;
        me = this_player();
        if(arg == "door" || arg == "����ʯ��" || arg == "��"){
                if(query("exits/down")){
                        return notify_fail("�����ǿ��ŵġ�\n");
                }
                if(me->query("combat_exp") > 4000000 && me->query_str() > 45){
                        message_vision("$N������˫�ۣ�˫�ƽ�������ʯ�ţ�$N���µ�ʯ�׺�Ȼҡ�������������������ѿ���\n", me);
                   message_vision(WHT"\nһ�����������洵����\n"NOR, me);
                        room = find_object("/d/yinghe/stair1");
                        if(!objectp(room)){
                                room = load_object("/d/yinghe/stair1");
                        }
                        set("exits/down", "/d/yinghe/stair1");
                        call_out("close_path", 4);
                } else {
                        message_vision("����ʯ����˿������\n", me);
                        tell_object(me, "��Ҳ���������������\n");
                }
                return 1;
        }
        return 0;
} 
void close_path(){
    object room;
    if( query("exits/down") ) {
        message("vision","����������ǰ�����رա�\n",this_object() );
        delete("exits/down");
        }
        return;
}      
