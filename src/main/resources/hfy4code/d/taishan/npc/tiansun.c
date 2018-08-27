 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
//int give_hint();
string sysmsg;
void create()
{
        set_name(HIG"����"NOR, ({ "tian sun", "tiansun" }) ); 
        set("gender", "����");
        set("age", 40);
        set("long",
 "\n�����ǵ��񽭺��������ص���֯�����ڡ���ͷ�죬�������źܶ��˵����ˡ�\n");
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("str", 2000);
        set("cor", 30);
        set("int", 40);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
//                "��������㹰�˹��ֵ�������λӢ�ۣ�������������ĳ������ң���\n",
        }) );
        set("inquiry", ([
//                "����" : (: give_hint:),
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
        set("title", "�޹�ɽׯ ��ׯ��");
        set("nickname", HIR"������˫"NOR);
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/taishan/npc/obj/mask")->wear();
        create_organization("����",1,"а");
}
int accept_fight(object me)
{
        command("say �ߣ���û������й���");
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
        if(me->query("organization/org_name")!="����")
         {
            tell_object(me,"������Ц�����㲻�����ڳ�Ա����ʲô�ʸ���Ҫ��������\n");
            return 1;
        }
        
        if(!me->query("mission_over")&&me->query("have_mission"))
        {
          tell_object(me,"����ҡͷ�����������û����ɡ�\n");
          return 1;
        }
        else if(!me->query("have_mission")&&!me->query("mission_over")&& !me->query("mission_fail"))
        {
            tell_object(me,"������Цһ������������֯�����������Ľ�������\n");
            return 1;
        }
        else if(me->query("mission_fail"))
        {
                tell_object(me,"����̾�������������������ޣ����ܰ�ʱ���������񰡣�\n");
        	exp = 200+random(100);
        	pot = exp /10+random(20);
        	improbity = 5;
        	me->add("combat_exp",-exp);
        	me->add("potential",-pot);
        	me->add("improbity",-improbity);       
        	tell_object(me,HIW"��ʧȥ�ˣ�\n" +
        	chinese_number(exp) + "��ʵս����\n"+
        	chinese_number(pot) + "��Ǳ��\n"NOR); 
        	tell_object(me,WHT"�����������ƺ���������������˻��ɡ�\n"NOR) ;
        	me->delete("mission");
        	me->set("mission_over",0);
        	me->set("have_mission",0);
        	me->set("mission_fail",0);
        	return 1;
        }
        else
        {
        tell_object(me,"����˵�����ã����úã����ھ���Ҫ���������˲ţ�\n");
        n = me->query("mission/difficult");    //quest�Ѷ�
        exp = n*100;
        pot = exp / 5 + 1;
        improbity = 1;
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("improbity",improbity);       //���һ����������һ��а��ֵ
        tell_object(me,HIW"�㱻����������ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"NOR);
//      chinese_number(score)+"���ۺ�����\n"NOR);
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

        if((string)me->query("organization/org_name") != "����")
                return 0;
/*   if((int)me->query("last_good_kill") < ((int)me->query("mud_age") - 24*3600))
        {
                tell_object(me,"����赶�����Ц��˵��
���ҿ���ԡ����ڡ����������ģ�������ȥɱһ�������书�൱�ġ��ˡ��\n");
                return 1;
        } */
        if((int) me->is_ghost())
        {
                write("��겻��Ҫ��֯����\n");
                return 1;
        }
        if( me->query("mission_wait") >= now_time )
        {
        	tell_object(me,"����ҡҡͷ���ƺ����ϴ���û��������񹢹��ڻ���\n");
        	return 1;
        }
        
        if(me->query("mission_fail"))
        {
        	write("����һ����֯����ʧ���ˣ���û�н�����֯�ĳͷ�(filish).\n");
        	return 1;
        }
        if(me->query("combat_exp") < 200000000)          //������200m���Ǻ�
        {
        	tell_object(me,"����΢Ц��˵��������ѭ�򽥽����ȴ�С������ʼ�ɡ�\n");
        	return 1;
        }
        
        if( me->query("mission/name") )
        {
        return 0;
	} 
        if( me->query("mission_over") )
        {
        	tell_object(me,"����΢Ц�������������񣬻�û����ȡ(filish)�����ء�\n");
        	return 1;
        }
        //���������嵥
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
        //��ɵ�ʱ��
        timep = random(300)+60;   
        timep = random(timep/2)+timep/2;
        time_period(timep, me);

        mission = npcs[random(sizeof(npcs))];
        tell_object(me,"������ɱ�ˡ�"NOR+mission+HIW"����\n"NOR);
        sysmsg +="ɱ�ˡ�"+mission+"����";
        me->set("mission/name", mission);     //����Ҫɱ���˵�����
        me->set("have_mission",1);    //�ӵ�����
        me->set("mission_over",0);    //�����Ƿ��������Ϊ����
        me->set("mission/mission_time", (int) time()+(int) timep);   //����������������ʱ��
//        me->add("vendetta/authority",1);
        me->set("mission_fail",0);
        CHANNEL_D->do_sys_channel("qst", sprintf("%s(%s)��%s",
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
        if(d) time = chinese_number(d) + "��";
        else time = ""; 
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��"; 
        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"˵����\n��" + time + "��");
        sysmsg = "��" + time + "��";
        return 1;
}
void die(){
         message_vision(HIR"$N��Ц���������ǲ����ģ���\n"NOR, this_object());
        "/cmds/imm/full"->main(this_object(),"");
}  