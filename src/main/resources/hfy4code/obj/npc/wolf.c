 // heaven_soldier.c
#include <ansi.h> 
inherit NPC;
void backattack();
void create()
{       
        set_name( "狼" , ({ "wolf" }) );
        set("race", "野兽");
        set("age", 10);
        set("long", "一头双眼泛着绿光，嗷嗷嚎叫的恶狼。\n");
        set("max_kee", 100);
        set("str",50);
        set("cor",50);
        set("limbs", ({ "头部", "身体", "尾巴","爪子" }) );
        set("verbs", ({ "bite","claw"}) );
        set("attitude","heroism");
        set("no_arrest",1);
        set("no_fly",1);         
        set("combat_exp", 200000);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("move", 50); 
        setup();  
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
         name() + "仰天长嚎一声，几个起落消失在苍茫雾色中。\n" , environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
           owner->add_temp("max_guard",-1);
        destruct(this_object());
} 
void invocation(object who, int level)
{
        int i;
        object *enemy;
        set_skill("unarmed", 100 + level/2+random(level)/2);
        set_skill("parry", 100 + 3*random(level)/2+3*level/2);
        set_skill("dodge", 100 + 3*random(level)/2+3*level/2);
        set_skill("move", 100 + 3*random(level)/2+3*level/2);
        set("str",30+random(level/5)/2+level/10);
        set("kee",50+level*3);
        set("max_kee",50+level*3);
        set("eff_kee",50+level*3);
        set("sen",50+level*2);
        set("max_sen",50+level*2);
        set("eff_sen",50+level*2);
        set("gin",50+level*2);
        set("max_gin",50+level*2);
        set("eff_gin",50+level*2);
        set("combat_exp", 300000 + level/3*level*level/2+random(level/3*level*level)/2);
        enemy = who->query_enemy(); 
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                        message("vision",
         name() + "对"+enemy[i]->name()+"嗷嗷嘶叫着，看来充满了敌意。\n" NOR,
                 environment(), this_object() );
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
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        object owner;
        if (!me->query("wolfbuff/shiri")) return;
        owner=me->query("possessed");
        if (!owner) return;
        dam = owner->query_skill("summonwolf",1);
        victim->receive_wound("kee",random(dam*3), me);
        return;
}      
