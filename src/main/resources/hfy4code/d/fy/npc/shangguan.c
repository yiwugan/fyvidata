 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("�Ϲٽ��", ({ "master shangguan", "master", "master shang" }) );
    set("nickname", RED"����˫��"NOR);
    set("gender", "����" );
    set("class", "assassin");
    set("age", 44);
    set("cor", 40);
    set("cps", 30);
    set("int", 30);
    set("per", 30);
    set("ill_boss",5);
        set("reward_npc", 1);
        set("difficulty", 30);
    set("attitude","friendly");
    set("max_force", 5000);
    set("force", 5000);
    set("force_factor",80+random(50));
    set("max_mana",2000);
    set("mana",2000); 
    set("long",
        "
һ������վ������ǰ�����ţ���ʱ������ھ����Ϲ��������ģ�����ż����¶��һ˿
�����Ц�ݡ�����վ�ŵġ�����Ϊһ����ֻҪ���������ͻ����Լ��ľ����ɳڣ�һ��
�˵ľ������ɳڣ���������ɴ���
\n"
        );
    create_family("��Ǯ��  ", 1, "����");
       set("rank_nogen",0);  
    set("combat_exp", 8000000);
    set("score", 200+random(200000));
    set("agi",25);
    set("int",30);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "hammer.longfengshuangfei" :),
            }) );
    set("skill_public",1);
    set_skill("move", 120);
    set_skill("parry", 160);
    set_skill("dodge", 150);
    set_skill("force", 200);
    set_skill("literate", 140);
    set_skill("jingxing",200);
    set_skill("hammer", 220);
    set_skill("flame-strike",200);
    set_skill("unarmed",200);
    set_skill("jinhong-steps",100);
    set_skill("longfenghuan",200);
    map_skill("dodge", "jinhong-steps");
    map_skill("hammer", "longfenghuan");
    map_skill("parry", "longfenghuan");
    map_skill("force", "jingxing");
    map_skill("unarmed", "flame-strike");
     
    set("ranks",({"����","������","����","������","����",
                   "��̳��","̳��","������","����",
                      "����","�󻤷�","������"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));  
    setup();
    carry_object(__DIR__"obj/whitecloth")->wear();
    carry_object(__DIR__"obj/longfenghuan")->wield();
} 
void attempt_apprentice(object me)
{
         if ( me->query("class")!="assassin") {
                message_vision("$Nҡ��ҡͷ��������Ҫ���ǵ��ºܶ࣬Ҫ��ʦ�㻹��ȥ�Ҿ������ɡ�\n",this_object(),me);
                message_vision("$N������˵������Ա������Ĺ��������Ժ���Ȼ��ָ����һ����\n",this_object()); 
                return 0;
                }
         if ((int)me->query("combat_exp") < 3456000 ) {
                message_vision("$N��$n˵�������㵱�˱���ĳ�����˵�ɣ�\n",
                           this_object(),me);
                return 0;
                }
         command ("say ��ʦȴҲ���ˣ���ѧʲô��˵�ɣ��һ��մ��㼸�еģ�");
} 
/*void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "assassin");
}*/  
int recognize_apprentice(object ob){
        if(ob->query("class")=="assassin") {
           if( (int)ob->query("combat_exp") > 1024000 ) return 1;
           else message_vision("$N��$n˵�������㵱�˱���Ķ�����˵�ɣ�\n",
                        this_object(),ob);
        }
        return 0; 
}  
void init()
{       
        ::init();
        add_action("do_killing", "kill");
    
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "assassin"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N�ȵ���������ǰɱ�Ұ�ĵ��ӣ�������ˣ�\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}
