 // tie@fengyun
//ʳ֥Ӣ������Ȫ�����ȹ�֦��������
//�����£��λ�Ԫ���������Σ���Ƿ�����档
//��δ�ƣ�����ǧ��������ɽ������
/*
    �̸��У����ף� 
�ԾƵ��裬�������Σ�
Ʃ�糯¶��ȥ�տ�ࡣ
�����Կ�����˼������
���Խ��ǣ�Ψ�жſ���
�������ƣ��������ġ�
��Ϊ���ʣ���������
����¹����ʳҰ֮ƻ��
���мα�����ɪ���ϡ�
�������£���ʱ�ɶޣ�
�Ǵ����������ɶϾ���
Խİ���䣬������档
����̸�磬����ɶ���
������ϡ����ȵ�Ϸɣ�
�������ѣ���֦������
ɽ����ߣ��������
�ܹ��²������¹��ġ� 
*/
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int third_blade(object me,object target,int extra,object weapon);
int perform(object me, object target)
{
        string msg;
        int extra,i;
        object weapon;
        extra = me->query_skill("shortsong-blade",1);
        if ( extra < 30) return notify_fail("��Ķ̸赶�����������죡\n");
        
        if (userp(me) && me->query_skill_mapped("force") != "qidaoforce")
                return notify_fail("�۶̸賤�Σ���Ҫ������ķ��ݵ���ͣ�\n"); 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
   ||      !me->is_fighting(target) )
                return notify_fail("�۶̸賤�Σ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon"); 
if (me->query("class")!="legend") {
        msg = HIY  "$Nʹ���̸赶���еģ۶̸賤�Σݣ�һ��������ʽ�����е�"+ weapon->name()+  HIY"�������$n"HIY"������һ������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
//      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_PERFORM,msg);
        msg = HIY  "�ڶ�����" NOR;
        me->add_temp("apply/damage",extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra);
        if (extra<150) {
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
        } 
        me->add_temp("apply/damage",extra*2);
        msg = HIY  "$N�������ɣ����ֻӳ���������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*2);
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
} 
        me->add_temp("apply/attack",extra*2);
        me->add_temp("apply/damage",extra*2);
        msg = HIY  "$Nʹ���̸赶���еģ۶̸賤�Σݣ�һ��������ʽ��\n���е�"+ weapon->name()+ HIY "�������$n"HIY"������һ������ʳ֥Ӣ������Ȫ�����ȹ�֦����������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "�ڶ������������£��λ�Ԫ���������������档��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra*2);            
        
        if (extra <150) {
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
        }
        
//              if(i=random(2))
//                      call_out("third_blade",i,me,target,extra,weapon);
//              else
        third_blade(me,target,extra,weapon);                            
        if (me->query_busy()<3) me->start_busy(3);
        return 1;
   
}
        
int third_blade(object me,object target,int extra,object weapon)
{
        string msg;
        int bonus, exp_bonus;
        
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me)) return 0;
        if(!present(weapon,me)||weapon->query("equipped")!="wielded")
                return 0;
        exp_bonus = me->query("combat_exp")/1000*extra/8000;
        if (me->query("mission_npc")) exp_bonus = exp_bonus/100;            
        me->add_temp("apply/damage",extra*6+exp_bonus);
                me->add_temp("apply/attack",extra*4);
        msg = HIY  "$N�������ɣ����ֻӳ�������������δ�ƣ�����ǧ��������ɽ��������" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra*6-exp_bonus);
                 me->add_temp("apply/attack",-extra*4);
        return 1;
} 
