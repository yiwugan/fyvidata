 // neon@fengyun.com
#include <ansi.h>
#include <combat.h>
inherit ITEM; 
void generate_name(); 
void create()
{       set_name( WHT"冰魄神针"NOR, ({ "shen zhen" , "zhen"}) );
        set_weight(10);
        set("unit", "根");
        set("long", "一根晶莹的银针，据说在千年冰蟾的血里浸泡过，可以用来射击（shoot）。\n");
        set("value", 50000);
        set("level", 50);
        set("no_drop", 1);
        ::init_item();
} 
void init(){
        add_action("do_shoot", "shoot");
} 
int do_shoot(string arg){
        object me, target;
        int level, exp, t_exp, damage;
        int busy_num;
        string msg;
        
        me = this_player();
        if (!arg) return notify_fail("你要对谁使用暗器？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n"); 
        target = present(arg,environment(me));
                
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) ) 
                return notify_fail( this_object()->name() + "只能对战斗中的对手使用。\n");      
        if (target->is_busy())
                return notify_fail("对方已经不能动弹了。\n");
        level = (int) query("level");
        damage = 0;
   
        t_exp = (int) target->query("combat_exp");
   exp   = (int) me->query("combat_exp");
        msg  = HIW"\n$N将手一挥，"NOR +name()+HIW"无声无息地飞出。\n\n"NOR;
        if( random(exp)*level/50 + 4*exp/5 > t_exp ) {
                damage = me->query_skill("perception",1)* level /10;
                damage = damage/2 + 2 * random(damage);
                msg +=  HIM + "$n浑身一麻，动弹不得！\n" NOR;
                target->receive_wound("kee", damage/20, me);
                target->add("sen",-damage/5);
                target->add("eff_sen",-damage/5);
                target->receive_damage("sen", 1, me);
                if (target->query("no_busy")) {
                        busy_num = target->query("no_busy");
                        target->delete("no_busy");
                        call_out ("busy_recover",12, busy_num, target);
                }
                target->start_busy(4);
        } else
                msg += "但是被$n躲开了。\n"; 
        message_vision(msg, me, target);
        if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 2);
           COMBAT_D->report_status(target);
        }
        me->start_busy(2);
        destruct(this_object());
        return 1;
} 
int busy_recover (int busy_num, object obj)
{
        obj->set("no_busy",busy_num);
        return 1;
}        
