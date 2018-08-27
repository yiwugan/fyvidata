 // enable.c
#include <ansi.h>
inherit F_CLEAN_UP; 
mapping valid_types = ([
//              "array":        "��",
                "animal-training":  "ѵ����",
                "axe":                  "����",
                "blade":        "����",
                "dagger":       "�̱���",
                "dodge":        "������",
                	 "duan-yiyangzhi":   "������",
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
                "spear":        "ǹ��",
]); 
int main(object me, string arg) {
        mapping skill_map;
        string *types, *skill, *usr_skill, ski, map_to;
        int i, j, modify;
        string s;
        string skill_name,enable_skill;
        int skill_level;
        
        seteuid(getuid());
   
        if(!arg) {
                skill_map = me->query_skill_map();
                if(!mapp(skill_map) || sizeof(skill_map)==0 ) {
                        return notify_fail("������û��ʹ���κ����⼼�ܡ�\n");
                }
                skill = keys(valid_types);
                write("��������Ŀǰʹ���е����⼼�ܡ�\n");
                for(i=0; i<sizeof(skill); i++) {
                        if(undefinedp(valid_types[skill[i]])) {
                                map_delete(skill_map, skill[i]);
                                continue;
                        }
                        if(!me->query_skill(skill[i])) {
                                continue;
                        }
                        modify = me->query_temp("apply/" + skill[i]);
                        printf("  %-20s�� %-20s  ��Ч�ȼ���%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(skill_map[skill[i]]) ? "��" : 
                                        SKILL_D(skill_map[skill[i]])->name(),
                                    (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                me->query_skill(skill[i]));
                }
                return 1;
        }
        
        if(arg=="?") {
                write("�����ǿ���ʹ�����⼼�ܵ�������������⼼�ܣ�\n");
                skill = sort_array(keys(valid_types), (: strcmp :) );
                if (me->query_skills())
                        usr_skill = keys(me->query_skills());
                for(i=0; i<sizeof(skill); i++) {
                        s = sprintf("%6s (%s)", valid_types[skill[i]], skill[i]);
                        if (me->query_skills())
                                usr_skill = filter_array(keys(me->query_skills()), (: SKILL_D($1)->valid_enable($2) :), skill[i]);
                        if(sizeof(usr_skill)) {
                                for(j=0; j<sizeof(usr_skill); j++) {
                                        printf("  %-20s : %s (%s)\n", s, SKILL_D(usr_skill[j])->name(), usr_skill[j]);
                                        s = " ";
                           }  
                        } else {
                                printf("  %-20s\n", s); 
                        }
                }
                return 1;
        } 
        if (arg)
        if (sscanf(arg, "%s %s", ski, map_to)!=2)
        if (sscanf(arg,"%s",skill_name)==1 && skill_name!="none") {
                if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) 
                        return notify_fail("��" + skill_name + "���������ּ�����\n"); 
                if( !(skill_level=me->query_skill(skill_name,1)))
                        return notify_fail("�㲢û��ѧ������ܻ��Ǽ��ܵȼ�Ϊ�㡣\n");
                
                if(undefinedp(valid_types[skill_name])) 
                        return notify_fail("����ܲ��ǻ����������࣬�� enable ? ���Բ鿴����Щ���ࡣ\n");
                enable_skill=me->query_skill_mapped(skill_name);
                                        
                write("���������ѯ�����⼼��״����\n\n");
                modify = me->query_temp("apply/" + skill_name);
                printf("  %-20s�� %-20s  ��Ч�ȼ���%s%3d\n\n" NOR, 
                                valid_types[skill_name] + " (" + skill_name + ")",
                                (!me->query_skill_mapped(skill_name)) ? "��" : 
                                        SKILL_D(enable_skill)->name(),
                                    (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                me->query_skill(skill_name)
                        );
                return 1;
        } 
        
        if(sscanf(arg, "%s %s", ski, map_to)!=2) {
                return notify_fail("ָ���ʽ��enable <��������> <��������>|none\n");
        }
        
        if(undefinedp(valid_types[ski])) {
                return notify_fail("û������������࣬�� enable ? ���Բ鿴����Щ���ࡣ\n");
        }
        
        if(map_to=="none") {
           me->map_skill(ski);
                me->reset_action();
                write("ֹͣʹ�á�" + valid_types[ski] + "�������⼼�ܡ�\n");
                return 1;
        } else if(map_to==ski) {
                write("��" + SKILL_D(ski)->name() + "��������" + valid_types[ski] + "�Ļ���������Ҫ enable��\n");
                return 1;
        }
        
        if(!find_object(SKILL_D(map_to)) && !load_object(SKILL_D(map_to))) {
                return notify_fail("��" + map_to + "���������ּ�����\n");     
        } 
        if(!me->query_skill(map_to, 1)) {
                return notify_fail("�㲻�����⼼�ܡ�" + SKILL_D(map_to)->name() + "����\n");
        } 
        if(!me->query_skill(ski, 1)) {
                return notify_fail("������" + SKILL_D(ski)->name() + "����ûѧ�ᣬ���ʹ�����⼼�ܡ�" + SKILL_D(map_to)->name() + "����\n");
        }
        if (map_to == "tanzhi-shentong" && ski=="parry" && !me->query("open_sesame") ) {
                return notify_fail("���⼼�ܡ�" + SKILL_D(map_to)->name() + "���������ڡ�" + valid_types[ski] + "���ϡ�\n");
        }
        if(!SKILL_D(map_to)->valid_enable(ski)) {
                return notify_fail("���⼼�ܡ�" + SKILL_D(map_to)->name() + "���������ڡ�" + valid_types[ski] + "���ϡ�\n");
        } 
        if(ski=="dodge" && me->query_temp("stepup"))
                return notify_fail("������ʹ�������������⼼�ܣ��������Ч����ʧ�����ת�����书��\n");
        
  //      if(ski=="iron-cloth" && me->query_temp("daoqian"))
    //            return notify_fail("������ʹ��Ӳ�������⼼�ܣ��������Ч����ʧ�����ת�����书��\n");
        
        if(ski=="force" && me->query_temp("buffup/buffed_kee"))
                return notify_fail("������ʹ�ñ��ľ������⼼�ܣ��������Ч����ʧ�����ת�����书��\n");
                
        me->map_skill(ski, map_to);
        me->reset_action();
        write("��ʼʹ�á�" + valid_types[ski] + "�������⼼�ܡ�" + SKILL_D(map_to)->name() + "����\n");
        
        if( ski=="magic" ) {
                write("�������һ�ַ���ϵ�������������¶�����\n");
                me->set("atman", 0);
   } else if( ski=="force" ) {
                write("�������һ���ڹ��������������¶�����\n");
                me->set("force_factor",0);
                me->set("force", 0);
        } else if( ski=="spells" ) {
                write("�������һ������ϵ��������������������\n");
                me->set("mana", 0);
        }
        
        return 1;
}
int help(object me) {
        write(@HELP
ָ���ʽ :      enable
                enable ?
                enable <��������>
                enable <��������> <��������> | none 
���ָ������ָ����Ҫ�õļ��ܣ���ָ����������ͼ������ơ�
������Ӳ��������ʾ���������༰��Ŀǰ��ʹ�õļ������� ��
�����һ�� ? ���г�������ʹ�����⼼�ܵļ������࣬
���ֱ�Ӹ�����������г�Ŀǰ�ü��ܵģ������״̬��
 
HELP
        );
        return 1;
}
       
