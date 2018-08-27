#include <ansi.h>
inherit NPC;
void backattack();
void create()
{ 
        set_name("���ڸ���", ({ "bodyguard" }) );
        set("long", "����һλ���ڸ��֣�ר�ŵ��α���֮��\n");
        set("attitude", "friendly");
        set("no_fly",1);
        set("no_arrest",1); 
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100); 
        set("str", 40);
        set("cor", 30);
        set("cps", 25); 
        set("combat_exp", 80000);
        set_skill("sword", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("move", 50);
        set_skill("feixian-sword",5);
        set_skill("feixian-steps",5);
        
        map_skill("sword","feixian-sword");
        map_skill("dodge","feixian-steps");
        map_skill("parry","feixian-sword");
        map_skill("move","feixian-steps"); 
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
} 
int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
} 
void leave()
{
        object owner;
        message("vision",
                 name() + "˵���������б仯������Ϊ����\n\n"
                + name() + "����������ʧ�����ˡ�\n" , environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
        destruct(this_object());
} 
void invocation(object who, int level)
{
        int i;
        object *enemy;
        set("dur",15);
        set("fle",5);
        set("con",15);
        set("cor",25);
        set("kee",900);
        set("max_kee",900);
        set("eff_kee",900);
        set_skill("sword", 60 + random(level/2));
        set_skill("parry", 60 + random(level/2));
        set_skill("dodge", 60 + random(level/2));
        set_skill("move", 60 + random(level/2));
        set_skill("feixian-sword",5+random(level/40));
        set_skill("feixian-steps",5+random(level/20));
        
        set("str",10+level/20+random(level/20));
        if (query("str")>35) set("str",35);
        set("combat_exp", 110000 + level/8*level*level/6+random(level/8*level*level)/2);
        
        if (level < 201)
                        set_name("���ڸ���",({ "bodyguard" }));
                else if (level<300)
                        set_name(HIY"��ǰ����"NOR,({ "bodyguard" }));
                else 
                        set_name(HIR"������"NOR,({ "bodyguard" }));
   
        message("vision",
                 name() + "�ȵ����󵨣����Һͳ�͢���ٹ���ȥ��\n" NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
        set("possessed",who);
}
void backattack()
{
        int i;
        object owner, *enemy;
        if(objectp(owner=this_object()->query("possessed")))
        {
                enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        } 
        } 
} 
void die()
{
        object owner;
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
        backattack();
        ::die();
}      
