inherit ROOM;
void init();
void create()
{
        set("short", "��������");
        set("long", @LONG
���ڵ���һ����ս.�����ȫ�������.��Ϊ����
������С���Т�Ĳ���.ר��һ����.Ϊ������ÿ��
�˹�����.�ո�һ��.��������Ǻ���ת��.����ҩ��
����������һ�㡣���ߵ�ǽ��Ӱ��������
LONG );
        set("exits", ([ 
  "eastup" : __DIR__"congwai",
])); 
        set("objects",([
           __DIR__"obj/book2" : 1,
           __DIR__"obj/book3" : 1,
           __DIR__"obj/book" : 1,                                                   __DIR__"obj/book1" :1,
        ]) );
        set("coor/x",-195);
        set("coor/y",250);
        set("coor/z",20);
        set("no_magic",1);
        set("item_desc", ([
                "ǽ��": "һ��⻬ǽ�ڡ�\n",
        ]) );;
        set("no_dazuo",1);
        setup();
}
void init()
{
        add_action("do_jump", "break");
}

int do_jump(string arg)
{
        object me=this_player(), room;

        if(!arg || arg!="ǽ��")
                return notify_fail("�����ʲô��\n");

        if(!( room = find_object(__DIR__"dishi1")) )
                room = load_object(__DIR__"dishi1");

        if(!objectp(room))
                return notify_fail("ERROR:not found 'xiaojin.c' \n");
   if(!(me->query("force_factor") >= 120))
                return notify_fail("�������������˫�ֺ�ʮ��һ��ˮ������ǽ�ڻ�ȥ��\nǽ��һ��������\n");
   if(me->query_skill("lingshenforce") < 120 && me->query_skill("binghuostrike") < 80)
                return notify_fail("����书���ܴ����ǽ�ڡ�\n");
        message_vision("$N�����������˫�ֺ�ʮ��һ��ˮ������ǽ�ڻ�ȥ��\n�����������ͣ������ǽ������ȥ�ˡ�\n",me);
        me->move(room);
        return 1;
}
