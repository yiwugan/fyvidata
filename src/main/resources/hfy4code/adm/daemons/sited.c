#include <ansi.h>
inherit F_DBASE;

mapping valid_login = ([
                "hxsd":         ({ "61.", "171.", "12.", "5." }),
                "keinxin":      ({ "218.", "211.", "210.", "202.", "10.","219" }),
                "wuye":         ({ "219.", "218.", "61." }),
                "haoren":       ({ "127.0.1.9" }),
                "sunyf":        ({ "127.0.1.9" }),
                "robber":       ({ "127.0.1.9" }),
                "winter":       ({ "127.0.1.9" }),
                "chk":          ({ "61.", "211.", "202.", "10.", "218." }),
                "tanggw":       ({ "127.0.1.9" }),
                "huoying":      ({ "127.0.1.9" }),
                "king":         ({ "127.0.1.9" }),
                "yao":          ({ "127.0.1.9" }),
                "ahunter":      ({ "127.0.1.9" }),
                "bbb":          ({ "127.0.1.9" }),
                "bobo":         ({ "127.0.1.9" }),
                "cht":          ({ "127.0.1.9" }),
                "cool":         ({ "127.0.1.9" }),
                "darken":       ({ "127.0.1.9" }),
                "emnil":        ({ "127.0.1.9" }),
                "hunthu":       ({ "127.0.1.9" }),
                "iceland":      ({ "127.0.1.9" }),
                "mingy":        ({ "127.0.1.9" }),
                "jpei":         ({ "127.0.1.9" }),
                "keepon":       ({ "127.0.1.9" }),
                "lius":         ({ "127.0.1.9" }),
                "lmoon":        ({ "127.0.1.9" }),
                "look":         ({ "127.0.1.9" }),
                "lxue":         ({ "127.0.1.9" }),
                "numa":         ({ "127.0.1.9" }),
                "river":        ({ "127.0.1.9" }),
                "snowman":      ({ "127.0.1.9" }),
                "tiantian":     ({ "127.0.1.9" }),
                "tomy":         ({ "127.0.1.9" }),
                "shaer":        ({ "127.0.1.9" }),
                "xiaolee":      ({ "127.0.1.9" }),
                "xiaoyao":      ({ "127.0.1.9" }),
                "guoo":         ({ "127.0.1.9" }),
                "yuj":          ({ "127.0.1.9" }),
                //�ӱ���ʦ
                "ldf":          ({ "127.0.1.9" }),
                "night":        ({ "127.0.1.9" }),
                //�ػʵ�
                "lanxin":       ({ "127.0.1.9" }),
                //ɽ��̩��
                "ziqing":       ({ "127.0.1.9" }),
                "godhelpu":     ({ "127.0.1.9" }),
                //ɽ����̨
                "can":          ({ "127.0.1.9" }),
                "mouse":        ({ "127.0.1.9" }),
                //�㽭
                "short":        ({ "127.0.1.9" }),
                "bluesky":      ({ "127.0.1.9" }),
                //����
                "jackyang":     ({ "127.0.1.9" }),
                "star":         ({ "127.0.1.9" }),
                ]);

int is_valid(string id, string ip)
{
        int i;

        if (ip == "127.0.0.1" || ip == "localhost") {
                if (wiz_level(id)) return 1;
                return 0;
        }
        if (undefinedp(valid_login[id])) {
                if (!wiz_level(id)) return 1;
                write("��ʦ�����е�ַ���ƣ����� guest ��¼֪ͨ����\n");
                destruct(this_object());
                return 0;
        }
        i = sizeof(valid_login[id]);
        while (i--) if (sscanf(ip, valid_login[id][i] + "%*s")) return 1;
        destruct(this_object());        // �Զ��ݻ��Լ�������YUJIP�ı�ˢ��
        return 0;
}

mapping valid_multi = ([
                "":             0
                ]);

int is_multi(string id, string ip, string port)
{
        object *usr = filter_array(objects(), (: interactive :));
        string *site = keys(valid_multi);
        int i, login_cnt = 0;

        if (query(ip)) {
                write("���ĵ�ַ�����˵�¼����Ȼ����ԡ�\n");
                return 1;
        }
        set(ip, 1);
        call_out("delete", 10, ip);
        usr = filter_array(usr, (: environment :));
        i = sizeof(usr);
        while (i--) if (usr[i]->query("id") != id && query_ip_number(usr[i]) == ip) login_cnt++;
        write("���� IP �ǣ�" HIW + ip + ":" + port + NOR "���˵�ַ����" + chinese_number(login_cnt)+"λ������ߡ�\n");
        if (!login_cnt) return 0;
        i = sizeof(valid_multi);
        while (i--) if (sscanf(ip, site[i] + "%*s")) break;
        if (i < 0) {
                write("�Բ�����Ŀǰ�ĵ�ַ��ֹ���ص�¼��������ʦ��ϵ��\n");
                return 1;
        }
        if (!(i = valid_multi[site[i]])) return 0;
        if (login_cnt < i) return 0;
        write("�Բ�����Ŀǰ�ĵ�ַ�ѵ����������ƣ�������ʦ��ϵ��\n");
        return 1;
}
