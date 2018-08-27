inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight(); 
void create()
{
    set_name("�ϵ�����", ({ "master lao dao", "master"}) );
    set("gender", "����" );
    set("class","wudang");
    set("age", 45);
    set("int", 30);
    set("per", 30);
    set("str",50);
    set("apprentice_available", 50);
    set("reward_npc", 1);
    set("difficulty", 15);
    set("fly_target",1);
    create_family("����ɽׯ", 1, "ׯ��");
    set("rank_nogen",1);
    set("ranks",({ "����","���","С�ܼ�","�ܼ�","��ܼ�",
                        "�ܹ�","���ܹ�","������" }));
    
    set("long", "�������ۣ�ͷ�����ң�������������ʵĹ�ꡣ\n" );
    
    set("inquiry", ([
        "�����ķ�": 
        "�����ķ�������ʮ��չ��������ã���[����Ʊ�]������һ����\n",
        "����Ʊ�": 
        "�˾�������������ǿ��ֻ�ִ�У��������ú����书��������ʹ�á�\n",
        ]) ); 
         
    set("max_atman", 1000);
    set("atman", 1000);
    set("max_force", 1000);
    set("force", 1000);
    set("force_factor", 90);
    set("max_mana", 2000);
    set("mana", 2000);
    
    set("resistance/kee",30);
    set("resistance/sen",50);
    set("resistance/gin",30);
    
    set("combat_exp", 9999999);
    set("score", random(90000));
    
    set("skill_public", 1); 
    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
    
    set_skill("perception", 150);
    set_skill("foreknowledge", 180);
    set_skill("changelaw", 150);
    set_skill("unarmed", 150);
    set_skill("sword", 180);
    set_skill("move", 150);
    set_skill("force", 180);
    set_skill("parry", 150);
    set_skill("literate", 180);
    set_skill("dodge", 150);
    set_skill("three-sword", 180);
    set_skill("taiji", 160);
    set_skill("five-steps",160);
    set_skill("liangyi-force",180); 
    map_skill("force","liangyi-force");
    map_skill("unarmed", "taiji");
    map_skill("sword", "three-sword");
    map_skill("parry", "three-sword");
    map_skill("dodge","five-steps"); 
    setup();
    carry_object(__DIR__"obj/cloth3")->wear();
    carry_object(__DIR__"obj/hat")->wear();
    carry_object(__DIR__"obj/swordd")->wield();
} 
/*void reset()
{
    delete_temp("learned");
    set("apprentice_available", 20);
}
*/ 
void attempt_apprentice(object ob)
{
            call_out("do_recruit", 2, ob);
} 
void do_recruit(object ob)
{
    if((int)ob->query_temp("marks/���Ʒ�")) {
        command("stare " + ob->query("id"));
        command("say �㲻��������ϸ�İɣ�\n");
        return;
    }
    else  if((int)ob->query_temp("marks/����ɽׯ")) {
        say("\n");
        command("say �ã�����䵱����ɽ���Ǳ����������ң��ٽ���ʯ�϶�ɱ�ˣ����ð�ʦ����Ҳ������һ���书��\n");
        ob->set("marks/�����Ǳ���", 1);
        return;
    }
    else {
        command("sigh");
        command("say �����Ѳ���ͽ���ˣ�");
        return;
    }
} 
/*int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "ghost");
    add("apprentice_availavble", -1);
}*/  
int recognize_apprentice(object ob)
{
    return ( ob->query("marks/�ϵ�����") ||
             (string) ob->query("class") == "ghost");
} 
int accept_object(object who, object ob)
{
    if((string)ob->name() != "���ǽ�") return 0;
    if(!who->query("marks/�����Ǳ���")) return 0;
    if(ob->query("real") && (object)ob->query_temp("marks/owner") == who &&
       who->query_temp("killed_master_shi"))
    {
        who->delete("marks/�����Ǳ���");
        command("spank " + who->query("id"));
        command("say ����Ҫ�书�ؼ�����������ѧ�䣿(accept book/teach?)");
        who->set_temp("marks/�õ����Ǳ���", 1);
        add_action("do_accept", "accept");
    }
    else
    {
        say("�ϵ����ӽӹ����ǽ�����ϸ�ؿ��˿���\n");
        command("sigh");
        command("say ��һ�����Ǽٵģ�");
    }
    return 1;
} 
int do_accept(string arg)
{
    object me, book;
    
    if(!arg || (arg != "book" && arg != "teach")) 
        return notify_fail("����Ҫʲô��\n");
    me = this_player();
    if(!me->query_temp("marks/�õ����Ǳ���")) return 0;
    me->set_temp("marks/�õ����Ǳ���", 0);
    if(arg == "book")
    {
        book = new(__DIR__"obj/book");
        book->move(this_object());
        command("give book to " + me->query("id"));
        command("say �㹦�Ͳ�С�������㻹��������ѧ�䡣");
    }
    else 
        command("say �ӽ��쿪ʼ�������ͬ��ѧ���ˡ�");
    me->set("marks/�ϵ�����", 1);
    return 1;
}  
smart_fight()
{
   int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        for(i=0; i<sizeof(enemy); i++) {
        if (!enemy[i]->is_zombie() && enemy[i]->query("id")!="guard") 
                who->perform_action("sword.nianzijue"); 
        }
        return;
}      
