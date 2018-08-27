 // taolord.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int marriage();
int leave();
void create()
{
    set_name( "������" , ({ "master ding", "master" }) );
    set("nickname",HIB "��հ���" NOR);
    set("gender", "Ů��");
    set("age", 46);
    set("long",
        "�������Ƕ��˷��ʦ�ã�Ҳ�Ƕ��˷�������á�����������ʱ�������������\n"
        "�����������������ɱ�˰�����󵽴˳��ҡ�\n"); 
    set("combat_exp", 10000000);
    set("score", 200000);
    set("reward_npc", 1);
        set("difficulty", 35); 
    set("class", "taoist"); 
    set("str", 20);
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30); 
    set("force", 2000);
    set("max_force", 1000);
    set("force_factor", 30); 
    set("atman", 1400);
    set("max_atman", 1400); 
    set("mana", 4000);
    set("max_mana", 2000);
    set("mana_factor", 5); 
    set("inquiry", ([
        "�����ķ�": 
        "�����ķ��������幬Ϊ�Կ�аħ����������ڹ��ķ���\n",
        "���幬": 
        "�����幬������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n",
         "leave" : (: leave :),
        ]) ); 
    set("apprentice_available", 3);
    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
        (: cast_spell, "drainerbolt" :),
        (: cast_spell, "invocation" :),
            }) ); 
    create_family("���幬", 6, "Ů����");
    set("rank_nogen",1);
    set("ranks",({"����","��ͯ","����","ɢ��","�ɹ�",YEL"��Ů"NOR,YEL"������"NOR,
                      HIY"����"NOR})); 
    set_skill("literate", 140);
    set_skill("force", 180);
    set_skill("spells", 240);
    set_skill("scratching",120);
    set_skill("move", 150);
    set_skill("unarmed", 150);
    set_skill("sword", 150);
    //set_skill("tenderzhi", 100);
    set_skill("parry", 150);
    set_skill("dodge", 120);
    set_skill("gouyee", 200);
    set_skill("notracesnow", 160);
    set_skill("snowshade-sword", 150);
    set_skill("taoism", 240);
    set_skill("necromancy", 200);
    set_skill("scratmancy",220);
    set_skill("perception", 100);
    set_skill("qiankunstrike", 100);
    map_skill("unarmed", "qiankunstrike"); 
    map_skill("spells", "necromancy");
    map_skill("parry", "snowshade-sword");
    map_skill("sword", "snowshade-sword");
    map_skill("move", "notracesnow");
    map_skill("dodge", "notracesnow");
    map_skill("force","gouyee"); 
    set_temp("apply/dodge", 20);
    set_temp("apply/armor", 20); 
    setup(); 
    carry_object(__DIR__"obj/sword2")->wield();
    carry_object(__DIR__"obj/robe2")->wear();
    carry_object(__DIR__"obj/hat2")->wear();
    carry_object(__DIR__"obj/shoe")->wear();
} 
void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say ������һ��һ������");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say ƶ�������Ѿ������������ӣ���������ͽ�ˡ�");
    }
} 
void do_recruit(object ob)
{
    
    if( (string)ob->query("gender") != "Ů��" )
        {
        command("say ƶ���ǳ����ˣ���������ͽ�������ˡ�");
                return;
        }
    else if(ob->query("marry") || ob->query("divorced")) {
                message_vision("$Ņͷ���˿�$n������һЦ������λ���������ϸ������˰ɡ������ɱ�ˣ��������ҡ���\n", 
                                this_object(), ob);
                return;
        }  
    else if (ob->query("once_menpai/sanqing") && ob->query("divorced")) {
                message_vision("$Nҡ��ҡͷ����������ѳ����壬����ʦ�����˳ɻ飬��Ȼ�����ڻ���ת�⡣����\n",this_object());
                message_vision("$N˵��������λ��������㣿��\n",this_object());
                return;
                }
    else if (ob->query_skill("scratmancy",1)>100) {
                message_vision("$N�ɻ�ؿ��˿�$n�����������Ů�ӣ�ȴ��ѧ����ʦ�ֵļ��ա�\n",this_object(),ob);
                message_vision("$N˵������ʦ��һ��ֻ����ͽ����˵��Ե�ɣ��Ҳ���������㡣��\n",this_object());
                return;
                }
             
        command("say ��... ���������幬��Ҳ��....");
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/sanqing",1);
        ob->set("once_sanqing",1);
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "taoist");
    add("apprentice_availavble", -1);
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
        id_class=victim->query("gender");
        id=victim->query("id");
        if(id_class == "Ů��"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N��$n��Цһ����ƶ������õľ�����ѹŮ��֮ͽ��\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy())  player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
   if (this_player()->query("class")!="taoist") return 0;
        message_vision(CYN"$N���������������Ų��⴫���������˿ɲ�Ҫ��ڡ�\n"NOR, this_object(),this_player());
        return 1;
}  
int marriage () {
        if (this_player()->query("once_menpai/sanqing")){
                message_vision(CYN"$N�����������ˣ��������޵���ĪҪ��Ů�鳤��\n"NOR,this_object());
                message_vision(CYN"$N�ֵ�������ִ��Ϊ��Ҫ��ɽ��Ҳ������ǿ��ֻ������һ������ͷ���ѣ��мǣ�\n"NOR, this_object());
                this_player()->delete("once_sanqing");
                return 1;
        }
        return 0;
}  
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/ɱ������", 1);
        }
        
        ::die(); 

}
