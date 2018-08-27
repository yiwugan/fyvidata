 inherit NPC;
void create()
{
        set_name("���ϴ�", ({ "boss chang","boss tsang", "boss", "tsang","chang"}) );
        set("title", "����կկ��");
        set("nickname", "�÷絶��");
        set("gender", "����");
        set("age", 53);
        set("combat_exp", 260000);
        set("score", 17000);
        set("bellicosity", 6000);
        set("attitude", "friendly"); 
        set("max_force", 1000);
        set("force", 1500);
        set("force_factor", 3); 
        set_skill("force", 60);
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("dodge", 70); 
        set_temp("apply/attack", 100);
        set_temp("apply/dodge", 100);
        set_temp("apply/parry", 100); 
        setup(); 
        carry_object(__DIR__"obj/glaive")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        carry_object(__DIR__"obj/fur_coat")->wear();
        carry_object(__DIR__"obj/bamboo_pipe");
        add_money("gold", 2);
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