#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��ū", ({ "hua nu", "hua", "nu" }));
        set("long",
            "����һ����ʮ�������Ů��,�Ʋ����˼�֮��,\n"+
            "�������, �������. \n"+
            "��һ���������µĽ�����, ��ʹ�����Լ��ֽ���.\n"+
            "�����ƻ��������ָ���,�ƻ���δ����ϣ��.\n");
        set("title", "�ƻ���������Ů");
        set("gender", "Ů��");
        set("age", 20);
        set("nickname", HIR "����������Ů" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 100);
        set("int", 250);
        set("con", 100);
        set("dex", 80);

        set("kee", 4000);
        set("max_kee", 4000);
        set("sen", 4000);
        set("max_sen", 4000);
        set("gin", 2000);
    set("max_gin", 2000);
    set("force", 1000);
    set("max_force", 20000);

        set("combat_exp", 3000000);
        set("score", 200);
        set_skill("force", 150);
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("sword",150);
        set_skill("literate",100);

        set_skill("jueqing-zhang",150);
        set_skill("mingyu-shengong",150);
        set_skill("lanhua-sword",150);
        set_skill("yihua-jiemu",100);

        map_skill("unarmed", "jueqing-zhang");
        map_skill("force", "mingyu-shengong");
        map_skill("dodge", "yihua-jiemu");
        map_skill("parry", "yihua-jiemu");
        map_skill("sword","lanhua-sword");

        create_family("�ƻ���",2, "��Ů");
        setup();
  //  carry_object("/d/yihua/obj/jinlvyi")->wear();
        carry_object("/obj/weapon/sword")->wield();
        add_money("silver",50);
}

void attempt_apprentice(object ob)
{
   if ((string)ob->query("gender")=="Ů��")
   {
                message_vision("��ū��Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ�������ݻ�ūΪʦ���²�Ҫ����˵��Ȼ�ù���֪���˾Ͳ�������.��\n",ob);
       command("recruit " + ob->query("id"));
                if((string)ob->query("class") != "yihua")
                        ob->set("class", "yihua");
       return;}
   else
      {
                message_vision("��ū�����㿴�˰���,˵�������㻹�ǿ��߰�!��Ȼ�ù����������ҿɱ�������.��\n",ob);

   if ((int)ob->query_skill("mingyu-shengong", 1) < 100) 
           {
                command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö�����������,��Ȼ�ù���֪���Ҳ��ܰ���!");
                return;
           }  
       return;}
}
