#include <ansi.h>
//inherit NPC;
inherit SSERVER;
int mimicurse(); 
void create()
{ 
        set_name("的亡灵", ({ "spirit"}) );
        set("long", "这是一个借尸还魂的亡灵，双眼茫然无神地注视着前方。\n");
        set("attitude", "friendly");
        set("title",BLU"借尸还魂"NOR);
        set("class","yinshi");
        set("max_atman", 1000+random(4000));
        set("atman", 1000+random(4000));
        set("max_mana", 1000+random(4000));
        set("mana", 1000+random(4000));
        
        set("resistance/kee",50);
        set("resistance/sen",50);
        set("resistance/gin",50);

        set("no_arrest",1);
        set("no_fly",1);
        
        set("combat_exp", 161361);
        set_skill("cursism",100);
        set_skill("celecurse",100);
        map_skill("cursism","celecurse"); 
        setup(); 
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: mimicurse() :),
        }) ); 
        carry_object("/obj/armor/cloth")->wear();
}  
void init()
{
        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
        add_action("do_kill","kill");
} 
void leave()
{
        object owner,*pros;
        message("vision",
                 name() + "消失不见了。\n" , environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("timer/solidghost",-1);
                pros = owner->query_temp("protectors");
                        pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        destruct(this_object());
}  
void heart_beat()
{
        object leader;
        
        ::heart_beat();
        
        if(query_temp("is_unconcious")||is_busy())
                return ;
        if(query("possessed"))
        {
                leader=query("possessed");
                if(environment(leader)!=environment()&&(!leader->is_ghost()))
                {
                        message_vision("$N无声无息地离去了。\n",this_object());
                        this_object()->move(environment(leader));
                        message_vision("$N飘了过来。\n",this_object());
                        delete("leave_room");
                }
        }
        
        else
        {
                if(!query("leave_room"))
                        set("leave_room",1);
                else
                        add("leave_room",1);
                if(query("leave_room")==5)
                        leave();
        }
}  
int do_kill(string arg)
{
        object victim,who;
        
        who=this_player();
        if(!arg) return 0;
        if(environment()->query("no_fight"))
                return 0;
        victim=present(arg,environment());
        if(!victim) return 0;
        if(victim==who) return 0;
        if(victim->query("possessed")==who)
        {
                tell_object(who,"此亡灵是你的法力所聚，杀它会损伤元神的。\n");
                return 1;
        }
        if(victim==query("possessed")||victim->query("possessed")==query("possessed"))
                {
                message_vision("$N喃喃道：“休。。。伤。。。我。。。主。。。！！”\n",this_object());
                kill_ob(who);
                }       
        if(who==query("possessed"))
        {
                message_vision("$N喃喃道："+victim->query("name")+"，拿。。。命。。。来。。。！”\n",this_object());
                kill_ob(victim);
        }
        return 0;
}  
void invocation(object who, int level)
{
        int i;
        object *enemy,*pros;
        int owner_exp,owner_hp;
        
        
        set("str",50+random(level/2));
        set("agi",50+random(level/2));
        set("cor",50+random(level/2)); 
        set_skill("cursism",level/3*2);
        set_skill("celecurse",level/3*2);
        set_skill("unarmed",random(level/2));
        set_skill("dodge",random(level/2));
        set_skill("parry",random(level/2));
        set_skill("move",random(level/2));
        //set_skill("iron-cloth",random(level/2));
        
   owner_exp=who->query("combat_exp");
        owner_hp= who->query("max_kee");
        
        map_skill("cursism","celecurse"); 
        set("max_kee",500+random(level*level/5)+owner_hp/5);
        set("eff_kee",query("max_kee"));
        set("kee",query("max_kee"));
        set("max_gin",query("max_kee"));
        set("eff_gin",query("max_gin"));
        set("gin",query("max_gin"));
        set("max_sen",query("max_kee"));
        set("eff_sen",query("max_sen"));
        set("sen",query("max_sen"));
        
        
        set("combat_exp", 1000000 + level*level*5+random(level*level*level/50)+owner_exp/5*4);
        set("possessed",who); 
        pros = who->query_temp("protectors");
        if(sizeof(pros))
                pros += ({ this_object() });
        else
                pros = ({ this_object() });
        who->set_temp("protectors",pros);
} 
void die()
{
        object owner,*pros;
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("timer/solidghost",-1);
                pros = owner->query_temp("protectors");
                        pros -= ({ this_object() });
                owner->set_temp("protectors",pros);
        }
        message_vision(BLU"$N惨叫一声，化成一缕黑烟消失了。\n"NOR,this_object());
        destruct(this_object());
}  
int mimicurse()
{
        string msg,id_enemy;
           int damage, ap, dp;
        int bonus_damage, my_exp;
        object owner,me,target;
        
        me=this_object();
        
        if( !target ) target = offensive_target(me);
        if( !target
                ||!target->is_character()
                ||target->is_corpse()
                ||target==me)
                return notify_fail("你要对谁施展这个降头？\n");
            
        me->receive_wound("kee", 100);
        msg = RED "$N的眼中红光一闪，一条细如发丝的血线射向$n！\n\n" NOR;
            
        ap = me->query_skill("cursism");
        my_exp=me->query("combat_exp");
                    
        // 600 + random(800)
        damage = ap*3 + random(ap*4);
        
        owner=this_object()->query("possessed");
        if (objectp(owner))     {
                bonus_damage = (owner->query("combat_exp")-4000000)/6000*damage/1000;
                if (bonus_damage<0) bonus_damage =0;
                if (bonus_damage>damage) bonus_damage = damage;
        }       
                        
        damage = damage + bonus_damage;
         
        ap=random(5*owner->query("combat_exp"));
        dp = target->query("combat_exp");
        
        if( ap>dp) {
                message_vision(msg, me, target);
                target->receive_wound("kee", damage/2, me);
                target->receive_damage("kee", damage/2, me);
                target->set_temp("damaged_during_attack", 0);
                COMBAT_D->report_status(target);
           COMBAT_D->win_lose_check(me,target,1);
            } else
            {
                msg += "但是被$n发现了！！\n";
                message_vision(msg, me, target);
            }
            me->start_busy(2);
            return 1;
}    
