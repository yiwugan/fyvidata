 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void healing(); 
void create()
{
        set_name("ŷ��˷", ({ "ouyang shuo" }) );
        set("gender", "����" );
        set("age", 39);
        set("title", MAG"�ϵ���˪������"NOR);
        set("long",
                "һ����������������ˣ���̸ֹ�����š�\n");
        set("combat_exp", 2500000);
        set("attitude", "friendly");
        set("class","beggar");
        set("per",30); 
        set("force",1800);
        set("max_force",1800);
        set("force_factor",80);
        set("str",36);
        
        set("vendor_goods", ([
        __DIR__"obj/shuangyi": 10,
        __DIR__"obj/dragonsword": 10,
        __DIR__"obj/dragonwhip": 10,
        __DIR__"obj/fengblade": 10,
        __DIR__"obj/duanshan": 10,
        __DIR__"obj/meispear": 10,  
        __DIR__"obj/pilihammer": 10,      
        ]) );
        
        
        set_skill("pyrobat-steps",200);
        set_skill("dodge",140);
        set_skill("parry",140);
        set_skill("unarmed",140);
        set_skill("dragonstrike",180);
        set_skill("move",150);
        
        map_skill("move","pyrobat-steps");
   map_skill("unarmed","dragonstrike");
        map_skill("dodge","pyrobat-steps");
        
        
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xianglongwuhui" :),
                }) );
        
        setup();
        carry_object(__DIR__"obj/oucloth")->wear();
} 
void init()
{
        add_action("do_vendor_list", "list");
        ::init();
}  
void reset()
{
        set("vendor_goods", ([
        __DIR__"obj/shuangyi": 10,
        __DIR__"obj/dragonsword": 10,
        __DIR__"obj/dragonwhip": 10,
        __DIR__"obj/fengblade": 10,
        __DIR__"obj/duanshan": 10,
        __DIR__"obj/meispear": 10,  
        __DIR__"obj/pilihammer": 10,  
             
        ]) );
}      
