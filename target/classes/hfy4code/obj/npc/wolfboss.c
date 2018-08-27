#include <ansi.h> 
inherit NPC;
void backattack();
void create()
{       
        set_name( "��" , ({ "wolf boss" }) );
        set("race", "Ұ��");
        set("age", 10);
        set("long", "һͷ˫�۷����̹⣬�໺��еĶ��ǡ�\n");
        set("max_kee", 100);
        set("str",50);
        set("cor",50);
        set("class","wolfmount");
        set("limbs", ({ "ͷ��", "����", "β��","צ��" }) );
        set("verbs", ({ "bite","claw"}) );
        set("attitude","heroism");
        set("no_arrest",1);
        set("no_fly",1);         
        set("combat_exp", 200000);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("move", 50); 
        set("chat_chance_combat", 10);
    	set("chat_msg_combat", ({
//            (: perform_action, "unarmed.ningxie" :),
    	}));
        setup();  
} 
 void init()
{       ::init();
        add_action("do_killing", "kill");
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
         name() + "���쳤��һ��������������ʧ�ڲ�ã��ɫ�С�\n" , environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
           owner->add_temp("wolf",-1);
        destruct(this_object());
} 

void setboss(object who, int level)
{
        int i;
        object *enemy;
        set("wolf_boss",1);   //����
        set_skill("unarmed", 200 + level+random(level));
        set_skill("parry", 200 + 3*random(level)+level);
        set_skill("dodge", 200 + 3*random(level)+level);
        set_skill("move", 200 + 3*random(level)+level);
        set_skill("wolf-claw",150+random(level));
        map_skill("unarmed","wolf-claw");
        set("str",50+random(level/4)+level/5);
        set("kee",50000+level*40);
        set("max_kee",50000+level*40);
        set("eff_kee",50000+level*40);
        set("sen",50000+level*40);
        set("max_sen",50000+level*40);
        set("eff_sen",50000+level*40);
        set("gin",50000+level*40);
        set("max_gin",50000+level*40);
        set("eff_gin",50000+level*40);
        set("combat_exp", 5000000 + level/3*level*level+random(level/3*level*level)/2);
        enemy = who->query_enemy(); 
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
/*                        message("vision",
         name() + "��"+enemy[i]->name()+"��˻���ţ����������˵��⡣\n" NOR,
                 environment(), this_object() );*/
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
                owner->add_temp("wolf",-1);
        backattack();
        ::die();
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        object owner;
        owner=me->query("possessed");
        if (!owner) return;
        dam = owner->query_skill("wolf-curse",1);
        victim->receive_wound("kee",random(dam*20), me);
        return;
}      
int do_killing(string arg)
{       
        object player, victim;
        object owner;
        string id;
        if(!arg) return 0;
        player = this_player();
        owner=this_object()->query("possessed");         
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                id = victim->query("id");
                if(id==owner->query("id"))
                {
                	message_vision(RED"$NͻȻ��Хһ��������һ��������"+owner->name()+"��$n�м䣡\n"NOR, this_object(),player);
                	this_object()->kill_ob(player);
               		player->kill_ob(this_object());
               		owner->remove_all_killer();
               		return 0;
               	}
               	return 0;
        }
        return 0;
}
