#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("月奴", ({ "yue nu", "yue", "nu" }));
        set("long",
            "这是一个二十五六岁的女子,似不是人间之物,\n"+
            "眼如点漆, 清秀绝俗. \n"+
            "身穿一件华贵雅致的金缕衣, 倒使她更显几分娇艳.\n"+
            "她是移花宫主亲手抚养,移花宫未来的希望.\n");
        set("title", "移花宫宫主侍女");
        set("gender", "女性");
        set("age", 20);
        set("nickname", HIR "宫主贴身侍女" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 100);
        set("int", 250);
        set("con", 100);
        set("dex", 80);

        set("kee", 4000);
        set("max_kee", 4000);
        set("sen", 4000);
        set("max_sen", 4000);
        set("gin", 2000);
    set("max_gin", 2000);
    set("force", 1000);
    set("max_force", 20000);

        set("combat_exp", 3000000);
        set("score", 200);
        set_skill("force", 150);
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("sword",150);
        set_skill("literate",100);

        set_skill("jueqing-zhang",150);
        set_skill("mingyu-shengong",150);
        set_skill("lanhua-sword",150);
        set_skill("yihua-jiemu",100);

        map_skill("unarmed", "jueqing-zhang");
        map_skill("force", "mingyu-shengong");
        map_skill("dodge", "yihua-jiemu");
        map_skill("parry", "yihua-jiemu");
        map_skill("sword","lanhua-sword");

        create_family("移花宫",2, "侍女");
        setup();
 //   carry_object("/d/yihua/obj/jinlvyi")->wear();
        carry_object("/obj/weapon/sword")->wield();
        add_money("silver",50);
}

void attempt_apprentice(object ob)
{
   if ((string)ob->query("gender")=="女性")
   {
                message_vision("月奴垂目沉思片刻, 说道：“好吧, 我就收下你了。不过你拜花奴为师的事不要到处说不然让宫主知道了就不得了了.”\n",ob);
       command("recruit " + ob->query("id"));
                if((string)ob->query("class") != "yihua")
                        ob->set("class", "yihua");
       return;}
   else
      {
                message_vision("月奴瞪着你看了半天,说道：“你还是快走吧!不然让宫主看见了我可保不了你.”\n",ob);

   if ((int)ob->query_skill("mingyu-shengong", 1) < 100) 
           {
                command("say " + RANK_D->query_respect(ob) + "是否还应该多练练明玉神功,不然让宫主知道我不能帮你!");
                return;
           }  
       return;}
}
