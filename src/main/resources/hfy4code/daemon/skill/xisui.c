 inherit SKILL;
void setup(){
        set("name", "ϴ�辭");
        set("usage/iron-cloth", 1);
        set("effective_level", 200);
        set("bounce_ratio", 25);
        set("learn_bonus", -70);
        set("practice_bonus", -20);
        set("black_white_ness", 30);
        set("effect",50);
        set("skill_class", "shaolin");
        
        set("absorb_msg", ({
        "$N����ܸһ�ɴ�����$n���Ϸ���������\n",
        "$nȫ��������̥���ǣ�һ�ɵ���������$N��\n",
        }) );   
} 
int practice_skill(object me)
{
        return notify_fail("ϴ�辭ֻ��ͨ��ѧϰ����ߡ�\n");
                
} 
