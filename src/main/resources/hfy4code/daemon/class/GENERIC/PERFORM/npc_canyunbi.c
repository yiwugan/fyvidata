 // sillencer@fy4.com
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 
int fight_pfm( object me, object target);
int no_fight_pfm( object me, object target);
int poisonhim(object me, object target);  
int perform(object me, object target)
{
        object *ob;
        int i, skill, my_exp,his_exp, bonus;
        string msg; 
        if(userp(me))
                return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");  
        
        if(me->query("class")!="knight")
                return notify_fail("ֻ�п���ֵ��Ӳ��ܹ�ʹ��"+HIG"��������ϲ��Ʊ̡�"NOR+"��\n"); 
        if (me->query_skill("dream-herb",1)<100)
                return notify_fail("��������廨�����������졣\n");
                
        fight_pfm(me,target);
        
        return 1;
                 
} 
int fight_pfm (object me, object target) { 
        object *ob;
        int i, skill, my_exp,his_exp, bonus, num;
        string msg;
        
        if(!me->is_fighting() ) {
                tell_object(me,"��������ϲ��Ʊ̡�ֻ����ս����ʹ�á�\n");
                return 1;
        }
        
        if (target) {
                tell_object(me,"��������ϲ��Ʊ̡�����Ҫָ��Ŀ�ꡣ\n");
                return 1;
        }
                
           skill = me->query_skill("herb");
        
        bonus = (me->query("combat_exp")-2000000)/5000*skill/1000;
        if (bonus>skill) bonus= skill;
        if (bonus>0) skill= skill+bonus; 
//      message_vision(" total is "+(string)(skill*3)+".\n",me);        
        
        msg = BLINK+GRN"$N������ת����ɫͻȻ��ñ�����������\n\n" NOR; 
        message_vision(msg,me);         
        
        me->start_busy(3);
        
        msg = HIG "$N��һҧ��⣬ʹ�������廨�������������ġ�������ϲ��Ʊ̡����� \n��Ѫ�������Ũ��һ�㣬����׷����䡣\n\n" NOR;
        message_vision(msg,me);
        
        my_exp=me->query("combat_exp");
        
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++)   {
                if (!living(ob[i]) || ob[i]==me ) continue;
                if (!ob[i]->is_fighting(me)) continue;
                if (ob[i]->query_temp("dot/dream-herb")) continue;
                his_exp=ob[i]->query("combat_exp");
                if (my_exp/2+ random(my_exp/50*skill)>his_exp) {
                        msg =  HIR "�廨����������Ϣ������$n�����ڣ�����\n" NOR;
                        message_vision(msg,me,ob[i]);
                        message_vision(YEL"$Nֻ����ǰ"+HIG"��"+HIG"��"+HIM"��"+HIY"�"NOR+YEL"���ƺ�������ֻС���ڷ��衣\n"NOR,ob[i]);
                        num = random(skill*3);
//                      message_vision(" it's "+(string)(num)+".\n",me);
                        ob[i]->receive_wound("kee",num,me);
                        ob[i]->set_temp("dot/dream-herb",1);
                        call_out("dot",6,me,ob[i],4,0,skill*3);                 
                } else 
                        tell_object(me,HIW"����廨����"+ob[i]->name()+"�����ˣ���\n"NOR);    
        }
    return 1; 
}  
void dot (object me, object enemy, int total, int count, int amount)
{
        int num;
   if (!enemy->is_fighting(me)|| !enemy ) {
                if (enemy) {
                        message_vision(WHT"$N����ɫ�����ָ�����������\n"NOR,enemy);
                        enemy->delete_temp("dot/dream-herb");
                }
                return;
        }
        message_vision(YEL"$Nֻ����ǰ"+HIG"��"+HIG"��"+HIM"��"+HIY"�"NOR+YEL"���ƺ�������ֻС���ڷ��衣\n"NOR,enemy);
        num= random(amount);
//      message_vision(" it's "+(string)(num)+".\n",me);
        enemy->receive_wound("kee",num,me);
        enemy->set_temp("dot/dream-herb",1);
        count= count+1;
        if (count<total) call_out("dot",6,me, enemy,total,count, amount);
                else {
                        message_vision(WHT"$N����ɫ�����ָ�����������\n"NOR,enemy);
                        if (enemy) enemy->delete_temp("dot/dream-herb");
                        return;
        }
        return ;
} 
