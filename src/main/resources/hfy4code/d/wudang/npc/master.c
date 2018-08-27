 // taolord.c
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave(); 
void create()
{
    set_name("ʯ��", ({ "master shi", "master", "shi" }) );
    set("nickname", "��������");
    set("gender", "����");
    set("age", 62);
    set("long",
        "ʯ���˵����䵱���ţ�����̫���ķ������Ž����������˼��ߵľ��硣\n"
        "�����侫̫ͨ�����У����������ǵ�����˫�������˳ƣ��������ˣݡ�\n");
    set("combat_exp", 90000000);
    set("score", random (20000)); 
    set("class", "wudang");
    set("reward_npc", 1);
    set("difficulty", 40); 
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30);
    set("fly_target",1);        
    set("force", 3000);
    set("max_force", 3000);
    set("force_factor", 100);
    set("atman", 1400);
    set("max_atman", 1400);
    set("mana", 2000);
    set("max_mana", 2000); 
    set("resistance/gin",70);
    set("resistance/kee",70);
    set("resistance/sen",99);
        
    set("inquiry", ([
        "̫���ķ�": "̫���ķ��˵������ŵĻ����ķ����ܹ��������ڵ�����������\n",
        "�䵱��":   "���䵱���������˿�ɽ����������������������������Ϊ���Ρ�\n",
        "���Ƿ�" :  "���Ƿ���Ϊ����ȴֻ�����������Ǿ���hanxing���ͻ��Ǿ���jixing����\n",
        "qixing" :  "���Ƿ���Ϊ����ȴֻ�����������Ǿ���hanxing���ͻ��Ǿ���jixing����\n",
    "leave" : (: leave :),
         ]) ); 
    set("apprentice_available", 10);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
            (: cast_spell, "jixing" :),
            (: perform_action, "sword.nianzijue" :),
             }) ); 
    create_family("�䵱��", 57, "������");
    set("rank_nogen",1);
    set("ranks",({"��ʿ","С����","����","С��ʦ","��ʦ",YEL"����ʦ"NOR,YEL"������"NOR,
                      HIY"����"NOR})); 
    set_skill("literate", 140);
    set_skill("force", 150);
    set_skill("move", 150);
    set_skill("unarmed", 130);
    set_skill("sword", 200);
    set_skill("parry", 220);
    set_skill("dodge", 160);
    set_skill("changelaw", 180);
    set_skill("three-sword", 160);
    set_skill("taijiforce", 200);
    set_skill("taiji", 150);
    set_skill("foreknowledge",120);
    set_skill("five-steps", 180);
    set_skill("spells",100);
    set_skill("qixing",180);
    set_skill("incarnation",180);
    set_skill("perception", 200);
    map_skill("spells","qixing");
    map_skill("parry", "three-sword");
    map_skill("sword", "three-sword");
    map_skill("move", "five-steps");
    map_skill("dodge", "five-steps");
    map_skill("literate", "changelaw");
    map_skill("force", "taijiforce");
    map_skill("unarmed", "taiji"); 
    setup(); 
    carry_object(__DIR__"obj/msword")->wield();
    carry_object(__DIR__"obj/mcloth")->wear();
    carry_object(__DIR__"obj/mhat")->wear();
} 
void attempt_apprentice(object ob)
{
    if(ob->query("marry")){
                message_vision("$N����һ�����䵱���£�û���϶���Ů�ġ���\n", 
                                this_object(), ob);
                return;
    }
    if (ob->query("once_menpai/wudang")&& ob->query("class")!="wudang") {
                command("say �㲻���ѳ�ȥ��ô,�������������ң�");
                return;
                } 
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
    if( (string)ob->query("marks/�䵱��ͽ") )
        command("say " + ob->query("name") + "���㻹�����������ң�");
    else {
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/wudang",1);
    }
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        (ob->set("class", "wudang")&& ob->set("wudang/zhen", 1));

    add("apprentice_availavble", -1);
} 
int accept_object(object who, object ob)
{
    object              book; 
    if((string)ob->name() != "���Ʒɵ��غ�") return 0;
    command("say ��л��λ" + RANK_D->query_respect(who));
    command("say �Ȿ������������ɡ�");
    book = new(__DIR__"obj/wubook");
    book->move(this_object());
    command("give book to " + who->get_id());
    return 1;
}  
void die()
{
    object ob;
    if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
    if(ob) 
        ob->set_temp("killed_master_shi",1);
    ::die();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_killing", "kill");
} 
void greeting(object ob)
{
        object *inv,letter, *sy_inv, things;
        int i,j;
        int got_sword = 0;
        if( !ob || environment(ob) != environment() ) return;
        
/*        if (ob->query("once_menpai/shaolin") && !ob->query("marks/muren_time")
                && !ob->query("marks/bugout") && ob->query("class")=="wudang"
                && ob->query("betrayer")==0)
        {
                ob->set("marks/bugout",1);
                letter = new(__DIR__"obj/letter1");
           if(letter) letter->move(ob);
                message_vision(HIW"ž��һ����$N�ӻ����ͳ�һ��������$n���\n"NOR,this_object(),ob);
                message_vision(HIW"$N˵���Լ�ȥ���ɡ�\n"NOR,this_object());
                ob->add("betrayer",1);
        } */
        if(ob->short() == "�䵱������(wudang master)") {
//Okey, we got a old wudang master here, fake or real?
        inv =all_inventory(ob);
        for(i=0; i<sizeof(inv); i++) 
         if(inv[i]->query("fake_7sword") && inv[i]->query("equipped")=="wielded"
                && inv[i]->query_temp("marks/owner_name") == ob->query("id")) 
                got_sword = 1;
        if(got_sword) {
        for(i=0; i<sizeof(inv); i++)
        if(inv[i]->query("name")=="���") destruct(inv[i]);
        command("say ���ģ��⣬�⣬���ǣ��ǣ��ϣ��ϰ���ô��\n");
        message_vision("$NͻȻһ����Ѫ���˳��������ŵ�������ϣ���ɫ���ڡ�����һͷ�Ե��ڵ��¡�\n",
        this_object());
        ob->set_temp("killed_master_shi",1);
        
        sy_inv = all_inventory(this_object());
        for(j=0;j<sizeof(sy_inv);j++){
                things = sy_inv[j];
                destruct(things);
        }
        this_object()->die();
        tell_object(ob,"���ڿ���ȥ֪ͨ�ϵ������ˣ������˴��Ͼ�����ǰ��潣��\n");
        
        } else {
        command("say �󵨣����һ�ױ���ϰ������Ż��Ϸ�\n");
        kill_ob(ob);
        } 
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
        if(id_class == "wudang"&& userp(victim)&&player!=victim)
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
        if (this_player()->query("class")!="wudang") return 0;
        message_vision(CYN"$Nŭ�����������ļһ���ҹ�����\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵�����߿��ԣ���̫�����е��䵱�ؼ���ͱ��������ˡ�\n"NOR,this_object(),this_player());
        message_vision(CYN"$N˵���Ժ�Ҳ���������ң�\n"NOR,this_object(),this_player());
        return 1;
}
