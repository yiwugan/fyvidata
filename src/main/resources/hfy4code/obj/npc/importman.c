#include <ansi.h>
inherit "/std/char/missionnpc.c";
void create()
{
        set_name("��Ҫ����", ({ "importman" }) );
        set("long",
                "������֯��һ����Ҫ����������������ڸ�����Ա��\n");
        set("cor",20);
        set("organization/����","а");
        set("max_kee",20000);
        set("kee",20000);
        set("max_sen",20000);
        set("sen",20000);
        set("max_gin",20000);
        set("gin",20000);
        set_skill("unarmed", 200);
        set_skill("parry", 200 );
        set_skill("dodge", 200);
        set_skill("move",200 ); 
        set_skill("blade",200);
        set_skill("demon-steps",200);
        set_skill("moon-blade",100);
        map_skill("blade","moon-blade");
        map_skill("parry","moon-blade");
        map_skill("move","demon-steps");
        map_skill("dodge","demon-steps");
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/damage", 30+random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
        }) ); 
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();
}      
