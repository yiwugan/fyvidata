#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "驿站马房");
        set("long", @LONG
人须健儿，马须良驹，每个驿站都配有专门的马房。这儿地处西疆，马都是
来自大宛，四肢细长，蹄上有小毛，鬃毛很稀，动作灵敏轻快，和内地那种骨骼
硕大，出自鲁南一带的马完全不同。马房被隔成六七个小间，角落里堆着草。
LONG
        );
        set("exits", ([ 
                "south":  __DIR__"yizhan",
        ]));
        set("objects",([
                __DIR__"npc/labor": 1,
                __DIR__"obj/corner":    1,
         ])  );
        set("item_desc", ([
                "草":   "饲料乱七八糟地堆在角落里。\n",
                "wood": "饲料乱七八糟地堆在角落里。\n",               
                "grass":"饲料乱七八糟地堆在角落里。\n",               
         ]));
        set("mouse",5);
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void reset(){
        object item, coffin;
        object *inv, *players;
        ::reset();
        if (!objectp(coffin=present("corner",this_object()))) return;
                
        if (!present("broken rake",coffin)) {
                item=new(__DIR__"obj/brokenrake");
                item->move(coffin);
        }
        if (!present("gao",coffin)) {
           item=new(__DIR__"obj/gao");
                item->move(coffin);
        }
        set("mouse",5);
        return;
} 
void init()
{
        add_action ("do_clean", "clean");
}  
int do_clean()
{               
        object me,mouse;
        int eff_kee,amount;
        
        me=this_player();
        if (!present("broken rake",me)) 
                return notify_fail("你身上没有扒草的工具呀。\n");
        
        eff_kee = me->query("kee");
        if (eff_kee < (int)this_player()->query("max_kee")/10) 
                return notify_fail("你太累了，怎么扒草？\n");
                
        if (me->is_busy())
                return notify_fail("你现在正忙。\n");
                
        me->start_busy(2);
        me->receive_damage("kee",(int)this_player()->query("max_kee")/10);
        message_vision(CYN"$N拿着钉把二话不说拨弄起饲料来，
辛苦了一番，马房里终于干净了一些。\n\n"NOR, me);
        
        if (me->query_skill("fork",1)<=50) {
                amount =  ((me->query("int") + me->query("cps"))*10);
                if(amount < 1) amount = 1;
                me->improve_skill("fork", amount);      
        }
        if (!random(5) && query("mouse")){
                mouse=new(__DIR__"npc/mice");
                mouse->move(this_object());
                message("vision","草堆下簌簌地钻出一只"+mouse->name()+"。\n",this_object());
           add("mouse",-1);
        }
        return 1;
}     
