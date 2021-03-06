 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i;
        string *style = ({
HIR "$N手中$w突发红光，急劈$n的$l！" NOR,
HIY "$N手中$w突发黄光，直取$n的$l！" NOR,
HIW "$N手中$w突发白光，径砍$n的$l！" NOR,
HIG "$N手中$w突发绿光，平削$n的$l！" NOR,
HIB "$A手中$W和$B手中的$V交织错合，泛出层层黑气，网向$n！" NOR,
});
        object ob,*obs;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［一片莲心］只能对战斗中的对手使用。\n");
        if(!pointerp(obs=me->query_team()) )
                return notify_fail("只有队伍才可以发动此式！\n");
// this loop just checking, make sure everyone use 莲心影现刀法
        for(i=0;i<sizeof(obs);i++)
        {
        if(!obs[i]) return notify_fail("你需要从新组合队伍。\n");
        if(environment(obs[i]) != environment(me)) return notify_fail("你队伍成员不全在你身边。\n");
        if(!obs[i]->query_skill("lianxin-blade")) return notify_fail("你队伍中有人不会莲心影现刀法。\n");
        if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("你的队伍中有人没有兵器！\n");
        if(ob->query("skill_type") != "blade") return notify_fail("你的队伍中有人没有用刀法！\n");
        if(obs[i]->query_skill_mapped("blade") != "lianxin-blade") return notify_fail("你的队伍中有人没有用莲心影现刀法！\n");
        }       
        if(sizeof(obs) !=2) return notify_fail("只有两个人的队伍才可以施展［一片莲心］！\n");
        message_vision( HIR "\n\n\n$N和$n的身行突然交织在一起，越转越快！\n" NOR,obs[0],obs[1]);
        obs[0]->kill_ob(target);
        obs[1]->kill_ob(target);
        for(i=0;i<sizeof(style)-1;i++)
        {
        msg = style[i];
   extra = obs[(i%2)]->query_skill("lianxin-blade");
        obs[(i%2)]->add_temp("apply/attack", extra);
        obs[(i%2)]->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(obs[(i%2)],target, TYPE_PERFORM,msg);
        obs[(i%2)]->add_temp("apply/attack", -extra);
        obs[(i%2)]->add_temp("apply/damage", -extra);
        }
        style[i] = replace_string(style[i],"$A", obs[0]->name());
        style[i] = replace_string(style[i],"$B", obs[1]->name());
        style[i] = replace_string(style[i],"$W", (obs[0]->query_temp("weapon"))->name());
        style[i] = replace_string(style[i],"$V", (obs[1]->query_temp("weapon"))->name());
        extra = obs[0]->query_skill("blade");
        extra += obs[1]->query_skill("blade");
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,style[i]);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        obs[0]->start_busy(3);
        obs[1]->start_busy(3);
        return 1;
}       
