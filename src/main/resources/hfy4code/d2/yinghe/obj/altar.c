 // Copyright (C) 2002, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "��̨", ({ "shentai", "shen tai", "��̨"  }) );
        set("unit", "��");
        set("no_get",1);
        set("no_shown", 1);
        set("value",20);
        set("long","
��ʯӢ��̨����̨������һ������������壩�������ֱַ��԰ף��������壩��
�죨���䣩���ƣ��������������ڣ������룩��ɫ����Ƕ���ɡ�
��ɰ��ο��ԷŶ�����
\n");
        set_weight(5000);
        ::init_item();
}
void init()
{
        add_action("do_turn","turn");
}  
int open_path(object me) {
    object room; 
    message("vision", "˲����ʯ��ð����ʣ�һ����ʹ�������"+me->name()+"��ʧȥ����Ӱ��\n", environment(me), me);
    tell_object(me, "��Ȼ������ǰ��һƬ��ʹ�â����ֻ��������������׹ȥ��\n\n");
    room = find_object("/d/yinghe/weaponroom");
    if(!objectp(room)){
        room = load_object("/d/yinghe/weaponroom");
    }
    me->move(room);
    tell_object(me, "��ǰ��â��ʧ�����������촦��\n");
    return 1;
} 
int check_jade(object me){
        object red, white, yellow, black, env, *inv;
        object red_jade, yellow_jade, white_jade, black_jade; 
        env = environment(this_object());
   if(!objectp(red=present("red", env))) return 0;
        if(!objectp(white=present("white", env))) return 0;
        if(!objectp(black=present("black", env))) return 0;
        if(!objectp(yellow=present("yellow", env))) return 0;
        inv = all_inventory(red);
        if( sizeof(inv) != 1) return 0;
        red_jade = inv[0];
        if((string)red_jade->query("name") != HIR"���ľ۱�"NOR) return 0;
    inv = all_inventory(white);
    if( sizeof(inv) != 1) return 0;
    white_jade = inv[0];
    if((string)white_jade->query("name") != HIW"����֬��"NOR) return 0;
    inv = all_inventory(black);
    if( sizeof(inv) != 1) return 0;
    black_jade = inv[0];
    if((string)black_jade->query("name") != BLU"����ī��"NOR) return 0;
    inv = all_inventory(yellow);
    if( sizeof(inv) != 1) return 0;
    yellow_jade= inv[0];
    if((string)yellow_jade->query("name") != HIY"����ʯ��"NOR) return 0;
// now we have everything, let's open path! and reset this room;
        red_jade->move(env); destruct(red_jade);
    yellow_jade->move(env); destruct(yellow_jade);
    white_jade->move(env); destruct(white_jade);
    black_jade->move(env); destruct(black_jade);
        open_path(me);
        return 1;
}
int do_turn(string arg)
{
    object me,env;
    if( !arg ) return 0;
    if( arg != "������" && arg != "jade") return 0;
    me = this_player();
    if((int) me->query("mana") < 500) {
            write("��ķ���������\n"); return 1;}
        if(((int) me->query("force") >= 100) && me->query_temp("yinghe_marks/altar")) {
                me->add("force",-100);
                open_path(me);
                return 1;
    }
    me->add("force",-50);
    message_vision("$N�þ�����ת����������\n", me);
    if( check_jade(me) ) {
            if(!me->query("m_success/��ɫ����̳")){
                me->set("m_success/��ɫ����̳",1);
                me->add("score",300);
                me->add("combat_exp", 2000);
                me->add("potential", 2000);
                }
                if(!me->query_temp("yinghe_marks/altar")){
                        me->set_temp("yinghe_marks/altar",1);
                }
                open_path(me);
        } else {
                message_vision("��$N��������ʱ����̨��΢΢ð����ʹ�â��˲���ʧ����\n",me);
    }
    return 1;
}       
