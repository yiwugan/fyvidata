#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra, blade,myexp,tarexp;
//        if (me->query("class")!="emei")
//                return notify_fail ("ֻ�ж��ҵ��Ӳ���ʹ�ã۵���˫ɱ�ݡ�\n");
        extra = me->query_skill("sky-sword",1);
        blade = me->query_skill("shenji-blade",1);
//                if (me->query("class")=="emei") extra*=3;
        if ( extra < 150) 
                return notify_fail("��ģ����콣���ݻ��������죡\n");
        if ( blade < 150) 
                return notify_fail("��ģ���������ݻ��������죡\n");
        dodskill = (string) me->query_skill_mapped("sword");
        if ( dodskill != "sky-sword")
                return notify_fail("�۵���˫ɱ����Ҫ������������콣������ϣ�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۵���˫ɱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
	if (me->query("class")=="emei") blade*=2;
        if (me->query("class")!="emei") blade/=2;
        if (me->query("class")=="emei") extra*=3;
        myexp=(int)me->query("combat_exp");
        tarexp=(int)target->query("combat_exp");
        msg = HIR"$N���е������裬ͻȻʹ��һ�С�����˫ɱ����\n"+NOR;
        if(random((extra+blade)/50)*myexp + random(myexp/2) >= tarexp*2/3)
        {
//        	me->add_temp("apply/attack",blade*4);
//        	me->add_temp("apply/damage",extra*4);     
        	message_vision(msg+"\n",me,target);
        	if( target->is_busy() ){       //����Է���busy����ô����Ҫbusy�Է���
        		me->add_temp("apply/damage",extra*4);
        		me->add_temp("apply/attack",blade*4);
        		message_vision( BLU " ɭɭɱ��ͻȻ��$N������"NOR+HIC"��"+HIB"��"+HIM"��"+HIW"��"+NOR"��"+CYN"��"+GRN"��"+MAG"��"+RED"��"+HIY"��" NOR,target);
        		msg= HIC"һ˲�䣬���⽣Ӱ���಻�ϡ�"NOR;
        		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        		target->receive_wound("sen",extra*3/2);
        		me->add_temp("apply/damage",-extra*4);    
        		me->add_temp("apply/attack",-blade*4);
        	}else{
        		me->add_temp("apply/damage",extra*3);
        		me->add_temp("apply/attack",blade*4);
        		message_vision( BLU " $Nֻ����ǰ������ò��ϣ�һ���Ӳ�֪���룡\n"+NOR"��ΧͻȻɱ�����أ�"+HIC"��"+HIB"��"+HIM"��"+HIW"��"+NOR"��"+CYN"��"+GRN"��"+MAG"��"+RED"��"+HIY"��" NOR,target);
        		msg=HIC"һ˲�䣬���⽣Ӱ���಻�ϡ�"NOR;
        		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        		target->receive_wound("sen",extra*3/2);
        		me->add_temp("apply/damage",-extra*3);    
        		me->add_temp("apply/attack",-blade*4);
        		target->start_busy(2);
        	}
        }else{
           msg= HIR  "$N���е������裬ͻȻʹ��һ�С�����˫ɱ����\n\n"+NOR"��ΧͻȻɱ��ɱ�����أ�"+HIC"��"+HIB"��"+HIM"��"+HIW"��"+NOR"��"+CYN"��"+GRN"��"+MAG"��"+RED"��"+HIY"��" NOR;
           COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        me->start_busy(2);
        target->set_temp("last_damage_from",me);
        return 1;
}     
