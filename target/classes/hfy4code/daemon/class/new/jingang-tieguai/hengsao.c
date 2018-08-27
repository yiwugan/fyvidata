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
    
    if ((me->query_skill("sword") > 1) ||	 (me->query_skill("blade") > 1) || 	 (me->query_skill("dagger") > 1)  )
    	 return notify_fail("金刚铁拐武功招式有别于传统刀剑短刃，你一时之间似乎忘记了该如何使用！\n");
    
    extra = me->query_skill("jingang-tieguai",1);
    if ( extra < 100)
        return notify_fail("你的金刚铁拐还不够纯熟！\n");
        
    enemy=me->query_enemy();
    if(!sizeof(enemy))
                return notify_fail("［横扫千军］只能对战斗中的对手使用。\n"); 
    
    
                  
    if(target)  return notify_fail("［横扫千军］不需要指定使用对象！！\n");
    if( !target ) target = offensive_target(me);

    
    if (me->query_skill("force",1) > 300)
         extra*=3;
        else extra*=2;
        
        if ( me->query_temp("speedup")) extra*=2;
        if ( me->query_skill("spear")) extra/=3;
       
        
        
    weapon = me->query_temp("weapon");
    if(extra <= 300)
    {
        damages = extra/4;
       if (target->query("SUPERER")==1 ) damages = 0;
        
        msg = HIC"\n$N"+HIC"深深吸了一口气，手中的"+ weapon->name()+
            HIC"犹如狂魔乱舞般卷向$n! " NOR;
        message_vision(msg,me,enemy[0]);
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/damage",damages*2);
    }
    else
    {
       if ((me->query_skill("hammer",1) > 220) ||	 (me->query_skill("axe",1) > 200) || 	 (me->query_skill("staff",1) > 220) ||   (me->query_skill("spear",1) > 300) ||  (me->query_skill("fork",1) > 180) )
		            damages = extra*3/2;
                else {damages = extra/5;}
         if (me->query("class")=="yinshi")  damages = damages *3/2;
         	     if (me->query("class")=="knight")  damages = damages *2/3;
      if ((me->query_skill("hammer") > 1) ||	 (me->query_skill("axe") > 1) || 	 (me->query_skill("staff") > 1) ||   (me->query_skill("spear") > 1)  )          
      	   damages = damages/2;
      	   else {damages = damages*2;}
    
       
          
        msg = HIC"\n$N"+HIC"双奋力一举"NOR+ weapon->name()+ HIC"以力劈华山之势罩向$n"+HIC"身前身后的破绽。面对突如其来的杀着，$n"+ HIC"一时间进退不得！" NOR;
        message_vision(msg,me,enemy[0]);
        
        if (target->query("SUPERER")==1 ) damages = 0;
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/damage",damages*2);
    }
      lmt = random(5)+3;
      
        if (extra <= 400 && lmt > 5) lmt= 5;      
        if (extra <= 300 && lmt > 4) lmt= 4;
        if (extra <= 200 && lmt > 3) lmt= 3;
        	
        		
        		         
         
    j=0;
    for(i=1;i<=lmt;i++)
    {
        msg =  HIW "横扫千军！！！"NOR+ weapon->name()+ HIW"犹如雷霆霹雳般连环砸下！！！" NOR;
        COMBAT_D->do_attack(me,enemy[j],TYPE_PERFORM,msg);
        if (j==sizeof(enemy)-1) j=0;
                        else j++;
    }
    me->add_temp("apply/attack",-damages*3/2);
    me->add_temp("apply/damage",-damages*2);
   
    if (me->query_busy()<3) 
                me->start_busy(3);
   
    return 1;
}  
int target_perform(object me, object target)
{
    string msg;
    int extra,i,j,lmt,damages,bell;
    object weapon;
    object *enemy;

        
    extra = me->query_skill("jingang-tieguai",1);
    weapon = me->query_temp("weapon");
    if(extra <= 300)
    {
                damages = extra/4;
                if (target->query("SUPERER")==1 ) {damages = 0;}
         msg = HIC"\n$N"+HIC"深深吸了一口气，手中的"+ weapon->name()+
            HIC"犹如狂魔乱舞般向$n"+HIC"扑面而至! " NOR;
        message_vision(msg,me,target);
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/damage",damages*2);
    }
    else
    {
     if ((me->query_skill("hammer",1) > 220) ||	 (me->query_skill("axe",1) > 200) || 	 (me->query_skill("staff",1) > 220) ||   (me->query_skill("spear",1) > 300) ||  (me->query_skill("fork",1) > 180) )
		            damages = extra*3/2;
                else {damages = extra/5;}
         if (me->query("class")=="yinshi")  damages = damages *3/2;
         	     if (me->query("class")=="knight")  damages = damages *2/3;
              if ((me->query_skill("hammer") > 1) ||	 (me->query_skill("axe") > 1) || 	 (me->query_skill("staff") > 1) ||   (me->query_skill("spear") > 1)  )          
      	   damages = damages/2;
      	   else {damages = damages*2;}         	     	
        
        
        msg = HIC"\n$N"+HIC"双奋力一举"NOR+ weapon->name()+ HIC"以力劈华山之势罩向$n"+HIC"身前身后的破绽。面对突如其来的杀着，$n"+ HIC"一时间进退不得！" NOR;
        message_vision(msg,me,target);
        
      if (target->query("SUPERER")==1 ) {damages = 0;}
        
        me->add_temp("apply/attack",damages*3/2);
        me->add_temp("apply/damage",damages*2);
    }
 lmt = random(5)+3;
        if (extra <= 220 && lmt > 1) lmt= 1;
        	if (extra <= 300 && lmt > 2) lmt= 2;
        		if (extra <= 400 && lmt > 3) lmt= 3;
         
    for(i=1;i<=lmt;i++)
    {
         msg =  HIW "横扫千军！！！"NOR+ weapon->name()+ HIW"犹如雷霆霹雳般连环砸下！！！" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);  
    }
    
    me->add_temp("apply/attack",-damages*3/2);
    me->add_temp("apply/damage",-damages*2);
   
    if (me->query_busy()<4) 
                me->start_busy(4);
    return 1;
} 
