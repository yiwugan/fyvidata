 // FYteam
#include <ansi.h>
inherit ROOM; 
string stone();
void create()
{
        set("short", "�����Ŀ�");
        set("long", @LONG 
������һ���޴�Ŀ�Ѩ������һƬ���ף��������ң�������ǡ���Զ����Ȫˮ
����������������ҭҭ���������ߡ���Ѩ����һ�����͵�ʯ�̣��ϱ�ȴû�б�˪��
�ᡣ ͣ��ʱ�ã������������Ī���Ŀ־�ӿ����ͷ��
LONG); 
        set("item_desc", ([
                "ʯ��" : (: stone :),
                "stone" : (: stone :),  
        ]));
        set("indoors", "yinghe");
        setup(); 
} 
string stone(){
        object me;
        me = this_player();
        if(query("broken")) {
                tell_object(me, "һ�������ѿ��Ļ���ʯ�̡�\n");
        } else {
                tell_object(me, "һ�����ε�ʯ�̣���һʯ�����������ϣ��ƺ������ƶ����������裩\n");
                add_action("do_push", "push");
        }
        return "";
} 
int do_push(string arg){
        object me, room;
        
        me = this_player();
        if(query("borken")){
                return 0;
        }
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("������æ��\n");
        }
   if(arg == "stone" || arg == "ʯ��"){
                message_vision(HIC"\nʯ�̺�Ȼ�ѿ��������Ȫˮ��ӿ������һ������$N����ˮ�С�\n\n"NOR, me);
                set("broken", 1);
                room = find_object(__DIR__"well");
                if(!objectp(room)){
                        room = load_object(__DIR__"well");
                }
                me->move(room);
        } else {
                return notify_fail("��Ҫ��ʲô��\n");
        }               
        return 1;
} 
void reset(){
        ::reset();
        if(query("broken")){
                delete("broken");
        }
        return;
}   
