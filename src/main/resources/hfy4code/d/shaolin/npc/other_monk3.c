 // TIE@FY3
inherit NPC;
void create()
{
        //string *name = ({"ɽ����","�˹�����","����","ӡ��","��ɽ��","������","��ɽ","̩��"});
        set_name("����ĺ���", ({ "saiwai monk", "monk"}) );
        set("gender", "����");
        set("age", random(90)+10);
        set("long",
                "һ�������ֵ����º��С�\n");
        set("combat_exp", 3000000);
        set("force",1200);
        set("max_force",1200);
        set("force_factor",50);
        set("cor",40);
        set("cps",40);
        
        set("class","shaolin");
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
        set("no_busy",2); 
        set_skill("unarmed", 180);
        set_skill("dabei-strike",150);
        set_skill("move",200);
        set_skill("dodge",150);
        set_skill("puti-steps",150);
        set_skill("force",100); 
        
        map_skill("unarmed", "dabei-strike");
        map_skill("dodge","puti-steps");
        map_skill("move","puti-steps");
              
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"̾�������ֲ���Ϊ������ͥѽ����\n",
                name()+"�����ҿ�����Ҳ�������������ߣ�\n",
                name()+"����˵������λС�ܣ���������Σ�\n",
        }) ); 
        set("attitude", "friendly");
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
} 