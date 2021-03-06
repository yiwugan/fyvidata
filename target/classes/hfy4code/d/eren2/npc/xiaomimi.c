#include <ansi.h>
inherit SMART_NPC;
void special_smart_fight(); 
void create()
{
        set_name("萧咪咪",({"xiao mimi"}));
        set("title",HIM"迷死人不偿命"NOR);
        set("long", "一个轻衫绿裙、鬃边斜插着朵茶花的少妇，她步履是那么婀娜，腰肢是
那么轻盈。\n"); 
        set("age",30);
        set("attitude", "aggressive");
        set("combat_exp", 20000000);
        set("dungeon_npc","eren2");
        set("class","huashan"); 
        set("max_atman", 20000);
        set("atman", 20000);
        set("max_mana", 20000);
        set("mana", 20000);
        set("max_force",30000);
        set("force",30000);
        set("force_factor",100);
        set("no_busy",100);
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set_skill("sword",250);
        set_skill("dodge",300);
        set_skill("move",300);
        set_skill("parry",300);
        set_skill("unarmed",300);
        set_skill("qingfeng-sword",200);
        set_skill("force",200);
        set_skill("hanmei-force",200);
        set_skill("anxiang-steps",200);
        set_skill("zhaixin-claw",200);
        
        map_skill("parry","qingfeng-sword");
        map_skill("sword","qingfeng-sword");
        map_skill("dodge","anxiang-steps");
   map_skill("move","anxiang-steps");
        map_skill("unarmed","zhaixin-claw");
        map_skill("force","hanmei-force");
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: special_smart_fight() :),    
        }) );
        
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/sword")->wield();
} 
void special_smart_fight() {
        
        object me, *enemy, owner,victim;
        int num,i;
        string msg;
        
        me=this_object();
        enemy=me->query_enemy();
        if (!random(100)) {
                for (i=0;i<sizeof(enemy);i++) {
/*                      if (!userp(enemy[i])) { 
                                if(owner=enemy[i]->query("possessed")) {
                                        victim = owner;
                                        }
                        } else victim = enemy[i];*/
                        victim=enemy[i];
                        if (!victim) continue;
                   if (environment(victim)!=environment(me)) continue;
                        msg = HIW "$n面色变得惨白如纸，双手提起，指尖发出莹莹的光芒。 
$n忽然用一种奇幻的身法闪到$N面前，双爪电击般抓向$N心口！ \n"NOR;
                        msg += RED"\n\n$N"RED"用不可置信的眼光看着自己心口的血洞，身子一晃，倒在地上。 \n" NOR;
                        victim->receive_wound("kee", victim->query("max_kee")+300000,me);
                        message_vision(msg, victim, me);
                        return;
                }
        }
        if (!random(10)) {
                message_vision(HIM"$N突然停下手来凄然一笑，“你们要杀我，我也没办法。\n"NOR,me);
                for (i=0;i<sizeof(enemy);i++) {
                        if (random(enemy[i]->query("cps"))<20){
                                enemy[i]->start_busy(2);
                                message_vision(WHT"$N望着$n，不由得痴了。\n"NOR,enemy[i],me);
                }
                }
                message_vision(CYN"$N轻叹道：“我生来就是这样，只知替别人着想，替别人做事，自
己也没法子。”\n"NOR,me);
                return;
        }
        if (!random(10)) {
                message_vision(
                
                HIG"\n$N停住了手，用飘飘的眼光温柔地瞧着你，媚眼如丝，巧笑盈盈 ...\n\n"NOR
                WHT"$N缓缓将手前伸，这只手纤细、柔美，而毫无瑕疵，带着种凄秘的妖艳之气。\n\n\n" NOR, me);
                for (i=0;i<sizeof(enemy);i++) {
                        if (random(enemy[i]->query("cor"))<30){
                                enemy[i]->receive_damage("sen", random(3000));
                                enemy[i]->receive_damage("kee", random(1000));
                                message_vision(RED"$N心头如针刺般剧痛，幽幽寒气渗入血脉。\n"NOR,enemy[i]);
                        }
                }
        }
        return;
}     
