 // FYTeam
#include <ansi.h>
inherit ROOM;
string sand();
int monster_attack(object me);
void create(){
        set("short", "��ɳ��");
        set("long", @LONG
ͻأ����ǰð��һƬ��ɳ��������ɳ����һ��ɫ�����۵Ľ��ɫ���������
�����뵽��ɫ�Ľ��ӡ���ϸ�������ܵ�ɳ����֪�������������ڻ�����ǰ�ƶ���
�������γ���һ����ɳ����
LONG); 
        set("exits",([
                "east":__DIR__"yellow_earth",
        ]) );
        set("item_desc", ([
                "sand" : (: sand :),
                "��ɳ��" : (: sand :),
                "sandtower" : (: sand :),
        ]));
        set("helsand", 1);
        set("indoors", "yinghe");
        setup();
} 
string sand(){
        object me;
        
        me = this_player();
        if(query("helsand")){
                tell_object(me, "��ɳ���Ķ�������һ���ɫ��ɳ�ӡ�������������䣩\n");
                add_action("do_get", "get");
        } else {
                tell_object(me, "��ɳ�������ŷ��ҵĽ�ӡ��\n");
        }
        return "";
} 
int do_get(string arg){
        object me, sand;
        me = this_player();
        if(arg == "sand"){
           if(query("monster_traped")) {
                        message_vision("$N�������ƽ���ɳ��������������һ���ɫ��ɳ�ӡ�\n", me);
                        sand = new(__DIR__"obj/sand");
                        if(objectp(sand)){
                                sand->move(me);
                        }
                        delete("helsand");
                        return 1;
                } else {
                        message_vision("$N�������ɳ����ȥ��\n", me);
                        me->start_busy(1);
                        monster_attack(me);
                        return 1;
                }
        }
        return 0;
} 
int monster_attack(object me){
        object monster, cage;
        
        cage = present("wood cage", this_object());
        if(objectp(monster = present("sand guardian", this_object()))) {
                if(objectp(cage)) {
                        message_vision("$N�Ʋ�����$n����Ȼ��$N�������䣬���������������Ұ�޵ĵͺ�\n", monster, me);
                        set("monster_traped", 1);
                        return 1;
                }
                monster->kill_ob(me);
                return 1;
        }
        message_vision(HIY"\n��Ȼ�䣬��ɳ�������ӵ��������һֻ��������$N��ǰ��\n"NOR, me);
        monster = new(__DIR__"npc/sand_guard");
        if(objectp(monster)){
                monster->move(this_object());
        }
        if(objectp(cage) && cage->query("installed")) {
                message_vision("$N�Ʋ�����$n����Ȼ��$N�������䣬���������������Ұ�޵ĵͺ�\n", monster, me);
                destruct(monster);
                set("monster_traped", 1);
                return 0;
   }
        monster->kill_ob(me);
        return 1;
} 
void reset(){
        ::reset();
        set("helsand", 1);
}       
