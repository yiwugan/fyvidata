#include <ansi.h>
inherit QUESTNPC;
int give_mail();
void create()
{
        set_name("Ѧ�ɿ�", ({ "xue keke","xue" }) );
        set("nickname",HIY"����"NOR);
        set("gender", "Ů��");
        set("age",19);
        set("class","quest_npc");
        set("npc_difficulty",20);
        set("organization/����","��");
        set("combat_exp", 58000000);
        set("long","��ɫˮ���䣬�·���  �㵭�����������������·���һ����
������Ӱ���ƿ������֣��¹�̸������������ǡ�������������ϡ�
�԰׵Ĺɣ��԰����¡�\n"
        );
        set("max_force",5000);
        set("force",5000);
        set("force_factor",150);
        set("max_kee",200000);
        set("max_gin",32000);
        set("max_sen",32000);
        set("con",40);
        set("int",27);
        set("resistance/kee",99);
        set("resistance/gin",99);
        set("resistance/sen",99);
        set_skill("move",150);
        set_skill("parry", 200);
        set_skill("blade",200);
        set_skill("dodge",150);
        set_skill("moon-blade",310);
        map_skill("dodge","moon-blade");
        map_skill("blade","moon-blade");
        map_skill("parry","moon-blade");
        set("chat_chance", 1);
        set("chat_msg", ({
 "Ѧ�ɿ�����źڰ��Ĳ�񷵭���ص�����̫���������������������Ŵ�ʱ
�˿̣�����һ��С¥�ĵƹ��£���Ҳһ���ڵȴ�����������\n",     }) );  
/*        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                        (:perform_action,"blade.yueshen-feidao":),
        }) ); */
                set("inquiry",([
                        "�":(:give_mail:),
                        ])      );
        setup();
        carry_object(__DIR__"obj/yueshencloth")->wear();
        carry_object(__DIR__"obj/yueshenblade")->wield();
} 
int give_mail()
{               object letter; 
                command("sigh");
                command("say ���±�������������飬��ʱ��ʹ֪�����ԣ�Ҳ������ȥ��");
                if(!this_object()->query("mail_given"))
                {
                        letter=new(__DIR__"obj/zhanshu");
                        message_vision("$N��$n˵����������Ұ�����Ž��������",this_object(),this_player());
                        letter->move(this_player());
                        this_object()->set("mail_given");
                }
                return 1;
} 
object offensive_target(object me)
{
        int sz;
        object *enemy; 
        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0; 
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4; 
        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}
 
void heart_beat()
{
object feidao;
object target;
if(!query_temp("weapon") && is_fighting())
{
        feidao = new("questnpc_1/obj/yueshenblade");
        feidao->move(this_object());
        command("smile");
        command("wield all");
        target = offensive_target(this_object());
        if(target)
        (CLASS_D("bandit") + "/moon-blade/yueshen-feidao")->kill_him(this_object(),target);
        return;
}else if(query_temp("weapon") && is_fighting()){
	target = offensive_target(this_object());
        if(target)
        (CLASS_D("bandit") + "/moon-blade/yueshen-feidao")->kill_him(this_object(),target);
        return;
}
else
return ::heart_beat();
} 