#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("������", ({ "yan bow", "bow" }) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ڵ�С��������ȥ���ͯ����ߣ���������ȴ�쳣��
���أ����ϻ�������ֵĻ��ơ�С���ƺ�����������������\n");
                set("value", 10000);
        set("material", "metal");
    }
} 
void init(){
        add_action("do_open", "open");
} 
int do_open(string arg){
        object me;
        
        me = this_player();
        if(!arg || arg != "bow" && arg != "pili bow"){
                return 0;
        }
        if(me->query("kee") < 100) {
                return notify_fail("��ʵ��̫���ˣ�����Ϣһ�°ɡ�\n");
        }
        if(me->query_str() > 35 ) {
                message_vision(HIG"$N���������������ѹ�����������\n"NOR, me);
                call_out("release_bow", 1, me);
        } else {
                message_vision("$N������������ȴ˿��������\n", me);
        }
        me->receive_damage("kee", 50);
        return 1;
} 
int release_bow(object me){
        object bat;
   if(!objectp(me) || environment(this_object()) != me) {
                return 0;
        }
        message_vision(HIG"\n$N΢һ���֣�һ�����εļ�����ǰ�����\n"NOR, me);
        bat = present("soul bat", environment(me));
        bat->bat_die(me);
        return 1;
}      
