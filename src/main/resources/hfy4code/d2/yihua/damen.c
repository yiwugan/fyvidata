//ROOM damen.c
inherit ROOM;
void create()
{
        set("short", "�ƻ�������");
        set("long",@LONG
�����ͨ���ƻ������Ĵ��š��������Ҹ���һƬ�ʻ�,��ζ
Ϯ�ˣ�ͨ�����ſ���ȥ������ܶ��ʻ�,������̲�ס��Ҫ��ȥ������
LONG
        );
        set("outdoors", "yihua");
        set("exits", ([
                "north" : __DIR__"qiandian",
                "south" : __DIR__"yihua_ge",
                	 "west" : __DIR__"yihua_in",
        ]));

        set("objects",([
        "/d/yihua/npc/huanu" : 1,
        ]));
        set("coor/x",-160);
        set("coor/y",145);
        set("coor/z",0);
        setup();
}

int valid_leave(object me, string dir)
{
        if (  (dir == "south")
           && ((string)me->query("family/family_name") != "�ƻ���")
           && objectp(present("hua nu", environment(me))) )
         return notify_fail
                ("��ū������ס�㣬˵�����������㲻���ƻ����ĵ��ӣ���Ҫ�������ܣ���Ȼ��ȥ���߹�������\n");
        return ::valid_leave(me, dir);
}
