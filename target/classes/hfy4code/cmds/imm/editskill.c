#include <ansi.h>
inherit F_CLEAN_UP;
#define SHUANGYIN_HAO "\""
#define HEADER_END 16
#define SPE_PRA_LINES 53
 string *valid_types = ({
	"unarmed",
	"sword",
	"blade",
});
string *banned_name=({
          "  ",});
string *spe_skill_lvl=({
            "0","12","20","30","40","50","60","80","100",});
 string *spe_skill_force=({
                "50","80","100","130","150","180","200","220",
                   });
string *spe_skill_unarmeddodge=({
             "10","15","20","25","30","40","50","80","100",
                   });
 string *spe_skill_unarmedparry=({
            "10","15","20","30","40","50","60","70","80",
                   });
 string *spe_skill_weapondodge=({
             "20","10","10","5","-5","-5","-10","-10","-10",
                   });
 string *spe_skill_weaponparry=({
            "20","20","10","10","5","5","5","5","5",
                   });
 mapping spe_skill = ([
   "action" : ({" "}),
     "damage" : ({"10"}),
    "dodge" : ({"10"}),
    "parry": ({"10"}),
    "damage_type" : ({"瘀伤"}),
    "lvl" : ({"10"}),
    "skill_name" : ({"横空出世"}),
    "skill_total_num" : ({"0"}),
    "skill_en_name" : ({" "}),
    "skill_ch_name" : ({" "}),
   ]);
 int spe_skillnum;
 string spe_skill_name;
 string spe_skill_basename;
