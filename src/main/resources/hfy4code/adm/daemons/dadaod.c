// dadaod.c

#include <ansi.h>

int fenbu_dadao();

void create() { seteuid(getuid()); }

void fengbu_dadao()
{
	int a,i;
	string file,location,*roomlines;
	object dadao;

	fenbu_dadao();
	for(i=0;i<6;i++)
	{
		switch(random(17)+1)
		{
			case 1 : file = read_file("/dadao/a");
			message("channel:rumor",HIR"���ٸ����ġ������Ƴ���Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 2 : file = read_file("/dadao/b");
			message("channel:rumor",HIR"���ٸ����ġ��������ţ����𵺣��������ȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 3 : file = read_file("/dadao/c");
			message("channel:rumor",HIR"���ٸ����ġ������ɱ��������ȵȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 4 : file = read_file("/dadao/d");
			message("channel:rumor",HIR"���ٸ����ġ�����԰�壬�䵱ɽ�ȵ���Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 5 : file = read_file("/dadao/e");
			message("channel:rumor",HIR"���ٸ����ġ����ٻ��ȣ����ϳǣ���ƽɽׯ����ǧ��ɽ�ȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 6 : file = read_file("/dadao/f");
			message("channel:rumor",HIR"���ٸ����ġ�������ɽׯ����ˮ���ȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 7 : file = read_file("/dadao/g");
			message("channel:rumor",HIR"���ٸ����ġ���������Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 8 : file = read_file("/dadao/h");
			message("channel:rumor",HIR"���ٸ����ġ�����ɽĿǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 9 : file = read_file("/dadao/i");
			message("channel:rumor",HIR"���ٸ����ġ���ɳĮ������ɵȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 10 : file = read_file("/dadao/j");
			message("channel:rumor",HIR"���ٸ����ġ�������ɽׯ����Ѫɽׯ�������µȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 11 : file = read_file("/dadao/k");
			message("channel:rumor",HIR"���ٸ����ġ�����÷ɽׯ������ç�֣��Ϻ��ȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 12 : file = read_file("/dadao/l");
			message("channel:rumor",HIR"���ٸ����ġ�����ɽ��������ɽ���ȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 13 : file = read_file("/dadao/m");
			message("channel:rumor",HIR"���ٸ����ġ���̩ɽ������կ�ȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 14 : file = read_file("/dadao/n");
			message("channel:rumor",HIR"���ٸ����ġ�������С��һ��·���½�������ֵȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 15 : file = read_file("/dadao/o");
			message("channel:rumor",HIR"���ٸ����ġ���������ɽ�ȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			//-------------------------------------------
			case 16 : file = read_file("/dadao/p");
			message("channel:rumor",HIR"���ٸ����ġ�����ɽ��ħ�̵ȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 17 : file = read_file("/dadao/q");
			message("channel:rumor",HIR"���ٸ����ġ������壬ɱ��ׯ�����Ƶ��ȵ�Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			case 18 : file = read_file("/dadao/r");
			message("channel:rumor",HIR"���ٸ����ġ����߳Ǽ��ܱ����Ŀǰ��������Ᵽ������������ص�����ʩ��\n"NOR, users());
			break;
			//-------------------------------------------
			default: message("channel:rumor",HIR"���ٸ����ġ��������񰲣�����̫ƽ��\n"NOR, users());
		}
		roomlines = explode(file,"\n");
		location = roomlines[random(sizeof(roomlines))];
		dadao= new("/dadao/npc/dadao");
		message("channel:rumor",HIM"��ҥ�ԡ�����˵"+dadao->name()+"�ֵ������к����ˣ�����\n"NOR, users());
		dadao->move(location);
	}
	return;
}
int fenbu_dadao()
{
	object *ob_list;
	int i;
	ob_list = children("/dadao/npc/dadao");
	for(i=0; i<sizeof(ob_list); i++)
	if(environment(ob_list[i]))
	{
		message_vision("$N����һЦ��˵��������Ҫȥ�������ˣ�\n$N�Ҵ�ææ���뿪�ˣ�\n",ob_list[i]);
		destruct(ob_list[i]);
	}
}

