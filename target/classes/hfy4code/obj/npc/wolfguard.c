#include <ansi.h> 
inherit NPC;
object F_boss;
void use_roar();
void create()
{       
        set_name( "��" , ({ "wolf" }) );
        set("race", "Ұ��");
        set("age", 10);
        set("long", "һͷ˫�۷����̹⣬�໺��еĶ��ǡ�\n");
        set("max_kee", 100);
        set("str",50);
        set("cor",50);
        set("limbs", ({ "ͷ��", "����", "β��","צ��" }) );
        set("verbs", ({ "bite","claw"}) );
        set("attitude","heroism");
        set("no_arrest",1);
        set("no_wolf_force",1);
        set("no_fly",1);      
        set("kuaidao_boss",1);   
        set("combat_exp", 200000);
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("move", 50); 
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
             (: use_roar :),
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
        message("vision",
         name() + "���쳤��һ��������������ʧ�ڲ�ã��ɫ�С�\n" , environment(),
                this_object() );
        destruct(this_object());
} 
void setguard(object who, int level)
{
        int i;
        object *enemy;
        set_skill("unarmed", 100 + level+random(level));
        set_skill("parry", 100 + 3*random(level)+3*level);
        set_skill("dodge", 100 + 3*random(level)+3*level);
        set_skill("move", 100 + 3*random(level)+3*level);
        set_skill("wolf-claw",100+random(level));
        map_skill("unarmed","wolf-claw");
        set("str",30+random(level/5)+level/5);
        set("kee",10000+level*30);
        set("max_kee",10000+level*30);
        set("eff_kee",10000+level*30);
        set("sen",10000+level*20);
        set("max_sen",10000+level*20);
        set("eff_sen",10000+level*20);
        set("gin",10000+level*20);
        set("max_gin",10000+level*20);
        set("eff_gin",10000+level*20);
        set("combat_exp", 3000000 + level/3*level*level+random(level/3*level*level)/2);
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
void die()
{
        object boss;
        F_boss = find_living("wolf boss");
        if(environment(F_boss))
        {
           message_vision(HIR"���������쳤Х��ͻȻȫ���ֳ����˻�������\n"NOR,this_object());
           "/cmds/imm/full"->main(this_object(),"");
        }
/*        if(objectp(boss=this_object()->query("boss"))){
        	message_vision(HIR"$N���쳤Х��ͻȻȫ���ֳ����˻�������\n"NOR,this_object());
        	"/cmds/imm/full"->main(this_object(),"");
        }*/
        else ::die();
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
               		owner->remove_killer(player);
               		player->remove_killer(owner);
               		return 1;
               	}
               	return 0;
        }
        return 0;
}
void use_roar()
{
    object *enemy, ob;
    object owner;
    string msg; 
    int lvl;
    
    if(!objectp(owner))
    	return;
    	else { 
    lvl=0;
    enemy = query_enemy();
    owner=this_object()->query("possessed");
    lvl=(int)owner->query_skill("wolf-curse");
    
    if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        message_vision(RED"���~~��~~~�����������쳤Х���̶���������$N�ľ���ս����\n"NOR, ob);
    tell_object(ob,HIC"������Х�����ƺ�������Χ�������������ǵ���Ӱ�����е��ӣ����ɵ÷����˹����ٶȣ�\n"NOR);
    ob->receive_wound("sen",random(2*lvl));
    if(!ob->query_busy()) ob->start_busy(1);
    ob->apply_condition("wolfclaw", 
        (int)this_player()->query_condition("wolfclaw")
        + random(2)+1);
} 
}