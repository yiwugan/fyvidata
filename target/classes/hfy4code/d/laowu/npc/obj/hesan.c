#include <ansi.h>
inherit ITEM; 
void create()
{
set_name(HIB"离魂散"NOR, ({ "lihunsan" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long","这是昔年蝙蝠公子的独门密药，可以用（ｙｏｎｇ）在自己身上。\n");
        }
        ::init_item();
}
void init()
{
        add_action("do_yong","yong");
} 
int do_yong(string arg)
{
        object ob,room;
        object me,corpse;
        me=this_player();
        if(me->is_busy()) return notify_fail("你正忙着呢。\n");
        if (!arg) return notify_fail("你要用在谁身上？\n");
        if ( me->query("combat_exp") < 1500000 )
                return notify_fail("你经验太差了，妄用"+this_object()->name()+"会引火烧身，伤害自己的。\n");
        ob=present(arg,environment(me));
        if (ob!=me) 
                return notify_fail("灵丹妙药岂能浪费在别人身上?\n");
        if( environment(me)->query("no_fight") ||
                environment(me)->query("no_magic") ||
                        environment(me)->query("no_spells") )
                return notify_fail("在这里不能用这个东西！\n");
        message_vision("$N小心翼翼地捧出$n吞了下去。\n",me, this_object());
        message_vision(BLU "$N只觉神魂飘忽，缕缕魂魄如抽丝般游出体外。\n"NOR,ob);
        message_vision("$N死了。\n",me);
        room = environment(me);
        if(objectp(corpse = CHAR_D->make_corpse(me, me)))
                        corpse->move(room);
   me->move("/d/death/yanluo");
        me->be_ghost(1);
        tell_object(me,"你的"+RED"内功心法"NOR+"降低了。\n");
        tell_object(me,"你的"+RED"扑击格斗之技"NOR+"降低了。\n");
        tell_object(me,"你的"+RED"基本轻功"NOR+"降低了。\n");
        me -> unconcious();  
        destruct(this_object());     
        return 1;
}   
