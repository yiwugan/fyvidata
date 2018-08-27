 // Room: fountain.c --- by MapMaker
#include <ansi.h>
inherit ROOM; 
string fountain();
void create()
{
        set("short", "ӫˮ��Ȫ"); 
        set("long", @LONG
���������ϵ�ӫ����ȵصĳ������ĵط������������½��ᣬ��ˮȴ����
���ҡ�����ͬ��һ����ľ����ϣ�����һ��˿�����뾵�е�Ӱ�������ƽƽ��
���������һ��һ�������Ȫ����ȻȻ����ӿ��Ө���ˮ����һ�а�Χ��һ
���ľ����ɵ�ƽ���С�
LONG); 
        //{{ --- by MapMaker
        set("exits",([
        "southeast":__DIR__"stonecave",
        "southwest":__DIR__"riverroad1",
        ]) );
        //}}
        set("item_desc", ([
                "fountain" : (: fountain :),
                "��Ȫ" : (: fountain :),
        ]));
        set("balanced", 1);
        set("indoors", "linghe");
        setup();
} 
string fountain(){
        object me;
        me = this_player();
        if(query("balanced")){
                tell_object(me, "һ�������Ȫ����ȻȻ����ӿ��Ө���ˮ��ˮ�������羵����ˮ���ϲ�����һ��
���������㲻�ɵ��붪������ȥ������Ρ������������\n");
                add_action("do_throw", "throw");
        } else {
                tell_object(me, "�����Ȫ΢б��Ȫˮ��Ȼ�ɺԡ�\n");
        }
        return "";
} 
int do_throw(string arg){
    object me;
    object tar; 
    me = this_player();
    if( !arg || arg == "") 
            return notify_fail("��Ҫ��ʲô������\n");
    tar = present(arg, me);
    if( !tar) 
            return notify_fail("������û���ⶫ����\n");
    if( userp(tar))
            return notify_fail("�㲻�ɶ���Ķ�����\n");
    if( tar->query("owner"))
            return notify_fail("�㲻�ɶ����Ķ�����\n");
    if (tar->query("no_drop"))
            return notify_fail("�����������ܶ���\n");
        if(tar->query("id") == "hel sand"){
                message_vision("$N�������еĺ�ɳ����ɳ����Ʈ����Ө���ˮ���ϡ���\n", me);
            tar->move(environment(me));
                destruct(tar);
                call_out("flash", 1, me);
                return 1;
        }
    message_vision("$N��$nͶ����ӫˮ��Ȫ��ˮ��ʼ��ƽ���羵��\n", me, tar);
    tar->move(environment(me));
    destruct(tar);
    return 1;
} 
int flash(object me){
        object *inv, room;
        int i;
        
        message_vision(HIC"\nֻ������¡¡����������Ȫ��б����ˮ��������Ұ�����˹�����\n\n"NOR, me);
        room = find_object("d/fy/fysquare");
    if(!objectp(room)) {
        room=load_object("d/fy/fysquare");
    }
        delete("balanced");
        set("long", @LONG
���������ϵ�ӫ����ȵصĳ������ĵط������������½��ᣬԭ��Ӧ��ƽ
���羵�ĺ�ˮ�ϴ�ʱȴ������ӿ��ӫ��Я����ǧ������֮��ע��ȵصĳ��ӣ�һ
����Ȼ�ɺ��˵������Ȫ΢΢��б��
LONG);
    inv = all_inventory(this_object());
    for(i=0; i<sizeof(inv); i++) {
        if(userp(inv[i])){
                inv[i]->move(room);
        } else {
                destruct(inv[i]);
        }
    }
        return 1;
} 
void reset(){
        set("long", @LONG
���������ϵ�ӫ����ȵصĳ������ĵط������������½��ᣬ��ˮȴ����
���ҡ�����ͬ��һ����ľ����ϣ�����һ��˿�����뾵�е�Ӱ�������ƽƽ��
���������һ��һ�������Ȫ����ȻȻ����ӿ��Ө���ˮ����һ�а�Χ��һ
���ľ����ɵ�ƽ���С�
LONG);
        set("balanced", 1);     
}     
