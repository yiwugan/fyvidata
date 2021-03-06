#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int begin_perform(object me,object target,int count,int tmp,int extra,object weapon);
int perform(object me, object target)
{
        string forceskill,msg;
        int extra, exp_bonus;
        int tmp,skill;
        object weapon;
        
        weapon=me->query_temp("weapon");
        extra = me->query_skill("feiyun-spear",1);
        tmp = me->query_skill("yue-spear",1);
        skill = me->query_skill("spear",1);
        tmp = extra * tmp * skill;
        if (!me->query("marks/官府/岳飞")) return notify_fail("你没有得到岳飞的指点，使唤不了飞云枪法。\n");

        
        if ( extra < 150) 
                return notify_fail("你的飞云枪法还不够纯熟！\n");
        
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『清河落』只能对战斗中的对手使用。\n");
        
                
        exp_bonus = me->query("combat_exp")/1000*extra/2000;    
        if (exp_bonus>extra*4) exp_bonus=extra*4;
     
                        
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra/2);  
        msg = HIW "\n$N沉吟道『都人层立似山丘』手中$w"+HIW"使出一招『－清－河－落－』！"NOR+HIC"\n\n坐啸将军拥棹游\n$N手中$w"HIC"直指长空，陡然直刺$n!" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIY  "儒将不须夸郄縠\n$N怒喝一声，千重矛影惊涛骇浪般直刺$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIB  "未闻诗句解风流\n$N握枪之手移至中间，枪头枪尾有若两道急电点向$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
		me->add_temp("apply/damage",extra);  
    msg = HIG  "绕郭烟波浮泗水\n$N手中$w"+HIG"如狂风落叶，无处不在，漫天枪影中一点红光直刺$n！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/damage",-extra); 
    msg = HIM  "一船丝竹载凉州\n$w"+HIM"虎虎生风，咝咝作响，仿佛万马奔腾！" NOR;
       COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);        
    msg = HIC  "城中睹望皆丹雘\n$N手中$w"+HIC"枪头颤震，倏得爆开，变成满天血光！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "旗里惊飞尽白鸥\n四周一切突复宁静，$N手中$w"+HIW"枪影消失。" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra/2); 
           
        if (me->query_busy()<6) me->start_busy(6);   
        return 1;
}       
