#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
        string msg;
        int damage, extra, dp;
        int i;
        object corp,*enemy,weapon, newweapon,newcloth;
        
        if(me->query("class")!="wolfmount")
                return notify_fail("只有狼山弟子才能使出「分身术」。\n");
        extra=me->query_skill("cursism");
        if(extra < 180 )
                return notify_fail("你的降头术不够高！\n");
        if(!me->is_fighting())
                return notify_fail("你现在没有使用分身的必要。\n"); 
        if( target && target != me)
                return notify_fail("你不能对别人使分身术．\n");
        if( (int)me->query_temp("figureshade") ) 
                return notify_fail("你的分身还没有收回！！\n");
        
        damage=me->query("max_kee")/5;
        if(damage<100) damage=100;
        if((int)me->query("kee") < damage )
                return notify_fail("你的气血不够！\n");
        me->receive_wound("kee", damage);
        msg = HIC "你暗念咒语，使出个障眼法．．．\n\n" NOR;
        me->save();
        tell_object(me,msg);
        extra=extra*extra;
        if(random(extra+10000)>extra)
        {
                message_vision(HIW"隐隐约约似乎有什么东西在$N身前一闪而过，但立刻消失了。\n"NOR,me);
                me->start_busy(2);
                return 1;
        }
        me->set_temp("figureshade",1);
        me->save();
        seteuid(getuid());
        corp=new("/d/fy/npc/shadefigure");
   corp->changeshape(me);
        corp->set("possessed",me);
        if(weapon=me->query_temp("weapon"))
        {
                newweapon=new("/obj/weapon/"+weapon->query("skill_type"));
                if (newweapon) {
                        newweapon->set("name",weapon->query("name"));
                        newweapon->set("id",weapon->query("id"));
                        newweapon->move(corp);
                        newweapon->wield();
                }                       
                newcloth=new("/obj/armor/cloth");
                newcloth->move(corp);
                newcloth->wear();
        }
        corp->set("owner",me);
        corp->move(environment(me));
        if(enemy=me->query_enemy())
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) 
                        enemy[i]->kill_ob(corp);
                        corp->kill_ob(enemy[i]);
                
        }
        if(me->query("class")=="wolfmount"){
                me->remove_all_killer();
                me->set("env/invisibility",1);
        } 
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,corp,damage:), (int)me->query_skill("cursism")/5);
        
        return 1;
}  
void remove_effect(object me,object corp,int damage)
{
        int eff_kee;
        
        me->delete("env/invisibility");
        
        if(!me->query_temp("figureshade"))
           return;
        eff_kee=me->query("eff_kee");
        me->delete_temp("figureshade");
        if(corp)
        {
                tell_object(me, "你已经收回了你的分身．\n");
                corp->disappear();
                eff_kee=eff_kee+damage;
                if(eff_kee>me->query("max_kee"))
                        eff_kee=me->query("max_kee");
                me->set("eff_kee",eff_kee);
        }       
}  
