 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        string *name = ({"��","��","ʱ","��","��","��","��","��","��","��","��","ʷ"});
        set_name("һ"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(20)+ 32);
        create_family("������", 18, "����");
        set("long", "���������µĺ���\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", random(500000)+3000000);
        set("attitude", "friendly");
        set("chat_chance", 2);
        set("cps",80);
        set("chat_msg", ({
                name()+"����������ܿ��˼��ۡ�\n",
        }) ); 
        set_skill("hammer", 200);
        set_skill("liuxing-hammer",random(100)+150);
        set_skill("parry",400);
        set_skill("move",200);
        set_skill("force",200);
        set_skill("dodge",150);
        set_skill("unarmed",150);
        set_skill("puti-steps",150);
        set_skill("dabei-strike",150);
        
        map_skill("unarmed","dabei-strike");
        map_skill("dodge","puti-steps");
        map_skill("hammer", "liuxing-hammer");
        map_skill("parry","liuxing-hammer");
        set("chat_chance_combat", 70);
        
        set("chat_msg_combat", ({
                name()+"Ц��������������Ұ��\n",
                (: perform_action, "hammer.fanbei" :),
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        set("force",500);
        set("max_force",500);
        set("force_factor",50);
        setup();
        carry_object(__DIR__"obj/monk18_cloth")->wear();
        carry_object(__DIR__"obj/hammer")->wield();
}
void init()
{
        add_action("do_get","get");
        ::init();
} 
/*
int do_get(string arg)
{
string what;
if(!arg) return 0;
if(sscanf(arg,"%s",what) !=1) return 0;
if(what== "all" || what== "niepan" )
{
message_vision("$N��$n���һ�����󵨣����Ҵ������¶��������⣡\n",this_object(),this_player());
this_object()->kill_ob(this_player());
this_player()->start_busy(2);
return 1;
}
}
*/ 
int do_get(string arg)
{
if(!arg) return 0;
message_vision("$N��$n˵�������ﲻҪ�����Ҷ���\n",this_object(),this_player());
if (!this_player()->is_busy()) this_player()->start_busy(1);
return 1;
}       
