#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL "������ʿ" NOR, ({"weishi" }) );
        set("long",

"��ȫ�����ң�һ��������վ�������˵���������硣\n");
        set("attitude", "heroism");
        set("pursuer", 1);
        set("vendetta_mark", "dali");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 1000000+random(1500000));
        set("chat_chance_combat", 45);

        set_skill("unarmed", 100+random(30));
        set_skill("sword", 100+random(50));
        set_skill("parry", 100+random(30));
        set_skill("dodge", 100+random(50));
        set_skill("move", 100+random(30));
        set_skill("duan-sword",151);
        map_skill("sword","duan-sword");
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

      carry_object(__DIR__"obj/armor")->wear();
        carry_object("/obj/weapon/sword")->wield();
}