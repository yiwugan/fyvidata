 // FYteam
#include <ansi.h>
inherit ROOM;
void create(){
        set("short", "��ɫɳ��");
        set("long", @LONG
������һ����ɳ��Ķ��ˣ�������һ��Ƭ��Ө��׵�ɳ����ѩ�������Ų���
ɳ���ϣ���Ȼ�������ö���������ɳ�����಻�ϣ�ռ�ع��
LONG); 
        set("exits",([
                "northdown":__DIR__"silversand",
        ]) );
        //}}
        set("item_desc", ([
                "sand" : "һƬ��Ө���ɳ�£�Ȼ�������뻬��ȥ�ĸо����������壩\n",
                "ɳ��" : "һƬ��Ө���ɳ�£�Ȼ�������뻬��ȥ�ĸо����������壩\n",
                "ɳ" : "һƬ��Ө���ɳ�£�Ȼ�������뻬��ȥ�ĸо����������壩\n",
        ]));
        set("indoors", "yinghe");
        setup();
} 
void init(){
        add_action("do_slide", "slide");
} 
int do_slide(){
        object me;
        
        me = this_player();
        message_vision(HIG"$N����һ���������������ö��������ɿ�����»�ȥ��������\n"NOR, me);
        me->start_busy(2);
        call_out("falling", 1, me);
        return 1;
}
void falling(object me){
        object room;
        
        room = find_object(__DIR__"snakehall");
        if(!objectp(room)){
                room = load_object(__DIR__"snakehall");
        }
   message("vision", HIY"\nͻȻ��һ�󾪿��Ѽ��Ĳҽ����ص���ɳ��䡣\n"NOR, this_object(), me);
        me->move(room);
        tell_object(me, HIY"\n����Ȼ����һ׹��������һ������Ŀռ䣬��������δͣ�ȣ�ȴ�ѱ���ǰ�ľ�ɫ
�ŵ�ʧ����С���~~~~~\n"NOR);
        message("vision", "ֻ��һ�������Ѽ��Ľ�������ע�⵽" + me->name() +"�Ĵ��ڡ�\n", 
                        environment(me), me); 
}       
