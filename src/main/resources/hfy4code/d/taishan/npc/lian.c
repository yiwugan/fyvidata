 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
int give_hint();
string sysmsg;
void create()
{
        set_name(HIG"�����"NOR, ({ "lian", "lian cheng bi", "chengbi" }) ); 
        set("gender", "����");
        set("age", 29);
        set("long",
 "һ�����ŵ����ҹ��ӣ���������ȴ�ִ��������˾��ø߲����ʵ��廪֮������Ȼ\n���ǵ�����������һ���е����䣬�޹�ɽׯ��������������Ľ�ľ�����š�\n");
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("difficulty", 10);
//      set("str", 40);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������㹰�˹��ֵ�������λӢ�ۣ�������������ĳ������ң���\n",
        }) );
        set("inquiry", ([
                "����" : (: give_hint:),
                "tianzong" : (: give_hint:) 
        ]));
        set("force", 4000);
        set("max_force", 80000);
        set("force_factor", 40);
        set("atman",1000);
        set("max_atman",1000);
        set("fly_target",1);
        set("combat_exp", 10000000);
        set_skill("unarmed", 180);
        set_skill("force", 100);
        set_skill("iron-cloth", 100);
        set_temp("apply/attack",100);
        set_temp("apply/dodge", 200);
        set_temp("apply/parry", 200);
        set_temp("apply/damage",100); 
        set("title", "�޹�ɽׯ ��ׯ��");
        set("nickname", HIR"������˫"NOR);
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        create_organization("����",1,"а");
}
int accept_fight(object me)
{
        command("say �������书���ã�����ĳ��Ӧ���㣬��ȭ�����飬��С���ˣ�");
        return 1;
}
void init()
{
	object ob;
        ::init();
        if( userp(ob = this_player()))
        if(ob->query("improbity")&&(string)ob->query("organization/org_name") == "����")
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
//      add_action("give_mission", "mission");
//      add_action("join_in","join");
}
int accept_object(object who, object ob)
{
        int  exp, pot, score, val;
        string test;
        string mission;
// Let's see if this player is one of us
        if((string)who->query("organization/org_name") != "����")
                return 0;
        val = ob->value();
        if(!(mission =  who->query("mission/name")))
        {
        tell_object(who,"�����˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
/*        if( (string)ob->query("unit")+(string)ob->query("name") != quest_tianzong)
        {
        tell_object(who,"�����˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        } */
        if( ob->is_character())
        {
        tell_object(who,"�����˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if ((int) who->query("mission_time") < time() )
        {
        tell_object(who,"�����˵�������ϧ����û����ָ����ʱ������ɣ�\n");
                        return 1;
        }
        else
        {
        tell_object(who,"�����˵�����ã����úã����ھ���Ҫ���������˲ţ�\n");
        exp = random(150) + 10;
// put a cap
        exp = exp * (int) who->query_temp("mission_number")/3;
        exp += 1;
        pot = exp / 5 + 1;
        score = 1;
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",-score);
        tell_object(who,HIW"�㱻����������ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"NOR);
//      chinese_number(score)+"���ۺ�����\n"NOR);
        who->set("mission/name", 0 );
        who->add("QUEST",1);
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
        string *npcs,*objs,file;
        int  t;
        me = this_player();
// Let's see if this player is one of us
        if((string)me->query("guild") != "����")
                return 0;
   if((int)me->query("last_good_kill") < ((int)me->query("mud_age") - 24*3600))
        {
                tell_object(me,"����赶�����Ц��˵��
���ҿ���ԡ����ڡ����������ģ�������ȥɱһ�������书�൱�ġ��ˡ��\n");
                return 1;
        } 
// Let's see if this player is a ghost
        if((int) me->is_ghost())
        {
                write("��겻��Ҫ����\n");
                return 1;
        }
        if( me->query("mission/name"))
        {
        	write("�����ڵ������ǹ���"+me->query("mission/name")+"��\n");
        return 1;
        }
// Let's see if this player still carries an un-expired task
        if((mission =  me->query("mission/name")))
        {
        if( ((int) me->query("mission_time")) >  time() )
                return 0;
        else
                me->set("kee", me->query("kee")/2+1);
                me->delete_temp("mission_number");
        }
        file = read_file("/quest/NPC");
        npcs = explode(file,"\n");
        file = read_file("/quest/OBJ");
        objs = explode(file,"\n");
        timep = random(300)+60;   //  big random factor
// A factor here to make time random
        timep = random(timep/2)+timep/2;
        time_period(timep, me);
        if(random(2))
        {
        mission = npcs[random(sizeof(npcs))];
        tell_object(me,"������ɱ��"+mission+"��\n"NOR);
        sysmsg +="ɱ��"+mission+"��";
        }
        else
        {
        mission = objs[random(sizeof(objs))];
        tell_object(me,"ȥ��"+mission+"�����ڡ�\n"NOR);
        sysmsg +="ȥ��"+mission+"��";
   }
        me->set("mission/name", mission);
//        me->add("vendetta/authority",1);
        me->set("mission_time", (int) time()+(int) timep);
        if((int)me->query_temp("mission_number") < 5)
        me->add_temp("mission_number",1);
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
int give_hint()
{
        object me,obj;
        me = this_player();
        obj = this_object();
        if(me->query("combat_exp") < 15000000)
        {
        tell_object(me,"����赵����������ڡ��ǵ��������������أ�а��İ�ᣬ���������¸�
�ɸ��֣��԰�ɱ��ʽ�������켺�������ڡ������ˣ�����������Ҳ�Ǹ������ԡ�
�����ڡ������޹ʲ�ɱ��������Ӣ�ۣ��Թ����Լ��������еĵ�λ��\n");
                return 1;
   }
        else{
           if(!me->query("����/����ʧ��")&& !me->query_temp("����/׼��ɱ�"))
           {
             tell_object(me,"����赵��������ƺ��ԡ����ڡ��ܸ���Ȥ���Ƿ�������أ�answer yes/no������\n");
             add_action("answer_lian", "answer");
           }
           else if( me->query_temp("����/׼��ɱ�") )
                 tell_object(me,"����赵����Ҹ����������û����ɰɣ�\n");
           else 
               tell_object(me,"�������Цһ����û��˵����\n");
           return 1;
        } 
}
int answer_lian(string arg)
{
	object me;
	me = this_player();
	
	if(arg == "yes" || arg == "YES")
	{
		tell_object(me,"����赶���˵������Ȼ��ˣ���ȥ�������ͷ����������
�Ҿ���������ڣ�\n");
		me->set_temp("����/׼��ɱ�",1);
		return 1;
	}
	else if(arg == "no" || arg == "NO")
	{       
		tell_object(me,"�����΢Ц�������ǿ�����ģ������ڣ��Ǽ�а����������֯��
���������ˣ����ǲ���Ź���ģ�\n");
		me->set("����/����ʧ��",1);
                return 1;
         }
         else
         {
         	tell_object(me,"����赾��������˵ʲô�����Ҳ����ף�\n");
         	return 1;
        }
}
void accept_member(object me)
{
        command("smile");
        command("enroll "+me->query("id"));
        tell_object(me,"��������������������
����ʵ�Ҿ��ǡ����ڡ����������ӽ��Ժ����Ϊ�����ڡ������ɣ��Ҿ��Բ��������ģ�
�����������Ҫ����mission��������һ��Ҫ֤������ǿ�ߣ��������ȥ����������ȡ����
(filish)��\n");
        me->delete("����/������");
        me->set("organization/org_name","����");
        me->set("organization/����","а");
        me->set("organization/org_level",0);
        CHANNEL_D->do_sys_channel("info",sprintf("%s��ĳ�����ܼ�����а����֯%s��",NATURE_D->game_time(),me->query("organization/org_name")) );
        me->save();
} 
void attempt_join(object me)
{
        if(me->query("����/������"))
           accept_member(me);
        else
        message_vision("�����΢Ц����.........\n",this_object());
}  

void greeting(object me)
{
        if(!me ||environment(me)!=environment())
                return ;
        if(!living(me))
                me->revive();
	if( me->query("improbity")>=800 && me->query("improbity") < 3000 && me->query("organization/org_level") != 5){
	   message_vision(CYN"$N����$n�ļ��˵���������ֵܣ����������������ģ�������Ϊ��֯���˲��ٹ��ͣ�\n���ｫ���㵣��һ����Ҫְ�񣬺úøɰɣ�����\n"NOR,this_object(),me);
	   me->set("organization/org_title",CYN"����"NOR);
	   me->set("organization/org_level",5);      //���˳�Ա����͵�ְ��
	   me->save();
	   tell_object(me,"��ϲ���Ϊ����"+CYN"����"NOR+"��\n");
	   CHANNEL_D->do_sys_channel("info",sprintf("��֯������%s��ĳ�˱�����Ϊ%s��%s��",NATURE_D->game_time(),me->query("organization/org_name"),me->query("organization/org_title")) );
	}
	if( me->query("improbity")>=3000 && me->query("improbity")<8000 && me->query("organization/org_level") != 4){
	   message_vision(CYN"$N����$n΢΢һЦ��Ȼ������˵������û���뵽�ֵ���˵ĸ��������ھ�����Ҫ�������ݶ�����֮�ˣ�\n���ڵ�"+RED"����׷��"NOR+"����ȱ�ţ���ȥ��ְ�ɣ���\n"NOR,this_object(),me);
	   me->set("organization/org_title",RED"����׷��"NOR);
	   me->set("organization/org_level",4);
	   me->save();
	   tell_object(me,"��ϲ���Ϊ����"+RED"����׷��"NOR+"��\n");
	   CHANNEL_D->do_sys_channel("info",sprintf("��֯������%s��ĳ�˱�����Ϊ%s��%s��",NATURE_D->game_time(),me->query("organization/org_name"),me->query("organization/org_title")) );
	   }
        return ;
}  