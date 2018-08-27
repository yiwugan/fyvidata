#include <ansi.h>
inherit ITEM;
string statuedesc(); 
void create()
{
    set_name("铁像", ({"statue","铁像"}) );
    set_weight(200000);
    set("no_get",1);
    set("no_shown",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",(: statuedesc :));
                set("unit", "座");
                set("value", 3000);
              }
    ::init_item();
} 
void init()
{
        add_action("do_turn","turn");
} 
string statuedesc()
{
        object me;
        string msg;
        me = this_player();
        msg="一座二人高的铁像，塑一大手大脚的虬髯汉子，两条发墨般的浓眉，棱棱的颧
骨，一只瘦骨嶙峋的大手抓着柄已锈得快烂的铁剑。\n";
        if (me ->query("marks/恶人窟")||me->query("marks/蜘蛛恶人窟"))
        {       
                msg+="仔细看去，铁剑的把手(handle)似乎可以转动(turn)。\n";
        }
        return msg;
} 
int do_turn( string arg){
        object me, room;
        
        me=this_player();
        if (!me->query("marks/恶人窟") && !me->query("marks/蜘蛛恶人窟")) 
           return 0;
        if (!arg || (arg!="把手" && arg!="handle")) {
                tell_object(me,"你要转什么？\n");
                return 1;
                }
        if (me->query("combat_exp")<2500000)
                tell_object(me,"你费尽全力，把手纹丝不动，也许是武功太差了吧。\n");
        message_vision  (YEL"$N用力一扳剑柄，只听一阵嘎嘎的响声，$N脚下出现了一个大洞。\n"NOR,me);
        room = find_object(AREA_EREN"tocave");
        if(!objectp(room)) 
                room = load_object(AREA_EREN"tocave"); 
        message_vision(HIR"一声惊叫，$N向洞里直坠下去。\n"NOR,me);
        message("vision",HIG"上方又掉下一个人来，手忙脚乱地抓住了你身边的藤条。\n"NOR,room);
        me->move(room);
        return 1;
}
