// force_book.c

inherit ITEM;

void create()
{
	set_name("兰花秘籍", ({ "lanhuabook" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"这本旧书的纸张都已经泛黄了，上面只有一些字迹模糊的字句，似乎\n"
			"提到一些拳脚功夫什麽的。\n");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 		"binghuostrike",		// name of the skill
                        "exp_required": 1000000,                              // minimum combat experience required
											// to learn this skill.
                        "sen_cost":             100,                             // gin cost every time study this
                        "difficulty":   80,                             // the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    31                              // the maximum level you can learn
											// from this object.
		]) );
	}
}
