 // TIE@FY3
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int main(object me, string arg)
{
        int skill;
        object target;
        string msg;
        seteuid(getuid());
        if(me->query("class") != "shenshui") return
        notify_fail("��������ˮ���ľ�����\n");
        skill=me->query_skill("nine-moon-spirit",1);
        skill=skill/5*6;
        
        if((int)me->query("timer/polu") + 8 > time())
                return notify_fail(HIM"��ո�ʹ�ù�[��­]����������������Ч��\n"NOR);
        
        if((int)me->query("timer/jiasi") + 900-skill*3/2 > time())
         {
                return notify_fail(HIM"��ô��;ɼ����ݻ��������\n"NOR);
        }
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�㲻��ս���У�����Ҫ��װ����\n");
       
//      if(random(10))
//      {       
        message_vision("$N�ҽ�һ����һͷ�Ե��ڵ��¡�\n$N���ˡ�\n",me);
        me->set("disable_type",HIG "<������>" NOR);
        me->remove_all_killer();
        me->remove_all_enemy();
//      me->delete("env/wimpy");
        me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me :), 
random(50 - (int) me->query_con()));
        me->set_temp("disable_inputs",1);
        me->set_temp("block_msg/all",1);
   me->set_temp("is_unconcious",1);
        me->set_temp("in_jiasi",1);
        
//      }
/*      else
        {
        msg = "��ϧ$nװ�������ɹ���$N�˻�����ѸȻ������";
        COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);  
        me->start_busy(random(3) + 2);
        } */
        return 1;
} 
void remove_dazuo(object me)
{
        me->delete_temp("in_jiasi");
        me->delete_temp("is_unconcious",1);
        me->delete_temp("disable_inputs");
        me->delete("disable_type");
        me->delete_temp("block_msg/all");
        message_vision("$N�ڵ������ĵط��˸���С��������������ۡ�\n",me);
        //me->move(environment(me),1);
        me->set("timer/jiasi",time());
} 
int help(object me)
{
        write(@HELP
ָ���ʽ : jiasi
������ս����װ�������������Ļ��ᡣ
����ˮ�����˲�����װ���� 
HELP
        );
        return 1;
}
     
