 // by Tie@fy3 hehe
inherit F_CLEAN_UP;
inherit F_DBASE;
mapping *quests;
string locate_obj(object me,string strr);
object find_env(object ob);
#define MAX_DIS 7
#define MAX_ALT  2
#define MAX_DIR  8  
mapping *read_table(string file) {
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn; 
        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
                        continue;
                }
                break;
        } 
        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}
int main(object me, string str)
{
        string output = "";
        if(!str) return notify_fail("ָ���ʽ: locate <��Ʒ>\n");
   if(me->query("sen") < 10) return notify_fail("����������Բ�Ѱλ�á�\n");
        me->add("sen",-5);
        output = locate_obj(me,str);
//      if(output=="")
//              output = QUESTNPC_D->locate_obj(me,str);
        if(output=="")
                return notify_fail("ȷ������"+str+"�Ĵ��λ�á�\n");
        write(output);
        return 1;
}  
string locate_obj(object me,string strr) {
        string *distance = ({
                "����", "�ܽ�", "�ȽϽ�", "��Զ",
                "����", "�Ƚ�Զ", "��Զ", "��Զ"
        });
        string *altitude =({
                "�ߴ�", "�ط�", "�ʹ�"
        });
        string *directions=({
                "��Χ","����", "�Ϸ�", "����","����",
                "������","������","���Ϸ�","���Ϸ�"
        });
        object ob, tmpobj,where, *ob_list;
        object item,room;
        string output,dis,alt,dir;
        int i;
        int x,y,z,x0,y0,z0;
        int realdis;
        int tmp;
        string str="";
        reset_eval_cost();
        quests = read_table("/quest/dynamic_quest");
        for( i=0; i < sizeof(quests); i++)
        {
                if(!objectp(item= find_object(quests[i]["file_name"])))
                        item = load_object(quests[i]["file_name"]);
        if(item->query("id") == strr || item->query("name") == strr) str = quests[i]["file_name"];
        }
        if(str != "") {
                room = environment(me);
           ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                        ob=find_env(ob_list[i]);
                        if(ob)
                        {
                                x0= (int)room->query("coor/x");
                                y0= (int)room->query("coor/y");
                                z0= (int)room->query("coor/z");
                                x=(int)ob->query("coor/x")-x0;
                                y=(int)ob->query("coor/y")-y0;
                                z=(int)ob->query("coor/z")-z0;
                                realdis=0;
                                if(x<0)realdis-=x; else realdis+=x;
                                if(y<0)realdis-=y; else realdis+=y;
                                if(z<0)realdis-=z; else realdis+=z;
                                tmp =(int)  realdis/50;
                                if(tmp>MAX_DIS) tmp = MAX_DIS;
                                dis=distance[tmp];
                                if(z>0) alt=altitude[0];
                                if(z<0) alt=altitude[2];
                                if(z==0) alt=altitude[1];
                                if(x==0&&y==0) dir=directions[0];
                                if(x==0&&y>0) dir=directions[1];
                                if(x==0&&y<0) dir=directions[2];
                                if(x>0&&y==0) dir=directions[3];
                                if(x<0&&y==0) dir=directions[4];
                                if(x>0&&y>0) dir=directions[5];
                                if(x<0&&y>0) dir=directions[6];
                                if(x>0&&y<0) dir=directions[7];
                                if(x<0&&y<0) dir=directions[8];
                                output = "��"+ob_list[i]->query("name")+"���ƺ���"+dir+dis+"��"+alt+"��\n";
                                return output;
                        }
                        else return "";
                }
        }
        else 
        if(wizardp(me) || me->query("class") == "official")
        {
                if (!wizardp(me) && me->query("combat_exp")<50000)
                   {tell_object(this_player(),"��ľ��黹������ȷ�����˵����ڡ�\n");
                                return"";
                        }       
                        tmpobj = find_player(strr);
                        if(!tmpobj) tmpobj = find_living(strr);
                        if(!tmpobj) return "";
                        ob = find_env(tmpobj);
                        room = environment(me);
                        if(ob)
                        {
                                x0= (int)room->query("coor/x");
                                y0= (int)room->query("coor/y");
                                z0= (int)room->query("coor/z");
                                x=(int)ob->query("coor/x")-x0;
                                y=(int)ob->query("coor/y")-y0;
                                z=(int)ob->query("coor/z")-z0;
                                realdis=0;
                                if(x<0)realdis-=x; else realdis+=x;
                                if(y<0)realdis-=y; else realdis+=y;
                                if(z<0)realdis-=z; else realdis+=z;
                                tmp =(int)  realdis/50;
                                if(tmp>MAX_DIS) tmp = MAX_DIS;
                                dis=distance[tmp];
                                if(z>0) alt=altitude[0];
                                if(z<0) alt=altitude[2];
                                if(z==0) alt=altitude[1];
                                if(x==0&&y==0) dir=directions[0];
                                if(x==0&&y>0) dir=directions[1];
                                if(x==0&&y<0) dir=directions[2];
                                if(x>0&&y==0) dir=directions[3];
                                if(x<0&&y==0) dir=directions[4];
                                if(x>0&&y>0) dir=directions[5];
                                if(x<0&&y>0) dir=directions[6];
                                if(x>0&&y<0) dir=directions[7];
                                if(x<0&&y<0) dir=directions[8];
                                output = "��"+tmpobj->query("name")+"���ƺ���"+dir+dis+"��"+alt+"��\n";
                                return output;
                        }
                        else return "";
        }
   else
                return "�㲻�ǳ�͢��Ա������locate��\n"; 
}   
int help(object me)
{
        write(@HELP
ָ���ʽ: locate <��Ʒ> 
���ָ����������֪ʹ����Ʒ�Ĵ��λ�á�
��͢��Ա�������ô�ָ���Ѱ����Ĵ��λ�á� 
HELP
        );
        return 1;
} 
object find_env(object ob)
{
        while(ob)
        {
        if(ob->query("coor") ) return ob;
        else ob=environment(ob);        
        }
        return ob;
}        
