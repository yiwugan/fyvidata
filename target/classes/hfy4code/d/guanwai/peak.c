#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"���µ�һ��"NOR); 
        set("long", @LONG
����������µ�һ�塪����������壡��
����Ⱥɽ��Զ���Ĵ��ԭ���ڽ��¡���ɫ�Ĳ��������ڽ����¿������紿��������
����ɫ�ı�������ʶ�һ�����ӷ嶥������˷�����ȥ����Ƕ�ڽ�׵�ɽ���ϡ���
���侢����ѩ���ˣ�����������ɽ�ӣ��������أ�׳־���ƣ�������������֮
�ģ���Х���������ƷŸ衣
LONG); 
        set("type","street");
        set("exits",([
        "jump":"/daemon/class/ghost/wudang-quan/null",
        ]) );
        set("objects", ([
                __DIR__"npc/champion":1,
        ]) );
        set("outdoors", "guanwai");
        set("no_death_penalty",1);
        set("coor/x",-1280);
        set("coor/y",-110);
        set("coor/z",888); 
        setup();
        call_other( "/obj/board/hero_b", "???" );
}     
