 // Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("王虎", ({ "wanghu" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long","一个身形高大的汉子\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_train", "train"); 
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "王虎说道：这位" + RANK_D->query_respect(ob)
                                + "，让它和我对打（train），我在你钱庄划帐？\n");
                        break;
                case 1:
                        say( "王虎笑道：这位" + RANK_D->query_respect(ob)
                                + "，放心！伤不到它的！\n"); 
                        break;
        }
} 
int do_train(string arg)
{
        object me,pet;
        int cost;
        int gold;
        me = this_player();
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
        if(!arg) return notify_fail("王虎道：＂你要什么呀？＂\n");
        pet = present(arg,environment());
        if(!objectp(pet)) return notify_fail("王虎道：＂你要什么呀？＂\n");
        if(pet->query("possessed") != me )
        return notify_fail("王虎道：＂那好象不是你的吧？＂\n");
//okey we identified the target, now the cost:
        cost = to_int(sqrt(to_float((int)pet->query("combat_exp"))))/5;
        gold = (int)me->query("deposit")/10000;
//        if(!gold) return notify_fail("你身上没有金子。\n");
        if(gold < cost)
        return notify_fail("你钱庄里不够"+chinese_number(cost)+"两金子。\n");
        if((int)me->query("score") < cost)
        return notify_fail("你的评价不够"+chinese_number(cost)+"点。\n");
        pet->add("combat_exp",cost*50);
        pet->save();
        me->add("deposit", -cost*10000);
        me->add("score",-cost);
        me->save();
        tell_object(me,"王虎笑道：这次用掉你"+chinese_number(cost)+"两金子，我直接在你的钱庄划帐。\n");
        command("say 好了！下次再打！\n");
        return 1;
}   
