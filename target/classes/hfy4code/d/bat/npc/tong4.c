 inherit NPC;
void create()
{
        set_name("С��ͯ", ({ "little kid"}) );
        set("gender", "����" );
        set("long", "����һ���ɰ���С��ͯ��\n");
        set("attitude", "friendly");
        set("age", 12); 
        set("combat_exp", 150000);
//        set("str", 20);
          set("cor", 20);
          set("agi", 20); 
        set_skill("parry", 170+random(200));
        set_skill("dodge", 170+random(200));
        set_skill("move", 170+random(200));
        set_skill("unarmed", 170+random(200));
        set_temp("apply/damage",10+random(30));  
 
        setup();
        add_money("coin", 5);
        carry_object("/obj/armor/cloth")->wear();
}  