 // FYteam
#include <ansi.h> 
inherit ROOM;
string door();
void create()
{
        set("short", "辉金大门"); 
        set("long", @LONG
一扇巨大的赤金大门，两丈多高，三丈多宽。细看之下，这如此巨大厚重的大
门竟然是足赤的黄金铸成的。
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
                "east":__DIR__"center",
        ]) );
        //}}
        set("item_desc", ([
                "door" : (: door :),
                "大门" : (: door :),
        ]));
        setup(); 
}  
void init(){
        add_action("do_open", "open");
} 
int do_open(string arg){
        object me, ob, room;
        
        me = this_player();
        if(!arg || arg != "door" && arg != "大门"){
                return 0;
        } 
        if(me->query("attribute_mark") == "gold") {
                message_vision("$N把双手放在大门上，一道耀眼的金光闪过，$N的身形消失不见。\n", me);
                room = find_object(__DIR__"westgate");
                if(!objectp(room)){
                        room = load_object(__DIR__"westgate");
                }
                me->move(room);
   } else {
                message_vision("$N把双手放在大门上。\n", me);
                tell_object(me, "触手是冰凉坚硬的大门。\n", me);
        }
        return 1;
} 
string door(){
        object me;
        me = this_player();
        
        tell_object(me, "看着足赤黄金铸成的大门，你不由幻想着这黄金门化成金子掂在手中沉甸甸的感觉。
你不由得四周寻肆了一遍，想看看有没有什么东西可以劈下一点金子。
（ｃｈｏｐ／ｏｐｅｎ）\n");
        message("vision", me->name() + "眼睛盯着黄金大门，一丝挂在嘴角的口水说明了一切。。。\n", environment(me), me);
        add_action("do_chop", "chop");
        return "";
} 
int do_chop(string arg){
    object obj, me, ob, guard;
    
    me = this_player();
    if(arg && (arg=="door" || arg=="大门")){
        obj = me->query_temp("weapon");
        if( !obj ) {
            write("你空着手，怎么砍？\n");
            return 1;
        }
        guard = present("golddoor guardian", this_object());
        if(objectp(guard)){
                return notify_fail("有人看着，这样做不大好吧！\n");
        }
        if( obj->query("flag") == 4){
                if( obj->query("skill_type") == "axe"){
                if(query("chop") < 10) {
                        message_vision(sprintf(
                        "$N挥动%s劈向黄金铸成的大门，“锵~~~~”的一声，诺大的声音震荡在四周。\n",obj->name()),me);
                        add("chop", 1);
                        if(random(3)){
                                ob=new(__DIR__"obj/goldpiece");
                                if(objectp(ob)){
                                   message_vision(HIY"\n一丝金黄色坠落在你眼前。\n"NOR, me);
                                        ob->move(this_object());
                                        }
                                }
                        } else  {
                                guard = new(__DIR__"npc/golddoor_guard");
                                if(objectp(guard)){
                                        guard->move(this_object());
                                }
                                message_vision(HIY"\n一个金盔金甲的武士突然出现。\n"NOR, me);
                                guard->kill_ob(me);
                        }
            } else {
                message_vision(sprintf(
                                    "$N用手中的%s向大门上一通乱砍。\n",obj->name()), me);
                        }
                } else {
                message_vision(sprintf(
                "$N用手中的%s向大门上一通乱砍。\n",obj->name()), me);
        }
    }
    else write("你要砍什么？\n");
    return 1;
} 
void reset(){
        ::reset();
        delete("chop");
}
