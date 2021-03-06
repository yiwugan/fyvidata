 // hu.c
inherit NPC;
#include <ansi.h>
int wieldblade();

void create()
{
        set_name("公孙大娘", ({ "gongsun daniang", "daniang" }) );
        set("title", HIM"卖艺女子"NOR);
        set("gender", "女性" );
        set("age", 37);
        set("str", 20);
        set("int", 40);
        set("cor", 40);
        set("per", 80);
        set("cps", 20);
    set("long",
"昔有佳人公孙氏，晚有弟子传芬芳。此女子虽然流落这穷街僻道，却依
然难掩盖她身上无端散发的风骚。她身上的彩裳鲜艳夺目，跟此间环境
丝毫不相符，仔细看来更不像普通卖艺女子。 \n"
    );
        set("force_factor", 100);
        set("combat_exp", 700000+random(3000000));
        set("attitude", "friendly");
        set_skill("move",200);
        set_skill("jianqi-dagger",180);
        set_skill("dagger",220);        
        set_skill("dodge",100);        
        set_skill("chaos-steps",160);        
        set_skill("perception", 180);
        set("skill_public",1);
        map_skill("dagger", "jianqi-dagger");
        map_skill("dodge", "chaos-steps");
        set("chat_chance", 10);
        set("chat_msg", ({
                "公孙大娘叹了口气：“难道易容这门手艺已经失传了麽。”\n",
            "公孙大娘拈花微笑说：“你能帮我找个面具么？”\n",
                (: random_move :),
        }));
        
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: wieldblade  :),
        }) );
        setup();
        carry_object("/d/fugui/npc/obj/w_skirt2")->wear();
        carry_object("/d/qianfo/npc/obj/silk")->wear();
        carry_object("/d/shanliu/npc/obj/sworddagger")->wield();
} 
/*void init(){
   ::init();
        add_action("do_look", "look");
        add_action("do_kill", "kill");
} 
int do_look(string arg) {
        if(arg == "gongsun daniang" || arg == "daniang"){
                write("昔有佳人公孙氏，晚有弟子传芬芳。此女子虽然流落这穷街僻道，却依\n");
                write("然难掩盖她身上无端散发的风骚。她身上的彩裳鲜  夺目，跟此间环境\n");
                write("丝毫不相符，仔细看来更不像普通卖艺女子。\n");
                write("她看起来约三十多岁。\n");
                write("她长的"+YEL"体态微丰"NOR+"，武功看起来好象"+HIR "深不可测"NOR+"，出手似乎极重。\n");
                write("她精神饱满，正处于巅峰状态。\n");
                write("她身穿"+RED"心字罗衣"NOR+"(Redskirt)\n");
                return 1;
        }
        return 0;
} */
int accept_object(object me, object ob){
        if (ob->query("name") == "人皮面具" ){
                if (ob->query("id") == "skinmask"){
                message_vision("$N接过"+ob->query("name")+"媚笑地说：“原来你也是同道中人……\n",
                                this_object());
                message_vision("既然如此，我们不妨交流交流。”\n", me);        
                me->set("free_learn/dagger", 1);
                return 1;
                }
                return 0;
        }
        return 0;
} 
int recognize_apprentice(object ob){
    if(ob->query("free_learn/dagger")) {
        return 1;
    } else {
        if (random(2))
        message_vision("$N对着$n拈花微笑说：“你能帮我找个面具么？”\n", 
                        this_object(), ob);
        else 
        message_vision("$N对$n鞠了个万福：“阁下见笑了，不知道阁下有什么赐教呢？”\n", 
                        this_object(), ob);             
                return 0;
    }
} 

int wieldblade()
{
command("fox");
perform_action("dagger.jianwu");
command("sing2");
return 1;
}