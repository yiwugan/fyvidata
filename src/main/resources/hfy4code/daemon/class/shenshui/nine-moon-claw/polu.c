 // silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void hit_break(object target, object me, int factor); 
int perform(object me, object target)
{
        string msg;
        int extra, my_exp, exp_factor;
        
        if(me->query("class")!="shenshui")
                return notify_fail("ֻ����ˮ�����Ӳ���ʹ������­���ľ�����\n");
        if (me->query_skill("nine-moon-claw",1)<150)
                return notify_fail("��ģ۾����׹�צ�ݻ��������졣\n");
        if (me->query_skill("nine-moon-steps",1)<150)
                return notify_fail("��ģ۾������ݻ��������졣\n");
        if (me->query_skill("nine-moon-force",1)<150)
                return notify_fail("��ģ۾����ľ��ݻ��������졣\n");
        if (me->query_skill("nine-moon-spirit",1)<150)
                return notify_fail("��ģ��Ů�񹦣ݻ��������졣\n"); 
        if (me->query_skill_mapped("force") != "nine-moon-force")
                return notify_fail("����­����Ҫ�����ľ�����ϡ�\n");
        if (me->query_skill_mapped("dodge") != "nine-moon-steps")
                return notify_fail("����­����Ҫ����������ϡ�\n");
        my_exp = (int) me->query("combat_exp");
        exp_factor = 750000000/my_exp;
        if (exp_factor < 100) exp_factor = 100;
        
//      2.7M, 4-5mins delay, after 3.4M no delay.
//        if(exp_factor>220 && (int)me->query("timer/polu") + exp_factor > time())
	if(exp_factor>220 && (int)me->query("timer/polu") + 60 > time())  //by xiaolang 1����performһ��
                return notify_fail(HIM"����­���ķ��������󣬲�������ʹ�á�\n"NOR);
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����­��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        extra = me->query_skill("nine-moon-claw",1)*3/2+ me->query_skill("nine-moon-steps",1)/2
                + me->query_skill("nine-moon-force",1)+ me->query_skill("nine-moon-spirit",1);
   extra = extra *4;
// 2.7M 2400, 6.4M 3020.        
        
// >3.125M  have 2 hits.
        if (exp_factor>240) {
                message_vision(HIW"$N�����������������䣬Ѹ���ޱȣ�����Ȱ��۵�$n"+HIW"��ߣ�
��������������֣������ָ��$n"+HIW"��ͷ��������ȥ��\n"NOR,me,target);
                hit_break(target, me, extra*2/3);
                if (me->query_busy()<3) me->start_busy(3);
        }
        
        else {
                me->add_temp("apply/attack", extra/6);  
                me->add_temp("apply/damage", extra/6);
                msg = HIW"$N�����������������䣬Ѹ���ޱȣ�����Ȱ��۵�$n"HIW"��ߣ�
��������������֣������ָ��ץ$n"+HIW"$l��\n"NOR ;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM, msg);
                me->add_temp("apply/attack", -extra/6);
                me->add_temp("apply/damage", -extra/6);
                //<- adjust damage here
                
                if (target->query_temp("damaged_during_attack") && (int)me->query("timer/polu") + exp_factor/20 < time()) {
                        //<- Adjust timer here
                        message_vision(HIW"\n$N"+HIW"һ�е��֣�������ͣ�����Ƽ������ָ����$n"+HIW"��ͷ��������ȥ��\n"NOR,me,target);
                        hit_break(target, me, extra/2);
                }
//      after 4.5M, 2 self busy instead of 3.
                if (me->query_busy()<2+exp_factor/166) 
                        me->start_busy(2 + exp_factor/166);    //<- Addjust busy here
                
        } 
        return 1;
} 
void hit_break(object target, object me, int factor) {
        int resist; 
// damage is 2400+random(2400) to 3000+random(3000);    
        if(target->query("combat_exp") < random((int)me->query("combat_exp"))*10)
        {
                message_vision(MAG"$N"+MAG"�ҽ�һ���������ѱ�$n"+MAG"��������ס��\n"NOR,target,me);
                resist=target->query("resistance/kee");
           target->set("resistance/kee",0);
                target->receive_wound("kee",factor/2+random(factor));
                target->receive_damage("kee",factor/2+random(factor));
                target->set("resistance/kee",resist);
                target->set_temp("last_damage_from",me);
                COMBAT_D->report_status(target);
        }
        else    message_vision(YEL"$N���Ų�æ����ǰ�벽���ܿ�������Ҫ����\n"NOR,target);
        
        me->set("timer/polu",time());
        
} 
int help(object me)
{
        write(@HELP
ָ���ʽ : perform polu
���������ݣ������ʼ��ߵ�һ�У�Ϊ��ˮ�书��
�������ۡ���������������ȣ�ֻ������ɱ��
̫ʢ�������롰������ͬʱʹ�á� 
HELP
        );
        return 1;
}
