/*
	User_weapond
	Created	by snowman@SJ 21/04/2001

   Copyright 1997-2001 ShuJian MUD Wizard Group.
   All rights reserved.

*/

#include <ansi.h>
inherit F_SAVE;

#include <user_weapon.h>


mapping	make_user_weapon_random(string type, int qua, string material);
object make_weapon(object me, mixed type, int qua, string material);
void weapon_rank(object ob, object me);

static int imbue_sta = 0;
static string imbue = "";
static int close = 0;

void imbue_s(string arg)
{
	imbue =	arg;	
}

void imbue_q(int arg)
{
	imbue_sta = arg;	
}

int query_close(){ return close; }

int set_close()
{
	if( close != 0 ) close = 0;
	else close = 1;
	return close;
}

protected void delete_user_weapon(object me, string name, string text, int p, int b, int i)
{
	if( !me ) return;
	if( text )
		write(HIW"����" + name + HIW"��Ϊ��" + text + "����ϵͳȡ����\n"NOR);
	if( b ){
		write("����" + MONEY_D->money_str(b) + "�Ĵ�");
		me->add("balance", b);
	}
	if( i ) {
		write("����"+chinese_number(-i)+"�δ���Ļ��ᡣ");
		me->add("user_weapon_imbued", i);
	}
	
	me->delete("user_weapon");
	me->save();
	log_file("quest/i_bug", sprintf("%s -> %s with %d damage, deleted on %s.\n", 
		geteuid(me), name, p,  ctime(time()) ));
}
	
void check_user_weapon(object me)
{
	object weapon, *clone;
	string id;
	mapping	u_map, w_map;
	int j;
	
	if( close != 0 ) return;
	
	id = geteuid(me);
	
	// Modified
	if( !mapp(u_map = copy(me->query("user_weapon"))) ){
		me->delete("user_weapon");
		log_file("quest/imbue_delete", sprintf("%s(%d) -> Bad mapping, deleted on %s.\n", 
			geteuid(me), me->query("user_weapon_imbued"), ctime(time()) ));
		return;
	}
	
	if( !u_map["saved"] ){
		if( mapp(u_map = u_map["user_weapon"]) && intp(u_map["damage"]))
			j = u_map["damage"];
		else j = me->query("user_weapon/weapon_prop/damage");
		j = 300000 * (1+j);
		me->delete("user_weapon");
		me->add("balance", j );
		write(WHT"ϵͳ�Ѿ�ȡ������Ĳ�����������Ϊ��������Ĵ��������" + MONEY_D->money_str(j) + "��\n"NOR);
		return;
	}
	
	if( me->query("env/no_weapon") ) return;
	
	clone =	filter_array(children(USER_WEAPON), (: clonep :));
	for( j = 0; j < sizeof(clone); j++ ){
		if ( clone[j]->query("user_weapon") == id 
		&& clone[j]->query("saved") == id )
			return;
	}
		
	w_map =	DEFAULT_SETTINGS;
	switch(u_map["imbued"]){
		case 5: w_map += copy(SPECIAL_B); break;
		case 4: w_map += copy(SUPER_B); break;
		case 3: w_map += copy(GREAT_B); break;
		case 2: w_map += copy(GOOD_B); break;
		default: break;
	}
	w_map += u_map;
	
	weapon = make_weapon(me, w_map,	0, 0);
	if( weapon ){
		weapon_rank(weapon, me);
		weapon->move(me);
	}

}

object make_weapon(object me, mixed type, int qua, string material)
{
	mapping	w_mp;
	object wp;
	string str = "", st;
	int w, p, new_w;
	
	if( stringp(type) ){
		w_mp = make_user_weapon_random(type, qua, material);
	
		if( !mapp(w_mp)	){
			write("Error! no w_mp! \n");
			return 0;
		}
		/*
		if( w_mp["wield_str"] > me->query_str() )
			w_mp["wield_str"] = me->query_str();
		if( w_mp["wield_maxneili"] > me->query("max_neili") )
			w_mp["wield_maxneili"] = me->query("max_neili");
		*/
		new_w = 1;
		
		special_st = name_st = ({ });
	}
	
	else if( mapp(type) ){
		w_mp = type;
		if( qua	){
			mp = w_mp;
			special_weapon_status(qua);	
			w_mp = copy(mp);
			mp = 0;
			if( sizeof(name_st) > 0 )
				w_mp["name_st"]	+= name_st[0];
			special_st = name_st = ({});
		}
	}
	else return 0;
	
	if( stringp(w_mp["long2"]) )
		str = w_mp["long2"];
	str += "����һ����" + s_good(w_mp["rigidity"]) + "��Ӳ��"; 
	
