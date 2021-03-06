#include <ansi.h>
inherit QUESTNPC;
int give_mail();
void create()
{
        set_name("薛可可", ({ "xue keke","xue" }) );
        set("nickname",HIY"月神"NOR);
        set("gender", "女性");
        set("age",19);
        set("class","quest_npc");
        set("npc_difficulty",20);
        set("organization/性质","正");
        set("combat_exp", 58000000);
        set("long","月色水波间，仿佛有  层淡淡的烟雾升起，烟雾间仿佛有一条淡
淡的人影。云开，月现，月光谈淡的照下来，恰巧照在她的脸上。
苍白的股，苍白如月。\n"
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
 "薛可可面对着黑暗的苍穹淡淡地道：“太阳是生，月是死，我相信此时
此刻，在那一座小楼的灯光下，他也一定在等待着月与死”\n",     }) );  
/*        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                        (:perform_action,"blade.yueshen-feidao":),
        }) ); */
                set("inquiry",([
                        "李坏":(:give_mail:),
                        ])      );
        setup();
        carry_object(__DIR__"obj/yueshencloth")->wear();
        carry_object(__DIR__"obj/yueshenblade")->wield();
} 
int give_mail()
{               object letter; 
                command("sigh");
                command("say 天下本来就有许多事情，有时候即使知道不对，也得做下去。");
                if(!this_object()->query("mail_given"))
                {
                        letter=new(__DIR__"obj/zhanshu");
                        message_vision("$N对$n说道：“请帮我把这封信交给李坏。”",this_object(),this_player());
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