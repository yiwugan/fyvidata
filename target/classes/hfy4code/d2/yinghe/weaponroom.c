 // FYteam
inherit ROOM; 
void create()
{
        set("short", "聚英堂");
        set("long", @LONG
这是一间宽敞的大堂。四壁上挂满了各式各样的兵器。最引人注目的却是厅中央
的大石桌。桌上摆了七件兵器的盒子，分别是：刀、剑、枪、锤、斧、鞭、匕首。
LONG); 
        set("valid_startroom", 1);
        set("exits",([
                "south":__DIR__"silversand",
                "north":__DIR__"weapon_array",
                "northeast":__DIR__"waterhole",
        ]) );
        //}}
        set("objects", ([
                __DIR__"obj/stone_table" : 1,
                "/obj/food_item/wineskin" : 3,
                "/obj/food_item/shaobing": 2,
        ]));
        set("indoors", "yinghe");
        setup();
} 
void reset(){
        object obj;
        ::reset();
        if(objectp(obj = present("stone table", this_object()))){
                if(obj->query("box")) {
                        obj->delete("box");
                }
        }       
        set("objects", ([
                "/obj/food_item/wineskin" : 3,
                "/obj/food_item/shaobing": 2,   
        ]));
        return;
}    
