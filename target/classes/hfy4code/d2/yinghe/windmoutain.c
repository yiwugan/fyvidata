 // Room: windmoutain.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "�Ʒ�ɽ"); 
        set("long", @LONG
�վ���ɽ���ϣ�é�ݼ������ַ�����ɽ·��ʱ�������ĺ��ǣ�Ҳ��֪������
�ǻ����޹ǡ����ڴ˴����㲻�ò���㾫��С���ж���
LONG);
        set("long_night", @LONG
�վ���ɽ���ϣ�ӫ��΢΢������ҹ�䡣ɽ·��ʱ�������ĺ��ǣ�Ҳ��֪������
�ǻ����޹ǡ����ڴ˴����㲻�ò���㾫��С���ж���
LONG);  
        set("outdoors", "yinghe");
        set("exits",([
                "eastdown":__DIR__"dryroad",
                "westdown":__DIR__"dryroad3",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/bandit" : 2+random(3),
                __DIR__"npc/crazy_dog" : 1,
        ]));
        setup();
        replace_program(ROOM);
}   
