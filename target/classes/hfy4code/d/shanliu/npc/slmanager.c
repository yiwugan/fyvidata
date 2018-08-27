//by xiaolang
inherit NPC;
#include <ansi.h> 
int test_dart();
void create_level(object who,string name, int exp); 
void create()
{
    set_name("���ܹ�", ({ "shanliu manager" }) );
    set("gender", "����" );
    set("age", 32);
    set("force",500);
    set("title","ɽ��");
    set("force_factor",20);
    set("max_force",500);    
    set("inquiry",      ([
        "mission" : (: test_dart :),
        ]) );
    set("int", 30);
    set("long",
        "û����֪�����ܹܵ���ʵ���֣����һ�㶼�����ܹܣ�\n���������ǳ���ƽ����ͨ����ȴ�ǳ�������\n"
        );
    set("chat_chance", 2);
    set("chat_msg", ({
            }) );
    
    set_skill("unarmed", 400);
    set_skill("dabei-strike", 400);
    set_skill("literate", 400);
    set_skill("force", 400);
    set_skill("dodge",400);
    set_skill("parry",400);
    set_skill("move",400);
    set_skill("hammer",400);
    set_skill("xiaochengforce",400);
    set_skill("liuxing-hammer",400);
    set_skill("puti-steps",400);

    map_skill("force", "xiaochengforce");    
    map_skill("unarmed", "dabei-strike");
    map_skill("dodge","puti-steps");
    map_skill("move","puti-steps");
    map_skill("hammer","liuxing-hammer");
    
    set("combat_exp", 35000000);
    setup();
    carry_object("/obj/armor/cloth")->wear();
//    carry_object("/d/taishan/npc/obj/hxshoes")->wear();
} 
void init()
{
        ::init();
//        add_action("do_accept", "accept");
} 
int test_dart()
{
    object me;
        
    me=this_player();
    if(me->query("organization/����") != "��")
    {
    	command("say �㲻��������֯�ģ�����ô�����㣿\n");
    	return 1;
    }

    if(me->query("����ʧ��/timer")+180>time())
    {
    	command("say ��ջ���ʧ�ܲ��á�\n");
    	return 1;
    }
    if(me->query("justice")>= 100)
    {
    	command("say ���Ѿ����ĺܲ����ˣ��ɵ�����ȥ�ɡ�\n");
    	return 1;
    }
    	
    if (query("��������/gived") )
    {
        set("��������/gived",1);
        command("say �������ﻹû����Ҫ�Ļ�������");
        return 1;
    }
    command("say ������һ����Ҫ������ҪȥĿ�ĵأ����Ƿ�Ը�⣿(accept mission)");
//    add_action("do_accept","accept");
    return 1;
} 
int do_accept(string arg)
{    
    object ob,cart,biaotou;
    object me,*team;
    string location,msg;
    int i, exp,n; 
    
    msg="";
    if (arg != "mission") return 0;
    me=this_player();
    team=me->query_team();
    if (sizeof(team)==0) team=({me}); 
   if (sizeof(team) != 0 && (team[0]!=me)) 
        return notify_fail("say ֻ�ж���������������������\n");
    for (i=0;i<sizeof(team);i++)
    {
    	if(team[i]->query("����ʧ��/timer")+180>time())
    		return notify_fail("����鵱�����˸ջ���ʧ�ܲ��á�\n");
    	}
    	
    for (i=0;i<sizeof(team);i++)
    {
//    	team[i]->set_temp("��������/�Ѷ�",1);
        if (team[i]->query("combat_exp")<15000000)
        {
            command("say ����·;Σ�գ��ҿ���λ"+RANK_D->query_respect(team[i])+"�ƺ����ˣ�");
            return 1;
        }
/*        if (!intp(team[i]->query("deposit")) || team[i]->query("deposit")<1000000)
        {
            command("say ������Σ�յ��£��ҿ�"+RANK_D->query_respect(team[i])+"û���⳥������");
            return 1;
        }  */
        if(team[i]->query("organization/����") != "��"){
        	command("heng");
        	command("say ������������������������²��ˡ�\n");
        	return 1;        	
        }
        if(team[i]->query("justice") >= 100){
        	command("smile");
        	command("say ��������Ѿ��������ĺܲ����ˣ�����Ҫ���������ˣ������ɵ���ȥ�ɡ�\n");
        	return 1;
        }
        
        if (team[i]->query("combat_exp")>exp)
                exp= team[i]->query("combat_exp");
    } 
    

        if (query("��������/gived"))
                {
                 command("say �������ˣ��Ѿ����˽�����������ˡ�");
                 return 1;
                }

    set("��������/gived",1);
    command("say һ·С�ġ�");
    location = environment(me)->query("short");        
    biaotou=new("/obj/npc/importman");
    biaotou->move(environment());
    n=random(3);
    switch( n ) {
    	case 0:
//    		biaotou->get_quest("/d/taishan/way/way1_ts_to_lyz");
    		msg = "ǰ������կ";
    		break;
    	case 1:
//    		biaotou->get_quest("/d/taishan/way/way2_ts_to_qp");
    		msg = "ǰ����ƽɽׯ";
    		break;
    	case 2:
//    		biaotou->get_quest("/d/taishan/way/way3_ts_to_fy");
    		msg = "ǰ�����Ƴǽ�Ǯ��";
    		break;
    }
    for (i=0;i<sizeof(team);i++)
    {
    	team[i]->set_temp("��������/�Ѷ�",n+1);
    }		
    biaotou->set_protector(team);
    biaotou->set("combat_exp",exp*3/5);
    create_level(biaotou,"importman",exp*3/5);
    
    CHANNEL_D->do_sys_channel(
                "info",sprintf("%s��%s����һ����Ҫ�����%s����%s��", NATURE_D->game_time(),
                me->query("name"),location,msg) );     

    me->set_leader(biaotou);
    me->set_temp("��������/accepted",1);
    biaotou->go_now();
    return 1;   
} 
void reset()
{
    delete("��������/gived");
}  
void create_level(object who,string name, int exp)
{
        int level;
        level=100+130*(exp-1000000)/6500000;
        if (exp<1000000) level=100;
        if (exp>7500000) level=200;
        level=level*level/100;
        if (name=="importman") {
                
                who->command("say �Ҿ����Ǹ�������Ա��·�϶���չˡ�");
                who->set("str",10+random(level/15));
                who->set("agi",10+random(level/8));
           	who->set("cor",20+random(15));
//                who->set("max_kee",1000+random(level*level/20));
//                who->set("eff_kee",who->query("max_kee"));
//                who->set("kee",who->query("max_kee"));
                who->set_skill("blade", 100 + random(level*2/3));
                who->set_skill("parry", 100 + random(level*2/3));
                who->set_skill("dodge", 100 + random(level*2/3));
                who->set_skill("demon-steps",100+random(level*2/3));
                who->set_skill("move", 100 + random(level*2/3));
                who->set_skill("moon-blade",100+random(level*2/3));
                who->set_skill("unarmed",100 + random(level*2/3));
        }
        if (name=="killer") {
                who->set("str",10+random(level/12));
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
                who->set_skill("parry", 70 + random(level/2));
                who->set_skill("dodge", 70 + random(level/2));
                who->set_skill("move", 70 + random(level/2));
                who->set_skill("blade",70+random(level/2));
                who->set_skill("fall-steps",70+random(level/2));
                who->set_skill("unarmed",70+ random(level/2));
                who->set_skill("yue-strike",50+random(level/8));
                who->set_skill("shortsong-blade",50+random(level/8));
        } 
}   
