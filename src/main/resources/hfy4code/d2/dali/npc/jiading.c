#include <ansi.h>

inherit NPC;

void create()
{
        set_name( "�����Ҷ�" , ({"jiading" }) );
        set("long",

"���������ļҶ���\n");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 500000+random(150000));
        set("chat_chance_combat", 45);

        set_skill("unarmed", 50+random(30));
        set_skill("sword", 50+random(50));
        set_skill("parry", 50+random(30));
        set_skill("dodge", 50+random(50));
        set_skill("move", 50+random(30));
        set_skill("duan-sword",80);
        map_skill("sword","duan-sword");
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}