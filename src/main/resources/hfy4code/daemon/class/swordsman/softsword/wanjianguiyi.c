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
                return notify_fail("���򽣹�һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
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
        
        if (me->query_skill("softsword",1) < 220) return notify_fail("��ģ����ϸ�����ὣ�ݻ�����������\n");
        
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
                msg = HIW  "$N�����������һʽ��ҽ���������ʽ����ת�ۼ����е�"+ weapon->name()+ HIW"б�ɣ���ʮ�ְԵ�а������ʽ������ȴ�γ�һƬ����Ľ�Ļ��\n\n��������֮���ƺ���ǧ���ֽ�ʽ��Ӱ�ӣ���â���²�����������\n\nͻȻ����Ļ����һ������ֱ��$n��ֻ��ǧ�ٽ�����һ�����ԣ����Ǽ�򵥵���һ��������" NOR;
        }
        else    {
        //      260+random(260)
        extra=me->query_skill("softsword",1);
        damage=extra/100*random(skill*n)/100;       
      if (me->query("class")=="swordsman") {
      	      	target->set("resistance/kee",0);     	
      	}else {damage = damage/100;}
        msg = HIW "$N���е�"+ weapon->name() + HIW"����һָ��������һ�㣬�ƺ������ɽ����в����У�ȴ����ɽׯ��һ�о�����򽣹�һ�ݣ�\n\nֻ�����콣�����ݺύ����ǧ���н�Ӱ�ķ����ѵش���$n��" NOR;
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