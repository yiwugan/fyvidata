 // hu.c
inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name("胖公子", ({ "fat man", "man" }) );
        set("gender", "男性" );
        set("age", 32);
        set("str", 30);
        set("int", 40);
        set("cor", 40);
    set("long",
"凉棚下坐着个人，这个人不但胖，而且胖得奇蠢无比，不但蠢，而且蠢得俗
不可耐，看起来简直就像是块活动的肥猪肉，穿着打扮却像是个暴发户，好像
恨不得把全副家当都带出来，好像生怕别人不知道他有钱。 \n"
    );
        set("force_factor", 100);
        set("combat_exp", 7000000+random(3000000));
        set("attitude", "friendly");
        set_skill("move",100);
        set_skill("perception", 150);
        set("chat_chance", 1);
        set("chat_msg", ({
                "胖公子愁眉苦脸的叹着气，道：“再这么样瘦下去，怎么得了呢？”\n",
                "胖公子忽然长长叹了口气，道：“我知道最近我一定又瘦了，而且瘦了不少。”\n",  
                "胖公子用一双又白又嫩，保养得极好的手，拿起一个馒头，带着种充满爱怜
的表情，看着馒头里夹着的五花肉，然后一口咬下去。\n",
        }));
        set("skill_public", 1);
        setup();
        carry_object(__DIR__"obj/fatcloth")->wear();
        carry_object("/obj/armor/boots")->wear();
        carry_object(__DIR__"obj/mantou");
} 
void init(){
        ::init();
        add_action("do_look", "look");
} 
int do_look(string arg) {
   if(arg == "fat man" || arg == "man"){
                write("凉棚下坐着个人，这个人不但胖，而且胖得奇蠢无比，不但蠢，而且蠢得俗\n");
                write("不可耐，看起来简直就像是块活动的肥猪肉，穿着打扮却像是个暴发户，好像\n");
                write("恨不得把全副家当都带出来，好像生怕别人不知道他有钱。\n");
                write("他看起来约三十多岁。\n");
                write("他长的不胖不瘦，武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。\n");
                write("他精神饱满，正处于巅峰状态。\n");
                write("他身穿"+BLU"绸缎袍"NOR+"(Silk cloth)\n");
                return 1;
        }
        return 0;
} 
int accept_object(object me, object ob){
        if(ob->query("food_remaining")){
                message_vision("$N接过" + ob->name()+"仔细的吃了进去，然后满意的叹了口气。\n", this_object());
                if(ob->query("name") == YEL"叫花子鸡"NOR){
                        message_vision("$N幽幽的叹了口气道：“\n", this_object());
                }
                return 1;
        }
        if(ob->query("id") == "piece" && ob->query("name") == "白棋子" ){
                message_vision("$N用白嫩的手接过"+ob->query("name")+"点头叹道：“不错，不错，中原的暗器也算见识了一番。\n",
                                this_object());
                message_vision("$N如果愿意可以随我学习听风辨器之术。”\n", me); 
                me->set("fear_learn/perception", 1);
                return 1;
        }
        return 0;
} 
int recognize_apprentice(object ob){
    if(ob->query("free_learn/perception")) {
        return 1;
    } else {
        message_vision("$N笑眯眯的对$n说道：“你一天能吃五只鸡吗？那叫花子鸡的味道真不错。\n", 
                        this_object(), ob);
                return 0;
    }
}      
