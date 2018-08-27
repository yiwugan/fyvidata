 inherit NPC;
#include <ansi.h> 
void create()
{
        object armor,weap;
        set_name("С��", ({ "xiao si" }) );
        set("gender", "����");
        set("age", 25);
        set("long",
"̫����ʮ�Ķ���ܶ��������������ү�����µ�����С�ˡ�\n"
);
                  
        set("attitude", "friendly");
        set("score", 0);
        set("class","yinshi");
        
        set("combat_exp", 2000000);        
        set("int", 30);
        set("cps", 40);
        set("spi", 30);
        set("fle",50);
        set("str",36);
        
        set("force", 1000);
        set("max_force",1000);
        set("force_factor", 60);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
        
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               (: perform_action ("whip.tianleiyiji") :),
        }) ); 
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 160);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
        set_skill("whip",160);        
        set_skill("qidaoforce", 150);
        set_skill("five-steps",120);
        set_skill("thunderwhip",140);
        set_skill("dragonstrike",140);
                
        map_skill("unarmed","dragonstrike");
        map_skill("force", "qidaoforce");
        map_skill("dodge","five-steps");
        map_skill("move","five-steps");
        map_skill("whip","thunderwhip");
        map_skill("parry","thunderwhip");
        
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(3));
        
        weap=new("/obj/weapon/whip");
        weap->set_name("�����",({"whip"}) );
        weap->move(this_object());
        weap->wield();
        
        armor=new("/obj/armor/cloth");
        armor->set_name("�Ҳ���",({"cloth"}) );
        armor->move(this_object());
        armor->wear();
}       
