 // Room: black_earth.c --- by neon
#include <ansi.h>
inherit ROOM;
string vine();
void create()
{
        set("short", "黑色土地");
        set("long", @LONG
这是一个黑黝黝的土坡，它延伸而下，构成了五色土金字塔的一面。这一方黑
土看来真是上好的耕地。
LONG); 
    set("item_desc", ([
        "earth" : "油油的黑土地，不种（ｐｌａｎｔ）点什么真的很可惜。\n",
        "黑土" : "油油的黑土地，不种（ｐｌａｎｔ）点什么真的很可惜。\n",
        "土地" : "油油的黑土地，不种（ｐｌａｎｔ）点什么真的很可惜。\n",
        "vine" : (: vine :),
        "枯藤" : (: vine :),
    ])); 
        set("type","street");
        set("exits",([
                "westup":__DIR__"earthtemple",
        ]) );
        //}} 
        setup();
} 
void init(){
        add_action("do_plant", "plant");
} 
string vine(){
        object me;
        me = this_player();
        if(query("vine")){
                tell_object(me, "半段枯藤，似乎可以拔出。（ｐｕｌｌ　ｖｉｎｅ）\n");
                add_action("do_pull", "pull");
        } else {
                tell_object(me, "黑油油的土地上什么都没有。\n");
        }
        return "";
} 
int do_pull(string arg){
   object me, obj;
        me = this_player();
        if(arg == "vine" && query("vine")){
                message_vision("$N手抓枯藤用力一拉，一块黑色的石头被根须带了出来，滚落$N眼前。。\n", me);
                obj = new(__DIR__"obj/black_jade");
                if(objectp(obj)){
                        obj->move(this_object());
                }
                delete("vine");
                return 1;
        } 
        return 0;
} 
int do_plant(){
        object me, seed, pa;
        me = this_player();
        seed = present("black seed", me);
        pa = present("ding pa", me);
        if(objectp(seed) && objectp(pa)){
                message_vision("$N用钉耙仔细的耕耘了一小块地，又种下了一颗黑色的种子。\n", me);
                destruct(seed);
                call_out("plant_grow", 3);
        } else {
                return notify_fail("你似乎缺少种子或农具。\n");
        }
        return 1;
} 
void plant_grow(){
        object obj;
        message("vision", HIG"\n
一颗绿油油的小苗从黑土地里长出，又迅速的长大，开花，结果，并且迅速
凋零。。若非眼前的一个金黄色的果实，以及半段枯藤（ｖｉｎｅ），你不
由得认为一切都是幻景。\n"NOR, this_object());
        set("vine", 1);
        obj = new(__DIR__"obj/fruit");
        if(objectp(obj)){
                obj->move(this_object());
        }
} 
void reset(){
   ::reset();
        if(query("vine")){
                delete("vine");
        }
} 
