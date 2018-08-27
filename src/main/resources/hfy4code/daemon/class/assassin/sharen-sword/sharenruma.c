#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int target_perform(object me, object target); 
int perform(object me, object target)
{
    string msg;
    int extra,i,j,lmt,damages,bell;
    object weapon;
    object *enemy;
    
    extra = me->query_skill("sharen-sword",1);
    if ( extra < 100)
        return notify_fail("���ɱ�˽������������죡\n");
        
    enemy=me->query_enemy();
    if(!sizeof(enemy))
                return notify_fail("��ɱ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
    if (me->query("bellicosity")<=500 && userp(me))
                return notify_fail("���ɱ�������ߡ�\n");    
    
    if (target && me->query_temp("jingxing/concentrate")) {
        if( !target->is_character()
                || !me->is_fighting(target) )
                return notify_fail("��ɱ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");   
///     message_vision(" aaa.\n",me);
        target_perform(me,target);
        return 1;
    }
                
    if(target)  return notify_fail("��ɱ������ݲ���Ҫָ��ʹ�ö��󣡣�\n");
    
    if (me->query_temp("timer/sharen")+20>time() && userp(me) 
                && ! me->query_temp("jingxing/concentrate"))
                return notify_fail("���ɱ�������һ��ʱ��������¾ۼ�����\n");
    if (me->query_temp("jingxing/concentrate"))
         extra*=3;
        else extra*=2;
        if (me->query("class") == "assassin" ) extra = extra*3/2;
        	else extra = extra/10;
    weapon = me->query_temp("weapon");
    if(extra <= 300)
    {
        damages = extra/4;
        msg = HIY"$N"+HIY"���Դ󷢣����е�"+ weapon->name()+
            HIY"��籩������$n"+HIY"����! " NOR;
        message_vision(msg,me,enemy[0]);
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/damage",damages*2);
    }
    else
    {
        if (me->query("class")=="assassin") damages = extra*2/3;
                else {damages = extra/4;}
        
        msg = HIY"$N"+HIY"ɱ����ʢ��ֻ��"NOR+ weapon->name()+
            HIY"������������$n"+HIY"ȫ������ҪѨ�̵�! " NOR;
        message_vision(msg,me,enemy[0]);
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/damage",damages*2);
    }
    lmt = random(5)+3;
        if (extra>160 && lmt<5) lmt=5;
         
    j=0;
    for(i=1;i<=lmt;i++)
    {
        msg =  HIR "��"+chinese_number(i)+"����" NOR;
        COMBAT_D->do_attack(me,enemy[j],TYPE_PERFORM,msg);
        if (j==sizeof(enemy)-1) j=0;
                        else j++;
    }
    me->add_temp("apply/attack",-damages*3/2);
    me->add_temp("apply/damage",-damages*2);
    bell = lmt*5-5;
    if (userp(me)) me->add("bellicosity",-bell);
    if (me->query_busy()<3) 
                me->start_busy(3);
    me->set_temp("timer/sharen",time());
    return 1;
}  
int target_perform(object me, object target)
{
    string msg;
    int extra,i,j,lmt,damages,bell;
    object weapon;
    object *enemy;
            
    extra = me->query_skill("sharen-sword",1);
    weapon = me->query_temp("weapon");
    if(extra <= 300)
    {
        damages = extra/4;
        msg = HIY"$N"+HIY"���Դ󷢣����е�"+ weapon->name()+
            HIY"��籩������$n"+HIY"����! " NOR;
        message_vision(msg,me,target);
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/damage",damages*2);
    }
    else
    {
        if (me->query("class")=="assassin") damages = extra*2/3;
                else {damages = extra/4;}
        
        msg = HIY"$N"+HIY"ɱ����ʢ��ֻ��"NOR+ weapon->name()+
            HIY"������������$n"+HIY"ȫ������ҪѨ�̵�! " NOR;
        message_vision(msg,me,target);
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/damage",damages*2);
    }
    lmt = random(5)+3;
    if (extra>160 && lmt<5) lmt=5;
         
    for(i=1;i<=lmt;i++)
    {
        msg =  HIR "��"+chinese_number(i)+"����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);  
    }
    
    me->add_temp("apply/attack",-damages*3/2);
    me->add_temp("apply/damage",-damages*2);
    bell = lmt*5-5;
    if (userp(me)) me->add("bellicosity",-bell);
    if (userp(me)) me->add("bellicosity",-bell);
    if (me->query_busy()<4) 
                me->start_busy(4);
    return 1;
} 