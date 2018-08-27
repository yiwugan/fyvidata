 // Copyright (c) 1998 Apstone, Inc.
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����ľ", ({ "eagle alimu", "alimu" }) );
        set("long", "tt");
        set("nickname",HIG "˫ͷͺӥ"NOR);
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("vendetta_mark","pker");
        set("reward_npc", 1);
        set("difficulty", 35);
        set("gender", "����");
        set("str", 60);
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
                "��ͻȻ�о�����������ζ������\n",
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
        carry_object(__DIR__"obj/kacloth")->wear();
} 
void init()
{
        object ob;
        ::init();
        if(userp(ob = this_player()) && ob->query("vendetta/pker") && !ob->query("disable_type"))
        {
                message_vision( HIW "$N˫��һ�ۣ��γ�һ������ĺ�������$n������\n
����ĺ�����Χ��$n��ȫ����$n���۳ɱ��飡\n"NOR, this_object(), ob);
//              ob->delete("max_force");
                ob->set_temp("disable_inputs",1);
                ob->set("disable_type",HIW "<������>"NOR);
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
   message_vision(HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n"NOR, me);
}        
