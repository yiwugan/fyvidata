// force_book.c

inherit ITEM;

void create()
{
	set_name("�����ؼ�", ({ "lanhuabook" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
			"�ᵽһЩ����ʲ��ġ�\n");
		set("value", 70);
		set("material", "paper");
		set("skill", ([
			"name": 		"lanhua-sword",		// name of the skill
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
