 // silencer@fy4 workgroup ������֮ľ��
inherit VRM_SERVER; 
void create()
{
        // �Թ��������̳е�����ĵ������ơ�
        set_inherit_room(__DIR__"wood-room"); 
        //�Թ��ĵ��߳� (5-100)
        set_maze_long(50); 
        //�Թ��������npc.
        //note: this one is optional
//      set_maze_npcs(__DIR__"npc/w-sentry-1"); 
        //�Թ������ڷ��� npc �Ŀ�����(1-100)
        //note: this one is optional too, if not set, then default is 20 (1/5)
//      set_maze_npc_rate(100); 
        //�Թ��ؽ�ʱ�� pass in integer ����Ϊ��λ
        //note: this one is optional, if not set then default is no refresh
        //if pass in 0, then means no refresh too.
        // this example means maze will be refreshed in 1 hour.
        set_maze_refresh(3600); 
        //��ڷ���(�����ڶ���)
        set_entry_dir("east"); 
        //�������������ӷ���
        set_link_entry_dir("east"); 
        //�������������ӵ�����
        set_link_entry_room(__DIR__"wood-entry");
        
        //��ڵ�����(��������link_entry_room���Ǹ���ʵroom������
        set_link_entry_room_x(1000);
        set_link_entry_room_y(2000);
        set_link_entry_room_z(3000);
         
        //��������������ӷ���
        set_link_exit_dir("west"); 
        //��������������ӵ�����
        set_link_exit_room(__DIR__"wood-exit"); 
        //��ڷ��������
        set_entry_short("����"); 
        //��ڷ�������
        set_entry_desc(@LONG
�߽����֣�ͻȻ������ղŴ���ж������������Իð�������ǰ���쿪������
�����岽����ǰ����һƬ������һƬ���֣�ͻȻ�䣬ֻ����Ҷ��ɳɳ���죬ǰ����
���Ҷ�����ľ��һ����һ�����Ҷ�׷�Ʈ�䣬���������Ļ�һƬ��û����⣬ֻ
��һ�����ɵ����⡣�������ʱ��ͷ�Ļ���������Ҳ�߲���ȥ�ˡ�
LONG
); 
        //���ڷ��������
        set_exit_short("�ݵ�"); 
        //���ڷ�������
        set_exit_desc(@LONG
�������һ����֦����ǰ��Ȼ�俪���������������߳�����Ƭ���֡�
LONG
); 
        //�Թ�����Ķ�����
        set_maze_room_short("����"); 
        //�Թ����������������ж�������������ÿ����
        //���ʱ���������ѡ��һ����
        set_maze_room_desc(@LONG
�������岽����ǰ����һƬ������һƬ���֣�ͻȻ�䣬ֻ����Ҷ��ɳɳ���죬
ǰ�������Ҷ�����ľ��һ����һ�����Ҷ�׷�Ʈ�䣬���������Ļ�һƬ��û
����⣬ֻ��һ�����ɵ����⡣�㲻��������һ����ʧ�ĸо���
LONG
); 
        // �Թ������Ƿ�Ϊ���ⷿ�䣿
        set_outdoors(1);
}  
