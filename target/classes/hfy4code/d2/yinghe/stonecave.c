 // Room: stonecave.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "��ʯ��"); 
        set("long", @LONG
��ˮ����úӹ����߳�������ɭɭ��ɽʯ����һ��˵��������ʵ���ʸС����治
Զ�ĵط���һ������ʯ̨���������ϡ�
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
        "east":__DIR__"stonestair1",
        "northwest":__DIR__"fountain",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}      
