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
"out" : __DIR__"enewbie1",
  "enter" : __DIR__"enewbie3",
  
]));
        set("objects", ([
               
"/d/qianfo/obj/book3":1,
"/d/qianfo/obj/book4":1,
"/d/qianfo/obj/book5":1,
"/d/bat/npc/obj/qfbook":1,
"/d/wudang/npc/obj/book":1,
                
                        ]) );
        set("indoors", "fengyun");
                set("no_fight",1);

        set("coor/x",40);
        set("coor/y",0);
        set("coor/z",-10);
        
        setup();
}
