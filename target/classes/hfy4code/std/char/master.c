#include <dbase.h>
#include <login.h>
#include <ansi.h> 
int prevent_learn(object me, string skill)
{
    mapping my_family, family;
    int betrayer, mylvl, lvl; 
    lvl = this_object()->query_skill(skill, 1);
    mylvl = me->query_skill(skill, 1);
    if( betrayer = me->query("betrayer") )
    {
        if( mylvl >= lvl - betrayer * 20 )
        {
            message_vision("$N神色间似乎对$n不是十分信任，\n"
                           "也许是想起$p从前背叛师门的事情\n...。\n",
                           this_object(), me );
            command("say 嗯 .... \n师父能教你的都教了，其他的你自己练吧。");
            return 1;
        }
    } 
    if( !me->is_apprentice_of(this_object()))
    {
        if( !mapp(my_family = me->query("family")) )  return 0;
        if( !mapp(family = this_object()->query("family")) ) return 0;
        if((my_family["family_name"] == family["family_name"]) )
        {
            command("hmm");
            command("pat " + me->query("id"));
            command("say 虽然你我同门，可是你并非我的弟子，"
                    "你还是去找你师父学吧....");
            return 1;
        }
    } 
    return 0;
}  
string std_rank_title(object student)
{
    int exp,i,gen;
    string* ranks;
    int * rank_levels;
    string title; 
    ranks=query("ranks");
    rank_levels=query("rank_levels");
    if(!arrayp(rank_levels))
        rank_levels= ({32000,64000,512000,1536000,3456000,
                       5187000,26244000});
    
    if(!arrayp(ranks) || sizeof(rank_levels)+1 != sizeof(ranks))
    {
        if(!title = query("student_title"))
            title = "弟子";
    }        
    else
    {
        exp = (int) student->query("combat_exp");
        for(i=0;i<sizeof(rank_levels);i++)
            if(exp < rank_levels[i]) break;
        title=ranks[i];
    }
    // if(!stringp(ranks[i])) title=?
    return title;
} 
void re_rank(object student)
{
    int exp;
    
    student->assign_title(std_rank_title(student),
                          query("rank_nogen"));
} 
int recruit_apprentice(object ob)
{
    mapping my_family, family;
    if( ob->is_apprentice_of( this_object() ) ) return 0;
    if( !mapp(my_family = query("family")) ) return 0;
    family = allocate_mapping(sizeof(my_family));
    family["master_id"] = query("id");
    family["master_name"] = query("name");
    family["family_name"] = my_family["family_name"];
    family["generation"] = my_family["generation"] + 1;
    family["enter_time"] = time();
    // privs = 0 for general 
    family["privs"] = 0;
    ob->set("family", family);
    ob->set("class", query("class"));
    re_rank(ob);
    return 1;
}    
