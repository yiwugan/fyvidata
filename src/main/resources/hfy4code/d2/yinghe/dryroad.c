 // Room: dryroad.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "��ɳ·"); 
        set("long", @LONG
����һ�����ѵĻ�ɳС����������ͨ��һ���վ���ɽ�룬����������һ��������
ľ�ȡ�ÿ����������������ɳ���죬�粽���С�
LONG);
        
        set("outdoors", "yinghe");
        set("exits",([
        "westup":__DIR__"windmoutain",
        "northeast":__DIR__"woodroad4",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}    
