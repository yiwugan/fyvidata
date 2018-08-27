 /* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��·");
        set("long", @LONG
��ԭ�ϵ�һ���������۵���·������һ��ĬĬ��Ϫ�����ңɣ֣ţң���
�峺��Ϫˮ��ʹ�˸е�һ��������Ϣ����ΧȺɽ�������ˮ���ѣ����������
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"hongshan",
  "south" : __DIR__"beimen",
]));
        set("objects", ([
        //__DIR__"npc/baiyi" : 1,
        "/d/zangbei/npc/xuedahan" : 1,
                        ]) );
        set("item_desc", ([
                "river": "ˮ���ļ������ǲ��������������ȥ(wade)��\n",
                "Ϫ��": "ˮ���ļ������ǲ��������������ȥ(wade)��\n" 
        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","�峺��Ϫˮ");
        set("liquid/container", "Ϫ��");
        set("coor/x",-1120);
        set("coor/y",2120);
        set("coor/z",0);
        setup();
} 

void init() {
        add_action("do_wade","wade");
}  
int do_wade(string arg) {
        
        object me;
        
        me=this_player();

        if (!arg || arg == "С��" || arg== "river") {
                if (me->query_temp("zangbei/wade_1"))
                   return notify_fail("���Ѿ��ں�ˮ�����ˡ�\n");
                message_vision("$N����ѥ�������ˮ�У����ѵ���԰���ȥ��\n\n",me);
                call_out("pass_river",6,me);
                me->start_busy(3);
                me->set_temp("zangbei/wade_1",1);
                return 1;
        }
        tell_object(me,"��Ҫ��ʲô��\n");
        return 1;
}  
int pass_river(object me) {
        object room;
        if (!objectp(me) || me->is_ghost()) return 0;
        room=find_object("/d/zangbei/bank");
        if (!objectp(room)) room=load_object("/d/zangbei/bank");
        tell_object(me,HIG"�������ߵ��˳����ӵĶ԰���\n"NOR);
        message("vision",HIG""+me->name()+"ˮ���ܵشӺ�������������\n"NOR,room);
        me->move(room);
        me->delete_temp("zangbei/wade_1");
        return 1;
}      

