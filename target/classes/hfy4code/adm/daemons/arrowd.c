// arrowd.c
// by xxs

#include <ansi.h>

varargs int other_vision(string str,object who,object arrow,string dir,object bow);
varargs int me_vision(string str,object who,object aroow,string dir,object bow);

varargs int shoot_at_vision(object shooter,object victim,object arrow,string dir,object bow);
varargs int shoot_vision(object shooter,object victim,object arrow,string dir,object bow);
varargs int miss_shoot_vision(object shooter,object victim,object arrow,string dir,object bow);

void create() { seteuid(getuid()); }

varargs int shoot_at_vision(object shooter,object victim,object arrow,string dir,object bow)
{
string default_victim_vision="ֻ����ವ�һ��,$num$unit$arrow��$dir����,ֱ��$N������";
int arrow_shoot_out=0;
mapping action;
string anti_dir,*act_key;
string shoot_action,victim_vision;
object arrow_out;
string skill,mapskill;
skill="arrow";
anti_dir=ROOM_D->anti_dir(dir);

while(arrow_shoot_out==0 || arrow_shoot_out>arrow->query_amount())
        {
        if(stringp(mapskill=shooter->query_skill_mapped(skill)))
                {
                action=SKILL_D(mapskill)->query_action(shooter,arrow);
                }
        else    {
                action=arrow->query("actions");
                }
act_key=keys(action);
        if(!undefinedp(action["arrows"]))
                arrow_shoot_out=action["arrows"];
        else    arrow_shoot_out=1;
        if(!arrow_shoot_out)
                arrow_shoot_out=1;
        }

shoot_action=action["action"];
if(!undefinedp(action["dir_action"]))
        victim_vision=action["dir_action"];
else    victim_vision=default_victim_vision;

arrow_out=new(base_name(arrow));
arrow_out->set_amount(arrow_shoot_out);
if(bow)
        {
        me_vision(shoot_action,shooter,arrow_out,dir,bow);
        other_vision(shoot_action,shooter,arrow_out,dir,bow);
        me_vision(victim_vision,victim,arrow_out,anti_dir,bow);
        other_vision(victim_vision,victim,arrow_out,anti_dir,bow);
        }
else    {
        me_vision(shoot_action,shooter,arrow_out,dir);
        other_vision(shoot_action,shooter,arrow_out,dir);
        me_vision(victim_vision,victim,arrow_out,anti_dir);
        other_vision(victim_vision,victim,arrow_out,anti_dir);
        }       
destruct(arrow_out);
return arrow_shoot_out;
}

varargs int shoot_vision(object shooter,object victim,object arrow,string dir,object bow)
{
string shoot_action="$arrow�ɳ�,ֻ������$dir����һ���ҽ�,�����������Ŀ��!";
string victim_vision="$num$unit$arrow����$N!";
int damage,wound,arrow_amount;
string anti_dir=ROOM_D->anti_dir(dir);
if(arrow->query("base_weight"))
wound=arrow->query_amount()*arrow->query("weapon_prop/damage");
else wound=arrow->query("weapon_prop/damage");
damage=wound+shooter->query("jiali");

if(bow)
        {
        me_vision(shoot_action,shooter,arrow,dir,bow);
        other_vision(shoot_action,shooter,arrow,dir,bow);
        me_vision(victim_vision,victim,arrow,anti_dir,bow);
        other_vision(victim_vision,victim,arrow,anti_dir,bow);
        }
else    {
        me_vision(shoot_action,shooter,arrow,dir);
        other_vision(shoot_action,shooter,arrow,dir);
        me_vision(victim_vision,victim,arrow,anti_dir);
        other_vision(victim_vision,victim,arrow,anti_dir);
        }       

message_vision(COMBAT_D->damage_msg(damage,"�˺�")+"\n",victim);
message_vision("$N"+COMBAT_D->eff_status_msg(100*(victim->query("eff_qi")-wound)/victim->query("max_qi"))+"\n",victim);

return 1;
}

varargs int miss_shoot_vision(object shooter,object victim,object arrow,string dir,object bow)
{
string shoot_action="$arrow���ꡱ��һ����ƫ�ˣ���֪���ɵ�����ȥ�ˡ�";
string victim_vision;
string skill="dodge",dodge_msg;
victim->set_temp("miss_vision",(: call_other, SKILL_D(skill), "query_dodge_msg":));
victim_vision=victim->query_temp("miss_vision");
if(bow)
        {
        me_vision(shoot_action,shooter,arrow,dir,bow);
        other_vision(shoot_action,shooter,arrow,dir,bow);
        }
else    {
        me_vision(shoot_action,shooter,arrow,dir);
        other_vision(shoot_action,shooter,arrow,dir);
        }
return 1;
}       

varargs int me_vision(string str,object who,object arrow,string dir,object bow)
{
str=replace_string(str,"$N","��");
str=replace_string(str,"$arrow",arrow->query("name"));
str=replace_string(str,"$num",chinese_number(arrow->query_amount()));
str=replace_string(str,"$unit",arrow->query("base_unit")); 
if(dir)
        str=replace_string(str,"$dir",ROOM_D->dir_chinese(dir));
if(bow)
        str=replace_string(str,"$bow",bow->query("name"));
tell_object(who,str+"\n");
return 1;
}

varargs int other_vision(string str,object who,object arrow,string dir,object bow)
{
str=replace_string(str,"$N",who->query("name"));
str=replace_string(str,"$arrow",arrow->query("name"));
str=replace_string(str,"$num",chinese_number(arrow->query_amount()));
str=replace_string(str,"$unit",arrow->query("base_unit")); 
if(dir)
        str=replace_string(str,"$dir",ROOM_D->dir_chinese(dir));
if(bow)
        str=replace_string(str,"$bow",bow->query("name"));
tell_room(environment(who),str+"\n",who);
return 1;
}
