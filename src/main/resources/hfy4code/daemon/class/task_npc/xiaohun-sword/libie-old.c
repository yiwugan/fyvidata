 //libie.c
// - neon 
/*    
��Ȼ�����ߣ�Ψ������ӣ�
...... 
���±ڶ����ʣ����������ɹ⡣
������֮��¶�������֮��˪��
Ѳ��麶����ڣ�����Ļ��������
֪����֮�������֮���
... 
�ʱ���һ�����������塣
... 
���������������������ᣬ�����������Ϳͽ�ȡ�
����������ĳ£��ࡢ�Ը��������ˣ�
����������ĺ�������⽿�ϴ���
������֮��������Ԩ��֮���ۡ�����ֶ����飬�м�į������
... 
�������ǧ�ϧ����֮ͽ����
���Ĺ�֮��ɪ���޸�̨֮���ơ�
�����մ���̦ɫ�����ʺ������¹⣬
���������粻ĺ����������ҹ�γ���
֯���������Ѿ�������ʫ��Ӱ���ˡ� 
... 
���Ա𷽲���������ǧ�����б��Թ����Թ��ӯ��
ʹ������񺧣����۹Ǿ�����Ԩ����֮ī��ϡ���֮�ʾ���
���֮���壬��̨֮ȺӢ����������֮�ƣ����е���֮����
˭��ġ����֮״��д����֮���ź��� 
...
*/ 
// ��Ȼ������Ψ����� 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int libie_sword(object me,object target,int extra,object weapon);
int perform(object me, object target)
{
        string msg, weather;
        int extra;
        object weapon;
        if (!(me->query("����A/��Դ_����") || me->query("����A/��ɽ_����") || me->query("����A/̩ɽ_����")))
       return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ����\n"); 
        if( !target ) target = offensive_target(me); 
        extra = 3 * me->query_skill("sword") /2;
        if(extra<200)
                return notify_fail("�㽣������Ϊ������\n"); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(MAG"������"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");  
        weapon = me->query_temp("weapon");
        
        me->add_temp("apply/attack", extra/10); 
        me->add_temp("apply/damage", extra/4);
        msg = HIC"$N����"+ weapon->name()+ HIC"�������ǰ�Ĺ�â�������ա�����\n"HIW"��â��̴٣��������Ѿ�û���ǹ��ܱ��������ã��Իͣ�����\n"NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack", -extra/10);
        me->add_temp("apply/damage", -extra/4);
// leave_hook mark checking here, to decide if there is a call out.
        weather = NATURE_D->get_weather();
        if (me->query("libie/���_β��")
          && ! (weather == "��")
          && (int) me->query("timer/libie") + 600 < time()
        ) {
                me->start_busy(2);      
                call_out("libie_sword",3, me,target,extra,weapon);
// Enemy has slim chance to run after libie first hit
                target->start_busy(1);
        }
        else me->start_busy(3);  
        return 1;
} 
int libie_sword(object me,object target,int extra,object weapon)
{
        string msg, wname;
        int d;
        
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me)) return 0;
        if(!present(weapon,me)||weapon->query("equipped")!="wielded")
                return 0;
        
   me->set("timer/libie",time());
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        target->delete_temp("last_damage_from");
        msg = WHT"\n\n��â��ȥ֮��$n"NOR+WHT"��ǰ��Ȼ���ֳ�������Ҷ�£���ʼ�Զȥ�Ĺ·���\nһʱ���г������������ļ�į����ʹ��";
        msg += YEL"\n\n$N����" + weapon->name() + YEL"����������������������֮����\n��ʯ���ɫ�䣬���Ɐ��������\n"NOR;
        me->set_temp("libie",1);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra); 
    if (me->query("����A/��ɽ_����")) {
        msg = HIB"\n������һƬ���ţ��紵��ľ��������û�У�Ҳ���Ƿ�����ʹ��������"NOR;
        msg += HIG"\n\n$N����" + weapon->name() + HIG"��Ȼ�����������������Ʈ�� . . . \n˭���������е�����֮״������֮���أ�"NOR;         
            me->add_temp("apply/attack",extra*2);
            me->add_temp("apply/damage",extra/2);
            COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
            me->add_temp("apply/attack",-extra*2);
            me->add_temp("apply/damage",-extra/2);
    } 
        if (!target->query_temp("last_damage_from"))
        {
                message_vision(HIR"\n$N��Ȼ�����������Ʈ翣����α���Ľ�Ӱ�м��������� \n"NOR,target);
                me->start_busy(5);
        }       
        else { 
        message_vision(HIW"\n\n\n     ��  Ȼ  ��  ��  �� �� Ψ  ��  ��  ��  ... ...  \n\n"NOR,me);
         
        if ( !(me->query("����A/̩ɽ_����") || weapon->query("id") == "leave hook") ) {
        
            if  (userp(target)) target->apply_condition("libie", extra/25);
            msg = MAG"\n\n���Ǽ�������ţ�$n"MAG"ͻ��һ�������ʹӿ����ͷ��\n"NOR;
            message_vision(msg,me,target);
            }
            else {
                target->receive_damage("sen",me->query("kee")/3,me);
                target->receive_wound("sen",me->query("kee")/4,me);
                me->receive_damage("kee", me->query("eff_kee")/2 + 20, me);
                me->receive_wound("kee", me->query("eff_kee")/2, me); 
                weapon->set("orig_name", weapon->query("name"));
                d = weapon->query("weapon_prop/damage") - 1;
           weapon->set("weapon_prop/damage",1);
                target->add_temp("apply/damage",-d);
                
                msg = HIY "\nֻ������ž����һ����$N���е�" + weapon->name() + HIY"�ھ������Ѿ���Ϊ���أ�\n"NOR;
                wname = replace_string( weapon->name(), "�ϵ���", "");
                weapon->set("name", "�ϵ���" + wname);
                if (weapon->query("owner")) weapon->save();
                else {
                        weapon->unequip();
                        weapon->set("weapon_prop", 0);
                        weapon->set("value", 0);
                } 
                msg += YEL"\n$Nǿ������������Ľ�����Ȼ�ӶϽ��ȳ�... \n";
                msg += MAG"\n\n���Ǽ�������ţ�$n"MAG"ͻ������������ζ��һ�����ӿ����ͷ��\n"NOR;
            message_vision(msg,me,target);
            }
            me->start_busy(4);
        }
        me->delete_temp("libie");
        return 1;
}  
