 // tall_bandit.c
inherit NPC; 
void create()
{
        set_name("����", ({ "bandit" }) );
        set("gender", "����");
        set("age", 27);
        set("long",     "��һﳤ�ø߸����ݣ���ɫ�԰ף�һ���޾���ɵ����ӡ�\n");
        set("combat_exp", 900);
        set("score", 100);
        set("attitude", "friendly");
        set_skill("sword", 15);
        set_skill("parry", 15);
        set_skill("dodge", 10);
        setup();
        carry_object(__DIR__"obj/long_sword")->wield();
        carry_object("/obj/armor/cloth")->wear(); 
        add_money("coin", 6);
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