 // drift_sense.c
#include <ansi.h> 
inherit SSERVER; 
int conjure(object me, object target)
{
//      if (me->query("class")!="ninja")
//              return notify_fail("ֻ�����߲���������.\n");
                
//      if((int) me->query_skill("ninjitsu",1) < 150)
//                return notify_fail("��������������\n");
        if(environment(me)->query("no_death_penalty"))
                return notify_fail("���޷�������ʹ�÷��ڡ�\n");
        if( me->query_temp("ninjitsu_dart"))
                return notify_fail("�����ھѻ�֮�У����ɷ��ġ���\n");
        if( me->query("atman") < 200 )
                return notify_fail("�������������\n");
         if( me->query("gin") <= 100 )
                return notify_fail("��ľ�������\n"); 
        write("��Ҫ��ɱ˭��");
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
} 
void select_target(object me, string name)
{
        object ob,room,here;
        int lvl,extra,delay,dis,x,y,z;
        int my_exp, your_exp, your_perp, my_skill;
        
        if( !name || name=="" ) {
                write("��ֹ�ѻ���\n");
                return;
        } 
        ob = find_player(name);
        if( !ob || !me->visible(ob) || wizardp(ob) )
                ob = find_living(name);
        if ( !ob) 
                {
                tell_object(me,"��Ҫ�ѻ��Ķ��󲻴��ڡ�\n");
                return;
                }
   if( me->query("atman") < 200 ) {
                write("�������������\n");
                return;
        } 
        my_exp=me->query("combat_exp");
        your_exp=ob->query("combat_exp");
        
        if ( my_exp>your_exp*5) {
                tell_object (me,"�Ը���ô��Ķ����ð�ɱ̫ʧ�������!\n");
                return;
        }
        me->add("atman", -200);
        me->receive_damage("gin", 100);
        
        lvl=me->query_skill("magic");
        extra=lvl*lvl/460*lvl/100;
        if (me->query("class")=="shaolin")  extra = extra *5/2;
        extra=extra+random(extra);
        delay=50-lvl/10;
        if(delay<0) delay=0;
        if (delay>10) delay=10;
        delay=delay+random(delay);
        
    message_vision( HIY "$N��Ŀ�����ƺ��ڼ�����ʲô����\n" NOR, me);
        room=environment(ob);
        if(!room||room->query("no_magic")||room->query("no_fight")) 
        {       
                tell_object(me,HIB"���޷�ȷ�����˵�λ�á�\n"NOR);
                return;
        }
                
        here=environment(me);
        x=room->query("coor/x")-here->query("coor/x");
        y=room->query("coor/y")-here->query("coor/y");
        z=room->query("coor/z")-here->query("coor/z");
        dis=x*x+y*y+z*z;
        if(dis>lvl*lvl/2)
        {
        tell_object(me,HIB"�����ʱ�Ĺ��������޷��ѻ����ңԶ�ĵ��ˡ�\n"NOR);
                return;
        }
   me->set_temp("ninjitsu_dart",1);        
        call_out("throwing",delay,me,ob,room,extra);
        me->start_busy(delay);
        
        my_skill=me->query_skill("ninjitsu",1)+1;
        your_perp=ob->query_skill("perception",1)+1;
        
        if (random(your_exp*your_perp)>random(my_exp*my_skill)) 
                tell_object(ob,HIW"������һ����ֻ��һ�����ε�ɱ��Ϯ����\n"NOR);
                
        return ;
} 
int throwing(object me, object ob, object room,int extra)
{       
        string msg;
        int my_exp,your_exp,your_perp, my_skill;
        me->delete_temp("ninjitsu_dart");
        if(userp(ob))
                me->start_busy(10+random(10));
        else
                me->start_busy(3);
    message_vision(HIR"$N΢��˫Ŀ�ͺ�һ�������������һö���ڶ�����������㻮�����ա�����\n"NOR,me);
        
        my_exp=me->query("combat_exp");
        my_skill=me->query_skill("ninjitsu",1)+1;
        your_exp=ob->query("combat_exp");
        your_perp=ob->query_skill("perception",1);
        
        if(present(ob,room))
        {
        message_vision(HIR"$N��ǰһ����һö���ھ��Ѻ�Х��������\n"NOR,ob);
        if(userp(ob))
                ob->delete_temp("been_darted");
                if (random(your_exp*your_perp)>random(my_exp*my_skill*2)
                        || ob->query_temp("been_darted")+300>time())
                {
                        message_vision(HIG"$N�ƺ�����׼��,��ָһ��,ž�ؽ����ڼ�ס.\n"NOR,ob);
                        msg=TASK_D->locate_obj(ob,me->query("id"));
                        tell_object(ob,"���ݷ��ڵ����ƣ����жϳ���Ϯ�����"+msg+"��\n");                
                        tell_object(me,"����,��ķ��ڱ��Է����ˡ�\n");
                   return 1;
                }
                        
                ob->set_temp("damaged_during_attack",1);
                COMBAT_D->report_status(ob);
                msg=TASK_D->locate_obj(ob,me->query("id"));
                tell_object(ob,"���ݷ��ڵ����ƣ����жϳ���Ϯ�����"+msg+"��\n");                
                tell_object(me,"������ľѻ��ɹ��ˡ�\n");
                ob->receive_wound("kee",extra/2);
                ob->receive_damage("kee",extra/2);
                ob->set_temp("last_damage_from",me);
                ob->set_temp("been_darted",time());
                return 1;
        }
    message("vision",HIW"һö���ڰ��һ����������ǰ��\n"NOR,room);
    tell_object(me,"�ǳ��ź�����ľѻ��޹�����������\n");
        return 1;
}
        
           
