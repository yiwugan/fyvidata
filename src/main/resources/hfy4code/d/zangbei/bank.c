 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��̲");
        set("long", @LONG
�߳�������һ���ļ���С�ӣ�����������Ϊ���ɫ�������˳�֮Ϊ�����ӣ���
���������Ĺ������ӣ�Ҳ���Ǵ�˵�е���ӣ����Գ�����Ҳմ����������ÿ������
��������ϵ���ͽ��תɽ������ƽʱ��ֻ�м��������ڽ�ϴ���ѡ��ӵ��ϰ�����
��ѵ����������ʯͷ��һ��С·ͨ��ɽ�����
LONG
        );
        set("exits", ([ 
                "northwest":  AREA_BIANCHENG"sstreet4",
        ]));
        set("item_desc", ([
                "river":        "ˮ���ļ������ǲ��������������ȥ(wade)��\n",
                "������":       "ˮ���ļ������ǲ��������������ȥ(wade)��\n",
//	          "river":        "ˮ���ļ������ǲ��\n",
//                 "������":       "ˮ���ļ������ǲ��\n",
        ]) );
        set("objects", ([
        
                __DIR__"npc/woman":     1,
                __DIR__"npc/girl":      1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",-1100);
        set("coor/y",130);
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
        room=find_object("/d/xinjiang/tulu");
        if (!objectp(room)) room=load_object("/d/xinjiang/tulu");
        tell_object(me,HIG"�������ߵ��˳����ӵĶ԰���\n"NOR);
        message("vision",HIG""+me->name()+"ˮ���ܵشӺ�������������\n"NOR,room);
        me->move(room);
        me->delete_temp("zangbei/wade_1");
        return 1;
}      
