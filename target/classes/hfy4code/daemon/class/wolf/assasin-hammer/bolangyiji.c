 //�۲���һ����
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int tobe_or_nottobe(object me,object target,int extra, object weapon);
int perform(object me, object target)
{
        string msg;
        int extra,i;
        object weapon;
        
        extra = me->query_skill("assasin-hammer",1);
        if(me->query("class")!="wolfmount")
                return notify_fail("ֻ����ɽ���Ӳ���ʹ�á�����һ������ɱ��\n");
        if ( extra < 100) 
                return notify_fail("��ģ۲�����ɱ�ݴ������������죡\n");
        if( !target || !target->is_character()) 
                return notify_fail(HIR"��Ҫ��ɱ˭��\n"NOR);
        if (target->query("combat_exp")*10<me->query("combat_exp"))
                return notify_fail("���˾���̫��������ش�ɱ\n");
        if(environment(me)->query("no_fight")) 
                return notify_fail("���ﲻ׼��ɱ����\n");
        if(me->is_busy())
                return notify_fail("������û�գ���\n"); 
        if( target==me) return notify_fail(HIR"�㲻����ˣ�\n"NOR);
                
        weapon=me->query_temp("weapon");
        
        if((int)me->query("bellicosity") > 100 
                ||(int)me->query("cps")< (int)target->query("cps")
                || me->query_skill("assasin-hammer",1)/2< target->query_skill("perception",1))
                tell_object(target, HIR"\n���Ȼ����һ��ɱ������ü�ޣ�ֱ�������㣬�����뿪����Ϊ�\n"NOR);
        
        tell_object(me, HIB"\n��ȫ���ע����׼" + target->query("name") + "�ķ�λ�ٶ�������׼�����֣�\n"NOR);
        
        extra = extra*(me->query("kar") + me->query("cps"));
        call_out("tobe_or_nottobe",3, me, target, extra, weapon);
        me->start_busy(6);
        return 1;
}
           
int tobe_or_nottobe(object me,object target,int extra, object weapon)
{
        string msg;
        int hit_rate;
        int hit_damage;
        if(!me||!target||environment(target)!=environment(me)) {
                tell_object(me, WHT"���ϧ����Ҫ��ɱ��Ŀ�������ˡ�\n"NOR);      
                return 0;
        }
        if(!present(weapon,me)||weapon->query("equipped")!="wielded"){
                tell_object(me, WHT"�����ˣ�����ô�������������ˣ� \n"NOR);
                return 0;
        }
                 
        msg = YEL "\n$NԾ���������"+weapon->query("name")+YEL"һת�������������֮����\n$N��һ����" + weapon->query("name") + YEL"���ַɳ��������ɳ��Х�Ż���$n�� \n"NOR;
        hit_rate = 15;
        hit_rate += 100 * random((extra*200 + (int) me ->query("combat_exp")));
        hit_rate = hit_rate / (200+ (int) target->query("combat_exp"));
        hit_damage = (int) me->query("str") * extra + weapon->weight();
        hit_damage = hit_damage/160 + hit_damage*hit_rate/40000;
        message_vision(msg, me, target);
        
        if (hit_rate>150) {
                msg = HIR"ֻ��" +weapon->query("name")+ HIR"����һ���Х�����ҵľ��硰�䡱�ػ�����$n��ͷ����\n"NOR;
                if (hit_damage>(int) target->query("max_kee"))
                        msg += HIW"\n���$n���ҵ��Խ��������Ҳ��̶ã�����\n"NOR;
                else
                        msg += RED"\n���$n���ҵÿ�����Ѫ���磡����\n"NOR;              
                target->start_busy(1);
        }
        else if (hit_rate>60){
                msg = HIR"ֻ��" +weapon->query("name")+ HIR"����һ���Х�����ҵľ��硰�䡱�ػ�����$n���ؿڣ�\n"NOR;
                msg += RED"\n���$n���ҵÿ�����Ѫ���磡����\n"NOR;
                target->start_busy(1);
        }
        else if (hit_rate>35){
                msg = HIR"ֻ��" +weapon->query("name")+ HIR"����һ�󾢷硰�䡱�ػ�����$n��\n"NOR;
                msg += WHT"\n���$n���ҵ��������ң��鴤��ֹ������\n"NOR;
                target->start_busy(1);
   }
        else {
                msg = HIR"ֻ��" +weapon->query("name")+ HIR"����һ�󾢷�����$n���Դ��ɹ���ֻ���û�л��У�\n"NOR;
                hit_damage = 0;
        }
        target->receive_wound("kee", hit_damage, me);
        weapon->move(environment(me));
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        target->kill_ob(me);
        me->kill_ob(target);    
        return 1;
}      
