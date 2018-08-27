 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int got_me();
int leave();
void create()
{
        set_name("��ս", ({ "master tiezhan", "master"}) );
    set("nickname", HIY "ս�ǵ�"NOR);
        set("gender", "����" );
        set("age", 34);
        set("agi",30);
        set("per", 35);
        set("int",30);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long","һ�������½󣬺�����Ĵ󺺣�����һ���;��ô��˹�������\n"); 
        create_family("��ɽ", 4, "��ͷ��");
       set("rank_nogen",1); 
    set("student_title","Ѳɽ��");
  
      set("inquiry", ([
           "leave" : (: leave :),
        ]) );
        
    set("combat_exp", 800000);
        set_skill("move", 150);
        set_skill("dodge", 150);
    set_skill("hammer", 150);
    set_skill("animal-training", 120);
        set_skill("force", 100);
    set_skill("parry", 180);
        set_skill("literate", 100);
        set_skill("unarmed",120);
    set_skill("summonwolf",120);
    set_skill("wolf-strike",120);
    set_skill("wolf-force",100);
    set_skill("xueyeqianzong",100);
    set_skill("assasin-hammer",100);
    set_skill("cursism",100);
    set_skill("perception", 100);
    
    map_skill("dodge", "xueyeqianzong");
    map_skill("unarmed", "wolf-strike");
    map_skill("hammer", "assasin-hammer");
    map_skill("parry", "assasin-hammer");
    map_skill("force", "wolf-force");
    set("class","wolfmount");
    set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.duanhou" :),
        }) );
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/pifeng")->wear();
    carry_object(__DIR__"obj/stonehammer")->wield();  
} 
void attempt_apprentice(object me)
{
      if( (int)me->query_cor() >=15 )
    {
    command("say ����ɽ�ֶ���һ����η�޾����Ѫ���ɣ���ϲ�ɺذ���\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("shake");
        command("say �ҿ��㵨С���£��������������ಫ���㻹���߰ɣ�\n"); 
    }
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wolfmount");
} 
int accept_fight(object me)
{
        if(me->query("class") == "wolfmount")
        {
            command("say �ã�Ӯ���ң���Ϳ���ȥ����ɽ�и������ʦ���ˣ�\n");
                return 1;
        }
        else
        {
                command("say ��ʲô��Ц�����Ӵ�������ܣ�Ҫ���־�����ģ�\n");
                return 0;
        }
} 
void win_enemy(object loser)
{
    command("say ���������Ͱ����������˵������ʦ�������ˣ����ˣ�\n");
} 
void lose_enemy(object winner)
{
    command("say ��ͽ������������ǰ;����ɽ����ʦүʦ��ѧȥ�ɡ�\n");
        winner->set_temp("marks/wolf_win_tiezhan",1);
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
        if(id_class == "wolfmount"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N��$n�ȵ�����ɽ�ӵ�,ͬ����֦,�����������꣡\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="wolfmount") return 0;
        message_vision(CYN"$N��м�ؿ�����һ�ۡ�\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵�����߿��ԣ��Ժ��ָ������ɽ�Ķ����ؼ���\n"NOR,this_object(),this_player());
        return 1;
}        
