#include <ansi.h>
inherit SMART_NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("title","���а���");
        set("long", "���а���֮�ף�������⣬����������\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 4800000);
        
        set("str",40);  
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",110); 
        set("reward_npc", 1);
        set("difficulty", 5); 
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30); 
        set("inquiry", ([
                "������" : "������ǵ�һ���Ҵ�����˹ȵ��������ˡ�\n",
                "���˹�" : "ʮ�����ɢ��ɢ�������������˹�����̫ƽ���ˡ�\n",
        ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ƽ������������书��ߣ����������壬С����������������ĸ���
��������Ȼ���壬����������ɷ����\n",
                
        }) );
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
         
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,170,1,"/d/eren2/npc/obj/","fighter_u","dragonstrike");
   set_name("��ƽ",({"yang ping"}));
        set("force_factor",50);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/hat")->wear();
        
}       
