 inherit VRM_SERVER;
void create()
{
        // �Թ��������̳е�����ĵ������ơ�
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
        set_entry_dir("east"); 
        //�������������ӷ���
        set_link_entry_dir("east"); 
        //�������������ӵ�����
        set_link_entry_room(__DIR__"shandao"); 
        //��������������ӷ���
        set_link_exit_dir("west"); 
        //��������������ӵ�����
        set_link_exit_room(__DIR__"muwu"); 
        //��ڷ��������
        set_entry_short("ɽ����"); 
        //��ڷ�������
        set_entry_desc(@LONG
����������ɽ�İ�ɽ����������һ����ֱ��ɽ������������
ȥ��һƬ���̵����֣���ʱ��������������
LONG
); 
        //���ڷ��������
        set_exit_short("��ʯ·"); 
        //���ڷ�������
        set_exit_desc(@LONG
������һ����ʯС·��������һƬ���̵����֣���ʱ������
��������������ȥ��Լһ��Сľ�ݣ���ɽ���֣�����һ��������
Դ�������ڡ�
LONG
); 
        //�Թ�����Ķ�����
        set_maze_room_short("����"); 
        //�Թ����������������ж�������������ÿ����
        //���ʱ���������ѡ��һ����
        set_maze_room_desc(@LONG
����һƬŨ�ܵĴ����֣�С����������ͷ紵�����ֵ�ɳɳ
����֯�������Ĵ���Ȼ�����ɡ������Ӳݴ���˵�������������
������׳�Ĵ����ֱ���ϣ�����������������ϴ���
LONG
); 
        // �Թ������Ƿ�Ϊ���ⷿ�䣿
        set_outdoors(1);
}   
