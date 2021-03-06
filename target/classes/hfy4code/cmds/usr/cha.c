#include <ansi.h>
inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "不堪一击" NOR,
        BLU "毫不足虑" NOR,
        BLU "不足挂齿" NOR,
        BLU "初学乍练" NOR,

        HIB "初窥门径" NOR,
        HIB "略知一二" NOR,
        HIB "普普通通" NOR,
        HIB "平平淡淡" NOR,
        CYN "平淡无奇" NOR,
        CYN "粗通皮毛" NOR,
        CYN "半生不熟" NOR,
        CYN "初露锋芒" NOR,
        HIC "驾轻就熟" NOR,
        HIC "心领神会" NOR,
        HIC "了然於胸" NOR,
        HIC "豁然贯通" NOR,
        YEL "出类拔萃" NOR,
        YEL "无可匹敌" NOR,
        YEL "技冠群雄" NOR,
        YEL "神乎其技" NOR,
        HIY "心驰神往" NOR,
        HIY "出神入化" NOR,
        HIY "傲视群雄" NOR,
        HIY "登峰造极" NOR,

        HIG "所向披靡" NOR,
        HIG "一代宗师" NOR,
        HIG "神功盖世" NOR,
        HIG "举世无双" NOR,
        HIW "惊世骇俗" NOR,
        HIW "震古铄今" NOR,
        HIW "叹为观止" NOR,
        HIW "深不可测" NOR,
        HIR "逆转乾坤" NOR,
        HIR "扑朔迷离" NOR,
        HIR "如梦似幻" NOR,
        HIR "返璞归真" NOR
   });

string *knowledge_level_desc = ({
        WHT"极轻"NOR,
        CYN"很轻"NOR,
        HIB"不重"NOR,
        CYN"不轻"NOR,
        HIW"很重"NOR,
        HIR"极重"NOR,  
});



mapping valid_type = ([
        "axe":          "斧法",
        "arrow":        "箭术",
        "blade":        "刀法",
        "dagger":       "短兵刃",
        "dodge":        "闪躲术",
        "force":        "内功",
        "fork":         "叉法",
        "hammer":       "锤法",
        "iron-cloth":   "硬功",
        "literate":     "读写",
        "magic":        "法术",
        "move":         "轻功",
        "parry":        "招架",
        "perception":   "听风术",
        "scratching":   "符之术",
        "cursism" :     "降头术",
        "spells":       "咒文",
        "staff":        "杖法",
        "stealing":     "妙手术",
        "sword":        "剑法",
        "throwing":     "暗器",
        "unarmed":      "拳脚",
        "whip":         "鞭法",
        "herb":         "药道",
        "spear":        "枪法",]);

string skill_level(string, int);
string skill_enables(object sk);

int sort_skill(string file)
{
        int i;
        if ( !sscanf(file, "%*s.c") )  return 0;
        i = strlen(file);
        while(i--){
                if( file[i] == '.' ) continue;
                if( file[i] < 'a' || file[i] > 'z' )
                        return 0;
        }
        return 1;
}



