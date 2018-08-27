 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���������", ({ "figure leader"}) );
        set("nickname", HIG "ȭ������"NOR);
        set("gender", "����" );
        set("age", 41);
        set("per", 30);
        set("agi",25);
        set("int",30);
        set("cor",40);
        set("cps",200);
        set("class","beggar");
        set("attitude","friendly");
        set("bellicosity",30000);
        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 100);
        set("mana",2000);
        set("max_mana",2000);
        set("atman",500);
        set("max_atman",500);
        set("str",40);
        set("figure_friend",1);
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set("long",
"���˵����ϴ��źڲ���ߣ���������Ŀ���������ݣ���ֻ���ƴ�ľ��ˡ���
�����˶����Ĺ�����������Ȼ����һ���˵����졣\n"
        );
        set("combat_exp", 5000000);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.xianglongwuhui" :),
        }) ); 
        set_skill("move", 200);
        set_skill("parry",200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("unarmed",150);
        set_skill("dragonstrike",200);
        set_skill("demon-steps",160);
        set_skill("blade",300);
        set_skill("parry",200);
        
        
        map_skill("unarmed","dragonstrike");
        map_skill("dodge", "demon-steps");
        map_skill("move","demon-steps");
        map_skill("force", "demon-force");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
                
} 
void init()
{
        object ob; 
        ::init();
        add_action("do_get","get");
        if( interactive(ob = this_player())) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        object friend;
        if( !interactive(ob) || environment(ob) != environment() ){
                return;
        }
        if (!ob->query("figure_friend")){
            message_vision("$N�ٺٵ����ã����Ǻ���һ��ģ����������������,�����Ǹ���ɱ��\n", this_object() );
                   this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
}  
int do_get(string arg)
{
if(!arg) return 0;
message_vision("$NЦ����û����ô���˵��°ɣ�\n",this_object(),this_player());
if (!this_player()->is_busy()) this_player()->start_busy(1);
return 1;
}      
