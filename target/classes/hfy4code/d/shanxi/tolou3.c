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
  "east" :"/d2/shanxi/tolou4",
  //"east" : "/d2/shanxi/yuan1",
  //"west" : "/d2/shanxi/shulin1",
  "southwest" : "/d2/shanxi/tolou2",
  
]));
        set("outdoors", "shanxi");
set("coor/x",-480);
        set("coor/y",-290);
        set("coor/z",100);
        setup();
}
/*
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
} */  
