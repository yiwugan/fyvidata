 inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @long
��������һƬ����Ǭˬ��������Ȼ�������˰��˺ܶණ����������Ȼ��
�úܿ������ϻ���һЩʪ�����Ľ�ӡ����Ȼ��������������żȻ�������һ
����Ӱ��Ҳ�����û̿֡������ƺ��Ե��ϵı��ﲢ��̰����ֻȡȥ�Լ����裬
�������뿪��
long
        );
        set("exits", ([ /* sizeof() == 4 */
"out" : "/d/fy/egatedown",
  "enter" : __DIR__"enewbie2",
  
]));
        set("objects", ([

"/d/qingping/obj/books":1,
"/d/qianfo/obj/book1":1,
"/d/qianfo/obj/book2":1,
                
                        ]) );
        set("indoors", "fengyun");
                set("no_fight",1);

        set("coor/x",50);
        set("coor/y",0);
        set("coor/z",-10);
        
        setup();
}
