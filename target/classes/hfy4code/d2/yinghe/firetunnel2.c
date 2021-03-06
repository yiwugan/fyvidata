 // Room: firetunnel2.c --- neon
inherit VRM_SERVER; 
void create() 
{ 
// 迷宫房间所继承的物件的档案名称。 
         // If you want your maze room has more functionality other than just room, you can create your own base maze room and make this line inherit from your own base maze room.  
set_inherit_room( ROOM );  
//迷宫的单边长 (5-100) 
set_maze_long(6);  
//迷宫房间里的npc. 
//note: this one is optional 
//set_maze_npcs(__DIR__"npc/mazewalker");  
//迷宫房间内放置 npc 的可能性(1-100) 
//note: this one is optional too, if not set, then default is 20 (1/5) 
//set_maze_npc_rate(50);  
//迷宫重建时间 pass in integer 以秒为单位 
//note: this one is optional, if not set then default is no refresh 
//if pass in 0, then means no refresh too. 
// this example means maze will be refreshed in 1 hour. 
set_maze_refresh(3600);  
//入口方向(出口在对面) 
set_entry_dir("north");  
//入口与区域的连接方向 
set_link_entry_dir("north");  
//入口与区域的连接档案名 
set_link_entry_room(__DIR__"firetunnel3");  
//出口与区域的连接方向 
set_link_exit_dir("south");  
//出口与区域的连接档案名 
set_link_exit_room(__DIR__"thunderstone");  
//入口房间短描述 
set_entry_short("艮火洞");  
//入口房间描述 
set_entry_desc(@LONG 
在一股灼人的热浪中，你被淹没于一片红色的光晕里，石质的地面似乎已将熔
化，地上几条裂隙喷吐着狰狞的暗红光芒，热流不断从你的脚踝涌上。 
LONG 
);  
//出口房间短描述 
set_exit_short("离火洞");  
//出口房间描述 
set_exit_desc(@LONG 
这是一个灼浪腾腾的山洞，洞壁透出暗暗的红色火光。一股股热浪袭来，
你似乎快被烤焦。更有无名的震响如雷鸣般传来，令人晕头晕脑，不辨方向。
东面似乎有阵阵微风吹来，给人一丝希望。 
LONG 
);  
//迷宫房间的短描述 
set_maze_room_short("雷火洞");  
//迷宫房间的描述，如果有多条描述，制造每个房 
//间的时候会从中随机选择一个。 
set_maze_room_desc(@LONG 
这是一个灼浪腾腾的山洞，洞壁透出暗暗的红色火光。一股股热浪袭来，你似
乎快被烤焦。更有无名的震响如雷鸣般传来，令人晕头晕脑，不辨方向。
LONG 
);  
// 迷宫房间是否为户外房间？ 
set_outdoors(0); 
} 
/*
void create()
{
        set("short", "雷火洞");
        set("long", @LONG
这是一个灼浪腾腾的山洞，洞壁透出暗暗的红色火光。一股股热浪袭来，你似
乎快被烤焦。更有无名的震响如雷鸣般传来，令人晕头晕脑，不辨方向。
LONG);
        
        set("indoors","yinghe");
        set("exits",([
                "east":__DIR__"firetunnel",
                "south":__DIR__"thunderstone",
                "north":__DIR__"firetunnel3",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}
*/     
