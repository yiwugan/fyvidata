 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @long
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï
�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ
�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
long
        );
        set("exits", ([ 
  "north" :"/d2/shanxi/shulin3",
  "east" : "/d2/shanxi/shulin3",
  "west" : "/d2/shanxi/yuan4",
  "south" : "/d2/shanxi/yuan3",
  
]));
        set("outdoors", "shanxi");
        set("coor/x",-450);
        set("coor/y",-350);
        set("coor/z",100);
        setup();
}
void init()
{
        add_action("do_go","go"); 
} 
int do_go()
{
if(random(10)){
this_player()->move(this_object());
return 1;
}
} 
