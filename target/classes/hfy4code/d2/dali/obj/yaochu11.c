#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("采药锄", ({ "yaochu" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "wood");
                set("long", "一个专门用来采药的采药锄，你似乎可以用它来挖(wa)些药材(yaocai)。\n");
                set("weapon_prop/karma",1);
        }
        ::init_hammer(5);
        
}
void init()
{
        if(environment(this_object())==this_player())
        if (!wizardp(this_player())) {
        set("no_get"," 还是不要乱动大理的东西为好! \n");
        set("no_drop","大理的东西怎么能随便乱丢呢! \n");
        set("no_give","大理的东西怎么能随便给人呢！\n");
       }
        add_action("do_read","wa");
        add_action("do_go","go");
}

int do_read(string arg)
{
object me;
mapping exits;
string *dirs;
string thisdir;
if(arg != "yaocai" && arg != "药材") return 0;
me=this_player();
if(find_call_out("markit")== -1)
call_out("markit",random(2)+1,me);
if( !mapp(exits = environment(me)->query("exits")) ) 
{
tell_object(me,"凭直觉，你觉得周围附近的土里一定有名贵的药材！\n");
//set("already",1);
return 1;
}
        dirs = keys(exits);
        thisdir = dirs[random(sizeof(dirs))];
        set("thisdir",thisdir);
        tell_object(me,"你胡乱地挖几锄头，累得满头大汗，但什么也没找到，
你或许可以去"+thisdir+"的方向碰碰运气！\n");
         me->add("sen",-(random(50)+20));
         me->add("kee",-(random(50)+20));
         me->add("gin",-(random(50)+20));


        return 1;
}

int do_go(string arg)
{
        if(arg==query("thisdir"))
        this_player()->add_temp("going",1);
        return 0;
}
int markit(object me)
{
object yaocai;
//if(me->query_temp("going") <= 20) return 1;
//if(me->query_temp("going") <= 20 || environment()!=me) return 1;
//if(!query("already"))
{
yaocai = new("/questnew/yaocai");
tell_object(me,"\n\n你的药锄象是碰到了些什么，这东西看上去象是药材，你毫不犹豫地把它揣在怀里！\n");
//gold->set_amount(10);
yaocai->move(me);
me->delete_temp("going");
//set("already",1);
}
return 1;
}