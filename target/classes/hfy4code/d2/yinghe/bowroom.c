 // Room: bowroom.c --- by MapMaker
#include <ansi.h>
inherit ROOM; 
void create()
{
        object bow, wall, arrow1, arrow2;
        
        set("short", "����������");
        set("long", 
"����һ�俪���Ĵ�������Χ��ǽ����װ���Ÿ��ָ���������ǽ�����й���һ
�����صĴ󹭡���������һ�Դ��������飺 
"YEL"
            ��          ��         
            ��          ��        
            ��          ��         
            ��          ��         "NOR" 
");
        set("objects", ([
                __DIR__"obj/wall" : 1,
                __DIR__"npc/laonu" : 1,
        ]));
        set("indoors","yinghe");
        set("exits",([
                "north":__DIR__"irongate3",
                "southeast":__DIR__"stonepath",
        ]) );
        //}} 
        setup();
        wall = present("ǽ��", this_object());
        bow = new(__DIR__"obj/bow");
        arrow1 = new(__DIR__"obj/arrow");
        arrow2 = new(__DIR__"obj/smallarrow");
        if(objectp(bow)){
                bow->move(wall);
                arrow1->move(wall);
                arrow2->move(wall);
        }
} 
void reset(){
        object bow, wall, arrow1, arrow2, *inv;
   int i;
        
        ::reset();
        
        inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++) {
                if( userp( inv[i]) ) return;
        }
        add("refresh_counter", 1);
        wall = present("ǽ��", this_object());
        if ( (int) query("refresh_counter") > 2 ) {
                bow = new(__DIR__"obj/bow");
                arrow1 = new(__DIR__"obj/arrow");
                arrow2 = new(__DIR__"obj/smallarrow");          
                arrow1->move(wall);
                arrow2->move(wall);
                bow->move(wall);
                delete("refresh_counter");
        }
        return;
} 
