 // FY4
#include <ansi.h>
inherit ROOM; 
string stone();
void create()
{
        set("short", "ӫ�����");
        set("long", @LONG
����һ��տ������أ����ص�������һ��ʯ̨����ˮ�ƺ���ʲô���������
��������Ϸ����������ĵĺӹ⣬���Կ��������ƺ���һ����������Ĵ��š���
��ڳ����ģ������м�С�ݡ�ʱ���ӱ���Ʈ�����ݺ�����ʱ���ִ����洵������
�ȷ磬���˺ܲ������
LONG); 
        //{{ --- by MapMaker
        set("exits",([
        "east":__DIR__"woodcabin",
        "west":__DIR__"golddoor",
        "south":__DIR__"firecave",
        "north":__DIR__"icehall",
        ]) );
        //}}
        set("item_desc", ([
                "stone" : (: stone :),
                "ʯ̨" : (: stone :),
        ]));
        set("indoors", "yinghe");
        setup();
} 
string stone(){
        object me;
        
        me = this_player();
        if(me->query("attribute_mark")&& me->query("attribute_mark")!="earth") {        
                tell_object(me, "ʯ̨�Ͽ��ż���ģ���ķ��š�\n");
        } else {
                tell_object(me, "��̨�Ͽ���"HIY"��"HIG"ľ"HIC"ˮ"HIR"��"NOR + YEL"��"NOR"����Զ�ŵ����֡����������裩\n");
                add_action("do_touch", "touch");
        }
        return "";
} 
int do_touch(string arg){
        object me;
        
        me = this_player();
        if(me->query("attribute_mark")&& me->query("attribute_mark")!="earth" ){
                return 0;
        }
        if(arg == "��" || arg == "jin" || arg == "gold"){
                message_vision("$N���ַ��ڡ������ϡ�\n", me);
                tell_object(me, HIY"�������ǰ���һ���������Լ��ۻ���\n"NOR);
                me->set("attribute_mark", "gold");
        } else if (arg == "ľ" || arg == "mu" || arg == "wood"){
                message_vision("$N���ַ��ڡ�ľ�����ϡ�\n", me);
                tell_object(me, HIG"���ƺ�͸��ľ�ſ���һƬ�Դ����ľ��\n"NOR);
                me->set("attribute_mark", "wood");              
        } else if(arg == "ˮ" || arg == "water" || arg == "shui"){
                message_vision("$N���ַ��ڡ�ˮ�����ϡ�\n", me);
                tell_object(me, HIC"�������Լ��������ˮ����\n"NOR);
                me->set("attribute_mark", "water");
        } else if(arg == "��" || arg == "fire" || arg == "huo"){
                message_vision("$N���ַ��ڡ������ϡ�\n", me);
                tell_object(me, HIR"һ������֮�������ֵ׵�ʯͷ�ϴ�����\n"NOR);
                me->set("attribute_mark", "fire");
        } else if(arg == "��" || arg == "earth" || arg == "tu"){
                message_vision("$N���ַ��ڡ��������ϡ�\n", me);
                message_vision(YEL"$N���º�Ȼһ�ɣ�������ٿ�س�����ȥ��\n"NOR, me);
                me->set("attribute_mark", "earth");
                me->move("/d/yinghe/earthtemple");
        } else {
                return notify_fail("��Ҫ�����\n");
        }
        return 1;
} 
int valid_leave(object who, string dir){
        if(dir == "north" && who->query("attribute_mark") == "water"){
                return 1;
        } else if(dir == "south" && who->query("attribute_mark") == "fire"){
                return 1;
        } else if(dir == "west" && who->query("attribute_mark") == "gold"){
                return 1;
   } else if(dir == "east" && who->query("attribute_mark") == "wood") {
                return 1;
        } else if(dir == "down" && who->query("attribute_mark") == "earth"){
                return 1;
        } else {
                return notify_fail("һ�ɾ޴�����������޷�ǰ����\n");
        } 
}  
