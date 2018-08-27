 // Mimicat@fy4
// kwan-yin-spells.c
inherit SKILL;
void setup() {
        set("name", "������������");
        set("usage/spells", 1);
        set("skill_class", "lama");
        set("effective_level", 150);
        set("learn_bonus", 10);
        set("black_white_ness", -20);
        set("practice_bonus", -10);
}
int valid_learn(object me)
{
        if( (int)me->query_skill("lamaism",1) < (int)me->query_skill("kwan-yin-spells",1)) {
                return notify_fail("������ڷ���Ϊ�������޷����������Ĺ����������䡣\n");
        }
        return 1;
} 
string cast_spell_file(string spell)
{
        return CLASS_D("lama") + "/kwan-yin-spells/" + spell;
}  
int practice_skill(object me)
{       
        object bug; 
        if (me->query_skill("kwan-yin-spells",1) > 120)
                return notify_fail("��ϰ�Ѿ����ܼ����������ֻ��ͨ��ѧϰ������ˡ�\n");
        if( bug = me->query_temp("mind_bug") )
                return notify_fail("��Ļ��ǻ�û��ȫ���ջأ��Ͽ�ɱ�����"
                        + bug->name() + "�ɣ�\n"); 
        if( (int)me->query("mana") < 10 )
                return notify_fail("��ķ���������\n"); 
        if( (int)me->query("sen") < 30 )
                return notify_fail("��ľ����޷����С�\n"); 
        me->add("mana", -10);
        me->receive_damage("sen", 30); 
        write("���Ŀ�����������⣬��ʼ��ϰ������������....\n");
        if( random((int)me->query("sen")) < 5 ) {
                int rnd; 
           rnd = random(me->query_skill("spells", 1));
                if( rnd < 10 )  bug = new("/obj/npc/mind_bug");
                else                    bug = new("/obj/npc/mind_beast"); 
                write("��������˼һ�ң������һֻ��Ŀ������" + bug->name() + "��\n");
                bug->move(environment(me));
                bug->set("combat_exp", (int)me->query("combat_exp")+100);
                bug->kill_ob(me);
                me->fight(bug);
                me->set_temp("mind_bug", bug);
                bug->set("owner", me->query("id"));
                return notify_fail("��Ļ�������" + bug->name() + "��ס������������ɣ�\n");
        }       
        else return 1;
}       
