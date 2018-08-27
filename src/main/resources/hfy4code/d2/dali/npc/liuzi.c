// banker.c

#include <ansi.h>

inherit NPC;
inherit F_BANKPAWNOWNER;
inherit F_VENDOR;
string ask_me(object who);

void create()
{
        set_name("С����", ({ "liuzi" }) );
        set("title", "�����ϰ�");
        set("gender", "����" );
        set("age", 20);
        set("richness",10000000);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 53);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("long",
"С�����Ǹ��ǳ����������ˡ�\n"
                );

        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("env/wimpy", 70);

        set("max_atman", 1000);         set("atman", 1000);             
set("atman_factor", 3);
        set("max_force", 1000);         set("force", 1000);             
set("force_factor", 3);
        set("max_mana", 1000);          set("mana", 1000);              
set("mana_factor", 3);

        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("shortsong-blade", 100);
//        set_skill("fall-steps", 100);
//        set_skill("bolomiduo", 100);
        set_skill("blade", 200);
        map_skill("force", "bolomiduo");
//        map_skill("dodge", "fall-steps");
//      map_skill("parry", "shortsong-blade");
//        map_skill("blade", "shortsong-blade");
        
        setup();
        
//        carry_object(__DIR__"obj/huadao")->wield();
        carry_object("/obj/cloth")->wear();

        add_money("gold", 10);
}
void init()
{
        ::init();
//       add_action("do_convert", "convert");
//        add_action("do_deposit", "deposit");
//        add_action("do_balance", "balance");
//        add_action("do_withdraw", "withdraw");
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
        add_action("do_vendor_list","list");
        add_action("do_loan","loan");
}
int accept_fight(object me)
{
        command("say ��... Ҫ������ɣ����ǽ�����û��˼��");
        command("grin");
        kill_ob(me);
        return 1;
}