int main(object me, string arg)
{
        mapping lrn;
        string exert, str, *file;
        object sk;
        int i, j = 0;

        seteuid(getuid());

        if(!arg) return notify_fail("指令格式 : cha [武功名称].[特殊技能]\n");

        sscanf(arg, "%s.%s", arg, str);

        if(!me->query_skill(arg, 1)) 
                return notify_fail("你要查对什么技能？\n");

        if(file_size(SKILL_D(arg)+".c") < 1)
                return notify_fail("错误！你要查对技能文件已经消失，请通知巫师。\n");

        if( stringp(str) ){
                // 格式 verify xxx.? 是查询此skill的帮助。
                // verify xxx.yyy 是查询 yyy 的帮助。
                if( str == "?" ){
                        notify_fail("对不起，「"+to_chinese(arg)+"」目前还没有详细的帮助说明。\n");
                        return SKILL_D(arg)->help(me);
                }
                else if( stringp(exert = SKILL_D(arg)->exert_function_file("")) && file_size(exert + str +".c") > 0){
                        notify_fail("对不起，"+to_chinese(arg)+"内功「"+str+"」功能没有详细的说明。\n");
                        return (exert + str)->help(me);
                }
                else if( stringp(exert = SKILL_D(arg)->perform_action_file("")) && file_size(exert + str +".c") > 0){
                        notify_fail("对不起，"+to_chinese(arg)+"外功「"+str+"」功能没有详细的说明。\n");
                        return (exert + str)->help(me);
                }
                return notify_fail("对不起，"+to_chinese(arg)+"没有「"+str+"」这项功能。\n");
        }

        lrn = me->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        str = sprintf("\n%24s\n", HIW"【"+to_chinese(arg)+"功能】\n"NOR);
        str = replace_string(str, "  ", "");
        str += sprintf(RED" 武功名："NOR"  %s "WHT"%3d级\t      \n"NOR,skill_level(SKILL_D(arg)->type(), 
                        me->query_skill(arg, 1)), me->query_skill(arg, 1),  );  

        str += "\t\t\t\t\t\t\t\t    \n";
        sk = load_object(SKILL_D(arg));

        exert = skill_enables(sk);
        if(exert != ""){
                str += exert;
                i++;
        }

        if( stringp(exert = SKILL_D(arg)->exert_function_file("")) ){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }

        if(j && j > 0){
                if( i )
                        str = str + "\n";
                str += RED" 内功(exert+)："NOR" ";
                for(i=0; i < j; i++){
                        if (i % 4 == 0) str += "";
                        str += sprintf("%-14s ",WHT+replace_string(file[i], ".c", "")+NOR);
                        if ( i > j-2 ){
                                switch(i%4){
                                        case 0: str +=" "; break;
                                        case 1: str +=" "; break;
                                        case 2: str +=" "; break;
                                        default: break;
                                }
                        }
                }
                str += "\n";
                j = 0;
        }
        if( stringp(exert = SKILL_D(arg)->conjure_magic_file("")) ){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }

        if(j && j > 0){
                if( i )
                        str = str + "\n";
                str += RED" 法术(conjure+)："NOR" ";
                for(i=0; i < j; i++){
                        if (i % 4 == 0) str += "";
                        str += sprintf("%-14s ",WHT+replace_string(file[i], ".c", "")+NOR);
                        if ( i > j-2 ){
                                switch(i%4){
                                        case 0: str +=" "; break;
                                        case 1: str +=" "; break;
                                        case 2: str +=" "; break;
                                        default: break;
                                }
                        }
                }
                str += "\n";
                j = 0;
        }
        if( stringp(exert = SKILL_D(arg)->cast_spell_file("")) ){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }
        if(j && j > 0){
                if( i )
                        str = str + "\n";
                str += RED" 咒术(cast+)："NOR" ";
                for(i=0; i < j; i++){
                        if (i % 4 == 0) str += "";
                        str += sprintf("%-14s ",WHT+replace_string(file[i], ".c", "")+NOR);
                        if ( i > j-2 ){
                                switch(i%4){
                                        case 0: str +=" "; break;
                                        case 1: str +=" "; break;
                                        case 2: str +=" "; break;
                                        default: break;
                                }
                        }
                }
                str += "\n";
                j = 0;
        }

        if( stringp(exert = SKILL_D(arg)->perform_action_file(""))){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }
        if(j && j > 0){
                if( i )
                        str = str + "\n";
                str += ""RED" 外功(perform+)："NOR"";
                for(i=0; i < j; i++){
                        if (i % 4 == 0) str += "";
                        str += sprintf("%-14s ",WHT+replace_string(file[i], ".c", "")+NOR);
                        if ( i > j-2 ){
                                switch(i%4){
                                        case 0: str +="\t            "; break;
                                        case 1: str +="\t            "; break;
                                        case 2: str +="\t    "; break;
                                        default: break;
                                }
                        }
                }
                str += "\n";
        }
        str += "\n";
        write(str);
        return 1;
}

string skill_enables(object sk)
{
        int i, j;
        string str, *skills;
        skills = keys(valid_type);

        for(i=0; i < sizeof(skills); i++) {
                if (sk->valid_enable(skills[i])) continue;
                skills[i] = 0;
        }
        skills -= ({ 0 });
        j = sizeof(skills);
        if( !j || j < 1)
                return "";
        str = RED" 装备技能："NOR"";

        for(i=0; i < j; i++) {
                if (i % 4 == 0) str += " ";
                str += sprintf("%-14s ", WHT+valid_type[skills[i]]+"("+skills[i]+")"NOR);
                if ( i > j-2 ){
                        switch(i%4){
                                case 0: str +=" "; break;
                                case 1: str +=" "; break;
                                case 2: str +=" "; break;
                                default: break;
                        }
                }
        }
        str += "\n";
        return str;
}
string skill_level(string type, int level)
{
        int grade;

        switch(type) {
                case "knowledge":
                        grade = level / 20;
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        grade = level / 8;
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write("\n指令格式 : cha [武功名称].[绝招名称 | ?]\n");
        write(@HELP
这个指令可以让你查询此项技能的功能和数据。

特殊技能表示可以 enable 的技能，如：
(轻功、招架、内功) 表示：此武功可以用作轻功，招架，内功等。
内功方面显示可运用(exert)的内功。
外功方面显示可使用(perform)的外功，绝招等。
如果内功或外功的绝招有帮助介绍，可用 cha skill.perform 的形式来查看。
如：    cha luoriquan.luori    查看落日

HELP);

    return 1;
}
