 inherit NPC;
void smart_fight();
void smart_attack();  
void create()
{
       set_name("����", ({ "yun song", "song" }) );
       set("nickname", "��������");
        set("gender", "����" );
        set("age", 32);
        set("int", 30);
        set("class","lama");
        create_family("������", 21, "����");
        set("long",
        "�������Ǹ��׸�ɮ�Ĺ���С���ӣ��������ڡ�������֮Ϊ����\n"
        "�ڵ��Ӱ�����\n"
                );
        set("chat_chance", 1);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("chat_msg", ({
                "����̾�˿����������ɴ�ʦ�֣���֪��������ô���ˡ���\n",
        }) ); 
        set("inquiry", ([
                "������": "��....������һ������ʦ�����ɵ��ߵġ�\n",
                "����": "�����ڲ��������ǵĴ������",
        ]) );
        set("attitude", "peaceful");
        set("mana",4000);
        set("max_mana",4000);
        
        set_skill("iron-cloth", 100);
        set_skill("staff", 100);
        set_skill("lamastaff", 100);
        set_skill("unarmed", 100);
        set_skill("lamaism", 10);
        set_skill("bloodystrike", 50);
        set_skill("force", 100);
        set_skill("bolomiduo", 100);
        set_skill("spells",100);
        set_skill("parry",100);
        set_skill("kwan-yin-spells",100);
   set_skill("perception", 100);
        
        map_skill("spells","kwan-yin-spells");
        map_skill("parry","lamastaff");
        map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("staff", "lamastaff");
        
        set("combat_exp", 1500000);
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
        setup();
        carry_object(__DIR__"obj/redclothh")->wear();
        carry_object(__DIR__"obj/7staff")->wield();
}   
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        if (who->is_busy()) return;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2) {
                who->cast_spell("ni");
                return;
        }
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_skill("iron-cloth")>300 
                                || enemy[i]->query("combat_exp")>who->query("combat_exp")) {
                                who->cast_spell("an");
                                switch( random(3) ) {
                                        case 0: command("grin");
                                                break;
                                        case 1: command("smile");
                                                break;
                                   case 2: command("smug");
                                                break;
                                        }
                                return;
                        }               
                        this_object()->smart_attack();
                        }
        }
return;
}  
smart_attack() {
        this_object()->perform_action("staff.fofazhizun");    
        return;
        }