int check_legal_id(string id);
int check_legal_name(string name);
int check_legal_basename(string name);
void skill_init_header(string skill_en_name,string skill_ch_name);
void get_zhaoshi_ch_name(string yn, object ob);
void get_zhaoshi_ch_action(string yn, object ob);
int check_skillnum_exist(object me,string skill_en_name,int skill_num);
void finish_write_skill(object ob);
int check_owner_skill(object me,string skill_en_name);
string get_header_skillchname(string file);
string get_header_skillbasename(string file);
int main(object me, string arg)
{
int skill_num,skill_num_result;
string skill_en_name,skill_ch_name,myskill;
string skill_base_name;
spe_skill_basename="";
spe_skill_name="";
spe_skillnum=0;
if(!arg)
    return notify_fail(WHT"指令格式：editskill 基本技能 武功英文名字 武功中文名字 第几招\n"NOR);
if( sscanf(arg, "%s %s %s %d", skill_base_name,skill_en_name,skill_ch_name,skill_num)!=4)
    return notify_fail(WHT"指令格式：editskill 基本技能 武功英文名字 武功中文名字 第几招\n"NOR);
skill_en_name=lower_case(skill_en_name);
spe_skill_basename=skill_base_name;
if(check_legal_basename(skill_base_name)==0)
    return notify_fail(RED"你输入的基本技能不存在。\n"NOR);
if(check_legal_id(skill_en_name)==0)
               return 1;             
spe_skill["skill_en_name"]=skill_en_name+"-"+skill_base_name+".c";
spe_skill_name=skill_en_name+"-"+skill_base_name;
if(check_legal_name(skill_ch_name)==0)
               return 1;             
spe_skill["skill_ch_name"]=skill_ch_name;
if( skill_num!=1 
    && get_header_skillchname(spe_skill["skill_en_name"])!=skill_ch_name)
    return notify_fail(HIR"你输入的中文武功名称和所选的英文武功代号有矛盾。\n"NOR);
if( skill_num!=1 
    && get_header_skillbasename(spe_skill["skill_en_name"])!=skill_base_name)
    return notify_fail(HIR"你输入的基本技能名和所选的英文武功代号有矛盾。\n"NOR);
if((int)me->query("skillmaxim")!=0
        && sizeof(keys(me->query("skillmaxim/"))) >3 )
    return notify_fail(HIR"你最多只能自创三种武功。\n"NOR);

switch(check_owner_skill(me,spe_skill["skill_en_name"])){
        case 2:
    return notify_fail(HIR"这个功夫在风云中已经存在，你没有办法再创新。\n"NOR);
       break;
        case 0: 
         break;
        case 1:
    return notify_fail(HIR"你目前只能针对这个基本技能创建一个功夫。\n"NOR);
        default:
        return notify_fail(HIR"请和长孙无情联系，所创功夫不对。\n"NOR);
    }
if(skill_num < 1)
       return notify_fail(HIR"你需要从第一招开始创建。\n"NOR);
if((int)me->query("combat_exp") < (skill_num)*1000000+6000000)
       return notify_fail(HIR"你的经验还不够，不能自创武功了。\n"NOR);
if((int)me->query("score") < 20000 && skill_num == 1)
       return notify_fail(HIR"你的评价还不够，不能自创武功了。\n"NOR);
if(//(int)me->query_skill(spe_skill_name)!=0  &&
      (int)me->query_skill(spe_skill_name) < (skill_num-1)*10)
       return notify_fail(HIR"你的招式还不够熟练，现提高它们，然后在想新招吧。\n"NOR);
skill_num_result=(check_skillnum_exist(me,spe_skill["skill_en_name"],skill_num));
if(skill_num_result > 1) {
      write(HIW"\r给招式起个名字(不要此时断线，否则永远无法再正确创建):"NOR);
                   }
else if(skill_num_result==1) {
      write(HIG"你现在开始创建"+skill_ch_name+"("+spe_skill_name+")"NOR+HIG"的第一招.\n"NOR);
      write(HIW"\r给招式起个名字(不要此时断线，否则永远无法再正确创建):"NOR);
                         }
else 
        return notify_fail(HIR"你所要创建招式数可能已经成功，请与长孙无情联系，或者尝试创建另外一招。\n"NOR);
spe_skillnum=skill_num;
if(skill_num==1) {
             rm(SKILL_D(spe_skill["skill_en_name"]));
             skill_init_header(spe_skill["skill_en_name"],skill_ch_name);
                      }
input_to( (: get_zhaoshi_ch_name :), this_player() );
return 1;
}
string get_header_skillchname(string file)
{
string result;
string content,*list;
content=read_file(SKILL_D(file));
if((int)content==0)
       return 0;
list = explode(content, "\n");
if(sizeof(list) < 8)
     return 0;
else {
    if(sscanf(list[7],"// %s",result)!=1) 
               return 0;
    else 
         return result;
  }
return 0;
}
string get_header_skillbasename(string file)
{
string result;
string content,*list;
content=read_file(SKILL_D(file));
if((int)content==0)
 return 0;
list = explode(content, "\n");
if(sizeof(list) < 7)
 return 0;
else {
    if(sscanf(list[6],"// %s",result)!=1) 
               return 0;
    else 
         return result;
  }
return 0;
}
void skill_init_header(string skill_en_name,string skill_ch_name)
{
string header;
object me;
int i;
string result;
result="";
me=this_player();
header="";

header="// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改\n";
header+="// "+geteuid(me)+"\n";
header+="// "+me->query("name")+"\n";
header+="// "+me->query("title")+"\n";
header+="// "+me->query("combat_exp")+"\n";
header+="// "+me->query("gender")+"\n";
header+="// "+spe_skill_basename+"\n";                  //list[6]
header+="// "+spe_skill["skill_ch_name"]+"\n"; //list[7]
for(i=10;i<15;i++)
    header+="\n";
write_file(SKILL_D(skill_en_name),header);
write_file(SKILL_D(skill_en_name),"inherit SKILL;\n");
write_file(SKILL_D(skill_en_name),"\n////////////////////////////////\n");
write_file(SKILL_D(skill_en_name),"\nmapping *action = ({\n");
write_file(SKILL_D(skill_en_name),"\n"+"// ZHAOSHI : 0");
}
void get_zhaoshi_ch_name(string yn, object ob)
{
 if( yn=="" ) {
      write(HIW"\r请给招式起个名字(不要此时断线，否则永远无法在正确创建):"NOR);
        input_to( (: get_zhaoshi_ch_name :), ob );
        return;
       }
 if( !check_legal_name(yn) ) {
        write("招式名称：");
        input_to( (: get_zhaoshi_ch_name :), ob );
        return;
           }
  spe_skill["skill_name"]=yn;
write(WHT"\n想象一下你和某人的战斗，指南:必须要有["+HIR+"你、某人、某部位"NOR+WHT"]的字样出现!");
write("\n如果是sword或blade请加入["HIR"武器"NOR+WHT"]字样。以下是举例。");
write(HIG"\n拳法示例："NOR+WHT"你前腿踢出，后腿脚尖点地，一式「出世」，二掌直出，攻向某人的某部位\n");
write(HIG"武器类例："NOR+WHT"你纵身一跃，手中武器一招「金光泻地」对准的某部位斜斜刺出一剑\n"NOR);
  input_to("get_zhaoshi_ch_action", 1, ob);
}
void get_zhaoshi_ch_action(string yn, object ob)
{
 if( yn=="" ) {
write(WHT"\n想象一下你和某人的战斗，指南:必须要有["+HIR+"你、某人、某部位"NOR+WHT"]的字样出现!");
write("\n如果是sword或blade请加入["HIR"武器"NOR+WHT"]字样。以下是举例。");
write(HIG"\n拳法示例："NOR+WHT"你前腿踢出，后腿脚尖点地，一式「出世」，二掌直出，攻向某人的某部位\n");
write(HIG"武器类例："NOR+WHT"你纵身一跃，手中武器一招「金光泻地」对准的某部位斜斜刺出一剑\n"NOR);
 input_to( (: get_zhaoshi_ch_action :), ob );
 return;
 }
  spe_skill["action"]=yn;
 finish_write_skill(ob);
ob->set("skillmaxim/"+spe_skill_basename,1);
 ob->set("myskill",spe_skillnum);
if(spe_skillnum==1) {
      ob->set_skill(spe_skill_name,1);
      ob->add("score",-20000);
       }
 log_file( "CREATESKILL", sprintf("%s(%s) %s(%s): %d (%s)\n",
 ob->query("name"),
 ob->query("id"),
  spe_skill["skill_ch_name"],
 spe_skill_name,
  spe_skillnum,
  ctime(time()) ) );
CHINESE_D->add_translate(spe_skill_name,spe_skill["skill_ch_name"]);
}
void finish_write_skill(object ob)
{
string action;
string file,*list;
string content;
int before_skillnum,i;
string *list2;
string header2;
string result;
header2="";
result="";
content="";
action="";
spe_skill["force"]=spe_skill_force[spe_skillnum-1];
switch(spe_skill_basename){
  case "unarmed":
spe_skill["damage_type"]="瘀伤";
  break;
  case "sword":
spe_skill["damage_type"]="刺伤";
  break;
  case "blade":
spe_skill["damage_type"]="割伤";
  break;
 default:
spe_skill["damage_type"]="瘀伤";
  break;
 }
if(spe_skill_basename=="unarmed"
 ) {
spe_skill["dodge"]=spe_skill_unarmeddodge[spe_skillnum-1];
spe_skill["parry"]=spe_skill_unarmedparry[spe_skillnum-1];
 }
else if(spe_skill_basename=="sword"
 || spe_skill_basename=="blade"
          ){
spe_skill["dodge"]=spe_skill_weapondodge[spe_skillnum-1];
spe_skill["parry"]=spe_skill_weaponparry[spe_skillnum-1];
     }
else {
spe_skill["dodge"]=spe_skill_weapondodge[spe_skillnum-1];
spe_skill["parry"]=spe_skill_weaponparry[spe_skillnum-1];
  }
spe_skill["lvl"]=spe_skill_lvl[spe_skillnum-1];
 spe_skill["action"]= replace_string(spe_skill["action"], "你","$N");
  spe_skill["action"]= replace_string(spe_skill["action"], "某人","$n");               
  spe_skill["action"]= replace_string(spe_skill["action"], "某部位","$l");              
if(spe_skill_basename=="sword"
         || spe_skill_basename=="blade"
      ) 
  spe_skill["action"]= replace_string(spe_skill["action"], "武器","$w");
action="\n([\n"
             +SHUANGYIN_HAO
           +"action"+SHUANGYIN_HAO
            +" :"
           +SHUANGYIN_HAO+
             spe_skill["action"]
            +SHUANGYIN_HAO
             +",\n"+
 SHUANGYIN_HAO+
  "damage"+SHUANGYIN_HAO+" :"+ spe_skill["force"]+",\n"+
 SHUANGYIN_HAO+
  "dodge"+SHUANGYIN_HAO+" :"+ spe_skill["dodge"]+",\n"+
 SHUANGYIN_HAO+
   "parry"+SHUANGYIN_HAO+" :"+ spe_skill["parry"]+",\n"+
 SHUANGYIN_HAO+
 "damage_type" +SHUANGYIN_HAO+": "+SHUANGYIN_HAO+spe_skill["damage_type"]+
       SHUANGYIN_HAO+",\n"+
 SHUANGYIN_HAO+
 "skill_name"+SHUANGYIN_HAO+" : "+SHUANGYIN_HAO+spe_skill["skill_name"]+
   SHUANGYIN_HAO 
   +"\n]),"
   +"\n });"
   +"\n// ZHAOSHI :"+spe_skillnum;
file=read_file(SKILL_D(spe_skill["skill_en_name"]));
if((int)file!=0)
    list = explode(file, "\n");
if(spe_skill_basename=="unarmed" 
       )
    header2=read_file(SKILL_MODEL_UNARMED);
else if(spe_skill_basename=="sword" 
         || spe_skill_basename=="blade"
          )
    header2=read_file(SKILL_MODEL_WEAPON);
else 
    header2=read_file(SKILL_MODEL_DEFAULT);

list2 = explode(header2, "\n");
for(i=0;i < sizeof(list2);i++) {
         list2[i]= replace_string(list2[i], "SKILL_EN_NAME", 
              SHUANGYIN_HAO+spe_skill_name+SHUANGYIN_HAO );
         list2[i]= replace_string(list2[i], "SKILL_CH_NAME", 
                SHUANGYIN_HAO+spe_skill["skill_ch_name"]+SHUANGYIN_HAO );
         list2[i]= replace_string(list2[i], "SKILL_BASE_NAME", 
              SHUANGYIN_HAO+spe_skill_basename+SHUANGYIN_HAO );
               }
for(i=0;i < sizeof(list2);i++) {
          result+=list2[i]+"\n";
        }
  if(spe_skillnum==1) {
      if(sscanf(list[sizeof(list)-1],"// ZHAOSHI :%d",before_skillnum)!=1){
             write(HIR"可能出现异常了，如不能解决请通知长孙无情。\n"NOR);
            return;
           }
       }
  else {
  if(sscanf(list[sizeof(list)-1-SPE_PRA_LINES],"// ZHAOSHI :%d",before_skillnum)!=1){
             write(HIR"可能出现异常了，如不能解决可通知长孙无情。\n"NOR);
                    return;
                  }
           }
           {
                  if( before_skillnum==spe_skillnum){
                for(i=0;i < sizeof(list)-11-SPE_PRA_LINES;i++)
                     content+=list[i]+"\n";
                content+=action;
              rm(SKILL_D(spe_skill["skill_en_name"]));
              write_file(SKILL_D(spe_skill["skill_en_name"]),content);
               }
         else {
          rm(SKILL_D(spe_skill["skill_en_name"]));

          if(spe_skillnum!=1) {
                for(i=0;i < sizeof(list)-SPE_PRA_LINES-2;i++)
                     content+=list[i]+"\n";
                  content+="// ZHAOSHI :"+(string)before_skillnum
                               +"\n";
                  content+=action;
              write_file(SKILL_D(spe_skill["skill_en_name"]),content);
                            }
          else if(spe_skillnum==1) {
                for(i=0;i < HEADER_END+3;i++)
                     content+=list[i]+"\n";
                  content+="// ZHAOSHI :"+(string)before_skillnum
                               +"\n";
                  content+=action;
              write_file(SKILL_D(spe_skill["skill_en_name"]),content);
                            }
         
             }    
        write_file(SKILL_D(spe_skill["skill_en_name"]),"\n"+result);
     }
}
int check_legal_basename(string name)
{
int i;
for(i=0;i<sizeof(valid_types);i++) 
     if(valid_types[i]==name)
        return 1;
return 0;
}
int check_legal_id(string id)
{
 int i;
 i = strlen(id);
 if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
 write("你的武功代号必须是 3 到 12 个英文字母。\n");
 return 0;
 }
 while(i--)
 if( id[i]<'a' || id[i]>'z' ) {
 write("你的武功代号只能用英文字母。\n");
                        return 0;
                }
        return 1;
}
int check_legal_name(string name)
{
 int i;
 i = strlen(name);
 if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
      write("武功的中文名称必须是 1 到 6 个中文字。\n");
 return 0;
 }
 while(i--) {
      if( name[i]<=' ' ) {
 write("你的武功中文名城不能用控制字元。\n");
 return 0;
 }
  if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("你的武功中文名要用「中文」!\n");
                        return 0;
                }
        }
        if( member_array(name,banned_name)!=-1 ) {
                write("你的武功中文名称会造成其他人的困扰。\n");
                return 0;
        }
        return 1;
}
int check_skillnum_exist(object me,string skill_en_name,int skill_num)
{
string file,*list;
string playername;
int total_zhaoshi_num;
file=read_file(SKILL_D(spe_skill["skill_en_name"]));
if(!file) {
          if(me->query("skillmaxim/"+spe_skill_basename)!=0)
              return 0;
          else {
              return 1;
                 }
       }
else
    list = explode(file, "\n");
playername=geteuid(me);
if(list[1]!="// "+playername)
      return 0;
if(list[0]!="// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改")
           return 0;
if(sscanf(list[sizeof(list)-1-SPE_PRA_LINES],"// ZHAOSHI :%d",total_zhaoshi_num)!=1)
         return 0;
if(total_zhaoshi_num==0)
           return 0;
if(total_zhaoshi_num==skill_num)
          return skill_num;
else if(total_zhaoshi_num+1 == skill_num)
          return skill_num;
else 
 return 0;
}
int check_owner_skill(object me,string skill_en_name)
{
	string file,*list;
	string playername;

	file=read_file(SKILL_D(skill_en_name));
	if(!file)
	{
		if(me->query("skillmaxim/"+spe_skill_basename)!=0)
			return 1;
		else 
			return 0;
	}
	else
		list = explode(file, "\n");
	playername=geteuid(me);
	if(list[1]!="// "+playername)
		return 2;
	if(list[0]!="// 这是玩家自创武功程序 原由maxim@nju_fengxue编写，现由xgchen@zzfy修改")
		return 2;
	else
		return 0;
}

