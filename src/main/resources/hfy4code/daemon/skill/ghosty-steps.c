 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup() {
        set("name", "̫��ò�");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 180);
        set("practice_bonus", -10);
        set("skill_class", "ninja");
        set("dodge_msg", ({
        "$n��Ӱһ�Σ����Ǽ�Ų��$N�ı���\n",
        "$n΢΢����һ����������Ʈ�����⡣\n",
        "$n˫��΢΢�趯����������һƬ��Ҷ����������Ʈ����\n",
        "$n˫��΢�ߣ���һֻ��ݵ����ӷ��˿���\n",
        "$n����һ���������˵������⡣\n"
        }) );
}  
int valid_learn(object me)
{
        object ob;
        
        if(!::valid_learn(me)) {
                return 0;
        }
        if (!me->query("tianfeng/done_quest"))
                return notify_fail("���ʮ����δ��Ӧת���������书��\n");
        if ((int)me->query("tianfeng/ghosty-steps")!=1){
                return notify_fail("���ʮ����δ��Ӧ���������书��\n");
        }
        return 1;
} 
int practice_skill(object me)
{
        if (me->query_skill("ghosty-steps",1) > 120)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");
        if ((int)me->query("force") < 20) {
                return notify_fail("�������������ϰ��\n");
        }
   if(!::practice_skill(me)) {
                return 0;
        }
        me->add("force", -10);
        return 1;
}    
