#define BABYFILE DATA_DIR + "babies"
inherit F_DBASE;
inherit F_SAVE;
#include <ansi.h>
mapping *babies=({});
void create()
{
        seteuid(getuid());
        set("name", "��������");
                set("no_cleanup",1);
        set("id", "babyd");
        restore();
} 
string query_save_file() { return BABYFILE; } 
void add_baby(object baby)
{
        mapping data=([]);
        string *names;
        names=baby->query("parents");
        data["name"]=baby->query("id");
        data["timestamp"]=baby->query("time_stamp");
        data["father"]=names[1];
        data["mother"]=names[0];
        babies+=({data});
        save();
} 
void return_home(object baby)
{
        string *babylist;
        int i;
        babylist=query_temp("babylist");
        for(i=0;i<sizeof(babylist);i++)
                if(babylist[i]==baby->query("time_stamp"))
                        {
                        babylist[i]=0;
                        break;
                        }
        set_temp("babylist",babylist);
} 
int query_baby(object parent)
{
        int i;
        string *babylist;
        babylist=query_temp("babylist");
        if(!babylist) babylist=({});
        while(sizeof(babylist)<sizeof(babies))
                babylist+=({0});
        for(i=0;i<sizeof(babies);i++)
                if( babies[i]["father"]==parent->query("id")
                        || babies[i]["mother"]==parent->query("id") )
                        if( !stringp(babylist[i]) )
                                return i;                               
        return -1;
} 
void chang_name(object baby)
{
        int  i;
        for(i=0;i<sizeof(babies);i++)
                if(babies[i]["timestamp"]==baby->query("time_stamp"))
                        {
                        babies[i]["name"]=baby->query("id");
                        break;
                        }
} 
object get_baby(object parent)
{
        int babyno;
        object  baby;
        string* babylist;
        babylist=query_temp("babylist");
        if(!babylist) babylist=({});
        while(sizeof(babylist)<sizeof(babies))
                babylist+=({0});
        if( (babyno=query_baby(parent)) >-1 )
                {
                baby=new("/obj/npc/baby");
                baby->set("owner",babies[babyno]["mother"]);
                baby->set("time_stamp",babies[babyno]["timestamp"]);
                baby->restore();
                baby->set_name(baby->query("name"),({baby->query("id"),"baby"}) );
           babylist[babyno]=baby->query("time_stamp");
//              if(!baby->query("title"))
//                      {
                                switch(baby->query("age")+random(5))
                                {case 0:
                                        baby->set("title",HIW"����С����"NOR);
                                break;
                                case 1:
                                        baby->set("title",HIW"���ƹԱ���"NOR);
                                break;
                                case 2:
                                        baby->set("title",HIW"���Ʊ���"NOR);
                                break;
                                case 3:
                                        baby->set("title",HIW"����������"NOR);
                                break ;
                                case 4:
                                        baby->set("title",HIW"����ϣ��֮��"NOR);
                                break ;
                        default:
                                        baby->set("title",HIW"������Ѫ"NOR);
                                 }
                           baby->save();
//                                                      }
                }
        else
                write("����û���⺢�ӣ��ǲ����Ѿ��������ˣ�\n");
        set_temp("babylist",babylist);
        return baby;
}  
