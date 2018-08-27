 // Room: foodroom.c --- by MapMaker
inherit ROOM;
void create()
{
        set("short", "�Ȳ�");
        set("long", @LONG
������һ���¾ɵĹȲ֣�ë�������ɵ�שǽ�ѽ������䣬һյ�͵ƹ���ǽ�ϣ�
���Ż�Ƶĵƹ�����Կ������ܵľ���Ȳ����ȴ���ɾ������϶ѷ��ż�ʮ����
������ǽ�������ŷ���һ�����
LONG); 
        //{{ --- by MapMaker
        set("exits",([
                "east":__DIR__"magicroom",
                "west":__DIR__"flatfloor",
                "south":__DIR__"weapon_array",
        ]) );
        set("objects", ([
                __DIR__"obj/basket": 1,
                __DIR__"obj/sack" : 1,
        ]));
        //}}
        set("indoors", "yinghe");
        setup(); 
} 
void reset()
{
    object *inv, item1, item2, basket, sack;
    string ganguo;
    string *order = ({"zao", "lizi", "guiyuan", "baihe", "guihua"});
        ::reset();
    basket = present("basket", this_object());
    inv = all_inventory(basket);
        ganguo = order[random(5)];
        item1 = new(__DIR__"obj/"+ganguo);
        ganguo = order[random(5)];
        item2 = new(__DIR__"obj/"+ganguo);
    if( !sizeof(inv)) {
                if(objectp(item1)){
                item1->move(basket);
                }
        if(objectp(item2)){
                    item2->move(basket);
        }
    }
        sack = present("sack", this_object());
        inv = all_inventory(sack);
        if(!sizeof(inv)){
                item1 = new(__DIR__"obj/bean");
                if(objectp(item1)){
                        item1->move(sack);
                }
                item2 = new(__DIR__"obj/bean");
                if(objectp(item2)){
                        item2->move(sack);
                }
        } 
}   
