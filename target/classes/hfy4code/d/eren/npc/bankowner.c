 // banker.c
#include <ansi.h> 
inherit NPC;
inherit F_BANKOWNER; 
void create()
{
        set_name("�Ϲ�ʮ����", ({ "shisi" }) );
        set("title", RED "Ǯׯ����"NOR);
        set("gender", "����" );
        set("age", 22);
        set("richness",5000000);
        set("cps", 30);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("long",
                
                "��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����Ϲ�ʮ������Ǯׯ���١�\n"); 
        set("combat_exp", 2000000);
        set("attitude", "friendly"); 
        set("max_atman", 1000);
        set("atman", 1000);             
        set("max_force", 1000); 
        set("force", 1000);             
        set("max_mana", 1000);
        set("mana", 1000);              
        set("force_factor",50);
                
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("doomstrike", 150);
        set_skill("doomsteps", 150);
        
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");
        
        set("inquiry", ([
                "����" : "����ɽ���������������������Ӱ��ȥ���٣�\n",
                "rob" : "����ɽ���������������������Ӱ��ȥ���٣�\n",
        ]) ); 
        setup();
        
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{
        ::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
        add_action("do_loan","loan");
        add_action("do_transfer","transfer");
}       
