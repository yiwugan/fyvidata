 // FYteam
inherit ROOM; 
void create()
{
        set("short", "��Ӣ��");
        set("long", @LONG
����һ����Ĵ��á��ı��Ϲ����˸�ʽ�����ı�����������עĿ��ȴ��������
�Ĵ�ʯ�������ϰ����߼������ĺ��ӣ��ֱ��ǣ���������ǹ�����������ޡ�ذ�ס�
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
