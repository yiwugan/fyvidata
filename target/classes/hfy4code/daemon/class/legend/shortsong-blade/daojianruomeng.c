 //mimicat@fy4
// - rewriten by neon 06-09-2002
// - new daojianruomeng 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int single_perform(object target, object me, object blade, object sword);
int team_perform(object target, object me, object you);
int perform(object me, object target)
{
        int mylevel;
        string msg,yourname,myname,targetname;
        int skl_me, skl_you, extra_me, extra_you,j,k, solo = 0;
        object you, ob,*myteam, *mystuff, sword, blade; 
        if (!target) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۵������Σ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if(me->query("gender")!="����")
                return notify_fail("�̸赶���ģ۵������Σݱ��������ӷ�����\n");
            
        mylevel=me->query_skill("shortsong-blade",1);
        
        myteam = me->query_team();
        k = 0;
        if( !pointerp(myteam)) solo = 1 ;
        else {
                for (j = 0; j< sizeof(myteam); j++) {
                        if (environment(myteam[j]) == environment(me)) {
                                if( myteam[j] != me ) you = myteam[j];
                                k++;
                        }
                }
                if (k == 1) solo = 1;
                else if (k == 2) solo = 0;
                else 
                        return notify_fail("�۵������Σ���Ҫ����������ӡ�������е��������Աߣ������ͷ��Ӳ�������\n"); 
        }
        
        
        /*Single player perform*/
        if (solo) 
                return notify_fail("�̸赶���ģ۵������Σ���Ҫ���˲��ܷ�����\n");
        /*Team perform*/
        else { 
                return team_perform(target, me, you);
        }
        
} 
int team_perform(object target, object me, object you)
{
        object blade, sword;
        int skl_me, skl_you, extra_me, extra_you,j,k, bonus;
        string msg,yourname,myname,targetname; 
        if(me->query("gender")!="����"|| you->query("gender")!="Ů��")  
                return notify_fail("����һ��һŮ���ܹ�ʹ�����������\n"); 
        if(me->query_skill("shortsong-blade",1)<30)
                return notify_fail("��Ķ̸赶�����𲻹���\n");
        if(!you->query_skill("diesword",1) || you->query_skill_mapped("sword") != "diesword") 
                return notify_fail("ͬ��û����ϵ��书��\n");
        if(you->query_skill("diesword",1)<30)
                return notify_fail("ͬ���书���𲻹���\n");
        if(!objectp(sword=you->query_temp("weapon"))) 
                return notify_fail("ͬ��û�б�����\n");
        if(sword->query("skill_type") != "sword")
                return notify_fail("ͬ��������಻�ԡ�\n");
        if(you == target )
                return notify_fail(MAG"����ô�ݵ�������ģ�\n"NOR);
        if(you->query("class")!="legend" && me->query("class")!="legend")
                return notify_fail("������һ���˱�������ѩ���Ӳ����ã۵������Σݡ�\n");
        if (you->is_busy())
                return notify_fail("ͬ����æ�ţ�û������һ��ʩչ�۵������Σݡ�\n"); 
                    
        // Now determine the bonus for same menpai and couple
        bonus = 0;
        if (you->query("class") == "legend" && me->query("class") == "legend" )  bonus++;
        if (you->query("marry") == me->query("id") && you->query("id") == me->query("marry"))  {
                bonus++;
                message_vision(HIG"\n$N��$n��Ŀ����һ�ۣ���Ȼ���������������ͷ������������������λð�ӳ�������\n\n"NOR,me,you);              
   }
        
        
        skl_me=(int)me->query_skill("shortsong-blade",1);
        extra_me=(int)me->query_skill("shortsong-blade",1);        
        skl_you=(int)you->query_skill("diesword",1);
        extra_you= (int)you->query_skill("diesword",1);
        
        skl_me=(skl_me+skl_you)/4 *(2+ bonus)/4;
        extra_me=(extra_me+extra_you)/2 * (1+bonus)/2;
        
//        message_vision((string)(bonus)+" "+(string)(skl_me)+" "+(string)(extra_me)+".\n",me);
        
        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        you->add_temp("apply/attack",skl_me);
        you->add_temp("apply/damage",extra_me);
 
        you->kill_ob(target);
        target->kill_ob(you);
        
        myname=me->name();
        yourname=you->name();
        targetname=target->name();
        blade=me->query_temp("weapon"); 
                msg=HIY"\n$N��$n�����ϱڣ�ʹ����һʽ���������Ρ���˿˿��ۣ���ˮ��©����"+targetname+HIY"նȥ�� \n\n";
                msg+=HIC"����ǣţ�ǣ���Ӻ�Ů��\n"NOR;
                msg+=HIY"$N���е�"+sword->name()+HIY"��תǧ�أ���ò�����"+targetname+HIY"��ǰһ����$n���е�"
                +blade->name()+HIY"����ɱ����ǰ�� "NOR;
                message_vision(msg,you,me);
                COMBAT_D->do_attack(me,target, TYPE_REGULAR," "); 
                msg=CYN"\n����ߪ���֣�����Ū���̡�\n";
                msg+="$N���л�����ǰ�����־���һ���� \n"NOR;
                COMBAT_D->do_attack(you,target,TYPE_REGULAR,msg); 
                msg=HIW"\n\n���ղ����£����������ꡣ\n";
                msg+="$n���е�"+blade->name()+HIW"��ס��Σ�$N�˻�����һƬ��Ӱ����"+targetname+HIW"ȫ���������С�" NOR;
                message_vision(msg,you,me);
                COMBAT_D->do_attack(you,target,TYPE_REGULAR," "); 
                msg=MAG"\n\n�Ӻ�����ǳ����ȥ������\n";
                msg+="$n������§$N������������"+blade->name()+MAG"бб�ӳ���ֱȡ"+targetname+MAG"��Ҫ���� "NOR;
           message_vision(msg,you,me);
                COMBAT_D->do_attack(me,target, TYPE_REGULAR," "); 
                msg=HIG"\n\nӯӯһˮ�䣬���������\n";
                msg+="$n��$N������ͨ��һ��һ������������е����£����϶�Ϊһ��ֱ��"+targetname+HIG"��ȥ��"NOR;
                message_vision(msg,you,me);
                me->add_temp("apply/attack",extra_me/4*bonus);
                you->add_temp("apply/attack",extra_me/4*bonus);
                me->add_temp("apply/damage",extra_me);
                you->add_temp("apply/damage",extra_me);
                COMBAT_D->do_attack(me,target, TYPE_REGULAR," ");
                COMBAT_D->do_attack(you,target,TYPE_REGULAR," ");
                me->add_temp("apply/attack",-extra_me/4*bonus);
                you->add_temp("apply/attack",-extra_me/4*bonus);
                me->add_temp("apply/damage",-extra_me);
                you->add_temp("apply/damage",-extra_me); 
        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
        you->add_temp("apply/attack",-skl_me);
        you->add_temp("apply/damage",-extra_me);
        if (me->query_busy()<3) me->start_busy(3);
        if (you->query_busy()<3) you->start_busy(3);
        return 1;
}       
