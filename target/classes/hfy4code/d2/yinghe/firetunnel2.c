 // Room: firetunnel2.c --- neon
inherit VRM_SERVER; 
void create() 
{ 
// �Թ��������̳е�����ĵ������ơ� 
         // If you want your maze room has more functionality other than just room, you can create your own base maze room and make this line inherit from your own base maze room.  
set_inherit_room( ROOM );  
//�Թ��ĵ��߳� (5-100) 
set_maze_long(6);  
//�Թ��������npc. 
//note: this one is optional 
//set_maze_npcs(__DIR__"npc/mazewalker");  
//�Թ������ڷ��� npc �Ŀ�����(1-100) 
//note: this one is optional too, if not set, then default is 20 (1/5) 
//set_maze_npc_rate(50);  
//�Թ��ؽ�ʱ�� pass in integer ����Ϊ��λ 
//note: this one is optional, if not set then default is no refresh 
//if pass in 0, then means no refresh too. 
// this example means maze will be refreshed in 1 hour. 
set_maze_refresh(3600);  
//��ڷ���(�����ڶ���) 
set_entry_dir("north");  
//�������������ӷ��� 
set_link_entry_dir("north");  
//�������������ӵ����� 
set_link_entry_room(__DIR__"firetunnel3");  
//��������������ӷ��� 
set_link_exit_dir("south");  
//��������������ӵ����� 
set_link_exit_room(__DIR__"thunderstone");  
//��ڷ�������� 
set_entry_short("�޻�");  
//��ڷ������� 
set_entry_desc(@LONG 
��һ�����˵������У��㱻��û��һƬ��ɫ�Ĺ����ʯ�ʵĵ����ƺ��ѽ���
�������ϼ�����϶�����������İ����â���������ϴ���Ľ���ӿ�ϡ� 
LONG 
);  
//���ڷ�������� 
set_exit_short("���");  
//���ڷ������� 
set_exit_desc(@LONG 
����һ���������ڵ�ɽ��������͸�������ĺ�ɫ��⡣һ�ɹ�����Ϯ����
���ƺ��챻���������������������������㴫����������ͷ���ԣ����淽��
�����ƺ�������΢�紵��������һ˿ϣ���� 
LONG 
);  
//�Թ�����Ķ����� 
set_maze_room_short("�׻�");  
//�Թ����������������ж�������������ÿ���� 
//���ʱ���������ѡ��һ���� 
set_maze_room_desc(@LONG 
����һ���������ڵ�ɽ��������͸�������ĺ�ɫ��⡣һ�ɹ�����Ϯ��������
���챻���������������������������㴫����������ͷ���ԣ����淽��
LONG 
);  
// �Թ������Ƿ�Ϊ���ⷿ�䣿 
set_outdoors(0); 
} 
/*
void create()
{
        set("short", "�׻�");
        set("long", @LONG
����һ���������ڵ�ɽ��������͸�������ĺ�ɫ��⡣һ�ɹ�����Ϯ��������
���챻���������������������������㴫����������ͷ���ԣ����淽��
LONG);
        
        set("indoors","yinghe");
        set("exits",([
                "east":__DIR__"firetunnel",
                "south":__DIR__"thunderstone",
                "north":__DIR__"firetunnel3",
        ]) );
        //}} 
        setup();
        replace_program(ROOM);
}
*/     
