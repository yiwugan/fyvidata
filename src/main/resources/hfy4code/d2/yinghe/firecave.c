 // FYteam
#include <ansi.h>
inherit ROOM; 
void create(){
        set("short", "�������");
        set("long", @LONG
����һ���޴�ĵ��ã�����ֻ��һ��ԡ���˵ĵ��������ƺ���ȼ��һ�㣬
��������ĺ�⡣���˹�������������翾���ˡ������ϵķ���������һ�������
���衣
LONG); 
        //{{ --- by MapMaker
        set("exits",([
                "north":__DIR__"center",
        ]) );
        set("item_desc", ([
                "shenzuo" : "ӳ������ĺ�⣬�����ϵķ�������һ����������衣���������裩\n",
                "����" : "ӳ������ĺ�⣬�����ϵķ�������һ����������衣���������裩\n",
        ]));
        set("indoors", "yinghe");
        setup();
} 
void init(){
        add_action("do_touch", "touch");
} 
int do_touch(string arg){
        object me, room;
        
        me = this_player();
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("������æ��\n");
        }
        if(arg == "����" || arg == "shenzuo"){
                if(me->query("attribute_mark") == "fire") {
                        message_vision(HIR"\n$N����������������Ȼ�����㡣\n\n"NOR, me);
                        tell_object(me, HIR"��ֻ�������˹�����͸����⣬��ǰ��ɫ��ģ����\n\n"NOR);
                        message("vision", me->name()+"����Ӱ�ں�����𽥱䵭��������ʧ������\n", environment(me), me);
                        tell_object(me, "\nһ��΢��Ϯ������ǰ����һ������\n\n");
                        room = find_object(__DIR__"pheonix_den");
                        if(!objectp(room)){
                                room = load_object(__DIR__"pheonix_den");
                   }
                        me->move(room);
                        message("vision", "��о�һ������Ϯ����" + me->name() +"����Ӱ��������ǰ��\n", environment(me), me);
                        return 1;
                } else {
                        tell_object(me, "���ȵĸо���������޷�����������\n");
                        return 1;
                }
        }
        return 0;
}      
