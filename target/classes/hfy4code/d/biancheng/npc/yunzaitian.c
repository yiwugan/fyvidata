#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me(); 
void create()
{
    set_name("������",({"yun zaitian","yun"}));
    set("title",HIW"���зɺ�"NOR);
    set("long","һ�������ѩ��������ͱȻ�����СЩ����Ҳ����ʮ�����ң�ԲԲ���������΢�룬
��Цʱ�����˾��úܿ��ס�\n");
        set("gender","����");
        set("age",42);
                    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 10);

        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
    //set_skill("dagger", 150);
    set_skill("move", 360);
    set_skill("parry",120);
    set_skill("dodge", 320);
    set_skill("force", 180);
    set_skill("literate", 100);
    set_skill("unarmed",220);
    set_skill("blade",200);

    set_skill("xiruo-blade",180);
    set_skill("liumang-strike",220);
    set_skill("stormdance",320);
  //  set_skill("yuping-dagger",200);
    set_skill("wuchenforce",200);

  map_skill("blade", "xiruo-blade");
    map_skill("dodge", "stormdance");
    map_skill("move", "stormdance");
    map_skill("force", "wuchenforce");
    map_skill("unarmed", "liumang-strike");
    //map_skill("dagger","yuping-dagger");
        
        set("force",1500);
        set("max_force",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set_temp("apply/armor",300);
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 250);
        
        set("attitude", "friendly");
                
        set("inquiry", ([
                "������" :      (: show_me :),
                "���Ⱥ" :       (: show_me :),
                "��"   :       (: show_me :),
                "������" :       (: show_me :),
        ]));
        
        set("death_msg",CYN"\n$N˵������һ���Ҳ����İ��� \n"NOR);             
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
           set("chat_msg_combat", ({
              (: perform_action, "blade.bafangfengyu" :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                name()+"���������·������ϰ�֮�������λӢ�۽�ҹ��ȥС�á���\n"
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/obj/weapon/blade")->wield();    
        carry_object("/obj/armor/cloth")->wear();    
    
}  
int show_me(){
        object me,ob;
        
        me=this_player();
        ob=this_object();       
        
        if (!me->query("wanma/��")){
                message_vision(CYN"$N����$n����������Ŀ���ƺ�Ҫ��$n������\n",ob,me);
                command("say ������Ҫ��Ŀ��ˣ���������Ȼ���뵽��");
                command("say �����ò���Ŀ��ˣ�����Ҳ�Ƕ��ࡣ");
                return 1;
        }
        
        message_vision(CYN"$Nһ����˵�����ϰ���ӭ���������ݡ�\n"NOR,ob);
        me->set("wanma/ӭ��",1);
        return 1;
}    
int accept_object(object me, object obj)
{
        object book;
        if( (string) obj->query("name") == HIG"�黨"NOR)
        {
                obj = new(__DIR__"obj/combinepaper");
                message_vision(CYN"$N˵�������������͸��߳ǵ�һ���˵İ���������Ȼ���Ѿ����Ѻ��ˣ�������һ���ɡ�Ŷ�����Ǻö�����Ҳ����һ�顣\n"+NOR"$N��"NOR + obj->name() + NOR"����$n���С�\n", 
                            this_object(),this_player() );

                        book = new(__DIR__"obj/combinepaper");
                        if(book) book->move(this_player());
                        
                        
           return 1;       
        }
        else {return notify_fail("����������ؾ��˸������������õ��ˣ��������ձ��˵Ķ�������\n");}
            
        return 1;
} 
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/ɱ������_ma", 1);
        }
        
        ::die(); 

}