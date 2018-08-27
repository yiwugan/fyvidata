inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int give_him();
// int kill_him();
void create()
{
        set_name("»ªºÕôŞ", ({ "hua hegen", "hua"}) );
//        set("nickname", "");
//        set("pursuer", 1);
        set("title","´óÀíË¾Í½");
        set("gender", "ÄĞĞÔ" );
        set("age", 46);
        set("agi",30);
        set("str", 22);
        set("per", 28);
        set("int",24);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 40);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_atman", 5000);
        set("atman", 5000);
        set("long",
"
ÕâÊÇ¸öÖĞÄêºº×Ó£¬Ä¿ÏÂÔÚ´óÀí¹úÎ»¾ÓË¾Í½¡£\n"
        );
        create_family("´óÀí", 12, "µÜ×Ó");
        set("chat_chance_combat", 20);
//        set("chat_msg_combat", ({
//                (: perform_action, "blade.liuyunxiyu" :)
//        }) );
        set("combat_exp", 1000000);
        set_skill("dodge", 110);
        set_skill("move",140);
        set_skill("force", 140);
        set_skill("sword", 110);
        set_skill("literate", 120);
        set_skill("unarmed",110);
//      set_skill("tianlong-shengong", 110);
        set_skill("duan-yiyangzhi", 110);
        map_skill("force", "tianlong-shengong");
        map_skill("unarmed", "duan-yiyangzhi");
//        map_skill("parry", "");        
// map_skill("parry","huanyu-blade");
//       map_skill("blade", "huanyu-blade");    
        set("inquiry", ([
                "²è»¨" : (: give_him :),
                "chahua" : (: give_him :)
        ]));
        setup();
     carry_object(__DIR__"obj/guanfu")->wear();
//  carry_object(__DIR__"obj/long-blade")->wield();

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
message_vision("$NËµµÀ£º¡°´óÀí»Ê¹¬ÕıĞèÒªÒ»Ğ©ÉÏµÈ²è»¨£®£®¡£¡±\n",this_object(),ob);
                        break;
                case 1:
