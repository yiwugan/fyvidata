 inherit ROOM;
void create()
{
        set("short", "�Ŷ�");
        set("long", @LONG
վ�ڴ˴����￴ӭ����һʯ�ڣ��������Ǳ��̵Ĳ�ƺ���Ŷ��ڰ���һ������ľ
���Ա���һ��СС����ʣ�������һ��С�ŷ�����Լ�ǿ�������Ϣ�ĵط���        
LONG
        ); 
    set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"murong",
                "west" : __DIR__"mroom",
                "northwest" : __DIR__"yard1",
                "northeast" : __DIR__"yard2",
        ]) ); 
        set("outdoors","murong"); 
        setup();
        replace_program(ROOM);
}    
