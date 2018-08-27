#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("牛肉汤", ({ "niuroutang" }) );
    set("title", HIB "南海一枝花"NOR);
        set("gender", "女性" );
    set("age", 16);
    set("per", 23);
        set("long", @LONG
一个胸脯很高，腰肢很细，年纪却很小的女孩子，眼睛里充满着热情，
虽说年纪小，却是南海小港名人，凡是有点能耐的船老大无不以和她
共度春宵(enjoy)为荣。
LONG
);
    set("combat_exp", 50000);
   set("attitude", "friendly"); 
   setup();
    carry_object("/d/fugui/npc/obj/w_skirt3")->wear();
} 
int accept_fight(object me)
{
        command("say 小女子哪里是您的对手？");
        return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，别看南海小港地远人稀，但是我牛肉汤啊，\n却比千金楼那些庸脂俗粉。嘻。\n");
    if((int)obj->value() >= 50000) me->add_temp("marks/niuroutang",1);
        return 1;
} 
void init()
{
        add_action("do_enjoy","enjoy");
} 
int do_enjoy()
{
object me;
object wo;
object *inv;
int maxgin,maxkee, maxsen;
int i;
        me = this_player();
    if((int)me->query_temp("marks/niuroutang") <=0)
        {
        command("say 哎哟．．．这位" + RANK_D->query_respect(me) +
    "，您还没给赏怎么能胡来呢，当心。。");
        return 1;
        }
    me->add_temp("marks/niuroutang",-1);
message_vision(HIB"$N咯咯地笑着朝$n走过来，水蛇般的腰肢扭动着缠了上来。。\n"NOR,this_object(),me);
        me->unconcious();
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
                        destruct(inv[i]);
                }
        maxgin = (int)me->query("max_gin");
        maxkee = (int)me->query("max_kee");
        maxsen = (int)me->query("max_sen");
        me->set("eff_gin", maxgin);
        me->set("gin", maxgin);
        me->set("eff_kee", maxkee);
        me->set("kee", maxkee);
        me->set("eff_sen", maxsen);
        me->set("sen", maxsen);
        wo = new(__DIR__"obj/flower");
        wo->move(me);
        return 1;
}   
