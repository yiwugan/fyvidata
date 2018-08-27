// allsave.c
// by abandon

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
 	object *usr ;
 	int i;
	usr = users();

	for(i=0; i<sizeof(usr); i++)
	{
		if( !environment(usr[i]) ) continue;
		if( userp(usr[i]) )
		usr[i]->save();
        	
	}
	write(HIW"所有人的档案都已经被成功储存了！\n"NOR);
	return 1;
}