inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me,string arg)
{
	string id,reason,wizname,criname,result,ttime;
	int howlong,i;
	object criminal;
	if(!arg || arg=="" || sscanf(arg, "%s %d %s", id, howlong,reason)!=3)
		return notify_fail("ָ���ʽ : qiujin <ĳ��> <ʱ��> <ԭ��>\n");
	criminal = find_player(id);
	if (!criminal) return notify_fail("û�������\n");
	if (wizardp(criminal)) return notify_fail("��ʦ�����⣬���Ǹ������Ǳ���ɡ�\n");
		wizname = me->query("name") + "("+me->query("id")+")";
	criname = criminal->query("name") + "("+criminal->query("id")+")";
	ttime=ctime(time())[8..strlen(ctime(time()))];
	criminal->set("qiushi/howlong",howlong);
	result = sprintf("%s��Ϊ��%s����%s��������%d����\n",
			wizname,reason,criname,howlong);
       CHANNEL_D->do_channel(this_object(), "rumor",
                ""HIG+criname+HIM"��"HIY+reason+HIM"���ͽ���"+HIW"���� "HIM"����ʱ��Ϊ 
"+howlong+"���ӣ�����"NOR);
	criminal->set("qiushi/temp",result);
//	tell_object(criminal,result);
	criminal->move("/d/wiz/qiushi");
	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : qiujin <ĳ��> <ʱ��> <ԭ��>
ʱ���Է���Ϊ��λ�����Ϊ0���ʾ���Զ��ų��������á�
ԭ��һ��Ҫ��ϸд��
����	qiujin kelly 60 chat̫˧
HELP	);
	return 1;
}
