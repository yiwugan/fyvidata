 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object friend)
{
        string msg;
        int extra,i,j,k;
        string *style = ({
HIR "$N����$wͻ����⣬����$n��$l��" NOR,
HIY "$N����$wͻ���ƹ⣬ֱȡ$n��$l��" NOR,
HIW "$N����$wͻ���׹⣬����$n��$l��" NOR,
HIG "$N����$wͻ���̹⣬ƽ��$n��$l��" NOR,
HIB "$A����$W��$B���е�$V��֯��ϣ�����������������$n��" NOR,
});
        object ob,*obs, target;
        object you, *myteam;
        
        if (!friend)
                return notify_fail ("��Ҫ��˭һ��ʹ�ã�һƬ���ģݣ�\n");        
        if (friend==me)
                return notify_fail ("һƬ������Ҫ��ͬ��һ��ʹ�á�\n");
                        
        you=friend;                          
        myteam = me->query_team();
        for(j=0; j<sizeof(myteam); j++) {
                if (myteam[j]==you) 
                                {k=1; 
                                continue;
                                }
                }               
        if (k!=1)
                return notify_fail("ͬ�������������ͬһ�������С�\n");  
        
        if(!you->query_skill("lianxin-blade",1) || you->query_skill_mapped("blade") != "lianxin-blade") 
                return notify_fail("ͬ��û����ϵ��书��\n");
        if(!objectp(ob=you->query_temp("weapon"))) 
                return notify_fail("ͬ��û��ִ����\n");
        if(ob->query("skill_type") != "blade")
                return notify_fail("ͬ��û��ִ����\n");
   if (you->is_busy())
                return notify_fail("ͬ����æ���ء�\n");
                        
        target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��һƬ���ģ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        
        message_vision( HIR "\n\n\n$N��$n������ͻȻ��֯��һ��ԽתԽ�죡\n" NOR,me,you);
        me->kill_ob(target);
        you->kill_ob(target); 
        msg = style[0];
        extra = me->query_skill("lianxin-blade");
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        
        msg = style[1];
        extra = you->query_skill("lianxin-blade");
        you->add_temp("apply/attack", extra);
        you->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(you,target, TYPE_PERFORM,msg);
        you->add_temp("apply/attack", -extra);
        you->add_temp("apply/damage", -extra);
        
        msg = style[2];
        extra = me->query_skill("lianxin-blade");
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        
        msg = style[3];
        extra = you->query_skill("lianxin-blade");
        you->add_temp("apply/attack", extra);
        you->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(you,target, TYPE_PERFORM,msg);
        you->add_temp("apply/attack", -extra);
        you->add_temp("apply/damage", -extra); 
        style[4] = replace_string(style[i],"$A", me->name());
        style[4] = replace_string(style[i],"$B", you->name());
        style[4] = replace_string(style[i],"$W", (me->query_temp("weapon"))->name());
        style[4] = replace_string(style[i],"$V", (you->query_temp("weapon"))->name());
        extra = me->query_skill("blade");
        extra += you->query_skill("blade");
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,style[4]);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(3);
        you->start_busy(3);
        return 1;
}  
