#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void do_bite(); 
void create()
{
        set_name("小僵尸",({"zombie"}));
        set("title","人间地狱");
        set("long","两个洞算是眼睛，一个扁平的肉瘤下两个窟窿算是鼻子和鼻孔，一道裂缝
算是嘴巴，嘴唇没有了，两排牙齿露在外面。一只手臂扭曲到背后，两条
腿一高一低，这是人还是从鬼门关上走回来的僵尸？\n"); 
        set("gender","男性");
        set("attitude", "aggressive");
        
        set("combat_exp",3000000);  
        set("age",32);
                
        set("int",40);
        set("cor",40);
        set("cps",40); 
        set_skill("unarmed",500);
        set_skill("dodge",500);
        set_skill("parry",500);
        set_skill("move",400);
        set_skill("force",400);
                        
        set("max_atman",random(500));
        set("atman",query("max_atman"));
        set("max_mana",random(500));
        set("mana",query("max_mana"));
        set("max_force",1000+random(500));
        set("force",query("max_force"));
        set("force_factor",80);
        
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                        10: name()+"喉咙里发出希里呼噜的声音：“杀。。。杀。。。！”\n",
                        70: (: do_bite() :),
        ]) );           
        set("chat_chance_combat", 100);
           set("chat_msg_combat", ({
             
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                
        }) );                   
        
        setup();
   
} 
void do_bite()
{
        object *enemy;
        message_vision(HIB"$N口中喷出一股中人欲呕的臭气，使你觉得头晕脑胀。\n"NOR,this_object());
        enemy = query_enemy();
        for(int i=0; i<sizeof(enemy); i++) {
                if( !enemy[i] ) continue;
                enemy[i]->receive_damage("sen", 100);
                COMBAT_D->report_status(enemy[i]);
        }
} 
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if (me)
        if(me->query("wanma/准备杀僵尸"))
                        me->add_temp("wanma/僵尸",1);
        message_vision("$N慢慢地倒下去消失了。\n",this_object());
        destruct(this_object());
}
        
         
