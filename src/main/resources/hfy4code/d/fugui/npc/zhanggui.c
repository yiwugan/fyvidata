 inherit NPC;
#define MONEY_VALUE 300000
#include <ansi.h> 
void create()
{
        set_name("韩掌柜", ({ "han zhanggui","zhanggui","han" }) );
        set("nickname","一阵风");
        set("gender", "男性" );
        set("age", 54);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("long",
"一个胖子，很难想象他当年能行走江湖，更不要说做什么有来头的江\n湖人了。\n"); 
        set("combat_exp", 10000);
        set("no_arrest",1);
        set("inquiry", ([
                "抢劫" : "唉！这群山西匪真厉害！来无影，去无踪！\n",
                "rob" : "唉！这群山西匪真厉害！来无影，去无踪！\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
} 
void init()
{
        object  ob;
        ::init();
        ob = this_player();
        call_out("greeting", 1, ob);
} 
int greeting(object ob)
{       
        if (random(100)>70 )
        {
        if(NATURE_D->get_current_day_phase() == 0)
     if ( 2>1 )
                {
                        message_vision("$N脸上浮起了一种诡异的笑容。\n",this_object(),ob);
                        command("whisper "+ob->query("id")+" 当年我一阵风韩风也是黑道上的角儿，\n如今年纪大了，就洗手不干了，不过．．．\n");
                        ob->set_temp("marks/韩掌柜耳语",1);
                        command("grin");
                        return 1; 
                }
                else 
                {
                        command("heihei");
                        command("say 小人这有好些好东西，不过么，白天实在不方便，这些\n天镇上官差也多，大爷不妨晚上来瞧瞧。");
                        return 1;
                }
        }
        else
                return 0;
} 
int accept_object(object me, object obj)
{       object hhs;
        object han;
        object room;
        
        han = this_object();
        room = environment(han);
        if (obj->query("name")=="金瓶梅") {
                message_vision("$N向$n淫笑着，＂啪＂的一声，一滴口水滴在书上。\n",han,me);
                me->set_temp("marks/金瓶梅",1);
                return 1;
        }
        if (obj->query("name")=="玉蒲团") {
                message_vision("$N向$n摇摇头，连声叹息：“玉蒲团过于粗糙，不好，不好！“\n",han,me);
                return 1;
        } 
        if(NATURE_D->get_current_day_phase() == 0) 
        if ( 2>1 )
        { 
                if( (int) obj->value() >= (MONEY_VALUE+ random(MONEY_VALUE)) && !room->query("gived") && me->query_temp("marks/韩掌柜耳语") && me->query_temp("marks/金瓶梅"))
                {
                        command("grin");
                   command("say 小人这除了叫贞洁烈女也变成淫娃荡妇的阴阳和合散，\n还有些很管用的蒙汗药,逍遥散！\n");
                        hhs = new(__DIR__"obj/hehesan");
                        if(hhs)
                        hhs->move(me);
                        room->set("gived",1);
                        message_vision("$N拿出"+HIY "阴阳和合散"NOR+"给$n。\n",this_object(),me);
                        return 1;       
                }
                else
                {
                        command("heihei");
                        command("say 多谢这位" + RANK_D->query_respect(me) +"，头一次见到象您这么大方的！");
                        return 1;
                }
        }
        else
        {
                command("heihei");
                command("say 多谢这位" + RANK_D->query_respect(me) +"，头一次见到象您这么大方的！");
                return 1;
        }
        return 0;
} 
