#include <ansi.h>
inherit SMART_NPC;
inherit F_PAWNOWNER;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
//      set("title","��������");
        set("nickname","��⣬�ع⣬��Ҳ��");
        set("long", "һ���ɰ˵ĺ������ڹ�̨�����Ŀ�������ȸ������ϡ���˫�����������
���滹�����˺����׵�ë�����ֱ��ϥ�ǡ�\n");
        set("age",45);
        set("attitude", "friendly");
        set("combat_exp", 4500000);
        set("dungeon_npc","eren");
                        
        set("max_atman",1000);
        set("atman",1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
                
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,180,0,"/d/eren2/npc/obj/","fighter_u","dragonstrike");
        set_name("��ԯ����",({"sanguang","san guang"}));
        set("age",40);
        set("gender","����");
   set("str",50);
        set("force_factor",100);
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{       
        ::init();
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem"); 
}    
