 inherit NPC;
void create()
{
        set_name("˾����ʦ", ({ "biaotou sima","biaotou"}) );
        set("gender", "����" );
        set("age", 42);
        
        set("long", "����һλ��ʨ�ھֵ���ʦ��\n");
        set("combat_exp", 2800000);
        set("attitude", "friendly");
        
        set("max_force",500);
        set("force",500);
        set("force_factor",30);
        
        set_skill("unarmed", 150);
        set_skill("dragonstrike",150);
        set_skill("dodge", 150);
        set_skill("move",200);
        set_skill("parry",150);
        set_skill("puti-steps",150);
        
        map_skill("dodge","puti-steps");
        map_skill("unarmed","dragonstrike");
        
        switch (random(3)) {
                case 0: set("resistance/kee",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/sen",30);
                }
                        
        set("chat_chance", 1);
        set("chat_msg", ({
                "˾����ʦ���˸���Ƿ˵����˯���ˡ�\n",
        }) );
        
        setup();
        add_money("silver", 5);
        carry_object(__DIR__"obj/jinzhuang")->wear();
        if (!random(2))
        carry_object(__DIR__"obj/hongbao"); 
}        
