#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name("����", ({ "iron case","case"}) );
        set_weight(500); 
        set_max_encumbrance(8000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "in");
                set("unit", "��");
                set("long", "һ���޴�����䣬�Ѿ�����һ�롣\n");
                set("value", 1);
        }
        ::init_item();
} 
int is_container() { return 1; } 
void init()
{
        add_action("do_open","open");
}  
int do_open(string arg)
{
        object cash,map;
        object guard;       
        
        if(arg!="iron case"&&arg!="����"&&arg!="case") return 0;
        else
        {
                if(guard = present("oldman",environment(this_object())))
                        if (guard->query("name")=="��ʿ")
                        {
                        message_vision("$N��$n�ȵ�����׼�Ҷ���\n", guard, this_player());
                        return 1;
                        }
                message_vision("$N������ĸ��ӡ�������\n",this_player());
                if(query_temp("been_get"))
                        return notify_fail("������䣬������տ���Ҳ��ʲôҲû�С�\n");
           set_temp("been_get",1);
                tell_object(this_player(),HIR"һ��һǧ������Ʊ����������æ����������\n"NOR);
                cash=new("/obj/money/thousand-cash");
                cash->move(this_player());
                return 1;
        }
}  
