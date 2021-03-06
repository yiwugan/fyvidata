 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("驼子喇嘛", ({ "travel lama","lama" }) );
        set("gender", "男性" );
        set("class", "lama");
        set("age", 32);
        set("str", 25);
        set("dur",100);
        set("cor", 14);
        set("per", 4);
        set("cps", 29);
        set("int", 25);
        set("long", "树荫下坐着个歇脚的喇嘛，微驼的背，脸上布满了沙尘。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "驼子喇嘛叹了口气，揉了揉腿。\n",
                "驼子喇嘛道：“走千山，涉百滩，靠的是什么？还不就是股毅力！\n“",
                "驼子喇嘛说：“听说南方沼泽里有条恶龙，不知道谁能把它除了。“\n",                
                }) );   
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 10);
        set_skill("yoga",151);
        set_skill("dodge",50);
        set_skill("move",50);
        set_skill("unarmed",50);
        set("skill_public",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
} 
void init() {
        object ob;
        ::init();
        if(interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
   }
} 
void greeting(object ob) {
        if(!ob || environment(ob) != environment()) {
                return;
        }
        switch( random(6)){
                case 0:
                        say("驼子喇嘛叹了口气，揉了揉腿。\n");
                        break;
                case 1:
                        say("驼子喇嘛道：“走千山，涉百滩，靠的是什么？还不就是股毅力！\n“");
                        break;
                case 2:
                        say( "驼子喇嘛说：“听说南方沼泽里有条恶龙，不知道谁能把它除了。“\n");
                        break;
        }
}  
int recognize_apprentice(object ob)
{
        if(ob->query("free_learn/yoga"))
        return 1;
        else {
                if (!random(3)) {
                command ("say 在下只结交英雄好汉。\n");
                } 
                return 0;
        }
}  
int accept_object(object who, object ob)
{       
        if (ob->query("name")==HIR "火龙赤皮" NOR)
        {
                message_vision("$N两眼放出光来，“火龙赤皮！，真是你杀了那条恶龙？\n\n",this_object(),this_player());           
                if( who->query("m_success/孽龙")) 
                { 
                command("praise"+who->query("id"));
                message_vision(HIR"$N一拱手，“世路艰辛，英雄若不嫌弃，在下懂一点强身健体的秘诀可与英雄分享”\n"NOR,this_object(),this_player());
                who->set("free_learn/yoga",1);
                return 1;
           }
                else {
                        message_vision(HIW"$N嘿嘿冷笑了几声。\n"NOR,this_object(),this_player());
                        message_vision(HIW"$N说道，“世上也有如此滥竽充数之辈”\n"NOR,this_object(),this_player());
                        message_vision(HIW"“火龙赤皮我收了，你，可以走了。”\n"NOR,this_object(),this_player());
                //      command("say 世上也有如此滥竽充数之辈\n");
                //      command("say 火龙赤皮我收了，你可以走了。\n");
                return 1;
                }       
        } 
        else {
                message_vision("$N扫了一眼$n手中的东西说，“这种东西有什么用。”\n",this_object(),this_player());
                return 0;
                }
} 