message_vision("$NÍûÁË$nÒ»ÑÛ£¬ÎÊµÀ£ºÄã¶ÔÑø²è»¨¸ĞĞËÈ¤Âğ£¿£®£®¡£\n",this_object(),ob);
                        break;
        }
}
int give_him()
{
        object me , obj;
        me = this_player();
 
        if(me->query("gongxian") > 1000) 
           {
         message_vision("$NËµµÀ£ºÄãµÄ¹ÙÖ°Ì«´óÀ²£¬²»ÒªÉêÇëÕâÃ´¼òµ¥µÄÈÎÎñ£¡»¹ÊÇÈ¥×öÒ»Ğ©¸üÄÑµÄ°É¡£\n",this_object(), me);
         return 1;
            }
//      if( !query("given")) {
        obj = new("/questnew/huapen");
        message_vision("$NËµµÀ£º¼ÈÈ»Äã¶ÔÑø²è»¨¸ĞĞËÈ¤£¬ÎÒ¾Í°ÑÕâÏîÖØÒªµÄ¹¤×÷½»¸¶¸øÄãÁË£¬
»ªºÕôŞ¸øÁË$nÒ»¸ö¾«ÖÂ»¨Åè¡£\n",this_object(), me);
        obj->move(me);
//      set("given",1);
        return 1;
//      }
//      return 0;
}


int accept_object(object who, object ob)
{
  int  exp, pot, gong, score;
  exp = random(100)+10000;
  pot = exp / 5 + 100;
  gong = exp / 50 + 2;
  score = exp / 50 +5;
//   if(!(who->query("class") == "dali") )
// {
//   write("»ªºÕôŞËµµÀ:Äã²»ÊÇ´óÀíµÜ×Ó£¬ÕâÖÖÀ´Àú²»Ã÷µÄ¶«Î÷ÎÒ²»Òª£¡\n");
//     return 0;
// 115
//  }
  if(!(ob->query("pname") == who->query("id")) )
    {
     write("»ªºÕôŞËµµÀ:Õâ²è»¨²»ÊÇÄãÖÖ³öÀ´µÄ£¬ÕâÖÖÀ´Àú²»Ã÷µÄ¶«Î÷ÎÒÃ»ÊÕÁË£¡\n");
     return 1;
    }
  if(ob->query("name") == "[1;33m¼«Æ·²è»¨[2;37;0m")
    {
     tell_object(who, "»ªºÕôŞËµµÀ£ºÄãÎª¹ú¼Ò×ö³öÁË¹±Ï×£¬¸øÄãÓ¦¸ÃµÃµ½½±Àø£¡\n");
        who->add("combat_exp",exp);
        who->add("potential",pot);
//      who->add("score",score);
        who->add("gongxian",gong);
        tell_object(who,HIW"Äã±»½±ÀøÁË£º\n" +
        chinese_number(exp) + "µãÊµÕ½¾­Ñé\n"+
        chinese_number(pot) + "µãÇ±ÄÜ\n"+
        chinese_number(gong) + "µã¶Ô´óÀí¹úµÄ¹±Ï×µã\n" NOR);
//      chinese_number(score) + "µã×ÛºÏÆÀ¼Û¡£\n"
        return 1;
    }
  if(ob->query("name") == "[1;32mÒ»Æ·²è»¨[2;37;0m")
    {
     tell_object(who, "»ªºÕôŞËµµÀ£ºÄãÎª¹ú¼Ò×ö³öÁË¹±Ï×£¬¸øÄãÓ¦¸ÃµÃµ½½±Àø£¡\n");
        who->add("combat_exp",exp*3/4);
        who->add("potential",pot*3/4);
//      who->add("score",score*3/4);
        who->add("gongxian",gong*3/4);
        tell_object(who,HIW"Äã±»½±ÀøÁË£º\n" +
        chinese_number(exp*3/4) + "µãÊµÕ½¾­Ñé\n"+
        chinese_number(pot*3/4) + "µãÇ±ÄÜ\n"+
        chinese_number(gong*3/4) + "µã¶Ô´óÀí¹úµÄ¹±Ï×µã\n" NOR);
//        chinese_number(score*3/4) + "µã×ÛºÏÆÀ¼Û¡£\n"
        return 1;
    }
  if(ob->query("name") == "[33m¶şÆ·²è»¨[2;37;0m")
    {
     tell_object(who, "»ªºÕôŞËµµÀ£ºÄãÎª¹ú¼Ò×ö³öÁË¹±Ï×£¬¸øÄãÓ¦¸ÃµÃµ½½±Àø£¡\n");
//     command("say ÄãÎª¹ú¼Ò×ö³öÁË¹±Ï×£¬¸øÄãÓ¦¸ÃµÃµ½½±Àø£¡\n");
        who->add("combat_exp",exp/2);
        who->add("potential",pot/2);
//      who->add("score",score/2);
        who->add("gongxian",gong/2);
        tell_object(who,HIW"Äã±»½±ÀøÁË£º\n" +
        chinese_number(exp/2) + "µãÊµÕ½¾­Ñé\n"+
        chinese_number(pot/2) + "µãÇ±ÄÜ\n"+
        chinese_number(gong/2) + "µã¶Ô´óÀí¹úµÄ¹±Ï×µã\n" NOR);
//        chinese_number(score/2) + "µã×ÛºÏÆÀ¼Û¡£\n"
        return 1;
    }
  if(ob->query("name") == "[1;37mÈıÆ·²è»¨[2;37;0m")
    {
     tell_object(who, "»ªºÕôŞËµµÀ£ºÄãÎª¹ú¼Ò×ö³öÁË¹±Ï×£¬¸øÄãÓ¦¸ÃµÃµ½½±Àø£¡\n");
//     command("say ÄãÎª¹ú¼Ò×ö³öÁË¹±Ï×£¬¸øÄãÓ¦¸ÃµÃµ½½±Àø£¡\n");
        who->add("combat_exp",exp/4);
        who->add("potential",pot/4);
//      who->add("score",score/4);
        who->add("gongxian",gong/4);
        tell_object(who,HIW"Äã±»½±ÀøÁË£º\n" +
        chinese_number(exp/4) + "µãÊµÕ½¾­Ñé\n"+
        chinese_number(pot/4) + "µãÇ±ÄÜ\n"+
        chinese_number(gong/4) + "µã¶Ô´óÀí¹úµÄ¹±Ï×µã\n" NOR);
//        chinese_number(score/4) + "µã×ÛºÏÆÀ¼Û¡£\n"
        return 1;
    }
  tell_object(who,"»ªºÕôŞËµµÀ£º´óÀí»Ê¹¬»áĞèÒªÕâÖÖÀÃ²è»¨Âğ£¿\n");
  return 0;
}
