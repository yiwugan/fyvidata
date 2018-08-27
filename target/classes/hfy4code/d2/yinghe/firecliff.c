 // Room: firecliff.c --- neon
//                       xxder
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "�̻�������"); 
        set("long", @LONG
����ɽ���ߵ��������һ�����¡��ϱ߷���µ��һ�����￴ȥ��Ȼ�м���
���̵���ɫ����Χ��Ȼ��һƬ�𺣣�������ȴ��˿˿�����ĸо���������ȥ���µ�
����������ƺ���ʲô����ԾԾ������ȴ�ֱ������ʯѹ�����棬ʹ�������ȥ̽
��������
LONG);  
        set("outdoors", "yinghe");
        set("exits",([
        "south":__DIR__"firemountain2",
        ]) );
        //}} 
        setup(); 
}  
void init(){
        add_action("do_jump", "jump");
} 
int do_jump(string arg){
        object me;
        
        me = this_player();
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("����������æ��\n");
        }
        if(arg == "cliff" || arg == "��"){
                if(me->query("attribute_mark") == "wood"){
                        message_vision("$N����������Ծȥ��\n", me);
                        me->start_busy(2);
                        call_out("falling", 1, me);
                        return 1;
                }
        }
        return 0;
} 
void falling(object me){
        object room;
        
        if(!interactive(me) || environment(me) != this_object()){
                return;
        }
        tell_object(me, HIR"\n��Ȼ������ǰ�ĺ���û������ڻ��棬�ǻ����ƺ�Ҫ����ٳ�
�ҽ����������ʹ���㼸�޿��̡�\n\n"NOR);
        message("vision", HIR ""+ me->name()+ "��������׹ȥ����Ȼ�䱻����û�����������Χ��\n"NOR, 
                        environment(me), me);
        room = find_object(__DIR__"slider");
        if(!objectp(room)){
                room = load_object(__DIR__"slider");
        }
        me->set("kee", 1);
        me->set("gin", 1);
        me->set("sen", 1);
        if(!me->query("yinghe_marks/�������")){
                me->set("yinghe_marks/�������", 1);
        }
        me->move(room);
        message("vision", me->name() + "�Ӱ�����£��½Ƿ�˿�ֱ����չ��ĺۼ���\n", environment(me), me);
        return; 
}      
