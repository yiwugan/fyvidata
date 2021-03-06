 // taolord.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER; 
int leave();
void create()
{
        set_name("黑带", ({ "master xman", "master", "xman" }) );
        set("nickname", HIY"护国法师"NOR);
        set("gender", "男性");
        set("age", 99);
        set("long",
"黑带是当今风云城城主阿铁的师弟，亦是当今国师，武功深不可测。\n"
);                
        set("combat_exp", 100000000);
        set("score", 50000); 
        set("class", "shaolin"); 
        set("str", 100);
        set("int", 100);
        set("cor", 100);
        set("cps", 100);
        set("spi", 100);
                set("fle",      100); 
                set("no_busy", 9);
        set("force", 88000);
        set("max_force", 88000);
        set("force_factor", 50);
                set("max_gin",28000);
                set("max_sen",28000); 
/*         set("inquiry", ([
                "太极剑法": 
"太极剑法的秘诀，就在于一个“慢”字。\n",
        ]) ); */
        set("apprentice_available", 1);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
                                    
        }) ); 
         set("rank_nogen",1);
        create_family("少林寺", 1, "圣僧"); 
        
        set("inquiry", ([
                "leave": (: leave:),
        ]) );
        
        set_skill("literate", 100);
        set_skill("force", 300);
        set_skill("move", 300);
        set_skill("unarmed", 300);
        set_skill("parry", 180);
        set_skill("dodge", 150);
        set_skill("perception", 120);
        set_skill("putiforce", 300);
        set_skill("nodust-steps", 300);
        set_skill("changquan", 350);
        set_skill("yizhichan", 300);
        set_skill("whip",200);
        set_skill("tianlongwhip",250);
        set_skill("xingyi-stick",300);
        set_skill("staff",160);
        
        map_skill("whip", "tianlongwhip");
        map_skill("staff", "xingyi-stick");
        map_skill("parry", "yizhichan");
        map_skill("dodge", "nodust-steps");
        map_skill("move", "nodust-steps");
        map_skill("force", "putiforce");
        map_skill("unarmed", "changquan"); 
        setup(); 
        carry_object("/d/shaolin/npc/obj/monk20_cloth")->wear();

} 
void attempt_apprentice(object me)
{
    if(me->query("family/master_id") != "damo")
    {
        command("heihei");
        command("say 太迟了，一切都太迟了……");
        return;
    }
    else
    {
        command("haha");
        command("say 切记！既为我徒，终身不可叛！");
        command("recruit " + me->query("id") );
        me->set("once_xman",1);
    }
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
} 
void init()
{
        object ob;
        ::init();
//        add_action("do_killing", "kill");
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
}  
void punish_betray(object ob)
{
        if( ( ob->query("once_xman")==1) && ( (ob->query("class"))!= "shaolin"))
          {      
                tell_object(ob, YEL"\n黑带冷哼:忘恩负义！！！\n"NOR);                  
                message("vision", YEL"黑带对"+ ob->name() +"怒道：“"+ ob->name() + "！ 容你不下！\n"NOR, environment(ob), ob);
                tell_object(ob, HIW"黑带一拳击在你的天灵盖上！\n"NOR);              
                message("vision", HIW"黑带一拳击在"+ ob->name() +"的天灵盖上！\n"NOR, environment(ob), ob);
                tell_object(ob, HIR"你只觉天晕地转,摇摇晃晃地倒了下去----悔不当初呀!\n"NOR);
                ob->set("title",HIW"少林叛徒"NOR);
                ob->die();
          }
}  

int leave() {
        if (this_player()->query("class")!="shaolin") return 0;
        message_vision(CYN"$N哼了一声，“背叛我也是不可以步入红尘的，既然入我门，就要付出代价！“\n"NOR, this_object());
        message_vision(CYN"$N说：若是背弃了佛祖，我看你也休想在世界上过安稳日子。\n"NOR,this_object());
        
        return 1;
}  