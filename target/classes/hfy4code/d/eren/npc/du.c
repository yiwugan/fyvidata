 inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("���ϵ�", ({ "du laodie" }) );
        set("gender", "����" );
        set("age", 60);
        set("long",
                "���ϵ���˵��Ѫ�ֶ�ɱ�����壬������������Ȥ�Ļ����������İ�
�����ഫ�ϵ�����ʱ�����ź�������������๤�����˵��Ǻպ�������\n");
        set("combat_exp", 800000);
        
        set("force",800);
        set("max_force",800);
        set("force_factor",40);
        set("mana",500);
        set("max_mana",500);
        
        set_skill("unarmed",100);
        set_skill("changquan",200);
        set_skill("puti-steps",150);
        set_skill("dodge",100);
        set_skill("move",100);
        map_skill("unarmed","changquan");
        map_skill("dodge","puti-steps");
        map_skill("move","puti-steps");
        
        
        set("attitude", "friendly");
        set("vendor_goods", ([
               __DIR__"obj/zhen": 10,
               __DIR__"obj/lei": 10,
               __DIR__"obj/jili": 10,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        message_vision("$N������һ�ۣ���ת�����ȥ�ˡ�\n",this_object());
}      
