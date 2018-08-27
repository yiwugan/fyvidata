#include <vote.h>
#include <ansi.h>
#define COL_PERIOD 300
inherit F_DBASE;
void check_vote(string whowhat);
int get_value(string what);
void create()
{
        seteuid( ROOT_UID );
}
int add_vote(object me, string what, string who)
{
        if(!query(who+"/"+what))
        {
        set(who+"/"+what, ({ (string)query_ip_number(me) }));
        set(who+"/"+what+"_time", time());
        call_out("check_vote", COL_PERIOD, who+"/"+what);
        return 1;
        }
        if(sizeof(query(who+"/"+what)) < get_value(what))
        {
        string *ips;
        int i;  
        ips = query(who+"/"+what);
        for(i=0;i<sizeof(query(who+"/"+what));i++)
                if(ips[i] == (string)query_ip_number(me))
                                return 0;
        add(who+"/"+what, ({ (string)query_ip_number(me) }));
        if(sizeof(query(who+"/"+what)) < get_value(what))
                return sizeof(query(who+"/"+what));
        else
        delete(who+"/"+what);
        return i+1;
        }
}

void check_vote(string whowhat)
{
        string who,what;
        string msg;
        if(sscanf(whowhat,"%s/%s",who,what) !=2 ) return;
        if(query(whowhat))
        {
        msg = HIW "��ͶƱ�����������Ʊ�����������ڶ�"+who+"ʵ��"+what+"�ı������ȡ����\n" NOR;        
        message("system",msg,users());  
        delete(who+"/"+what);
        }
        return;
}

int get_value(string what)
{
switch(what) {
        case "right": return (int) right_no;
        case "noright": return (int) noright_no;
        case "kickout": return (int) kickout_no;
        case "robot": return (int) robot_no;
        case "block": return (int) block_no;
        case "noblock": return (int) noblock_no;
        case "ban": return (int) ban_no;
        case "off": return (int) off_no;
        case "on": return (int) on_no;
        case "imprison" : return (int) imprison_no;
        case "redis" : return (int) sizeof(users())/2 + 1;
        default : return 0;
                }

}
