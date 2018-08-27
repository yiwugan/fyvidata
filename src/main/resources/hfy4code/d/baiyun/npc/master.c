 // master.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("Ҷ�³�", ({ "master ye", "master" }) );
        set("nickname", HIC"һ������"NOR+HIR" �������"NOR);
        set("gender", "����" );
        set("age", 44);
        set("str", 100);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
       set("per", 20);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );
        set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 100);
        set("max_kee",99999);
        set("max_gin",99999);
        set("max_sen",99999);
        set("eff_kee",9999);
        set("kee",99999);
        set("chat_chance", 1);
        set("chat_msg", ({
                "Ҷ�³Ǵӵ��Ѫ�ߵİ���˺��һ��������\nҶ�³��ôӵ��Ѫ�ߵİ���˺�µĲ������Լ����ˡ�\n",
        }) ); 
        set("long",
"
һ������΢�룬������ѩ�׳��۵��ˡ��������ܰף��Ȳ��ǲ԰ף�Ҳ���ǲҰף�
����һ�ְ���㾧Ө�������ɫ�������۾���������ڵģ���ȴ���ÿ��£���
�������ź��ǡ�����ڵ�ͷ���ϣ�������̴��ľ������ڣ����ϵ��·�Ҳ���
��ѩ���·������ϵ�����һ�㡣
\n"
        );
        create_family("���Ƴ�",1, "����");
        set("rank_nogen",1);
        set("ranks",({"��ͯ","С��ʿ","��ʿ","С����","����",
                      "С����","����","��ʦ",CYN"��ʦ"NOR,
                      CYN"����"NOR,CYN"����"NOR,HIC"��ʥ"NOR}));
        set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));
        set("combat_exp", 8000000);
        set("score", 200000);
        set("reward_npc", 1);
        set("difficulty", 10);
        
        set_skill("move", 150);
        set_skill("daode",160);
        set_skill("parry", 180);
        set_skill("dodge", 150);
        set_skill("force", 160);
        set_skill("literate", 180);
        set_skill("sword", 240);
        set_skill("unarmed",100);
        set_skill("music",220);
        set_skill("feixian-steps",220);
        set_skill("feixian-sword",200);
        set_skill("calligraphy",160);
        set_skill("chess",200);
        set_skill("magic",150);
        set_skill("painting",160);
        map_skill("magic","music");
        map_skill("literate","chess");
        map_skill("dodge", "feixian-steps");
        map_skill("sword", "feixian-sword");
        map_skill("force", "painting");
        map_skill("parry", "feixian-sword");
        map_skill("unarmed", "calligraphy");
        map_skill("move","feixian-steps"); 
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/bsword")->wield();
   carry_object(__DIR__"obj/bcloth")->wear(); 
} 
void attempt_apprentice(object me)
{
      command("say �ţ����Ƴ���������֮ʱ�����ҪŬ������");
      command("recruit " + me->query("id") ); 
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "baiyun");
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
        if(id_class == "baiyun"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N�����������¥�������������\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="assassin") return 0;
        message_vision(WHT"$N����һ������������Ƶ����������Ĳ����������������ģ����ǳ����߰ɣ�\n"NOR, this_object());
        message_vision(CYN"$N��Ȼ�������Ƶ��������黭������ͽ֮����������\n"NOR,this_object());
        return 1;
}        
