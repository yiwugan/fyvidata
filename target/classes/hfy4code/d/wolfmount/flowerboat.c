#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "花舟"); 
        set("long", @LONG
小小的舟上，堆满了鲜花，各式各样的鲜花，从远山采来的鲜花。风中这花舟
轻轻地荡漾着，就象是梦中的花，风中的雾，水中的月，似乎能看见，却永远捉不
住。满舟鲜花中一个完全赤裸的美丽女人安谧而宁静地睡着。
LONG); 
        set("type","indoors");
        set("outdoors", "wolfmount");
        set("exits",([
                "out":__DIR__"sunlake",
        ]) );
        set("objects",([
                __DIR__"npc/xiaolin":1,
                __DIR__"npc/liangyu":1,
                __DIR__"npc/laopi":1,
                __DIR__"obj/flower1":1,
                __DIR__"obj/flower2":1,
                __DIR__"obj/flower3":1,
                __DIR__"obj/flower4":1,
                __DIR__"obj/flower5":1,
        ]) ); 
        set("coor/x",-800);
        set("coor/y",-800);
        set("coor/z",60);
        setup();
} 
int kill_notify(object npc, int k)
{
        int i,j;
        object me,xiaoma,laopi;
        xiaoma=present("xiao ma",this_object());
        me = this_player();
        {
                if ( xiaoma && me->query_temp("marks/wolf_xiaoma_good") )
                {
                        npc->set("force_factor",20);
                   npc->set("chat_chance_combat", 20);
                        message_vision(HIR"$N对著$n喝道：「臭贼！今日不是你死就是我活！」\n"NOR,me,npc);
                        me->kill_ob(npc);
                        npc->kill_ob(me); 
                        message_vision(HIY"$N也突然冲向$n，连续攻出数拳！！\n"NOR,xiaoma,npc);
                        npc->start_busy(3);
                        j=random(3)+2;
                        for (i=0;i<=j;i++)
                        {
                                COMBAT_D->do_attack(xiaoma, npc, query_temp("weapon"));
                        }
                        xiaoma->kill_ob(npc);
                        npc->kill_ob(xiaoma);
                }
                else if (me->query_temp("marks/wolf_xiaoma_normal") && me->query_temp("marks/wolf_laopi_friend"))
                {
                        message_vision(HIR"$N对著$n喝道：「臭贼！今日不是你死就是我活！」\n"NOR,me,npc);
                        me->kill_ob(npc);
                        npc->kill_ob(me);
                        if (laopi = present("laopi",this_object()))
                        {
                                call_out("laopistory",20+random(40),laopi,npc,me);
                        }
                }
                else 
                {
                        message_vision(HIR"$N对著$n喝道：「臭贼！今日不是你死就是我活！」\n"NOR,me,npc);
                        me->kill_ob(npc);
                        npc->kill_ob(me);
                        return 1;
                }
        }
        return 0;
} 
void goodresult_notify(object me,object xiaolin,int i)
{
        object xiaoma;
        if(living(xiaolin) && me->query_temp("marks/wolf_xiaoma_good"))
        {
                message_vision(HIW"$N突然嘤咛一声，苏醒过来......：这是什么地方？\n"NOR,xiaolin);
           if(!xiaolin->query("xiaoma_died") && xiaoma = present("xiao ma", this_object()))
                {
                        xiaolin->set("nickname","娇娇弱弱");
                        call_out("goodevent",4,xiaoma,xiaolin,me,1);
                }
                else if (xiaolin->query("xiaoma_died"))
                {
                        xiaolin->set("nickname","楚楚可怜");
                        call_out("badevent",4,xiaolin,me,1);
                }
        }
        else if(living(xiaolin) && me->query_temp("marks/wolf_xiaoma_normal"))
        {
                xiaolin->set("nickname","出水芙蓉");
                call_out("normalevent",4,xiaolin,me,1);
        }
} 
void normalresult_notify(object me,object xiaolin,int i)
{ 
        if(living(xiaolin))
        {
                message_vision(HIW"$N突然嘤咛一声，苏醒过来......：这是什么地方？\n\n"NOR,xiaolin);
                xiaolin->set("nickname","娇娇弱弱");
                if(!me->query("m_success/义助小马"))
                {
                        me->set("m_success/义助小马",1);
                        me->add("score",200);
                }
                me->delete_temp("marks/wolf_xiaoma_normal");
        }
} 
void goodevent(object xiaoma,object xiaolin,object me,int i)
{
        switch(i)
        {
        case 1: 
                message_vision(HIR"$N激动地搂住$n，哽噎着说不出话来。\n\n"NOR,xiaoma,xiaolin);
                break;
        case 2:
                message_vision(HIR"$N向$n抱拳道谢：多谢英雄仗义相救。他日江湖相遇，当把盏千杯，不醉不归！\n\n"NOR,xiaoma,me);
           break;
        case 3:
                message_vision(HIY"$N一把抱起$n，纵出花舟。。。\n\n"NOR,xiaoma,xiaolin);
                if(!me->query("m_success/义助小马"))
                {
                        me->set("m_success/义助小马",1);
                        me->add("score",500);
                }
                        me->delete_temp("marks/wolf_xiaoma_good");
                destruct(xiaoma);
                destruct(xiaolin);
                return;
        }
        i=i+1;
        call_out("goodevent",4,xiaoma,xiaolin,me,i);
} 
void badevent(object xiaolin,object me,int i)
{
        switch(i)
        {
        case 1:
                message_vision(HIC"$N突然惊呼一声，眼泪夺眶而出,低头不语。！\n\n"NOR,xiaolin);
                break;
        case 2:
                message_vision(HIC"$N向$n浅施一礼：“多谢英雄搭救。我要去找小马了！”\n\n"NOR,xiaolin,me);
                break;
        case 3:
                message_vision(HIC"$N喃喃道：“小马，小马！为什么，你要抛开我？我...我...我...想你。”\n\n"NOR,xiaolin);
                break;
        case 4:
                message_vision(HIY"$N回眸一笑，转身转身跃入湖中......风轻吹，一点涟漪逐渐消失在湖面。\n\n"NOR,xiaolin);
                if(!me->query("m_success/义助小马"))
                {
                        me->set("m_success/义助小马",1);
                        me->add("score",300);
                }
                        me->delete_temp("marks/wolf_xiaoma_good");
                destruct(xiaolin);
                return;
        }
   i=i+1;
        call_out("badevent",4,xiaolin,me,i);
} 
void laopistory(object laopi,object npc,object me){
        object grass;
        if(!objectp(npc))
        {
                return;
        }
        message_vision(HIR"\n\n$N微微抬了抬头看了$n一眼，突然扑上去抱住太阳使者，向湖中滚去......\n\n"NOR,laopi,me);
        grass = new(__DIR__"npc/obj/grass");
        grass->move(this_object());
        message_vision(HIR"$N听到$n滚入湖水前说的最后两句话：\n         “你把我当朋友，我不能让你丢人。”\n"NOR,me,laopi);
        destruct(laopi);
        destruct(npc);
        
        if (present(me,this_object())) {
        if(!me->query("m_success/老皮友情"))
        {
                me->set("m_success/老皮友情",1);
                me->add("score",100);
        }
        if(me->query_temp("marks/拜朱五太爷")){
                        me->delete_temp("marks/拜朱五太爷");
                        me->set("m_success/狼山灭奸",1);
        }
        }
}
/*
void reset()
{
        object item;
        ::reset();
        if (!present("begonia",this_object()))
        {
                item = new(__DIR__"obj/flower1");
                item->move(this_object());
        }
        if (!present("gardenia",this_object()))
        {
           item = new(__DIR__"obj/flower2");
                item->move(this_object());
        }
        if (!present("daisy",this_object()))
        {
                item = new(__DIR__"obj/flower3");
                item->move(this_object());
        }
        if (!present("hyacinth",this_object()))
        {
                item = new(__DIR__"obj/flower5");
                item->move(this_object());
        }
        if (!present("lily",this_object()))
        {
                item = new(__DIR__"obj/flower4");
                item->move(this_object());
        }
}
*/     
