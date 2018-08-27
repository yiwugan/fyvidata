 //neon@fy4
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void get_up(object me,object target);
int perform(object me, object target)
{
        string msg;
        int extra, myexp, enemyexp, lvl;
        object weapon; 
        if(me->query("class")!="beggar" && userp(me))
                return notify_fail("�۰��־���ֻ���ڸ�ؤ����ӣ�\n");
        
        if((int)me->query_skill("dagou-stick",1) < 60)
                return notify_fail("��Ĵ򹷰���������������\n");       
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۰��־���ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        weapon = me->query_temp("weapon");
        
        lvl = (int) me->query_skill("dagou-stick",1);
        if (me->query("force")<lvl/2+10)        
                return notify_fail("�������������\n");
        extra = me->query_skill("staff");
        myexp = (int) me->query("combat_exp");
        enemyexp= (int) target->query("combat_exp");
        
        msg = HIY"\n$N"+HIY"��׼$n"+HIY"����������������"+ weapon->name() + HIY"�����ѵ�ˮ����������$n"+HIY"���̡�\n" NOR;
        
        if (target->query("disable_type")&& target->query("is_unconcious")) {
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                return 1;
        }
        else message_vision(msg,me,target); 
        if (myexp/3 + random(myexp/80*extra) > enemyexp) {
                msg = HIG"\nֻ��"+ weapon->name() + HIG"���ڵ��£����ᵯ��$n"HIG"�ƺ���һ����������ȥһ����\n"
                        HIR+ weapon->name()+HIR"��ž����һ�����ݺ�����$n"HIR"�ֹ��ϣ�"NOR"\n\n"
                   WHT"���ų����ҽУ�$n��ͨһ�µ��ڵ��ϣ�\n\n"NOR;
                if (me->query("cps")<random(target->query("cps")*3)) {
                        msg +=CYN"$N����$n�۵��ڵ��ϴ����Ц������ֱ��������\n��������������˵�����ֲ��ù�����Ҫ�����ȶ���������\n"NOR;
                        me->start_busy(3);
                }
                else me->start_busy(2);
                if (userp(me))  me->add("force",-lvl/2);
                //Beat down enemy
                target->start_busy(3);
                target->receive_wound("kee", extra+random(extra*2), me);
                call_out("get_up",3, me,target);
                message_vision(msg,me,target);
                COMBAT_D->report_status(target);
                COMBAT_D->win_lose_check(me,target,1);
                        
        }
        else {
                me->add_temp("apply/attack", extra/2);
                me->add_temp("apply/damage", extra/2);
                msg = HIR"\n�ۼ�$nѸ�ٱ任������$Nֻ����ʽͻ����һ�����ֻӳ���\n"NOR;
//              me->set_temp("dagou/pfm",1);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
//              me->delete_temp("dagou/pfm",1);
                me->add_temp("apply/attack", -extra/2);
                me->add_temp("apply/damage", -extra/2);
                me->start_busy(2);
        }
        return 1;
} 
void get_up(object me,object target){
        
        if(!target||!living(target)||target->is_ghost())
                return ;
        message_vision(YEL "\n\n$N�ڵ��ϴ��˼�������������ʹ�Ǳ�������������������\n\n" NOR, target);
        
}     
