//Last modify by vikee.
//2000.12.15

#include <ansi.h>
inherit F_CLEAN_UP;

string chinese_daoxing(int gain);
string status_color(int current, int max);

int main(object me, string arg)
{
        object ob;
        mapping my;
        int dao,x,i;
        string str;
        seteuid(getuid(me));
        
        if(!arg) ob = me;
        else if (wizardp(me)) { ob = present(arg, environment(me));
             if (!ob) ob = find_player(arg);
             if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
        } 
                else return notify_fail("ֻ����ʦ�ſ��Բ쿴���˵�״̬��\n");

        my = ob->query_entire_dbase();
        printf("\n");   
        printf(NOR CYN"����������������������������������������������������������������������\n"NOR,);
        printf(NOR CYN"��"NOR HIW" ����״̬ "NOR CYN" ���� "NOR HIW"%-12s	"NOR CYN"ID "NOR HIW" %-13s "NOR CYN" �ȼ� "NOR HIW" %-10d "NOR CYN"��\n"NOR,ob->name(),"["+capitalize(ob->query("id"))+"]",ob->query("level"));
        printf(NOR CYN"�ǩ�������������������������������������������������������������������\n"NOR);
        printf(NOR CYN"��"NOR"�� "+HIC+"����"+NOR+" ��%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["gin"],my["eff_gin"]),my["gin"],my["eff_gin"],status_color(my["eff_gin"],my["max_gin"]),my["eff_gin"]*100/my["max_gin"]);
        printf(NOR"  �� "+HIB+"����"+NOR+" ��%s%7-d/%7-d(+%4d)"NOR CYN"��\n"NOR,status_color(my["atman"], my["max_atman"]), my["atman"], my["max_atman"],my["atman_factor"]);
        printf(NOR CYN"��"NOR"�� "+HIC+"��Ѫ"+NOR+" ��%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["kee"],my["eff_kee"]),my["kee"],my["eff_kee"],status_color(my["eff_kee"],my["max_kee"]),my["eff_kee"]*100/my["max_kee"]);
        printf(NOR "  �� "+HIY+"����"+NOR+" ��%s%7-d/%7-d(+%4d)"NOR CYN"��\n"NOR,status_color(my["force"], my["max_force"]), my["force"], my["max_force"],my["force_factor"]);
        printf(NOR CYN"��"NOR"�� "+HIC+"����"+NOR+" ��%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["sen"],my["eff_sen"]),my["sen"],my["eff_sen"],status_color(my["eff_sen"],my["max_sen"]),my["eff_sen"]*100/my["max_sen"]);
        printf(NOR"  �� "+MAG+"����"+NOR+" ��%s%7-d/%7-d(+%4d)"NOR CYN"��\n"NOR,status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],my["mana_factor"]);
        if(my["food"]*100/ob->max_food_capacity()>100) str=HIC+"�ܱ�";
        else if(my["food"]*100/ob->max_food_capacity()>90) str=HIG+"����";
        else if(my["food"]*100/ob->max_food_capacity()>60) str=HIY+"ȱʳ";        
                else if(my["food"]*100/ob->max_food_capacity()>30) str=CYN+"ȱʳ";
        else if(my["food"]*100/ob->max_food_capacity()>10) str=HIR+"ȱʳ";
        else str=RED+"����";
        printf(NOR CYN"��"NOR"�� "+HIW+"ʳ��"+NOR+" ��%s%7-d/%7-d [%4s%s]"NOR,status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),str,status_color(my["food"], ob->max_food_capacity()));
        printf(NOR "  �� "+HIM+"����"+NOR+" ��%s%18-d    "NOR CYN"��\n"HIG,HIM,(int)ob->query("combat_exp"));        
        if(my["water"]*100/ob->max_water_capacity()>100) str=HIC+"�ܱ�";
        else if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"����";
        else if(my["water"]*100/ob->max_water_capacity()>60) str=HIY+"ȱˮ";
        else if(my["water"]*100/ob->max_water_capacity()>30) str=CYN+"ȱˮ";
        else if(my["water"]*100/ob->max_water_capacity()>10) str=HIR+"ȱˮ";
        else str=RED+"����";
         printf(NOR CYN"��"NOR"�� "+HIW+"��ˮ"+NOR+" ��%s%7-d/%7-d [%4s%s]"NOR,status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),str,status_color(my["water"], ob->max_water_capacity()));
        printf(NOR"  �� "+HIG+"Ǳ��"+NOR+" ��%s%14-d "NOR CYN"       ��\n"NOR,HIG,(int)ob->query("potential") - (int)ob->query("learned_points"));
        printf(NOR CYN"��"NOR"�� "+HIW+"����"+NOR+" ��%s%21-d "NOR,HIW,(int)ob->query("score"));
        printf(NOR"  �� "+HIR+"ɱ��"+NOR+" ��%s%20-d "NOR CYN" ��\n"HIG,HIR,(int)ob->query("bellicosity"));
        printf(NOR CYN"����������������������������������������������������"HIY"���������¡�"NOR CYN"������\n"NOR);
        printf("\n");   
        return 1;
}

string status_color(int current, int max)
{
        int percent;
        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return CYN;
        if( percent >= 10 ) return HIR;
        return RED;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : hp
           hp <��������>                   (��ʦר��)
 
���ָ�������ʾ��(���)��һЩ����״̬
see also : score

HELP
    );
    return 1;
}
 

