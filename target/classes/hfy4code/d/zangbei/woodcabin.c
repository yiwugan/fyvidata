 inherit ROOM;
#include <ansi.h>
string pai(); 
void create() 
{
        set("short", "�ּ�С��");
        set("long", @LONG
�����������һ��Сľ�ݣ�����������ָ���������ҵ���������������ܼ�
�ӣ��ܸɾ���ѩ�׵�ǽ�ϣ�����һ�����񡣻��ò����õ�����ȴ�ܴ���һ����
��΢�롢Ŀ�⾼������������ˣ�΢΢��������վ��һƬ�����⣬���ӱ�ͦ������
��һ�˱�ǹһ�㡣����ǰ�������㰸�Ͱ�ľ�����ơ�
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"woods3",
        ]));
        set("objects", ([
                __DIR__"npc/zhaodafang":        1,
                __DIR__"npc/yidajing":  1,
                __DIR__"obj/table":     1,
        ]) );
        set("item_desc", ([
                "picture": "һ������΢��������ˣ�������һ���϶н��ۣ����ϵ�˿���ϣ�����һ��
������ڵĵ���\n",
                "����":  "һ������΢��������ˣ�������һ���϶н��ۣ����ϵ�˿���ϣ�����һ��
������ڵĵ���\n",
                "��ľ������":   (: pai() :),
                "pai":          (: pai() :),
        ]));
        
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}  
string pai(){ 
    return
    "\n"
 "              **********\n"
 "         *        *\n"
 "              *   ��   *\n"
 "              *   ��   *\n"
 "              *   ��   *\n"
 "              *   ��   *\n"
 "              *   ��   *\n"
 "              *        *\n"
 "              *        *\n"
 "              *        *\n"
 "              *   ֮   *\n"
 "              *   λ   *\n"
 "              *        *\n"
 "              *        *\n"
 "              **********\n";
    "\n";
}     