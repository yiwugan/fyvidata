//lmd@wenxin
inherit ROOM;
void create()
{
        set("short", "���������");
        set("long", @LONG
������Ǵ���ǵĳ����ģ�����ǵ���Ҫ�ֵ��������ｻ�ᣬ����·��������
�γ���һ����԰Լʮ���ɵĹ㳡���㳡�����Σ�һȦΧ�Ķ���С�������ˣ��Ϳ�����
�ġ�������������Ⱥ��Ҳ�ٲ���Щ���ܽ����ģ���ˣ��������������˷���һЩ����
ԭ����δ�ŵ�����������һЩ���뽭�����������˷ܲ��ѡ�λ�ڹ㳡������һ������
��С��ˮ�أ�һ�޴������ʯ������ˮ�����룬һ����ĸ�Ȫˮ��ʯ����������ӿ����
������ʯ���Ͽ�ȥ��ֻ�����飺
[1;32m
                         ~   ��  ��  ~

                         ~   ��  ��  ~

                         ~   ̫  ��  ~

                         ~   ƽ  ��  ~
[37m                         

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gnroad1",
  "south" : __DIR__"sroad1",
  "east" : __DIR__"eroad1",
  "west" : __DIR__"wroad1",
]));
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);
        set("outdoors", "dali");
        set("resource/water",1);
        set("liquid/name","�峺�ĳ�ˮ");
        set("liquid/type", "alcohol");
        set("liquid/drunk_apply",3);
        set("coor/x",-800);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
// To "load" the board, don't ever "clone" a bulletin board.
  //      call_other( "/obj/board/dali_a", "???" );

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
                                "name": "��Ȫˮ",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("����������װ�����峺�ĸ�Ȫˮ�� \n");
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