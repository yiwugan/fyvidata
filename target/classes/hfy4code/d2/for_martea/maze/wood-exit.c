 // silencer@fy4 workgroup ������֮ľ��
inherit ROOM; 
void create()
{
        set("short", "Сľ��");
        set("long", @LONG
����һ���ª��Сľ�ݣ����ڿ��߷���һ��ľ�崲���м���һ��ľ�������Ϸ�
�������ڵķ��ˣ������ǿ���������ֵ����ߡ�
LONG
        );
        set("no_clean_up", 0); 
        set("exits",([
        "east" : __DIR__"wood-maze/exit", 
        ])); 
        setup();
        
} 
