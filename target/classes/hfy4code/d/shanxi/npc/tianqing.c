inherit NPC;
#include <ansi.h>
//int wieldblade();
 
void create()
{
        set_name("霍天青", ({ "huo tianqing", "huo" }) );
        set("title", "天禽孺子" );
        set("gender", "男性" );
        set("age", 33);
        set("str", 30);
        set("str", 99);
        set("cor", 40);
        set("cps", 1);
        set("no_busy", 99);
                 set("reward_npc", 1);
        set("difficulty", 80);

        set("class","huangshan");
            set("resistance/kee",99);
    set("resistance/sen",99);
    set("resistance/gin",99);

    set("long",
"这是个很有自信，很有判断力的人，无论做什麽事都有他自己的原则，\n他虽然很骄傲，却不想别人认为他骄傲。 \n"
    );
        set("force_factor", 100);
        set("max_force",5000);
        set("force",5000);
        set("combat_exp", 1000000+random(9000000));
        set("attitude", "friendly");
        set_skill("move",100);
        set_skill("force",100);
        set_skill("unarmed",999);
        set_skill("dodge",999);
        set_skill("throwing",999);
        set_skill("yunwu-strike",999);
        set_skill("liuquan-steps",999);
        
        //set_skill("tangforce",100);
        //set_skill("blade",180);
        //set_skill("tang-blade",180);        
        set_skill("perception", 220);
        //set("skill_public",1);
       // map_skill("throwing", "tanzhi-shentong");
        map_skill("unarmed", "yunwu-strike");
        map_skill("dodge", "liuquan-steps");
        //map_skill("force", "tangforce");
        set("chat_chance", 1);
        set("chat_msg", ({
                "霍天青的声音低沈而有力，说话时缓慢而温和。\n",
                "霍天青希望每个人都能很注意的听他说话，而且都能听得很清楚”\n",  
                //"青枫道人忽然挥袖拂乱了这局残棋，悠悠慨叹，“人生岂非，也正如一局棋．输瀛又何必太认真呢？”\n",
        }));
        //set("skill_public", 1);
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
        perform_action("unarmed.miwu"),
        perform_action("dodge.liushuichanchan"),
             //   (: wieldblade  :),
        }) );
        setup();
           carry_object("/obj/armor/cloth")->wear();

       // carry_object("/d/huashan/npc/obj/chickbone")->wield();
        
} 
/*
int wieldblade()
{
command("wield piece");
perform_action("throwing.tanzhijinghun");
command("unwield piece");
return 1;
}*/
