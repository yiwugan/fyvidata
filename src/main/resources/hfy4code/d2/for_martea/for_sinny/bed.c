#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�������", ({ "bed" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
                set("value",1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������ɫ����齣������ܵ�����Ҷ�񣬿���ȥ��Ϊ����(gosleep,gobed,bed)��\n");
                set("value", 1);
                }
} 
void init()
{
                add_action("do_bed",  "gosleep");
                add_action("do_bed",  "gobed",  );
                add_action("do_bed",  "bed");
} 
int do_bed(string arg)
{
        object who;
        object room;
        who=this_player();
                if( !objectp(room=query("inside")))
                        {
                        room=new(__DIR__"onbed");
                        room->set("exit",this_object());
                        set("inside",room);
                        }
        message_vision(HIY  "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n"  NOR,  who);
                who->move(room);
        message_vision(HIY  "\nɳ������һ����$N���˽�����\n"  NOR,  who);
        return 1;
} 
