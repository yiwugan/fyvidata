 // logind.c //modified by wuxiami 02.03.08
// 120-145 line added for max_dummy 
#define MAX_DUMMY 2 //�����������dummy
#include <ansi.h>
#include <command.h>
#include <login.h> 
inherit F_DBASE;
int wiz_lock_level = WIZ_LOCK_LEVEL;
int new_user_lock = NEW_USER_LOCK;
string L_IP = "216.101.216.5";
string Rname;
string *banned_name = ({ 
        "��", "��", "��", "��", "��", "��", "��",
        "����","����", "���ƣɣ�","���Ƣ�", "����",
        "����",  "����","�ɹ���","���ƣɣɣ�","���Ƣ�",
        "ϵͳ", "����", "ϵͳ����", "���Ƣ�", "���ƣɣ�",
        "��", "��", "������","�ƣգã�","�ƣ����","���",
        "��","��","ү","��","��","��","���","��","��",
        "��","ë��","������","����","������","�¼ұ�","�й�","�ձ�","����","Ի",
});
string *banned_id= ({
        "chat", "new", "fy", "rumor", "tell", "none", "reboot",
        "shutdown","core", "fymud","mud", "fuck", "public",
        "dick",  "shit","cao","cunt","slut","tianji", "song", "zhu",
        "mei", "afa",
        "master", "all",
}); 
string *start_loc = ({
        AREA_FY"fqkhotel",
        AREA_CHENXIANG"cag",
        AREA_GUANWAI"inn",
        AREA_LAOWU"inn",
}); 
string *national = ({
        "����",
        "����",
        "����",
        "�ɹ���",
}); 
private void get_encoding(string arg, object ob);
private void get_id(string arg, object ob);
private void read_msg(string arg, object ob);
private void get_resp(string arg, object ob);
private void confirm_id(string yn, object ob);
private int valid_wiz_login(string id,string ip);
private object make_body(object ob);
private void init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
int check_legal_password(object ob,string arg);
int set_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar);
int cphirdir(string dirstr, string newdirstr);
string random_name();
void logon_write(string str); 
void create() {
        seteuid(getuid());
} 
void logon(object ob) {
        
        // Before we do all this, see if this installation is legal and not expired
/*
        if(SECURITY_D->check_illegal(L_IP)) {
                shutdown(0);
        }
        if(SECURITY_D->check_illegal2()) {
                shutdown(0);
        } 
*/      
        if (BAN_D->is_banned(query_ip_name(ob))  ||
                        BAN_D->is_banned(query_ip_number(ob))) {
                write("�Բ������ĵ�ַ���ܾ����ߡ�\n"
                "��ţͣ��ɣ̣�����������������������ߡ�\n");
                destruct(ob);
                return;
        }
        
        cat(WELCOME) ;
   get_encoding("", ob);
} 
private void get_encoding(string arg, object ob) {
        string str;
        object *usr;
        int i, wiz_cnt, ppl_cnt, login_cnt,log_num=0;
        
        if(arg == "0" || arg == "��") {
                ob->set_temp("char_encoding", "gb");
        } else if(arg == "1" || arg == "��") {
                ob->set_temp("char_encoding", "big5");
        } else {
                str = "������";
                write("    0) " + str + "(" + ENCODE_D->gbTobig5(str) + ") GB\n");
                str = "������";
                write("    1) " + str + "(" + ENCODE_D->gbTobig5(str) + ") BIG5\n");            
                str = "��ѡ����ʹ�õ�����";
                write(str + "(" + ENCODE_D->gbTobig5(str) + "): ");
                input_to((: get_encoding :), ob);
                return;
        }
        write("\n\n");
        UPTIME_CMD->main();
        usr = users();
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
        for(i=0; i<sizeof(usr); i++) {
                if( !environment(usr[i]) ) login_cnt++;
                else if( wizardp(usr[i]) ) wiz_cnt++;
                else ppl_cnt++;
        }
        write(sprintf(BLU"Ŀǰ����%sλ��ʿ������Ϸ�С�\n"
        "������%sλ����Ա��%sλ������ҡ���%sλ�����ߡ�\n\n" NOR,
        chinese_number(WHO_D->query_num()), chinese_number(wiz_cnt),
        chinese_number(ppl_cnt), chinese_number(login_cnt)));
//max_dummy
        for(i=0;i<sizeof(usr);i++) 
        if (ob!=usr[i]) 
           if 
                (
                        (
                                //����netbar���������ò������Ƶ�վ��
                                !NETBAR_D->is_netbar(query_ip_number(ob))
                                &&!NETBAR_D->is_netbar(query_ip_name(ob))
                        )
                        &&
                                query_ip_name(ob)==query_ip_name(usr[i])
                ) 
                log_num=log_num+1;      
        if (log_num > MAX_DUMMY )
        {  
                write(HIR+"��ֻ����ͬʱ��½" + chinese_number(MAX_DUMMY+1) + "��ID�����˳������ʺ����ԡ�\n"+NOR); 
                destruct(ob); 
                return;                 
        }
        else
        {       log_num=MAX_DUMMY-log_num;
                write("�����ڵĵ�ַ("+YEL+query_ip_number(ob)+NOR")��������"YEL+chinese_number(log_num)+NOR"λ������ߡ�\n\n");
        }
        
        write("����Ӣ�����֣�");
        input_to( (: get_id :), ob);
} 
private void get_id(string arg, object ob)
{
        object ppl,*usr;
        int i; 
        arg = lower_case(arg);
        if( !check_legal_id(arg))
        {
                write("����Ӣ�����֣�");
                input_to("get_id", ob);
                write("\n");
                return;
        }
#ifdef MAX_USERS
        if( (string)SECURITY_D->get_status(arg)=="(player)"
           && sizeof(users()) >= MAX_USERS ) 
        {
                ppl = find_body(arg);
                // Only allow reconnect an interactive player when MAX_USERS exceeded.
                if( !ppl || !interactive(ppl) )
                {
                        write("�Բ���"+MUD_NAME+"��ʹ�����Ѿ�̫���ˣ������������\n");
                        destruct(ob);
                        return;
                }
        }
#endif 
        if( wiz_level(arg) < wiz_lock_level )
        {
                write("�Բ���" + MUD_NAME + 
                          "Ŀǰ����ά��֮�У����Ժ������ߡ�\n");
                destruct(ob);
                return;
        }
                
        if( (string)ob->set("id", arg) != arg )
        {
                write("Failed setting user name.\n");
                destruct(ob);
                return;
        }
// toomany guets nowdays
        if( arg=="guesttttttttt" )
        {
                // If guest, let them create the character.
                confirm_id("Yes", ob);
                return;
        }
        else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 )
        {
                if( ob->restore() )
                {
                        write("��Ӣ�������ѱ�ʹ�ã���������ʺŵ����룺");
                        input_to("get_passwd", 1, ob);
                   return;
                }
                write("�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
                destruct(ob);
                return;
        }
        if(new_user_lock)
        {
                write("���ڷ��Ʋ������µ�������Ժ��ٴ����µ����\n");
        destruct(ob);
        return;
        }
        usr = filter_array(children(LOGIN_OB), (: interactive :));
        i = sizeof(usr);
        while (i--)
                if (usr[i] != ob && usr[i]->query("id") == arg)
                        break;
        if (i >= 0) {
                write("�������������ʹ����� ID�����������롣\n");
                write("����Ӣ�����֣�");
                input_to("get_id", ob);
                return;
        }                       
        write("ʹ�� " + (string)ob->query("id") +
                  "\n������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
        input_to("confirm_id", ob);
} 
private void get_passwd(string pass, object ob)
{
        string my_pass;
        object user; 
        write("\n");
        my_pass = ob->query("password");
        if( crypt(pass, my_pass) != my_pass )
        {
                write("�������\n");
                log_file("ATTEMPT_LOGIN",sprintf("FAILED: %s tried to login from %s\n",
                                                                                 ob->query("id"), query_ip_name(ob)));
                destruct(ob);
           return;
        } 
        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (user)
        {
                if(!user->query_temp("successful_login")) {
                        destruct(user);
                } else {
                
                if( user->query_temp("netdead") )
                {
                        reconnect(ob, user);
                        return;
                }
                                
                write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
                }
        } 
        if( objectp(user = make_body(ob)) )
        {
                if( user->restore() )
                {
                        log_file( "USAGE", sprintf(
                                "%s loggined from %s (%s)\n",
                                user->query("id"),query_ip_name(ob), ctime(time()) ) );
                        log_file("STAT", sprintf(
                                "ON %s %s %d %d %d %d %d %d %s\n",
                                user->query("id"),user->query("name"),
                                user->query("combat_exp"), user->query("deposit"),
                                user->query("potential"),user->query("TASK"),
                                user->query("mud_age"), user->query("QUEST"),
                                ctime(time()) ) );
                        if(time()-(int)user->query("kickout_time") < 3600)
                        {
                                write("������û�н�����Ƶ�Ȩ������һСʱ�������ߡ�\n");
                                destruct(user);
                           destruct(ob);
                                return;
                        }
                        enter_world(ob, user);
                        return;
                }
                else  destruct(user);
        }
        write("�������´���������\n");
        confirm_id("y", ob);
} 
private void confirm_relogin(string yn, object ob, object user)
{
        object old_link; 
        if(!objectp(user)) {
                write("��һ�������е���ͬ�����Ѳ����ڣ���������ߡ�\n");
                destruct(ob);
                return;
        }
        
        if(yn=="") {
                write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }        
        if(yn[0]!='y' && yn[0]!='Y') {
                write("�ðɣ���ӭ�´�������\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "���˴ӱ�( " + query_ip_name(ob)
                                        + " )����ȡ���������Ƶ����\n");
                log_file("USAGE", sprintf("%s replaced by %s (%s)\n", 
                                                                   user->query("name"),
                                                                   query_ip_name(ob), ctime(time()) ) );
        } 
        // Kick out tho old player.
        old_link = user->query_temp("link_ob");
        if( old_link )
   {
                exec(old_link, user);
                destruct(old_link);
        } 
        reconnect(ob, user);    
} 
private void confirm_id(string yn, object ob)
{
        if( yn=="" )
        {
                write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
                input_to("confirm_id", ob);
                return;
        }       
        
        if( yn[0]!='y' && yn[0]!='Y' )
        {
                write("�ðɣ�������������������Ӣ�����֣�");
                input_to("get_id", ob);
                return;
        } 
        write( @TEXT
���Ƣ���һ���Թ���С˵Ϊ���������磬������һ�������ʣ�
�и��ԣ��ֲ���̫��ֵ��������֣��ر�Ҫ���������ǣ�
����ʹ�ù���С˵�е�������������ֽ�����������
�������Ὣ�����ٸ��ģ���������ء� 
����������������������֣���ֱ���ûس����ۣңţԣգңΣݡ�
TEXT
                );
        write("�����������֣�");
        input_to("get_name", ob);
}
        
private void get_resp(string arg, object ob)
{
        if( arg=="" )
   {
                write("������(y)������(n)����������֣�");
                input_to("get_resp", ob);
                return;
        } 
        if( arg[0]=='y' || arg[0]=='Y' )
        {
                printf("%O\n", ob);
                ob->set("name", Rname);
                write("���趨�������룺");
                input_to("new_password", 1, ob);
        return;
        }
        else if( arg[0]=='n' || arg[0]=='N')
        {
                Rname = random_name();
                write("������(y)������(n)����������֣�");
                printf( HIY" -- %s ��"NOR, Rname);
                input_to("get_resp", ob);
                return;
        }
        else
        {
                write("�Բ�����ֻ��ѡ������(y)������(n)�� ");
                input_to("get_resp", ob);
                return;
        }
} 
private void get_name(string arg, object ob)
{
        string name;
        if( arg =="")
        {
        Rname = random_name();
                write("������Ҫ������������������֣���\n");
                write("������(y)������(n)����������֣�");
                printf( HIY" -- %s ��"NOR, Rname);
                input_to("get_resp", ob);
        }
   else
        {
                if(ob->query_temp("char_encoding") == "big5") {
                        arg = ENCODE_D->big5Togb(arg);
                }
                if( !check_legal_name(arg) )
                {
                        write("�����������֣�");
                        input_to("get_name", ob);
                        return;
                } 
                printf("%O\n", ob);
                ob->set("name", arg);
                write("���趨�������룺");
                input_to("new_password", 1, ob);
        }
} 
private void new_password(string pass, object ob)
{
        write("\n");
        if( !check_legal_password(ob,pass))
        {
                input_to("new_password", 1, ob);
                write("���趨�������룺");
                return;
        }
        ob->set("password", crypt(pass,0) );
        write("��������һ���������룬��ȷ����û�Ǵ�");
        input_to("confirm_password", 1, ob);
} 
private void confirm_password(string pass, object ob)
{
        string old_pass;
        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("��������������벢��һ�����������趨һ�����룺");
                input_to("new_password", 1, ob);
                return;
   } 
        write("���ĵ����ʼ���ַ��");
        input_to("get_email",  ob);
} 
private void get_email(string email, object ob)
{
        object user;
        ob->set("email", email); 
        // If you want do race stuff, ask player to choose one here, then you can
        // set the user's body after the question is answered. The following are
        // options for player's body, so we clone a body here.
        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
                return; 
        write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
        input_to("get_gender", ob, user);
} 
private void get_gender(string gender, object ob, object user)
{
        if( gender=="" )
        {
                write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        } 
        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "����");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "Ů��" );
        else
        {
                write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }
        write("
��������
��������
��������
�����ɹ���
\n");
        write("��ѡ�����ڷ��Ƣ��е����壨0��1��2��3����");
        input_to("get_nresp",ob, user);
} 
private void get_nresp(string arg, object ob, object user)
{
        if( arg=="" )
        {
                write("��ѡ�����ڷ��Ƣ��е����壨0��1��2��3����");
                input_to("get_nresp", ob, user);
                return;
        }
        if( arg[0]=='0' || arg[0]=='1' || arg[0]=='2'|| arg[0]=='3')
        {
                log_file( "USAGE", sprintf("%s was created from %s (%s)\n", 
                                                                   user->query("id"),
                                                                   query_ip_name(ob), ctime(time()) ) );
        user->set("national",national[(int) (arg[0]-'0')]);
                init_new_player(user);
                enter_world(ob, user);
        return;
        }
        else
        {
                write("�Բ�����ֻ�ܴӣ�0,1,2,3����ѡ�� ");
                input_to("get_nresp", ob,user);
                return;
        }
} 
object make_body(object ob)
{
        string err;
        object user;
        int n; 
        user = new(ob->query("body"));
        if(!user)
        {
                write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
           write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
} 
private void init_new_player(object user)
{
        string national;
        user->set("title", "��ͨ����");
        user->set("birthday", time() );
        user->set("potential", 299);
        national = user->query("national");
        switch(national)
        {
        case "����":
// ���� high int, high per, low cor, low tol
                set_attribute(user,5,10,10,10,12,10,10,10,20,10,10,10);     
                break;
        case "����":
//���� high agi, high kar, low con, low spi
                set_attribute(user,10,10,20,10,10,10,5,5,10,15,10,20);
                break;
        case "����":
//���� high cps, spi, low int,dur
                set_attribute(user,10,10,10,5,8,10,10,20,10,15,20,10);
                break;
        case "�ɹ���":
//�ɹ��� high str, fle , low agi, dur
                set_attribute(user,10,20,5,5,10,20,10,10,10,15,10,10);
                break;
        }        
        user->setup();
        user->set("food", user->max_food_capacity());
   user->set("water", user->max_water_capacity());
        user->set("env/wimpy", 50);
        user->set("combat_exp",2000);
        user->set("channels", ({ "chat","fy","new","info",
                                                         "vote","bangtalk","teamtalk" }) );
} 
varargs void enter_world(object ob, object user, int silent)
{
        object cloth, room;
        mixed info;
        string id;
        string mailfile;
        int laston;
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);
        user->set_temp("char_encoding", ob->query_temp("char_encoding")); 
        write(CLR + "ĿǰȨ�ޣ�" + wizhood(user) + "\n");
        user->setup();
        
