 inherit ROOM;
void create()
{
        set("short", "ͥԺ");
        set("long", @LONG
����һ�������ε�СͥԺ��һ��ʯ�ڰ�����������������ש�̳ɵĵ���Ʈ��
�ż�Ƭ��Ҷ����������������ף���β������������Ȼ�Եá�Ժ�ӵĶ�����������
С���ţ����������á�
LONG
        ); 
    set("exits", ([ /* sizeof() == 4 */
                "east" : __DIR__"menkou",
        ]) ); 
        set("indoors","murong");
        setup();
        replace_program(ROOM);
}       
