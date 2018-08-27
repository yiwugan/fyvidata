#include <ansi.h>
inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "����һ��" NOR,
        BLU "��������" NOR,
        BLU "����ҳ�" NOR,
        BLU "��ѧէ��" NOR,

        HIB "�����ž�" NOR,
        HIB "��֪һ��" NOR,
        HIB "����ͨͨ" NOR,
        HIB "ƽƽ����" NOR,
        CYN "ƽ������" NOR,
        CYN "��ͨƤë" NOR,
        CYN "��������" NOR,
        CYN "��¶��â" NOR,
        HIC "�������" NOR,
        HIC "�������" NOR,
        HIC "��Ȼ���" NOR,
        HIC "��Ȼ��ͨ" NOR,
        YEL "�������" NOR,
        YEL "�޿�ƥ��" NOR,
        YEL "����Ⱥ��" NOR,
        YEL "����似" NOR,
        HIY "�ĳ�����" NOR,
        HIY "�����뻯" NOR,
        HIY "����Ⱥ��" NOR,
        HIY "�Ƿ��켫" NOR,

        HIG "��������" NOR,
        HIG "һ����ʦ" NOR,
        HIG "�񹦸���" NOR,
        HIG "������˫" NOR,
        HIW "��������" NOR,
        HIW "������" NOR,
        HIW "̾Ϊ��ֹ" NOR,
        HIW "��ɲ�" NOR,
        HIR "��תǬ��" NOR,
        HIR "��˷����" NOR,
        HIR "�����ƻ�" NOR,
        HIR "��豹���" NOR
   });

string *knowledge_level_desc = ({
        WHT"����"NOR,
        CYN"����"NOR,
        HIB"����"NOR,
        CYN"����"NOR,
        HIW"����"NOR,
        HIR"����"NOR,  
});



mapping valid_type = ([
        "axe":          "����",
        "arrow":        "����",
        "blade":        "����",
        "dagger":       "�̱���",
        "dodge":        "������",
        "force":        "�ڹ�",
        "fork":         "�淨",
        "hammer":       "����",
        "iron-cloth":   "Ӳ��",
        "literate":     "��д",
        "magic":        "����",
        "move":         "�Ṧ",
        "parry":        "�м�",
        "perception":   "������",
        "scratching":   "��֮��",
        "cursism" :     "��ͷ��",
        "spells":       "����",
        "staff":        "�ȷ�",
        "stealing":     "������",
        "sword":        "����",
        "throwing":     "����",
        "unarmed":      "ȭ��",
        "whip":         "�޷�",
        "herb":         "ҩ��",
        "spear":        "ǹ��",]);

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

        if(!arg) return notify_fail("ָ���ʽ : cha [�书����].[���⼼��]\n");

        sscanf(arg, "%s.%s", arg, str);

        if(!me->query_skill(arg, 1)) 
                return notify_fail("��Ҫ���ʲô���ܣ�\n");

        if(file_size(SKILL_D(arg)+".c") < 1)
                return notify_fail("������Ҫ��Լ����ļ��Ѿ���ʧ����֪ͨ��ʦ��\n");

        if( stringp(str) ){
                // ��ʽ verify xxx.? �ǲ�ѯ��skill�İ�����
                // verify xxx.yyy �ǲ�ѯ yyy �İ�����
                if( str == "?" ){
                        notify_fail("�Բ��𣬡�"+to_chinese(arg)+"��Ŀǰ��û����ϸ�İ���˵����\n");
                        return SKILL_D(arg)->help(me);
                }
                else if( stringp(exert = SKILL_D(arg)->exert_function_file("")) && file_size(exert + str +".c") > 0){
                        notify_fail("�Բ���"+to_chinese(arg)+"�ڹ���"+str+"������û����ϸ��˵����\n");
                        return (exert + str)->help(me);
                }
                else if( stringp(exert = SKILL_D(arg)->perform_action_file("")) && file_size(exert + str +".c") > 0){
                        notify_fail("�Բ���"+to_chinese(arg)+"�⹦��"+str+"������û����ϸ��˵����\n");
                        return (exert + str)->help(me);
                }
                return notify_fail("�Բ���"+to_chinese(arg)+"û�С�"+str+"������ܡ�\n");
        }

        lrn = me->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        str = sprintf("\n%24s\n", HIW"��"+to_chinese(arg)+"���ܡ�\n"NOR);
        str = replace_string(str, "  ", "");
        str += sprintf(RED" �书����"NOR"  %s "WHT"%3d��\t      \n"NOR,skill_level(SKILL_D(arg)->type(), 
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
                str += RED" �ڹ�(exert+)��"NOR" ";
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
                str += RED" ����(conjure+)��"NOR" ";
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
                str += RED" ����(cast+)��"NOR" ";
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
                str += ""RED" �⹦(perform+)��"NOR"";
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
        str = RED" װ�����ܣ�"NOR"";

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
        write("\nָ���ʽ : cha [�书����].[�������� | ?]\n");
        write(@HELP
���ָ����������ѯ����ܵĹ��ܺ����ݡ�

���⼼�ܱ�ʾ���� enable �ļ��ܣ��磺
(�Ṧ���мܡ��ڹ�) ��ʾ�����书���������Ṧ���мܣ��ڹ��ȡ�
�ڹ�������ʾ������(exert)���ڹ���
�⹦������ʾ��ʹ��(perform)���⹦�����еȡ�
����ڹ����⹦�ľ����а������ܣ����� cha skill.perform ����ʽ���鿴��
�磺    cha luoriquan.luori    �鿴����

HELP);

    return 1;
}