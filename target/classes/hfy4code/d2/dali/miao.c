inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǵ����������( shaoxiang )��Ը�ĵط�����˵��������ع���
ʮ�����飬����ÿ��������ڣ����ﶼ��ͥ���С���Ҷ�������ͨ������
����ƽ�����м�һ����̨������ư���������Ρ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"wroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-880);
        set("coor/y",-740);
        set("coor/z",80);
        setup();
}
void init()
{
       add_action("do_ponder","shaoxiang");
}
int do_ponder(string arg)
{
       object who;

       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("����񲻹���\n");
       message_vision("$N�ϵع����㰸ǰ��ĬĬ����\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 15 ) );
       message_vision("$N�ƺ��о�������ˬ�����ϵ�ɱ��Ҳ�ƺ������˲��١� \n" , who);
    return 1;
}