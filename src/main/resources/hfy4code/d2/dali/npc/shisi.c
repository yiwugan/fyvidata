// banker.c

#include <ansi.h>

inherit NPC;
inherit F_BANKOWNER;

void create()
{
        set_name("�Ϲ�ʮ����", ({ "shisi" }) );
        set("title", HIY "Ǯׯ�ϰ�" NOR);
        set("gender", "����" );
        set("age", 22);
        set("richness",100000000);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("long",
                
                "��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����Ϲ�ʮ������Ǯׯ�ϰ�\n");

        set("combat_exp", 1000000);
        set("attitude", "friendly");

        set("max_atman", 1000);         set("atman", 1000);             
set("atman_factor", 3);
        set("max_force", 1000);         set("force", 1000);             
set("force_factor", 3);
        set("max_mana", 1000);          set("mana", 1000);              
set("mana_factor", 3);

        set("chat_chance", 3 );
        set("chat_msg", ({
                (: exert_function, "powerfade" :),
        }) );

    set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: perform_action, "dodge.huoliao" :),
                (: perform_action, "unarmed.tianxieliuzhang" :),
        }) ); 
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("celestrike", 100);
        set_skill("celestial", 100);
        set_skill("pyrobat-steps", 100);

        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");
        map_skill("dodge", "pyrobat-steps");
        
        set("inquiry", ([
                "����" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
                "rob" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
        ]) );

        setup();
        
//        carry_object(__DIR__"obj/jinzhuang")->wear();
 //       if (!random(2)) carry_object("questnew/obj/shuijing");

        add_money("gold", 10);
}

void init()
{
        ::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
        add_action("do_loan","loan");
}


int accept_object(object who, object ob)
{
 object silk;
 if(ob->query("pname") != who->query("name")) 
   {
    tell_object(who,query("name") + "˵�����ⲻ����ģ�û�ա�\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(who->query("letter") < time())
   {
    tell_object(who,query("name") + "˵�����������ˣ��������ˣ�\n");
    who->set_temp("nofly",0);
    return 1;
   }
 if(ob->query("toname") == query("name"))
  {
   command("say ��л��λԶ�����ܺ����������Ǹ���Ļغ�,�м�Ҫ���ܺã���\n");
   who->set_temp("nofly",0);
   silk = new("/d/dali/obj/huihan");
   silk->set("pname",who->query("name"));
   silk->move(who);
   return 1;
  }
 tell_object(who,query("name") + "˵�����ⲻ������Ҫ�ġ�\n");
 return 0;
}