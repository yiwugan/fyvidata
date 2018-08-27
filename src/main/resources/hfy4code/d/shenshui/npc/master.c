 //XXDER
inherit NPC;
inherit F_MASTER;
int leave(); 
#include <ansi.h>
void create()
{
    set_name("��ˮ����", ({ "master shenshui", "master", "shenshui" }) );
    set("nickname", HIB"ˮĸ����"NOR);
    set("gender", "Ů��");
    set("class", "shenshui");
    set("age", 33);
    set("long",
        "һλ���ϴ�����ɳ����Ů�����ڵ����ϣ�����Ȼ�������������ݣ�ȴ���Ըо�����"
        "�Ǿ��ѵ����ʺ;���Ͷ���ĳ�����ϡ�\n");
    set("attitude", "peaceful");
    set("class", "shenshui");
    set("apprentice_available", 2);
    
    create_family("��ˮ��", 11, "����");
    set("rank_nogen",1);
    set("ranks",({"����","С��Ů","��Ů","����Ů","��",MAG"�ɼ�"NOR,HIM"ʥ��"NOR,
                      HIR"������"NOR}));
    set("reward_npc", 1);
        set("difficulty", 30);
    set("inquiry", ([
        "leave" : (: leave :),
                ]));  
        
    set("int", 28);
    set("spi", 26);
    set("per", 30);
    set("cps", 30);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
                (: perform_action, "dodge.lianhuanbu"  :),
  //      (: perform_action, "unarmed.suicidal" :),
            }) );
    set("force", 1200);
    set("max_force", 1200);
    set("force_factor", 60); 
    set("combat_exp", 15000000);
    set("score", random(90000)); 
    set_skill("unarmed", 150);
    set_skill("sword", 150);
    set_skill("force", 180);
    set_skill("parry", 140);
    set_skill("dodge", 140);
    set_skill("literate", 140);
    set_skill("move",200);
    set_skill("charm",280);
    set_skill("nine-moon-spirit", 200); 
    set_skill("nine-moon-steps", 180);
    set_skill("nine-moon-claw", 200);
    set_skill("nine-moon-force", 150);
    set_skill("nine-moon-sword", 200); 
    map_skill("dodge", "nine-moon-steps");
    map_skill("unarmed", "nine-moon-claw");
    map_skill("force", "nine-moon-force");
    map_skill("sword", "nine-moon-sword");  
    set_temp("apply/dodge", 100);
        set_temp("apply/parry", 100); 
    setup();
    carry_object(__DIR__"obj/ghostyboots")->wear();
    carry_object(__DIR__"obj/ghostycloth")->wear();
    carry_object(__DIR__"obj/ghostygirth")->wear();
    carry_object(__DIR__"obj/ghostyribbon")->wear();
} 
void reset()
{
    delete_temp("learned");
    set("apprentice_available", 5);
} 
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say ������һ��һ������");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say �����Ž����Ѿ�����������ӣ���������ͽ�ˡ�");
    }
} 
void do_recruit(object ob)
{
    object girl; 
   if( ((int)ob->query("cor") < 10) || ((int)ob->query("cps") < 10)
        || ((int)ob->query("int") < 10)
        ||      ((int)ob->query("con") < 10)) {
        command("say ����ˮ����Ҫ��Ե�ݣ����ҿ�" +
                RANK_D->query_respect(ob) + "�;���������Ե��");
        return;
    }
    if( (string)ob->query("gender") != "Ů��" )
    {
                command("shake");
                command("say ��ˮ�����书����Ů�Ӳ������������߾��硣"); 
        } else {
        command("smile");
        command("say �ܺã��ܺã��ܺá�");
        command("recruit " + ob->query("id") );
                tell_object(ob, HIY"\n��ֻ��һ��ϸ΢���������˹��������㼴��������ˮ����֪��ˮ�ܾ���\n"NOR);
                tell_object(ob, HIY"������ˮ���ɻ��Ҷ��ڴ��ƿ�ɽʯ����·���ɳ���ƽɽׯ��԰�ţ�\n"NOR);
                tell_object(ob, HIY"�����֣���ɽ�´��ƿ�ɽʯ�����ǡ����ǡ���\n\n"NOR);
                message("vision", ob->name()+ "�ƺ��ڲ������ʲô����ȴʲôҲ��������\n",
                                environment(ob), ob);
        }
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "shenshui");
         ob->set("once_shenshui",1);
    add("apprentice_availavble", -1);
} 
void init()
{
	object ob;
        ::init();
        add_action("do_killing", "kill");
                if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",3 , ob);
        }
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
        if(id_class == "shenshui"&& userp(victim)&&player!=victim)
        {
message_vision(HIW"$N����$n�ȵ���" + RANK_D->query_rude(player) 
                                                + "����ɱ" + RANK_D->query_self_rude(this_object()) 
                                                + "��ͽ�ܣ�ȥ���ɡ�\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="shenshui") return 0;
        message_vision(CYN"$N��Ц��һ����\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵�����߿��ԣ����Ӵ˲����ڽ�����ʹ�þ����񹦡�\n"NOR,this_object(),this_player());
        return 1;
} 
void punish_betray(object ob)
{
        if( ( ob->query("once_shenshui")) && ( (ob->query("class"))!= "shenshui"))
          {      
                tell_object(ob, YEL"\nˮĸ����������Ц���������Ȼ�г����ţ��Ͳ������б��ŵ��书����\n"NOR);              
                message("vision", "ˮĸ������"+ ob->name() +"��Ц������"+ ob->name() + "�� ���Ȼ�г����ţ��Ͳ������б��ŵ��书��\n", environment(ob), ob);
           tell_object(ob, HIW"ˮĸ������һ�һ֧ţë��ϸС�ķ�����������̨��\n"NOR);              
                message("vision", HIW"ˮĸ��������"+ ob->name() +"��һ����һ֧ţë��ϸС�ķ��룡\n"NOR, environment(ob), ob);
                
                if (ob->query_skill("nine-moon-claw",1)) ob->delete_skill("nine-moon-claw");
                if (ob->query_skill("nine-moon-force",1)) ob->delete_skill("nine-moon-force");
                if (ob->query_skill("nine-moon-steps",1)) ob->delete_skill("nine-moon-steps");
                if (ob->query_skill("nine-moon-sword",1)) ob->delete_skill("nine-moon-sword");
                tell_object(ob, HIR"��ֻ��Ѫ��һ���������书ȫʧ����\n"NOR);
                ob->start_busy(10);
                ob->delete("once_shenshui");
  
          }
} 