        // add here:
        if ( wizardp(user))
        {// add by akuma for wiz login ip check
             if( valid_wiz_login( user->query("id"),query_ip_number(user) )==0 )
             {
                write("���ʺ�ʹ���˲��������IP��½���������ʣ���mailto:admin@fengyun.com��лл��λ��ʦ�ĺ�����\n");
                destruct(ob);
                destruct(user);
                return;
             }
        }
        // In case of new player, we save them here right aftre setup 
        // compeleted.
        user->autosave();
        ob->save(); 
        cloth = new("/obj/armor/cloth");
        if(objectp(cloth)) {
                cloth->move(user);
                cloth->wear();
   }
        if(!silent )
        {
                cat(MOTD);
        id = user->query("id");
        mailfile = DATA_DIR+ "user/" + sprintf("%c",id[0]) + "/" + id + "/mail.o";
        if( file_size(mailfile) > 0 )
                        info = stat(mailfile);
        if( info && (int)info[0] >=0 )
                {
                        laston = (int) ob->query("last_on");
                        if( laston < info[1])
                                write(HIY"\n�������ţ��뵽���Ƴ���վ��һ�ˣ���\n\n"NOR);
                }
        write( HIR+"�ϴ����ߵ�ַ��" + ob->query("last_from") + "��"+
                           ctime(ob->query("last_on")) + "��\n\n" + NOR);
                write("���ûس����ۣңţԣգңΣݣ���������");
                input_to( "read_msg", user );
   }
}
private int valid_wiz_login(string id,string ip)
{
    string tmp, file;
        string *wiz_ips = ({});
        string tempip;
        int i;
        int sign=0;
        tmp=sprintf("/adm/etc/wizip/%s",id); 
    // read the list of the banned sites
    // û���ļ�Ҳ���Խ�ȥ
    if (file_size(tmp)>0)
    { 
        wiz_ips = explode(read_file(tmp), "\n"); 
        if(sizeof(wiz_ips)==0) return 3;
        for(i=0;i<sizeof(wiz_ips);i++)
        {
                if (regexp(ip, wiz_ips[i]) && wiz_ips[i]!="")
                {
                        sign=1;

                }
        }
        return sign;
    }
        return 1;
} 
private void read_msg(string str, object user) {
        string startroom; 
        if( user->is_ghost() )
                startroom = DEATH_ROOM;
        else if( !stringp(startroom = user->query("startroom")) )
        {
                switch((string) user->query("national"))
                {
                case "����":
                        startroom = start_loc[0];
                        break;
                case "����":
                        startroom = start_loc[1];
                        break;
                case "����":
                        startroom = start_loc[3];
                        break;
                case "�ɹ���":
                        startroom = start_loc[2];       
                        break;
                }
        user->set_temp("first_time_login", 1);
        } 
        if( !catch(load_object(startroom)) && user->move(startroom)){
                user->set("startroom", startroom);
        } else {
                user->move(START_ROOM);
                startroom = START_ROOM;
                user->set("startroom", START_ROOM);
        }
        tell_room(startroom, user->query("name") + 
                          "���߽���������硣\n", ({user})); 
        CHANNEL_D->do_sys_channel("sys",

                                                          sprintf("%s(%s)��%s���߽��롣", user->name(), 
                                                                          user->query("id"),query_ip_name(user)) );
        UPDATE_D->check_user(user);
        STATUS_D->compare_status(user);
        write(HIY "\n���ڹ���"+HIR+"/cmds/wiz/sameip"->tot_usr(user)+HIY+
                  "λ��Ҵ����վ�㣨"+query_ip_name(user)+"�����ߡ�\n\n"+NOR);
        user->set_temp("successful_login", 1);
        return;
} 
varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);
        // retain the old encoding scheme on reconnects.
        //user->set_temp("char_encoding", ob->query_temp("char_encoding")); 
        user->reconnect();    
        if( !silent )
        {
                tell_room(environment(user), user->query("name") + 
                                  "�������߻ص�������硣\n", ({user}));
        }
        CHANNEL_D->do_sys_channel(
                "sys",sprintf("%s(%s)��%s�������߽��롣", user->query("name"),
                                          user->query("id"), query_ip_name(user)) );
        UPDATE_D->check_user(user);
} 
int check_legal_id(string id)
{
        int i; 
        i = strlen(id);
                
        if( (strlen(id) < 3) || (strlen(id) > 8 ) )
        {
                write("�Բ������Ӣ�����ֱ����� 3 �� 8 ��Ӣ����ĸ��\n");
                return 0;
        }
        while(i--) if( id[i]<'a' || id[i]>'z' )
        {

                write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
                return 0;
        }
        if( member_array(id, banned_id)!=-1 )
        {
                write("�Բ�������Ӣ�����ֻ���������˵����š�\n");
                return 0;
        }
        return 1;
} 
string random_name()
{
        string *lname = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��","��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��","˾��",
"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
"����","�麣","����","΢��","��","˧","��","��","��","��","��","��","����","����","����","����",
        });
        return (lname[random(200)] + chinese_number(random(20)));
} 
int check_legal_name(string name)
{
        int i;
        string tempname; 
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 10 ) )
        {
                write("�Բ�������������ֱ�����һ����������֡�\n");
                return 0;
        }
        while(i--)
        {
                if( name[i]<=' ' )

                {
                        write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) )
                {
                        write("�Բ��������á����ġ�ȡ���֡�\n");
                        return 0;
                }
        }
        foreach(tempname in banned_name)
        {
            if(strsrch(name,tempname)!=-1)
            {
                    write("�Բ����������ֻ���������˵����š�\n");
                    return 0;
            }
        }
        return 1;
} 
int check_legal_password(object ob,string pass)
{
        int i;
        int bigletter=0;
        int smlletter=0;
        int number=0;
        string id;
        i = strlen(pass);
        if( strlen(pass) <= 5)
        {
                write("�Բ����������������������ַ���\n");
                return 0;
        }
        id= ob->query("id");    
        if ( strsrch(id, pass) != -1 || strsrch(pass,id) != -1)
        {
        write("�Բ��������������Ӣ������̫���ˡ�\n");
                return 0;
        } 

        while(i--)
        {
                if( pass[i]<='Z' && pass[i] >='A' ) bigletter++;
                if( pass[i]<='z' && pass[i] >='a' ) smlletter++;
        }
        if( bigletter == 0 || smlletter == 0 || 
        bigletter+smlletter == strlen(pass))
        {
                write("����������������д" + HIR"��" + NOR"СдӢ����ĸ"
                          + HIR"��" + NOR"����������ţ����֣���㣩��\n");
        return 0;
        }
        return 1;
} 
object find_body(string name)
{
        object ob, *body; 
        if( objectp(ob = find_player(name)) )
                return ob;
        body = children(USER_OB);
        for(int i=0; i<sizeof(body); i++)
                if( clonep(body[i]) && getuid(body[i]) == name ) return body[i]; 
        return 0;
} 
int set_wizlock(int level)
{
        if( wiz_level(this_player(1)) <= level )
                return 0;
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;
        wiz_lock_level = level;
        return 1;
} 
int set_attribute(object user,int tol, int fle, int agi, int dur,
                                  int intt, int str, int con, int spi, int per,
                                  int cor, int cps, int kar)
{
        user->set("tol",tol);
        user->set("fle",fle);

        user->set("agi",agi);
        user->set("dur",dur);
        user->set("int",intt);
        user->set("str",str);
        user->set("con",con);
        user->set("spi",spi);
        user->set("per",per);
        user->set("cor",cor);
        user->set("cps",cps);
        user->set("kar",kar);
        return 1;
} 
int cphirdir(string dirstr, string newdirstr) {
        string *dir;
        int i;
        dir = get_dir(dirstr+"/");
        if(!mkdir(newdirstr)) write("FAILED\n");
        for(i=0; i<sizeof(dir); i++) {
                if(file_size(dirstr+"/"+dir[i]) == -2 )
                        cphirdir(dirstr +"/"+dir[i],newdirstr+"/"+dir[i]);
                cp(dirstr+"/"+dir[i], newdirstr+"/"+dir[i]);
        }
        return 1;
} 
int set_newuser_lock( int level) {
        new_user_lock = level;
        return level;
}            
