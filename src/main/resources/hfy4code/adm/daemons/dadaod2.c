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
			message("channel:gab",HIG"�����ƴ�������칫�ҡ������Ƴ���Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 2 : file = read_file("/dadao/b");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ��������ţ����𵺣��������ȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 3 : file = read_file("/dadao/c");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ������ɱ��������ȵȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 4 : file = read_file("/dadao/d");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ�����԰�壬�䵱ɽ�ȵ���Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 5 : file = read_file("/dadao/e");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ����ٻ��ȣ����ϳǣ���ƽɽׯ����ǧ��ɽ�ȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 6 : file = read_file("/dadao/f");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ�������ɽׯ����ˮ���ȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 7 : file = read_file("/dadao/g");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ���������Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 8 : file = read_file("/dadao/h");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ�����ɽĿǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 9 : file = read_file("/dadao/i");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ���ɳĮ������ɵȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 10 : file = read_file("/dadao/j");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ�������ɽׯ����Ѫɽׯ�������µȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 11 : file = read_file("/dadao/k");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ�����÷ɽׯ������ç�֣��Ϻ��ȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 12 : file = read_file("/dadao/l");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ�����ɽ��������ɽ���ȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 13 : file = read_file("/dadao/m");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ���̩ɽ������կ�ȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 14 : file = read_file("/dadao/n");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ�������С��һ��·���½�������ֵȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 15 : file = read_file("/dadao/o");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ���������ɽ�ȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			//-------------------------------------------
			case 16 : file = read_file("/dadao/p");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ�����ɽ��ħ�̵ȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 17 : file = read_file("/dadao/q");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ������壬ɱ��ׯ�����Ƶ��ȵ�Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			case 18 : file = read_file("/dadao/r");
			message("channel:gab",HIG"�����ƴ�������칫�ҡ����߳Ǽ��ܱ����Ŀǰ��������Ᵽ������СϺ������ص�����ʩ��\n"NOR, users());
			break;
			//-------------------------------------------
			default: message("channel:gab",HIG"�����ƴ�������칫�ҡ��������񰲣�����̫ƽ��\n"NOR, users());
		}
		roomlines = explode(file,"\n");
		location = roomlines[random(sizeof(roomlines))];
		dadao= new("/dadao/npc/dadao2");
		message("channel:gab",HIB"��ҥ�ԡ�����˵"+dadao->name()+"�ֵ������к����ˣ�����\n"NOR, users());
		dadao->move(location);
	}
	return;
}
int fenbu_dadao()
{
	object *ob_list;
	int i;
	ob_list = children("/dadao/npc/dadao2");
	for(i=0; i<sizeof(ob_list); i++)
	if(environment(ob_list[i]))
	{
		message_vision("$N����һЦ��˵��������Ҫȥ�������ˣ�\n$N�Ҵ�ææ���뿪�ˣ�\n",ob_list[i]);
		destruct(ob_list[i]);
	}
}

