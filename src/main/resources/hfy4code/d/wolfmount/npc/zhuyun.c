#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("����",({"zhu yun","zhu"}));
        set("long","�������ᣬ����ͷ��üë���ѿ�ʼ���䣬����Ҳϸ����˿��\n");
        set("nickname", BLU"�������"NOR);
        set("gender","����");
        
        set("no_arrest",1);
        set("no_heal",1);
        
        set("age",22);
        set("int",22);
        set("str",40);
        set("cor",30);
        set("per",30);
        set("cps",20);
        set("gin",3000);
        set("max_gin",2500);
        set("eff_gin",2500);
        set("gin",2500);
        
        set("max_kee",5000);
        set("eff_kee",2500);
        set("kee",2500);  
        
        set("max_sen",2500);
        set("sen",2500);    
        set("eff_sen",2500);
        
        set("combat_exp",3000000);  
        set_temp("apply/damage",200);
        set_temp("apply/armor",200);
        
        set_skill("force",200);
        set_skill("iron-cloth",200);
        set_skill("wolf-claw",200);
        set_skill("xueyeqianzong",200);
        set_skill("unarmed",200);
   set_skill("parry",150);
        set_skill("dodge",150);
         
        map_skill("dodge","xueyeqianzong");
        map_skill("unarmed","wolf-claw");
        
        set("force",10000);
        set("max_force",10000);
        set("force_factor",100);
        
        set("attitude", "friendly");
        
        set("chat_chance",1);     
        set("chat_msg",({
        "��������üͷ�������Ҹ�����Ӣ�ţ����ž��ޣ�����������ɽ��˻��Ҳ��������ǡ�����\n",
        }) );
        setup();
    if (!random(5)) add_money("thousand-cash", 1);
    carry_object(__DIR__"obj/whitecloth")->wear();
    if (!random(10)) carry_object(__DIR__"obj/zhuguo");
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
int greeting(object ob)
{
 if (random(100)>20 )
        {
        if(NATURE_D->get_current_day_phase() == 1080) 
                {
                       if (present("zhuguo",this_object()))
                       {
                                                   message_vision(HIR"$NͻȻ���ҵؿ���������\n$N̾�˿����������ǳ�ҩ��ʱ���ˡ�\n\n"NOR,this_object(),ob);
                                                   command("eat zhuguo");
                                              return 1; 
                       }
                                                
                }
                else 
                {
                        command("sigh");
                        say ("����̧ͷ������һ�ۣ��̲�ס�ֿ���������\n");
                        return 1;
                }
        }
        else
                return 0;
}
       