int help (object me)
{
        write(@HELP
指令格式：editskill 武功基本技能 武功英文名字 武功中文名字 第几招
例如：editskill unarmed xgchen 无情神拳 1
 
这是用来创建自己风格武功的指令，随着经验值的增长，所可以实现的招式
越来越多，招式的威力也越来越大。每创造一种武功必须要有20000评价点
玩家增加招式的熟练程度的方式是使用个专用指令：
mylian,用practice也可以，但是难度会加大。

由于是自己摸索招式，所以难度要大些。玩家只能修改当前的招式，对以前的
招式无法改动。所以玩家要事先规划好6-7招，边练边修改，以免到时侯无法
改动以前的基本招式。

可以利用的基本功夫有：
 unarmed,
 sword,
 blade,
注意:
招式的英文名称后面将被加上基本技能的几个标识，玩家要事先想好，一旦
开始创建则无法随意改动英文名称。
招式描述中不要加入控制字符。
玩家最多只能创建三种高级功夫。
招式描述中的：
某人，你，某部位，武器带有普遍性，将来可以用来对付各种不同敌人。

招式的描述不要带有对自己或对手状态的描写，不要不负责的乱写。
巫师将检查玩家所创建的功夫，如不符合规定，将被删除。
HELP
);
        return 1;
}
