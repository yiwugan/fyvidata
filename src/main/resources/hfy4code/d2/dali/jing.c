//lmd@wenxin
inherit ROOM;
void create()
{
        set("short", "ˮ��");
        set("long", @LONG
���Ǵ����԰��ˮ������˵����ھ���ˮ���軨���ܳ�����Ʒ�軨��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"chayuan",
]));
        set("outdoors", "dali");
        set("resource/water",1);
        set("liquid/name","��԰��ˮ");
//        set("liquid/type", "alcohol");
        set("liquid/drunk_apply",3);
        set("coor/x",-820);
        set("coor/y",-830);
        set("coor/z",80);
        setup();
}

void init()
{
        add_action("do_fillwater", "fillwater");
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "��԰��ˮ",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("��װ���˸մӾ����������ˮ�� \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��\n");
        }
        return 1;
}
