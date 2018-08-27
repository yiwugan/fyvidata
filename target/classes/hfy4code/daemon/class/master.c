 // master.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("��һ��", ({ "master yichen", "master", "master lan" }) );
        set("nickname", HIC "������"NOR);
        set("gender", "����" );
        set("reward_npc", 1);
        set("difficulty", 40);
        set("no_heal",1);
        set("age", 54);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("per", 30);
        set("agi",25);
        set("skill_public",1);
        
        set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 50);
        
        set("max_kee",99999999);
        set("max_gin",999999);
        set("max_sen",999999);
        set("eff_kee",999999);
        set("kee",999999);
        set("combat_exp", 10000000);
        set("score", 200000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��һ����ɫ���������������һ���ֵ�������ж�����ԡѪ���飬\n��Ȼ̤���������������ȥ�ɡ���ĳ��������̤�����ְ벽��\n",
        }) ); 
        set("long",
"
�����ͷ���Ŷ�������ң����ĺܵ͡�������ס��üë��ס���۾���
��һ���������������ҵ���Ӱ�һ�������Ѿ���ϥ���ϡ�
\n"
        ); 
        create_family("��ɽ����", 3, "����");
        
        set("����",0);
        
        set_skill("move", 120);
        set_skill("parry", 180);
        set_skill("dodge", 160);
        set_skill("force", 100);
        set_skill("literate", 120);
        set_skill("sword", 180);
        set_skill("unarmed",120);
        set_skill("sky-steps",120);
        set_skill("xiaohun-sword",160);
        set_skill("libie-sword",120);
        set_skill("xiaohun-whip",160);
        set_skill("whip",150);
        
        map_skill("dodge", "sky-steps");
        map_skill("sword", "xiaohun-sword");
        map_skill("force", "jingyiforce");
        map_skill("parry", "libie-sword");
        map_skill("whip","xiaohun-whip");  
        setup();
        carry_object(__DIR__"obj/bluesword")->wield();
        carry_object(__DIR__"obj/shirt")->wear(); 
} 
void attempt_apprentice(object me)
{
        command("shake "+me->query("id"));
        command("say ��ĳ�ѳɷ��ˣ��㻹����������ɡ�����"); 
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
 
 
 
int accept_object(object who, object ob)
{
if(ob->query("name") == "����һ������" ) {
if(query("����")) {
        message_vision(HIY"��һ����Ŷ����һ��������ô����һ�����ŵģ��ѵ��Ǽ�ð�Ĳ��ɣ���\n",this_object());
        return 1;
}       
if(ob->query("������")==who)
{
    message_vision(HIY "��һ����Ŷ����һ�������������İ��Ȼ��̾������㣬��$N���˵�ͷ������
����ʵΪ���ˣ��粻����������ĳ��ɴ�������ѧ���������»��м������������
���͡�����ľ������������ʾӡ�������Ѷ�������δ������ɹ�Щ������ȥ��\n"NOR,this_player()); 
        who->set_temp("libie/���_���ųɹ�",1);
        set("����",1);
        return 1;
}
else
{
    say(HIR"��һ�������˵���������������߹������Լ���ƭ�ң�ȴҲû��ô���ס�\n"NOR);
        kill_ob(who);
        return 1;
}
}
return 0;
} 
int recognize_apprentice(object ob)
{
        if(ob->query("libie/���_ɱ��������"))
                return 1;
}  
void reset()
{
        if(query("����")) {
                add("����",1);
                if (query("����")>8) set("����",0);
        }
}      
