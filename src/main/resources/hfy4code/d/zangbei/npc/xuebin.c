#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC; 
//inherit SMART_NPC;
int kill_him(); 
void create()
{ 
        set_name("Ѧ��",({"xuebin"}));
        set("title",YEL"�ú�ׯ��ׯ��"NOR);
        set("long", "Ѧ��̧������ס�죬����ؿ����ţ��������������ϣ���Ȼ��ֻ�����Ǹ���������
���⣬�������о��У�ȴ������Ϧ�������Լ�ȴ��Ϧ�����޺õ�ʱ�ⶼ�ѹ�ȥ����
�������ѵ�����ҹ����\n");
        set("age",59);
        set("ill_boss",5);
        set("combat_exp", 5500000);
        set("attitude", "friendly");
                set("reward_npc", 1);
       set("difficulty", 20);
              set("no_busy", 9);

        set("inquiry", ([
             "������" : (: kill_him :),
        ]));
        
                set("class","knight");
        set_skill("unarmed", 180);
        set_skill("xuanyuan-axe", 200);
        set_skill("dream-herb", 220);
        set_skill("windy-steps", 150);
        set_skill("longlife-force", 200);
        set_skill("axe", 200);
        set_skill("literate", 140);
        set_skill("dodge", 140);
        set_skill("move", 140);
        set_skill("parry", 160);
        set_skill("force", 200);
        set_skill("herb", 280);
        set_skill("perception",200);
        set_skill("hanshan-strike",140);
               
          map_skill("unarmed","hanshan-strike");
          map_skill("herb","dream-herb");
          map_skill("axe","xuanyuan-axe");
          map_skill("parry","xuanyuan-axe");
          map_skill("dodge","windy-steps");
          map_skill("force","longlife-force");
        
        set("no_fly",1);
        
        //set("resistance/gin",30);
        //set("resistance/kee",50);
        //set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//         defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:perform_action,"axe.jiuqipoxiao":),
        }) );
         
        CHAR_D->setup_char(this_object());
        //auto_npc_setup("xuebin",200,180,1,"/obj/weapon/","fighter_w","xuanyuan-axe");
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/loulan/obj/axe")->wield();
}  
int kill_him()
{
        object me, another;
        
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"Ѧ������û�ջش��㡣\n");
                return 1;
                }
        message_vision(CYN"$N�������Ǵ����������£���Ȼ�����������䣬���������ص�ʮ����ǰ����
���ǻ���ͬ�����ġ���������Ϊ������ʵ�ڲ��Ǹ���������\n",this_object());
        return 1;
}     
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/Ѧ��_ma", 1);
        }
        
        ::die(); 

}
