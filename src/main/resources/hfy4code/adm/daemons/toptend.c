// new_toptend.c

#pragma optimize
#pragma save_binary
#define TOPTEN_DIR      "/open/topten"
#include <ansi.h>
#include <dbase.h>
#include <mudlib.h>

inherit F_DBASE;

int get_score(object ob);   // get top score
int rewrite_top();              // ��дtop
int compare_top(object ob); // compare ob

void create()
{
    set("channel_id","Top ����");
    seteuid(geteuid());
}
int get_score(object ob)
{
    /*
	    int tlvl,i,score;
	    string *ski;
	    mapping skills;

	  reset_eval_cost();
	    skills = ob->query_skills();
	    if (!sizeof(skills)) return 1; 
	    ski  = keys(skills);
	    for(i = 0; i<sizeof(ski); i++) {
			    tlvl += skills[ski[i]];
			    }  // count total skill levels
	    score = tlvl/4;
	    score += ob->query("max_neili") / 2;
	    score += ob->query("max_jingli") / 2;
	    score += (ob->query_str() + ob->query_int() + ob->query_dex() + ob->query_con()-80) * 10;
	    score += (int)ob->query("combat_exp") / 250;

    */
    return "/cmds/usr/score.c"->get_score(ob);
}

int rewrite_top()
{
    object *ob;
    int i , T ;
    string msg;
    ob = filter_array(users(), (: !wizardp($1) 
	&& environment($1)
	&& SECURITY_D->get_status($1)!="(immortal)"
      :));
    ob = sort_array(ob, (: get_score($2) - get_score($1) :));
    msg = "";
    T = sizeof(ob);

    for( i = 0 ; i < T ; i++ ) {
	msg += sprintf("%s:%s:%s:%d\n",
	  (string)ob[i]->query("id"),
	  (string)ob[i]->query("name"),
	  ob[i]->query("family")?(string)ob[i]->query("family/family_name"):"��ͨ����",
	  get_score(ob[i]));
    }
    if(write_file(TOPTEN_DIR, msg, 1) != 1) error("Topten : can't rewrite with write_file() .\n");
    CHANNEL_D->do_channel(this_object(),"sys","Top ��д.\n");
    return 1;
}
int compare_top(object ob)
{
    string *msg,aa,bb,cc,*all_name,id;
    mapping top;
    int T, i,dd;
    if( wizardp(ob) ) return 1;
    if( file_size(TOPTEN_DIR) < 1 ) return rewrite_top();
    msg = explode(read_file(TOPTEN_DIR),"\n");
    T = sizeof(msg);
    // �ȶԷ�ʽ�Ҳ���mapping + array�����
    top = allocate_mapping( T+1 );
    id = ob->query("id");   
    // ȡ����ǰ��top
    for(i = 0 ; i < T ; i++ ) {
	if(sscanf(msg[i],"%s:%s:%s:%d",
	    aa,bb,cc,dd
	  ) != 4 ) error("Top : can't sscanf for src top list.\n");
	top[aa] = ({ bb,cc,dd });
    }
    // ��mapping �м���id,�����ǰ����id,��ô���滻
    top[id] = ({
      ob->query("name"),
      ob->query("family")?ob->query("family/family_name"):"��ͨ����",
      get_score(ob)
    });
    all_name = keys(top);
    T = sizeof(all_name);
    if( rm(TOPTEN_DIR) != 1 ) error("Top : can't rm() old topten list.\n");
    for( i = 0 ; i < T ; i++ ) {
	if( write_file(TOPTEN_DIR,sprintf("%s:%s:%s:%d\n",
	      all_name[i],
	      top[all_name[i]][0],
	      top[all_name[i]][1],
	      top[all_name[i]][2])) != 1 )
	    error("Top : can't write_file new topten list.\n");
    }
    return 1;
}

