#include <ansi.h>
inherit NPC;
inherit F_MASTER; 
void create()
{
        set_name("姜仙公", ({ "jiang xiangong", "jiang" }) );
        set("title", HIG "鹤发童颜"NOR);
        set("gender", "男性" );
        set("age", 80);
        set("str", 30);
        set("per", 25);
        set("long", @LONG
满头的华发如银丝，红润的脸膛却又婴孩一样没有一丝皱纹。
LONG
);
        set("combat_exp", 800000);
        set("attitude", "friendly");
    set("chat_chance", 1);
    set("chat_msg", ({
                "姜仙公看看四周点头道：不错，不错，灵山有仙气。\n",
                "姜仙公嘀嘀咕咕：不知道这儿有什么奇珍异宝？ \n",
    }) );
        set_skill("incarnation", 150);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("celestial", 150);
        set_skill("celestrike", 150);
        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");
        set("skill_public",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}  
int accept_fight(object me)
{
        command("say 我老人家哪里是您的对手？");
        return 0;
} 
int recognize_apprentice(object ob)
{
    if(ob->query("free_learn/incarnation"))
        return 1;
        return 0;
} 
int accept_object(object who, object ob)
{ 
        if (ob->name() == HIY"琥珀"NOR){
                message_vision("$N拿着"+ ob->name() + "仔细看了看道：“好，好，我正需此物。”\n",this_object());
                message_vision("$N转头看了看$n道：老夫无以为报，你如有意可随我学修仙术。\n", this_object(), who);
                who->set("free_learn/incarnation", 1);
                return 1;
        }
        return 0;
}   
