 // taolord.c
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave(); 
void create()
{
    set_name("��һ��", ({ "master tang", "master", "tang" }) );
    set("nickname", HIG"�º�"NOR);
    set("gender", "����");
    set("age", 38);
    set("long",
        "���꿪ɽ�������϶���������ס������󵱼ң�֮����϶���һ�������š�\n"
        "���ն��Ҿ�Ӣ����Ϊ���ű������������������������������ƽ��ɽ��\n");
    set("combat_exp", 1000000);
    set("score", random (20000)); 
    set("class", "emei");
    set("reward_npc", 1);
    set("difficulty", 30); 
    set("int", 30);
    set("cor", 20);
    set("no_busy", 5);
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
        
    set("inquiry",  ([
                "leave": (: leave :),
                ]) );
    set("apprentice_available", 10);

    create_family("������", 5, "���ڳ���");
    set("rank_nogen",1);
    set("ranks",({"����","����","��ʿ","����",RED"����"NOR,YEL"����"NOR,YEL"������"NOR,
                      HIR"����"NOR})); 
    set_skill("literate", 180);
    set_skill("force", 120);
    set_skill("move", 180);
    set_skill("unarmed", 120);
    set_skill("sword", 180);
    set_skill("parry", 120);
    set_skill("dodge", 180);
    set_skill("changelaw", 120);
    set_skill("sky-sword", 180);
    set_skill("skyforce", 150);
    set_skill("yue-strike", 150);
    set_skill("sky-steps", 150);
    set_skill("perception", 180);
    set_skill("throwing", 220);
    set_skill("tanzhi-shentong", 180);
    map_skill("parry", "sky-sword");
    map_skill("sword", "sky-sword");
    map_skill("move", "sky-steps");
    map_skill("dodge", "liuquan-steps");
    map_skill("literate", "changelaw");
    map_skill("force", "skyforce");
    map_skill("unarmed", "yue-strike"); 
    map_skill("throwing", "tanzhi-shentong"); 
    setup(); 
    carry_object("/obj/weapon/sword")->wield();
    carry_object("/obj/armor/cloth")->wear();
} 
void attempt_apprentice(object ob)
{
    if(ob->query("marry")){
                message_vision("$N����һ����������Ȼ�����������ǳ��ң���Ҳû���϶���Ů�ġ���\n", 
                                this_object(), ob);
                return;
    }
    if (ob->query("once_menpai/emei")&& ob->query("class")!="emei") {
                command("say �㲻���ѳ�ȥ��ô,���������������ǣ�");
                return;
                } 
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say ������һ��һ������");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say �Ϸ�����Ѿ������������ӣ���������ͽ�ˡ�");
    }
} 
void do_recruit(object ob)
{
//    if( (string)ob->query("marks/������ͽ") )
    if( ob->query("once_menpai/emei") )
        command("say " + ob->query("name") + "���㻹�������������ǣ�");
    else {
        command("recruit " + ob->query("id") );
        ob->set("once_menpai/emei",1);
    }
} 
int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "emei");
    add("apprentice_availavble", -1);
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
        if(id_class == "emei"&& userp(victim)&&player!=victim)
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
        if (this_player()->query("class")!="emei") return 0;
        message_vision(CYN"$N���γ�̾������һ��һ�����������ɸ���������\n"NOR, this_object(),this_player());
        message_vision(CYN"$N��Ц˵���߰ɣ����Ұ�����Ϊ�������Լ��ú���ĥ�ˡ�\n"NOR,this_object(),this_player());
        message_vision(CYN"$N˵��һ��Ե�֣����������ɵ��Ӿʹ������Űɣ�\n"NOR,this_object(),this_player());
        return 1;
}
