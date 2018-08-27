//by xiaolang@fy.sumxin.com
#include <ansi.h> 
inherit NPC;
mapping *way;
object cart,F_leader;             
object *protector;
mapping *read_table(string);
void del_marks_mission();          
void give_reward();
void to_rob();
void be_protect();
void create_gangster(object who,string name, int exp); 
void setup()
{
        ::setup();
    set("chat_chance_combat",70);
    set("chat_msg_combat", ({
            (: be_protect :),
            }) );
} 
int accept_fight(object who)
{
	command("say �һ�Ҫ���Ÿ�·��û���й���͸����д����壬��������");
	return 0;
}

int random_move()
{
        mapping exits;
        string *dirs, direction;
        object env;
        
        if( !mapp(exits = environment()->query("exits")) ) return 0;
        
        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        command("go " + direction);
        return 1;
}
//overwrite base npc random_move() function
void go()
{
    int i,j;
    object robber;
    string *cmds;
    remove_call_out("go");
    for(i=0;i<sizeof(way);i++)
    {
        if (base_name(environment()) != way[i]["room_file"]) continue;
        cmds=explode(way[i]["cmd_table"],";");
        break;
    }
    robber=present("killer",environment());
    if (this_object()->is_fighting() || (robber && robber->name()=="ɱ��"))
    {
        command("say ���У������");
        call_out("go",15);
        return;
    }
    if (random(100)<15)
    {
        to_rob();
        call_out("go",15);
        return;
    }
    if (i>=sizeof(way))
    {   
        random_move();
        call_out("go",5);
        return;
    } 
    for(j=0;j<sizeof(cmds);j++)
        command(cmds[j]);
    if (way[i]["delay_time"]<0)
    {
        give_reward();
        return;
    }
    call_out("go",way[i]["delay_time"]);
    return;
}        
void be_protect()
{
    int i,j,flag;
    object *inv,*enemy;
        
    inv=all_inventory(environment());
    enemy=query_enemy();
// if one of the protectors wants to kill... then heis out of the loop
    for(j=0;j<sizeof(enemy);j++)
        enemy[j]->delete_temp("protecting"); 
    for (i=0;i<sizeof(inv);i++)
        if (objectp(cart) && inv[i]->query_temp("protecting")==cart)
        {
            flag=1;
            for(j=0;j<sizeof(enemy);j++)
            {
                inv[i]->kill_ob(enemy[j]);
                enemy[j]->kill_ob(inv[i]);
                enemy[j]->remove_killer(this_object());
                remove_killer(enemy[j]);
            }
        }
    if(!flag) return;
    message_vision(WHT"$N��������������ƴ�ˣ���\n"NOR,this_object());
        
}        
void get_quest(string file)
{   
    way=read_table(file);
}
void to_rob()
{
    int i;
    object robber;
    int exp;
    object *inv;
    
    exp=this_object()->query("combat_exp");
    inv=all_inventory(environment());
// Some players joined team after getting mission.....
    for (i=0;i<sizeof(inv);i++) {
         if (inv[i]->query("combat_exp")>exp) 
                exp = inv[i]->query("combat_exp");
    }
        
    message_vision(HIR"��Ȼ������һȺɱ�֣�\n"NOR,this_object());
    for (i=0;i<=random(5)+1;i++)
    {
        robber=new("/obj/npc/killer");
        robber->move(environment());
        robber->set("combat_exp",exp);
        create_gangster(robber,"killer",exp);
        robber->kill_ob(this_object());
        this_object()->kill_ob(robber);
        robber->set_leader(this_object());
    }
    be_protect();
        
}
        
