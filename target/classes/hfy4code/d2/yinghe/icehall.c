 // FYTeam
#include <ansi.h>
inherit ROOM; 
void create(){
        set("short", "��������");
        set("long", @LONG
����һ�����εĳǱ������ܸߴ��ǽ��͸����һ��΢�������صĹ�â�����Ĺ�
û�и���˿�������ĸо������������޾����İ�����š����ﺮ���絶�罣�����
���˼���ѪҺ���̡�
LONG); 
        set("objects", ([
                __DIR__"npc/water_guard" : 1,
        ]));
        set("exits",([
        "south":__DIR__"center",
        "north":__DIR__"mudpath",
        ]) ); 
        set("indoors", "yinghe");
        setup();
} 
void init(){
        object me, *inv;
        int i;
        me = this_player();
        if(userp(me)){
                inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++){
                if(inv[i]->query("bigcloth") && inv[i]->query("equipped") == "worn"){
                        message_vision(HIW "\n�Ǳ��д���ɭɭ���������ã�$N�а��þ�װ��ů��\n\n"NOR, me);
                        return;
                } else {
                        message_vision(HIW "\n�Ǳ��д���ɭɭ����͸��$N���塣\n\n"NOR, me);
                        call_out("frozen", 120, me);
                        return;
                        }
        } 
        }
} 
void frozen(object me){
        if(!interactive(me) || environment(me) != this_object()){
           return;
        }
        message_vision(HIW "\n��������Ȼ����$N�����壬$Nֻ������֫���ԣ���Ȼ�������á�\n\n"NOR, me);
        me->set_temp("disable_inputs",1);
        me->set("disable_type",HIW "<������>"NOR);
    me->set_temp("is_unconcious",1);
        call_out("remove_frozen", 10, me);
        return;
} 
void remove_frozen(object me){
    me->delete("disable_type");
    me->delete_temp("disable_inputs");
    me->delete_temp("is_unconcious");
    if(!me->is_ghost())
    message_vision(HIR "\n$Nǿ���������忪�����֫���������������\n\n"NOR, me);
        call_out("frozen", 60, me);     
} 
int valid_leave(object ob, string dir){
        object guard;
        guard = present("water guard", this_object());
        if(dir == "north" && objectp(guard)){
                return notify_fail("����Ԫ��Ц����������������˵������˵�߾��ߵĵط�����\n");
        }
        if(dir == "south" && ob->query("attribute/mark") != "water" && objectp(guard)){
                return notify_fail("����Ԫ����һ����������������˵������˵�߾��ߵĵط�����\n");
        }
        return 1;
}
