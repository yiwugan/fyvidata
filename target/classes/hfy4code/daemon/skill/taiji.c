 // taiji.c
#include <ansi.h>
inherit SKILL;
void setup(){
        set("name", "̫��ȭ");
        set("usage/unarmed", 1);
        set("usage/parry", 1);
        set("effective_level", 200);
        set("learn_bonus", 10);
        set("practice_bonus", -100);
        set("black_white_ness", 30);
        set("skill_class", "wudang");
        set("parry_msg", ({
            "$nһ�С��������ơ���Բ���λ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
            "$n����̫����һ�С�§ϥ���������Ƶ�$N����������\n",
            "$n����Ϊ����һ�С����������������ͻ�$N��$w������\n",
            "$nһ�С�����Ʊա���˫�Ʋ���Բת������$N����������ת��һȦ��\n",
        }) ); 
        set("unarmed_parry_msg", ({
            "$nһ�С�ʮ���֡����Ƶ�$N��;���С�\n",
            "$n�����������Ծ��ƶ���һ�С�������ɽ������$N������Զ��\n",
            "$n����������������ʹ��̫��ȭ�ġ�����ʽ��������׾ٵؽ�$N���ڳ��⡣\n",
            "$n˫�������ʹ��̫��ȭ���һʽ�����޺�̫������$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",
        }) );   
        action = ({
            ([ "action":
            "$N˫��Բת��ʹ��һ�С�����β������׼$n��$l����",
             "dodge":30,
             "parry":150,
             "force":300,
             "damage_type":"����"
                ]),
            ([ "action":
            "$N������Σ����ƻ���һ��Բ����һ�С����ޡ�����$n��$l�к���ȥ",
             "dodge":20,
             "parry":120,
             "force":300,
             "damage_type":"����"
                ]),
            (["action": 
       "$Nһ�С��׺����᡹��˫�Ƴ�Բ��������Բת����$n��$l����",
             "dodge":20,
             "parry":120,
             "force":300,
             "damage_type":"����"
                ]),
            ([ "action":
            "$N����������������ʹ��һ�С��ֻ����á���˫��������$n��$l��£",
             "dodge":20,
             "parry":120,
             "force":300,
             "damage_type":"����"
                ]),
        });
}
int valid_learn(object me)
{
        object ob;
        if( (int)me->query_skill("changelaw",1)*2 < (int)(me->query_skill("taiji",1))){
                return notify_fail("����׾����˽⻹��������޷�ѧϰ̫��ȭ��\n");
                }
        if(!::valid_learn(me)){
                return 0;
        }
        if ((int)me->query("max_force") < 500) {
                return notify_fail("�������������\n");
        }
        
        return 1;       
        
        
    return 1;
} 
int practice_skill(object me)
{ 
        if((int)me->query("force") < 15 ) {
                return notify_fail("�������������������̫��ȭ��\n");
        }
   if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -15);
        return 1;
        if ((int)me->query_skill("taiji",1) > 50) {
                return notify_fail("����ȭ���������ֻ����ѧ�ġ�\n");
        }
}  
int effective_level()
{
        object me=this_player();
                int skill,n;
                skill=me->query_skill("taiji",1);
         if (skill >= 165 && me->query("class")=="wudang") {return 300;}
         	  else return 200;
        
        
}
/*void skill_improved(object me)
{
    int s;
    s = me->query_skill("taiji", 1);
    if (s== 160 && me->query("class")=="wudang") {
       tell_object(me,HIW "���Ȼ���ã�������Լ����ټ�������һ���Ļ���\n"NOR);
       tell_object(me,HIW "�ܹ���̫��ȭ�Ĺ�Ч����һ��¥��\n"NOR);
       }
    if (s== 165 && me->query("class")=="wudang") {
       tell_object(me,HIW "���̫��ȭ���������ǵǷ��켫������\n"NOR);
       }
} */    
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
        if( damage_bonus < 300 ) return 0;
        badint = victim->query_skill("iron-cloth") + victim->query_temp("apply/iron-cloth")*2;
        if (victim->query_skill_mapped("iron-cloth") == "xuanxinjue"
           ||victim->query_skill_mapped("iron-cloth") == "jin-gang"
                ||victim->query_skill_mapped("iron-cloth") == "spring-water"
                ||victim->query_skill_mapped("iron-cloth") == "yijinjing"
                ) {
                if(badint) {
                        victim->receive_wound("kee",badint);
                        switch(random(3)) {
                                case 0: return "$Nȭ�����಻������������һ�㣬��ͻ����$n����ǽ��\n";
                                case 1: return "$Nȭ��������ǽ��ͻȻ��ʧ��ȴ����$n��$lǰͻȻ���֣�������ֻ������������һ�����죡\n";
                                case 2: return "ֻ����$n��$l��������һ�� ������\n";
                                }
                }
        }
}  

  