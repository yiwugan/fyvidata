 //XXDER
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"��Կ��"NOR, ({ "key", "��Կ��", "golden key"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѳ����Ľ�ɫԿ�ס�\n");
                set("value", 50);
        }
} 
void init()
{
        add_action("do_use", "use");
} 
int do_use(string arg)
{
        if( arg != "key" && arg != "Կ��") return 0; 
        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "��\n");
        environment(this_player())->goldenkey_notify(this_object(), 0); 
        return 1;
}   
