inherit ROOM;
void create()
{
        set("short", "���°���");
        set("long", @LONG
�������ֲ�����ָ�������Ըо����ص���խ��ֻ����(climb)�Ź�ȥ��
LONG
        );
        set("no_magic",1);
        set("coor/x",-780);
        set("coor/y",-990);
        set("coor/z",90);
        setup();
}

init() 
{
        add_action("do_climb", "climb");        
}


int do_climb()
{
        object room;
        message_vision("$N���ź���ǰ��ȥ��\n",this_player());
        room = load_object(__DIR__"hole");
        this_player()->move(room);
        tell_object(this_player(),"��о�������ƽ̹��һЩ��\n",this_player());
        return 1;       

}