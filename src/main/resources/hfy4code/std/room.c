 // room.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//  
//      11/10/2002      removed room_item_force_refresh to save system load, only 5-6 rooms use that one.
//      11/13/2002      remove return_home to simplify code.
//                      -- by silencer@fy4 workgroup 
//#pragma save_binary 
#include <dbase.h>
#include <room.h> 
inherit F_DBASE;
inherit F_CLEAN_UP; 
static mapping doors; 
void create() {
        if(clonep(this_object())) {
                destruct(this_object());
                return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
        }
} 
int query_max_encumbrance() { 
        return 100000000000; 
} 
object make_inventory(string file) {
        object ob;
        
        ob = new(file);
        if(objectp(ob)) {
                ob->move(this_object());
                ob->set("startroom", base_name(this_object()));
        }
        return ob;
} 
void reset() {
        mapping ob_list, ob;
        string *list;
        int i,j;
        object *inv;
        
    // I put this one here to get rid the function of trash collecting...Tie
    // since the quest feature, rooms hardly get swarpped out.
        inv = all_inventory();
        for(i=sizeof(inv)-1; i>=0; i--) {
                if(!inv[i]->is_character() 
                                && inv[i]->query("startroom") !=base_name(this_object()) 
                                && !inv[i]->query("no_reset")) {
                        destruct(inv[i]);
                }
        } 
        //
        // Check loaded objects to match the objects specified in "objects"
        // while query("objects") is 
        // ([ <object filename>: <amount>, ..... ])
        // and query_temp("objects") is
        // ([ <object filename>: ({ob1, ob2, ...}), .... ])
        //
        set("no_clean_up", 0);
        ob_list = query("objects");
        if(!mapp(ob_list)) {
                return;
        }
        if(!mapp(ob = query_temp("objects"))) {
                ob = allocate_mapping(sizeof(ob_list));
        }
        
        list = keys(ob_list);
        for(i=0; i<sizeof(list); i++) {
                // Allocate an array if we have multiple same object specified.
                if(undefinedp(ob[list[i]]) && intp(ob_list[list[i]]) && ob_list[list[i]] > 1) {
                        ob[list[i]] = allocate(ob_list[list[i]]);
                }
                switch(ob_list[list[i]]) {
                        case 1:
//  �����Ѿ�����Ϸ����ʧ�������
                                if(!ob[list[i]]) {
                                        ob[list[i]] = make_inventory(list[i]);
                                        continue;
                                } 
/* ǿ����������Ϸ����Ȼ���ڵ������--- ʹ�÷ǳ����ޣ��Ƶ��ض���room�ļ� Silencer��                               
                                else if (  query("refresh_all_items") &&  environment(ob[list[i]]) != this_object() ) {
                                   ob[list[i]] = make_inventory(list[i]);
                                        continue;
                                }                                       */
                                
// ����NPC�ع�����أ�һ��ֻ������NPC��Ҫ��
// random_move�����ļ� std/char/npc ����.
// pursurer �Ĳ��࣬�� includeһ��std/char/pursurer.c������--- Silencer                               
/*                              if(environment(ob[list[i]]) != this_object() 
                                                && ob[list[i]]->is_character()) {
                                        if(!ob[list[i]]->return_home(this_object())) {
                                                add("no_clean_up", 1);
                                        }
                                }*/
                                break;
                        default:
                                for(j=0; j<ob_list[list[i]]; j++) {
                                        // If the object is gone, make another one.
                                        if( !objectp(ob[list[i]][j]) ) {
                                                ob[list[i]][j] = make_inventory(list[i]);
                                                continue;
                                        }
/*-> Added by neon to refresh items in room ground
                                        else if ( query("refresh_all_items") &&  environment(ob[list[i]][j]) != this_object() ) {
                                                ob[list[i]][j] = make_inventory(list[i]);
                                                continue;
                                        }
<- End of refreshing items                                      */
                                        // Try to call the wandering npc come back here.
/*                                      if(environment(ob[list[i]][j]) != this_object()
                                                        && ob[list[i]][j]->is_character()){
                                                if(!ob[list[i]][j]->return_home(this_object())){
                                                        add("no_clean_up", 1);
                                                }
                                        }*/
                                }
                                break;
                }
        }
        set_temp("objects", ob);
} 
// Redirect item_desc of the door to this function in default.
string look_door(string dir)
{
    if( !mapp(doors) || undefinedp(doors[dir]) )
        return "��Ҫ��ʲ�᣿\n";
    if( doors[dir]["status"] & DOOR_CLOSED )
        return "���" + doors[dir]["name"] + "�ǹ����ġ�\n";
    else
        return "���" + doors[dir]["name"] + "�ǿ����ġ�\n";
}  
varargs int open_door(string dir, int from_other_side)
{
    mapping exits;
    object ob; 
    if( !mapp(doors) || undefinedp(doors[dir]) )
        return notify_fail("�������û���š�\n"); 
    if( !(doors[dir]["status"] & DOOR_CLOSED) )
        return notify_fail( doors[dir]["name"] + "�Ѿ��ǿ������ˡ�\n"); 
    exits = query("exits");
    if( !mapp(exits) || undefinedp(exits[dir]) )
        error("Room: open_door: attempt to open a door with out an exit.\n"); 
    if( from_other_side )
        message("vision", "���˴���һ�߽�" + doors[dir]["name"] + "���ˡ�\n",
                this_object());
    else if( objectp(ob = find_object(exits[dir])) ) {
        if( !ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;
    } 
    doors[dir]["status"] &= (!DOOR_CLOSED);
    return 1;
} 
varargs int close_door(string dir, int from_other_side)
{
    mapping exits;
    object ob; 
    if( !mapp(doors) || undefinedp(doors[dir]) )
        return notify_fail("�������û���š�\n"); 
    if( (doors[dir]["status"] & DOOR_CLOSED) )
        return notify_fail( doors[dir]["name"] + "�Ѿ��ǹ������ˡ�\n"); 
    exits = query("exits");
    if( !mapp(exits) || undefinedp(exits[dir]) )
        error("Room: close_door: attempt to open a door with out an exit.\n"); 
    if( from_other_side )
        message("vision", "���˴���һ�߽�" + doors[dir]["name"] + "�����ˡ�\n",
                this_object());
    else if( objectp(ob = find_object(exits[dir])) ) {
        if( !ob->close_door(doors[dir]["other_side_dir"], 1) ) return 0;
    } 
    doors[dir]["status"] |= DOOR_CLOSED;
    return 1;
}  
int check_door(string dir, mapping door)
{
    // If we have no responding door, assume it is correct.
    if( !mapp(doors) || undefinedp(doors[dir]) ) return 1; 
    door["status"] = doors[dir]["status"];
    return 1;
} 
/*
int check_door(string dir)
{
    // If we have no responding door, assume it is correct.
    if( !mapp(doors) || undefinedp(doors[dir]) ) return 1;
    return doors[dir]["status"];
}
*/ 
varargs void create_door(string dir, mixed data,
                         string other_side_dir, int status)
{
    mapping d, exits, item_desc;
    object ob; 
    exits = query("exits");
    if( !mapp(exits) || undefinedp(exits[dir]) )
        error("Room: create_door: attempt to create a door without exit.\n"); 
    // Compact mode.
    if( stringp(data) )
    {
        d = allocate_mapping(4);
        d["name"] = data;
        d["id"] = ({ dir, data, "door" });
        d["other_side_dir"] = other_side_dir;
        d["status"] = status;
    }
    else if( mapp(data) )
        d = data;
    else
        error("Create_door: Invalid door data, string or mapping expected.\n"); 
    set("item_desc/" + dir, (: look_door, dir :) ); 
    if( objectp(ob = find_object(exits[dir])) )
    {
        if( !ob->check_door(other_side_dir, d) )
            return;
    } 
    if( !mapp(doors) ) doors = ([ dir: d ]);
    else doors[dir] = d;
} 
mapping query_doors() { return doors; } 
mixed query_door(string dir, string prop)
{
    if( !mapp(doors) || undefinedp(doors[dir]) ) return 0;
    else return doors[dir][prop];
} 
int valid_leave(object me, string dir)
{
    if( mapp(doors) && !undefinedp(doors[dir]) ) {
        if( doors[dir]["status"] & DOOR_CLOSED )
            return notify_fail("������Ȱ�" + doors[dir]["name"] + "�򿪣�\n");
        // if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
    }
    return 1;
} 
void setup()
{
    seteuid(getuid());
    this_object()->reset();
} 
string long() {
        string str;
        
        if(NATURE_D->is_day_time()) {
                str = query("long_day");
   } else {
                str = query("long_night");
        }
        if(!stringp(str)) {
                str = query("long");
                if(!stringp(str)) {
                        str = query("short") + "��\n";
                }
        } 
        return str;
}
