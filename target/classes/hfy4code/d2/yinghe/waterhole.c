 // Room: waterhole.c --- by MapMaker
#include <ansi.h>
inherit ROOM; 
string spring();
void diving(object me);
void create(){
        set("short", "��ˮȪ");
        set("long", @LONG
һ����������������˾���һ��̧ͷ����ǰ����Զ����һС̶��̶��
����һȪ�ۣ�ȪˮЯ����������ӿ��ƽ����ˮ�棻̶�ߺ�ɫ����ʯ�Ͻ�����
���ı�˪�������ݲ�����
LONG); 
        //{{ --- by MapMaker
        set("exits",([
        "east":__DIR__"waterpath",
        "southwest":__DIR__"weaponroom",
        ]) );
        //}}
        set("item_desc", ([
                "Ȫ��" : (: spring :),
                "spring" : (: spring :),
                "Ȫ" : (: spring :),
        ]));    
        set("indoors", "yinghe");
        setup();
} 
string spring(){
        object me;
        
        me = this_player();
        tell_object(me, "ȪˮЯ����������ӿ��ƽ����ˮ�棬�㲻�ɵ���һ̽�������������壩\n");
        add_action("do_dive", "dive");
        return "";
} 
int do_dive(){
        object *inv, obj, me;
        string att, temp_att;
        int i;
        me = this_player();
        att = me->query("attribute_mark");
   temp_att = me->query_temp("attribute_mark");
        inv = all_inventory(me);
        if(att == "water" || att == "earth"){
                diving(me);
                return 1;
        }
        if(att == "gold" || att == "wood") {
                for(i=0;i<sizeof(inv); i++){
                        if((inv[i]->query("attribute") == att && inv[i]->query("yinghe_weapon"))){
                                diving(me);
                                return 1;
                        }
                }
        }
        if(att == "fire") {
                if(temp_att == "water" || temp_att == "earth") {
                        diving(me);
                        return 1;
                }
                message("vision", me->name() + "������ǰ�ƶ������̶�פ�㲻ǰ��\n", environment(me), me);
                tell_object(me, HIR"�����ˮ��������û�����ʹ�ѵ���\n"NOR);
                me->receive_damage("kee", 100);
                return 1;
        } 
        message("vision", me->name() + "������ǰ�ƶ������̶�פ�㲻ǰ��\n", environment(me),me);
        tell_object(me, "�����ǵĳ���֮���������һ��פ�㲻ǰ��\n");
        return 1;
} 
void diving(object me){
        object room;
        
        room = find_object(__DIR__"watertunnel");
        message_vision(HIC"\n$N����Խ����̶����Ǳȥ��\n\n"NOR, me);
        if(!objectp(room)){
                room = load_object(__DIR__"watertunnel");
        }
        tell_object(me,"��Ȼ������ǰһ����\n\n");
        me->move(room);
        
}  
