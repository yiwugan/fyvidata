 // Room: woodroad.c --- neon
inherit ROOM; 
void create()
{
        set("short", "��ľ����"); 
        set("long", @LONG
����һ��������ľ���ȣ�������ڹ�����ɳ֮�ϡ������ɽ��͸���������翾
���ˣ������ڳ��ȵ�ľ�Ķ������ɽ��ڵ���ɫ������ľ��֮�ϣ�������ɳ������ľ
�����ŽŲ��������죬���˲��ɵ����ĵ�����ľ�������ػأ�����Զ����һ������
��Ľṹ������ɳ֮�У��ƺ���ľ�ȵ�֧�š�
LONG);
//  pick firewood here 
        
        set("indoors", "yinghe");
        set("exits",([
        "east":__DIR__"woodroad2",
        "north":__DIR__"slop",  
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
} 
