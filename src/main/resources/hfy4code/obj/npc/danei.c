 // heaven_soldier.c
#include <ansi.h> 
inherit NPC;
void backattack();
void create()
{ 
        set_name("���ڸ���", ({ "guard", "body guard" }) );
        set("long", "����һλ���ڸ��֣�ר�ŵ��α���֮��\n");
        set("attitude", "friendly");  
        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100); 
        set("str", 40);
        set("cor", 30);
        set("cps", 25); 
        set("combat_exp", 100000);
        set_skill("sword", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 70); 
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
        set_skill("sword", 60 + random(level/2));
        set_skill("parry", 60 + random(level/2));
        set_skill("dodge", 60 + random(level/2));
        set_skill("move", 60 + random(level/2));
        set_skill("feixian-sword",5+random(level/20));
        set_skill("feixian-steps",5+random(level/20));
        map_skill("sword","feixian-sword");
        map_skill("dodge","feixian-steps");
        map_skill("parry","feixian-sword");
        map_skill("move","feixian-steps");
        set("str",10+level/20+random(level/20));
        set("combat_exp", 100000 + level/8*level*level/4+random(level/8*level*level)*3/4);
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
