inherit NPC;
int give_him();
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("°ÍÌìÊ¯", ({"ba tian shi","ba","batianshi" }) );
	set("gender", "ÄĞĞÔ" );
	set("age", 30);
	set("title", HIY "´óÀíË¾¿Õ" NOR);
	set("long",
		"ÕâÊÇ¸öÖĞÄêºº×Ó£¬Ä¿ÏÂÔÚ´óÀí¹úÎ»¾ÓË¾¿Õ¡£¡£\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set_skill("unarmed",50);
	set_skill("dodge",50);
        set("inquiry", ([
                "ÍÚÒ©" : (: give_him :),
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
message_vision("$NËµµÀ£º¡°´óÀí¹ú¿âÕıÈ±ÉÙÒ»Ğ©Ò©²Ä£®£®¡£¡±\n",this_object(),ob);
			break;
		case 1:
message_vision("$NÍûÁË$nÒ»ÑÛ£¬ÎÊµÀ£ºÄã¶ÔÍÚÒ©¸ĞĞËÈ¤Âğ£¿£®£®¡£\n",this_object(),ob);
			break;
	}
}

int give_him()
{
	object me , obj;
	me = this_player();
      
        if(me->query("gongxian") < 1000) 
           {
         message_vision("$NËµµÀ£ºÄãµÄ¹ÙÖ°²»¹»£¬²»ÄÜÉêÇëÕâÃ´ÖØÒªµÄÈÎÎñ£¡»¹ÊÇÈ¥×öÒ»Ğ©¼òµ¥µÄ°É¡£\n",this_object(), me);
         return 1;
            }
        if(me->query("gongxian") > 40000) 
           {
         message_vision("$NËµµÀ£ºÄãµÄ¹ÙÖ°Ì«´óÀ²£¬²»ÒªÉêÇëÕâÃ´¼òµ¥µÄÈÎÎñ£¡»¹ÊÇÈ¥×öÒ»Ğ©¸üÄÑµÄ°É¡£\n",this_object(), me);
         return 1;
            }
	obj = new("/d/dali/obj/yaochu");
	message_vision("$NËµµÀ£º¼ÈÈ»Äã¶ÔÍÚÒ©¸ĞĞËÈ¤£¬ÎÒ¾Í°ÑÕâÏîÖØÒªµÄ¹¤×÷½»¸¶¸øÄãÁË£¬
°ÍÌìÊ¯¸øÁË$nÒ»°ÑÒ©³ú¡£\n",this_object(), me);
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
//    write("°ÍÌìÊ¯ËµµÀ:Äã²»ÊÇ´óÀíµÜ×Ó£¬ÕâÖÖÀ´Àú²»Ã÷µÄ¶«Î÷ÎÒ²»Òª£¡\n");
//    return 1;
//  }
        if(!(ob->query("pname") == who->query("id")) )
        {
write("°ÍÌìÊ¯ËµµÀ:ÕâÒ©²Ä²»ÊÇÄãÍÚ³öÀ´µÄ£¬ÕâÖÖÀ´Àú²»Ã÷µÄ¶«Î÷ÎÒÃ»ÊÕÁË£¡\n");
		return 1;
	}
 if(who->query("gongxian") > 40000) 
           {
         write("°ÍÌìÊ¯ËµµÀ£ºÄãµÄ¹ÙÖ°Ì«´óÀ²£¬²»ÒªÉêÇëÕâÃ´¼òµ¥µÄÈÎÎñ£¡»¹ÊÇÈ¥×öÒ»Ğ©¸üÄÑµÄ°É¡£\n");
         return 1;
            }
if(ob->query("name") == "[1;33mÇ§ÄêÈË²Î[2;37;0m")
	{
command("say ÄãÎª¹ú¼Ò×ö³öÁË¹±Ï×£¬¸øÄãÓ¦¸ÃµÃµ½½±Àø£¡\n");
        who->add("combat_exp",exp);
	who->add("potential",pot);
        who->add("gongxian",gong);
        who->add("YQUEST",1);
        tell_object(who,HIW"Äã±»½±ÀøÁË£º\n" +
	chinese_number(exp) + "µãÊµÕ½¾­Ñé\n"+
        chinese_number(pot) + "µãÇ±ÄÜ\n"+
        chinese_number(gong) + "µã¶Ô´óÀí¹úµÄ¹±Ï×µã\n" NOR);
        return 1;
	}
if(ob->query("name") == "[1;32m³ÉĞÍ»´É½[2;37;0m")
	{
command("say ÄãÎª¹ú¼Ò×ö³öÁË¹±Ï×£¬¸øÄãÓ¦¸ÃµÃµ½½±Àø£¡\n");
        who->add("combat_exp",exp);
	who->add("potential",pot);
        who->add("gongxian",gong);
        who->add("YQUEST",1);
        tell_object(who,HIW"Äã±»½±ÀøÁË£º\n" +
	chinese_number(exp) + "µãÊµÕ½¾­Ñé\n"+
        chinese_number(pot) + "µãÇ±ÄÜ\n"+
        chinese_number(gong) + "µã¶Ô´óÀí¹úµÄ¹±Ï×µã\n" NOR);
        return 1;
	}
if(ob->query("name") == "[33mºÎÊ×ÎÚ¾«[2;37;0m")
	{
command("say ÄãÎª¹ú¼Ò×ö³öÁË¹±Ï×£¬¸øÄãÓ¦¸ÃµÃµ½½±Àø£¡\n");
        who->add("combat_exp",exp);
	who->add("potential",pot);
        who->add("gongxian",gong);
        who->add("YQUEST",1);
        tell_object(who,HIW"Äã±»½±ÀøÁË£º\n" +
	chinese_number(exp) + "µãÊµÕ½¾­Ñé\n"+
        chinese_number(pot) + "µãÇ±ÄÜ\n"+
        chinese_number(gong) + "µã¶Ô´óÀí¹úµÄ¹±Ï×µã\n" NOR);
        return 1;
	}
if(ob->query("name") == "[1;37mÕä¹ó±±ÜÎ[2;37;0m")
	{
command("say ÄãÎª¹ú¼Ò×ö³öÁË¹±Ï×£¬¸øÄãÓ¦¸ÃµÃµ½½±Àø£¡\n");
        who->add("combat_exp",exp);
	who->add("potential",pot);
        who->add("gongxian",gong);
        who->add("YQUEST",1);
        tell_object(who,HIW"Äã±»½±ÀøÁË£º\n" +
	chinese_number(exp) + "µãÊµÕ½¾­Ñé\n"+
        chinese_number(pot) + "µãÇ±ÄÜ\n"+
        chinese_number(gong) + "µã¶Ô´óÀí¹úµÄ¹±Ï×µã\n" NOR);
        return 1;
	}
        tell_object(who,"°ÍÌìÊ¯ËµµÀ£ºÎÒÀ´°ïÄãÈÓÁËËü°É£¬´óÀí¹ú¿â»áĞèÒªÕâÖÖ¿İÖ¦ÀÃ²İÂğ£¿\n");
        return 1;
}

