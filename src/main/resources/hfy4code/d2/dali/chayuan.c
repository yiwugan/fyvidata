inherit ROOM;
void create()
{
        set("short", "�軨԰");
        set("long", @LONG
Ժ�������˲軨���硣ÿ�ö�����׳�ɳ�����Ȼ���˾����չˡ�����
֮�仹���˹����ѵ�С�ӹ�����������ˮ�������ʣ������ÿһ�����硣
�����ڶ����ɣ���Ȼ�Ǳ���Ӫ���ķ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sroad2",
  "west" : __DIR__"jing",
]));
        set("outdoors", "dali");
        set("item_desc", ([
                "�軨": "
���ƺ������ڣ����磩�������������
                        \n",

        ]) );
        set("coor/x",-810);
        set("coor/y",-830);
        set("coor/z",80);
        setup();
}
void init()
{
        add_action("do_dig","dig");
}
do_dig()
{
object vege;
if((this_player()->query("sen") < 70) || (this_player()->query("kee") < 70) || (this_player()->query("gin") < 70) )
 {
  write("���Ѿ�û�����������ˡ�\n");
  return 1;
 }
if((int) query("pulled") <= 5000)
{
write("������һ�ò軨������ڻ��\n");
vege = new(__DIR__"obj/huamiao");
vege->move(this_player());
this_player()->add("sen",-(random(50)+20));
this_player()->add("kee",-(random(50)+20));
this_player()->add("gin",-(random(50)+20));
add("pulled",1);
return 1;
}
else
        write("�������ڹ��ˣ���\n");
        return 1;
}

void reset()
{
:: reset();
delete("pulled");
}
