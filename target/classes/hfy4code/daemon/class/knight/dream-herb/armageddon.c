 // armageddon.c
// ��ʯ���
// by Love@FY(olives) 
#include <ansi.h> 
//inherit F_DBASE;
inherit SSERVER; 
int do_prepare(object me,object target);
int interrupt_prepare(object me,object who,string reason); 
void create() { set("channl_id","������˵");} 
int perform(object me, object target)
{
        int skill,i,extra;
        object *obs;  
        if( !me->is_fighting() )
                return notify_fail("����ħ����󷨡�ֻ����ս����ʩ�á�\n");
        if( environment(me)->query("no_death_penalty"))
                return notify_fail("�ֲ��������ಫ��û��Ҫ������ƴ��\n"); 
        if( !target || target == me ) target = offensive_target(me); 
        skill = me->query_skill("dream-herb");
//      skill=300;
        if( skill < 250 ) return notify_fail("�����Ϊ������ʹ��������ħ����󷨡���\n");
        //��Ȼ�б�̬��NPC����һ��ʼ���ó�����
        if(userp(me) && !wizardp(me)&& me->query("kee")>me->query("max_kee")/2)
                return notify_fail("�����ڲ���������ͷ��û��Ҫʩ�á���ħ����󷨡���\n");
        message_vision(HIR"$N�����ֳ�����֮ɫ���ӻ��г���������룬�����Լ�ͷ��Ѩ��������ͻȻ������ת����������Ѫɫȫ����ȥ.\n" NOR, me);
        extra=skill+random(skill);
        me->add_temp("apply/defense",extra);
        me->set_temp("herb/armageddon",extra);
        obs = filter_array( all_inventory(environment(me)) , (:$1->is_character()&&!$1->is_corpse():) );
        obs -= ({me});
        i = sizeof(obs);
        while( i-- )
        {
                        me->kill_ob(obs[i]);
                        if( !userp(obs[i]) )
                                obs[i]->kill_ob(me);
                        else
                                obs[i]->fight_ob(me);
        }
        me->set_temp("prepare_armageddon",5);
   environment(me)->set_temp("lock_scene",time());
        seteuid(ROOT_UID);
        me->start_busy(
                bind((: call_other, __FILE__, "do_prepare", me, target:), me),
                bind((: call_other, __FILE__, "interrupt_prepare" :), me) );
        //        0 );
        return 1;
} 
int do_fire(object me,object target)
{
        int damage,i,extra;
        object *obs; 
        me->clean_up_enemy();
        if( !target || target == me || target->is_corpse()) target = offensive_target(me); 
        damage = me->query_skill("force")*me->query_skill("herb")/100+me->query_skill("herb");
        damage *= (6 + random(5)); 
        if(!me->query("����B/��Դ_����"))
                damage += random(damage/4);
        if(wizardp(me) && me->query("env/debug"))
                tell_object(me,sprintf("armageddon damage=%d,target=%O\n",damage,target)); 
        me->set("force",0);
        me->delete_temp("prepare_armageddon"); 
        if( !target )
                message_vision(HIR"\n���˵��澢����$N���ܱ������Ծ��˵ĸ�����ɢ��������Χ�ռ䣬\n"NOR,me);
        else
        {
                message_vision(HIR"\n���˵��澢����$N���ܱ������Ծ��˵ĸ�����ɢ��������Χ�ռ䣬\n"NOR,target);  
                if( (damage-target->query_temp("apply/armor_vs_force")) > 0 )
                {
                        target->receive_wound("kee",damage-target->query_temp("apply/armor_vs_force"),me);
                        target->set_temp("last_damage_from","����ħ�����ը���ˡ�");
                        //��NPCɱ�˸���һЩ
                        if( !userp(target) )
                                target->receive_wound("kee",damage,me);
                        COMBAT_D->report_status(target,1); 
                }
                else
                {
                        message_vision(GRN"����$N"+GRN"���������һ��ƴ��ȫ���ֵ�ס�����������һ����\n"NOR);
                        target->set("force",0);
           }
        }
        message_vision(RED"\n���ͬʱ��$N"+RED"�������쾫Ѫ��ۣ������񼣰���ʧ����Ӱ���١�\n"NOR,me); 
        message_vision(HIR"������������һ����û....\n\n"NOR,me);
        obs = all_inventory(environment(me));
        obs -= ({me,target});
        i = sizeof(obs);
        while( i-- )
        {
                if( obs[i]->is_character() && obs[i]->query("max_kee") )
                {
                        if( (damage/2-obs[i]->query_temp("apply/armor_vs_force")) > 0 )
                        {
                                write("...\n");
                                message_vision(RED"ֻ�������项��һ�����죬$N"+RED"������Ѫ������������ߵķ���һ�������ȥ����\n"NOR,obs[i]);
                                obs[i]->receive_wound("kee",damage/2-obs[i]->query_temp("apply/armor_vs_force"),me);
                                if(userp(obs[i]))
                                        obs[i]->set_temp("last_damage_from","����ħ�����ը���ˡ�");
                                else
                                        obs[i]->receive_wound("kee",damage/2,me);
                                //COMBAT_D->report_status(me,obs[i],1);
                        }
                }
        }
        write(""NOR);
        target->check_status();
        obs->check_status();
        environment(me)->delete_temp("lock_scene");
        CHANNEL_D->do_sys_channel(
                                "info",sprintf("��˵%s(%s)ʩ����ħ����󷨣���������ˡ�", me->name(1),geteuid(me)));
//      CHANNEL_D->do_channel(this_object(),"rumor","��˵"+me->name()+"ʩ����ʯ���,��������ˡ�");
//      me->delete_temp("last_damage_from");
        seteuid(getuid());
        extra=me->query_temp("herb/armageddon");
        me->add_temp("apply/defense",-extra);
        me->delete_temp("herb/armageddon");
        me->die(1);
} 
int do_prepare(object me,object target)
{
   int left_busy; 
        me->add_temp("prepare_armageddon",-1);
        left_busy = me->query_temp("prepare_armageddon"); 
        me->clean_up_enemy();
        if( !target || target == me || target->is_corpse()) target = offensive_target(me);
        if( left_busy > 3 )
        {
                message_vision(HIR"$N�����Ѫ������������ħ������ס��խ����...\n"NOR,me);
                return 1;
        }
        if( left_busy > 2 )
        {
                if(target)
                        message_vision(HIR"$N����ħ������ס��խ������������$nΪ������Χ�ķ���֮�أ�$N����ɫ�������Ѫ��...\n"NOR,me,target);
                else
                        message_vision(HIR"$N����ħ������ס��խ��������������Χ�ķ���֮�أ�$N����ɫ�������Ѫ��...\n"NOR,me);
                return 1;
        }
        if( left_busy > 1 )
        {
                message_vision(HIR"$NĿ����⣬ͫ����â��ʢ��������������������ĺ�Х��ȴ������ǿ...\n"NOR,me);
                return 1;
        }
        if( left_busy > 0 )
        {
                if(target)
                        message_vision(HIR"���ڼ�ս֮�У�$N��Ȼ������Х����ħ����ٿ����$nΪ����������ϸխ����һ��.\n"NOR,me,target);
                else
                        message_vision(HIR"$N��Ȼ������Х����ħ����ٿ��������ϸխ����һ��.\n"NOR,me);
                return 1;
        }
        do_fire(me,target);
        return 0;
} 
int interrupt_prepare(object me,object who,string reason)
{
        int extra;
        switch(reason)
        {
/*              case "halt":
                   return notify_fail(HIR"����ħ����󷨡�һ��ʩ�ã��ض��������������޷���ֹͣ�ˣ�\n"NOR);
                        break;
 */
                case "hit":
                        if( random(who->query("force_factor")+who->query("force")) < (me->query_skill("herb")+me->query("force"))/4*3 ) return 0;
                        message_vision(HIR "$Nһ�����У�����͸��$n���ڣ���ʱ�ض���$n��������\n" NOR, who,me);
                        tell_object(me,HIR"��ֻ����ȫ������ͻȻ������Ѩ������ǰ������ܿ��Ƶؿ��Ҵ�������������!\n"NOR);
                        me->set("force",0);
                        extra=me->query_temp("herb/armageddon");
                        me->add_temp("apply/defense",-extra);
                        me->delete_temp("herb/armageddon");
                        me->unconcious();
                        break;
                default:break;
        }
        environment(me)->delete_temp("lock_scene");
        return 1;
} 
