#include <ansi.h>
inherit NPC;
inherit F_BANKOWNER;
void create()
{
        set_name("�Ϲ�ʮ����", ({ "shier" }) );
        set("title",RED"Ǯׯ����"NOR);
        set("gender", "����" );
        set("age", 22);
        set("richness",5000000);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("fly_target",1);
        set("long",
                
                "��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����Ϲ�ʮ������Ǯׯ����\n"); 
        set("combat_exp", 1000000);
        set("attitude", "friendly"); 
        set("max_atman", 1000);
        set("atman", 1000);             
        set("atman_factor", 3);
        set("max_force", 500);
        set("force", 500);             
        set("max_mana", 1000);
        set("mana", 1000);              
        set("mana_factor", 3); 
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("celestrike", 120);
        set_skill("celestial", 100);
        set_skill("chaos-steps", 120); 
        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");
        map_skill("dodge", "chaos-steps");
        
        set("inquiry", ([
                "����" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
                "rob" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
        ]) ); 
        setup();
        
        carry_object("/obj/armor/cloth")->wear();
        add_money("silver", 10);
} 
void init()
{
        ::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
        add_action("do_loan","loan");
        add_action("do_show","show");
} 
int do_show(string arg)
{
        object letter;
        object me;
        if (!arg) return 0;
        me=this_player();
        if(!objectp(letter=present(arg,me)))
                return 0;
        if(!letter->query("for_di"))
                return 0;
        if ( !me->query("libie/���_ɱ��������"))
                return 0;
        if (me->query("libie/�Ϲ�ʮ����")) {
                message_vision("$N���õ����������Ѿ������ˡ���\n",this_object());
                return 1;
                }               
        message_vision("$N��ɫ΢�䣬������ֻ�е�С��ү�������ܶ�����Щ���ӡ���\n",this_object());
        message_vision("$N��$n˵������������Ȼ��С��ү�Ѿ����ˣ���ô�������ˣ�����һ��������������ţ���Σ���\n",this_object(),me);
        destruct(letter);
        add_action("do_answer","answer");
           return notify_fail(HIY"answer(yes/no)\n"NOR);
        return 1;
} 
int do_answer(string arg)
{
        object ob, me;
        object room, money_reward;
        int i; 
        me=this_player();
        if ( !me->query("libie/���_ɱ��������"))
                return 0;
        
        if (arg=="no")
        {
                message_vision(HIW"�Ϲ�ʮ����΢Ц�Ķ�$N˵�����������������,�ҶԴ���һ����֪����\n"NOR,me);
                remove_action("do_answer","answer");
                if (!me->query("libie/�Ϲ�ʮ����")){
                        me->add("score",500);
                        me->set("libie/�Ϲ�ʮ����",1);
                        }
                return 1;
        }
        if (arg=="yes")
        {
                message_vision(HIB"�Ϲ�ʮ���������Ķ�$N˵��������,��,������֪��֪,��֪��֪����\n"NOR,me);
                remove_action("do_answer","answer");
                if (!me->query("libie/�Ϲ�ʮ����")){
                        money_reward = new("/obj/money/tenthousand-cash");
                        money_reward ->move(me);
                        me->set("libie/�Ϲ�ʮ����",1);
                        message_vision(HIB"�Ϲ�ʮ��������$Nһ����Ʊ.\n"NOR,this_player());
                        }
                return 1;
        }
        return 0;
}      
