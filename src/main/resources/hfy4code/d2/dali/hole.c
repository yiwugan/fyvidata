inherit ROOM;
void create()
{
        set("short", "���°���");
        set("long", @LONG
�������ֲ�����ָ�������Ըо����ص���խ��ֻ����(climb)�Ź�ȥ��
Զ���ƺ���һ������⡣
LONG
        );
        set("no_magic",1);
        set("coor/x",-750);
        set("coor/y",-950);
        set("coor/z",80);
        setup();
}

init() 
{
        add_action("do_climb", "climb");        
}


int do_climb()
{
        object room;
        message_vision("$N˳��������ǰ��ȥ��\n",this_player());
        tell_object(this_player(),"�����˶��ڣ�����ǰһ����\n",this_player());
        room = load_object(__DIR__"shanjiao");
        this_player()->move(room);
        return 1;       

}