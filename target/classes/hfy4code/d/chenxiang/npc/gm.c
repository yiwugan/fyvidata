 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�Ŷ�", ({ "zhang", "zhang en"}) );
        set("title", HIW "ؤ��ֶ����"NOR);
        set("gender", "����" );
        set("age", 34);
        set("cps",50);
        set("attitude","friendly");
        set("force_factor", 30); 
        set("long","ؤ��鲼���ϱ����Ŷ��������ڣ����������˷ֶ档\n");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xianglongwuhui" :)
        }) );
        set("combat_exp", 1000000);
        
        set_skill("move", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("unarmed",150);
        set_skill("doggiesteps",140);
        set_skill("dragonstrike",100);
        set_skill("huntunforce",100);
        
        map_skill("dodge", "doggiesteps");
        map_skill("move","doggiesteps");
        map_skill("force", "huntunforce");
        map_skill("unarmed", "dragonstrike"); 
        setup();
        carry_object(__DIR__"obj/7bagcloth")->wear(); 
}    
