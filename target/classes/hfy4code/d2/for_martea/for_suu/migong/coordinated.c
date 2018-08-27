 //coordinated.c
//coordinate deamon, by cyz&&kitten@xeno 
/***********************************************
This daemon is created for system resource saving purpose.
The idea of having our mud's map mainly composed of outter
space. with coordinace(pity, only 2D, of course, 3D is to
be implemented the sameway, howerver, use up and down dir
to demonstrate the actual Y axis would look stupid.)
A map setting of (100*100) would require 10k standard rooms,
gee, that is some dumb labour work that we are not willing 
to do. Also, it would be a waste of system resource to have 
such simple room only to be walked in and refreshed in 
clean_up. Well, so this daemon is done so in hope such huge
empty area can be shown using as few rooms as possible. 
1. find coordinates to c if this room already exists.
2. if exits of room points to file itself, and the current
   room is composed of only you(reminds me of the dumb song),
   then just change the current room setting,
3. if not, find an empty room with the exact same file
   and move user there while setting room's cord.
4. everything else failed, new room created. (duh!)
***********************************************/
#include <ansi.h> 
inherit F_DBASE; 
mapping dirs = (["north" : ({0, 1}),
                 "south" : ({0,-1}),
                 "east"  : ({1, 0}),
                 "west"  : ({-1,0}),
                 "northeast" : ({1, 1}),
                 "southeast" : ({1,-1}),
                 "northwest" : ({-1,1}),
                 "southwest" : ({-1,-1}),]);
                 
mapping boundary = (["space"    :       50
                ]);
                 
void create()
{
        seteuid(getuid());
        set("name", "���꾫��");
        set("id", "coordinated");
} 
//for efun objects()'s use only
int inherits_room(object ob)
{
        return ob->is_room();
} 
//for efun filter_array's use only
int check_coord(object ob, string dim, int x, int y)
{
        mixed val, coord;
        if (!arrayp(val = ob->query("coordinate/"+dim)))
                return 0;
                
        coord = val + ({});
        return ((coord[0]==x) && (coord[1]==y));
} 
object find_coordinate(string dim, int x, int y)
{
        object *points;
        object *rooms = objects((:inherits_room:));
        
        points = filter_array(rooms, (:check_coord:), dim, x, y);
        if (!sizeof(points))    return 0;
        
        if (sizeof(points) > 1) //report error
        {
                CHANNEL_D->do_channel(this_object(), "sys", sprintf("�����ظ�: %s (%d, %d)", dim, x, y));
        }
        
        return points[0];
} 
object *points(string dim, int x, int y)
{
        object *rooms = objects((:inherits_room:));
        
        return filter_array(rooms, (:check_coord:), dim, x, y);
} 
int *calculate_coordinate(object prev_room, string dir, string dim)
{
   mixed val, coord;
        
        if (undefinedp(dirs[dir]))      return 0;
        
        if (!arrayp(val = prev_room->query("coordinate/"+dim)))
                return 0;
        
        coord = val + ({});
        coord[0] += dirs[dir][0];
        coord[1] += dirs[dir][1];
        
        if (!undefinedp(boundary[dim]))
        {
                //if (abs(coord[0]) > boundary[dim])
                        //coord[0] = - (coord[0] - dirs[dir][0]);
                
                //if (abs(coord[1]) > boundary[dim])
                        //coord[1] = - (coord[1] - dirs[dir][1]); 
                if (coord[0] > boundary[dim])
                        coord[0] = - (coord[0] - dirs[dir][0]);
                
                if (coord[1] > boundary[dim])
                        coord[1] = - (coord[1] - dirs[dir][1]);
        }       
        return coord;
} 
/********************************************************************
within coordinated, we still offer the option of not having an area
coordinated. As long as you dont want the rooms to be coordinated,
just dont set ("coordinate/xxx") in the create. ("coordinate/xxx")
can be either a setting [a,b], or just plain 1. In the case of 1, 
the room coordinate would be calculated from the center of the origin
of this destined area.
********************************************************************/ 
int update_coordinate(object prev_room, object this_room, string dir)
{
        mixed val, dims, found;
        int *coord;
        
        if (undefinedp(dirs[dir]))      return 0;
   if (!mapp(val = prev_room->query("coordinate")))        return 0;
        
        dims = keys(val);
        found = 0;
                
        for (int i = 0; i < sizeof(dims); i++)
        {
                if (arrayp(prev_room->query("coordinate/" + dims[i]))&& this_room->query("coordinate/" + dims[i]))
                {
                        this_room->set("coordinate/" + dims[i], calculate_coordinate(prev_room, dir, dims[i]));
                        found++;
                }               
        }
        
        return found;
} 
object find_dir(object prev_room, string dir)
{
        mixed val, dims, found;
        int *coord;
        
        if (undefinedp(dirs[dir]))      return 0;
        if (!mapp(val = prev_room->query("coordinate")))        return 0;
        
        dims = keys(val);
        found = 0;
        
        for (int i = 0; i < sizeof(dims); i++)
        {
                if (!arrayp(val = prev_room->query("coordinate/" + dims[i]))) continue;
                
                coord = calculate_coordinate(prev_room, dir, dims[i]);
                
                if (objectp(found = find_coordinate(dims[i], coord[0], coord[1]))) break;
        }
        
        return found;
} 
