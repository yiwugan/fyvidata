inherit NPC;
int give_him();
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("����ʯ", ({"ba tian shi","ba","batianshi" }) );
	set("gender", "����" );
	set("age", 30);
	set("title", HIY "����˾��" NOR);
	set("long",
		"���Ǹ����꺺�ӣ�Ŀ���ڴ����λ��˾�ա���\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set_skill("unarmed",50);
	set_skill("dodge",50);
        set("inquiry", ([
                "��ҩ" : (: give_him :),
                "wayao" : (: give_him :)
        ]));
	setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0:
message_vision("$N˵���������������ȱ��һЩҩ�ģ�������\n",this_object(),ob);
			break;
		case 1:
message_vision("$N����$nһ�ۣ��ʵ��������ҩ����Ȥ�𣿣�����\n",this_object(),ob);
			break;
	}
}

int give_him()
{
	object me , obj;
	me = this_player();
      
        if(me->query("gongxian") < 1000) 
           {
         message_vision("$N˵������Ĺ�ְ����������������ô��Ҫ�����񣡻���ȥ��һЩ�򵥵İɡ�\n",this_object(), me);
         return 1;
            }
        if(me->query("gongxian") > 40000) 
           {
         message_vision("$N˵������Ĺ�ְ̫��������Ҫ������ô�򵥵����񣡻���ȥ��һЩ���ѵİɡ�\n",this_object(), me);
         return 1;
            }
	obj = new("/d/dali/obj/yaochu");
	message_vision("$N˵������Ȼ�����ҩ����Ȥ���ҾͰ�������Ҫ�Ĺ������������ˣ�
����ʯ����$nһ��ҩ����\n",this_object(), me);
	obj->move(me);
	return 1;
}


int accept_object(object who, object ob)
{
  int  exp, pot, gong, score;
        exp = random(200)+2000;
  pot = exp / 5 + 20;
        gong = exp / 50 + 2;
//    if(!(who->query("class") == "dali") )
// {
//    write("����ʯ˵��:�㲻�Ǵ�����ӣ��������������Ķ����Ҳ�Ҫ��\n");
//    return 1;
//  }
        if(!(ob->query("pname") == who->query("id")) )
        {
write("����ʯ˵��:��ҩ�Ĳ������ڳ����ģ��������������Ķ�����û���ˣ�\n");
		return 1;
	}
 if(who->query("gongxian") > 40000) 
           {
         write("����ʯ˵������Ĺ�ְ̫��������Ҫ������ô�򵥵����񣡻���ȥ��һЩ���ѵİɡ�\n");
         return 1;
            }
if(ob->query("name") == "[1;33mǧ���˲�[2;37;0m")
	{
command("say ��Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp);
	who->add("potential",pot);
        who->add("gongxian",gong);
        who->add("YQUEST",1);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
        chinese_number(gong) + "��Դ�����Ĺ��׵�\n" NOR);
        return 1;
	}
if(ob->query("name") == "[1;32m���ͻ�ɽ[2;37;0m")
	{
command("say ��Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp);
	who->add("potential",pot);
        who->add("gongxian",gong);
        who->add("YQUEST",1);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
        chinese_number(gong) + "��Դ�����Ĺ��׵�\n" NOR);
        return 1;
	}
if(ob->query("name") == "[33m�����ھ�[2;37;0m")
	{
command("say ��Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp);
	who->add("potential",pot);
        who->add("gongxian",gong);
        who->add("YQUEST",1);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
        chinese_number(gong) + "��Դ�����Ĺ��׵�\n" NOR);
        return 1;
	}
if(ob->query("name") == "[1;37m�����[2;37;0m")
	{
command("say ��Ϊ���������˹��ף�����Ӧ�õõ�������\n");
        who->add("combat_exp",exp);
	who->add("potential",pot);
        who->add("gongxian",gong);
        who->add("YQUEST",1);
        tell_object(who,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
        chinese_number(gong) + "��Դ�����Ĺ��׵�\n" NOR);
        return 1;
	}
        tell_object(who,"����ʯ˵�������������������ɣ�����������Ҫ���ֿ�֦�ò���\n");
        return 1;
}

