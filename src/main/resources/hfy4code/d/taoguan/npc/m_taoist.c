 inherit NPC;
void create()
{
        set_name("�����ʿ", ({ "adult taoist" }) );
        set("gender", "Ů��");
        set("age", 42);
        set("long",
"���Ǹ�������͵ĵ�ʿ��������ĥ�����������\n"
);
        set("combat_exp", 300000);
        set("score", 200); 
        set("class", "taoist"); 
        set("int", 30);
        set("cps", 30);
        set("spi", 30); 
        set("force", 50);
        set("max_force", 50);
        set("force_factor", 30);
        
        set("sen",1200);
        set("max_sen",1200);
        set("eff_sen",1200); 
        set("mana", 600);
        set("max_mana", 600);
        set("mana_factor", 5); 
        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "invocation" :),
        }) ); 
        create_family("���幬", 6, "����"); 
        set_skill("move", 80);
        set_skill("force", 200);
        set_skill("spells", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("gouyee", 80);
        set_skill("notracesnow",140);
        set_skill("taoism", 70);
        set_skill("necromancy", 70);            
        set_skill("qiankunstrike",80); 
        map_skill("force", "gouyee");
        map_skill("unarmed","qiankunstrike");
        map_skill("dodge","notracesnow");
        map_skill("spells", "necromancy");  
        setup(); 
        add_money("coin", 30);
        carry_object(__DIR__"obj/m_cloth")->wear();
} 
int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="���幬" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say ���幬���ͱ��ɵ��˹��С�");
        return 0;
}
      
