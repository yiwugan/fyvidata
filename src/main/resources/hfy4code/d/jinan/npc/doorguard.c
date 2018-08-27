#include <ansi.h> 
inherit NPC;
int give_guard();
void create()
{
        set_name("����", ({ "yinxian" }) );
        set("long",
                "һ�����»����Ĵ���������Ҳ���ղ������������Զ��ֶ����
��������为����ϸ�����������,��͢������������ٻ���(guard).\n"); 
        set("attitude", "heroism");
        set("title", "��͢���� ��Ʒ��������");
        set("vendetta_mark","authority");
        set("reward_npc", 1);
        set("difficulty", 10); 
        set("cor", 26);
        set("cps", 55); 
        set("combat_exp", 5000000); 
        set_skill("unarmed", 150+random(500));
        set_skill("blade", 100+random(500));
        set_skill("parry", 100+random(500));
        set_skill("dodge", 100+random(500));
        set_skill("move", 100+random(500));
        set_skill("qiusheng-blade",150);
        set_skill("liuquan-steps",150); 
        map_skill("parry","qiusheng-blade");
        map_skill("blade","qiusheng-blade");
        map_skill("dodge","liuquan-steps");
        map_skill("move","liuquan-steps"); 
        set_temp("apply/damage", 200+random(200));
        set_temp("apply/armor", 200); 
        set("chat_chance", 1);
        set("chat_msg", ({
"�����۾������Ź⣬��Ц�����������Ҷ�³������Ŵ�ѩ��ս�Ͻ���֮\n�ա������������ȴ�����з�������ʵ�����뿪���á�����\n"
        }) ); 
        set("inquiry"   ,       ([
                "����"  : (:give_guard:),
                "guard" : (:give_guard:),
                "huwei" : (:give_guard:),
                "shiwei" : (:give_guard:),
                ]) );
    setup(); 
        carry_object(__DIR__"obj/yafu")->wear();
    carry_object(__DIR__"obj/peidao")->wield();
} 
int give_guard()
{
        object me,shiwei;
        int extra,maximum,gcount,gcount1,i,j;
        
        me=this_player();
        
        if(me->query("class")!="official")
        {
                message_vision("���۶�$N˵����������ʲô��������ʲô�ʸ�Ҫ��������\n",me);
                return 1;
        }
        
        if (me->query_skill("strategy",1)<100
                || me->query_skill("leadership",1)<100) {
                message_vision("����̾�˿��������������˺��У���Դ�����ˡ���\n",me);
                message_vision("���۶�$N˵��������Ǹ����������������Ĺٶ��ˡ���\n",me);
                return 1;
        }       
                
        extra=me->query_skill("strategy",1)*me->query_skill("strategy",1);
        maximum = me->query_skill("leadership",1);
        maximum = maximum/50-1;
        if (maximum <1) maximum =0;
              
        gcount=me->query_temp("guard_count");
        if(gcount>=maximum)
        {
                message_vision("���۶�$N˵��������͢�ĵ��ƣ��㲻����ָ���ٶ��ʿ�ˡ���\n",me);
                return 1;
        } 
        if(me->query("family/master_id")!="master yue"&& me->query("marks/shiwei")+600>time()) {
                message_vision("���۶�$N˵�������������̫����ϧ��,�Ҷ�������ѵ����.��\n",me);
                message_vision("����˵������һ�������Ҫ������.��\n",me);
                return 1;
        } 
  gcount1=maximum-gcount;
        me->set("marks/shiwei",time());
        for(i=0;i<gcount1;i++)
        {
                if(me->query("sen")<150) 
                {
                        tell_object(me,"����񲻹����޷�ָ���ٶ��ʿ�ˡ�\n");
                        break;
                }
                if (me->query("family/master_id")=="master yue") {
                        if (extra>48400) extra=48400;
                        shiwei=new("/obj/npc/fighter1");
                        shiwei->invocation(me,extra/100);
                        shiwei->move(environment());
                        if (me->query("combat_exp")>2700000) {
                        if (shiwei->query("combat_exp")>me->query("combat_exp")*4/5)    
                                shiwei->set("combat_exp",me->query("combat_exp")*4/5);
                        }
                        message_vision("���۶�$N˵�������úø���"+me->query("name")+"�����ɣ���Ч��͢����\n",shiwei);
                } else
                {
                        if (extra>40000) extra=40000;
                        shiwei=new("/obj/npc/shiwei");
                        shiwei->invocation(me,extra/100);
                        shiwei->move(environment());
                        j=8-(me->query_skill("leadership",1)-100)/20;
                        shiwei->set("title", "��͢ "+chinese_number(j)+"Ʒ��������");
                        if (me->query_skill("strategy",1)>250 || me->query_skill("leadership",1)>250) 
                        {
                        	shiwei->set("title", RED"��ǰ"NOR+" һƷ��������");
                        	}
                        if (me->query("combat_exp")>2700000) {
                        if (shiwei->query("combat_exp")>me->query("combat_exp")*4/5)    
                                shiwei->set("combat_exp",me->query("combat_exp")*4/5);
                        }
                        message_vision("���۶�$N˵�������úø���"+me->query("name")+"�����ɣ�����ĺô�����\n",shiwei);
                }
                                
                me->add_temp("guard_count",1);
                me->add("sen",-50);
        }
        return 1;
}   
