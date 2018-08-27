// renwu.c for player interactive jobs.
// Keinxin@sj2  2003.3



#include <ansi.h>

#define TIME_TICK (time()*60)

string get_place(string str);
string ppl;


mapping get_renwu(object ob, string type, string family, string gender)
{
        object *obs = filter_array(objects(), (: interactive :));
        int bonus;
        int i = sizeof(obs), j = 10;
        string *arg;
        
        if (i < 1) return 0;
        while (j--) {
                ob = obs[random(i)];
                if (wiz_level(ob)) continue;       //������ʦ
                if (ob->is_ghost()) continue;      //���˹��
                if (ob->query("combat_exp")< 60000 ) continue;      //����exp<60k��id
                if (!environment(ob)) continue;            //���˶��ߵ�id
                if (ob->query("id") == ppl) continue;      //���˸ձ�ѡ�е�id
                arg = explode(base_name(environment(ob)), "/");      //���˴��������԰��id
                if ( arg[0] != "d" || arg[1] == "wizard" || arg[1] == "wuguan") continue;   //������ݵȴ���id
                break;
        }
        if (j < 0) return 0;
        ppl = ob->query("id");
        
// here to enoch the quest   �Զ�����quest mapping����
        bonus = 150+random(150);
        type = "Ȱ��";           //default Ϊzm jobȰ����������������job
                return ([ 
                "id":           (string)ob->query("id"),
                "name":         (string)ob->name(1),
                "time":         TIME_TICK+(200*30*60),
                "exp_reward":   bonus/8 + random(bonus/8),         
                "pot_reward":   bonus,
                "type":         type,
                "place":        get_place(base_name(environment(ob)))+environment(ob)->query("short"),
                ]);

}




string get_time(int i)
{
        return CHINESE_D->chinese_date(i);
}

string get_place(string str)       //������������
{

        string *place = explode(str, "/");

        str = " ";
        if(place[0] == "d")
                switch(place[1]){
                        case "baituo":  str = "�������ɽ"; break;
                        case "hj":      str = "����ؽ�"; break;
                        case "mingjiao":str = "��������"; break;
                        case "shaolin": str = "������ɽ����"; break;
                        case "songshan":str = "������ɽ"; break;
                        case "wudang":  str = "�����䵱ɽ"; break;
                        case "xingxiu": str = "�������޺�"; break;
                        case "city":    str = "�������ݳ�"; break;
                        case "emei":    str = "�Ĵ�����ɽ"; break;
                        case "fuzhou":  str = "�Ͻ�����"; break;
                        case "jiaxing": str = "���ϼ���"; break;
                        case "taishan": str = "ɽ��̩ɽ"; break;
                        case "dali":    str = "���ϴ����"; break;
                        case "tls":     str = "����������"; break;
                        case "tiezhang":str = "��������ɽ"; break;
                        case "kunlun":  str = "����ɽ��"; break;
                        case "fairyland":str = "����ɽ��"; break;
                        case "xiaoyao": str = "��ң��"; break;
                        case "gumu":    str = "����ɽ��Ĺ"; break;
                        case "chengdu": str = "�Ĵ��ɶ�"; break;
                        case "huashan": str = "������ɽ"; break;
                        case "xiangyang":str = "��������"; break;
                        case "xueshan": str = "������ѩɽ"; break;
                        case "wizard":  str = "��������"; break;
                        case "death":   str = "��ʮ�˲����"; break;
                        case "gaibang": str = "ؤ��ֶ�"; break;
                        case "hz":      str = "���Ϻ���"; break;
                        case "village": str = "����С��"; break;
                        case "wuguang": str = "�������"; break;
                        case "thd":     str = "�����һ���"; break;
                        case "gaibang": str = "ؤ��ֶ�"; break;
        }
        return str;
}
