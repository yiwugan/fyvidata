 // bandit_leader.c
inherit NPC; 
void create()
{
        set_name("��������", ({ "bandit leader", "chief", "leader" }) );
        set("gender", "����");
        set("age", 47);
        set("long",     "��һ������׶�һ˫���������������������Ĳ��ӡ�\n");
        set("combat_exp", 50000);
        set("score", 7700);
        set("bellicosity", 3000);
        set("attitude", "friendly"); 
        set("max_force", 700);
        set("force", 1300);
        set("force_factor", 4); 
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                "\n����������������˵������������è�Ĺ���Ҳ��������կ����Ұ����\n",
                "\n��������˵����ȥ��ģ����ӽ���Ҫ�������ͷ��������צ��\n",
                "\n�������컢��һ����������ǰ��\n"
        }) );
        set_skill("blade", 60);
        set_skill("parry", 70);
        set_skill("dodge", 70); 
        // Because the chief's �书 is not done yet, set apply to replace it.
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 50); 
        setup();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        add_money("coin", 300);
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