 // Copyright (c) 1998 Apstone, Inc.
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("古丽娜", ({ "eagle gulina", "gulina" }) );
        set("long", "tt");
        set("nickname",HIY "断翅金鹰"NOR);
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("vendetta_mark","pker");
        set("reward_npc", 1);
        set("difficulty", 35);
        set("str", 60);
        set("gender", "女性");
        set("cor", 26);
        set("max_kee",100000);
        set("max_gin",100000);
        set("max_sen",100000);
        set("max_mana",1000);
        set("mana",1000);
        set("cps", 25);
        set("agi", 40);
        set("combat_exp", 6000000+random(4000000));
        set("chat_chance", 30);
        set("chat_msg", ({
        (: random_move :)
        }) );
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                "你突然感觉到了死的滋味．．．\n",
                (: cast_spell, "freeze" :),
        }) );
        set_skill("unarmed", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));
        set_skill("spells",100);
        set_skill("mapo",200);
        map_skill("spells","mapo");
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/move", 100);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: cast_spell, "freeze" :),
        }) );
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
} 
void init()
{
        object ob;
        ::init();
        if(userp(ob = this_player()) && ob->query("vendetta/pker") && !ob->query("disable_type"))
        {
                message_vision( HIW "$N双手一聚，形成一团奇冷的寒气，向$n射来！\n
奇冷的寒气包围了$n的全身，将$n凝聚成冰块！\n"NOR, this_object(), ob);
//              ob->delete("max_force");
                ob->set_temp("disable_inputs",1);
                ob->set("disable_type",HIW "<冻僵中>"NOR);
                ob->set_temp("is_unconcious",1);
                seteuid(ROOT_UID);
                ob->start_call_out( (: call_other, __FILE__, "remove_frozen",ob:), 
                random(20)+20);
                ob->kill_ob(this_object());
                kill_ob(ob);
        }
} 
void remove_frozen(object me)
{
   me->delete("disable_type");
   me->delete_temp("disable_inputs");
   me->delete_temp("is_unconcious");
   if(!me->is_ghost())
   message_vision(HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n"NOR, me);
}        
