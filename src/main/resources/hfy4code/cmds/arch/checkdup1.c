#include <combat.h>
#include <ansi.h>
#define SYNTAX  "ָ���ʽ��gq <dir>\n"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        int i,j,k,m,l,flag=0;
        string *top = ({"/adm/"});
        string direc,*dir,*dir1, roomname;
        string *file;
        string status;
        object *nodes = ({});
        object newnode;
        object room;
        if(!me->query("env/yesiknow")) return notify_fail("���ָ���Ѿ����ϳ��ˣ�\n");
        status = wizhood(me);
        if( me!=this_player(1)
        || wiz_level(me) < wiz_level(status) )
                return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
        seteuid(getuid());
        for(i=0; i<sizeof(top); i++) 
        {
        dir = get_dir(top[i]);//dir=/daemon/class/�µ�Ŀ¼�б�
        write(top[i]+"\n");///daemon/class/
        for(j=0; j<sizeof(dir); j++)
        {dir1=get_dir(top[i]+dir[j]+"/");//dir1=/daemon/class/assassin/�µ�Ŀ¼�б�
        write(top[i]+dir[j]+"/"+"\n");//daemon/class/assassin/
        for(l=0;l<sizeof(dir1);l++)
        {write(top[i]+dir[j]+"/"+dir1[l]+"/"+"\n");///daemon/class/assassin/jingxing/
        file = get_dir(top[i]+dir[j]+"/"+dir1[l]+"/");
        //write("ok");
        for(k=0; k<sizeof(file); k++)
        {//write(k);
        if( sscanf(file[k],"%s.c", roomname) != 1) continue;
                write( "working on:" +file[k]+"\n");
        reset_eval_cost();
                room = load_object(top[i]+dir[j]+"/"+dir1[l]+"/"+file[k]);
        
        flag = 0;
        for(m=0;m<sizeof(nodes);m++)
                {
                        if(nodes[m]->query("x") == room->query("coor/x")
                        && nodes[m]->query("y") == room->query("coor/y")
                   && nodes[m]->query("z") == room->query("coor/z"))
                        {
                        flag = 1;
                        nodes[m]->add("dups"," "+top[i]+dir[j]+"/"+dir1[l]+"/"+file[k]);
                        }                                        
                }
        if(!flag)
                {
                newnode = new("/obj/armor/cloth.c");
                newnode->set("x",room->query("coor/x"));
                newnode->set("y",room->query("coor/y"));
                newnode->set("z",room->query("coor/z"));
                newnode->set("dups",top[i]+dir[j]+"/"+dir1[l]+"/"+file[k]);
                nodes += ({ newnode });
                }
        
        }}}}
        for(i=0;i<sizeof(nodes);i++)
        {
        if(strsrch(nodes[i]->query("dups")," ") != -1)
        write_file("DUP",nodes[i]->query("dups")+"\n");
        } 
        return 1;
}     
