 // Room: snakehall.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "����"); 
        set("long", @LONG
�����ƺ���һ�����ҡ����ڽྻ���룬������������������һ�����ɡ�һ��̴
ľ���Ϸ��ʵʹ���һ���и���ױ̨��̨������ӯӯ��һ���綹��������͵Ĺ�â��
�������أ���ʱ�������㸡����
LONG); 
        set("indoors","yinghe");
        set("exits",([
                "out" : __DIR__"pearlcurtain",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}  
