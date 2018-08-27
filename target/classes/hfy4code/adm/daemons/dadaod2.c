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
			message("channel:gab",HIG"【风云大米清理办公室】：风云城中目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 2 : file = read_file("/dadao/b");
			message("channel:gab",HIG"【风云大米清理办公室】：月行门，蝙蝠岛，长春岛等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 3 : file = read_file("/dadao/c");
			message("channel:gab",HIG"【风云大米清理办公室】：黑松堡，帝王谷等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 4 : file = read_file("/dadao/d");
			message("channel:gab",HIG"【风云大米清理办公室】：桃园村，武当山等地中目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 5 : file = read_file("/dadao/e");
			message("channel:gab",HIG"【风云大米清理办公室】：百花谷，济南城，清平山庄还有千佛山等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 6 : file = read_file("/dadao/f");
			message("channel:gab",HIG"【风云大米清理办公室】：霸王山庄，神水宫等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 7 : file = read_file("/dadao/g");
			message("channel:gab",HIG"【风云大米清理办公室】：少林寺目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 8 : file = read_file("/dadao/h");
			message("channel:gab",HIG"【风云大米清理办公室】：嵩山目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 9 : file = read_file("/dadao/i");
			message("channel:gab",HIG"【风云大米清理办公室】：沙漠中天枫派等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 10 : file = read_file("/dadao/j");
			message("channel:gab",HIG"【风云大米清理办公室】：幽灵山庄，铁血山庄，大昭寺等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 11 : file = read_file("/dadao/k");
			message("channel:gab",HIG"【风云大米清理办公室】：万梅山庄，沼泽，莽林，南海等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 12 : file = read_file("/dadao/l");
			message("channel:gab",HIG"【风云大米清理办公室】：黄山，沉香镇，山西等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 13 : file = read_file("/dadao/m");
			message("channel:gab",HIG"【风云大米清理办公室】：泰山，老云寨等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 14 : file = read_file("/dadao/n");
			message("channel:gab",HIG"【风云大米清理办公室】：无名小镇，一环路，新疆，快活林等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 15 : file = read_file("/dadao/o");
			message("channel:gab",HIG"【风云大米清理办公室】：富贵，狼山等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			//-------------------------------------------
			case 16 : file = read_file("/dadao/p");
			message("channel:gab",HIG"【风云大米清理办公室】：华山，魔教等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 17 : file = read_file("/dadao/q");
			message("channel:gab",HIG"【风云大米清理办公室】：三清，杀人庄，白云岛等地目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			case 18 : file = read_file("/dadao/r");
			message("channel:gab",HIG"【风云大米清理办公室】：边城及周遍地区目前江洋大盗猖獗，请大米小虾做好相关抵御措施．\n"NOR, users());
			break;
			//-------------------------------------------
			default: message("channel:gab",HIG"【风云大米清理办公室】：国富民安，天下太平．\n"NOR, users());
		}
		roomlines = explode(file,"\n");
		location = roomlines[random(sizeof(roomlines))];
		dadao= new("/dadao/npc/dadao2");
		message("channel:gab",HIB"【谣言】：听说"+dadao->name()+"又到江湖中横行了！！！\n"NOR, users());
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
		message_vision("$N哈哈一笑，说道：老子要去找乐子了．\n$N匆匆忙忙的离开了．\n",ob_list[i]);
		destruct(ob_list[i]);
	}
}

