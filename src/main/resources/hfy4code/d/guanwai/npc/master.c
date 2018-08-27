 inherit NPC;
inherit F_MASTER;
#include <ansi.h> 
void smart_fight();
void smart_busy();
void smart_attack();
int leave(); 
void create()
{
        set_name("����", ({ "master gelun", "master","gelun" }) );
        set("gender", "����" );
        set("class","lama");
        set("age", 99);
        set("int", 30);
        set("agi",25);
        set("int",30);
        set("fle",50);
        set("apprentice_available", 20);
        create_family("������", 20, "����");
    set("rank_nogen",1);
    set("ranks",({"����","�޺�","��ɮ","��ʦ","ʥɮ",YEL"����"NOR,YEL"���"NOR,HIY"����"NOR}));
        set("long",
                "���׸�ɮ���ڴ��������ֶ��ꡣ��Ů���ӱ鲼���⡣\n"
                );
        set("inquiry", ([
                "������": "��....������.....���������\n",
                "����": "�����ڴ����µ�ľ���",
                "leave": (: leave:),
        ]) );
        set("combat_exp", 3000000+random(1500000));
        set("score", random(90000));
        set("reward_npc", 1);
        set("difficulty", 30);
        set("mana",4000);
        set("max_mana",4000); 
        set("max_force",1500);
        set("force",1500);
        set("force_factor",30); 
        set_skill("unarmed", 200);
        set_skill("dodge", 100);
		set_skill("move", 100);
        set_skill("staff", 200);
        set_skill("force", 180);
        set_skill("parry", 150);
        set_skill("literate", 140);
        set_skill("fanwen",100);
        set_skill("iron-cloth", 230);
        set_skill("bloodystrike", 150);
        set_skill("lamastaff", 200);
        set_skill("bolomiduo", 160);
        set_skill("lamaism", 200);
        set_skill("jin-gang", 200);
        set_skill("spells",200);
        set_skill("kwan-yin-spells",200);
        set_skill("perception", 100);
        
        map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "fanwen");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "lamastaff");
        map_skill("parry", "lamastaff");
        map_skill("spells","kwan-yin-spells");
        
        set_temp("apply/iron-cloth",200); 
/*      set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "unarmed.fefawubian" :),
                (: cast_spell, "an" :),
        }) ); */
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: smart_fight() :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
}  
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
} 
void attempt_apprentice(object ob)
{
      if(ob->query("marry")){
                message_vision("$N̾�˿���������ʩ���츳������ֻ��ϧ���쳾���ˡ���\n", 
                                this_object(), ob);
                return;
        }
        
        
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �����ֽ����Ѿ����˶�ʮ�����ӣ���������ͽ�ˡ�");
        }
}
void do_recruit(object ob)
{
                if (ob->query("once_gelun")>0 && ob->query("class")!="lama") {
                        command("say �㻹�����������ң�");
                        return;
                } 
                command("smile");
                command("say �ܺã��ܺã��ܺá�");
                command("say ϣ���㲻Ҫ�������������ʧ����");
                command("recruit " + ob->query("id") );
                ob->set("once_gelun",1);
                ob->set("once_menpai/lama",1);
} 
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
        add("apprentice_availavble", -1);
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
        if(id_class == "lama"&& userp(victim)&& player!= victim)
        {
            message_vision("$N����$n�ȵ���" + RANK_D->query_rude(player) 
                                                + "����ɱ" + RANK_D->query_self_rude(this_object()) 
                                                + "��ͽ�ܣ�ȥ���ɡ�\n", this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}   
void die()
{
    object killer;
    if(objectp(killer = query_temp("last_damage_from")))
        killer->set("marks/ɱ�˸���", 1);
    ::die();
}  
void init()
{
        object ob;
        ::init();
        add_action("do_killing", "kill");
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
}  
void punish_betray(object ob)
{
        if( ( ob->query("once_gelun")==1) && ( (ob->query("class"))!= "lama"))
          {      
                tell_object(ob, YEL"\n���״�ŭ:ԭ���������һ��,�Ǹ�����ʦ�ŵ�С�ˣ���\n"NOR);                  
                message("vision", YEL"���׶�"+ ob->name() +"ŭ������"+ ob->name() + "�� ��������ļһ�,����һ�ȣ�\n"NOR, environment(ob), ob);
                tell_object(ob, HIW"����һ�Ȼ�����ı��ϣ�\n"NOR);              
                message("vision", HIW"����һ�Ȼ���"+ ob->name() +"�ı��ϣ�\n"NOR, environment(ob), ob);
                if (ob->query_skill("jin-gang",1)>150)  ob->set_skill("lamaism",150);
                if (ob->query_skill("spells",1)>100)  ob->set_skill("lamaism",100);
                if ( ob->query("max_mana")<300 )
                   ob->set("max_mana",0);
                else
                   ob->set("max_mana",-300);
                tell_object(ob, HIR"��ֻ�����ε�ת,ҡҡ�λεص�����ȥ----�ڲ�����ѽ!\n"NOR);
                ob->set("once_gelun",2);
                ob->unconcious();
          }
}  
int leave() {
        if (this_player()->query("class")!="lama") return 0;
        message_vision(CYN"$N����һ����������һ������������,�Ϸ���޵ľ����������ˡ���\n"NOR, this_object());
        message_vision(CYN"$N˵�����Ǳ����˷��棬��Ҳ�̲��ù������䡣\n"NOR,this_object());
        message_vision(CYN"$N˵���Ĵ�������⵶ǹ����Ľ�ղ���Ҳ��ֻ�и��������Ϸ�������ȷ���Ҳ�޷������ˡ�\n"NOR,this_object());
        
        return 1;
}  
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        if (who->is_busy()) return;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2) {
                who->cast_spell("ni");
                return;
   }
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_skill("iron-cloth")>300 
                                || enemy[i]->query("combat_exp")>who->query("combat_exp")) {
                                who->cast_spell("an");
                                switch( random(3) ) {
                                        case 0: command("grin");
                                                break;
                                        case 1: command("smile");
                                                break;
                                        case 2: command("smug");
                                                break;
                                        }
                                return;
                        }               
                        this_object()->smart_attack();
                        }
        }
return;
} 
smart_busy() {
        this_object()->perform_action("unarmed.fefawubian");
        return;
} 
smart_attack() {
        this_object()->perform_action("staff.fofazhizun");    
        return;
        }       
