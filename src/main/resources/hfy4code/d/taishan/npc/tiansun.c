 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
//int give_hint();
string sysmsg;
void create()
{
        set_name(HIG"天孙"NOR, ({ "tian sun", "tiansun" }) ); 
        set("gender", "男性");
        set("age", 40);
        set("long",
 "\n天孙是当今江湖中最神秘的组织〖天宗〗的头领，他掌握着很多人的命运。\n");
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("str", 2000);
        set("cor", 30);
        set("int", 40);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
//                "连城璧向你拱了拱手道：＂这位英雄，今朝相遇，我连某深感荣幸！＂\n",
        }) );
        set("inquiry", ([
//                "天宗" : (: give_hint:),
//                "tianzong" : (: give_hint:) 
        ]));
        set("force", 4000);
        set("max_force", 80000);
        set("force_factor", 500);
        set("atman",1000);
        set("max_atman",1000);
        set("combat_exp", 100000000);
        set_skill("unarmed", 500);
        set_skill("force", 500);
        set_skill("iron-cloth", 200);
        set_skill("dodge",500);
        set_skill("yiqiforce",100);
        map_skill("force","yiqiforce");
        map_skill("iron-cloth","yiqiforce");
        map_skill("unarmed","yiqiforce");
        set_temp("apply/attack",100);
        set_temp("apply/dodge", 200);
        set_temp("apply/parry", 200);
        set_temp("apply/damage",100); 
        set("title", "无垢山庄 少庄主");
        set("nickname", HIR"侠义无双"NOR);
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/taishan/npc/obj/mask")->wear();
        create_organization("天宗",1,"邪");
}
int accept_fight(object me)
{
        command("say 哼！我没有这等闲功夫");
        return 0;
}
void init()
{
      add_action("give_mission", "mission");
      add_action("filish_mission","filish");
//     add_action("join_in","join");
}
int filish_mission()
{
        int  exp, pot, improbity;
        int n=0;
        object me;
        string mission;
        
        me=this_player();
        if(me->query("organization/org_name")!="天宗")
         {
            tell_object(me,"天孙冷笑道：你不是天宗成员，有什么资格来要奖励！！\n");
            return 1;
        }
        
        if(!me->query("mission_over")&&me->query("have_mission"))
        {
          tell_object(me,"天孙摇头道：你的任务还没有完成。\n");
          return 1;
        }
        else if(!me->query("have_mission")&&!me->query("mission_over")&& !me->query("mission_fail"))
        {
            tell_object(me,"天孙冷笑一声道：不做组织任务哪里来的奖励？！\n");
            return 1;
        }
        else if(me->query("mission_fail"))
        {
                tell_object(me,"天孙叹气道：看来你能力有限，不能按时完成这个任务啊！\n");
        	exp = 200+random(100);
        	pot = exp /10+random(20);
        	improbity = 5;
        	me->add("combat_exp",-exp);
        	me->add("potential",-pot);
        	me->add("improbity",-improbity);       
        	tell_object(me,HIW"你失去了：\n" +
        	chinese_number(exp) + "点实战经验\n"+
        	chinese_number(pot) + "点潜能\n"NOR); 
        	tell_object(me,WHT"看起来天孙似乎对你的能力产生了怀疑。\n"NOR) ;
        	me->delete("mission");
        	me->set("mission_over",0);
        	me->set("have_mission",0);
        	me->set("mission_fail",0);
        	return 1;
        }
        else
        {
        tell_object(me,"天孙说道：好！做得好！天宗就需要你这样的人才！\n");
        n = me->query("mission/difficult");    //quest难度
        exp = n*100;
        pot = exp / 5 + 1;
        improbity = 1;
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("improbity",improbity);       //完成一个任务，增加一个邪恶值
        tell_object(me,HIW"你被〔天孙〕奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"NOR);
//      chinese_number(score)+"点综合评价\n"NOR);
        me->delete("mission");
        me->set("mission_over",0);
        me->set("have_mission",0);
        me->set("mission_fail",0);
        me->add("QUESTNPC",1);
        return 1;
        }
                return 1;
}
int give_mission(string arg)
{
        string mission ;
        object me;
        int j, combatexp, timep, lvl=0;
        mixed *local;
        string *npcs,file;
        int  t;
        int now_time;
        now_time = (int)time();
        me = this_player();

        if((string)me->query("organization/org_name") != "天宗")
                return 0;
/*   if((int)me->query("last_good_kill") < ((int)me->query("mud_age") - 24*3600))
        {
                tell_object(me,"连城璧对你阴笑着说：
＂我看你对〔天宗〕并不很忠心，除非你去杀一个和你武功相当的「人」物＂\n");
                return 1;
        } */
        if((int) me->is_ghost())
        {
                write("鬼魂不可要组织任务．\n");
                return 1;
        }
        if( me->query("mission_wait") >= now_time )
        {
        	tell_object(me,"天孙摇摇头，似乎对上次你没有完成任务耿耿于怀。\n");
        	return 1;
        }
        
        if(me->query("mission_fail"))
        {
        	write("你上一个组织任务失败了，还没有接受组织的惩罚(filish).\n");
        	return 1;
        }
        if(me->query("combat_exp") < 200000000)          //先设置200m，呵呵
        {
        	tell_object(me,"天孙微笑地说到：还是循序渐进，先从小的任务开始吧。\n");
        	return 1;
        }
        
        if( me->query("mission/name") )
        {
        return 0;
	} 
        if( me->query("mission_over") )
        {
        	tell_object(me,"天孙微笑道：你刚完成任务，还没有领取(filish)奖赏呢。\n");
        	return 1;
        }
        //加入任务清单
        switch( random(2) ) {
                case 0:
        		file = read_file("/quest/NPC_0");
        		npcs = explode(file,"\n");
        		me->set("mission/difficult",1);
        		break;
                case 1: 
                        file = read_file("/quest/NPC_1");
                        npcs = explode(file,"\n");
                        me->set("mission/difficult",2);
                        break;
                        }
        //完成的时限
        timep = random(300)+60;   
        timep = random(timep/2)+timep/2;
        time_period(timep, me);

        mission = npcs[random(sizeof(npcs))];
        tell_object(me,"替天宗杀了【"NOR+mission+HIW"】。\n"NOR);
        sysmsg +="杀了【"+mission+"】。";
        me->set("mission/name", mission);     //输入要杀的人的名字
        me->set("have_mission",1);    //接到任务
        me->set("mission_over",0);    //任务是否完成设置为“否”
        me->set("mission/mission_time", (int) time()+(int) timep);   //设置完成任务的最终时间
//        me->add("vendetta/authority",1);
        me->set("mission_fail",0);
        CHANNEL_D->do_sys_channel("qst", sprintf("%s(%s)：%s",
        me->query("name"),me->query("id"),sysmsg)); 
return 1;
} 
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t; 
        if(d) time = chinese_number(d) + "天";
        else time = ""; 
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒"; 
        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"说道：\n在" + time + "内");
        sysmsg = "在" + time + "内";
        return 1;
}
void die(){
         message_vision(HIR"$N冷笑道：天孙是不死的！！\n"NOR, this_object());
        "/cmds/imm/full"->main(this_object(),"");
}  