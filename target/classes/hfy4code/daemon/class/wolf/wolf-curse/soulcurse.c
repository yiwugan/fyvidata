#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int extradam;
        if(me->query("class")!="wolfmount")
                return notify_fail("ֻ����ɽ���Ӳ���ʹ�������������\n");
       
        if((int)me->query_skill("cursism") < 200 )
                return notify_fail("��Ľ�ͷ�������ߣ�\n"); 
        if((int)me->query("kee") < 1000 )
                return notify_fail("�����Ѫ������\n");
                 write("����ʹ˭��ꣿ");
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
                write("\n��ֹʩ����\n");
                return;
        } 
        ob = find_living(name);
        room = environment(me);
        if( !ob  || !present(ob, room)){
                write("\n���������\n");
                return; 
        }       
        if(ob->is_ghost() || ob->is_corpse())           {
                write("\n��ֻ�ܶԻ����������ͷ��\n");
           return;
        }
        if (!userp(ob)){
                write("\n��ֻ�ܶ�����������ͷ.\n");
                return;
        }
        me->receive_wound("kee",1000);
        if (ob!=me) msg = HIB "\n$N��$n��������������λ���������οࡣ��Ī����ȥ������\n\n" ;
                else msg = HIB "\n$N��������������λ���������οࡣ��Ī����ȥ������\n\n" ;
        
        me->start_busy(2);
        level = (int) me->query_skill("cursism");
        if( random(level)>level/2) 
                { 
                if (ob!=me){
                msg +=  "$n��Ȼ����������ͷ��ð��һ��Ũ��Ũ����һ����Ӱ�����ܿ����ʧ�ˡ�\n" NOR;
                message_vision(msg, me,ob);
                }       else {
                msg +=  "$N��Ȼ����������ͷ��ð��һ��Ũ��Ũ����һ����Ӱ�����ܿ����ʧ�ˡ�\n" NOR;
                message_vision(msg, me);
                } 
                if(objectp(corpse = CHAR_D->make_corpse(ob, me)))
                        corpse->move(room);
                ob->be_ghost(1);
                ob->move("/d/death/gate");
                return;
                }
        else
        msg += "���ʲôҲû�з���\n"NOR;
        if (ob !=me) message_vision(msg, me,ob);
                else message_vision (msg,me);
        
}        
