 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, skill, armor,damage,x,n,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
        object weapon;
        
        if( !target ) target = offensive_target(me); 
        if( !target
                ||      !target->is_character()
                ||      !me->is_fighting(target) )
                return notify_fail("［万剑归一］只能对战斗中的对手使用。\n");
        
        weapon = me->query_temp("weapon");
        armor = target->query("resistance/kee");        
        skill=me->query_skill("sword",1);
        n1=me->query_skill("13-sword",1);
        n2=me->query_skill("diesword",1);
        n3=me->query_skill("six-chaos-sword",1);
        n4=me->query_skill("three-sword",1);
        n5=me->query_skill("taiji-sword",1);
        n6=me->query_skill("huanhua-sword",1);
        n7=me->query_skill("suiyuan-sword",1);
        n8=me->query_skill("doomsword",1);
        n9=me->query_skill("springrain-sword",1);
        n10=me->query_skill("qisha-sword",1);
        
        if (me->query_skill("softsword",1) < 220) return notify_fail("你的［清风细雨温柔剑］还不够熟练。\n");
        
        n= n1 + n2 +n3 +n4 +n5 +n6 +n7 +n8 +n9 +n10;
      if (n9 =0 ||n6 =0 || n10=0 ||n8=0) {x =1;}else {x=3;}
      	if (n3 >150) x= x*3;
        	
        if(skill > 300 && userp(me)) {
        //      130+random(130)
                extra = skill*n/100 + random(skill*n)/100;
                damage = extra/10;
                      if (me->query("class")=="swordsman") {
                      	target->set("resistance/kee",0);     	
                      	}else {damage = damage/100;}
                msg = HIW  "$N剑尖上扬，似是一式佛家剑法的起手式，但转眼间手中的"+ weapon->name()+ HIW"斜飞，又十分霸道邪气，两式连贯下却形成一片温柔的剑幕。\n\n若隐若现之间似乎有千百种剑式的影子，剑芒吞吐不定————\n\n突然，剑幕中心一点亮光直逼$n，只见千百剑化成一剑！对，就是简简单单的一剑！！！" NOR;
        }
        else    {
        //      260+random(260)
        extra=me->query_skill("softsword",1);
        damage=extra/100*random(skill*n)/100;       
      if (me->query("class")=="swordsman") {
      	      	target->set("resistance/kee",0);     	
      	}else {damage = damage/100;}
        msg = HIW "$N手中的"+ weapon->name() + HIW"往左一指，再向下一点，似乎剑不成剑，招不成招，却是神剑山庄的一招精髓［万剑归一］！\n\n只见漫天剑气，纵横交错，千百招剑影四分五裂地刺向$n！" NOR;
        }
        
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", damage*x);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -damage*x);
        if (me->query("class")=="swordsman")target->set("resistance/kee",armor); 
        
        if (me->query_busy()<2) {
                me->start_busy(2);
           }
                
        return 1;
}      
