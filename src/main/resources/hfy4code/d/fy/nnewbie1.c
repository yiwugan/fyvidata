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
"out" : "/d/fy/ngatedown",
  "enter" : __DIR__"nnewbie2",
  
]));
        set("objects", ([
                __DIR__"obj/gui1" : 1,
                "/obj/newbie/sword2" :1,
"/obj/newbie/windsword" : 1,
"/obj/newbie/zheshan" : 1,
"/obj/newbie/toysword" :1,
 "/d/shaolin/npc/obj/axe" :1,
 "/obj/newbie/xiesword" : 1,

/*/obj/newbie/s_spear
/obj/newbie/g_spear
/obj/newbie/sword_katana
/obj/newbie/rockhammer
/obj/newbie/juque
/obj/newbie/wolf_hammer
/obj/newbie/guzi
/obj/newbie/bamboo_staff
/obj/newbie/dafeng*/
                
                        ]) );
        set("indoors", "fengyun");
                set("no_fight",1);

        set("coor/x",0);
        set("coor/y",50);
        set("coor/z",-10);
        
        setup();
}
