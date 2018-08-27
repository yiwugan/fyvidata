 // dog.c
inherit NPC; 
void create()
{
        set_name("小白兔", ({ "rabbit" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "小白兔白又白两只耳朵竖起来。\n");
        set("limbs", ({ "头部", "身体", "前腿", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }));
        set_temp("apply/dodge", 100);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3); 
        setup();
}
