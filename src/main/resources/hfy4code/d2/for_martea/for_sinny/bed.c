#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("牙玉软榻", ({ "bed" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
                set("value",1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张牙玉色的软榻，塌四周雕着竹叶格，看上去极为精致(gosleep,gobed,bed)。\n");
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
        message_vision(HIY  "$N掀开纱帐，准备上床了。\n\n"  NOR,  who);
                who->move(room);
        message_vision(HIY  "\n沙帐轻轻一动，$N钻了进来。\n"  NOR,  who);
        return 1;
} 
