 //========================��������====================================
//->Multi-perform , level dependent, high damage, high hit rate, 
//-> with special effects repends on enabled cursism.
//->The purpose of this perform is to give DWG a strong skill to 
//-> compete with other menpai.
// The purpose of this i look if to make higher attack and and
// damage when you can perform more.
// the last perform is always better than the previous one.
// if the above setting is too strong can use the next one. don't delete 
// "i" factor
// --------   neon 
// Dwg should never have high physical damage, thus damage is out of the question.
// this pfm is to utilize curse power, instead of having any physical damage 
// therefore, increase celepower but REMOVE physical damage. ---- silencer   
#include <ansi.h>
#include <combat.h>
inherit SSERVER;  
int perform(object me, object target)
{
    string msg;
    int extra, celepower, i, skill,whippower, myexp, enemyexp,total;
    int exp_bonus,damage,damage1;
    object weapon;
    string *perform_msg = ({
        HIW "�����ڿ�"NOR WHT" �� $N����$W��׺�������գ�����$n��\n"NOR,
        HIW "������ң"NOR WHT" �� $N��Ʈҡ��$W����õ���Ӱ�ж��������ػ�����$n��\n"NOR,
        HIW "Я�׳���"NOR WHT" �� $N����$W����һ����������$n��\n"NOR,
        HIW "���߳���"NOR WHT" �� �����ѿ����ı�������$W"NOR+WHT"����������ķ���������$n��\n"NOR,
        HIW "��������"NOR WHT" �� $W"WHT"������������$n"NOR+WHT"�ζ�����ʱ�仯��һ����꣬����$n��\n"NOR,
        HIW "��ͼ����"NOR WHT" �� $N����$W"WHT"��ת���飬�ڿ��лó�һ��������׭��ӡ��$n��\n"NOR,
        HIC "���н�������ǿ��Ϣ"NOR WHT" �� $N������������ʱ���˺�һ��$W"NOR+WHT"ƽƽ����һ�Ӷ�����ȴ�޿ɵֵ���\n"NOR,
        YEL "���������Ժ������"NOR WHT" �� $Nһ������$W"WHT"��һ������ʵ���͵��ھ���������Χ��$n��\n"NOR,
        HIG "�����Ȼ"NOR WHT" �� $N���޲�������Ȼ���лó��ڶ����飬��������չʾ�ڲ�ã��ؼ䡣\n"WHT
        "$n���ɵ���������Ȼ���Ķ����ΰ��\n"NOR}); 
    if (me->query("class") != "yinshi") 
        return notify_fail("ֻ�е����ȵ��ӿ���ʹ��"WHT"���������֣�"NOR"��\n"); 
    weapon = me->query_temp("weapon");
    skill = me->query_skill("thunderwhip",1);   
    if( skill < 30) return notify_fail("��������ƻ�����������\n"); 
    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail(WHT"���������֣�"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
    celepower = me->query_skill("cursism"); 
    
    exp_bonus = (me->query("combat_exp")-3000000)/6000000*celepower;
    if (exp_bonus<0) exp_bonus=0;
    if (exp_bonus>celepower) exp_bonus=celepower;
    
    damage = celepower+exp_bonus;
    
    myexp = me->query("combat_exp");
    enemyexp = target->query("combat_exp");
        message_vision(WHT"$N�ı޷�һ�䣬��ʽչ�������ܲ���Ũ�ƣ��꽫��δ�䣬������δ��\n"HIC"ʹ���������Ƶ��ռ�ɱʽ  ��  ���������֣ݣ���\n\n"NOR, me);
        for(i=0;i<9;i++)
        {
                msg = perform_msg[i];
                msg = replace_string(msg,"$W", weapon->name()+WHT);
                if (skill >= i * 20+10) {
                        if (i>6 && userp(me)&& (!me->query("marks/hammerwhip") || me->query_skill("whip")<355)) {
                                me->start_busy(2+i/2);
                                if (!random(1 + 8*i -i*i) && i!=8 ) 
                                        tell_object(me, YEL"\n����ñ޷��ƺ�����Ƿ��Ȼ������һ���ǳɡ�\n"NOR);
                                return 1;       
                        }
                        message_vision("\n"+msg,me,target);
                        if (random(myexp)/150*celepower*(i/2+1)> enemyexp) {
                                message_vision("\n"MAG+weapon->name()+MAG"����һ˿˿���ĵ��Ϲ⣬����$n"NOR+MAG"����... ...\n"NOR, me, target);
                                damage1 = damage+ random(damage)*3/2;
//                              total= damage1+total;
//                              message_vision(HIW"\t\tdamage is "+(string)(total)+" .\n"NOR,me);
                                target->receive_damage("gin", damage1,me);
                                target->receive_wound("gin",10 + random(celepower),me);
                                COMBAT_D->report_status(target);
                                COMBAT_D->win_lose_check(me,target,1);
                        if (i==8)       {
                                        message_vision(HIG"$N"+HIG"�������ƣ������������Ϊһ�壬������и�ɻ���\n"NOR, me);
                                        me->start_busy(5);
                                        if ( target->is_busy()) target->start_busy(target->query_busy()+2);
                                           if ( !target->is_busy() ) target->start_busy(2);
                                        return 1;                       
                                        }       
                        } else 
                                message_vision(HIG"$N��������������$n�ı�Ӱ��\n\n"NOR,target,me);
                                                        
                }
        }
                i= (skill-10)/20-1;
                me->start_busy(2+i/2);
                return 1;       
                
} 
/* 
int perform(object me, object target)
{
    string msg;
    int extra, celepower, i, skill,whippower, myexp, enemyexp;
    object weapon;
    string *perform_msg = ({
        HIW "�����ڿ�"NOR WHT" �� $N����$W��׺�������գ�����$n��\n"NOR,
        HIW "������ң"NOR WHT" �� $N��Ʈҡ��$W����õ���Ӱ�ж��������ػ�����$n��\n"NOR,
        HIW "Я�׳���"NOR WHT" �� $N����$W����һ����������$n��\n"NOR,
        HIW "���߳���"NOR WHT" �� �����ѿ����ı�������$W����������ķ���������$n\n"NOR,
        HIW "��������"NOR WHT" �� $W"WHT"������������$n�ζ�����ʱ�仯��һ����꣬����$n��\n"NOR,
        HIW "��ͼ����"NOR WHT" �� $N����$W"WHT"��ת���飬�ڿ��лó�һ��������׭��ӡ��$n��\n"NOR,
        HIC "���н�������ǿ��Ϣ"NOR WHT" �� $N������������ʱ���˺�һ��$Wƽƽ����һ�Ӷ�����ȴ�޿ɵֵ���\n"NOR,
        YEL "���������Ժ������"NOR WHT" �� $Nһ������$W"WHT"��һ������ʵ���͵��ھ���������Χ��$n��\n"NOR,
        HIG "�����Ȼ"NOR WHT" �� $N���޲�������Ȼ���лó��ڶ����飬��������չʾ�ڲ�ã��ؼ䡣\n"WHT
        "$n���ɵ���������Ȼ���Ķ����ΰ��"NOR}); 
    if (me->query("class") != "yinshi") return notify_fail("ֻ�е����ȵ��ӿ���ʹ��"WHT"���������֣�"NOR"��\n"); 
    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail(WHT"���������֣�"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    weapon = me->query_temp("weapon");
    extra = me->query_skill("thunderwhip");
    skill = me->query_skill("thunderwhip",1);   
    if( skill < 35) return notify_fail("��������ƻ�����������\n");
    
    celepower = me->query_skill("cursism"); //Get enabled level of cursism
    
    myexp = me->query("combat_exp");
    enemyexp = target->query("combat_exp");
    whippower = 0;
        message_vision(WHT"$N�ı޷�һ�䣬��ʽչ�������ܲ���Ũ�ƣ��꽫��δ�䣬������δ��\n"HIC"ʹ���������Ƶ��ռ�ɱʽ  ��  ���������֣ݣ���\n\n"NOR, me);
        for(i=0;i<9;i++)
        {
//              whippower = extra/3 + (i*random(skill))/4;  // neon - new formular
                msg = perform_msg[i];
                msg = replace_string(msg,"$W", weapon->name()+WHT);
                if (skill >= i * 25 + 10) {
                //      me->add_temp("apply/attack", whippower/5);      
                //      me->add_temp("apply/damage", +whippower);  //neon - change from /3 to /4 
                //      COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                      message_vision(msg,me,target);
                //      me->add_temp("apply/attack", -whippower/5);
                //      me->add_temp("apply/damage", -whippower);
                        if (celepower*(i/2+1)*random(myexp)/150 > enemyexp) {
                                message_vision(MAG+weapon->name()+MAG"����һ˿˿���ĵ��Ϲ⣬����$n����... ...\n\n"NOR, me, target);
                                target->receive_damage("gin", celepower+ random(celepower)*3/2,me);
                                target->receive_wound("gin",10 + random(celepower),me);
//                              COMBAT_D->report_status(target);
                        } else {
                                message_vision(HIG"$N��������������$n�ı�Ӱ��\n\n"NOR,target,me);
                                }                       
                }
                else {
                        me->start_busy(2+i/2);
                        if (!random(1 + 8*i -i*i) && i!=8 ) tell_object(me, YEL"\n����ñ޷��ƺ�����Ƿ��Ȼ������һ���ǳɡ�\n"NOR);
                        return 1;       
                }
        }
    message_vision(HIG"$N�������ƣ������������Ϊһ�壬������и�ɻ���\n"NOR, me);
    me->start_busy(5);
    if ( !target->is_busy() ) target->start_busy(3);
    return 1;
}
*/