	switch(w_mp["material"]){
		case "xuantie":	str += BLU"����"NOR; break;
		case "supersteel": str += "��������"; break;
		case "greatsteel": str += "������"; break;
		case "softsteel": str += "����"; break;
		case "bamboo": str += "����"; break;
		case "wood": str += "̴ľ"; break;
		default: str +=	"����";	break;
	}
	w = w_mp["weight"];
	str +=	"�Ƴɣ���"+sprintf("%s", chinese_number(w/500)+"��"+chinese_number((w%500)/50)+"��"+chinese_number((w%50)/5)+"Ǯ")+"��"+w_mp["name"]+"��\n";

	//mm = w_mp;
	if( new_w )
		p = w_mp["weapon_prop/damage"];
	else if( intp(w_mp["weapon_prop"]["damage"]) )
		p = w_mp["weapon_prop"]["damage"];
	else p = 0;
	
	if( w_mp["imbued"] < 5 && p > 300 && !new_w ){
		delete_user_weapon(me, w_mp["name"], "ʹ��Bug��ʹ��������", p, 5000000, -2);
		return 0;
	}
	
	else if( p <= 0 && !new_w){
		delete_user_weapon(me, w_mp["name"], "ϵͳBug��ʹ��������", p, 5000000, -2);
		return 0;
	}
	
	str += "������"	+ ( w_mp["flag"]==4?s_good(w_mp["sharpness"])+"������":"" ) + "����"+ s_power(p) + "��������\n";
	str += "��������������֣���" 
		+ chinese_number(w_mp["wield_str"]) + "��" 
		+ chinese_number(w_mp["wield_maxneili"]) + "��"	
		+ chinese_number(w_mp["wield_neili"]) +	"��\n";	
	
	if( w_mp["name_st"] ){
		if( stringp(w_mp["name_st"]) ) 
			str += "�Լ�һ�Ź�׭�֡� "HIG +	w_mp["name_st"]	+ NOR" ��\n\n";
		else if( sizeof(w_mp["name_st"]) > 0	){
			st = implode(w_mp["name_st"][0..<1], "��");
			str += "�Լ�һ�Ź�׭�֡� "HIG +	st + NOR" ��\n\n";
		}
	}
	
	wp = new(USER_WEAPON);
	wp->set("weapon_mp", copy(w_mp));
	
	if( wp->weapon_setup(copy(w_mp)) ){
		wp->set("user_weapon",geteuid(me));
		wp->set("long",	str);
		wp->set_temp("apply/long", ({ str + "\n�ֱ��Ͽ��˼���С�֣�" + me->name(1) + "(" + capitalize(geteuid(me)) + ")\n" }));
		if( new_w ){
			log_file("quest/IMBUES", sprintf("%s(%d) imbued	%s(%s) with %d damage on %s.\n", 
				geteuid(me), me->query("user_weapon_imbued"), w_mp["name"], 
				w_mp["skill_type"], w_mp["weapon_prop/damage"],	ctime(time()) ));
			me->add("user_weapon_imbued", 1);
		}
		return wp;
	}
	else return 0;
	
}

// type	= weapon types.
// qua:	0 = normal, 1 =	good, 2	= great, 3 = super, 4 = special
mapping	make_user_weapon_random(string type, int qua, string material)
{
	string wp_name,	name;
	int i;
	
	mp = DEFAULT_SETTINGS;
	
	if( member_array(type, keys(WEAPON_MAP)) != -1 )
		mp += copy(WEAPON_MAP[type]); 
	else {
		write("Weapon Type out of range, ��֪ͨ	Snowman. \n");
		return 0;
	}
	
	mp["material"] = material;
	
	if( type == "sword" && (imbue == "special" || qua == 4)	){
		qua = 5;
		i = random(sizeof(Special_Class));
		wp_name	= keys(Special_Class)[i];
		mp += copy(SPECIAL_B);
		mp += Special_Class[wp_name];
	}
	
	else if( imbue == "super" || qua == 3 ){
		qua = 4;
		i = random(sizeof(Super_Class));
		wp_name	= keys(Super_Class)[i];
		// Basic status	for Super class	weapons.
		mp += copy(SUPER_B);
		mp += ([ "weapon_prop/damage":	110, ]);
		mp += Super_Class[wp_name];
		mp["id"] = ({ Super_Class[wp_name]["id"] + " " + type, Super_Class[wp_name]["id"], mp["b_id"], type });
	}
	
	else if( imbue == "great" || qua == 2 ){
		qua = 3;
		i = random(sizeof(Great_Class));
		wp_name	= keys(Great_Class)[i];
		// Basic status	for Great class	weapons.
		mp += copy(GREAT_B);
		mp += ([ "weapon_prop/damage":	70, ]);
		mp["id"] = ({ Great_Class[wp_name] + " " + type, Great_Class[wp_name], mp["b_id"], type	});
	}
	
	else if( imbue == "good" || qua	== 1 ){
		qua = 2;
		// Basic status	for good class weapons.
		wp_name	= G_3_class[random(sizeof(G_3_class))];
		mp += copy(GOOD_B);
		mp += ([ "weapon_prop/damage":	40, ]);
		mp["id"] = ({ "good "+type, "good", mp["b_id"] , type});
	}
	
	else {
		// Basic status	for normal class weapons.
		qua = 1;
		mp += ([ "weapon_prop/damage":	20, ]);
		wp_name	= mp["basic_name"];
		mp["id"] = ({ "normal "+type, "normal",	mp["b_id"], type });
	}
	imbue =	"";
	mp["basic_name"] = wp_name;
	
	if( qua != 5 ){
		while(qua--)
			special_weapon_status(0);
	}
	
	if( imbue_sta >	0 ){
		special_weapon_status(imbue_sta);
		imbue_sta = 0;
	}
	
	if( sizeof(special_st) > 0 ){
		special_st += ({ "" });
		name = special_st[random(sizeof(special_st))];
	}
	else name = "";
	
	mp["name"] = name + mp["basic_name"] + mp["name"] + NOR;
	mp["name_st"] =	name_st;
	
	mp["weapon_prop/damage"] = mp["weapon_prop/damage"]/2 + random(mp["weapon_prop/damage"]/2);
	if( mp["weapon_prop/damage"] > 300 && qua != 5 )
		mp["weapon_prop/damage"] = 300;
		
	i = sizeof(mp["weapon_prop"]);
	if( i <	1 ) i =	1;
	mp["value"] = (	mp["weapon_prop/damage"] * 300 ) * ( mp["rigidity"] + mp["sharpness"] +	2 ) * i	* ( mp["weight"] / 500 ) / 5;
	
	return mp;
}

