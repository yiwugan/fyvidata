#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int extradam;
        if(me->query("class")!="wolfmount")
                return notify_fail("只有狼山弟子才能使出「离魂术」。\n");
       
        if((int)me->query_skill("cursism") < 200 )
                return notify_fail("你的降头术不够高！\n"); 
        if((int)me->query("kee") < 1000 )
                return notify_fail("你的气血不够！\n");
                 write("你想使谁离魂？");
                 input_to( (: call_other, __FILE__, "select_target", me :));
                 return 1;
        
} 
void select_target(object me, string name)
{
        mapping ob_list;
        object ob,new1;
        string msg;
        object room,corpse;
        string *list;
        object *inv;
        int i,level;
        if( !name || name=="" ) {
                write("\n中止施法。\n");
                return;
        } 
        ob = find_living(name);
        room = environment(me);
        if( !ob  || !present(ob, room)){
                write("\n有这个人吗？\n");
                return; 
        }       
        if(ob->is_ghost() || ob->is_corpse())           {
                write("\n你只能对活物下这个降头。\n");
           return;
        }
        if (!userp(ob)){
                write("\n你只能对玩家下这个降头.\n");
                return;
        }
        me->receive_wound("kee",1000);
        if (ob!=me) msg = HIB "\n$N对$n悲声低吟：生亦何欢。。死亦何苦。。莫若归去。。。\n\n" ;
                else msg = HIB "\n$N悲声低吟：生亦何欢。。死亦何苦。。莫若归去。。。\n\n" ;
        
        me->start_busy(2);
        level = (int) me->query_skill("cursism");
        if( random(level)>level/2) 
                { 
                if (ob!=me){
                msg +=  "$n忽然倒了下来，头上冒出一阵浓雾，浓缩成一个黑影，但很快就消失了。\n" NOR;
                message_vision(msg, me,ob);
                }       else {
                msg +=  "$N忽然倒了下来，头上冒出一阵浓雾，浓缩成一个黑影，但很快就消失了。\n" NOR;
                message_vision(msg, me);
                } 
                if(objectp(corpse = CHAR_D->make_corpse(ob, me)))
                        corpse->move(room);
                ob->be_ghost(1);
                ob->move("/d/death/gate");
                return;
                }
        else
        msg += "结果什么也没有发生\n"NOR;
        if (ob !=me) message_vision(msg, me,ob);
                else message_vision (msg,me);
        
}        
