 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
                
        extra = me->query_skill("duanhun-spear",1) ;
        if ( extra < 145) return notify_fail("��Ķϻ�ǹ���������죡\n");
        
/*      if ( userp(me) && me->query_skill_mapped("force") != "xiaochengforce"
                || me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("�ϻ�ǹ��Ҫ�����ڹ�����ϣ�\n");     */
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����β����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = target->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        
        if (extra >119 && me->query_skill("zen",1)>179 && me->query("class")=="shaolin")
			myexp = myexp+random(myexp);
			
        hisexp= (int)target->query("combat_exp");
        
        if (hisexp>3500000) hisexp=hisexp*3;
        
        if(random(hisexp) < myexp && weapon && random(2))       {
                message_vision(HIW "\n\n$Nʹ��һʽ���β���ǹ��ǹ�������߰��ס$n���еı��У�"NOR+ 
weapon->name()+  HIW"���ֶ��ɣ�\n\n" NOR, me,target);
                if( weapon->unequip()) 
                        weapon->move(environment(target));
        } else  {
                me->add_temp("apply/attack", extra);
                me->add_temp("apply/damage", extra*2);
                msg = HIR+ "\n\n$Nʹ��һʽ���β���ǹ�����е�"NOR+(me->query_temp("weapon"))->name()+HIR"�����߰�ֱҧ$n��$l��\n\n"+ NOR;
                COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
           me->add_temp("apply/attack", -extra);
                me->add_temp("apply/damage", -extra*2);
        }
        if (me->query_busy()<2) me->start_busy(2);
        return 1;
}   
