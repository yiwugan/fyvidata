 inherit NPC;
#include <ansi.h>
string horsedesc();
void create()
{
        set_name("黄骏马", ({ "yellow horse","horse" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 3);
       //set("long", "一匹皮毛黑亮的野马，自由自在的撒蹄飞奔着，不知是否可以驯服（ｘｕｎｆｕ）。\n");
        set("long",(: horsedesc :));
        set("max_kee", 3000);
        set("max_gin", 3000);
        set("max_sen", 3000);
                set("int",40);
        set("cor",80);
        set("str",50);
        set("attitude", "peaceful");
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "hoof"}) ); 
        set("chat_chance", 1);
        set("chat_msg", ({
                  "黄骏马＂咴～～咴咴＂地仰天长啸了几声。\n",
        }) );
        set("combat_exp", 3000000);
        set_temp("apply/attack", 300);
        set_temp("apply/dodge",300);
        set_temp("apply/armor", 100);
        set_temp("apply/damage",200);
        setup();
}
void init()
{
        add_action("do_xunfu","xunfu");
        add_action("do_ride","ride");
} 
string horsedesc()
{
        object me;
        me = this_player();
   if (me ->query_temp("marks/驯服_黄骏马"))
        {       
                return "骑上（ｒｉｄｅ）这匹骏马，你就能到达湖泊的另一边。\n";
        }
        return "一匹皮毛象缎子般光亮的野马，自由自在地撒蹄飞奔着，不知是否可以驯服（ｘｕｎｆｕ）。\n";
} 
int do_xunfu(string arg)
{
        object me;
        if (arg != "黄骏马" && arg != "yellow horse" && arg != "野马" && arg!= "horse" )
                return notify_fail("你要驯服什么？\n");
        
        me = this_player();
        if (me->query_temp("marks/驯服_黄骏马"))
                return notify_fail("这匹野马已经被你驯服了。\n");
        
        message_vision("$N长嘶一声，扬尾踏足，乱踢狂奔，硬是要把$n扔下来。。。 \n",this_object(),me);
        
        if (me->query_skill("dodge",1) >=100 && me->query_skill("animal-talk",1)>=150 && me->query_skill("animal-training",1)>=150)
        {
                message_vision(HIC"$n紧紧抓住马鬃，无论$N如何撩蹄打撅，稳如泰山般附在马背。\n "NOR,this_object(),me);
                message_vision("$N终于安静了下来，驯服地喘着粗气。。\n$n满意地拍了拍$N的头，从马上跃了下来。\n",this_object(),me);
                if (!me->query("marks/驯服_野马"))
                {
                        me->add("potential",500);
                        me->add("score",100);
                        tell_object(me,"你被奖励了：\n五百点潜能\n一百点综合评价\n\n");
                        me->set("marks/驯服_野马",1);
                }
                me->set_temp("marks/驯服_黄骏马",1);
        }else   {
                message_vision("$n终于不支，从$N背上摔了下来。\n",this_object(),me);
                me->unconcious();
        }
        return 1;
} 
int do_ride(string arg)
{
        object me,room;
        
   if (arg != "黄骏马" && arg != "yellow horse" && arg != "野马" && arg!="horse")
                return notify_fail("你要骑什么？\n");
        
        me = this_player();
        if (!me->query_temp("marks/驯服_黄骏马"))
                return notify_fail("你需要先驯服这匹烈马。\n");;
        
        message_vision(HIC"$n骑上马背，仰天长啸一声，抱紧马颈，双腿夹紧马腹，用力一鞭。。 。\n\n"NOR,this_object(),me);
        message_vision(HIW"$N凌空跃起，以一个动人心弦、超越了世间一切美态的姿势，颈后的鬃毛 
在山风中自由地飘扬，有若天马行空，在天空里划出一条美丽的弧线，再落下至 
远方的浓雾里。 \n"NOR,this_object(),me);
                if (!room=find_object(AREA_ZANGBEI"lake2")) 
                        room=load_object(AREA_ZANGBEI"lake2");
                me->move(room);
                message_vision("$N宛若神祗，乘着黄骏马从天而降。\n",me);
                message_vision("$N跃下马背，黄骏马踏风而去。\n",me);
        destruct(this_object());
        return 1;
}    
