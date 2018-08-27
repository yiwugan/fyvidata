// heaven_soldier.c

#include <ansi.h>

inherit NPC;
void backattack();
void create()
{

        set_name("������ͷ", ({ "dali guard", "guard" }) );
        set("long", "����һλ������ս�Ĵ�����ͷ��ר�ŵ��α��������Ա֮��\n");
        set("attitude", "friendly");


        set("max_atman", 100);
        set("atman", 100);
        set("max_mana", 100);
        set("mana", 100);

        set("str", 40);
        set("cor", 30);
        set("cps", 25);

        set("combat_exp", 200000 + random(300000));
        set_skill("sword", 170);
        set_skill("parry", 170);
        set_skill("duan-sword", 170 );
        set_skill("duan-steps", 170 );
        set_skill("dodge", 170);
        set_skill("move", 170);
        map_skill("sword", "duan-sword");
        map_skill("dodge", "duan-steps");
        map_skill("parry", "duan-sword");

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/d/dali/obj/longsword")->wield();
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        object owner;
        message("vision",
                 name() + "˵�������������飬����Ϊ�ţ�\n\n"
                + name() + "���ָ��ˡ�\n" , environment(),
                this_object() );
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
        destruct(this_object());
}

void invocation(object who, int level)
{
        int i;
        object *enemy;
        set_skill("sword", 70 + random(level/2));
        set_skill("duan-sword", 70 + random(level/2));
        set_skill("parry", 70 + random(level/2));
        set_skill("dodge", 70 + random(level/2));
        set_skill("move", 70 + random(level/2));
        set_skill("duan-steps",70 + random(level/2));
        map_skill("sword", "duan-sword");
        map_skill("dodge", "duan-steps");
        set("combat_exp", 300000 + random(level/4*level*level));
        message("vision",
                 HIC "" + name() + "�ȵ����󵨣������ԱҲ�����������𣿸����ϣ�\n" NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
        set("possessed",who);
}
void backattack()
{
        int i;
        object owner, *enemy;
        if(objectp(owner=this_object()->query("possessed")))
        {
                enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

        }

}

void die()
{
        object owner;
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
        backattack();
        ::die();
}
