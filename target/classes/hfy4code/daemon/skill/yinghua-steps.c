 // yinhua-steps.c ӣ������
inherit SKILL;
void setup(){
        set("name", "ӣ������");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 250);
        set("learn_bonus", -50);        
        set("skill_class", "bat");      
        set("dodge_msg", ({
        "$n����һת���͵�����һ��,�����$N�Ĺ��ơ�\n",
        "$n������һֻ��ӥ������һ����$N����ǰ�ɹ���\n",
        "$nȫ��Ϊһ����Ӱ������һ���շ��������Ʈ���ұߡ�\n",
        "$n���İεض����ڰ����һת�����䵽����Զ�ĵط���\n",
        "$n����һ����ʸ������ٿ�İεض�����$N�������ӡ�\n",
        }) );
}     
