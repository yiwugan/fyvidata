#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "hua shen","hua","shen"}) );
set("long",
            "���Ǹ��������ص�����,\n"+
            "��ʵԭ��ʲô�����Ѿ��޴ӻ������������书�����̶ȣ���\n�������Ҳ�������֣��������ٷ磬�������.\n"+
            "��Ϊ�������ڱ�����ȴû����������.\n");
        set("gender", "����" );
        set("age", 318);
        set("combat_exp", 180000000);
        set("shen_type",1000);
        set("str", 180);
        set("dex", 180);
        set("con", 180);
        set("int", 180);

            set("sen", 1000000);
        set("max_sen", 1000000);
            set("kee", 3000000);
        set("max_kee", 3000000);
        set("gin", 50000);
    set("max_gin", 5000);
    set("force", 1000000);
    set("max_force", 20000);

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("move",200);
        set_skill("unarmed",200);

        set_skill("yihua-jiemu",200);
        set_skill("yifeng-jian",200);

 //       map_skill("unarmed", "jueqing-zhang");
//        map_skill("force", "mingyu-shengong");
 //       map_skill("dodge", "yihua-jiemu");
  //      map_skill("parry", "yihua-jiemu");
   //     map_skill("sword", "yifeng-jian");

        create_family("����",2,"������");
        set("chat_chance_combat", 50);
 //       set("chat_msg_combat", ({
  //              (: perform_action, "sword.yifeng" :),
   //                     }) );
        setup();
    carry_object("/d/yihua/obj/jinlvyi")->wear();
        carry_object("/obj/weapon/sword")->wield();
        add_money("gold",15);
        set("attitude", "friendly");
        set("chat_chance",20);
        set("chat_msg",({
        "����˵������������ȴ���飬����������Σ���ϲ��Ц��һ������\n",
        "����˵����ɱ����ɱ��ɱ����ɱ��\n",
        "����������������������������ϣ������������ѳ\n",
           }) );
       set("inquiry",([

       "����" : "�ҵİ����뿪�ң���֪������������\n",
           "С��" : "�������ҵİ��ˣ�������ô֪�����ģ���\n",
           ]) );
       setup();
}

void init()
{
        object ob;

        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() )
               {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
}
int accept_object(object me, object obj)
{
	if(obj->query("for_fang"))
	{
	me->set_temp("for_fang",1);
         command("say �ѵ�������������\n");
        command("recruit " + me->query("id") );
	return 1;
	}
	return 0;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say("����һ�����˽�����æ˵��" + RANK_D->query_respect(ob)
          +"������ʲô����ô�ܵ��������������뿪!\n");
}
