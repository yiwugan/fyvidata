#include <ansi.h>
inherit "/d/taiping/npc/smart_npc";
inherit INQUIRY_MSG; 
void create()
{
        set_name("���",({"feng hao","feng"}));
        set("title","�Һ���ʵ");
        set("long","
����Ǿջ�԰������һ��ƽ����ʵ������˵������������������ֻҪ
�ϲ�һ�����£����������������ٶȴ�����ǣ��һƥ��װ�����Ŀ���\n");
        
        set("gender","����");
        set("group","juhua");
        
        set("age",42);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        
        set("force",1000);
        set("max_force",1000);
        set("force_factor",80);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",3500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                
        ]));
        
        set("nb_chat_chance", 100);
           set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(30) :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({ 
        }) );                   
        
        auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_u","nine-moon-claw",1);
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
 
}    
