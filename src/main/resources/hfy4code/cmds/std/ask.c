 // ask.c
#include <ansi.h> 
inherit F_CLEAN_UP; 
string *msg_dunno = ({
        "$n��������ش�$N�����⡣\n",
        "$n�����۾�����$N����ô�򵥵����ⶼҪ����\n",
        "$n�����ʼ磬����ϧ�ض�$N˵�������ǲ��ɾ�ҩ��\n",
        "$n��$N˵������....����������������Լ���\n",
        "$n��$N˵�����Բ���̫��������ͬ���������ˣ�\n"
}); 
int main(object me, string arg)
{
        string dest, topic, msg;
        string *chat_msg;
        object ob;
        int i;
        mapping inquiry; 
        seteuid(getuid()); 
        if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
                return notify_fail("��Ҫ��˭ʲ���£�\n"); 
        if( !objectp(ob = present(dest, environment(me))) )
                return notify_fail("����û������ˡ�\n"); 
        if( !ob->is_character() ) {
                message_vision("$N����$n��������....\n", me, ob);
                return 1;
        } 
        if( !ob->query("can_speak") ) {
                message_vision("$N��$n�����йء�" + topic + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
                return 1;
        } 
        if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
                message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob); 
        if( userp(ob) ) return 1;
        if( !living(ob) ) {
                message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n",
                        me, ob);
                return 1;
        }
        if(topic == "here"){
                chat_msg = ob->query("chat_msg");
           i = random(sizeof(chat_msg));
                if(sizeof(chat_msg) > 0) {
                        if (stringp(chat_msg[i])){
                                message_vision(chat_msg[i], me, ob);
                                
                        } else { 
                                message_vision("$n˵������....��������������һ���ȣ�\n", me, ob);
                        }
                } else {
                        message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
                }       
                return 1;
        }
        if( msg = ob->query("inquiry/" + topic) ) {
                if( stringp(msg) ) {
                        message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
                        return 1;
                }
        } else if (msg = ob->query("inquiry/" + "*")){
                if( stringp(msg) ) {
                message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
                return 1;
                }
        } else {
                message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
        }
        return 1; 
} 
int help(object me)
{
   write( @HELP
ָ���ʽ: ask <someone> about <something>  or ask <someone> about here 
���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
HELP
   );
   return 1;
}     
