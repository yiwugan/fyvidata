// waiter.c

inherit NPC;
int give_him();
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("兰绿", ({ "ying ke shizhe" }) );
        set("gender", "男性" );
        set("age", 81);
        set("title", CYN "移花宫迎客使者" NOR);
        set("long",
                "一个风情万种的女人.....\n");
        set("combat_exp", 2450000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tiannvsanhua" :),
        }) );
        set("per",30);
         set("inquiry", ([
                "移花宫" : (: give_him :),
                "yihuagong" : (: give_him :),
        ]));
        set_skill("sword", 120);
        set_skill("lanhua-sword",120);
        set_skill("yanyu-steps",120);
        set_skill("dodge",120);
         map_skill("dodge", "yanyu-steps");
          map_skill("sword", "lanhua-sword");
        setup();
        add_money("gold", 20);
        carry_object(__DIR__"obj/cq1")->wield();

}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N摇头晃脑地低吟道：真是自古英雄出少年,后生可畏呀!唉!\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N望了$n一眼,惊讶道:你什么时候过来的??\n",this_object(),ob);
                        break;
        }
}
int give_him()
{
        object me , obj;
        me = this_player();
        if( !query("given")) {
        obj = new(__DIR__"obj/baipao");
        message_vision("$N说道:这位壮士.你居然能过来.真是英雄出少年呀,于是给了$n一件白袍。\n",this_object(), me);
        obj->move(me);
        set("given",1);
        return 1;
        }
        return 0;
}

