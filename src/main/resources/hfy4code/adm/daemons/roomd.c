// roomd.c
#include <room.h>

string dir_chinese(string dir);
object get_neighbour(object where,string dir);
string room_direction(object where,string filename);
string anti_dir(string dir);

void create() { seteuid(getuid()); }

object get_neighbour(object where,string dir)
{
mapping direction;
int i,have_dir=0;
string *dire,filename;
object neighbour;
if(!direction=where->query("exits"))
	return 0;
dire=keys(direction);
for(i=0,have_dir=0;i<sizeof(dire);i++)
	{
	if(dire[i]==dir)
		{
		filename=direction[dire[i]];
		if(neighbour=find_object(filename));
			return neighbour;
		call_other(filename,"???");
		neighbour=find_object(dir);
		return neighbour;
		}
	}
}

string room_derection(object where,string filename)
{
mapping direction;
string	*dire,dir;
int i;
if(!direction=where->query("exits"))
	return NO_SUCH_DIRECTION;
dire=keys(direction);
for(i=0;i<sizeof(dire);i++)
	{
	if(filename==direction[dire[i]])
		return dire[i];
	}
return NO_SUCH_DIRECTION;
}
	
string dir_chinese(string dir)
{
switch(dir)
{
case	"east" : return "����" ;
case  	"west" : return "����" ;
case	"north" : return "����" ;
case	"south" : return "����" ;
case	"enter" : return "����" ;
case	"out" : return "����" ;
case	"southeast" : return "������";
case	"northwest" : return "������";
case	"southwest" : return "������";
case	"northeast" : return "������";
case	"northup"   : return "���Ϸ�";
case	"eastup"    : return "���Ϸ�";
case    "southup"   : return "���Ϸ�";
case 	"westup"    : return "���Ϸ�";
case	"up"        : return "����";
case	"down"	    : return "����";
case    "eastdown"  : return "���·�";
case    "westdown"  : return "���·�";
case    "southdown" : return "���·�";
case    "northdown" : return "���·�";
default :	return dir;
}
}

string anti_dir(string dir)
{
string dir1=dir;
if(dir=="east") return "west";
if(dir=="west") return "east";
if(dir=="south") return "north";
if(dir=="north") return "south";
if(dir=="up") return "down";
if(dir=="down") return "up";
if(dir=="northeast") return "southwest";
if(dir=="northwest") return "southeast";
if(dir=="southeast") return "northwest";
if(dir=="southwest") return "northeast";

return dir1;
}
