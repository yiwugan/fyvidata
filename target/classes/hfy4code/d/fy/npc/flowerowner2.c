 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("������", ({ "huaman" }) );
        set("gender", "����" );
        set("age", 81);
        set("title", BLU "����"NOR);
        set("long",
                "��λ�ϰ�������¶�������Ц�ݡ�\n");
        set("combat_exp", 350000);
        set("attitude", "friendly");
        set("per",20);
        set("vendor_goods", ([
                __DIR__"obj/purple_flower":30,
                __DIR__"obj/red_flower":25,
                __DIR__"obj/yellow_flower":33,
                __DIR__"obj/blue_flower":44,
                __DIR__"obj/white_flower":14,
                __DIR__"obj/black_flower":10,
        ]) );
        set_skill("unarmed",50);
        set_skill("dodge",50);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
} 
void init()
{       
        add_action("assign_delivery","deliver");        
} 
mapping *delivery = ({
        ([      "flowersender":                "��Ѱ��",
                "floweraccepter":           "��С��",
        ]),
});
//Find the First Index to have exp level >= x 
mapping query_delivery()
{
        int i;
   i = 0;
  return delivery[i];
} 
string get_flower()
{
        mapping goods;
        int i;
        string *names;
        goods = query("vendor_goods");
        names = keys(goods);
        i = sizeof(names);
        //write( names[random(i)]);
        return names[random(i)];
} 
int assign_delivery()
{
        mapping delivery;
    string dstr;
        object who;
        object flower;
    who = this_player();
        /*
        if((quest =  who->query("quest")) && (time() - who->query("task_time") < 900)) {
                return 0;d
        }
        
        if((who->query("next_time")) > time()) {
                return notify_fail(HIW"��Ҫ��" 
                                + wait_period(who->query("next_time") - time()) 
                                + "֮��ſ�Ҫ����\n"NOR);
        }
        
        combatexp = (int)who->query("combat_exp");
        if(combatexp/1024 < 100) {
          tag="_small";
        } else if(combatexp/1024 < 1000) {
          tag="_middle";
        } else {
          tag="_large";
        }
           
        quest = QUEST_D(tag)->query_quest(combatexp/1000);*/
        flower = new(get_flower());
        flower->move(who);
        delivery = query_delivery();
        who->set("delivery", delivery);
        who->set("delivery_time", (int)time());
        who->add_temp("delivery_number", 1);
        
        
        dstr = HIW"�桺" + delivery["flowersender"] + HIW"����"+ flower->name() + "��" 
                                + delivery["floweraccepter"] + HIW"�͹�ȥ��"NOR; 
        
        tell_object(who,  this_object()->name() + HIW"˵������" + dstr + "\n");
        /*
        CHANNEL_D->do_sys_channel("qst", sprintf("%s��%s(%s)%s\n",
                me["name"],
                HIW + who->name(),
                HIW + who->query("id"),
                HIW + qstr));
        */
        return 1;
}    