#define total 100
mapping *ranks;

void create()
{
	seteuid(getuid());
	restore();
}

int remove()
{
	save();
	return 1;
}

string query_save_file()
{
	return "/log/quest/i_rank";
}

int sort_rank(mapping rank1, mapping rank2)
{
	reset_eval_cost(); // added by snowman@SJ
	return rank2["score"] - rank1["score"];
}

int clean_all()
{
	ranks = ({ });
	return remove();
}

void weapon_rank(object ob, object me)
{
	int i, score;
	mapping rank, wp;

	if( !me || !userp(me) || wiz_level(me) ) return;
	// ��ɾ��ԭ�ȼ�¼
	for (i = 0; i < sizeof(ranks); i++)
		if( (!ob && ranks[i]["owner"] == geteuid(me)) 
		|| wiz_level(ranks[i]["owner"]) 
		||  ranks[i]["owner"] == geteuid(me) 
		|| ranks[i]["score"] < 1
		|| ranks[i]["time"] < (time() - 259200)) {  // ��������
			ranks = ranks[0..i-1] + ranks[i+1..total];
		}

	if( !ob ) {
		save();
		return;
	}
	wp = copy(ob->query("weapon_mp"));
	score = wp["weapon_prop/damage"];
	if( !score ) score = wp["weapon_prop"]["damage"];
	score += wp["poisoned"]?4:0;
	score += wp["rigidity"] * 6;
	score += wp["sharpness"] * 7;
	score += sizeof(wp["weapon_prop"]) * 9;
	score += stringp(wp["name_st"])?10:0;
	
	if (!sizeof(ranks)) ranks = ({ });
	ranks = sort_array(ranks, (: sort_rank :));

	for (i = 0; i < sizeof(ranks); i++)
		if (score > ranks[i]["score"]) break;
	if (i > total) return;

	rank =  ([      "id":           wp["id"][0],
			"name":         wp["name"],
			"owner":       	geteuid(me),
			"owner_name":   me->query("name"),
			"score":        score,
			"time":		time() ]);
	if (!sizeof(ranks)) ranks = ({ rank });
	else ranks = ranks[0..i-1] + ({ rank }) + ranks[i..total];
	save();
}

string show_rank(object me, int j)
{
	int i;
	string str = "\n";

	str += "                    ��  �� �� �� �� �� �� ��  ��\n";
	str += "�������ө������������ߩ��������������ө��������ߩ��������ө���������\n";
	str += "�����Ω�       ��          ��       ��   ��   ��   ��   ���������۩�\n";
	str += "�ĩ����ة����������������������������ة������������������ة���������\n";
	if (j < 1) j = 10;
	if (j > total) j = total;
	if (j > sizeof(ranks)) j = sizeof(ranks);
	for (i = 0; i < j; i++)
		str += sprintf("��%s%|4d"NOR"  %|28s  %8s%-10s  %|8d" NOR "��\n",
				(ranks[i]["owner"] == me->query("id"))?HIY:"",
				i+1,
				ranks[i]["name"]+"("+capitalize(ranks[i]["id"])+")",
				ranks[i]["owner_name"],
				"("+capitalize(ranks[i]["owner"])+")",
				ranks[i]["score"]);
	str += "��������������������������������������������������������������������\n";
	return str;
}