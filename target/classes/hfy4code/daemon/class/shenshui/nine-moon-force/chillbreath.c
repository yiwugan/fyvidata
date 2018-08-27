#include <ansi.h>
inherit F_CLEAN_UP; 
int exert(object me, object target, int amount)
{
        object *ob;
        int i, skill, my_exp,his_exp, bonus; 
        if(me->query("class")!="shenshui")
                return notify_fail("ֻ����ˮ�����Ӳ���ʹ�������������ľ�����\n"); 
        if (me->query_skill("nine-moon-force",1)<150)
                return notify_fail("��ģ۾����ľ��ݻ��������졣\n");
        if (me->query_skill("nine-moon-spirit",1)<150)
                return notify_fail("��ģ��Ů�񹦣ݻ��������졣\n");
        
        if( !me->is_fighting() )
                return notify_fail("����������ֻ����ս����ʹ�á�\n"); 
        if( (int)me->query("force") < 150 )
                return notify_fail("�������������\n"); 
        skill = me->query_skill("nine-moon-force",1)+me->query_skill("nine-moon-spirit",1);
        
        bonus = (me->query("combat_exp")-2000000)/5000*skill/1000;
        if (bonus>skill) bonus= skill;
        if (bonus>0) skill= skill+bonus;
                        
        me->add("force", -150);
        me->receive_wound("kee",100);
        me->start_busy(2);
        message_vision(HIR "$N���������������ͻȻ�³�һ��Ѫ��ɫ������\n" NOR, me);
        
        my_exp=me->query("combat_exp");
        
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++)   {
                if (!living(ob[i]) || ob[i]==me ) continue;
                if (!ob[i]->is_fighting(me)) continue;
                if (ob[i]->query_temp("nine-moon-force/dot")) continue;
                his_exp=ob[i]->query("combat_exp");
                if (my_exp/2+ random(my_exp/80*skill)>his_exp) {
                        message_vision(HIM"$N"+HIM"�����������棬�������˹�ȥ��\n"NOR,ob[i]); 
                        ob[i]->receive_wound("kee",random(skill*2),me);
//                      message_vision("damage is "+(string)(skill*2)+" .\n",me);
                   call_out("dot",6,me,ob[i],10,0,skill*2);  
                        ob[i]->set_temp("nine-moon-force/dot",1);
                }
        }
    return 1;
} 
void dot (object me, object enemy, int total, int count, int amount)
{
        int num;
        if (!enemy->is_fighting(me)|| !enemy ) {
                message_vision(WHT"$N����һ���������еġ�������������ʧЧ�ˡ�\n"NOR,enemy);
                if (enemy) enemy->delete_temp("nine-moon-force/dot");
                return;
        } 
        message_vision(MAG"$N"+MAG"�������ͨ�죬����������ת��ҡҡ��׹��\n"NOR,enemy);
        num = random(amount);
        enemy->receive_wound("kee",num,me);
//      message_vision((string)(count)+" damage is "+(string)(num)+" .\n",me);
        enemy->set_temp("nine-moon-force/dot",1);
        count= count+1;
        if (count<total) call_out("dot",6,me, enemy,total,count, amount);
                else {
                        message_vision(WHT"$N����һ���������еġ�������������ʧЧ�ˡ�\n"NOR,enemy);
                        if (enemy) enemy->delete_temp("nine-moon-force/dot");
                }
        return ;
}
