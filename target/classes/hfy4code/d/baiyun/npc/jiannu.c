 // banker.c
#include <ansi.h>
inherit NPC;
inherit F_BANKPAWNOWNER;
inherit F_VENDOR;
string ask_me(object who); 
void create()

{
    set_name("��ū" , ({ "swords slave","slave" }) );
    set("nickname",CYN"ǧ�ذ��ƿ�����"NOR);
    set("long", "�����Ƶ�Ϊ��֪��ʱ�����������û��֪�����������ϣ�Ҳû��֪������Ҷ\n�³ǵĹ�ϵ��ֻ֪������û�����������ڽ��ַ����������ƺ�ֻ�Ǿ�������\n������ɨ��ڣ���ո�һ�գ��긴һ�ꡣ\n");
    set("attitude", "friendly");
    set("age", 123);
    set("no_busy", 8);
        set("gender", "����" );
        create_family("���Ƴ�",1, "��ڣ�ػ���");
        set("chat_chance", 1);
        set("chat_msg", ({
        "��ū���ű�������������ز����Ž����е�ÿһ�ѽ���\n",
        }) );
    set("per",10);
    set("class", "baiyun");
    set("combat_exp", 30000000);
    set_skill("dodge", 200);
    set_skill("feixian-steps", 200);
    set_skill("feixian-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("henglian", 200);
    map_skill("iron-cloth","henglian");
    map_skill("sword","feixian-sword");
    map_skill("dodge","feixian-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) ); 
        setup();
    carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}    
void init()
{
        ::init();
        
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
        add_action("do_vendor_list","list");
        add_action("do_loan","loan");
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
} 
int accept_fight(object me)
{
        command("heng");
        kill_ob(me);
        return 1;
}
       
