 // bandit_guard.c
inherit NPC; 
void create()
{
        set_name("�������", ({ "bandit" }) );
        set("gender", "����");
        set("age", 33);
        set("long","��һ��������⣬һ�������ɷ��ģ��������������η��\n");
        set("combat_exp", 3600);
        set("pursuer", 1);
        set("score", 260);
        set("bellicosity", 600);
        set("attitude", "friendly");
        set_skill("sword", 50);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        setup();
        carry_object(__DIR__"obj/short_sword")->wield();
        carry_object("/obj/armor/cloth")->wear();
        add_money("coin", 5);
}  
int heal_up()
{
        if(environment() && !is_fighting() && !is_busy()
                && query("startroom") 
                && file_name(environment()) != query("startroom")) {
//              command("say ok");
                return_home(query("startroom"));
                return 1;
        }
        return ::heal_up() + 1;
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !ob || environment(ob) != environment() )
                return;
        if (ob->query("class") != "bandit")
        {
                message_vision("$N��������������������ֵ��ǣ�������ڣ���\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        else if(ob->query("class")=="bandit")
        {
                message_vision("$N������Ц�����ֵܽ����ֵ������ҽ��᣿\n", this_object() );
        }
        return;
}     