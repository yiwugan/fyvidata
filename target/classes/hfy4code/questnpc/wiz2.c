 //QCed and Modified by Tie
#include <ansi.h>
inherit NPC;  
inherit F_VENDOR;
int tell_test(); 
void create()
{
         set_name("��ϲ����", ({ "luck", "facai" }) );
        set("gender", "����");
        set("title", HIC"��������"NOR);
        set("age", 26);
        set("long",
                "һ���˼����ģ����Ϊ�ң�������ɣ�Ķ��н��͡�\n");
        set("combat_exp", 50000000);
        set("attitude", "friendly");
       set("combat_exp", 8000000);
        set("score", 50000); 
        set("class", "taoist"); 
        set("str", 30);
        set("int", 33);
        set("cor", 45);
        set("cps", 30);
        set("spi", 30);
        set("per", 100);
                set("fle",      45); 
        set("force", 4000);
        set("max_force", 4000);
        set("force_factor", 50);
                set("max_gin",2800);
                set("max_sen",2800); 
                
                
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }));
        
        set_skill("literate", 100);
        set_skill("force", 180);
        set_skill("move", 120);
        set_skill("unarmed", 140);

        set_skill("parry", 150);
        set_skill("dodge", 200);
        set_skill("changelaw", 120);
        
        set_skill("taijiforce", 140);
        set_skill("taiji", 300);
        set_skill("five-steps", 200);
        map_skill("spells","qixing");
        map_skill("parry", "taiji-sword");

        map_skill("literate", "changelaw");
        map_skill("force", "taijiforce");
        map_skill("unarmed", "taiji"); 
        
    setup(); 
        carry_object("/obj/armor/cloth")->wear();
        
} 
