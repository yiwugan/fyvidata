 // hu.c
inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name(HIW"������"NOR, ({ "whitecloth man", "man" }) );
        set("gender", "����" );
        set("age", 32);
        set("str", 30);
        set("int", 20);
        set("cor", 40); 
    set("long",
"����ˬˬ��һ������ѣ��������ŵ�һ��Ц�����ټ����������°��һ��Ц
�ۣ�Ц���л��·�ʱ�а���Ʈ��������ԶԶ����ô��һ����ơ� 
\n"
    );
    set("max_gin", 6000);
    set("max_kee", 6000);
    set("max_sen", 6000);
        set("max_force", 10000);
        set("force_factor", 100);
        set("combat_exp", 5000000+random(3000000));
        set("attitude", "friendly");
        set("str", 200);
        set_skill("move",200);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("unarmed", 200);
        set_skill("force", 130);
        set_skill("flying-dragon", 100);
        set_skill("zuixian-steps", 100);
        set_skill("cloudforce", 90);
        map_skill("move", "zuixian-steps");
        map_skill("dodge", "zuixian-steps");
        map_skill("force", "cloudforce");
        map_skill("unarmed", "flying-dragon");
        map_skill("parry", "flying-dragon");
    set("chat_chance_combat", 15);
    set("chat_msg_combat", ({
        (: perform_action, "longwujiutian" :),
            }) );
        setup();
        carry_object("/obj/armor/cloth", 
                ([      "name"  :       HIW"����"NOR ,
                        "long" : "��ɫ�������ɾ�ƽ����û��һ˿�ۺۡ�"])
                )->wear();
}     
