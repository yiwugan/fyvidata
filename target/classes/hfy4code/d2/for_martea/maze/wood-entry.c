 // silencer@fy4 workgroup ������֮ľ��
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "ľ��");
        set("long", @LONG
ľ����һƬ���֣�����ȥֻ�����﷽Բ��ȴ��ï�ܣ���������������Ī�⡣��
��ż����͸���ۣ��������������������ճ�һ���̲���������пյأ������ճ���
����������ľ޴��ľ���չ����һ���ֶ�����Ŷ����صĺڰ�֮�С� 
LONG
        ); 
        set("outdoors", "shaolin"); 
        set("exits", ([ 
                "west" : __DIR__"wood-maze/entry",
        ])); 
        setup(); 
} 
//      �����ʾ refresh maze 
void    init(){
        add_action("flush_maze","flush");
}  
int     flush_maze(){
        object maze_room;
        string flush_msg;
        maze_room=find_object(__DIR__"wood-maze");
        if (!maze_room) return 1;
        flush_msg=HIG"��Ȼ��һ��ַ紵������Χ����֦�������԰��趯������������
һ����ҡ��ת���㷢���Լ��ֻص������ӵĽ��ڡ�\n"NOR,
        maze_room->remove_all_players(maze_room,this_object(),flush_msg);
        maze_room->refresh_maze();
        return 1;
}     
