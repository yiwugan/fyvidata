 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("��Ӣ", ({ "huo ying", "huo"}) );
        set("gender", "����" );
        set("age",22);
        set("long", "һ����ɽ�ɵ��ӡ�\n");
        create_family("��ɽ��", 6, "����");
        set("combat_exp", random(50000)+30000);
        set("attitude", "friendly");
        set_skill("unarmed", 60+random(10));
        set_skill("yunwu-strike",random(50)+30);
        set_skill("move",40);
        set_skill("force",20);
        map_skill("unarmed", "yunwu-strike");
        set_skill("dodge",100);
        set_skill("liuquan-steps",40);
        map_skill("dodge","liuquan-steps");
        set("chat_chance", 5);
        set("chat_msg", ({
"��Ӣ����΢Ц������֪������ɽ�кι�ɣ�\n",
        }) );
        set("chat_chance_combat", 30);
        set("force",500);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.miwu" :),
        }) );
        set("max_force",500);
        set("force_factor",2);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}  