mapping *read_table(string file)
{
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
void set_protector(object *prot)
{ protector=prot; } 
object *query_protector()
{ return protector; } 
/* void set_cart(object dartcart)
{ cart=dartcart; } 
object query_cart()
{ return cart; } */
void die()
{
    object killer;
    object *pro_team;
    string location,msg;
    int i,j,exp,pots;
        
    location = environment(this_object())->query("short");
    killer=query_temp("last_damage_from");
    
        if (arrayp(protector)) 
        {
            pro_team=({0});
            if (sizeof(pro_team))
            {
                for (i=0;i<sizeof(protector);i++)
                {
                    if (objectp(protector[i])) 
                        pro_team+=({protector[i]});
                }
                if (!sizeof(pro_team))//���ڵ�quit���
                {
                        del_marks_mission();               //ȡ�����������mark
                    ::die();
                    return;
                }
                for(i=0;i<sizeof(pro_team);i++)
                {
                    if (!objectp(pro_team[i])) continue;
                    j=pro_team[i]->query_temp("��������/�Ѷ�");
                    if(j==1) exp = random(300)+500;
        	else if(j==2) exp = random(300)+600;
        	else if(j==3) exp = random(500/3)+800;
        	else if(j==4) exp = random(200)+900;
        	else if( j>=5 && j<=7 ) exp = random(2000/j)+random((j-1)*250);
        	else if(j>7) exp = random(500)+1600+j*50;
        	else exp = 100;
        	pots=exp/6+random(100);
                    if( pro_team[i]->query("organization/����") == "��" ){
                    	pro_team[i]->add("justice",-2*j);
                    	pro_team[i]->add("combat_exp",-exp);
                    	pro_team[i]->add("potential",-pots);
                    	msg="�����";
                    }else if( pro_team[i]->query("organization/����") == "а" ){
                    	pro_team[i]->add("improbity",-2*j);
                    	pro_team[i]->add("combat_exp",-exp);
                    	pro_team[i]->add("potential",-pots);
                    	msg="а��ֵ";
                    }else{
                    	pro_team[i]->add("score",-2*j);
                    	pro_team[i]->add("combat_exp",-exp);
                    	pro_team[i]->add("potential",-pots);
                    	msg="����";
                    }
                    tell_object(pro_team[i],HIW"�������ʧ���ˣ���ʧȥ�ˣ�\n"+chinese_number(exp)+"��ʵս����\n"+chinese_number(pots)+"��Ǳ��\n"+chinese_number(2*j)+"��"+msg+"��\n"NOR);
                    pro_team[i]->delete_temp("��������/�Ѷ�");
                    pro_team[i]->set("����ʧ��/timer",time());
                    pro_team[i]->save();
                }               
            }
        }
        if (objectp(killer))
        {
        CHANNEL_D->do_sys_channel(
                "info",sprintf("%s��%s��%s��%s��ɱ��", NATURE_D->game_time(),
                this_object()->name(),location,killer->name()) );  
             j=killer->query_temp("��������/�Ѷ�");
                    if(j==1) exp = random(300)+500;
        	else if(j==2) exp = random(300)+600;
        	else if(j==3) exp = random(500/3)+800;
        	else if(j==4) exp = random(200)+900;
        	else if( j>=5 && j<=7 ) exp = random(2000/j)+random((j-1)*250);
        	else if(j>7) exp = random(500)+1600+j*50;
        	else exp = 100;
        	pots=exp/6+random(100);
             if( killer->query("organization/����") == "��" ){
                    	killer->add("justice",-2*j);
                    	killer->add("combat_exp",-exp);
                    	killer->add("potential",-pots);
                    	msg="�����";
              }else if( killer->query("organization/����") == "а" ){
                    	killer->add("improbity",-2*j);
                    	killer->add("combat_exp",-exp);
                    	killer->add("potential",-pots);
                    	msg="а��ֵ";
              }else{
                    	killer->add("score",-2*j);
                    	killer->add("combat_exp",-exp);
                    	killer->add("potential",-pots);
                    	msg="����";
              }
             tell_object(killer,HIW"�������ʧ���ˣ���ʧȥ�ˣ�\n"+chinese_number(exp)+"��ʵս����\n"+chinese_number(pots)+"��Ǳ��\n"+chinese_number(2*j)+"��"+msg+"��\n"NOR);
             killer->delete_temp("��������/�Ѷ�");
             killer->set("����ʧ��/timer",time());
             killer->save();
        }

        del_marks_mission();               //ȡ�����������mark
    ::die();
} 
void give_reward()
{   
    object *pro_team,me;
    int values,i,reward,j; 
    string reward_msg,msg;
                
    reward=0;
    reward_msg ="";
    msg="";
    me=this_player();
    
    if (arrayp(protector)) 
    {
        pro_team=protector;
        if (sizeof(pro_team))
        {
            for(i=0;i<sizeof(pro_team);i++)
            {
            	j=pro_team[0]->query_temp("��������/�Ѷ�");
            }
        	values = j;
        	if(j==1) reward = random(300)+500;
        	else if(j==2) reward = random(300)+600;
        	else if(j==3) reward = random(500/3)+800;
        	else if(j==4) reward = random(200)+900;
        	else if( j>=5 && j<=7 ) reward = random(2000/j)+random((j-1)*250);
        	else if(j>7) reward = random(500)+1600+j*50;
        	else reward = 100;
            values/=sizeof(pro_team);
            reward/=sizeof(pro_team);
            for(i=0;i<sizeof(pro_team);i++)
            {
                if (!objectp(pro_team[i])) continue;
                if(!intp(pro_team[i]->query("deposit")))
                    pro_team[i]->set("deposit",0);
                pro_team[i]->add("deposit",values*10000);
                pro_team[i]->add("combat_exp",reward);
                pro_team[i]->add("potential",reward/6+random(reward/100));
                if( pro_team[i]->query("organization/����") == "��" ){
                	pro_team[i]->add("justice",j);       //�Ժ������޸�Ϊ������ֵ
//                	msg="�����";
                }else if( pro_team[i]->query("organization/����") == "а" ){
                	pro_team[i]->add("improbity",j);      //�Ժ������޸�Ϊ��а��ֵ
//                	msg="а��ֵ";
                }
                else {
                	pro_team[i]->add("score",j);          //�Ժ������޸�Ϊ������ֵ��������
//                	msg="����";
                }  
                
/*        reward_msg +=HIW+"��ɹ�������˻��������㱻�����ˣ�\n\t\t" +
        chinese_number(reward) + "��ʵս����\n\t\t"+
        chinese_number(reward/10) + "��Ǳ��\n\t\t" +
//        chinese_number(10) + "��"+msg+"\n\t\t" + 
        chinese_number(10) + "���ƽ�\n" + NOR;
        tell_object(pro_team[i],reward_msg);   */
        	pro_team[i]->delete_temp("��������/�Ѷ�");
                pro_team[i]->save();
            }
        }
    } 
        del_marks_mission();               //ȡ�����������mark
    destruct(this_object());
        
    return;
} 
void del_marks_mission()
{
	
	if( this_object()->query("organization/����") == "��" )
	{
		F_leader = find_living("shanliu manager");
        	if(environment(F_leader))
        	{
                	F_leader->delete("��������/gived");
        	}
        }
        else if( this_object()->query("organization/����") == "а" )
        {
		F_leader = find_living("huo xiu");
        	if(environment(F_leader))
        	{
                	F_leader->delete("��������/gived");
        	}
        }
        else {
        	F_leader = find_living("tester");
        	if(environment(F_leader))
        	{
                	F_leader->delete("��������/gived");
        	}
        }
                	
}
//end 
void go_now()
{
    call_out("go",10);
}  
void create_gangster(object who,string name, int exp)
{
        int level;
        level=100+130*(exp-1000000)/5500000;
        if (exp<1000000) level=100;
        if (exp>6400000) level=230;
        level=level*level/100;
        if (name=="importman") {
                who->set("str",10+random(level/15));
                who->set("agi",10+random(level/8));
                who->set("cor",20+random(15));
                who->set("max_kee",1000+random(level*level/20));
                who->set("eff_kee",who->query("max_kee"));
                who->set("kee",who->query("max_kee"));
                who->set_skill("hammer", 70 + random(level*2/3));
                who->set_skill("parry", 70 + random(level*2/3));
                who->set_skill("dodge", 70 + random(level*2/3));
                who->set_skill("move", 70 + random(level*2/3));
                who->set_skill("changquan",50+random(level*2/3));
                who->set_skill("unarmed",70 + random(level*2/3));
        }
        if (name=="killer") {
                who->set("str",20+random(level/12));
                who->set("agi",10+random(level/8));
                who->set("cor",20+random(15));
                who->set("max_kee",2500+random(level*level/40));
                who->set("eff_kee",who->query("max_kee"));
                who->set("kee",who->query("max_kee"));
                who->set("max_sen",who->query("max_kee")/2);
                who->set("max_gin",who->query("max_kee")/2);
                who->set("eff_sen",who->query("max_sen"));
                who->set("sen",who->query("max_sen"));
                who->set("eff_gin",who->query("max_gin"));
                who->set("gin",who->query("max_gin"));
                who->set_skill("parry", 100 + random(level/2));
                who->set_skill("dodge", 100 + random(level/2));
                who->set_skill("move", 100 + random(level/2));
                who->set_skill("blade",100+random(level/2));
                who->set_skill("fall-steps",100+random(level/2));
                who->set_skill("unarmed",100+ random(level/2));
                who->set_skill("yue-strike",100+random(level/8));
                who->set_skill("shortsong-blade",100+random(level/8));
                who->set("max_force",2000+random(level*level/40));
                who->set("force",who->query("max_force"));
                who->set("force_factor",80+random(level/8));
        } 
}
