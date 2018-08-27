 inherit NPC;
int kill_him();
void smart_fight(); 
void create()
{
        object armor;
        set_name("����ѷ", ({ "guo changxun" }) );
        set("gender", "����");
        set("age", 39);
        set("long",
                "�䵱�����ŵ��ӣ���һ�����ɫ�ĵ��ۡ�\n"
        );
        
        set("inquiry", ([
            "ͷ­��" : (: kill_him :),
             "�䵱������" : (: kill_him :),
              "������" : (: kill_him :),
        ]));
        
        set("attitude","friendly");
        set("combat_exp", 4500000);
        set("score", 200);
        set("class", "wudang"); 
        set("force",2000);
        set("max_force",2000);
        set("force_factor",100);
        set("str",40);
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40); 
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
        
        set("no_busy",8);
        
        create_family("�䵱��", 58, "����"); 
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("taijiforce", 200);
        set_skill("taiji", 180);
        set_skill("taiji-sword", 180);
        set_skill("five-steps", 200);
        set_skill("taiji",180); 
        map_skill("force", "taijiforce");
        map_skill("sword", "taiji-sword");
        map_skill("parry", "taiji");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
        
        setup(); 
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/skinmask2");
        armor=new("/obj/armor/cloth");
        armor->set_name("����ɫ�ĵ���",({"cloth"}) );
        armor->move(this_object());
        armor->wear(); 
} 
int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="�䵱��" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say �䵱�ɲ��ͱ��ɵ��˹��С�");
        return 0;
} 
int kill_him()
{
        object me;
        me = this_player();
        if (!me->query("m_success/�з�����")||!me->query("m_success/ͷ­��")    )       {
           command("heng");
                command("say ��������ȥ�����ʱ�����ŵġ�\n");
                return 1;
        }       
        command("say ������֪�����治�٣��� \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        this_object()->set("have_mask",1);        
        return 1;
}
 
void die(){
        object *inv, ob, killer;
        int i;
        if(objectp(killer=query_temp("last_damage_from") ))
        if (killer->query("m_success/ͷ­��")&& this_object()->query("have_mask")
                && !killer->query("marks/�ϵ�����")) {
                ::die();
                return;
                }
        inv = all_inventory(this_object());
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if(ob->query("name")== "���") {
                        destruct(ob);
                }
        }
        ::die();
}  
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie2");
                return;
        }
   return;
}  
