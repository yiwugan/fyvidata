 // user list
#include <ansi.h> 
inherit F_CLEAN_UP; 
int main(object me,string arg)
{
        string id, id2;
        object obj, *pros;
        int i, remove_me;
        if (!arg)
                return notify_fail("ָ���ʽ : baohu <����>\n");
        if(!stringp(id=me->query("marry")))
                return notify_fail("�����û�н�飡\n");
        if (!objectp(obj=present(arg,environment(me))))
                return notify_fail("������������\n");
        if(id!= arg)
                return notify_fail(obj->name()+"���󲢲������"+(me->query("gender") == "Ů��" ? "�ɷ�":"����")+"��\n");
        id2 = obj->query("marry");
        if( id2 != me->query("id"))
                return notify_fail(obj->name()+"���󲢲������"+(me->query("gender") == "Ů��" ? "�ɷ�":"����")+"��\n");
// passed all checks!
        pros = obj->query_temp("protectors");
        remove_me =0;
        for(i=0;i<sizeof(pros);i++)
                if(pros[i] == me) 
                {
                 pros -= ({ me });
                 remove_me =1;
                }
        if (remove_me) {
                obj->set_temp("protectors",pros);
                return notify_fail("��ֹͣ�������"+(me->query("gender") == "Ů��" ? "�ɷ�":"����")+obj->name()+"�ˣ�\n");      
        } 
        if(sizeof(pros))
                pros += ({ me });
        else
                pros = ({ me });
        obj->set_temp("protectors",pros);
        write("�㿪ʼ�������"+(me->query("gender") == "Ů��" ? "�ɷ�":"����")+obj->name()+"��\n");
        return 1;
        
} 
int help(object me)
{
write(@HELP
ָ���ʽ : baohu <����> 
�����ѻ�����������Է������ӣ��ɷ򣩵�ָ��
�����Ϊ������ʱ����������Լ��߳��Ĳ��еļ���������
�Լ���ͬ�飬��Է���ܵ��˵Ĺ�����
HELP
    );
    return 1;
}
