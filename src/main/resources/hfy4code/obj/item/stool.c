#include <ansi.h>
inherit ITEM;
void create(){ 
    set_name("ʯ��", ({ "stool" , "ʯ��", "deng zi"}) );
    set_weight(2000);
    set_max_encumbrance(8000);
    set("no_get", 1); 
    if( clonep() )
        set_default_object(__FILE__);
    else {
    set("prep", "on");
    set("unit", "��");
    set("long", "ʯ�ʵı��汻ĥ��ʮ�ֹ⻬��������������������������������\n");
    set("value", 10);
    }
    ::init_item();
} 
void init()
{
        add_action("do_sitdown", "sitdown");
        add_action("do_standup", "standup");
        add_action("do_look","look");
}
int do_look()
{
        object sitdown_person;
        if (query("sitdown_person") && present(query("sitdown_person"),environment(this_object())))
        {
                set("long", query("sitdown_person")->name()+"��Ȼ����ʯ��֮�ϡ�\n");    
        }else
        {
                set("long", "ʯ�ʵı��汻ĥ��ʮ�ֹ⻬��������������������������������\n");
        }
        return 0;
} 
int do_sitdown(){
        
        object me;
        mapping who;
        int i,j,amount;
   
        me = this_player();
        if(me==query("sitdown_person") || me->query_temp("state/sit")){
                return  notify_fail("���Ѿ�������ѽ����\n");            
        }
        if(query("sitdown_person")&&present(query("sitdown_person"),environment(this_object()))){
                return notify_fail("ʯ���϶��Ѿ������ˡ�����\n");
        }
        message_vision("$N��ʯ���ߵ�ʯ��������������\n", me);
        //set("long", me->name()+"��Ȼ����ʯ��֮�ϡ�\n");
        set("sitdown_person", me);
        me->set_temp("state/sit", 1);
        return 1;
} 
int do_standup(){
        object me;
        
        me = this_player();
        if(me==query("sitdown_person")){
                message_vision("$N��ʯ����վ��������\n",me);
                me->delete_temp("state/sit");
                set("sitdown_person",0);
                //set("long", "ʯ�ʵı��汻ĥ��ʮ�ֹ⻬��������������������������������\n");
                return 1;
        }
        return 0;
}   