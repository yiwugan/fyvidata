 //written by Cheng Bao
// gangster.c 
inherit NPC;
void goaway();
void create()
{
        set_name("ɱ��", ({ "killer" }) );
        set("gender", "����" );
        set("age", 27);
        set("str", 40);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
���ɱ�������棬���޷��������ĳ��࣬���Ǵ������������ܿ�������һ��
�ǳ�������ѵ�����ص�ɱ�֡�
LONG
);
        set("attitude", "heroism");
        set("bellicosity", 1500 ); 
        set("combat_exp", 10000); 
        set("chat_chance", 50);
        set("chat_msg", ({
                        (: goaway :),
        }) );  
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              "ɱ���Եú�����֯����������Ŀ�ĵġ�\n",
              "ɱ�ָߺ�����ɱ������Ա������\n",
        }) ); 
        set("force",5000);
        set("force_factor",80);
        set_skill("unarmed", 200);
        set_skill("blade", 160);
        set_skill("dodge", 140);
        set_skill("parry", 150);
        set_skill("move",100);
        set_skill("fall-steps",100);
        set_skill("shortsong-blade",120);
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("blade","shortsong-blade");
        map_skill("parry","shortsong-blade");
        set("chat_chance_combat", 60);
    	set("chat_msg_combat", ({
//        	(: perform_action, "blade.duangechangmeng" :),
            }) );

        setup();
        add_money("coin", 10); 
        carry_object("/obj/weapon/blade")->wield();
        carry_object("/obj/armor/cloth")->wear();
} 
void goaway()
{
        object ob;
        if (ob=present("importman",environment()) )
        {
                command("heng");
                kill_ob(ob);
                ob->kill_ob(this_object());
                return; 
        }
                
        message_vision("$Nһ�����ڣ���ʧ����Ӱ���٣�\n",this_object());
        destruct(this_object());
}  
