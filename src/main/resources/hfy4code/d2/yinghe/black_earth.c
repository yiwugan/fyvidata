 // Room: black_earth.c --- by neon
#include <ansi.h>
inherit ROOM;
string vine();
void create()
{
        set("short", "��ɫ����");
        set("long", @LONG
����һ������������£���������£���������ɫ����������һ�档��һ����
�����������Ϻõĸ��ء�
LONG); 
    set("item_desc", ([
        "earth" : "���͵ĺ����أ����֣�����������ʲô��ĺܿ�ϧ��\n",
        "����" : "���͵ĺ����أ����֣�����������ʲô��ĺܿ�ϧ��\n",
        "����" : "���͵ĺ����أ����֣�����������ʲô��ĺܿ�ϧ��\n",
        "vine" : (: vine :),
        "����" : (: vine :),
    ])); 
        set("type","street");
        set("exits",([
                "westup":__DIR__"earthtemple",
        ]) );
        //}} 
        setup();
} 
void init(){
        add_action("do_plant", "plant");
} 
string vine(){
        object me;
        me = this_player();
        if(query("vine")){
                tell_object(me, "��ο��٣��ƺ����԰γ����������졡�����壩\n");
                add_action("do_pull", "pull");
        } else {
                tell_object(me, "�����͵�������ʲô��û�С�\n");
        }
        return "";
} 
int do_pull(string arg){
   object me, obj;
        me = this_player();
        if(arg == "vine" && query("vine")){
                message_vision("$N��ץ��������һ����һ���ɫ��ʯͷ��������˳���������$N��ǰ����\n", me);
                obj = new(__DIR__"obj/black_jade");
                if(objectp(obj)){
                        obj->move(this_object());
                }
                delete("vine");
                return 1;
        } 
        return 0;
} 
int do_plant(){
        object me, seed, pa;
        me = this_player();
        seed = present("black seed", me);
        pa = present("ding pa", me);
        if(objectp(seed) && objectp(pa)){
                message_vision("$N�ö�����ϸ�ĸ�����һС��أ���������һ�ź�ɫ�����ӡ�\n", me);
                destruct(seed);
                call_out("plant_grow", 3);
        } else {
                return notify_fail("���ƺ�ȱ�����ӻ�ũ�ߡ�\n");
        }
        return 1;
} 
void plant_grow(){
        object obj;
        message("vision", HIG"\n
һ�������͵�С��Ӻ������ﳤ������Ѹ�ٵĳ��󣬿��������������Ѹ��
���㡣��������ǰ��һ�����ɫ�Ĺ�ʵ���Լ���ο��٣������壩���㲻
�ɵ���Ϊһ�ж��ǻþ���\n"NOR, this_object());
        set("vine", 1);
        obj = new(__DIR__"obj/fruit");
        if(objectp(obj)){
                obj->move(this_object());
        }
} 
void reset(){
   ::reset();
        if(query("vine")){
                delete("vine");
        }
} 
