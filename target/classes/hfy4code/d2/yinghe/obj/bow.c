#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("������", ({ "bow", "pili bow" }) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��̥ͭ�޹����ںڷ������粻֪���Ǻ������ɡ�
û��һ���ı������������˹���\n");
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
        if(me->query_str() > 45 ) {
                message_vision(HIG"$N���������������ѹ�����������\n"NOR, me);
                call_out("release_bow", 1, me);
        } else {
                message_vision("$N������������ȴ˿��������\n", me);
        }
        me->receive_damage("kee", 50);
        return 1;
} 
int release_bow(object me){
        if(!objectp(me) || environment(this_object()) != me) {
           return 0;
        }
        message_vision(HIG"\n$N΢һ���֣�����������������\n"NOR, me);
        environment(me)->bird_flee(me);
        return 1;
}     
