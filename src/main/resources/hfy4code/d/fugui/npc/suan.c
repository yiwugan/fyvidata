 // suan.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("��÷��", ({ "suanmei tang","tang" }) );
        set("gender", "Ů��" );
        set("vendetta_mark","fugui");
        set("age", 24);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("long",
"��÷���ǵ�Ư��������Ư�����ˡ������ϴ�����Ȼ�Ǽ��ֲ��·�������\n��ʲô�·����������ϣ������úܺÿ���\n\n"); 
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("max_force", 300); 
        set("force", 600);             
        set("force_factor", 10);
        set("chat_chance_combat", 40);
        set_skill("sword", 100);
        set_skill("move", 100);
        set_skill("snowshade-sword", 120);
        set_skill("force", 100);
        set_skill("notracesnow",100);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("gouyee",100);
        map_skill("sword", "snowshade-sword");
        map_skill("parry", "snowshade-sword");
        map_skill("dodge", "notracesnow");
        map_skill("move", "notracesnow");
        map_skill("force", "gouyee");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.baixueaiai" :),
        }) );
        set("chat_chance",2);
        set("chat_msg", ({
        "��÷���ƺ����Ĵ�Ѱ����Щʲô���������������֣�ǰЩ������\n�������Ǽ���Ʊ�������񷿵�ѽ����\n\n",
                                })  );
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
} 
void init()
{
        object  ob;
        ::init();
        ob = this_player();
        call_out("greeting", 1, ob);       
}  
int greeting(object ob)
{
        if (!random(10))
                message_vision("$N����üͷ�������ӵ�������Թ���������Ҳʵ���ൽ���ˣ�\nŶ���鷳��λ"+RANK_D->query_respect(ob)+"���Ҵ�ɨһ��,��ô����\n",this_object());
        return 1;
}   
