 // Copyright (C) 2002, by Sinny Shi. All rights reserved.
// - revised by neon
// - This skill is a skill to enable all kinds of "pen-like" weapons - neon 
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
#include <ansi.h>
void setup(){
        set("name", "�鷨");
        
        set("usage/unarmed", 1);
        set("usage/parry", 1);
        //set("usage/sword", 1);
        set("effective_level", 220);
        set("practice_bonus", -10);
        set("black_white_ness", 10);
        set("skill_class", "baiyun");
        set("unarmed_parry_msg", (
        
         { "$n������ɣ�˲Ϣ֮�䡸�����w��, �κ��κΡ�������$N��֪���롣 \n",
          "$n�������飬����Ȧת�趯�������������֮�кӺ�����$N�ۻ����ҡ� \n",
         }
        ) ); 
        action = ({
        ([      "action":               
"$N��Хһ��������Ʈ�ݣ������絶����$n���ݺ�֮�䡸��֮���ס�����д������ͰΣ�׿����Ⱥ��",
                "dodge":                -10,
                "parry":                10,
                "damage":               110,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���δ󿪴��أ�����Ĺ���ݱ����һ���ǳɣ�һ��һ�����Ǳ��ߣ���籩�������$n��",
                "dodge":                -30,
                "parry":                30,
                "damage":               140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ⶶ�䣬���ֳٻ����أ�����ǧ��֮������$n��$l��д�����ǡ�׷Ω���������֡�",
                "dodge":                50,
                "parry":                50,
                "damage":               160,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����֮����$n��$l���¡���Ľ�ݾ���ʹ���ĸΡ����֣�����Ҳ���أ��Ƴ��֮������
��Ҳ�վ��������֮�ѡ� ",
                "dodge":                270,
                "parry":                270,
                "damage":               30,
                "damage_type":  "����"
        ]),
        });
}
int valid_learn(object me)
{
        if(!::valid_learn(me)){
                return 0;
        }
    if((int)me->query_skill("chess", 1) <  (int)me->query_skill("calligraphy",1) ){
        return notify_fail("���������Ϊ�������ĸ����겻��ѧϰ�鷨��\n");
    }
    return 1;
}  
int practice_skill(object me)
{
    if((int)me->query_skill("calligraphy",1) >  100){
        return notify_fail("������ĵ�ֻ��ͨ��ѧϰ���о��������ˡ�\n");
    }
        if( (int)me->query("force") < 25 ){
            return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        }
        if(!::practice_skill(me)){
                return 0;
        }
        me->add("force", -15);
   return 1;
}  
mixed parry_ob(object victim, object me)
{       int busy_time;
        int skill;
        int my_exp, your_exp;
        
        my_exp=me->query("combat_exp");
        your_exp=victim->query("combat_exp");
        
       //if ( random(my_exp*5) < your_exp ) return 0;
        
        skill=me->query_skill("calligraphy",1);
        
        if (/*random(skill) + skill/2 > 100 && */me->is_busy()) {
                message_vision(HIG"$N������֣����˾�Ȼ�����յģ۵���ƪ��������Ŀ��������Ȼ����������\n"NOR, me);       
                me->stop_busy();
        }
        
        return 0;
}         
mapping query_action(object me, object weapon)
{
        int attack_act;
        object *victims,victim;
        attack_act=random(sizeof(action));
        me->set_temp("calli_print",attack_act);
        return action[attack_act];
}  
mixed hit_ob(object me, object victim, int damage_bonus)
{
       
        int action;
        string printtype, prints;
        
        if (! random(3)) return;
                
        action = me->query_temp("calli_print"); 
        
        switch(action) {
                case 0:
                   printtype="����֮���ס�" ;
                        break;
                case 1:
                        printtype="����Ĺ���ݱ����";
                        break;
                case 2:
                        printtype="��׷Ω������";
                        break;
                case 3:
                        printtype="����Ľ�ݾ���ʹ���ĸΡ�";
                        break;
                }
        
        me->delete_temp("calli_print");
        
        if(printtype)
        {
                prints =(string) victim->query_temp("body_print");
                if ( victim->query_temp("cali_print") <3) {
                        if (!prints)
                                prints = gender_pronoun(victim->query("gender")) + "���ϲ�֪����˭���£�"+ printtype+ "�����֡�\n";
                        else prints = prints + "�������˿��µĻ��У�"+ printtype+ "�����֡�\n";
                }
                else prints = gender_pronoun(victim->query("gender")) + "���ϱ����ҿ��һ���һ���㣬��ǿ���Կ�����" + printtype+ "�����֡�\n";
                victim->set_temp("body_print", prints);
                victim->add_temp("apply/personality" , -1);
                victim->add_temp("cali_print", 1);
        }
        // -----> can add special effects here
        
        
        // <------------
        switch(random(2)) {
                case 0: return WHT"$N������Ȼ������$n��$lд��" + printtype + "�����֣�\n"NOR;
                case 1: return WHT"$N�����վ�����ľ���֣���" + printtype+"�����ֿ���$n��$l��\n"NOR ;
        }
        
}       
int learn_skill(object me)
{
       if (me->query("class") != "baiyun") 
                return notify_fail("ֻ�а��Ƴǵ��Ӳſ���ѧϰ�鷨��\n");
}
