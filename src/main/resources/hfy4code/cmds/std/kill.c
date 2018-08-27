 // kill.c
// Modified by justdoit at Dec 5,2001
// When player type kill,KILL_LOG file will add user id in it. 
#include <ansi.h>
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
        object obj;
        string *killer, callname;
        seteuid(getuid());
        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ׼ս����\n"); 
        if( !arg )
                return notify_fail("����ɱ˭��\n"); 
        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n"); 
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n"); 
        if(obj==me)
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n"); 
        callname = RANK_D->query_rude(obj);

        if( userp(obj) &&
                (int) obj->query("combat_exp") < me->query("combat_exp")/10 &&
                !me->query("licensed_to_kill")          
          )
                return notify_fail("������ɲ����Ըĵ���ǿ�����Ķ�ϰ��\n");

        if( userp(obj) && environment(obj)->query("no_pk"))
                me->add("vendetta/pker",1); 
/*        if( userp(obj))
   log_file( "KILL_LOG", sprintf("(%s)
%s tried to kill %s\n", ctime(time()), me->query("name")+"("+me->query("id")+")", obj->query("name")+"("+obj->query("id")+")")); */
        message_vision("\n$N����$n�ȵ�����" 
                + callname + "�����ղ������������һ��\n\n", me, obj); 
        me->kill_ob(obj);
        if( !userp(obj) )
                obj->kill_ob(me);
        else {
                obj->fight_ob(me);
           tell_object(obj, HIR "�����Ҫ��" + me->name() 
                        + "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
        } 
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ��������ҡ���ɱ���Է���kill �� fight ����
��ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill�� 
�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)�� 
�������ָ��: fight 
�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
  