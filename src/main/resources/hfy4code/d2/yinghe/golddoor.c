 // FYteam
#include <ansi.h> 
inherit ROOM;
string door();
void create()
{
        set("short", "�Խ����"); 
        set("long", @LONG
һ�Ⱦ޴�ĳ����ţ����ɶ�ߣ����ɶ��ϸ��֮�£�����˾޴���صĴ�
�ž�Ȼ�����Ļƽ����ɵġ�
LONG); 
        //{{ --- by MapMaker
        set("type","indoors");
        set("exits",([
                "east":__DIR__"center",
        ]) );
        //}}
        set("item_desc", ([
                "door" : (: door :),
                "����" : (: door :),
        ]));
        setup(); 
}  
void init(){
        add_action("do_open", "open");
} 
int do_open(string arg){
        object me, ob, room;
        
        me = this_player();
        if(!arg || arg != "door" && arg != "����"){
                return 0;
        } 
        if(me->query("attribute_mark") == "gold") {
                message_vision("$N��˫�ַ��ڴ����ϣ�һ��ҫ�۵Ľ��������$N��������ʧ������\n", me);
                room = find_object(__DIR__"westgate");
                if(!objectp(room)){
                        room = load_object(__DIR__"westgate");
                }
                me->move(room);
   } else {
                message_vision("$N��˫�ַ��ڴ����ϡ�\n", me);
                tell_object(me, "�����Ǳ�����Ӳ�Ĵ��š�\n", me);
        }
        return 1;
} 
string door(){
        object me;
        me = this_player();
        
        tell_object(me, "�������ƽ����ɵĴ��ţ��㲻�ɻ�������ƽ��Ż��ɽ��ӵ������г����ĸо���
�㲻�ɵ�����Ѱ����һ�飬�뿴����û��ʲô������������һ����ӡ�
������𣯣���\n");
        message("vision", me->name() + "�۾����Żƽ���ţ�һ˿������ǵĿ�ˮ˵����һ�С�����\n", environment(me), me);
        add_action("do_chop", "chop");
        return "";
} 
int do_chop(string arg){
    object obj, me, ob, guard;
    
    me = this_player();
    if(arg && (arg=="door" || arg=="����")){
        obj = me->query_temp("weapon");
        if( !obj ) {
            write("������֣���ô����\n");
            return 1;
        }
        guard = present("golddoor guardian", this_object());
        if(objectp(guard)){
                return notify_fail("���˿��ţ�����������ðɣ�\n");
        }
        if( obj->query("flag") == 4){
                if( obj->query("skill_type") == "axe"){
                if(query("chop") < 10) {
                        message_vision(sprintf(
                        "$N�Ӷ�%s����ƽ����ɵĴ��ţ�����~~~~����һ����ŵ��������������ܡ�\n",obj->name()),me);
                        add("chop", 1);
                        if(random(3)){
                                ob=new(__DIR__"obj/goldpiece");
                                if(objectp(ob)){
                                   message_vision(HIY"\nһ˿���ɫ׹��������ǰ��\n"NOR, me);
                                        ob->move(this_object());
                                        }
                                }
                        } else  {
                                guard = new(__DIR__"npc/golddoor_guard");
                                if(objectp(guard)){
                                        guard->move(this_object());
                                }
                                message_vision(HIY"\nһ�������׵���ʿͻȻ���֡�\n"NOR, me);
                                guard->kill_ob(me);
                        }
            } else {
                message_vision(sprintf(
                                    "$N�����е�%s�������һͨ�ҿ���\n",obj->name()), me);
                        }
                } else {
                message_vision(sprintf(
                "$N�����е�%s�������һͨ�ҿ���\n",obj->name()), me);
        }
    }
    else write("��Ҫ��ʲô��\n");
    return 1;
} 
void reset(){
        ::reset();
        delete("chop");
}
