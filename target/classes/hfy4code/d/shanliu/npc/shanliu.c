 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
//int give_hint();
string sysmsg;
void create()
{
        set_name(WHT"������"NOR, ({ "mysterious man", "man" }) ); 
        set("gender", "����");
        set("age", 40);
        set("long",
 "\n����������ɽ����������û����֪��������ʵ��ݺ�������\n");
        set("attitude", "peaceful");
        set("quest_npc", 1);
        set("npc_difficulty", 10);
        set("str", 2000);
        set("cor", 30);
        set("int", 40);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );
        set("inquiry", ([
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
        set("title", "ɽ�� ����");
        set("nickname", HIR"ƽ������"NOR);
        setup(); 
        carry_object("/obj/armor/cloth")->wear();
        create_organization("ɽ��",1,"��");
}
int accept_fight(object me)
{
	command("smile");
        command("say ��������æ�����в��㡣");
        return 0;
}
void init()
{
      add_action("give_mission", "mission");
      add_action("filish_mission","filish");
}
int filish_mission()
{
        int  exp, pot, justice;
        int n=0;
        object me;
        string mission;
        
        me=this_player();
        if(me->query("organization/org_name")!="ɽ��")
         {
            tell_object(me,"������΢Ц������ɽ���ĵ�������Ȼ���ţ����Ǳ���֯���»��ֲ���������������\n");
            return 1;
        }
        
        if(!me->query("mission_over")&&me->query("have_mission"))
        {
          tell_object(me,"������ҡͷ�����������û����ɡ�\n");
          return 1;
        }
        else if(!me->query("have_mission")&&!me->query("mission_over")&& !me->query("mission_fail"))
        {
            tell_object(me,"����������ֵ���������������������ֺ���Ҳ�����ˣ�û����������ȡ������\n");
            return 1;
        }
        else if(me->query("mission_fail"))
        {
                tell_object(me,"������̾�������������������ޣ����ܰ�ʱ���������񰡣�\n");
        	exp = 200+random(100);
        	pot = exp /10+random(20);
        	justice = 5;
        	me->add("combat_exp",-exp);
        	me->add("potential",-pot);
        	me->add("justice",-justice);       
        	tell_object(me,HIW"��ʧȥ�ˣ�\n" +
        	chinese_number(exp) + "��ʵս����\n"+
        	chinese_number(pot) + "��Ǳ��\n"NOR); 
        	tell_object(me,WHT"�������������ƺ���������������˻��ɡ�\n"NOR) ;
        	me->delete("mission");
        	me->set("mission_over",0);
        	me->set("have_mission",0);
        	me->set("mission_fail",0);
        	return 1;
        }
        else
        {
        tell_object(me,"������˵�����ã����úã�ɽ���Ϳ�������Щ���ֵ������ˣ�\n");
        n = me->query("mission/difficult");    //quest�Ѷ�
        exp = n*100;
        pot = exp / 5 + 1;
        justice = 1;
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("justice",justice);       //���һ����������һ��а��ֵ
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

        if((string)me->query("organization/org_name") != "ɽ��")
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
        	tell_object(me,"������ҡҡͷ���ƺ��������������֯����ʧ�ܲ��á�\n");
        	return 1;
        }
        
        if(me->query("mission_fail"))
        {
        	write("����һ����֯����ʧ���ˣ���û�н�����֯�ĳͷ�(filish).\n");
        	return 1;
        }
        if(me->query("combat_exp") < 200000000)
        {
        	tell_object(me,"������΢Ц�����ֵܻ����ȸɵ��İɡ�\n");
        	return 1;
        }
        
        if( me->query("mission/name") )
        {
        return 0;
	} 
        if( me->query("mission_over") )
        {
        	tell_object(me,"������΢Ц�������ֵܣ�����ȡ(filish)����������һ���ɡ�\n");
        	return 1;
        }
        //���������嵥
        switch( random(3) ) {
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
                case 2:
                	file = read_file("/quest/NPC_2");
                	npcs = explode(file,"\n");
                	me->set("mission/difficult",3);
                	break;                        
                        }
        //��ɵ�ʱ��
        timep = random(300)+60;   
        timep = random(timep/2)+timep/2;
        time_period(timep, me);

        mission = npcs[random(sizeof(npcs))];
        tell_object(me,"��ɽ��ɱ�ˡ�"NOR+mission+HIW"����\n"NOR);
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
        tell_object(me,HIW + sprintf("%s",this_object()->name()) +HIW"˵����\n��" + time + "��");
        sysmsg = "��" + time + "��";
        return 1;
}
void die(){
         message_vision(HIR"$N��Ц����ɽ���Ĵ�ҵδ�ɣ������᲻�����ģ���\n"NOR, this_object());
        "/cmds/imm/full"->main(this_object(),"");
}  