 //feiyuancurse.c
inherit SKILL; 
void setup() { 
        set("name", "��ԩ������"); 
        set("usage/herb", 1); 
        set("practice_damage", 40); 
        set("learn_bonus", 0);
        set("practice_bonus", -50); 
        set("skill_class", "quanli"); 
        set("black_white_ness", -50);
  }       
int valid_learn(object me)  
{ 
    if((int)me->query_skill("force", 1) < 100) { 
        return notify_fail("����ڹ��ķ�����㣬�޷�����ԩ��������\n"); 
        } 
        return 1; 
} 
        
int practice_skill(object me)
{
        if (me->query_skill("feiyuancurse",1) > 120)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");
        if ((int)me->query("force") < 20) {
                return notify_fail("���������������ԩ��������\n");
        }
        if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -15);
        return 1;
}     
