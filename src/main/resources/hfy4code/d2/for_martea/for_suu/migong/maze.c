 // maze.c
// originated from space.c
// cyz&kitten@xeno 99.06.20
// related file /adm/daemons/coordinated 
// there are local go/look here, why? because we dont feel 
// like to change the std ones, yet.  
#define COORDINATE_D "/d/for_suu/coorninated"
inherit ROOM; 
mapping default_dirs = ([
        "north":                "��",
        "south":                "��",
        "east":                 "��",
        "west":                 "��"
        ]); 
// the following is a maintence friendly monster list, if
// modifications on enemy/rate of appearing/number etc needs
// change, just alter the following mapping. 
/************************************************************
file_name == path of the file
chance    == any int from 1 - 100, as in percentage
amount    == amount of enemy will appear at once
dim       == which dimension should it appear.
coordinate/range
          == range of which enemy has chance to appear, c
             coordinate is the center, range is the radius
************************************************************/ 
mapping *monsters = ({
        ([      "file_name"     :       "/d/fy/npc/waiter.c",
                "chance"        :       25,
                "amount"        :       2,
                "dim"           :       "maze",
                "coordinate"    :       ({0,0}),
                "range"         :       2
        ]),
        ([      "file_name"     :       "/d/fy/npc/zhu.c",
                "chance"        :       50,
                "amount"        :       1,
                "dim"           :       "maze",
                "coordinate"    :       ({0,0}),
                "range"         :       2
        ]),
           
        ([      "file_name"     :       "/d/fy/npc/mei.c",
                "chance"        :       30,
                "amount"        :       2,
                "dim"           :       "maze",
                "coordinate"    :       ({4,4}),
                "range"         :       1
        ]),
        ([      "file_name"     :       "/d/fy/npc/song.c",
                "chance"        :       70,
                "amount"        :       4,
                "dim"           :       "maze",
                "coordinate"    :       ({-4,-4}),
                "range"         :       1
        ])
}); 
void create()
{
        set("short", "��̫��");
        set("long", "����޼ʵ���̫�գ����������صȴ���ȥ̽����\n");
        
        set("exits", ([
                "north" : __FILE__ ,
                "south" : __FILE__ ,
                "east"  : __FILE__ ,
                "west"  : __FILE__ ,
                "out"   : __DIR__"shandao",
                ]) );
        
        set("coordinate/maze", 1);
                
        setup();
} 
void setup()
{
        seteuid(getuid());
} 
void init()
{
        add_action("do_go", "go");
   add_action("do_look", "look");  
} 
int is_here(mapping monster, string dim, int x, int y)
{
        int diff_x = monster["coordinate"][0] - x;
        int diff_y = monster["coordinate"][1] - y;
        
        //return (monster["dim"] == dim) && (abs(diff_x) <= monster["range"]) && (abs(diff_y) <= monster["range"]);
        return (monster["dim"] == dim) && (diff_x <= monster["range"]) && (diff_y <= monster["range"]);
} 
void reset()
{ 
        int i, j;
        //int x = query("coordinate/maze")[0];
        //int y = query("coordinate/maze")[1];
        
        
        int x , y = 1;
        object *objs = all_inventory(this_object()), *mons = ({});
        object ob;
        mapping *mon_list = filter_array(monsters, (:is_here:),"maze", x, y);
        
        for(i = 0; i < sizeof(objs); i++)
        {
                if (!userp(objs[i]))    destruct(objs[i]);
        }
        
        
        // ����ʽս��ϵͳ�� originated from traditional RPG battle
        
        for(i = 0; i < sizeof(mon_list); i++)
        {
                if ((random(3)) && (random(100) < mon_list[i]["chance"]))
                {
                        for (j = 0; j < mon_list[i]["amount"]; j++)
                        {
                                ob = make_inventory(mon_list[i]["file_name"]);
                                mons += ({ob});         
                                delete("exists");
                                set("exits", ([
                                   "out" : __DIR__"muwu"
                                        ]));
                                set("in_battle", 1);
                        }
                }
        }
        
        
        
        set_temp("objects", mons);
} 
int do_go(string arg)
{
        string dest, mout, min, dir, *tmp_dir;
        object env, obj, *rooms, tmp_obj, me = this_player();
        mapping exit, tmp_exit;
        int *coord;
        mixed val; 
        if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n"); 
        if( me->over_encumbranced() )
                return notify_fail("��ĸ��ɹ��أ��������á�\n"); 
        if( me->is_busy() )
                return notify_fail("��Ķ�����û����ɣ������ƶ���\n"); 
        env = environment(me);
        if(!env) return notify_fail("������Ҳȥ���ˡ�\n"); 
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                if( query_verb()=="go")
                        return notify_fail("�������û�г�·��\n");
                else
                        return 0;
        } 
        dest = exit[arg];
        
        if (!objectp(obj = COORDINATE_D->find_dir(env, arg)))
        {       
                //search for an unoccupied room
                rooms = children(dest);
                for (int i = 0; i < sizeof(rooms); i++)
                {
                        if ((!(rooms[i]->usr_in())) && (!rooms[i]->query_temp("occupied")) && 
                           (clonep(rooms[i])))
                        {
                                obj = rooms[i];
                                break;
                        }
                }
                
                //always use cloned maze object
                if (!objectp(obj))
                        obj = new(dest);
                
        
                if( !objectp(obj) )
                {
                        write("�޷��ƶ���\n");
                        return 1;
                }
                
                COORDINATE_D->update_coordinate(env, obj, arg); 
        }
        
        if ((!obj->usr_in()) && (!obj->query_temp("occupied")))
                obj->reset();
        
        if( !env->valid_leave(me, arg) ) return 0; 
        if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg; 
        if( me->is_fighting() ) {
                mout = "��" + dir + "��Ķ����ˡ�\n";
                min = "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
        } else {
                mout = "��" + dir + "�뿪��\n";
                min = "���˹�����\n";
        }
        
        //cant enter a room if some1 is fighting there
        if (obj->query("in_battle") && obj->usr_in())
        { 
           write ("���˶�ס��ͨ��" + dir + "�ĳ��ڣ������������ڽ���һ����ս���ȵȵȰա�\n");
                return 1;
        } 
        message( "vision", me->name() + mout, environment(me), ({me}) );
        if( me->move(obj) ) {
                me->remove_all_enemy();
                message( "vision", me->name() + min, environment(me), ({me}) );
                me->set_temp("pending", 0);
                all_inventory(env)->follow_me(me, arg);
                
                //if the room is empty, remove all occupied flag
                if ((!env->usr_in()) && (mapp(tmp_exit = env->query_temp("exits"))))
                {
                        tmp_dir = keys(tmp_exit);
                        for (int i = 0; i < sizeof(tmp_dir); i++)
                        {
                                if (objectp(tmp_obj = tmp_exit[tmp_dir[i]]) && (tmp_obj->query_temp("occupied")))
                                {
                                        tmp_obj->delete_temp("occupied");
                                        env->delete_temp("exits/" + tmp_dir[i]);
                                }
                        }
                }
                
                //if user left an empty room, destruct it
                if ((!env->usr_in()) && (!env->query_temp("occupied")) && (env!=obj))
                        destruct(env);
                
                return 1;
        } 
        return 0;
} 
int do_look(string arg)
{
        mapping exits;
        object obj, *rooms, env = this_object();
        string dest;
        
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) 
        {
           if (!objectp(obj = COORDINATE_D->find_dir(env, arg)))
                {
                        
                        dest = exits[arg];      
                        //search for an empty room
                        rooms = children(dest);
                        for (int i = 0; i < sizeof(rooms); i++)
                        {
                                CHANNEL_D->do_sys_channel("sys",sprintf("room %s",base_name(rooms[i])));
                                if ((!(rooms[i]->usr_in())) && (!rooms[i]->query_temp("occupied")) && 
                                        (clonep(rooms[i])))
                                {
                                        obj = rooms[i];
                                        break;
                                }
                        }
                
                        //always use cloned maze object
                        if (!objectp(obj))
                                obj = new(dest);
                        
                        if( !objectp(obj) )
                                return notify_fail("cant find room��\n");
                
                        COORDINATE_D->update_coordinate(env, obj, arg);
                }
        
                if ((!obj->usr_in()) && (!obj->query_temp("occupied")))
                {
                        obj->reset();
                        obj->set_temp("occupied", 1);
                        env->set_temp("exits/" + arg, obj);
                }
                
                return call_other("/cmds/std/look.c", ({"look_room", this_player(), obj}));
        }
        return 0;
} 
int valid_leave(object me, string dir)
{
   if (dir == "out")
                me->delete_temp("in_maze");
        return ::valid_leave(me, dir);
}      
