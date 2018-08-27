 // friend.c
// -silencer@fy4.com 
#include <ansi.h> 
inherit F_CLEAN_UP; 
void create()
{
        seteuid(getuid());
} 
int main(object me, string arg)
{
        string msg, name, *friends,*new_friends;
        object body,ob;
        int i;
        
        friends = me->query("friends_list");
        if (!friends) 
                friends=({});
        
        new_friends=friends;
        
        if( (int)me->query("sen") < 150 && !wizardp(me))
                        return notify_fail("������Ҫ������������\n"); 
        
        if( !arg ) {
                if (!sizeof(friends)) {
                        write("���ͨѶ¼�ǿյġ�\n");
                        return 1;
                }
                for (i=0;i<sizeof(friends);i++) {
                        name=friends[i];
                        ob = new(LOGIN_OB);
                        ob->set("id", name);
                        if (!ob->restore()) {
                                msg=sprintf(YEL"%-26s\t�����ڣ����Զ������ͨѶ¼�г�����\n"NOR, name);
                                new_friends=new_friends-({name});
                                write(msg);
                                continue;
                        }       
                        if( objectp(body = find_player(name)) && geteuid(body)==name ) 
                                msg = sprintf(HIG"%-16s%-10s\tĿǰ���������С�\n"NOR, ob->query("name"),name); 
                   else 
                                msg=sprintf(CYN"%-16s%-10s\tĿǰ���������С�\n"NOR, ob->query("name"),name);
                        write(msg); 
                }
                me->set("friends_list",new_friends);
                if (!wizardp(me)) me->receive_damage("sen",150);
        }
        else    {
                ob = new(LOGIN_OB);
                ob->set("id", arg);
                if( !ob->restore() ) {
                        write ("û�������ҡ�\n");
                        return 1;
                }
                if ( !friends || member_array(arg,friends)==-1) { 
                        if (sizeof(friends)>=15) {
                                write(HIR"ͨѶ¼�����ֻ����ʮ������֣���ɾȥһЩ�����õġ�\n"NOR);
                                return 1;
                        }
                        me->set("friends_list",friends+({arg}));
                        write(WHT"�㽫��� "+ob->query("name")+"��"+arg+"�� ����ͨѶ¼��\n"NOR);
                }else   {
                        me->set("friends_list",friends-({arg}));
                        write(WHT"�㽫��� "+ob->query("name")+"��"+arg+"�� ��ͨѶ¼��ȥ���ˡ�\n"NOR);
                }
        
        } 
        return 1;
} 
int help(object me)
{
  write(@HELP
ָ���ʽ : friend [���Ӣ�����]
��ָ��Ϊ����ʽ����һ�δ��뽫��һ��������ּ������ͨѶ¼����ͬ��
����������ٴβ������Ѵ����ִ�ͨѶ¼��ɾ������������κβ�����
��ʾͨѶ¼��������ҵ�����״����ͨѶ¼�����ɴ洢ʮ������֡�
see also : who, finger
HELP
    );
    return 1;
}
       
