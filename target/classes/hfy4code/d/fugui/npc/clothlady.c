
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
        set_name("姬灵燕", ({ "ji lingyan", "ji" }) );
        set("gender", "女性" );
        set("age", 18);
        set("title",WHT "巧手无双"NOR);
        set("long",
"长发光亮如镜，白袍与长发随风而舞，一张苍白的脸，以及一双美丽\n而迷茫的眼睛。她有双洁白如玉的手，你很难想象就是这双手，做出\n了风云城最美丽的衣服。\n");
        set("combat_exp", 50000);
    set("str", 20);
        set("attitude", "friendly");
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set("inquiry", ([
                "钱包" : (: tell_him :),
                 ])); 

        set("vendor_goods", ([
                __DIR__"obj/m_cloth1":8,
                __DIR__"obj/g_gloves":8,
                __DIR__"obj/m_cloth2":10,
                __DIR__"obj/m_cloth3":10,
                __DIR__"obj/m_cloth4":10,
                __DIR__"obj/m_boots1":7,
                __DIR__"obj/m_boots2":8,
                __DIR__"obj/w_skirt1":8,
                __DIR__"obj/w_skirt2":8,
                __DIR__"obj/w_skirt3":8,
                __DIR__"obj/w_skirt4":10,
                __DIR__"obj/w_girth1":10,
                __DIR__"obj/w_girth2":10,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
} 
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(6) ) 
        {
                case 0:
                        say( " 姬灵燕古怪地笑了笑：这位"
                                + RANK_D->query_respect(ob)
                                + "，你有没有丢了钱包？ \n");
                        break;
                case 1:
                        say( " 姬灵燕笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，我们这些衣服的手工可是天下无双的，。。。 \n");
                        break;
                                case 2:
                        say ( " 姬灵燕笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，这里的东西绝对能让你满意。。。 \n");
                       break;
        }
} 
                                  
int tell_him()
{
    object me;
    me =this_player();
        
    tell_object(me,"姬灵燕天真地眨了眨眼睛，「我前两天在前面的山林里捡到个颇精致的钱包，如果你要，拿叁百两金子来吧。」\n");
               
    return 1;
} 

int accept_object(object who, object ob)
{
	    object obj;
                if( (int)ob->value() >= 3000000 ) {
                        say( name()+"高兴得跳了起来，然後小心地将"+ob->name()+"放入怀内。\n");
                    message_vision(NOR"$N从衣物中找出一个钱包给$n。\n\n"NOR, this_object(),this_player());

                    //    say ("\n$N从衣物中找出一个钱包给$n。\n",this_object(),this_player());�
                    obj = new(__DIR__"obj/notecase");
                    obj->move(this_player());


                        return 1;
                } else {
                        command("say 这些钱，还不够我做件像样点的衣服呢。");
                        return 0;
                }
        return 0;
}  