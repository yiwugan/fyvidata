 // master.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("蓝一尘", ({ "master yichen", "master", "master lan" }) );
        set("nickname", HIC "神眼神剑"NOR);
        set("gender", "男性" );
        set("reward_npc", 1);
        set("difficulty", 40);
        set("no_heal",1);
        set("age", 54);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("per", 30);
        set("agi",25);
        set("skill_public",1);
        
        set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 50);
        
        set("max_kee",99999999);
        set("max_gin",999999);
        set("max_sen",999999);
        set("eff_kee",999999);
        set("kee",999999);
        set("combat_exp", 10000000);
        set("score", 200000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "蓝一尘神色凝重望着密林深处，一字字道：大好男儿，当浴血锄奸，\n慨然踏死，杨铮啊杨铮，你放心去吧。蓝某绝不让人踏入密林半步。\n",
        }) ); 
        set("long",
"
这个人头戴着顶宽边竹笠，戴的很低。不但盖住了眉毛挡住了眼睛，
连一张脸都隐藏在竹笠的阴影里。一条左腿已经齐膝而断。
\n"
        ); 
        create_family("蓝山剑宗", 3, "宗主");
        
        set("收信",0);
        
        set_skill("move", 120);
        set_skill("parry", 180);
        set_skill("dodge", 160);
        set_skill("force", 100);
        set_skill("literate", 120);
        set_skill("sword", 180);
        set_skill("unarmed",120);
        set_skill("sky-steps",120);
        set_skill("xiaohun-sword",160);
        set_skill("libie-sword",120);
        set_skill("xiaohun-whip",160);
        set_skill("whip",150);
        
        map_skill("dodge", "sky-steps");
        map_skill("sword", "xiaohun-sword");
        map_skill("force", "jingyiforce");
        map_skill("parry", "libie-sword");
        map_skill("whip","xiaohun-whip");  
        setup();
        carry_object(__DIR__"obj/bluesword")->wield();
        carry_object(__DIR__"obj/shirt")->wear(); 
} 
void attempt_apprentice(object me)
{
        command("shake "+me->query("id"));
        command("say 蓝某已成废人，你还是另请高明吧。。。"); 
} 
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
 
 
 
int accept_object(object who, object ob)
{
if(ob->query("name") == "给蓝一尘的信" ) {
if(query("收信")) {
        message_vision(HIY"蓝一尘“哦”了一声，“怎么又来一个送信的，难道是假冒的不成？“\n",this_object());
        return 1;
}       
if(ob->query("送信人")==who)
{
    message_vision(HIY "蓝一尘“哦”了一声，拆开信来，阅罢喟然长叹不语。稍倾，向$N点了点头，道：
阁下实为信人，如不嫌弃，将来某或可传你我所学。不过现下还有件事情想请阁下
代劳。密林木屋乃杨铮亡父故居。杨铮发妻已独守三日未出，你可购些饭菜送去。\n"NOR,this_player()); 
        who->set_temp("libie/离别钩_送信成功",1);
        set("收信",1);
        return 1;
}
else
{
    say(HIR"蓝一尘冷冷的说：你这个狄青麟的走狗，想以假信骗我，却也没那么容易。\n"NOR);
        kill_ob(who);
        return 1;
}
}
return 0;
} 
int recognize_apprentice(object ob)
{
        if(ob->query("libie/离别钩_杀死狄青麟"))
                return 1;
}  
void reset()
{
        if(query("收信")) {
                add("收信",1);
                if (query("收信")>8) set("收信",0);
        }
}      
